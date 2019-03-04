#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name("platinum necklace", "白金项链");
add( "id", ({ "necklace" }) );
	set_short( "白金项链" );
        set_long(
@C_LONG
这条白金的项链看来价值不斐，是奇维送给佩萝蒂丝的十八岁生日
礼物，由於锻造工艺细腻，这是佩萝蒂丝所喜爱的装饰品。
C_LONG
        );
	set( "unit", "条");
        set( "type", "misc" );
	set( "material", "light_metal" );
   set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "mental":6, "evil":-5, "fire":-2]) );                       
        set( "weight", 40 );
   set( "value", ({ 100, "gold" }) );
        set( "no_sale", 1);
}
