
#include "../layuter.h"

inherit ROOM;
int knife_control;
  
void create()
{
	::create();
	set_short("地下城");
	set_long( @C_LONG_DESCRIPTION
此处是一个古老的地下城房间，此处的墙壁及地板都是以大理石铺设成的同时墙上正
有几只火把燃烧著，这个房间里面到处堆满了许\多的竹简书，以及一张上面摆\满奇怪道具
的桌子，看起来像是一座祭坛，屋子的东侧有一个柜子，上面摆\著一些动物的头骨以及其
装著看去似蜥蜴类小动物□体的罐子，北侧则有一个龙形巨神像，无论以前有多丰富的旅
行经验，当你初次见到这房间时，都不免有惊怖的感觉。
C_LONG_DESCRIPTION
	);
	set("item_desc",([
	    "table":"这是一个摆\满各式各样奇特东西的桌子,它的物品中有一样发出奇特的光芒\n"])); 
	set( "light", 1 );
	set( "exits", ([
		"south" : Lcave"cave15"
	]) );
	set("objects",([
	    "flamen" : Ldmonster"flamen"])); 
	reset();
}

void init()
{
 add_action("do_search","search");
 }
void reset()
{
	::reset();
	knife_control=1;
}

int do_search(string arg)
{
	object obj;

	if( !arg || arg!="table" )
		return notify_fail( 
		"你在这里中找来找去，但并没有找到任何奇特的东西。\n"
		);
	if( knife_control ) {
		write( 
			"你仔细搜索桌子，结果找到一把奇特的铲子。\n"
		);
		obj = new(Lditem"shovel");
		obj->move(this_object());
                this_player()->set_explore("eastland#2");
		knife_control = 0;
		return 1;
	} else {
		write( 
			"你把整个桌子都翻遍了，但没有发现任何奇特的东西。\n"
		);
		return 1;
	}
}
