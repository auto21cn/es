// deathknight.c

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Death Knight", "地狱骑士");
    add("id", ({ "knight", "death" }));
    set_short("地狱骑士");
    set("unit", "位");
    set_long("传说中最厉害最可怕的不死骑士。\n");
    set("race", "undead");
    set("gender", "neutral");
    set("unbleeding", 1);
    set("max_hp", 5000);
    set("hit_points", 5000);
    set_perm_stat("str", 23);
    set_perm_stat("dex", 23);
    set_perm_stat("pie", 21);
    set_perm_stat("kar", 22);
    set_perm_stat("int", 21);
    set_natural_weapon( 50, 10, 20 );
    set_natural_armor( 80, 50 );
    set_skill("dodge", 100);
    set_skill("longblade", 100);
    set_skill("parry", 100);
    wield_weapon(WP"scythe");
    set("killer", 1);  
}

void die()
{
    object *items;
    int i;

    items = all_inventory(this_object());

    for(i = 0; i < sizeof(items); i++)
        items[i]->remove();

    tell_room(environment(this_object()), "地狱骑士发出一声狂笑：「你以为这样就能打倒我吗？做梦！」\n\n地狱骑士的尸体又站了起来！\n\n", this_object());
    set("alt_corpse", MOB"deathknight");
    
    ::die(1);
}
