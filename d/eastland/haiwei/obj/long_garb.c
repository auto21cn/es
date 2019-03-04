#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "long garb", "长袍马褂" );
	add( "id", ({ "garb" }) );
	set_short( "长袍马褂" );
	set_long("这是一件很普通的长袍马褂。\n");
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 8 );
	set( "defense_bonus", 1 );
	set( "weight", 50 );
	set( "value", ({ 240, "silver" }) );
}
