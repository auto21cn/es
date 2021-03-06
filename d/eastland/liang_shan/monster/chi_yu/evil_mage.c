#include "../../takeda.h"
#include "/include/move.h"
#include <daemons.h>

#define C_NAME(x)     (string)x->query("c_name") 
#define NAME(x)       lower_case((string)x->query("name"))        

inherit "d/eastland/liang_shan/monster/chi_yu_group";

void create()
{
      ::create();
      set_level(18);
      set_name( "evil mage", "邪恶法师" );
      add ("id", ({ "mage" }) );
      set_short( "邪恶法师");
      set("unit","位");
      set("alignment",-1300);
      set("weight",400);
      set_long(query("c_name")+"带著一本魔法师们都有的魔法书□n");
      set( "alt_corpse", "NONE" );
      set( "moving", 1 );
      set( "speed", 40 );
      set_perm_stat( "dex", 20 );
      set_perm_stat( "str", 13 );
      set_perm_stat( "int", 30 );
      set_perm_stat( "kar", 20 );
      set_skill( "dodge", query_level()*3 );
      set_skill( "concentrate",query_level()*4 );
      set_skill( "target",query_level()*4 );
      set_skill( "black-magic", query_level()*4 );
      set("magic_delay",2);
      set("spells/lightning",3);
      set("chi_yu_group",1);                   
      set("max_hp",360);
      set("hit_points",360);
      set("natural_defense_bonus",20);
      set ("natural_weapon_class1", 10);
      set ("natural_armor_class", 40);
      set ("special_defense",(["fire":5,"cold":5,"evil":50]));
      set ("gender", "male");
      wield_weapon("/d/deathland/weapon/dagger04");
      equip_armor( "/d/deathland/armour/amulet01" );
      set("guild_levels/black-magic",40) ;
      set("guild_levels/guild",40);
      set_temp("be_joke",10);
      set("class","mage");
      set("max_sp",1000);
      set("spell_points",1000);
      set("couple",1);
      set("stun_difficulty",40);
      set( "alt_corpse", "NONE" );
      set( "tactic_func", "my_tactic" );
      command("party form");
}        

int can_help( object ob )
{
   if( ob->query_attacker() ) return 0;
   if( ob->query("couple")) return 1;
   return 0;
}
void make_angry(object obj,object victim)
{
   object ob1,ob2,ob3,*all,env;        
        
    if( query("have_party") ) return ;
    env=environment(obj);
    tell_room(env,C_NAME(obj)+
      "大喝:「注意，这里有敌人喔....」\n"
      "一大群蛇人不知从那儿跑了出来，把你团团围住... \n\n");
    set("have_party",1);
    set("party_num",4);
    set_temp("embattle_busy",0);
    ob1=new(TMONSTER"chi_yu/healer");
    ob1->move(env);
    ob2=new(TMONSTER"chi_yu/knight");
    ob2->move(env);
    ob3=new(TMONSTER"chi_yu/mage");
    ob3->move(env);
    ob1->set("master",obj);
    ob2->set("master",obj);
    ob3->set("master",obj);
    ob1->set_temp("leader",obj);
    ob2->set_temp("leader",obj);
    ob3->set_temp("leader",obj);
    ob1->add_temp( "protectees", ({ obj }) );
    ob2->add_temp( "protectees", ({ obj }) );
    ob3->add_temp( "protectees", ({ obj }) );
    ob1->kill_ob(victim);
    ob2->kill_ob(victim);
    ob3->kill_ob(victim);
    all=obj->query_temp("party_members");
    all=all+({ob1,ob2,ob3});
    obj->set_temp("party_members",all);
    obj->add_temp( "protectors",({ob1,ob2,ob3}));
}

int my_tactic()
{
     object *all,*couples,victim;
     int i,members;     
     string name;
     
     if (!(victim= query_attacker())) return 0;
     name=lower_case(NAME(victim));
     make_angry(this_object(),victim);

//     couples = filter_array( all_inventory(environment(this_object())),
//        "can_help", this_object() );
//     for( i=0; i<sizeof(couples); i++ ) 
//            couples[i]->kill_ob(victim);

     if ( this_object()->query("spell_points")<200 ) 
          this_object()->set("spell_points",1000);
     
     if( random(24)<4 ) {
            command("cast lightning on "+name);
            
            } else 
    return 1;
}

void die()
{
  object killer;
  if ( !killer = query("last_attacker") ) {
  ::die(1);
  }
  else
  write(query("c_name")+"化为一道青烟，消失在空气中...\n");
  ::die(1);
}
