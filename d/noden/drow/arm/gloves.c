#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name("snake gloves", "青蛇手套");
   add( "id", ({ "gloves" }) );
	set_short( "青蛇手套" );
        set_long(
@C_LONG
这是一双由蛇皮所缝制的手套，上面有美丽的纹路，具有绝佳的伸
缩性，能适合任何尺寸的人来配戴。
C_LONG
        );
        set( "unit", "双");
        set( "type", "hands" );
        set( "material", "leather" );
   set( "armor_class", 4 );
   set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "mental":6, "evil":-5, "fire":-2]) );                       
	set( "weight", 25 );
	set( "value", ({ 180, "gold" }) );
}
