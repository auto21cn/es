#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(11);
	set_name( "The left_temple enforcer", "左殿执事" );
	add( "id", ({ "enforcer" }) );
	set_short( "左殿执事" );
	set_long(
                "一位神殿左殿执事，他付责神殿中左殿的祭祀事情。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 500 );
	set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
        set_perm_stat( "pie", 25 );
        set_perm_stat( "int", 23 );
	set( "wealth/gold", 15 );
        set( "hit_points", 200);
        set( "max_hp", 200);
        set("natural_armor_class",35);
        set("natural_defense_bonus",15);
        set_natural_weapon(10,3,7);
        wield_weapon(OWEAPON"whip1");
        equip_armor(OARMOR"cloth3");
        set( "inquiry", ([
             "box" : "@@ask_box",
             "tree": "@@ask_tree",
             "fruit": "@@ask_tree",
             "chilin":"@@ask_chilin",
             ]) );
}

void ask_box(object who)
{
  tell_object(who,
     "\n执事说：我觉的黑龙宝盒的传说应该是真的，但要找到它是非常困难。\n"
       "我曾听长老说过，黑龙的宝盒有难以想像的强大力量，连巫师的神力也难\n"
       "以抗衡，听说只要黑龙拿到它的宝盒，它就能再恢复昔日强大的力量。\n\n"
     ); 
}

void ask_tree(object who)
{
  tell_object(who,
    "\n执事说：人□果入土即化，需要有块布摊开(spread)在下面接著。\n\n");
}

void ask_chilin(object who)
{
  tell_object(who,
    "\n执事说：相传火麒麟是火神的坐骑之一，全身冒著火□，口中也能吐出烈火。\n\n");
}
