# Copyright 2019 Brian T. Park
#
# MIT License

import logging
import datetime
import collections
import pytz
from datetime import timedelta
from zone_specifier import ZoneSpecifier
from zone_specifier import SECONDS_SINCE_UNIX_EPOCH
from zone_specifier import DateTuple

# An entry in the test data set.
TestItem = collections.namedtuple(
    "TestItem", "epoch total_offset dst_offset y M d h m s type")


class TestDataGenerator:
    """Generate the validation test data using the Transitions determined by
    ZoneSpecifier and the UTC offsets determined by pytz. This gives us
    stability which we can use to test other versions of ZoneSpecifier.
    """

    # The following zones have transitions which occurs at a time which is not a
    # multiple of 15 minutes, so cannot be represented by the C++ TimeOffset
    # object. In all cases below, the actual transition occurs at 00:01, but the
    # Transformer filter truncated the transition time to the nearest 15-minute
    # towards 00:00. To produce the correct validation_data.cpp data file,
    # for the transitions appearing below, we must shift the actual transition
    # time to 00:01 before calling the timezone object in PyTz.
    #
    # The first value of the 2-tuple is a DateTuple that marks the
    # 'transitionTime' of the current Transition (usually the wall time, using
    # the UTC offset of the *previous* Transition), as determined by the
    # (Python) ZoneSpecifier class. Since the algorithm in ZoneSpecifier already
    # truncates the transition time, this will be the transition time *after*
    # the granularity truncation has been applied. In other words, if the actual
    # transitionTime according to the TZ Database was 00:01, then the first
    # component will be stored as 00:00. (The DateTuple[3] component is 'ss'
    # which is the transitionTime in seconds.)
    #
    # The second value of the 2-tuple is the amount of offset (in seconds) that
    # should be added to the transitionTime to get the corrected transitionTime
    # which should be passed to pytz to determine the expected UTC offset.
    #
    # NOTE: Using a dict {} might make the look up faster than using a
    # sequential scan through the DateTuple.
    CORRECTIONS = {
        'Asia/Gaza': [
            (DateTuple(2010, 3, 27, 0, 'w'), 60),
            (DateTuple(2011, 4, 1, 0, 'w'), 60),
        ],
        'America/Goose_Bay': [
            (DateTuple(2000, 4, 2, 0, 'w'), 60),
            (DateTuple(2000, 10, 29, 0, 'w'), 60),
            (DateTuple(2001, 4, 1, 0, 'w'), 60),
            (DateTuple(2001, 10, 28, 0, 'w'), 60),
            (DateTuple(2002, 4, 7, 0, 'w'), 60),
            (DateTuple(2002, 10, 27, 0, 'w'), 60),
            (DateTuple(2003, 4, 6, 0, 'w'), 60),
            (DateTuple(2003, 10, 26, 0, 'w'), 60),
            (DateTuple(2004, 4, 4, 0, 'w'), 60),
            (DateTuple(2004, 10, 31, 0, 'w'), 60),
            (DateTuple(2005, 4, 3, 0, 'w'), 60),
            (DateTuple(2005, 10, 30, 0, 'w'), 60),
            (DateTuple(2006, 4, 2, 0, 'w'), 60),
            (DateTuple(2006, 10, 29, 0, 'w'), 60),
            (DateTuple(2007, 3, 11, 0, 'w'), 60),
            (DateTuple(2007, 11, 4, 0, 'w'), 60),
            (DateTuple(2008, 3, 9, 0, 'w'), 60),
            (DateTuple(2008, 11, 2, 0, 'w'), 60),
            (DateTuple(2009, 3, 8, 0, 'w'), 60),
            (DateTuple(2009, 11, 1, 0, 'w'), 60),
            (DateTuple(2010, 3, 14, 0, 'w'), 60),
            (DateTuple(2010, 11, 7, 0, 'w'), 60),
            (DateTuple(2011, 3, 13, 0, 'w'), 60),
        ],
        'Asia/Hebron': [
            (DateTuple(2011, 4, 1, 0, 'w'), 60),
        ],
        'America/Moncton': [
            (DateTuple(2000, 4, 2, 0, 'w'), 60),
            (DateTuple(2000, 10, 29, 0, 'w'), 60),
            (DateTuple(2001, 4, 1, 0, 'w'), 60),
            (DateTuple(2001, 10, 28, 0, 'w'), 60),
            (DateTuple(2002, 4, 7, 0, 'w'), 60),
            (DateTuple(2002, 10, 27, 0, 'w'), 60),
            (DateTuple(2003, 4, 6, 0, 'w'), 60),
            (DateTuple(2003, 10, 26, 0, 'w'), 60),
            (DateTuple(2004, 4, 4, 0, 'w'), 60),
            (DateTuple(2004, 10, 31, 0, 'w'), 60),
            (DateTuple(2005, 4, 3, 0, 'w'), 60),
            (DateTuple(2005, 10, 30, 0, 'w'), 60),
            (DateTuple(2006, 4, 2, 0, 'w'), 60),
            (DateTuple(2006, 10, 29, 0, 'w'), 60),
        ],
        'America/St_Johns': [
            (DateTuple(2000, 4, 2, 0, 'w'), 60),
            (DateTuple(2000, 10, 29, 0, 'w'), 60),
            (DateTuple(2001, 4, 1, 0, 'w'), 60),
            (DateTuple(2001, 10, 28, 0, 'w'), 60),
            (DateTuple(2002, 4, 7, 0, 'w'), 60),
            (DateTuple(2002, 10, 27, 0, 'w'), 60),
            (DateTuple(2003, 4, 6, 0, 'w'), 60),
            (DateTuple(2003, 10, 26, 0, 'w'), 60),
            (DateTuple(2004, 4, 4, 0, 'w'), 60),
            (DateTuple(2004, 10, 31, 0, 'w'), 60),
            (DateTuple(2005, 4, 3, 0, 'w'), 60),
            (DateTuple(2005, 10, 30, 0, 'w'), 60),
            (DateTuple(2006, 4, 2, 0, 'w'), 60),
            (DateTuple(2006, 10, 29, 0, 'w'), 60),
            (DateTuple(2007, 3, 11, 0, 'w'), 60),
            (DateTuple(2007, 11, 4, 0, 'w'), 60),
            (DateTuple(2008, 3, 9, 0, 'w'), 60),
            (DateTuple(2008, 11, 2, 0, 'w'), 60),
            (DateTuple(2009, 3, 8, 0, 'w'), 60),
            (DateTuple(2009, 11, 1, 0, 'w'), 60),
            (DateTuple(2010, 3, 14, 0, 'w'), 60),
            (DateTuple(2010, 11, 7, 0, 'w'), 60),
            (DateTuple(2011, 3, 13, 0, 'w'), 60),
        ],
    }

    def __init__(self, zone_infos, zone_policies, granularity, start_year,
        until_year):
        """
        Args:
            zone_infos (dict): {zone_name -> zone_info{} }
            zone_policies (dict): {zone_name ->zone_policy{} }
        """
        self.zone_infos = zone_infos
        self.zone_policies = zone_policies
        self.granularity = granularity

        self.zone_name = ''
        self.viewing_months = 14
        self.start_year = start_year
        self.until_year = until_year

    def create_test_data(self):
        """Create a map of {
            zone_name: [ TestItem() ]
        }
        Return (test_data, num_items).
        """
        test_data = {}
        num_items = 0
        for zone_name, zone_info in sorted(self.zone_infos.items()):
            if self.zone_name != '' and zone_name != self.zone_name:
                continue
            test_items = self._create_test_data_for_zone(
                zone_name, zone_info)
            if test_items:
                test_data[zone_name] = test_items
                num_items += len(test_items)
        return (test_data, num_items)

    def _create_test_data_for_zone(self, zone_name, zone_info):
        """Create the TestItems for a specific zone.
        """
        zone_specifier = ZoneSpecifier(zone_info)
        try:
            tz = pytz.timezone(zone_name)
        except:
            logging.error("Zone '%s' not found in Python pytz package",
                          zone_name)
            return None

        return self._create_transition_test_items(
            zone_name, tz, zone_specifier)

    @staticmethod
    def _add_test_item(items_map, item):
        current = items_map.get(item.epoch)
        if current:
            # If a duplicate TestItem exists for epoch, then check that the
            # data is exactly the same.
            if (current.total_offset != item.total_offset
                    or current.dst_offset != item.dst_offset
                    or current.y != item.y or current.M != item.M
                    or current.d != item.d or current.h != item.h
                    or current.m != item.m or current.s != item.s):
                raise Exception('Item %s does not match item %s' % (current,
                                                                    item))
            # 'A' and 'B' takes precedence over 'S' or 'Y'
            if item.type in ['A', 'B']:
                items_map[item.epoch] = item
        else:
            items_map[item.epoch] = item

    def _create_transition_test_items(self, zone_name, tz, zone_specifier):
        """Create a TestItem for the tz for each zone, for each year from
        start_year to until_year, exclusive. The following test samples are
        created:

        * One test point for each month, on the first of the month.
        * One test point for Dec 31, 23:00 for each year.
        * A test point at the transition from DST to Standard, or vise versa.
        * A test point one second before the transition.

        Each TestData is annotated as:
        * 'a': corrected pre-transition
        * 'b': corrected post-transition
        * 'A': pre-transition
        * 'B': post-transition
        * 'S': a monthly test sample
        * 'Y': end of year test sample

        For [2000, 2038], this generates about 100,000 data points.
        """
        items_map = {}
        for year in range(self.start_year, self.until_year):
            # Skip start_year when viewing months is 36, because it needs data
            # for (start_year - 3), but ZoneSpecifier won't generate data for
            # years that old.
            if self.viewing_months == 36 and year == self_start_year: continue

            # Add samples just before and just after the DST transition.
            zone_specifier.init_for_year(year)
            for transition in zone_specifier.transitions:
                # Some Transitions from ZoneSpecifier are in previous or post
                # years (e.g. viewing_months = [14, 36]), so skip those.
                start = transition.startDateTime
                transition_year = start.y
                if transition_year != year: continue

                # If viewing_months== (13 or 36), don't look at Transitions at
                # the beginning of the year since those have been already added.
                if self.viewing_months in [13, 36]:
                    if start.M == 1 and start.d == 1 and start.ss == 0:
                        continue

                correction = self._get_correction(
                    zone_name, transition.transitionTime)

                epoch_seconds = transition.startEpochSecond

                # Add a test data just before the transition
                test_item = self._create_test_item_from_epoch_seconds(
                    tz, epoch_seconds - 1, correction,
                    'a' if correction else 'A')
                self._add_test_item(items_map, test_item)

                # Add a test data at the transition itself (which will
                # normally be shifted forward or backwards).
                test_item = self._create_test_item_from_epoch_seconds(
                    tz, epoch_seconds, correction, 'b' if correction else 'B')
                self._add_test_item(items_map, test_item)

            # Add one sample test point on the first of each month
            for month in range(1, 13):
                tt = DateTuple(y=year, M=month, d=1, ss=0, f='w')
                correction = self._get_correction(zone_name, tt)
                test_item = self._create_test_item_from_datetime(
                    tz, tt, correction, type='S')
                self._add_test_item(items_map, test_item)

            # Add a sample test point at the end of the year.
            tt = DateTuple(y=year, M=12, d=31, ss=23*3600, f='w')
            correction = self._get_correction(zone_name, tt)
            test_item = self._create_test_item_from_datetime(
                tz, tt, correction, type='Y')
            self._add_test_item(items_map, test_item)

        # Return the TestItems ordered by epoch
        return [items_map[x] for x in sorted(items_map)]

    def _get_correction(self, zone_name, tt):
        """Given the DateTuple of interest, return the correction (in seconds)
        due to truncation of the transition time caused by the granularity. For
        example, if the actual transition time was 00:01, but the granularity is
        15 minutes, then the various transition times got truncated to 00:00 and
        the correction will be 60 seconds.
        """
        if self.granularity <= 60:
            return 0

        correction_list = TestDataGenerator.CORRECTIONS.get(zone_name)
        if correction_list:
            for correction in correction_list:
                if tt == correction[0]:
                    return correction[1]
        return 0

    def _create_test_item_from_datetime(self, tz, tt, correction, type):
        """Create a TestItem for the given DateTuple in the local time zone.
        """
        # Can't use the normal datetime constructor for pytz. Must use
        # timezone.localize(). See https://stackoverflow.com/questions/18541051
        ldt = datetime.datetime(tt.y, tt.M, tt.d, tt.ss//3600)
        dt = tz.localize(ldt)
        unix_seconds = int(dt.timestamp())
        epoch_seconds = unix_seconds - SECONDS_SINCE_UNIX_EPOCH
        return self._create_test_item_from_epoch_seconds(
            tz, epoch_seconds, correction, type)


    def _create_test_item_from_epoch_seconds(self, tz, epoch_seconds,
        correction, type):
        """Determine the expected date and time components for the given
        'epoch_seconds' for the given 'tz'. The 'epoch_seconds' is the
        transition time calculated by the ZoneSpecifier class (which is the
        Python implementation of the C++ ExtendedZoneSpecifier class). That
        epoch_seconds will be off by 'correction' seconds (usually 60 seconds)
        for a handful of zones at small number of transitions because
        ZoneSpecifier truncates transition time to multiples of 15 minutes. For
        example, a transition time of 00:01 will be truncated to 00:00.

        To calculate the expected date & time components using pytz, the actual
        transition time must be corrected using 'epoch_seconds + correction',
        and this corrected epoch_seconds must be given to pytz to retrieve the
        expected DST offsets.

        Return the TestItem with the following fields:
            epoch: epoch seconds from AceTime epoch (2000-01-01T00:00:00Z)
            total_offset: the expected total UTC offset at epoch_seconds
            dst_offset: the expected DST offset at epoch_seconds
            y, M, d, h, m, s: expected date&time components at epoch_seconds
            type: 'a', 'b', 'A', 'B', 'S', 'Y'
        """

        # Convert AceTime epoch_seconds to Unix epoch_seconds.
        unix_seconds = epoch_seconds + SECONDS_SINCE_UNIX_EPOCH

        # Shift the epoch seconds by its correction to get the actual transition
        # time, then feed that into pytz to get the total offset and DST shift
        corrected_utc_dt = datetime.datetime.fromtimestamp(
            unix_seconds + correction, tz=datetime.timezone.utc)
        corrected_dt = corrected_utc_dt.astimezone(tz)
        total_offset = int(corrected_dt.utcoffset().total_seconds())
        dst_offset = int(corrected_dt.dst().total_seconds())

        # The expected YMDHMS components (from AceTime) are determined by taking
        # the corrected datetime (from pytz), and shifting back by the given
        # correction.
        rdt = corrected_dt - timedelta(seconds=correction)

        return TestItem(
            epoch=epoch_seconds,
            total_offset=total_offset,
            dst_offset=dst_offset,
            y=rdt.year,
            M=rdt.month,
            d=rdt.day,
            h=rdt.hour,
            m=rdt.minute,
            s=rdt.second,
            type=type)
