#include <takeda.h>

inherit ROOM;

void create()
{
	object ling;
	::create();
	set_short( "点将台" );
	set_long(
	"这里是梁山泊的点将台，站在这里对前方的演武场，一览无遗，许多\n"
	"人正在台下操练阵法。辉煌的旗帜簇拥著一座四丈高台，台上烟云袅绕，\n"
	"如在云中。台上一具千斤巨鼎，袅绕的烟云，就是从鼎中飘出来的，鼎旁\n"
	"罗列著三十六张紫檀交椅。一个全身戎装的中年人，神情威严，卓立在铜\n"
	"鼎前，正注视著台下。\n"
	);
	set( "light",1 );
        set( "c_item_desc",(["chair":
        "正当你端详这些交椅时，林冲冷冷的瞪了你一眼，你急忙将目光转向台下。\n"
        ]));
        set_outside("eastland");
        set( "exits", ([
                "south"  : TROOM"plaza5",    
                "north"  : TROOM"path5",
        ]) );
        ling = new(TMONSTER"lin");
        ling->move(this_object());
        set( "objects",([
                "bandit":TMONSTER"small_bandit",
        ]) );        
        reset();
}
void init()
{
add_action("do_sit","sit");
}
int do_sit(string arg)
{
if ( !arg || arg!="chair") return notify_fail(
"坐什麽?\n");
if ( ! present("lin") ){
   write (
   "你舒服的躺在紫檀交椅上，感觉人世的喧闹离你而去\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"舒服的躺在紫檀交椅上，安详的闭上了眼睛\n"
      ,this_player());
}
else {
   write (
   "正当你想坐下时，林冲伸出丈八蛇矛抵住你後心，说道: 这不是你能坐的\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"想要坐下休息，但却被林冲制止了．\n"
   ,this_player());
}
return 1;
}
int clean_up() { return 0; }
