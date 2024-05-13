#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "1-wire/ds18b20.h"
#include "settings/settings.h"

static char* hotWaterRom;

uint16_t HotWaterGetDS18B20Value(){ return DS18B20ValueFromRom(hotWaterRom); }

static void setHotWaterRom(char* value) { memcpy(hotWaterRom,  value, 8); SetHotWaterRom(hotWaterRom); }

void HotWaterInit()
{
	hotWaterRom = DS18B20AddRom(setHotWaterRom, "HotWater");
    GetHotWaterRom(hotWaterRom);
}