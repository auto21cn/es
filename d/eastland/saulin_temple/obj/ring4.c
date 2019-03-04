#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("ring of cat eye","猫眼石指环");
    add("id",({"ring"}) );
    set_short("猫眼石指环");
	set_long(@C_LONG
猫眼石是一种会随著阳光变换色彩的宝石, 
用它做成的指环能帮人带来福气。
C_LONG
 	        );
	set( "unit", "只" );
	set( "weight", 10 );
        set("material","stone");
	set( "type", "finger" );
	set( "armor_class", 0 );
	set( "defense_bonus", 4 );
	set( "value", ({ 100, "gold" }) );
}
