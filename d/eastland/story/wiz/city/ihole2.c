#include "../../story.h"

inherit ROOM;
void create()
{
        ::create();
	set_short("圣池");
	set_long( @LONG
这里就是传说中的圣池，孕育著圣水－「天堂之水」。其实，这里的「天堂之
水」并非真正的液体，乃是一种气体，需要经过凝结之後才会成为真水。大祗天生
灵物必有神兽呵护，想必你已经历过了在圣池的周围潜伏著的一只千年寒冰精魂修
练而成的妖物的考验。
LONG
	);
        set("exits",([
          "south":SCITY"ihole1"
        ]) );
        set("heaven_water",1); 
	reset();
}
