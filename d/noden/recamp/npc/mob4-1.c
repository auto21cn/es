
#include <mudlib.h> 
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "lighting general", "迅雷将军" );
	add("id",({"lighting","general"}));
	set_short( "迅雷将军" );
	set_long(
         "【迅雷将军】留著最新潮的庞克头，听说他可以放出无数电波，因此他有
许多的女友。\n"
	);
	set( "alignment", 10 );
	set( "race","orc");
	set( "gender","male");
	set( "max_hp", 500 );
	set( "hit_points", 500 );
	set( "tactic_func", "my_tactic" );

        set_natural_armor(30,30);
        set_natural_weapon(30,10,30);
        set("aim_difficulty",
          (["critical":50,"vascular":50,"weakest":70,"ganglion":80])) ;
        set("wealth/silver",1000) ;
        set("weight",900) ;
        set_skill("dodge",80) ;
        set_skill("parry",80) ;

        wield_weapon(CAMPOBJ"labo4") ;
        equip_armor(CAMPOBJ"plate4") ;
}

int my_tactic()
{
  object victim;

    if( random(50)>10 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,
        "\n将军突然大喊：看我的「雷击秘计」，你看到数道电光向你迎面而来.\n");
      tell_room( environment(victim),
        "\n将军突然大喊：看我的「雷击秘计」，你看到数道电光向"
        +victim->query("c_name")+"射去.\n",victim);
      victim->receive_special_damage("fire",50+random(10));
      "/d/magic/magic"->report(this_object(),victim);
 
      tell_object(victim,"( 你发现被电的毫无力气! )\n" );
      tell_room(environment(victim),
          "( 你发现"+victim->query("c_name")+
          "被电的毫无力气! )\n", victim);
      victim->block_attack(5) ; 
      victim->set_temp("msg_stop_attacker","( 你发现被电的毫无力气! )\n") ; 
      return 1;
}

int accept_item(object who,object item)
{
  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) return 1 ;
  if (!(who->query_temp("lulu_active"))) return 1 ;  

  command("give paper to "+who->query("name"));
  if ( (who->query_temp("lulu_mob3")) && (who->query_temp("lulu_mob2")) )  
        tell_object( who,"说道: 谢谢！请把他交给露露吧!!\n");
  else  tell_object( who,"说道: 谢谢！请再寻找其他将军吧!!\n");

  return 1;
}
