#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("ruby ring","红宝石戒指");
        add("id",({"ring"}) );
         set_short( "ruby ring","红宝石戒指");
	set_long(
"这是由红宝石所制成的美丽戒子，看来价值不菲....\n"
);
	set( "unit", "个" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material","element");
	set( "defense_bonus", 5 );
	set( "equip_func","equip_ring");
	set( "value", ({ 880, "silver" }) );
        set("extra_skills",(["dodge":-5,"unarmed":-10]));
}
void equip_ring()
{
object holder;
    holder=this_player();
    tell_room(environment(holder),
    holder->query("c_name")+"套上一只亮丽的红宝石戒指....\n"
    ,({holder}));
    tell_object(holder,
    "你小心翼翼的套上红宝石戒指....\n");
return ;
}