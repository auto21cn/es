// 王药师的茅屋外的小广场
#include <mudlib.h>
#include "wang.h"
inherit ROOM;
inherit DOORS;

void create()
{
 	::create();
        set_short("空地");
	set_long(@C_LONG
这里原本是杂草丛生的地方，不过已经被清出一片空地了。地上铺了些
待晒乾的草药, 空地的另一边堆了一些柴, 还有一个竹笼。前方有个小茅屋。
C_LONG
);
	set("light", 1);
	set("exits",([
		"north" : WANG"room1",
		"south" : WANG"room3", 
		"enter" : WANG"room6",
	]));

	create_door("enter","out",([
		"keyword" : ({"iron door","door"}),
		"name" : "iron door",
		"c_name" : "铁门",
		"c_desc" : "这是一扇厚重的铁门, 门下有个很小的小开口",
		"status" : "locked",
		"lock"	: "WANG",
	]) );
		
	reset();
}


