#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "pallium", "袈裟" );
	set_short( "袈裟" );
	set_long("这是一件很普通的和尚穿的袈裟。\n");
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 1 );
	set( "defense_bonus", 3 );
	set( "weight", 50 );
	set( "value", ({ 270, "silver" }) );
}
