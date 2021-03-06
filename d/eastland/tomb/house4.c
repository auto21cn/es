#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("书房");
	set_long( 
@C_LONG_DESCRIPTION
这是一个打扫得相当乾净的书房，四周的家具摆设、悬挂的字画等等，在在都显示出此
间主人的品味高尚。墙边的书架上放满了各种文字的书籍，大多数都是你看不懂的文字。一
阵阵袅袅的烟自书桌上的小香炉飘起，淡淡的檀香令你觉得十分舒服。你看到书桌上有一些
七彩的石头(stones)三三两两的放著，似乎有点儿古怪。
C_LONG_DESCRIPTION
	);

	add( "c_item_desc" , ([
		"stones" : @STONE_DESC
当你注视著这些石头时，感到一阵头晕目眩而看不清楚。
STONE_DESC
,  
	]) );
	set( "exits", ([ 
		"south" : TOMB"/house2",  ]) );
	set( "objects", ([
		"master" : MOB"/master" ]) );
	reset();	
}

void init() 
{
	object *obj;
	int i;
	
	obj = all_inventory(this_object());
		i = sizeof(obj);
	if( random(7) > 2 ) {
		while( i-- ) {
			if( (int)obj[i]->query("player_invisible") ) 
				obj[i]->set("player_invisible",0); }
		tell_room(this_object(),"桌上的七彩石发出阵阵的波动....\n");
	}
}

int clean_up() {return 0;}