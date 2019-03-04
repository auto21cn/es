#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "dragon gloves", "龙纹手套" );
	add( "id", ({ "dragon", "gloves", }) );
	set_short( "dragon gloves", "龙纹手套" );
	set_long(@C_TOPIC
一双华丽的手套，上面绣著一只活灵活现的飞龙，使得这个手套生色不少。
C_TOPIC
	);
	set( "unit", "双" );
	set( "type", "hands" );
	set( "material", "cloth");
        set( "armor_class", 4 );
	set( "defense_bonus", 5 );
	set( "special_defense",
	    ([ "acid":10, "poison":5 ]) );    
	set( "weight", 10 );
	set( "value", ({ 2500, "silver" }) );
}
