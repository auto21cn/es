#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("cloth","暖衣");
        add("id",({"cloth"}) );
        set_short("暖衣");
	set_long(@C_LONG
这不过是一件寻常的衣服。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 4 );
	set("special_defense",
	     (["fire":5,"cold":5]) );
	set( "value", ({ 350, "silver" }) );
}
