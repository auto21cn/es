#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("doctor cloth","医者之袍");
        add("id",({"cloth"}) );
        set_short("医者之袍");
	set_long(@C_LONG
这是『一代神医 小雪子』最爱穿的衣服。虽然上面破了几个洞, 而且缝缝补补几
个补丁,好像一用力就会被撕个稀巴烂, 但由於是小雪子死去的师父所赠, 对她而
言异常珍贵。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",110 );
	set( "type", "body" );
        set("material","healer");
	set( "armor_class", 35 );
	set( "defense_bonus", 8 );
	set("special_defense",
	     (["fire":-10,"poison":15,"acid":10]) );
	set( "value", ({ 4000, "silver" }) );
}
