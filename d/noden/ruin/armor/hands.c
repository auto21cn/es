// hands.c

#include "../lilia.h"

inherit ARMOR;

void create()
{
    set_name("magic gauntlets", "铠魔手");
    set_short("铠魔手");
    add("id", ({ "gloves", "gauntlets" }));
    set_long("由魔力幻化而成的手套。\n");
    set("unit", "双");
    set("weight", 0);
    set("type", "hands");
    set("material", "knight");
    set("armor_class", 4);
    set("defense_bonus", 4);
    set("no_sale", 1);
    set("prevent_drop", 1);
}

void unequip(int silent)
{
    tell_object(this_player(), "铠魔手拒绝离开你的身体!\n");
}

int remove()
{
    object p;
    p = environment(this_object());

    if (p && query("equipped"))
        ::unequip(0);
    return ::remove();
}
