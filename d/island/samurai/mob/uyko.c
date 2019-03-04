#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "uyko", "橘右京" );
//	add( "id", ({ "uyko" }) );
	set_short( "uyko", "橘右京" );
	set_long(@AAA
你眼前是一位年轻的剑客，有著一张十分貌美清秀的脸孔，但是明显的他气色
并不好，一直咳嗽著，有时还会咳出鲜血，让你怀疑他还能和人战斗吗？
AAA
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 27 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "kar", 20 );
        set_perm_stat( "pie", 30 );    
        set( "max_hp",650 );
        set( "hit_points",650 );
 	set_natural_armor( 70,25 );
	set( "natural_weapon_class1", 15 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 45 ); 
        set( "time_to_heal",25);
        set( "special_defense",([ "all":25,"none":25 ])); 
        set( "aim_difficulty",([ "critical":80,"weakest":20,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty/ma",15);  
	set( "alignment", 1000 );
	set_c_limbs( ({ "头部", "身体", "手腕", "咽喉" }) );
        set_skill( "parry",100 );
        set_skill( "longblade",100 );
        set_skill( "dodge",80);
        set( "wealth" , ([ "gold": 100 ]) );
        set( "tactic_func", "att_gonfus");
        set( "weight", 400 );
        wield_weapon(MOBJ"swallow_sword");    
        equip_armor(MOBJ"sakura"); 
        set("inquiry",([
            "o_i_la_shi":"@@give_ob"
            ]));
}

int att_gonfus()
{
     object victim;
     int dam;
     
     if( !(victim = query_attacker()) || (random(20)>2) ) return 0;
     tell_room(environment(this_object()), 
     "\n\n右京突然跃向空中，快剑一挥，从剑身上居然飞出一只火鸟\n"+
     "\n那只火鸟休一声飞向"+victim->query("c_name")+"\n\n"
      );
      dam = 20 + random(25);
      victim->receive_special_damage("fire", dam );
      report(this_object(),victim);
      return 1;
}
int give_ob(object ob)
{  
   if( this_player()->query_temp("have_get_statue") )
   {
       write(@CCC
橘右京说道：你这个贪心的家伙，去死吧 !!! 
说著快剑一挥，对你造成了难以想像的伤害。
CCC);
     this_player()->set("hit_points",0);
     return 1;
   }    
   if( !this_player()->query_temp("calford") )
      return notify_fail("橘右京瞪著你说:小子，有何指教？想和我挑吗？\n");
   ob=new(MIT"statue");
   this_player()->set_temp("have_get_statue",1);
   write(@AAA
橘右京说道：你是加尔福特叫来拿礼物的吧，这个雕像我刻好已经很久了，就
　　　　　　是等你来拿而已，算算娜考璐璐的生日也快到了，你就赶快拿去
　　　　　　给她让她高兴一下吧！


橘右京说完从身後的大树下拿出一个雕像，放在你脚边．．


AAA
);
   ob->set("statue_getter",(string)this_player()->query("name") );
   ob->move(environment(this_player()));
   return 1;
 }

