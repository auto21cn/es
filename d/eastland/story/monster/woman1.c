#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "wing woman", "羽民妈妈" );
	add( "id", ({ "woman" }) );
	set_short( "羽民妈妈" );
	set_long(@C_LONG
一位典型的羽民族成年女子，她正在忙著处理刚采收下来的葡萄。
C_LONG
        );
        set( "race","羽民" );
	set( "gender", "female" );
	set( "alignment", 100 );
        set_natural_armor(50,2);
        set_natural_weapon( 17,9,10 );
}
