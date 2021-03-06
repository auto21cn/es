#include <mudlib.h>

inherit TEACHER;
inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "Dalifore", "戴利佛" );
	add ("id", ({ "captain", "knight", "dalifore" }) );
	set_short( "精锐骑士长 戴利佛 伯爵");
	set_long(@CLONG
戴利佛是诺顿骑士团中仅次於雷思团长的第二号人物，他擅长的武器非常
多，因此国王派他负责训练皇家骑士们的武器技巧。
CLONG
	);
	set_perm_stat("str", 30 );
	set_perm_stat("con", 25 );
   set_skill( "tactic", 100 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "block", 100 );
	set( "alignment", 1500 );

	set( "race", "human" );
	set( "gender", "male" );

	set( "hit_points", 800 );
	set( "max_hp", 800 );

	set_natural_weapon( 15, 5, 20 );
	set_natural_armor( 70, 30 );
	
   set( "tactic", "flank" );
   set("special_defense",(["all":30]));
    set("aim_difficulty",([ 
    	"critical":80,"vascular":50,"weakest":50,"ganglion":50 ]) );
	
	wield_weapon( "/d/noden/nodania/obj/markara" );
	equip_armor( "/d/noden/nodania/obj/steel_plate" );
	equip_armor( "/d/noden/nodania/obj/steel_leggings" );
	equip_armor( "/d/noden/nodania/obj/steel_gauntlets" );
	equip_armor( "/d/noden/nodania/obj/shield" );
	equip_armor( "/d/noden/nodania/obj/steel_boots" );
	equip_armor( "/d/noden/nodania/obj/steel_helmet" );
	set( "inquiry", ([
		"lucksis" : "@@ask_lucksis",
		"yamor" : ({
			"亚默？.... 没错，我是答应过要训练(train)他的公会成员 ....。\n" }),
		"train" : ({
"我可以教你长刃型武器(longblade)及战术运用(tactic)的技巧。\n" }),
	        "tactic" : ({
			"还问!?再罗唆我就不教了!\n" }),
		"longblade" : ({
			"没—错！你再罗唆我就不教了！\n" })
	]) );
	set_lessons( ([
	   "tactic" : ({ 200, 45 }),
           "longblade" : ({ 150, 55 })
	]) );
}

void ask_lucksis(object who)
{
     if ( !(who->query_temp("lucksis_quest")) || 
     	  !(who->query_temp("lucksis_quest/ask")) ) 
       tell_object(who,"戴利佛说道: 对不起,我正在训练士兵.\n");
     else {
         tell_object(who,
         	"戴利佛说道: 你是拉克希丝派来的?\n"
            "那是一段往事了, 当时她正被怪物攻击, 而我救了她。\n"
            "正如我往常的工作, 只不过她与其他人不同的是..\n"
            "她对我纠缠不已, 原谅我这麽说, 但是实在是如此,\n"
            "为此我还特别向国王请求, 派我前往遥远的死亡大地。\n"
            "与矮人王莫拉德会面做双边的外交。这样我才逃过她\n"
            "的纠缠。\n戴利佛说完後,继续训练士兵。\n\n\n"
            "你觉得戴利佛与拉克希丝的关系似乎是落花有意, 而流水无情。\n"
         );
         who->set_temp("lucksis_quest/dalifore",1);             
     }
}

void init()
{
   teacher::init();
   npc::init();
}

int check_trainee(object trainee)
{
	if( (string)trainee->query("class")!="adventurer"
	|| (int)trainee->query_level()<5 ) {
		return notify_fail(
		"戴利佛摇摇头，说道: 根据当初和亚默的约定，我只教 5 级以上的冒险者。\n"
	); 
      }
	return 1;
}
