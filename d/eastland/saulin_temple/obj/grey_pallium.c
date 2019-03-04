#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("grey pallium","灰补衲");
    add("id",({"cloth","pallium"}) );
    set_short( "灰补衲");
	set_long(
		"这是一件看来很陈旧的百衲袈裟，用灰布织就并经过高僧的祝福，是一件上好的袈裟。\n"
	);
	set( "unit", "件" );
	set( "weight", 150 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 9 );
	set( "value", ({ 800, "silver" }) );
}
