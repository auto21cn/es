// leggings.c

#include "../moon.h"

inherit ARMOR;

void create()
{
    set_name("magic leggins", "月神裆");
    set_short("月神裆");
    add("id", ({ "gloves", "gauntlets" }));
    set_long("由月神剑的神力幻化而成的胫甲。\n");
    set("unit", "件");
    set("weight", 0);
    set("type", "legs");
        set( "armor_class", 150 );
        set( "defense_bonus", 150 );
        set("special_defense",(["all":100])) ;
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "月神裆拒绝离开你的身体!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
