#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("映世村广场");
     set_long(@C_LONG
这儿就是映世村最著名的广场，地上铺著一片片的大石板，穿插著几
株新植不久，刚发新叶的榕树，走在这儿，不禁让人心情放松。在广场的
中间，伫立著一幢白色亮晶晶的建筑物，没错，这就是远近著名的和平纪
念堂。如果你来到这儿，却忘了进去参观，那麽，你一定会後悔的哦！
C_LONG
             );
     set_outside("island");
     set("light",1);
     set("exits",([
                 "west" : ITOWN"square05",
               "south"  : ITOWN"i_place",
               "north"  : ITOWN"square07"
            ]) );
     reset();
#include <replace_room.h>
 }