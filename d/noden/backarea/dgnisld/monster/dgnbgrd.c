#include "../dgnisld.h"

inherit MONSTER;

void create ()
{
	object    obj;
	object    sword;

	::create();
	set_level(10);
	set_name( "Guard", "守护者" );
	add ("id", ({ "guard",}) );
	set_short( "a guard for dragon ball", "保护龙珠的守护者" );
	set_long(
            "The guard protects the dragon ball from others.\n",
	    "他是保护龙珠的人，你想得到龙珠便必须打败他。\n"
	);
	
	set_perm_stat( "dex", 10 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 10);
	set ("max_hp", 500);
	set ("max_sp", 500);
	set ("hit_points", 500);
	set ("spell_points", 500);
	set ("wealth", ([ "gold": 5 ]) );
	set ("gender", "male");
	set ("exp_reward",2000);
	set ("unit", "个");
	set ("natural_weapon_class1", 10);
	set ("natural_armor_class", 10);
	set ("natural_min_damage1", 20);
	set ("natural_max_damage1", 30);
    set ("weight", 500);
                
	set ("chat_chance", 5);
	set ("chat_output", ({
	    "Guard says: You can never get the Dragon Ball!\n",
        "守护者说：你别想从我这儿拿到龙珠。\n",
	    }) );
	obj=new(DGNISLD"obj/dgnbal-7.c");
	obj->move(this_object());
	sword=new(DGNISLD"obj/dgnkiller.c");
	sword->move(this_object());
	wield_weapon(sword);
}
