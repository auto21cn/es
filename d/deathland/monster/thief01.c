#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	object ob;
	::create();
    set_level(3);
    set_name("lost thief","迷路的小贼");
    add ("id", ({ "thief"}) );
    set_short("迷路的小贼");
	set_long(@LONG
一个迷路的小贼,他并不能发现出路而迷失在这里
LONG
	);
    set("alignment",-300);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",  6);
	set_skill("dagger",30);
    set ("max_hp",75);
    set ("max_sp",0);
    set ("hit_points",75);
    set ("spell_points",0);
    set ("wealth", ([ "gold":8]) );
    set_natural_weapon(12,4,9);
	set_natural_armor(35,0);
    set ("weight", 350);
    set("chat_chance",15);
    set("chat_output",({
        "小贼说:谁能告诉我如何离开这里呢 ?\n"
       }) );
    wield_weapon(Weapon"/dagger06");
    ob = new(Object"/opiate");
    ob->move(this_object());
}


