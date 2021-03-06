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
		"west" : TROOM"whirl2",
		"north" : TROOM"shallow6",
		"south" : TROOM"shallow14" ]) );
	set( "pre_exit_func",([
	        "west":"check_whirl",
	        "north":"check_shallow",
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
 int check_whirl()
 {
   int n;
   string place;
   write (
   "突然间，你发现你正游向一个大漩涡，强劲的水流不断的把你扯向漩涡中心。\n"
   "你不断的挣扎...................................\n\n\n\n"
   "你终於精疲力尽，随著漩涡卷入水底，死亡的阴影顿时占据了你的心灵.....\n");
   switch (n=random(3) ){
   case 0: place = "whirl1"; break;
   case 1: place = "whirl2"; break;
   case 2: place = "whirl3"; break;
   }
   this_player()->move_player( TROOM+place,"SNEAK");
   return 1;
 }
