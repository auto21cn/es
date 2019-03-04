#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name("copper bracers", "黄铜手环");
   add( "id", ({ "bracers" }) );
	set_short( "黄铜手环" );
        set_long(
@C_LONG
这是黄铜打造的手环，拿起来有厚重的感觉。
C_LONG
        );
	set( "unit", "个");
        set( "type", "hands" );
	set( "material", "heavy_metal" );
	set( "armor_class", 4 );
	set( "defense_bonus", 2 );                       
	set( "weight", 60 );
	set( "value", ({ 170, "silver" }) );
}
