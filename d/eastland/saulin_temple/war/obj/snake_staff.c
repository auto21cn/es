
#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("staff of snake","蛇杖");
        add("id",({"staff",}) );
	set_short("蛇杖");
	set_long(@C_LONG
这是一把漆黑的钢杖，铸成恶魔面孔的杖头上正有两只五彩斑斓的
怪蛇上下地游走著，不时昂首吐信，显得诡异非凡。
C_LONG
               );

        set( "unit", "把" );
        set( "weapon_class", 24 );
	set("type","blunt");
        set( "min_damage", 15 );
        set( "max_damage", 30 );
	set( "weight", 180 );
        set( "value", ({ 170, "gold" }) );
}
