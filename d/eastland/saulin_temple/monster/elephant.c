#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "A huge elephant", "大白象" );
	add( "id", ({ "elephant"}) );
	set_short( "大白象" );
	set_long(@ELEPHANT
你看到一头超级大白象，头上戴著黄金的垂饰，背上安著一张青玉座椅，它应该是
某位神的座骑。这只大象看起来很安详，正轻摆著两只大耳朵用长长的大鼻子拔著
树叶吃，不过它的吃相实在有够难看，东拉西扯的把美好的树林破坏的一榻糊涂，
你最好赶快把这只贪吃家伙赶回它主人(master)身边。  
ELEPHANT
	);
     set_perm_stat("dex", 5);
     set_perm_stat("str",10);
     set_perm_stat("kar",10);
     set_perm_stat("int", 5);
     set_perm_stat("pie",10);
     set_skill("dodge", 30);
     set("alignment",2000);
     set("max_hp",300);
     set("hit_points",300);
     set_natural_weapon(9, 4, 8);
     set_natural_armor(20, 18);
     set("special_defense", ([ "all" : 10, ]) );
     set("aim_difficulty", ([ "critical" : 10, ]) );
     set("exp_reward", 250);
     set("alt_corpse", SAULIN_MONSTER"fire_elephant");
     set_c_verbs(({ "%s用腿踩%s", "%s用头撞%s", "%s用身体压%s" }));
     set_c_limbs(({ "身体", "头部", "脚部", "手臂" }));
     set ("c_death_msg",
  "%s大叫说: 可恶，竟敢欺负我？你不要命了! 让我送你下地狱吧! 有种的不要走!\n"
     );
	 set( "inquiry", ([
		  "master" : 
	      "我的主人就是大名鼎鼎的西天如来佛 .......\n" 
	      "            座下的普贤菩萨，所以你可千万不要欺负我喔!!\n"   ]) );
      set("tactic_func","crying");
}

int crying()
{
    if( random(20)<12 ) return 0;
    tell_room( environment(),
      "\n大白象叫道: 你做什麽？快停手! 否则我要生气喽!!\n" ,
      this_object()
    );
	return 1;
}

void die()
{
    tell_room( environment(this_object()),@C_DIE_MESSAGE
      
  大象惨叫一声，摇身一变，化身成为一只银色巨象，它精光四射的眸子瞪著你
    ，红红的两道烈焰随著愤怒的呼吸飞扬在空中。
  它大叫道：可恶的白痴 !! 纳命来 !! 
  
C_DIE_MESSAGE
      ,this_object()
    );
    ::die(1);
}
