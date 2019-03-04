#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Raingod's robe","雨师之袍");
        add("id",({"robe"}) );
        set_short("雨师之袍");
	set_long(@C_LONG
一件透明薄如蝉翼的衣服，但却坚韧无比，令人无法轻易撕开它。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "special_defense",(["cold":-20,"magic":30]));
	set( "value", ({ 1200, "silver" }) );
}
