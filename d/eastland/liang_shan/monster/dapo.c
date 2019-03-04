#include "mudlib.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(15);
	set_name("Grandmother Da", "达婆婆");
	add ("id", ({ "da", "grandmother" }) );
	set_short("达婆婆");
	set_long(
		"你看到一个年老的老婆婆，躺在床上呻吟，乍看之下好像是\n"
		"病的奄奄一息的样子，但仔细看看，却好像没有病的很重。\n");
	set_perm_stat("dex", 10);
	set_perm_stat("kar", 17);
	set_perm_stat("str", 13);
        set( "chat_chance",20);  
        set("chat_output",({"老婆婆不停的发出呻吟.......嗯.....唔.....\n"}));
	set_skill( "dodge", 30 );
	set( "max_hp", 380 );
	set( "hit_points", 380 );
	set( "gender", "female" );
	set( "race", "beholder" );
	set( "alignment", 100 );
	set( "tactic_func", "become_weak" );
	set_natural_armor( 35, 20 );
	set_natural_weapon( 34, 15, 20 );
	set( "forgetful", 1 );
	set( "time_to_heal", 5 );
        set( "inquiry", ([
              "sick" : "@@ask_sick",
              "food" : "@@ask_food"
              ]));
}
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "妹妹" : "太太" ;
	else
	return (!who->query("spouse")) ? "弟弟" : "先生" ;
}
void ask_sick()
{
write (
"达婆婆叹了一口气，说道: 我是生病了...\n");
return ;
}

void ask_food()
{
write (
"达婆婆说道: 喔，这位" + c_call(this_player()) +"，你问我喜欢吃什麽吗??\n"
"住在鱼村当然喜欢吃鱼啦，只是我病的快葛屁了，那有心情吃呢??\n");
return ;
}

int become_weak()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    tell_room( environment(this_object()),
            "\n达婆婆叫道: 连生病的人都要欺负....你不怕被传染吗??\n"
            "你听完达婆婆的话，觉得身体有些不对劲.......\n\n",
		this_object() );
	(CONDITION_PREFIX + "weak")->apply_effect( victim, 2, 12 );
	return 1;
}

int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name!="fish meat") ) return 1;
{
     tell_object(me,
@MEAT
达婆婆接过黄金梦幻鲤鱼的肉，不禁泪流满面....

没想到湖里还有黄金梦幻鲤鱼，几十年没有尝过它鲜美的滋味了...

MEAT
	);
//      command("eat meat");
        item->remove();
     tell_object(me,
@HAHA
达婆婆抬头看著你，说道: 为了再吃到黄金梦幻鲤鱼，我怎麽能够躺在这
儿等死呢? 说完: 从屋角的箱子里拿出钓竿，准备要去钓鱼....

不管怎麽说，帮助达婆婆重拾健康，你感到无比的快乐。
HAHA
	);
	  if( (int)this_player()->query_quest_level("A_da")<1 ) {
		write("你完成了达婆婆任务，得到了7000点经验值\n");
		this_player()->finish_quest( "A_da", 1 );
		this_player()->gain_experience(7000);
	   }
		                           return 1;
}
}
