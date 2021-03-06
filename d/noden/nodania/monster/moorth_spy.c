#include <mudlib.h>

inherit MONSTER;

void create()
{
   object weapon;

	::create();
	set_level(13);
   set_name( "Moorth Spy", "默尔斯间谍" );
   add( "id", ({ "spy" }) );
   set_short( "默尔斯间谍" );
	set_long(
         "他是默尔斯大军(army)派出的间谍, 他正努力地刺探军情(news)。\n"
	);
   set( "alignment", -500 );
	set_perm_stat("str",16);
	set_perm_stat("dex",15);
	set_skill("parry", 50);
   set_skill( "dodge", 60 );

	set( "race", "human" );
	set( "gender", "male" );
   set_natural_armor( 40, 10 );
   set( "pursuing", 1 );
   set( "moving", 1 );
   set( "speed", 10 );
   set( "patrol", ({ "east", "west", "west", "west", "west", "east",
          "north", "south", "east", "east" }) );

   wield_weapon( "/d/moorth/obj/shortsword" );

   set( "inquiry", ([
          "news" : "@@ask_news",
          "reward" : "@@ask_reward",
          "inform" : "@@ask_inform",
          "army" : "我们的大军正准备进攻诺达尼亚城, 要命快闪吧!\n" 
        ]) );
}

int ask_news(object who)
{
   if( (int)who->query_level()<5 ) {
     write( "走开! 走开! 无名小卒别烦我!\n" );
     return 1;
   } else {
   tell_object( who, @LONG
嘿嘿嘿...没错! 我正在收集情报, 如果你能提供对我们有利的
情报(inform), 你将会得到很大的好处(reward)!
LONG
     );
     return 1;
   }
   return 1;
}

int ask_inform(object who)
{
   if( (int)who->query_level()<5 ) {
     write( "走开! 走开! 无名小卒别烦我!\n" );
     return 1;
   } else {
   tell_object( who, @LONG
我们的军队一直想进攻达尼亚城, 无奈那个守军将领戴利佛
对我们的行动了如指掌, 要是他死掉就好了!
LONG
     );
     return 1;
   }
   return 1;
}

int ask_reward(object who)
{
   if( (int)who->query_level()<5 ) {
     write( "走开! 走开! 无名小卒别烦我!\n" );
     return 1;
     }

   if( who->query_temp("war_spy") ) {
   tell_object( who, @LONG
很好, 非常感谢你的帮助! 而且也高兴看到你还活著!
这是当初讲好的赏金.
[ 默尔斯间谍拿出一袋钱币给你 ]
LONG
     );
   who->credit( "silver", 777 );
   who->delete_temp( "war_spy" );
   who->set_explore("noden#15");
   return 1;
   } else {
     write(
"如果那个将军死去, 而你能在高塔上挥舞(brandish)他的佩剑\n"
"通知我军的话, 我将给你一笔庞大的赏金! 不过...\n"
"我们的大军是六亲不认, 杀人不眨眼的噢!\n" );
     return 1;
     }
   return 1;
}
