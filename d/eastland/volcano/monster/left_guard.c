#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(17);
	set_name( "Left Guard", "左护卫" );
	add ("id", ({ "guard" }) );
	set_short( "左护卫－左青城" );
	set_long(
             @LONG
左护卫－左青城、是当年曾力战两湖水怪的英雄，在一次除妖的时後，身受重伤，恰
好被龙王遇到，因而获救，从此就跟著龙王一起修炼，并且担任龙王的护卫。
LONG
	);
    set( "alignment", 1000 );
    set( "gender", "male" );
    set( "race", "human" );
//    set( "pursuing" ,1);
    set( "unit", "个" );
    set( "likefish",1);
    set_perm_stat( "dex", 23 );
    set_perm_stat( "str", 25 );
    set_perm_stat( "int", 20 );
    set_perm_stat( "con", 27 );
    set_perm_stat( "piety", 10 );
    set_perm_stat( "karma", 21 );
    set("max_hp", 800);
    set("hit_points", 800);
    set("wealth", ([ "gold": 50 ]) );
    set_natural_weapon( 10, 10, 15 );
    set_natural_armor( 35, 20 );
    set("weight", 800);
    set("exp_reward",32590 );
    set_experience(950000);
    set_skill("parry",80);
    set_skill("block",80);
    set_skill("dodge",85);
    set("unbleeding", 1);
    set("special_defense", ([ "all" : 50, "none" : 40 ]) );
    set("aim_difficulty", ([ "critical" : 50 ]) );
    set("chat_chance",5);
    set("att_chat_output", ({
      "\n左青城说：你们比那些烂妖怪还差，再去修炼个五百年再来吧。\n\n"
    }) );
    wield_weapon( OWEAPON"axe1" );
    equip_armor( OARMOR"mail7" );
    equip_armor( OARMOR"shield2" );
    set("tactic_func", "special_attack"); 
}

int special_attack()
{
    object *victim;
    int i;
    
    if( !(victim = query_attackers()) || (random(10)<5) ) return 0;
    tell_room( environment( this_object() ),
      "\n左青城大喊: 看我的绝招 天雷破! \n"+
      "只见左青城举起斧一劈，只听得一阵雷声，一道闪电直击向所有的敌人。\n\n",
      this_object()
    );
    i = sizeof(victim);
    while(i--) {
      victim[i]->receive_damage(random(10)+25);
    }
    return 1;
}
