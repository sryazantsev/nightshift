/*
  This file is part of NightShift Message Library.

  NightShift Message Library is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  NightShift Message Library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with NightShift Message Library. If not, see <https://www.gnu.org/licenses/>. 
*/

#ifndef EVENT_H
#define EVENT_H
#include <inttypes.h>
#include "device-event.h"
#include "dozor-crypto.h"
#include "utils.h"

#define EVENT_COUNT 64
#define MAX_EVENT_NAME_LENGTH 25
#define COMMON_EVENT_SCOPE "Common"
#define AUTH_EVENT_SCOPE "Auth"
#define USER_EVENT_SCOPE "User"
#define SECURITY_EVENT_SCOPE "Security"
#define KEEP_ALIVE_EVENT_SCOPE "KeepAlive"
#define DEFAULT_DATA_POSITION 0
#define REPORT_TEMP_DATA_POSITION 1
#define USER_DATA_POSITION 3
#define COMMAND_RESULT_DATA_POSITION 4
#define VERSION_DATA_POSITION 1
#define VERSION_MASK 0x7

typedef struct COMMON_EVENT {
  uint8_t typeId;
  uint8_t site;
  char timestamp[25];
  char data[256];
} CommonEvent;

char* getKeepAliveEvent(uint8_t site, DeviceInfo* info);
char* convertDeviceEventToCommon(uint8_t site, DeviceEvent* deviceEvent);
static char * getFirmwareVersionEventData(uint8_t type, uint8_t * data, uint8_t len);
static char * getCommandEventData(uint8_t type, uint8_t * data, uint8_t len);
static char * getReportEventData(uint8_t type, uint8_t * data, uint8_t len);
static char * getAuthEventData(uint8_t type, uint8_t * data, uint8_t len);
static char * getSecurityEventData(uint8_t type, uint8_t * data, uint8_t len);
static char * getCommonEventData(uint8_t type, uint8_t * data, uint8_t len, char * scope);
static char * getZoneEventData(uint8_t type, uint8_t * data, uint8_t len);
static char * getSectionEventData(uint8_t type, uint8_t * data, uint8_t len);
static char * getData(uint8_t * data, uint8_t index, uint8_t len);
static char * getEventNameByType(uint8_t type);
#endif