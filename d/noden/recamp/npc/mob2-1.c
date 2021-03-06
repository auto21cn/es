#include <mudlib.h>
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "sea general", "海冥将军" );
	add("id",({"sea","general"}));
	set_short( "海冥将军" );
	set_long(
         "海冥将军有著一头绿色的头发，相传是海神的後裔，相当孔武有力。\n"
	);
	set( "alignment", 2000 );
	set_perm_stat( "dex", 10 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "str", 30 );
        set("race","orc") ;
        set("gender","male") ;
        set("max_hp",600) ;
        set("hit_points",600) ;
	set( "tactic_func", "my_tactic" );

        set_natural_armor(30,30);
        set_natural_weapon(30,10,30);
        set("aim_difficulty",
            (["critical":60,"vascular":50,"weakest":70,"ganglion":80])) ;
        set("wealth/silver",1000) ;
        set("weight",90) ;
        set_skill("dodge",80) ;
        set_skill("parry",80) ;

        wield_weapon(CAMPOBJ"3xgi2") ;
        equip_armor(CAMPOBJ"plate2") ;
}

int my_tactic()
{
    object victim;

    if( random(40)>10 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,
          "\n将军口中念动咒语，你看到一波海浪向你袭卷而来.\n"
          );
      tell_room(environment(victim),
          "\n将军口中念动咒语，你看到一波海浪向"
          +victim->query("c_name")+"袭卷而去.\n"
          ,victim);
      victim->receive_special_damage("evil",40+random(10));
      "/d/magic/magic"->report(this_object(),victim);
      return 1;
}

int accept_item(object who,object item)
{
  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) return 1 ;
  if (!(who->query_temp("lulu_active"))) return 1 ;  

  command("give paper to "+who->query("name"));
  if ( (who->query_temp("lulu_mob3")) && (who->query_temp("lulu_mob4")) )  
        tell_object( who,"说道: 谢谢！请把他交给露露吧!!\n");
  else  tell_object( who,"说道: 谢谢！请再寻找其他将军吧!!\n");

  return 1;
}
