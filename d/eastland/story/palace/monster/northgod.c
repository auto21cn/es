#include "/d/eastland/story/story.h"
#include <conditions.h>
inherit MONSTER ;
int cast=0;
int times=0;
int receive_damage(int damage);
void create ()
{
	::create();
	set_level(19);
	set_name( "King of the north Ra-Shan","颛顼");
	add ("id", ({"king","ra-shan","Ra-Shan"}) );
	set_short( "北方天帝 颛顼 [骑在一只[0;31m□[1;31m□[0;37m[0;31m□[1;31m□[0;37m[0;31m□[1;31m□[m上]");
	set_long(@CLONG
颛顼乃是黄帝的曾孙，管理北方积雪寒冰的荒野，一共一万二千里的地方。颛顼生
得细眉凤目，内堂神仪，丰神俊朗，一身白也似的雪肤，脸上并无任何表情。身为
上帝的颛顼对於下方人民的痛苦似乎不怎麽顾念，但他却讲究「礼法」的。
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 24 );
        set_perm_stat("dex", 23 );
        set_perm_stat("kar", 28 );
        set_perm_stat("int", 28 );
	set( "alignment", 2000 );
	set( "hit_points", 1800 );
	set( "max_hp", 1800 );
        set( "max_fp",200);
	set_natural_weapon( 45, 8, 8 );
	set_natural_armor( 3, 26 );
        set_temp("detect_hide",1);
        set("aim_difficulty",([ 
    	  "critical":70,"vascular":40,"weakest":40 ]) );
        set("wealth/gold",300);
        set("stun_difficulty",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("dagger",100);
        set("tactic_func","my_tactic");
        wield_weapon(SPWEA"northgod_dagger");
        equip_armor(SPARM"northgod_cape");
        equip_armor(SPARM"northgod_cloth");
        equip_armor(SPARM"northgod_ring");
        equip_armor(SPARM"northgod_shield");
        set("special_defense",(["all":100,"none":45,"electric":10]));
}
int receive_damage(int damage)
{
  if ( damage>25 ) damage=25;
  ::receive_damage(damage);
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( cast ) {
      if ( times++ > 10 ) {
         tell_room(environment(),"渐渐地，漫天的冰雪溶化於地上凝结成水滴！\n\n");      
         environment()->set("cast",0);
         cast=0;
         return 0;
      }
      return 0;
    }
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),"\n颛项双手往前摊开，空气中满是漫天冰雪！！\n\n");
    cast=1;
    times=0;
    environment()->set("cast",1);
    return 0;
}
void die()
{
   object phoenix;
   phoenix=new(SPMOB"phoenix");
   phoenix->move(environment());
   environment()->set("cast",0);
   set_short("北方天帝 颛顼");
   ::die();
}
