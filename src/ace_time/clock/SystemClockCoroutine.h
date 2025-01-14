/*
 * MIT License
 * Copyright (c) 2018 Brian T. Park
 */

#ifndef ACE_TIME_SYSTEM_CLOCK_COROUTINE_H
#define ACE_TIME_SYSTEM_CLOCK_COROUTINE_H

#include <stdint.h>
#include <AceRoutine.h>
#include "../common/TimingStats.h"
#include "SystemClock.h"

namespace ace_time {
namespace clock {

/**
 * A version of SystemClock that mixes in the ace_routine::Coroutine class so
 * that that the non-block methods of mReferenceClock are called. This is
 * helpful when the referenceClock issues a network request to an NTP server.
 *
 * Initially, the class attempts to sync with its referenceClock every
 * initialSyncPeriodSeconds. If the request fails, then it retries with an
 * exponential backoff (doubling the delay every iteration), until the sync
 * period becomes greater than syncPeriodSeconds, then the delay is set
 * permanently to syncPeriodSeconds.
 */
class SystemClockCoroutine: public SystemClock, public ace_routine::Coroutine {
  public:
    static const uint8_t kStatusSent = 0;
    static const uint8_t kStatusOk = 1;
    static const uint8_t kStatusTimedOut = 2;

    /**
     * Constructor.
     *
     * @param referenceClock The authoritative source of the time. If this is
     *    null, the object relies just on clockMillis() and the user to set the
     *    proper time using setNow().
     * @param backupClock An RTC chip which continues to keep time
     *    even when power is lost. Can be null.
     * @param syncPeriodSeconds seconds between normal sync attempts
     *    (default 3600)
     * @param initialSyncPeriodSeconds seconds between sync attempts when
     *    the systemClock is not initialized (default 5)
     * @param requestTimeoutMillis number of milliseconds before the request to
     *    referenceClock times out
     * @param timingStats internal statistics
     */
    explicit SystemClockCoroutine(
        Clock* referenceClock /* nullable */,
        Clock* backupClock /* nullable */,
        uint16_t syncPeriodSeconds = 3600,
        uint16_t initialSyncPeriodSeconds = 5,
        uint16_t requestTimeoutMillis = 1000,
        common::TimingStats* timingStats = nullptr):
      SystemClock(referenceClock, backupClock),
      mSyncPeriodSeconds(syncPeriodSeconds),
      mRequestTimeoutMillis(requestTimeoutMillis),
      mTimingStats(timingStats),
      mCurrentSyncPeriodSeconds(initialSyncPeriodSeconds) {}

    /**
     * @copydoc Coroutine::runCoroutine()
     *
     * The CoroutineScheduler will use this method if enabled. Don't forget to
     * call setupCoroutine() (inherited from Coroutine) in the global setup() to
     * register this coroutine into the CoroutineScheduler.
     */
    int runCoroutine() override {
      if (mReferenceClock == nullptr) return 0;

      COROUTINE_LOOP() {
        // Send request
        mReferenceClock->sendRequest();
        mRequestStartTime = this->millis();
        mRequestStatus = kStatusSent;

        // Wait for request
        while (true) {
          if (mReferenceClock->isResponseReady()) {
            mRequestStatus = kStatusOk;
            break;
          }

          {
            // Local variable waitTime must be scoped with {} so that the goto
            // in COROUTINE_LOOP() skip past it in clang++. g++ seems to be
            // fine without it.
            uint16_t waitTime = this->millis()
                - mRequestStartTime;
            if (waitTime >= mRequestTimeoutMillis) {
              mRequestStatus = kStatusTimedOut;
              break;
            }
          }

          COROUTINE_YIELD();
        }

        // Process the response
        if (mRequestStatus == kStatusOk) {
          acetime_t nowSeconds = mReferenceClock->readResponse();
          uint16_t elapsedTime = this->millis()
              - mRequestStartTime;
          if (mTimingStats != nullptr) {
            mTimingStats->update(elapsedTime);
          }
          syncNow(nowSeconds);
          mCurrentSyncPeriodSeconds = mSyncPeriodSeconds;
        }

        COROUTINE_DELAY_SECONDS(mDelayLoopCounter, mCurrentSyncPeriodSeconds);

        // Determine the retry delay time based on success or failure. If
        // failure, retry with exponential backoff, until the delay becomes
        // mSyncPeriodSeconds.
        if (mRequestStatus == kStatusTimedOut) {
          if (mCurrentSyncPeriodSeconds >= mSyncPeriodSeconds / 2) {
            mCurrentSyncPeriodSeconds = mSyncPeriodSeconds;
          } else {
            mCurrentSyncPeriodSeconds *= 2;
          }
        }
      }
    }

    /** Return the current request status. Mostly for debugging. */
    uint8_t getRequestStatus() const { return mRequestStatus; }

  private:
    friend class ::SystemClockCoroutineTest;

    // disable copy constructor and assignment operator
    SystemClockCoroutine(const SystemClockCoroutine&) = delete;
    SystemClockCoroutine& operator=(const SystemClockCoroutine&) = delete;

    uint16_t const mSyncPeriodSeconds;
    uint16_t const mRequestTimeoutMillis;
    common::TimingStats* const mTimingStats;

    uint16_t mRequestStartTime;
    uint16_t mCurrentSyncPeriodSeconds;
    uint16_t mDelayLoopCounter;
    uint8_t mRequestStatus;
};

}
}

#endif
