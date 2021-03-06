#include "mobs.h"
#include <races.h>

inherit RACE_HUMAN;

void create()
{
	::create();
	seteuid( getuid() );
	set_level(13);
	set_name( "Cid Previa", "施得 潘维尔" );
	add( "id", ({ "cid", "Cid", "engineer", }) );
	set_short( "a engineer Cid Previa", "技师 施得 潘维尔" );
	set_long( @LONG
NEED WORK HERE!
LONG
             , @C_LONG
    擅长发明和发现各种东西，为世界带来繁荣的技师。最近醉心於魔法
能源的研究，目前率领了许多学者，努力研究并开发新的魔法能源。你可
以问他有关 recharge 的问题。
C_LONG
	);
	set( "alignment", 2000 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "位" );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 24 );
	set_perm_stat( "con", 19 );
	set_perm_stat( "piety", 20 );
	set_perm_stat( "karma", 25 );
	set ("max_hp", 400);
	set ("hit_points", 400);
	set ("wealth/silver",100 );
	set_natural_weapon( 50, 15, 30 );
	set_natural_armor( 80, 30 );
    set ("weight", 800);
    set ("exp_reward",4000 );
    set_experience(50000);
    set_skill("dodge",80);
    set( "inquiry", ([
      "recharge" : "@@ask_recharge",
    ]) );
}

void init()
{
    ::init();
    add_action("to_value", "value");
}

void ask_recharge( object who )
{
    tell_object( who,
      "施得说: 你可以用 recharge item 来补充魔法物品的能源或\n"+
      "        value item 来看看补充它需要多少钱及经验值。\n" 
    );
}

int to_value( string str )
{
    object item, who;
    int wc, damage, times, cost_money, cost_exp, skill, money, exp;
    who = this_player();
    if( !str )
      return notify_fail("Value what ?\n");
    if( !(item=present( str, who )) )
      return notify_fail( can_read_chinese() ?
        "施得说: 你身上没这个东西。\n" : "Cid says: You have no this item.\n"
      );
    if( !item->query("max_charge") )
      return notify_fail(
        "施得说: 这不是魔法物品，无法补充魔法能源!\n" 
      );
    wc = (int)item->query("weapon_class");
    damage = (int)item->query("special_damage");
    times = (int)(item->query("max_charge"))-(int)(item->query("charge_left"));
    skill = (int)who->query_skill("recharge");
    money = 200;
    exp = 500;
    cost_money = wc*damage*times*(150-skill)/money;
    cost_exp = wc*damage*damage*(150-skill)/exp;
    if( !cost_money )
      tell_object( who,
        "施得说: 这物品不须要补充能源。\n"
      );
    else
      tell_object( who,
        "施得说: 补充这物品的能源需 "+cost_money+" 银币及 "+cost_exp+
        " 点经验值。\n"
      );
    return 1;
}
