#include <../goomay.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(12);
	set_name( "hunter", "猎人阿三" );
	set_short( "猎人阿三" );
	set("long","@@query_c_long");
	set( "gender", "male" );
	set( "race", "orc" );
	set( "no_attack",1);
	set("inquiry",([ "health" : "@@ask_health" ]) );
}
void ask_health()
{
if( (int)this_player()->query_quest_level("Goddess_statue") < 2 )
	tell_object(this_player(),
	"猎人阿三感激地道 ： 谢谢你，我觉得好多了，请问你有找到我弟弟小四吗？\n"
	"他在段家矿场工作，你问问守卫就知道了。\n");
else
	tell_object(this_player(),
	"猎人阿三爽朗地笑道 : 谢谢你 ! 我已经好了，小四也回来了，真不知道该怎麽感谢你 !!\n");
	return ;
}

string query_c_long()
{
if( (int)this_player()->query_quest_level("Goddess_statue") ){
    set("hit_points",this_object()->query("max_hp"));
    return "你看到一个健康(health)快乐的猎人，他有著古铜色的皮肤和令人信赖的眼神。\n"
     "他是山野的英豪 !! 如果你有任何需要，可以直接找他帮忙。\n";
  }
 else
  {
   set("hit_points",1);
   return "你看到一个病的奄奄一息的可怜人，原本古铜色的皮肤现在都成了死灰色，\n"+
     "如果再没有人为这个神智不清的人去请医生，恐怕他撑不了多久。\n";
  }
}

int accept_item(object me,object item)
{

     if ((string) item->query("name") !="pack of herbs" || 
         (int)this_player()->query_quest_level("Goddess_statue")>0 ) {
     tell_object(me,
        "猎人阿三苦笑著摇摇头：「谢谢 !! 我不需要这东西 !!」\n");
        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
     tell_object(me,
"你把药包交给重病的猎人，并且帮他煎好了药□他，吃了药以後的阿三果然精神\n"
"好多了，虚弱的他挣扎著说：「我有一个弟弟，在段家的铁矿坑工作，可否请您\n"
"替我把他叫回来 !! 谢谢 !! 你只要跟矿场守卫说要找"+
set_color("小四","HIY")+"就可以了 !! 」\n\n"
"看到他好多了，你觉得很欣慰 !! "+set_color("[ 得到 1500 点经验 ]","HIC")+"\n"
		 );
	item->remove();
	this_player()->finish_quest( "Goddess_statue", 1 );
	me->gain_experience(1500);
        return 1;
}
