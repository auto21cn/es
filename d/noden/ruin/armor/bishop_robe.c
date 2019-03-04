// bishop_robe.c

#include "../lilia.h"

inherit ARMOR;

void create()
{
    set_name("bishop robe", "祭司袍");
    add("id", ({ "robe" }));
    set_short("祭司袍");
    set_long("这是大祭司卡帕的袍子，上面用金线绣著他的名字。\n");
    set("unit", "件");
    set("weight", 80);
    set("type", "body");
    set("armor_class", 22);
    set("defense_bonus", 5);
    set("material", "healer");
    set("value", ({ 2000, "silver" }));
}

