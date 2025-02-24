// This file was generated by the following script:
//
//   $ ../../../tools/tzcompiler.py --input_dir ../../../tools/../../tz --output_dir /home/brian/dev/AceTime/src/ace_time/zonedbx --tz_version 2019a --action zonedb --language arduino --scope extended --start_year 2000 --until_year 2050
//
// using the TZ Database files from
// https://github.com/eggert/tz/releases/tag/2019a
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDBX_ZONE_REGISTRY_H
#define ACE_TIME_ZONEDBX_ZONE_REGISTRY_H

#include <ace_time/internal/ZoneInfo.h>

namespace ace_time {
namespace zonedbx {

const uint16_t kZoneRegistrySize = 387;

extern const extended::ZoneInfo* const kZoneRegistry[387];

}
}
#endif
