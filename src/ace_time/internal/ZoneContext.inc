/*
 * MIT License
 * Copyright (c) 2019 Brian T. Park
 */

/**
 * Metadata about the zone database. A ZoneInfo struct will contain a pointer
 * to this.
 */
struct ZoneContext {
  /*
   * Epoch year. Currently always 2000 but could change in the future. We're
   * leaving this out for now because it's not clear how or if the various
   * AceTime classes can use this information since the value '2000' is often
   * a compile-time constant instead of a runtime constant.
   */
  //int16_t epoch_year;

  /** Start year of the zone files. */
  const int16_t startYear;

  /** Until year of the zone files. */
  const int16_t untilYear;

  /** TZ Database version which generated the zone info. */
  const char* const tzVersion;
};
