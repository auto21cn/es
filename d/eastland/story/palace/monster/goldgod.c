#include "../../story.h"
#include "../../magic.c"
#include <ansi.h>
inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "The Gold-God Ru", "蓐收" );
	add ("id", ({"the god-god ru","ru","Ru"}) );
	set_short( "金神蓐收");
	set_long(@CLONG
蓐收全身长得漆金也似的，一对眼睛大如铜铃，相貌极有威仪。蓐收原是辅佐西天
帝少昊的，掌管著四季中的秋天。由於蓐收是属於五行中的西金，不免有些穿凿附
会之说，一但遇见他，总会财富滚滚。	
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 28 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 20 );
        set_perm_stat("int", 27 );
	set( "alignment", 500 );
	set( "hit_points", 1500 );
	set( "max_hp", 1500 );
        set( "spell_points",100);
        set( "max_fp",500);
	set_natural_weapon( 18, 14, 21 );
        set_natural_weapon2( 38, 23, 35 );
	set_natural_armor( 70, 52 );
        set("aim_difficulty",([ 
    	  "critical":50,"vascular":50,"weakest":50 ]) );
        set("wealth/gold",400);
        set("stun_difficulty",100);
        set_skill("block",100);
        set_skill("two-weapon",100);
        set_temp("detect_invi",1);
        set_skill("parry",100);
        set_skill("thrusting",100);
        set_skill("chain",100);
        set("tactic_func","my_tactic");
        wield_weapon(SPWEA"ruler");
        equip_armor(SPARM"goldgod_shield");
        wield_weapon2(SPWEA"chain");
        set("special_defense",(["all":50,"none":30]));
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(18) > 1 ) return 0;
    tell_room(environment(),
      "蓐收手中的璇天尺不停地旋转，变成一团栲栳大的光圈激射而出！\n",victim);
    tell_object(victim,
      "\n蓐收手中的璇天尺不停地旋转，变成一团栲栳大的光圈 ...\n\n那团光圈忽然激射出万丈豪光射向你的全身!！\n\n\n");
    tell_object(this_object(),sprintf(
      "\n你手中的璇天尺不停地旋转，变成一团栲栳大的光圈 ...\n那团光圈对著%s激射出万丈豪光!！\n\n\n"
      ,victim->query("c_name")));
    victim->receive_special_damage("energy",40+random(10));
    report( this_object(), victim );
    return 1;
}
void die()
{
   int i,max;
   object env, *atk;
   env=environment();
   atk=all_inventory(env);
   max=sizeof(atk);
   tell_room(environment(),"蓐收临死前怀著深沈的恶意道：你们这些人会受到诅咒的！\n");
   for ( i=0;i<max;i++ ) 
      if ( userp(atk[i]) ) 
         damn_player(atk[i]);
   ::die();
}
