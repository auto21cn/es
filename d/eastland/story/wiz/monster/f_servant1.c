#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(9);
	set_name( "female servant", "宫女" );
	add("id",({"servant"}));
	set_short( "宫女");
	set_long(@C_LONG
一色浅黄宫装的女ㄚ□，正在服侍著公主。
C_LONG
        );
        set( "wealth/silver",80);
        set( "gender","female");
        set_natural_armor(45,0); 
        set_natural_weapon( 15,7,15 );
}
