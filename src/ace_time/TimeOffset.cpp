/*
 * MIT License
 * Copyright (c) 2018 Brian T. Park
 */

#include <string.h> // strlen()
#include "common/util.h"
#include "common/DateStrings.h"
#include "TimeOffset.h"

namespace ace_time {

using common::printPad2;

void TimeOffset::printTo(Print& printer) const {
  int8_t hour;
  int8_t minute;
  toHourMinute(hour, minute);

  if (mOffsetCode < 0) {
    printer.print('-');
    hour = -hour;
    minute = -minute;
  } else {
    printer.print('+');
  }
  common::printPad2(printer, hour);
  printer.print(':');
  common::printPad2(printer, minute);
}

TimeOffset TimeOffset::forOffsetString(const char* offsetString) {
  // verify exact ISO 8601 string length
  if (strlen(offsetString) != kTimeOffsetStringLength) {
    return forError();
  }

  return forOffsetStringChainable(offsetString);
}

TimeOffset TimeOffset::forOffsetStringChainable(const char*& offsetString) {
  const char* s = offsetString;

  // '+' or '-'
  char utcSign = *s++;
  if (utcSign != '-' && utcSign != '+') {
    return forError();
  }

  // hour
  uint8_t hour = (*s++ - '0');
  hour = 10 * hour + (*s++ - '0');
  s++;

  // minute
  uint8_t minute = (*s++ - '0');
  minute = 10 * minute + (*s++ - '0');
  s++;

  offsetString = s;
  if (utcSign == '+') {
    return forHourMinute(hour, minute);
  } else {
    return forHourMinute(-hour, -minute);
  }
}

}
