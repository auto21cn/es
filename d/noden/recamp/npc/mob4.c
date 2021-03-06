
#include <mudlib.h> 
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "tyrannosaurus statue", "暴龙雕像" );
	add("id",({"statue"}));
	set_short( "暴龙雕像" );
	set_long(
          "你看到一个中型的暴龙雕像，也许长久暴露於户外的关系，已经\n"
          "斑痕点点了。\n"
	);
	set( "alignment", -800 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 70 );
        set("unbleeding",1) ;
        set("weight",350) ;
        set("exp_reward",800) ;
	set( "tactic_func", "my_tactic" );
        set( "max_hp", 300 );
        set("hit_points",300) ;
}

int my_tactic()
{
  object victim;

    if( random(20)<15 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,
        "雕像身形急转，你感到脸上热辣，脸上已经挂彩了！\n"
      );
      tell_room(environment(this_object()),
        "雕像身形急转向"+victim->query("c_name")+"脸上攻去去.\n"
          ,this_object() );
      victim->receive_special_damage("fire",10+random(5));
      "/d/magic/magic"->report(this_object(),victim);

      tell_object(victim,"( 你发现麻麻的毫无力气! )\n" );
      tell_room(environment(victim),
          "你发现"+victim->query("c_name")+
          "麻痹而毫无力气!\n", victim);
      victim->block_attack(2) ; 
      victim->set_temp("msg_stop_attacker","( 你发现麻痹而毫无力气! )\n") ; 
      return 1;
}

int accept_item(object who,object item)
{
  int code ;

  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) code = 1 ; else 
  if (!(who->query_temp("lulu_active"))) return 1 ;  

    command("give paper to "+who->query("name"));
    write("\n突然一阵耀眼的光芒照亮的让你几乎看不清楚眼前的东西......\n") ;
    write("咦？你不禁怀疑自己是不是眼花了...怎麽眼前多了个陌生的男子？\n") ;

    tell_room( environment(), 
       sprintf("陌生人向%s(%s)点头微笑，说道: 谢谢！\n",
       who->query("c_name"),who->query("name") ), who ) ;

    set("alt_corpse",CAMPMOB"mob4-1") ;
    if (code==1) return 1 ; 
    if (!(who->query_temp("lulu_mob4"))) { 
      who->set_temp("lulu_mob4",1) ;
    }
    if ( (who->query_temp("lulu_mob2")) && (who->query_temp("lulu_mob3")) ) 
          tell_object( who,"陌生人说道: 谢谢！请把他交给露露吧!!\n");
    else  tell_object( who,"陌生人说道: 谢谢！请再寻找其他将军吧!!\n");

    die() ;
    return 1;
}

void die()
{
   ::die(1) ;
   return;
}
