#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("洞穴");
	set_long( @C_LONG_DESCRIPTION
你进入了山壁上的洞穴，洞穴的四周插满了火把，照的四周一片明亮，许\多山贼
在洞穴里钻来钻去，只有少数人注意到你的进入而投以怀疑的目光。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"out" : TROOM"yard1", 
		"eastdown" : TROOM"cave4" ]) );
	reset();
}
int clean_up() { return 0; }