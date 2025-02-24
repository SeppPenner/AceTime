#line 2 "TimeOffsetTest.ino"

#include <AUnit.h>
#include <AceTime.h>

using namespace aunit;
using namespace ace_time;

// --------------------------------------------------------------------------
// TimeOffset
// --------------------------------------------------------------------------

test(TimeOffsetTest, code) {
  assertEqual(TimeOffset::forHour(-8).toOffsetCode(), -8*4);
}

test(TimeOffsetTest, isZero) {
  assertTrue(TimeOffset::forHour(0).isZero());
  assertTrue(TimeOffset().isZero());
  assertFalse(TimeOffset::forHour(1).isZero());
}

test(TimeOffsetTest, forMinutes) {
  TimeOffset offset = TimeOffset::forMinutes(-15);
  assertEqual((int16_t) -15, offset.toMinutes());
  assertEqual((int32_t) -900, offset.toSeconds());

  offset = TimeOffset::forMinutes(15);
  assertEqual((int16_t) 15, offset.toMinutes());
  assertEqual((int32_t) 900, offset.toSeconds());

  offset = TimeOffset::forMinutes(-16);
  assertEqual((int16_t) -15, offset.toMinutes());
  assertEqual((int32_t) -900, offset.toSeconds());

  offset = TimeOffset::forMinutes(16);
  assertEqual((int16_t) 15, offset.toMinutes());
  assertEqual((int32_t) 900, offset.toSeconds());
}

test(TimeOffsetTest, forHour) {
  assertEqual(TimeOffset::forHour(-8).toMinutes(), -8*60);
  assertEqual(TimeOffset::forHour(1).toMinutes(), 1*60);
}

test(TimeOffsetTest, forHourMinute) {
  assertEqual(TimeOffset::forHourMinute(-8, 0).toMinutes(), -(8*60));
  assertEqual(TimeOffset::forHourMinute(-8, -15).toMinutes(), -(8*60+15));
  assertEqual(TimeOffset::forHourMinute(1, 0).toMinutes(), 60);
  assertEqual(TimeOffset::forHourMinute(1, 15).toMinutes(), 75);
  assertEqual(TimeOffset::forHourMinute(0, -15).toMinutes(), -15);
}

test(TimeOffsetTest, forOffsetString) {
  assertTrue(TimeOffset::forOffsetString("").isError());
  assertEqual(TimeOffset::forOffsetString("-07:00").toMinutes(), -7*60);
  assertEqual(TimeOffset::forOffsetString("-07:45").toMinutes(), -(7*60+45));
  assertEqual(TimeOffset::forOffsetString("+01:00").toMinutes(), 60);
  assertEqual(TimeOffset::forOffsetString("+01:15").toMinutes(), 75);
  assertEqual(TimeOffset::forOffsetString("+01:16").toMinutes(), 75);
}

test(TimeOffsetTest, toHourMinute) {
  int8_t hour;
  int8_t minute;
  TimeOffset offset;

  TimeOffset::forHourMinute(0, 15).toHourMinute(hour, minute);
  assertEqual(0, hour);
  assertEqual(15, minute);

  TimeOffset::forHourMinute(0, -15).toHourMinute(hour, minute);
  assertEqual(0, hour);
  assertEqual(-15, minute);

  TimeOffset::forHourMinute(-1, -15).toHourMinute(hour, minute);
  assertEqual(-1, hour);
  assertEqual(-15, minute);

  TimeOffset::forHourMinute(1, 15).toHourMinute(hour, minute);
  assertEqual(1, hour);
  assertEqual(15, minute);
}

test(TimeOffsetTest, error) {
  TimeOffset offset;
  assertFalse(offset.isError());

  offset = TimeOffset::forError();
  assertTrue(offset.isError());
}

// --------------------------------------------------------------------------
// time_offset_mutation
// --------------------------------------------------------------------------

test(TimeOffsetMutationTest, increment15Minutes) {
  int8_t hour;
  int8_t minute;
  TimeOffset offset;

  offset = TimeOffset::forHourMinute(-16, 0);
  time_offset_mutation::increment15Minutes(offset);
  offset.toHourMinute(hour, minute);
  assertEqual(-15, hour);
  assertEqual(-45, minute);

  time_offset_mutation::increment15Minutes(offset);
  offset.toHourMinute(hour, minute);
  assertEqual(-15, hour);
  assertEqual(-30, minute);

  time_offset_mutation::increment15Minutes(offset);
  offset.toHourMinute(hour, minute);
  assertEqual(-15, hour);
  assertEqual(-15, minute);

  time_offset_mutation::increment15Minutes(offset);
  offset.toHourMinute(hour, minute);
  assertEqual(-15, hour);
  assertEqual(0, minute);

  offset = TimeOffset::forHourMinute(15, 45);
  time_offset_mutation::increment15Minutes(offset);
  offset.toHourMinute(hour, minute);
  assertEqual(16, hour);
  assertEqual(0, minute);

  time_offset_mutation::increment15Minutes(offset);
  offset.toHourMinute(hour, minute);
  assertEqual(-16, hour);
  assertEqual(0, minute);
}

// --------------------------------------------------------------------------

void setup() {
#if defined(ARDUINO)
  delay(1000); // wait for stability on some boards to prevent garbage SERIAL_PORT_MONITOR
#endif
  SERIAL_PORT_MONITOR.begin(115200); // ESP8266 default of 74880 not supported on Linux
  while(!SERIAL_PORT_MONITOR); // for the Arduino Leonardo/Micro only
}

void loop() {
  TestRunner::run();
}
