#include <stdio.h>
#include <string.h>

#include "web/http/http.h"
#include "web-this/web-nav-this.h"
#include "web/web-add.h"
#include "log/log.h"
#include "build.h"

void WebSystemHtml()
{
    HttpOk("text/html; charset=UTF-8", "no-cache", NULL, NULL);
    WebAddHeader2("System", "settings.css", "ajax-class.js", "system.js");
    WebAddNav(SYSTEM_PAGE);
    WebAddH1("System");

    WebAddH2("TFTP");
    WebAddAjaxInput   ("Server url",                      5, "ajax-server-name",   "tftpserver"   );
    WebAddAjaxInput   ("File (strftime)",                11, "ajax-file-name",     "tftpfilename" );
    WebAddAjaxInput   ("Interval (secs) 0=no",            5, "ajax-read-interval", "tftpreadint"  );
    WebAddAjaxInput   ("Records per backup 0=no",         5, "ajax-write-size",    "tftpwriteint" );
    WebAddAjaxLabelled("Count",                              "ajax-count"                         );
    WebAddAjaxLabelled("Started",                            "ajax-start-time"                    );

    WebAddH2("FRAM");
    WebAddAjaxLabelled("Used",                               "ajax-fram-used"                     );
    
    WebAddH2("Compiler");
    WebAddLabelledText("Version", __VERSION__);
    WebAddH2("C standard");
    WebAddLabelledInt("YYYYMM", __STDC_VERSION__);
    WebAddH2("Build");
    WebAddLabelledText("Date", BuildGetDate());
	
    WebAddEnd();
}
