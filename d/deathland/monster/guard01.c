#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(11);
    set_name("dwarf guard","矮人守卫");
    add ("id", ({ "guard","dwarf"}) );
    set_short( "a dwarf guard",
           "矮人守卫");
	set_long(@LONG
一个矮人守卫正保卫著矮人的村庄.
LONG
	);
    set("alignment",10);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "个" );
    set_perm_stat( "dex",  13);
    set_perm_stat( "str",  17);
    set_perm_stat( "int",   8);
    set_perm_stat( "piety", 8);
    set_perm_stat( "karma",15);
	set_skill("shortblade",60);
	set_skill("parry",55);
    set ("max_hp",350);
    set ("max_sp",0);
    set ("hit_points",350);
    set ("spell_points",0);
    set ("wealth", ([ "gold":13]) );
    set_natural_weapon(12,4,9);
	set_natural_armor(35,0);
    set ("weight", 350);
    set("chat_chance",15);
    set("chat_output",({
        "守卫说:离开这里,离开我们的村落.\n"
       }) );
    equip_armor(Armour"/ringmail01");
    wield_weapon(Weapon"/shortsword02");
    equip_armor(Armour"/armband01");
}


