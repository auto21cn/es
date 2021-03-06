#include <mudlib.h>

//inherit ROOM;

inherit "/std/room/std_storage.c";

void create()
{
	::create();
	set_short("储藏室");
	set_long(@LONG
这里是一间储藏室，地上散落著一些武器和装备，这是为了让公会中的书生
能够更团结而设的，也是为了能够让书生们有饮水思源之心，能长存己利利人、
己达达人的胸怀，墙上有贴一张告示(note)。
LONG
	);
 /*       
        set( "item_desc", ([
             "note": "储藏室是用来放武器防具容器等重要物资的,空间有限\n"
                     "请不要当垃圾堆般的堆放无用途的东西。\n"
           ]) );
*/
	set("exits", ([
		"down"	: "/d/scholar/scholar/embattle_room",
		]) );
        set("light",1);
     //   set("container_res",1);
       set("weapon_res",({20,13}));
       set("armor_res",([
                         "body" : 20   , "legs"   : 7 ,
                         "feet" : 6    , "cloak"  : 8 ,
                         "head" : 5    , "arms"   : 4 ,
                         "misc" : 6    , "finger" : 5 ,
                         "hands" : 5   , "globe"  : 23 ,
                         "shield" : 6  , "saddle" : 9 ,
                         "kernal" : 4  , "tail"   : 8 ,
                         "others" : 6,
                         ]) ) ;
        set("max_amount",50);
        set("class_name","scholar");
        set("msg_arg","老猫");
        reset();  
}

