#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "spider ankh", "蜘蛛圣标" );
	add( "id", ({ "ankh" }) );
   set_short( "蜘蛛圣标" );
	set_long(
		"这是一个小型的圣标，上面扎著一条破布，圣标中间一个圆形的\n"
		"突起上刻著一个蜘蛛的记号。\n"
	);
	set( "type", "misc" );
   set( "material", "wood" );
   set( "weight", 50 );
	set( "armor_class", 0 );
   set( "defense_bonus", 5 );
   set( "special_defense", ([ "poison":20, "acid" : -25 ]) );
   set( "value", ({ 980, "silver" }) );
   set( "extra_skills", ([ "depoison" : 10 ]) );
}
