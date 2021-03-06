#include "../legend.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "hostress", "女主人");
        set_short("女主人" );
	set_long(@C_LONG
女主人约莫四十多岁年纪，却有沈鱼落雁之貌，和男主人可说是天造地设的一双。
在二十多年前，女主人是位轰动武林惊动万教的人物，历经了几百场战役，却从未
被打败过，堂堂挤身为一流高手之列。女主人自从与男主人相遇，一时被惊为天人
，如今却心甘情愿跟著男主人双双过著隐居的生活，一度令人极为诧异，却因此佩
服她的勇气。
C_LONG
	);
	set( "gender", "female" );
	set( "race", "human" );
	set( "alignment",100 );
	set( "time_to_heal", 7 );
	set_natural_armor( 70 , 30 );
	set_natural_weapon( 24 , 8 , 6);
	set("max_hp",700);
	set("hit_points",700);
        set("max_fp",500);
	set("force_points",500);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",25 );
	set_skill( "parry",80 );
	set_skill( "longblade",70);
	set("spouse","host");
	set( "wealth/silver",200);
	set( "special_defense", ([ "all": 45,"none":30 ]) );
	set( "aim_difficulty",(["critical":70,"vascular":60,"weakest":50]) );
	set("couple",1);
        equip_armor(LARMOR"moon_ring");
        equip_armor(LARMOR"moon_amulet");
        wield_weapon(LWEAPON"red_sle");                                              
        set( "tactic_func", "my_attack" );
        set("inquiry", ([
                "third":"@@ask_third",
                         
        ]) );
        set("scholar_gonfu/couples_sword",30);
        set("scholar_gonfu/han",30);
} 
void ask_third(object asker)
{
write(@C_LONG
女主人道：我相公要你来问我喔？那好吧，我给你一项工作，妾身近来皮肤老化，
　　　　　苦无良方可以回复以往面貌，希望你为我想个办法。
C_LONG
      );
}
int accept_item(object me, object item)
{
   string pname,name;
   pname=me->query("name");
   name=item->query("name");
   if( name!="red fruit" ) {
      command("give "+name+" to "+pname);
      tell_object(me,"女主人道：咦，你给我这个东西是什麽啊？\n");
      return 1;
   }
   if( me->query_temp("third") ) {
      tell_object(me,@C_LONG
女主人说道：谢谢，我已经很年轻了。      
C_LONG
   );   
      command("give "+name+" to "+pname);
      return 1;
   }
   tell_object(me,@C_LONG
女主人吃下你带给她的朱果，瞬间年轻了好几十岁。哇！比「欧雷」还好用咩！

女主人感激地向你说谢谢 ^_^

C_LONG
    );     
    item->remove();
    me->set_temp("third",1);
    return 1;
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}

int my_attack()
{ 
   object *couples,victim;
   int i;

   if( !victim =query_attacker() ) return 0;
   
   if( query("force_points") < 50 ) set("force_points",500);
                        
   couples = filter_array( all_inventory(environment(this_object())),
           "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) {
      tell_room( environment(this_object()), sprintf(
          "%s怒道:我们岂是那麽好欺负的,给我下地狱去吧!!\n",couples[i]->query("c_name"))
          ,couples[i]);
      couples[i]->kill_ob(victim);
   }
   if ( !present("host",environment(this_object())) ) {
        set("attack_skill","scholar/han");                                    
        delete_temp("extra_db");
   }
   else set("attack_skill","scholar/couples_sword");
   return 0;
}
