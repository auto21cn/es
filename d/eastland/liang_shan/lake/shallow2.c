#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("湖边");
	set_long( @C_LONG_DESCRIPTION
这里是湖中的浅水区域，水并不算深，大约只到腰际，就算不游泳也不必担心
会有危险，也因此你才能好好欣赏到这大湖的景色。湖水一望无际，烟波浩瀚，几 
只白鹭闲闲飞越水畔，在目力难及之处，似乎有群山相绕，但由於湖上的烟霞，看
得不是很清楚。
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"west" : TROOM"shallow1",
		"north" : TROOM"beach2",
		"south" : TROOM"shallow3" ]) );
	set( "pre_exit_func",([
	        "west":"check_shallow",
	        "north":"check_beach",
	        "south":"check_shallow"
	        ]));
	reset();
}
int check_shallow()
{
    if ((int)this_player()->query_skill("swimming")-random(5)<13){
    write (
    "你努力的想游到别处，但你发现身体一动也不动.....\n");
  return 1;
    }
    else return 0;
}
int check_beach()
{
    write (
    "你七手八脚的爬上沙滩，沾的全身都是沙土...\n");
return 0;
}
