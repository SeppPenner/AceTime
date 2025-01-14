// This file was generated by the following script:
//
//   $ ../../../tools/tzcompiler.py --input_dir ../../../tools/../../tz --output_dir /home/brian/dev/AceTime/src/ace_time/zonedb --tz_version 2019a --action zonedb --language arduino --scope basic --start_year 2000 --until_year 2050
//
// using the TZ Database files from
// https://github.com/eggert/tz/releases/tag/2019a
//
// DO NOT EDIT

#include <ace_time/common/compat.h>
#include "zone_infos.h"
#include "zone_registry.h"

namespace ace_time {
namespace zonedb {

//---------------------------------------------------------------------------
// Zone registry. Sorted by zone name.
//---------------------------------------------------------------------------
const basic::ZoneInfo* const kZoneRegistry[270] ACE_TIME_PROGMEM = {
  &kZoneAfrica_Abidjan, // Africa/Abidjan
  &kZoneAfrica_Accra, // Africa/Accra
  &kZoneAfrica_Algiers, // Africa/Algiers
  &kZoneAfrica_Bissau, // Africa/Bissau
  &kZoneAfrica_Ceuta, // Africa/Ceuta
  &kZoneAfrica_Johannesburg, // Africa/Johannesburg
  &kZoneAfrica_Lagos, // Africa/Lagos
  &kZoneAfrica_Maputo, // Africa/Maputo
  &kZoneAfrica_Monrovia, // Africa/Monrovia
  &kZoneAfrica_Nairobi, // Africa/Nairobi
  &kZoneAfrica_Ndjamena, // Africa/Ndjamena
  &kZoneAfrica_Tunis, // Africa/Tunis
  &kZoneAmerica_Adak, // America/Adak
  &kZoneAmerica_Anchorage, // America/Anchorage
  &kZoneAmerica_Asuncion, // America/Asuncion
  &kZoneAmerica_Atikokan, // America/Atikokan
  &kZoneAmerica_Barbados, // America/Barbados
  &kZoneAmerica_Belem, // America/Belem
  &kZoneAmerica_Blanc_Sablon, // America/Blanc-Sablon
  &kZoneAmerica_Bogota, // America/Bogota
  &kZoneAmerica_Boise, // America/Boise
  &kZoneAmerica_Campo_Grande, // America/Campo_Grande
  &kZoneAmerica_Cayenne, // America/Cayenne
  &kZoneAmerica_Chicago, // America/Chicago
  &kZoneAmerica_Chihuahua, // America/Chihuahua
  &kZoneAmerica_Costa_Rica, // America/Costa_Rica
  &kZoneAmerica_Creston, // America/Creston
  &kZoneAmerica_Curacao, // America/Curacao
  &kZoneAmerica_Danmarkshavn, // America/Danmarkshavn
  &kZoneAmerica_Dawson, // America/Dawson
  &kZoneAmerica_Dawson_Creek, // America/Dawson_Creek
  &kZoneAmerica_Denver, // America/Denver
  &kZoneAmerica_Detroit, // America/Detroit
  &kZoneAmerica_Edmonton, // America/Edmonton
  &kZoneAmerica_El_Salvador, // America/El_Salvador
  &kZoneAmerica_Glace_Bay, // America/Glace_Bay
  &kZoneAmerica_Godthab, // America/Godthab
  &kZoneAmerica_Guatemala, // America/Guatemala
  &kZoneAmerica_Guayaquil, // America/Guayaquil
  &kZoneAmerica_Guyana, // America/Guyana
  &kZoneAmerica_Halifax, // America/Halifax
  &kZoneAmerica_Havana, // America/Havana
  &kZoneAmerica_Hermosillo, // America/Hermosillo
  &kZoneAmerica_Indiana_Indianapolis, // America/Indiana/Indianapolis
  &kZoneAmerica_Indiana_Marengo, // America/Indiana/Marengo
  &kZoneAmerica_Indiana_Vevay, // America/Indiana/Vevay
  &kZoneAmerica_Inuvik, // America/Inuvik
  &kZoneAmerica_Jamaica, // America/Jamaica
  &kZoneAmerica_Juneau, // America/Juneau
  &kZoneAmerica_Kentucky_Louisville, // America/Kentucky/Louisville
  &kZoneAmerica_La_Paz, // America/La_Paz
  &kZoneAmerica_Lima, // America/Lima
  &kZoneAmerica_Los_Angeles, // America/Los_Angeles
  &kZoneAmerica_Managua, // America/Managua
  &kZoneAmerica_Manaus, // America/Manaus
  &kZoneAmerica_Martinique, // America/Martinique
  &kZoneAmerica_Matamoros, // America/Matamoros
  &kZoneAmerica_Mazatlan, // America/Mazatlan
  &kZoneAmerica_Menominee, // America/Menominee
  &kZoneAmerica_Merida, // America/Merida
  &kZoneAmerica_Miquelon, // America/Miquelon
  &kZoneAmerica_Moncton, // America/Moncton
  &kZoneAmerica_Monterrey, // America/Monterrey
  &kZoneAmerica_Montevideo, // America/Montevideo
  &kZoneAmerica_Nassau, // America/Nassau
  &kZoneAmerica_New_York, // America/New_York
  &kZoneAmerica_Nipigon, // America/Nipigon
  &kZoneAmerica_Nome, // America/Nome
  &kZoneAmerica_North_Dakota_Center, // America/North_Dakota/Center
  &kZoneAmerica_Ojinaga, // America/Ojinaga
  &kZoneAmerica_Panama, // America/Panama
  &kZoneAmerica_Paramaribo, // America/Paramaribo
  &kZoneAmerica_Phoenix, // America/Phoenix
  &kZoneAmerica_Port_au_Prince, // America/Port-au-Prince
  &kZoneAmerica_Port_of_Spain, // America/Port_of_Spain
  &kZoneAmerica_Porto_Velho, // America/Porto_Velho
  &kZoneAmerica_Puerto_Rico, // America/Puerto_Rico
  &kZoneAmerica_Rainy_River, // America/Rainy_River
  &kZoneAmerica_Regina, // America/Regina
  &kZoneAmerica_Santiago, // America/Santiago
  &kZoneAmerica_Sao_Paulo, // America/Sao_Paulo
  &kZoneAmerica_Scoresbysund, // America/Scoresbysund
  &kZoneAmerica_Sitka, // America/Sitka
  &kZoneAmerica_Swift_Current, // America/Swift_Current
  &kZoneAmerica_Tegucigalpa, // America/Tegucigalpa
  &kZoneAmerica_Thule, // America/Thule
  &kZoneAmerica_Thunder_Bay, // America/Thunder_Bay
  &kZoneAmerica_Toronto, // America/Toronto
  &kZoneAmerica_Vancouver, // America/Vancouver
  &kZoneAmerica_Whitehorse, // America/Whitehorse
  &kZoneAmerica_Winnipeg, // America/Winnipeg
  &kZoneAmerica_Yakutat, // America/Yakutat
  &kZoneAmerica_Yellowknife, // America/Yellowknife
  &kZoneAntarctica_DumontDUrville, // Antarctica/DumontDUrville
  &kZoneAntarctica_Rothera, // Antarctica/Rothera
  &kZoneAntarctica_Syowa, // Antarctica/Syowa
  &kZoneAntarctica_Vostok, // Antarctica/Vostok
  &kZoneAsia_Amman, // Asia/Amman
  &kZoneAsia_Ashgabat, // Asia/Ashgabat
  &kZoneAsia_Baghdad, // Asia/Baghdad
  &kZoneAsia_Baku, // Asia/Baku
  &kZoneAsia_Bangkok, // Asia/Bangkok
  &kZoneAsia_Beirut, // Asia/Beirut
  &kZoneAsia_Brunei, // Asia/Brunei
  &kZoneAsia_Damascus, // Asia/Damascus
  &kZoneAsia_Dhaka, // Asia/Dhaka
  &kZoneAsia_Dubai, // Asia/Dubai
  &kZoneAsia_Dushanbe, // Asia/Dushanbe
  &kZoneAsia_Ho_Chi_Minh, // Asia/Ho_Chi_Minh
  &kZoneAsia_Hong_Kong, // Asia/Hong_Kong
  &kZoneAsia_Hovd, // Asia/Hovd
  &kZoneAsia_Jakarta, // Asia/Jakarta
  &kZoneAsia_Jayapura, // Asia/Jayapura
  &kZoneAsia_Jerusalem, // Asia/Jerusalem
  &kZoneAsia_Kabul, // Asia/Kabul
  &kZoneAsia_Karachi, // Asia/Karachi
  &kZoneAsia_Kathmandu, // Asia/Kathmandu
  &kZoneAsia_Kolkata, // Asia/Kolkata
  &kZoneAsia_Kuala_Lumpur, // Asia/Kuala_Lumpur
  &kZoneAsia_Kuching, // Asia/Kuching
  &kZoneAsia_Macau, // Asia/Macau
  &kZoneAsia_Makassar, // Asia/Makassar
  &kZoneAsia_Manila, // Asia/Manila
  &kZoneAsia_Nicosia, // Asia/Nicosia
  &kZoneAsia_Pontianak, // Asia/Pontianak
  &kZoneAsia_Qatar, // Asia/Qatar
  &kZoneAsia_Riyadh, // Asia/Riyadh
  &kZoneAsia_Samarkand, // Asia/Samarkand
  &kZoneAsia_Seoul, // Asia/Seoul
  &kZoneAsia_Shanghai, // Asia/Shanghai
  &kZoneAsia_Singapore, // Asia/Singapore
  &kZoneAsia_Taipei, // Asia/Taipei
  &kZoneAsia_Tashkent, // Asia/Tashkent
  &kZoneAsia_Tehran, // Asia/Tehran
  &kZoneAsia_Thimphu, // Asia/Thimphu
  &kZoneAsia_Tokyo, // Asia/Tokyo
  &kZoneAsia_Ulaanbaatar, // Asia/Ulaanbaatar
  &kZoneAsia_Urumqi, // Asia/Urumqi
  &kZoneAsia_Yangon, // Asia/Yangon
  &kZoneAsia_Yerevan, // Asia/Yerevan
  &kZoneAtlantic_Azores, // Atlantic/Azores
  &kZoneAtlantic_Bermuda, // Atlantic/Bermuda
  &kZoneAtlantic_Canary, // Atlantic/Canary
  &kZoneAtlantic_Cape_Verde, // Atlantic/Cape_Verde
  &kZoneAtlantic_Faroe, // Atlantic/Faroe
  &kZoneAtlantic_Madeira, // Atlantic/Madeira
  &kZoneAtlantic_Reykjavik, // Atlantic/Reykjavik
  &kZoneAtlantic_South_Georgia, // Atlantic/South_Georgia
  &kZoneAustralia_Adelaide, // Australia/Adelaide
  &kZoneAustralia_Brisbane, // Australia/Brisbane
  &kZoneAustralia_Broken_Hill, // Australia/Broken_Hill
  &kZoneAustralia_Currie, // Australia/Currie
  &kZoneAustralia_Darwin, // Australia/Darwin
  &kZoneAustralia_Eucla, // Australia/Eucla
  &kZoneAustralia_Hobart, // Australia/Hobart
  &kZoneAustralia_Lindeman, // Australia/Lindeman
  &kZoneAustralia_Lord_Howe, // Australia/Lord_Howe
  &kZoneAustralia_Melbourne, // Australia/Melbourne
  &kZoneAustralia_Perth, // Australia/Perth
  &kZoneAustralia_Sydney, // Australia/Sydney
  &kZoneCET, // CET
  &kZoneCST6CDT, // CST6CDT
  &kZoneEET, // EET
  &kZoneEST, // EST
  &kZoneEST5EDT, // EST5EDT
  &kZoneEtc_GMT, // Etc/GMT
  &kZoneEtc_GMT_PLUS_1, // Etc/GMT+1
  &kZoneEtc_GMT_PLUS_10, // Etc/GMT+10
  &kZoneEtc_GMT_PLUS_11, // Etc/GMT+11
  &kZoneEtc_GMT_PLUS_12, // Etc/GMT+12
  &kZoneEtc_GMT_PLUS_2, // Etc/GMT+2
  &kZoneEtc_GMT_PLUS_3, // Etc/GMT+3
  &kZoneEtc_GMT_PLUS_4, // Etc/GMT+4
  &kZoneEtc_GMT_PLUS_5, // Etc/GMT+5
  &kZoneEtc_GMT_PLUS_6, // Etc/GMT+6
  &kZoneEtc_GMT_PLUS_7, // Etc/GMT+7
  &kZoneEtc_GMT_PLUS_8, // Etc/GMT+8
  &kZoneEtc_GMT_PLUS_9, // Etc/GMT+9
  &kZoneEtc_GMT_1, // Etc/GMT-1
  &kZoneEtc_GMT_10, // Etc/GMT-10
  &kZoneEtc_GMT_11, // Etc/GMT-11
  &kZoneEtc_GMT_12, // Etc/GMT-12
  &kZoneEtc_GMT_13, // Etc/GMT-13
  &kZoneEtc_GMT_14, // Etc/GMT-14
  &kZoneEtc_GMT_2, // Etc/GMT-2
  &kZoneEtc_GMT_3, // Etc/GMT-3
  &kZoneEtc_GMT_4, // Etc/GMT-4
  &kZoneEtc_GMT_5, // Etc/GMT-5
  &kZoneEtc_GMT_6, // Etc/GMT-6
  &kZoneEtc_GMT_7, // Etc/GMT-7
  &kZoneEtc_GMT_8, // Etc/GMT-8
  &kZoneEtc_GMT_9, // Etc/GMT-9
  &kZoneEtc_UTC, // Etc/UTC
  &kZoneEurope_Amsterdam, // Europe/Amsterdam
  &kZoneEurope_Andorra, // Europe/Andorra
  &kZoneEurope_Athens, // Europe/Athens
  &kZoneEurope_Belgrade, // Europe/Belgrade
  &kZoneEurope_Berlin, // Europe/Berlin
  &kZoneEurope_Brussels, // Europe/Brussels
  &kZoneEurope_Bucharest, // Europe/Bucharest
  &kZoneEurope_Budapest, // Europe/Budapest
  &kZoneEurope_Chisinau, // Europe/Chisinau
  &kZoneEurope_Copenhagen, // Europe/Copenhagen
  &kZoneEurope_Dublin, // Europe/Dublin
  &kZoneEurope_Gibraltar, // Europe/Gibraltar
  &kZoneEurope_Helsinki, // Europe/Helsinki
  &kZoneEurope_Kiev, // Europe/Kiev
  &kZoneEurope_Lisbon, // Europe/Lisbon
  &kZoneEurope_London, // Europe/London
  &kZoneEurope_Luxembourg, // Europe/Luxembourg
  &kZoneEurope_Madrid, // Europe/Madrid
  &kZoneEurope_Malta, // Europe/Malta
  &kZoneEurope_Monaco, // Europe/Monaco
  &kZoneEurope_Oslo, // Europe/Oslo
  &kZoneEurope_Paris, // Europe/Paris
  &kZoneEurope_Prague, // Europe/Prague
  &kZoneEurope_Rome, // Europe/Rome
  &kZoneEurope_Sofia, // Europe/Sofia
  &kZoneEurope_Stockholm, // Europe/Stockholm
  &kZoneEurope_Tirane, // Europe/Tirane
  &kZoneEurope_Uzhgorod, // Europe/Uzhgorod
  &kZoneEurope_Vienna, // Europe/Vienna
  &kZoneEurope_Warsaw, // Europe/Warsaw
  &kZoneEurope_Zaporozhye, // Europe/Zaporozhye
  &kZoneEurope_Zurich, // Europe/Zurich
  &kZoneHST, // HST
  &kZoneIndian_Chagos, // Indian/Chagos
  &kZoneIndian_Christmas, // Indian/Christmas
  &kZoneIndian_Cocos, // Indian/Cocos
  &kZoneIndian_Kerguelen, // Indian/Kerguelen
  &kZoneIndian_Mahe, // Indian/Mahe
  &kZoneIndian_Maldives, // Indian/Maldives
  &kZoneIndian_Mauritius, // Indian/Mauritius
  &kZoneIndian_Reunion, // Indian/Reunion
  &kZoneMET, // MET
  &kZoneMST, // MST
  &kZoneMST7MDT, // MST7MDT
  &kZonePST8PDT, // PST8PDT
  &kZonePacific_Auckland, // Pacific/Auckland
  &kZonePacific_Chatham, // Pacific/Chatham
  &kZonePacific_Chuuk, // Pacific/Chuuk
  &kZonePacific_Easter, // Pacific/Easter
  &kZonePacific_Efate, // Pacific/Efate
  &kZonePacific_Enderbury, // Pacific/Enderbury
  &kZonePacific_Fiji, // Pacific/Fiji
  &kZonePacific_Funafuti, // Pacific/Funafuti
  &kZonePacific_Galapagos, // Pacific/Galapagos
  &kZonePacific_Gambier, // Pacific/Gambier
  &kZonePacific_Guadalcanal, // Pacific/Guadalcanal
  &kZonePacific_Honolulu, // Pacific/Honolulu
  &kZonePacific_Kiritimati, // Pacific/Kiritimati
  &kZonePacific_Kosrae, // Pacific/Kosrae
  &kZonePacific_Kwajalein, // Pacific/Kwajalein
  &kZonePacific_Majuro, // Pacific/Majuro
  &kZonePacific_Marquesas, // Pacific/Marquesas
  &kZonePacific_Nauru, // Pacific/Nauru
  &kZonePacific_Niue, // Pacific/Niue
  &kZonePacific_Noumea, // Pacific/Noumea
  &kZonePacific_Pago_Pago, // Pacific/Pago_Pago
  &kZonePacific_Palau, // Pacific/Palau
  &kZonePacific_Pitcairn, // Pacific/Pitcairn
  &kZonePacific_Pohnpei, // Pacific/Pohnpei
  &kZonePacific_Port_Moresby, // Pacific/Port_Moresby
  &kZonePacific_Rarotonga, // Pacific/Rarotonga
  &kZonePacific_Tahiti, // Pacific/Tahiti
  &kZonePacific_Tarawa, // Pacific/Tarawa
  &kZonePacific_Tongatapu, // Pacific/Tongatapu
  &kZonePacific_Wake, // Pacific/Wake
  &kZonePacific_Wallis, // Pacific/Wallis
  &kZoneWET, // WET

};

}
}
