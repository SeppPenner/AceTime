/*
 * MIT License
 * Copyright (c) 2018 Brian T. Park
 */

#ifndef ACE_TIME_TESTABLE_SYSTEM_CLOCK_COROUTINE_H
#define ACE_TIME_TESTABLE_SYSTEM_CLOCK_COROUTINE_H

#include <stdint.h>
#include "../clock/SystemClockCoroutine.h"
#include "FakeMillis.h"

namespace ace_time {
namespace testing {

/**
 * A version of SystemClockCoroutine that allows the clockMillis() function to
 * be manually set for testing purposes.
 */
class TestableSystemClockCoroutine: public clock::SystemClockCoroutine {
  public:
    TestableSystemClockCoroutine(
        Clock* referenceClock /* nullable */,
        Clock* backupClock /* nullable */,
        FakeMillis* fakeMillis):
      SystemClockCoroutine(referenceClock, backupClock),
      mFakeMillis(fakeMillis) {}

    // Override Coroutine::millis().
    unsigned long millis() const override {
      return mFakeMillis->millis();
    }

    unsigned long clockMillis() const override {
      return mFakeMillis->millis();
    }

  private:
    FakeMillis* mFakeMillis;
};

}
}

#endif
