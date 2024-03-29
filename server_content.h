#ifndef SC
#define SC

String content=
"<html>"
"  <head>"
"      <meta name=\"viewport\" content=\"width=device-width\">"
"    <title>REAW Train</title><meta charset=\"utf-8\"/>"
"    <link rel=\"icon\" href=\"http://rpi.turai.hu/img_show/air.png\" type=\"image/icon type\">"
"    <link rel=\"stylesheet\" type=\"text/css\" href=\"http://rpi.turai.hu/storage2/src/css/style.css\">"
"    <link rel=\"stylesheet\" type=\"text/css\" href=\"http://rpi.turai.hu/dash/train/train.css\">"
"    <script src=\"http://rpi.turai.hu/dash/train/train.js\"></script>"
"  </head><body>"
"    <a href=\"http://rpi.turai.hu/\" title=\"Vissza a főoldalra\" style=\"position:fixed;\"><img src=\"http://rpi.turai.hu/storage2/src/img/b_undo.png\" width=\"28px\"></a>"
"    <center>"
"      <h1 style=\"color:#0c343d\"><img src=\"http://rpi.turai.hu/img_show/air.png\" width=\"60px\"><img src=\"http://rpi.turai.hu/storage2/src/img/reaw_1.svg\" height=\"50px\"><u>Train</u></h1>"
"        <div class=\"kontener\"> "
"          <table border=\"1px\" height=\"400px\">"
"            <tr>"
"              <td colspan=\"2\" style=\"text-align:center; vertical-align:bottom;\" width=\"250px\">"
"                <h2>Mozdony1 <img src=\"http://rpi.turai.hu/img_show/train.png\" width=\"50px\" style=\"vertical-align: top;\"/></h2>"
"              </td>"
"            </tr>"
"            <tr>"
"              <td width=\"50%\" height=\"38%\" style=\"vertical-align:top; text-align:center;\">"
"                <img src=\"http://rpi.turai.hu/img_show/engine.png\" width=\"30px\" style=\"vertical-align: middle;\"/> Motor <br><br>"
"                <label style=\"vertical-align:bottom;\" class=\"switch\">"
"                  <input type=\"checkbox\" id=\"engine1\" onchange='engine(\"engine1\");'>"
"                  <span class=\"slider round\"></span>"
"                </label>"
"              </td>"
"              <td  rowspan=\"2\" style=\"text-align:center; vertical-align:top;\">"
"                <h2>Sebesség</h2>"
"                <input id=\"speed1\" type=\"range\" orient=\"vertical\" value=\"0\" min=\"0\" max=\"255\" onchange='setSpeed(\"speed1\");'/>"
"              </td>"
"            </tr>"
"            <tr>"
"              <td height=\"38%\" style=\"vertical-align:top; text-align:center;\">"
"                <img src=\"http://rpi.turai.hu/img_show/right_r.png\" width=\"18px\">Menetirány<br>"
"                <button onclick='changeDir(\"left\")'><font id=\"left\" style=\"color:red; vertical-align:middle; font-size:50px;\">&#8592;</font></button>"
"                <button onclick='changeDir(\"right\")'><font id=\"right\" style=\"color:green; vertical-align:middle; font-size:50px;\">&#8594;</font></button>"
"              </td>"
"            </tr>"
"            <tr>"
"              <td colspan=\"2\">"
"                <p id=\"debug\">&#8205;</p>"
"              </td>"
"            </tr>"
"          </table>"
"        </div>"
"    </center>"
"    <div class=\"footer kontener\">Powered by Turai Botond &copy;2021</div>"
"  </body>"
"</html>"
;
#endif
