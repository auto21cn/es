#include "../oldcat.h"
#include "/include/move.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Leeng Ru Shuang", "极恶盗贼－冷如霜" );
	set_short( "极恶盗贼－冷如霜" );
        add ( "id", ({"shuang"}));
	set_long(@LONG
你见到一个美丽的女人，但她也是个嗜血的女人，凡是她看上的东西，无论用
任何手段，她都要弄到手。
LONG
	);
	set( "gender", "female" );
	set( "alignment", -2000 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "kar", 25 );
	set_skill( "dodge", 100 );
        set_skill( "parry", 100 );
	set_skill( "shortblade",90);
	
	set( "hit_points" , 600);
	set( "max_hp" , 600);
	set( "tactic_func", "my_tactic" );
	set_natural_armor(80,16);
	set( "special_defense",(["all":25,"none":30]) );
	set( "aim_difficulty", ([ "vascular":20,"weakest":20]) );
	set_natural_weapon(5,7,10);
        set( "killer" , 1 );
        set("chat_chance",5);
        set("att_chat_output", ({
          "\n冷如霜狂笑：哈哈，就凭你，也想来强夺宝盒，简直是在做梦。\n\n"
        }) );
        wield_weapon(OWEAPON"shortsword2");
        equip_armor(OARMOR"ring3");
        equip_armor(OARMOR"amulet2");
}

int my_tactic()
{
	object victim;
        object *all_vic;
	int i;
	
	if( random(20)>6 || !(victim= query_attacker()) )  return 0;
	if ( random(10)>5 ) {
	  if( victim->query("stop_attack") ) {
	     tell_object( victim, 
		 "\n冷如霜消失在你面前，你正不知她去何地方时，突然一个给你背刺。\n\n");
	     tell_room( environment(this_object()), 
		 "\n冷如霜消失在你面前，突然一个背刺攻击"+ victim->query("c_cap_name") +".\n\n"
		 ,({ victim, this_object() }) );
	     victim->receive_special_damage( "energy" , 35+random(15) );
	  }
	  else {  
	     tell_object( victim, 
		   "\n冷如霜施展嗫魄大法，你被她的魔力所迷惑住\n\n");
	     tell_room( environment(this_object()),
		   "\n冷如霜对"+ victim->query("c_cap_name") +"施展嗫魄大法，把"+ victim->query("c_cap_name") +"给迷惑住了.\n\n"
		   ,({ victim, this_object() }) );
	     victim->block_attack(6);
	     victim->set_temp("msg_stop_attack",
		 "( 你现在被迷惑著，无法攻击！ )\n" );
	  }
	  return 1;
      }
      else if ( random(10)< 6 ) {
        all_vic=query_attackers();
        all_vic->receive_special_damage("mental",50 );
        tell_room(environment(),
                "\n冷如霜施展吸魂大法，吸取你的生命。\n\n"
                ,this_object() );
        return 1; 
      }
      else 
        return 0;  
}

void die()
{
  object ob1,killer;
 
  ob1=new(OOBJ"dragon_box");
  killer=query("last_attacker");
  killer->set_temp("dragon_box",1);
  if (!killer) {
    ::die();
    return;
  }
  tell_object(killer,
     "\n冷如霜用剩下的最後一口气跟你说：我好不容易探得黑龙宝盒是落在井龙王\n"
       "的手里且使他建立了井龙宫王国，我冒著生命危险潜入龙宫宝库把宝盒偷出\n"
       "想来研究为什麽会有传说中强大的力量，想不到以我的聪明才智仍无法领悟\n"
       "出来，就遇到你，算我衰，我看你也是颓颓的，不可能找得到宝盒的秘密的\n"
       "，唉．．．．．．真是天妒英才，让我死在你手里，真是死不瞑目。\n\n"
       "只见她说完就睁著眼死了，你在她身上找到了黑龙宝盒。\n");
  ob1->set("killer",(string)killer->query("name"));
  if ( (int)(ob1->move(killer)) != MOVE_OK )
    ob1->move(environment(this_object()));
  ::die();
}
