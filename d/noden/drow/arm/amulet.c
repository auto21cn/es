#include <mudlib.h>
inherit ARMOR;

void create()
{
   set_name("copper rings", "铜颈环");
   add( "id", ({ "rings" }) );
	set_short( "铜颈环" );
        set_long(
@C_LONG
这个铜环看起来已经年代久远，但是仍然磨的光亮，是黑暗精灵的
装饰品。
C_LONG
        );
	set( "unit", "个");
        set( "type", "misc" );
	set( "material", "heavy_metal" );
	set( "defense_bonus", 2 );                       
	set( "weight", 60 );
	set( "value", ({ 200, "silver" }) );
}
