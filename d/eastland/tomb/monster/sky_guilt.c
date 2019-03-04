#include "../almuhara.h"
 
inherit MONSTER;
 
void create ()
{
	::create();
	seteuid( getuid() );
        set_level(18);
	set_name( "Sky Guilt", "『 天罪 』" );
	add ("id", ({ "sword","sky guilt","sky","guilt" }) );
	set_short( "『 天罪 』" );
	set_long( 
@C_LONG
这是『 天罪 』。一只由上古神兵在吸取了这儿天地之灵气所幻化成的奇兽。从它
身上散发出的邪气，令你不寒而栗。
C_LONG
	);
	set( "alignment", -5000 );
        set( "unit", "把" );
        set_perm_stat( "dex", 23 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "int", 26 );
        set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 10 );
        set_perm_stat( "karma", 20 );
	set ("chat_chance", 5);
        set ("max_hp", 1200);
        set ("hit_points", 1200);
	set ("killer", 1);
	set("stun_difficulty/ma",40) ;
        set("aim_difficulty",(["critical":80,"weakest":60,
                               "vascular":40,"ganglion":60 ])) ;
        set_natural_weapon( 70, 40, 70 );
        set_natural_armor( 100, 30 );
    set ("weight", 150);
    set ("exp_reward", 27767 );
    set ("special_defense", 
         ([ "all":50, "none":40, "fire":20, "cold":30 ]) );
    set_skill("tactic",90);
    set_skill("dodge",90);
    set_skill("parry",90);
    set("tactic","assault");
    set_c_verbs( ({ "%s直刺%s", "%s横斩%s","%s斜挑%s"}) );
    set_c_limbs( ({ "剑刃", "剑锋","剑柄" }) );
    set( "alt_corpse", WEAPONS"/d_sky_guilt" );
    set( "c_death_msg", "%s发出一声凄厉的悲嚎，化回原形。\n");
    set( "att_chat_output", ({
		"『天罪』狂笑说道: 放我出来就是你的死期到了!!\n",
	        "天罪冷冷地看著你。\n", }) );
}
 
void die()
{
	object ob;
	
	ob = query("last_attacker");
	ob->set_temp("GUILT",1);
        if ((string)ob->query("class")=="scholar") {
          tell_object(ob,set_color(
 "突然这个房间的剑气凝成一人形：谢谢你把这邪恶的天罪给除去，我是在这里修炼\n的剑魂，由於天罪的关系，我都不能好好的在这里修炼，总而言之，假如须要我的帮忙，\n请不要客气。\n"
          ,"HIW"));
          ob->set("demand/sword",2);
        }
	::die();
}
