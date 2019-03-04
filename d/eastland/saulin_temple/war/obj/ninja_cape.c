
#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "ninja cape", "忍者披风" );
        add( "id", ({ "cape" }) );
        set_short( "忍者披风" );
        set_long(@C_LONG
这是一件黑色的披风，上面有各式各样奇怪的迷彩花纹。这就是
传说中的忍术 － 隐身术的必备法宝。
C_LONG
        );
        set( "unit", "件" );
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 4 );
        set( "defense_bonus", 4);
        set( "weight", 70 );
	set( "special_defense", ([ "evil":5,"divine":-7 ]) );
        set( "value", ({ 1200, "silver" }) );
}
