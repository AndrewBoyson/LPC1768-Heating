#include "web/http/http.h"

//Use http://tomeko.net/online_tools/cpp_text_escape.php   to convert from text to c-multiline
//Use http://tomeko.net/online_tools/cpp_text_unescape.php to convert from c-multiline to text

static const char* script =
#include "web-program-script.inc"
;
const char* WebProgramScriptDate = __DATE__;
const char* WebProgramScriptTime = __TIME__;

void WebProgramScript()
{
    HttpOk("application/javascript; charset=UTF-8", "max-age=3600", WebProgramScriptDate, WebProgramScriptTime);
    HttpAddText(script);
}
