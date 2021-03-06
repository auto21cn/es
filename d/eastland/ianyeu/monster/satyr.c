#include "../mad.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(8);
   set_name( "satyr", "色狼" );
   set_short( "色狼" );
	set_long(
          "你见到一个身材魁武, 一脸奸相的家伙, 他正对你邪恶地笑著。\n" );
   set_perm_stat( "str", 12 );
   set_perm_stat( "int", 10 );
   set_perm_stat( "dex", 15 );
   set_perm_stat( "kar", 15 );
   set( "max_hp", 350 );
   set( "hit_points", 350 );
   set_skill( "dodge", 80 );
	set( "killer", 1 );
   set( "race", "daemon" );
	set( "gender", "male" );
   set( "alignment", -500 );
	set( "natural_armor_class", 40 );
   set( "natural_defense_bonus", 20 );
   set( "natural_weapon_class1", 20 );
   set( "natural_min_damage1", 8 );
   set( "natural_max_damage1", 15 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
           "色狼说道: 嘿嘿嘿 .... 你既然见到了我，就别想活命！\n",
           "色狼脸上露出邪恶的笑容。\n",
	}) );
}

int my_tactic()
{
   object victim;

   if( random(20)>3 || !(victim=query_attacker()) ) return 0;
   if( victim->query("stop_attack") ) return 0;
   tell_object( victim,
          "色狼喃喃地念著诡异的咒文，你的身体竟然石化了!\n",
        );
   victim->block_attack(6+random(4));
   victim->set_temp("msg_stop_attack", 
        "( 你正努力於挣扎突破石化的身体, 无法攻击！ )\n" );
   return 1;
}

void die()
{
   object heart;
   heart = new( IANOBJ"heart" );

   heart->move(this_object());
   ::die(1);
}
