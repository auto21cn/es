#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("冰原");
	set_long( @LONG
极目远眺是片无垠无涯，银光闪闪，通体晶莹，不见任何尘沙的冰原。在这片
坚滑光润的地面上，竟会生著许多不知名的奇树，每株七、八抱宽，其高多达一、
二丈以上，全身覆盖著一片冰衣，里面却是琼枝碧叶，青葱欲滴。在你旁边还有个
十尺宽的小池子(pool)。
LONG
	);
	set( "exits", ([ 
           "north" : SCITY"ice2",
           "south" : SCITY"ice1",
            "east" : SCITY"ice1",
            "west" : SCITY"ice1",
        ]) );
	set("c_item_desc", ([
	   "pool":"一个直径约十尺的小池子，池水呈绿色，如果你泳技够，可以潜下(dive pool)去看看。\n" 
        ]) );
	reset();
}
void init()
{
    add_action("do_dive","dive");
}
int do_dive(string arg)
{
   string name;
   object player;
   if ( !arg || arg !="pool" ) return 0;
   player=this_player();
   name=this_player()->query("c_name");
   write("你双手往前一伸，两脚一蹬，扑向小池子而去！\n");
   tell_room(environment(player),sprintf(
     "%s往小池子潜了去下！\n",name),player);
   tell_object(player,@LONG


忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！
忽然，池底下一股强大的漩涡把你卷到别的地方处！



LONG   
   );
   player->move_player(SAREA"rest1.c","SNEAK");
   tell_object(player,"等你醒来时已经在一个凉亭里了。\n\n");
   tell_room(environment(player),sprintf("%s从旁边的莲池里爬了上来。\n",name),player);   
   return 1;
}
