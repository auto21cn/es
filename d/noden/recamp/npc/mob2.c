#include <mudlib.h>
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "plesiosaurus statue", "蛇颈龙雕像" );
	add("id",({"statue"}));
	set_short( "蛇颈龙雕像" );
	set_long(
         "【蛇颈龙】相传是古代湖里的守护兽，这个雕像看起来很旧，却令人感觉
          栩栩如生。\n"
	);
	set( "alignment", 800 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 70 );
        set("unbleeding",1) ;
        set("weight",300);
        set("max_hp",300);
        set("hit_points",300) ;
        set("exp_reward",800) ;
	set( "tactic_func", "my_tactic" );
}

int my_tactic()
{
    object victim;

    if( random(20)<15 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,
          "\n雕像口中吐出一道强劲的水柱，如同飞剑般向你射来.\n"
          );
      tell_room(environment(this_object()),
        "\n雕像口中吐出一道强劲的水柱，如同飞剑般向"
        +victim->query("c_name")+"射去.\n",this_object()) ;
      victim->receive_special_damage("evil",5+random(2));
      "/d/magic/magic"->report(this_object(),victim);
      return 1;
}

int accept_item(object who,object item)
{
  int code ;

  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) code = 1 ; else 
  if ( !(who->query_temp("lulu_active")))  return 1 ;  

    command("give paper to "+who->query("name"));
    write("\n突然一阵耀眼的光芒照亮的让你几乎看不清楚眼前的东西......\n") ;
    write("咦？你不禁怀疑自己是不是眼花了...怎麽眼前多了个陌生的男子？\n") ;

    tell_room( environment(), 
       sprintf("陌生人向%s(%s)点头微笑，说道: 谢谢！\n",
       who->query("c_name"),who->query("name") ), who ) ;

    set("alt_corpse",CAMPMOB"mob2-1") ;
    if (code==1) return 1 ; 
    if ( !(who->query_temp("lulu_mob2")) ) { 
      who->set_temp("lulu_mob2",1) ;
    }
    if ( (who->query_temp("lulu_mob3")) && (who->query_temp("lulu_mob4")) )  
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
