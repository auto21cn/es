#include <mudlib.h>

inherit WEAPON;
void create()
{
	set_name( "standard shortsword", "制式短剑" );
	add( "id", ({ "shortsword","sword","standard" }) );
	set_short( "制式短剑" );
	set_long(
            "这是一把标准的短剑，不论重量或是长度都很适合初学者使用。\n"
	);
	set( "unit", "把" );
	set( "type", "shortblade" );
	set( "weight", 50 );
	set( "weapon_class", 15 );
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "value", ({ 290, "silver" }) );
}
