#include "LocalDate.h"
#include "ExtendedZoneSpecifier.h"

namespace ace_time {

const extended::ZoneEra ExtendedZoneSpecifier::kAnchorEra = {
  0 /*offsetCode*/,
  nullptr /*zonePolicy*/,
  0 /*deltaCode*/,
  nullptr /*format*/,
  LocalDate::kInvalidYearTiny /*untilYearTiny*/,
  1 /*untilMonth*/,
  1 /*untilDay*/,
  0 /*untilTimeCode*/,
  'w' /*untilTimeModifier*/
};

void ExtendedZoneSpecifier::printTo(Print& printer) const {
  printer.print(mZoneInfo->name);
}

}