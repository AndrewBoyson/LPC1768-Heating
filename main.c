#include "lpc1768/crt.h"
#include "lpc1768/lpc1768.h"
#include "lpc1768/led.h"
#include "clk/clk.h"
#include "log/log.h"
#include "net/net.h"
#include "1-wire/1-wire.h"
#include "heating/heating.h"
#include "settings/settings.h"
#include "web/web.h"
#include "heating/values.h"
#include "wiz/wiz/wiz.h"
#include "lpc1768/debug.h"

int main()
{
				CrtInit();
            Lpc1768Init();
                LogInit(ClkNowTmUtc, 0);
                ClkInit();
    if (   SettingsInit()) goto end; //Uses log. Fram is initialised here and bombs out if full
				NetInit("Heating", "p1.31", "p1.30");
                WebInit("Heating");
            OneWireInit("p0.4"); //P0.4 == dip30
            HeatingInit();
             ValuesInit();
                WizInit();
				
    while (1)
    {
            LogMain();
            ClkMain();
            NetMain();
         ValuesMain();
        OneWireMain();
        HeatingMain();
        Lpc1768Main();
            WizMain();
    }

end:
    Led1Set(1); Led2Set(1); Led3Set(1); Led4Set(1);
	while (1) {;}
    return 0;
}