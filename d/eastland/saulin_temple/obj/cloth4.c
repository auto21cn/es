#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("silver pallium","银灰补衲");
    add("id",({"cloth","pallium"}) );
    set_short("银灰补衲");
	set_long(@C_LONG
这是一件看来很新的补衲, 用灰布织成的并滚上银边, 只有级位相
当高的和尚有资格穿著, 它长年在庙中被使用, 闻起来有一股上好
的薰香味 !
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 90 );
        set("material","monk");
	set( "type", "body" );
	set( "armor_class", 19 );
	set( "defense_bonus", 4 );
	set( "value", ({ 1691, "silver" }) );
}
