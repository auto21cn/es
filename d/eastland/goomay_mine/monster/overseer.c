#include "../zeus.h"
inherit MONSTER;

void create()
{       int i;
        ::create();
        set_level(19);
        set_name( "overseer", "萧别离" );
        add ("id", ({ "overseer" }) );
        set_short( "矿工工头 萧别离");
        set("unit","位");
        set_long(@C_LONG
他是一位凶悍的而且强壮的工头，所有的矿工在他的严苛管理下，没有
人敢打混摸鱼，听说过去是专门做跑单帮生意的，在一次因缘际会中被
段老大所救，被段老大邀请回来帮忙，代替上次爆炸中受伤的工头
C_LONG
        );
        
        set("alignment",100);
        set("wealth/gold",50);
        set("gender", "male");
        set("race", "dwarf");
        set("max_hp", 800);
        set("max_fp", 600);
        set("hit_points", 800);
        set("force_points", 600);
        set_perm_stat("str", 27);
        set_perm_stat("dex", 26);
        set_natural_weapon( 30,20, 40 );
	set_natural_armor( 80, 30 );
        set("special_defense", ([ "all":40, "none":30 ]) );
        set("aim_difficulty", ([ "critical":40, "vascular":50, ]) );
        set_skill("longblade",90);
        set_skill("parry", 90);
	set("tactic_func","my_tactic");
	set("inquiry",([
	"key":
"我不清楚，不过以前的工头曾告诉我他在那次爆炸中遗失了\n"
"一个像钢片的东西，希望我如果有发现类似的东西能还给他．\n"
])); 
	 wield_weapon(ZOBJ"/dragon_sword");
	 equip_armor(ZOBJ"/dragon_gloves");
	 equip_armor(ZOBJ"/love_ring.c");
	 equip_armor(ZOBJ"/six_shoe.c");
}
int my_tactic()
{       object *victim;
        int dam,bonus; 
        string *attack_msg=({
"\n萧别离举剑在头上划个圆後使出＜银龙抬头＞攻向你的头部！．．．．．．．\n\n",
	              
"\n萧别离将剑挽花，向後甩刺再向前上方推出使出＜仙人指路＞攻向你的弱点！．\n\n",
	              
"\n萧别离右腿向後提膝，双手推剑向前猛刺使出＜青龙过海＞攻向你的心脏！．．\n\n",
	              
"\n萧别离左脚踏实，右手持剑挽逆花使出＜卧龙吐舌＞攻向你手臂！．．．．\n\n",
	              
"\n萧别离右手持剑由上下撩，在挽花使出＜龙展风眉＞攻向你身体的弱点！．．．\n\n",
	              
"\n萧别离右手持剑，向胸前下方横劈使出＜矫龙吞妖＞攻向你的致命弱点！．．．\n\n"
	              });
	bonus=(int)this_player()->query_perm_stat("dex");
	if(!(victim=query_attackers())|| ( random(20)>5 ) ) return 0;
	tell_object(victim,attack_msg[random(6)]);
	dam = 60+random(30)-bonus*2;
	victim->receive_special_damage("divine",dam);
	return 1;
	}