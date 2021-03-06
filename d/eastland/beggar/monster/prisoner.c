#include "../dony.h"

inherit MONSTER;
int times;

void create()
{
	::create();
	set_level(19);
	set_name( "unknow prisoner","不知名" );
	add ("id", ({"prisoner"}) );
	set_short( "囚犯 不知名" );
	set_long(@C_LONG
你眼前所见是一个年约八、九十岁的老人;他长发披肩全身上下污秽不堪,他的衣服
处处散发著一股令人掩鼻的气息; 让你惊呀的是有两条粗粗的精铁铸锁□从他的琵
琶骨穿了过去,两端各连在墙壁上;除此之外,全身上下不下千百个疤痕,与其说是刀
伤不如说是受到极悲惨的酷刑。据说,他曾是轰动一时的大魔头,但受到八大门派的
围□并且制服了他才不致於为害武林。
C_LONG
	);
	set( "unit", "名" );
	set_perm_stat( "str", 28 );
	set_perm_stat( "dex", 26 );
	set_perm_stat( "int", 24 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 22 );
        set("weight",900);
	set_skill( "dodge", 90 );
	set_skill( "unarmed", 90 );
        set_skill( "unarmed-parry",100);    
	set( "special_defense", ([ "all": 60,"none":60]) );
	set("aim_difficulty", 
	   ([ "critical":80, "vascular":60, "ganglion":70, "weakest":70 ]) );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -4000 );
	set("max_hp", 650);
	set("hit_points",650);
	set("force_points",350);
	set_natural_armor( 55,50 );
	set_natural_weapon( 90,30,55);
	set( "wealth/gold", 400 );
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        equip_armor(DARMOR"fighter_ring.c");
	set( "tactic_func", "my_tactic" );
        set_c_verbs( ({ "%s腾空跃起当头一记劈空掌对著%s劈下",
                        "%s脚往前踏一步十指成爪往%s一抓,凌厉已极",
                        "%s使出六、六三十六式旋风腿往%s狠狠一扫"
                    }) );
}

int my_tactic()
{
     int i,ran;
     object *env,victim;
     string vic_name;
     
     if (!victim= query_attacker()) 
        return 0;
     vic_name=victim->query("c_name");
     if( times ) {
        if (times==6)
           tell_room(environment(this_object()),
             "\n不知名开始施展吸星大法......\n\n");
        if( --times ) {
           tell_object( victim,"你正被吸取精力！！\n");
           tell_room(environment(this_object()),
               vic_name+"被吸取全身的精力！\n",victim);
           victim->receive_damage(10);
           victim->block_attack(2);
           victim->set_temp("msg_stop_attack","(  你正被吸取精力而动弹不得!!  )\n");
           if ( ( victim->query("class") )=="monk" )
               victim->add( "force_points", -10 );
           report(this_object(),victim);
           return 1;
        } else {
           this_object()->set_natural_armor( 55,50 );
           tell_room(environment(this_object()),"\n不知名脸上露出满意的表情:好饱好饱,哈哈哈哈哈！！\n");
           return 1;
        }
     }       
     ran=random(40);
     if ( ran>34 ) {
         times = 6;
         this_object()->set_natural_armor( 40,40 );
         return 0;
     } 
     else if ( ran>30 ) {
        tell_object(victim,
           "\n不知名盘旋而起使出了「天水之舞」,令你头昏眼花！！\n\n");
        tell_room(environment(this_object()),
           "不知名盘旋而起使出了「天水之舞」令"+vic_name+"不由自主地跟著起舞！！\n",victim);
        (CONDITION_PREFIX + "confused")->apply_effect( victim, 10, 8 );         
        return 0;
     } 
}

void die()
{
   object eq;
   tell_room(environment(this_object()),
      "\n\n忽然,不知名的□体有了变动.....不明名竟然爬了起来没死!!\n\n\n");
   eq=present("ring",this_object());
   eq->unequip(1);
   eq->move(environment(this_object()));
   set( "alt_corpse", DMONSTER"ch_prisoner.c" );
   ::die(1);
}        