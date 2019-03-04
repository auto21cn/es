
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("front","前庭广场");
       set_long(@C_LONG
这里空气清新，你闻到一股淡淡的木菰气味，四周宽广
并有水声潺潺，你注意到前方有一座大宫殿，但由一於地势
较高，你必需从侧面的小径绕至宫庭侧殿再进入大宫庭，东
边则有一扇开启的石门，黝黑的地道不知通往何处。
C_LONG );
       set("exits",([
                     "northwest":"/d/noden/drow/r65",
                     "eastdown":"/d/noden/drow/r71",
                    ]));
       set("pre_exit_func",([
                     "eastdown":"check_knight"]));
       set("light",1);
       set("object",([
                      "skeleton":"/d/noden/drow/mob/m30",
                   ]));
}
