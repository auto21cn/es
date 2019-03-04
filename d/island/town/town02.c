#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("映世村大街");
     set_long(@C_LONG
这是映世村连外的的主要通道之一，再往南就是村落的广场，那儿就
是谪仙岛最繁荣的地方，如果你有任何需要，应该都可以在那儿找到。在
南方的不远处，有一幢非常显眼的白色建筑，那就是和平纪念堂，来这里
观光的人，都应该去那儿逛一逛。东边有一家驿站，西边则是武士战斗教
练场。西边墙上有些字(word)。
C_LONG
             );
     set_outside("island");
     set("item_desc",(["word":@LONG
      
     入口不在这边啦！
LONG
     ]));
     set("light",1);
     set("exits",([
               "east"   : ITOWN"post_office",
               "north"  : ITOWN"town01",
               "south"  : ITOWN"square01"
            ]) );
     reset();
#include <replace_room.h>     
 }