#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("武士战斗教练场");
     set_long(@C_LONG
这儿是武士堡的战斗教练场，美其名为教练场，实际上，它却是武士
堡用来埋藏军队的伪装，为的是就近监视蜥蜴人及魔族的动向；一旦有些
许的风吹草动，那麽一场惊天动地的杀戮恐怕就无法避免了
C_LONG
             );
     set_outside("island");
     set("light",1);
     set("exits",([
               "south"  : ITOWN"square02"
            ]) );
     reset();
#include <replace_room.h>
 }
