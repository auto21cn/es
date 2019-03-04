#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("魔族通关衙门");
     set_long(@C_LONG
这儿是树雷王家的驻外办事处，在此设衙门不但可以为过往商旅办通
关手续，以应因魔族目前的戒严时期；更可就近监视蜥蜴人领事馆及武士
校场的一举一动！
C_LONG
             );
     set("objects",([
             "elder" : IMON"elder"
                   ]));         
     set("light",1);
     set("exits",([
               "west"  : ITOWN"square08"
            ]) );
     reset();
#include <replace_room.h>
 }