"//System script\n"
"'use strict';\n"
"\n"
"let serverName   = '';\n"
"let fileName     = '';\n"
"let readInterval = 0;\n"
"let writeSize    = 0;\n"
"let count        = 0;\n"
"let startTime    = null;\n"
"let framUsed     = 0;\n"
"\n"
"function parse()\n"
"{\n"
"    let lines = Ajax.response.split('\\n');\n"
"    serverName   =                       lines[0];\n"
"    fileName     =                       lines[1];\n"
"    readInterval = Ajax.hexToSignedInt16(lines[2]);\n"
"    writeSize    = Ajax.hexToSignedInt16(lines[3]);\n"
"    count        = Ajax.hexToSignedInt16(lines[4]);\n"
"    startTime    =     new Date(parseInt(lines[5], 16) * 1000);\n"
"    framUsed     = Ajax.hexToSignedInt16(lines[6]);\n"
"}\n"
"function display()\n"
"{\n"
"    let elem;\n"
"    elem = Ajax.getElementOrNull('ajax-server-name'  ); if (elem) elem.value = serverName;\n"
"    elem = Ajax.getElementOrNull('ajax-file-name'    ); if (elem) elem.value = fileName;\n"
"    elem = Ajax.getElementOrNull('ajax-read-interval'); if (elem) elem.value = readInterval;\n"
"    elem = Ajax.getElementOrNull('ajax-write-size'   ); if (elem) elem.value = writeSize;\n"
"    elem = Ajax.getElementOrNull('ajax-count'        ); if (elem) elem.textContent = count;\n"
"    elem = Ajax.getElementOrNull('ajax-start-time'   ); if (elem) elem.textContent = startTime.toISOString().substr(0, 19).split('T').join(' ') + ' UTC';\n"
"    elem = Ajax.getElementOrNull('ajax-fram-used'    ); if (elem) elem.textContent = framUsed;\n"
"}\n"
"\n"
"Ajax.server     = '/system-ajax';\n"
"Ajax.onResponse = function() { parse(); display(); };\n"
"Ajax.init();\n"
""