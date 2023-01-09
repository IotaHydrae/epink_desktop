#ifndef __INDEX_H
#define __INDEX_H
#define INDEX_HTML_CONTENT "<!DOCTYPE html>\
\
<head>\
    <meta charset=\"UTF-8\">\
    <title>Xenia Clock</title>\
    <style>\
        body {\
            font-family: 'Courier New', Courier, monospace;\
            background-color: rgba(5, 14, 38, 0.85);\
        }\
\
        p,\
        label {\
            font-size: 18px;\
            font-weight: bold;\
        }\
\
        p,\
        h1,\
        h2,\
        h3,\
        h4,\
        label {\
            color: burlywood;\
        }\
\
        p,\
        label {\
            display: inline;\
            margin-left: 25%;\
            margin-right: 20px;\
        }\
\
        .center {\
            max-width: 50%;\
            margin: auto;\
        }\
\
        .radius_border {\
            border-style: solid;\
            border-radius: 20px;\
            border-width: 5px;\
            border-color: burlywood;\
            padding: 20px;\
        }\
    </style>\
</head>\
\
<body>\
    <form class=\"radius_border center\">\
        <h1 class=\"center\">Xenia Clock</h1><br />\
        <h4 class=\"center\">Connect to Your WIFI</h4><br /><br />\
        <p>SSID:</p><input type=\"text\" name=\"ssid\" placeholder=\"WiFi Name\"><br /><br />\
        <p>PSK :</p><input type=\"password\" name=\"psk\" placeholder=\"WiFi Password\"><br><br />\
        <label><input type=\"checkbox\" name=\"remember\" value=\"yes\"> Remember it</label><input type=\"submit\"\
            value=\"Connect\">\
    </form>\
</body>\
\
</html>\
"
#endif
