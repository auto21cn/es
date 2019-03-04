#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name( "coral blade", "琅□宝刀" );
    add( "id", ({ "blade" }) );
    set_short( "琅□宝刀" );
	set_long(
        "这是一把用万年金珊瑚打造而成的长刀, 通体金亮, 但刀刃中隐约透出\n"
        "一丝红光, 似乎是因沾满血腥所致。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 90 );
    set( "weapon_class", 30 );
    set( "min_damage", 15 );
    set( "max_damage", 28 );
//    set( "bleeding", 15 );
    set( "value", ({ 1200, "silver" }) );
}
