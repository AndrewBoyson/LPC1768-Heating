#include "web/http/http.h"

//Use http://tomeko.net/online_tools/cpp_text_escape.php   to convert from text to c-multiline
//Use http://tomeko.net/online_tools/cpp_text_unescape.php to convert from c-multiline to text

static const char* script =
#include "web-boiler-script.inc"
;
const char* WebBoilerScriptDate = __DATE__;
const char* WebBoilerScriptTime = __TIME__;

void WebBoilerScript()
{
    HttpOk("application/javascript; charset=UTF-8", "max-age=3600", WebBoilerScriptDate, WebBoilerScriptTime);
    HttpAddText(script);
}
