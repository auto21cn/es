#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("broken cloth","披襟褴衣");
        add("id",({"cloth"}) );
        set_short("披襟褴衣");
	set_long(@C_LONG
一件麻料编成的衣服，由於技巧不好，所以看起来烂烂的。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 5 );
	set( "value", ({ 500, "silver" }) );
}
