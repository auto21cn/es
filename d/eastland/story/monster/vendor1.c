#include "../story.h"
inherit MONSTER;
int left=1;
void create()
{
    ::create();
    set_level(1);
    set_name( "wander merchant", "旅行商人" );
    add("id",({"merchant"}));
    set_short( "旅行商人[骑在驴子上]" );
    set_long(@LONG
这是一个四处旅行贩卖物品的人，他看起来风尘仆仆地正在赶往「巫咸国」去。他
卖的尽是一些稀奇古怪的东西，你可以向他询问价格(price) ，看是否有什麽东西
是你喜欢的。
LONG    
    );
    set( "gender", "male" );
    set( "no_attack", 1 );
    set( "inquiry", ([
	 "price" : "@@show_menu",
        "shadow" : "@@ask_shadow" 
    ]) );
    set( "player_invisible" ,1 );
}
void ask_shadow(object asker)
{
  write(@LONG
商人说道：唉哟，前几天晚上有个冒失鬼撞了我一下，连个对不起都没有就逃掉了
　　　　　，你看看，我肚子上还黑青一块，痛死了，叫那个天杀的，早晚给雷劈
　　　　　死好了。我看他逃往南边的山岭方向，据说，那边最近出没一具僵□精
　　　　　，叫他给僵□啃死了也好。  
LONG
  );
}
void show_menu(object asker)
{
 if ( !left ) 
    write("商人说道：喔，你想要向我买东西喔，唉，真是抱歉，全都卖完了咩，请你下次再来。\n");
 else 
    write("商人说道：唉，今天太好卖了，只剩下水晶玻璃球(glass)而己，你要吗？还有一颗，价钱是 5000 银币。\n"); 
}
void init()
{
    ::init();
    add_action("do_buy","buy");
}
int do_buy(string arg)
{
   object glass,player;
   if ( !arg || arg!="glass" )
      return notify_fail("商人说道：很抱歉，我没卖那样东西。\n");
   if ( !left )
      return notify_fail("商人说道：对不起，都卖完了。\n");
   player=this_player();
   if ( !player->debit("silver",5000) ) 
      return notify_fail("商人说道：对不起，你钱不够，水晶玻璃球需要 5000 银币。\n");  
   glass=new(SWITEM"crystal1");
   if( glass->move(player)!=0 ) {
      glass->remove();
      player->add("wealth/silver",5000);
      return notify_fail("对不起，这样东西对你来说太重了。\n");
   }                                                                      
   glass->set("special_things",1);
   glass->move(player);
   left=0;
   call_out("back",900);
   return notify_fail("你向商人买下了一颗水晶玻璃球。\n");
}
void back()
{  
   left=1; 
}