#include "../takeda.h"
#include "/include/move.h"
#include "conditions.h"
#include "stats.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Gold Snake", "金鳞鬼蟒" );
	add ("id", ({ "snake" }) );
	set_short( "snake","金鳞鬼蟒");
	set("unit","尾");
	set_long(@C_LONG
你看到一条非常巨大的蟒蛇，粗糙的外皮就如同石头般坚硬，表面长满
了许\多金色鳞片，泛起的金光使你看不清原来的纹路，仔细看看似乎有
一股邪气笼罩著它。它现在正在抬头到处张望，不知道它在干嘛，也许你
能够帮助它喔...
C_LONG
	);
	set( "likefish",1);
	set( "unbleeding",1);
	set("alignment",-3500);
	set_perm_stat("str", 25);
	set_perm_stat("dex", 28);
	set_perm_stat("kar",22);
	set_natural_weapon( 65, 32, 56 );
	set_natural_armor( 75, 30 );
	set ("tactic_func","poison");
	set_skill("dodge",100);
	set_skill("target",100);
	set_skill("black-magic",100);
	set_skill("concentrate",100);
	set("magic_delay",2);
	set("spells/ether-bolt",8);
	set ("gender", "male");
	set ("race", "monster");
	set_c_limbs(({"坚硬的鳞片","长长的蛇身","巨大的蛇头","粗大的尾巴"}));
	set_c_verbs( ({"%s卷动整个身体，猛然袭向%s","%s用身体紧紧的卷住%s","%s喷出一股强劲毒液，射向%s"
	,"%s张开血盆大口，一口咬向%s"}));
        set( "inquiry", ([
              "cycle": "@@ask_cycle",
              "蚩尤" : "@@ask_chiyu",
              "lair" : "@@ask_lair",
              "dragon" : "@@ask_dragon",
              "help" : "@@ask_help",
              "chiyu" : "@@ask_chiyu",
              "chuyin" : "@@ask_chuyin"
              ]));
}
void evil_damage()
{
     if ( find_call_out("evil")==-1 )
            call_out("evil",5,0);
}
void init()
{
     ::init();
     evil_damage();
}
void evil(int call_again)
{
     object npc,room,*player;
         int i;
          
         npc=this_object();
         room=environment(npc);
         player=all_inventory(room);
         for(i=0;i<sizeof(player);i++)
         if ( living(player[i]) && player[i]!=npc ) {
         tell_object(player[i],
         "从金鳞鬼蟒身上发出强烈的妖气震伤了你.\n");
         player[i]->receive_special_damage("evil",10+random(20));
         "/d/magic/magic"->report( this_object(), player[i] );
         }
         call_again++;
         if ( call_again<5 ) call_out( "evil", 8 , call_again );
         }

void ask_lair()
{
write (@C_LONG
你感到金鳞鬼蟒在你的心中说道: 这个洞穴是我的祖先九婴(chuyin)所建立的，
C_LONG);
      return ;
}
void ask_cycle()
{
write (@C_LONG
你感到金鳞鬼蟒在你的心中说道: 这个魔法阵是我一手建立的
用来开发一些更强力的黑魔法
C_LONG);
      return ;
      }
void ask_chuyin()
{
      write (@C_LONG
你感到金鳞鬼蟒在你的心中说道: 九婴是我们一族最伟大的英雄，不仅勇武
非凡，更兼法力高强，他传下的黑魔法能力，虽然经过无数祖先的钻研，到
我也大概只能学到八成而已...
C_LONG);     
      return ;
}
void ask_dragon()
{
      write (@C_LONG
你感到金鳞鬼蟒在你的心中说道: 龙是这世界第二强大的生物....第一强大就是
我们妖蛇族
C_LONG );
      return ;
}
void ask_help()
{
      write("金鳞鬼蟒冷冷的看著你......\n");
      call_out("ask_help2",10,this_player());
      return ;
}
void ask_help2()
{
      if ( this_player()->query("alignment") < 0 ) {
      write(@C_LONG
你感到金鳞鬼蟒在你的心中说道: 喔，你好像蛮合我的胃口的，我就把你
当成我的手下吧，传说中蚩尤在屯鹿战死之後，英雄九婴(chuyin)逃到这个山
洞，开始进行让蚩尤(chiyu)复活的光荣任务。
C_LONG
            );
            call_out("ask_help3",10,this_player());
            return ;
            }
      write("金鳞鬼蟒说道: 你是好人，正好我有点饿了.....\n"
             "你觉得它对你不怀好意，主动发动攻击....\n");
      this_object()->kill_ob(this_player());
            return ;
}
void ask_help3()
{
       write(@C_LONG
这麽多年来，由於我的祖先们的努力，所需要的一切咒文及技术都已准备好
了，唯独欠缺使蚩尤复活的关键物－[ 蚩尤的遗骸 ]，目前我正在开发强力
的定位搜寻魔法，以便於早日寻找到它以使蚩尤复活..
C_LONG
       );
             call_out("ask_help4",10,this_player());
             return ;
}
void ask_help4()
{
        write(@C_LONG
不过虽然我的魔法已接近完成，不过最快大概也还要三年
不过在开发这个魔法时，我发现似乎存在另一股力量在阻止我们的任务
若再等三年，不知道会有什麽变化发生，所以若你能够在这三年中，先
找到蚩尤的遗骸并且带到我这里来，你将会因此而得到很大的报酬...
你听了它的话，心里有点想帮助它，但又不知是否适当
不管怎麽说，先回去报告公孙先生你的发现似乎比较恰当...
C_LONG
              );
        this_player()->set_temp("find_something",1);
        return ;
}              
void ask_chiyu()
{
write("蚩尤是我们一族的领袖，为了争夺天下的霸权，与黄帝大战於屯鹿之野。\n"
      "而这附近就是古时候的屯鹿....\n");
      return ;
}
void announce( string msg, string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], can_read_chinese(usr[i])? c_msg: msg );
	}
}
void die()
{  
   object ob1,killer,ob2,ob3;
   
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
      tell_room(environment(this_object()),
            "\n金鳞鬼蟒一声嘶吼，一头往山壁撞去想要逃跑，不料体力透支，竟一头\n"
            "撞死在山壁上。四周的山壁经它这麽一撞，一大堆落石乒乒乓乓的滚了下来..\n\n");
   ob1 = new("/d/adventurer/natural_history/stone");
   ob1->move(TROOM"lair/lair5");         
   ob2 = new("/d/adventurer/natural_history/stone");
   ob2->move(TROOM"lair/lair5");
   ob3 = new(TOBJ"rock");
   ob3->move(TROOM"lair/lair5");
   tell_room( environment(ob3),
   "\n你看到许多大大小小的石头从山上滚下来，你集中全部的注意力闪躲，总算\n"
   "没有打到你...\n");
   ::die();   
}


int poison()
{
	object victim;

	if( random(20)>4 || !(victim = query_attacker()) ) return 0;
	if( random(3) < 1 ) {
	tell_object( victim, 
		set_color("\n金鳞巨蟒血口一张，一团绿色毒雾向你袭来！\n","HIG",victim));
	tell_room( environment(this_object()), 
		"金鳞巨蟒巨口大开，一团毒雾向" + victim->query("c_name") + "的面门罩下！\n"
		, victim  );
	SIMPLE_POISON->apply_effect( victim, 8, 10 );
	return 1;
	}
	command("cast ether-bolt on "+victim->query("name"));
	this_object()->receive_healing(30);
	return 1;
}
