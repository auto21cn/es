#include "../../story.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "golden older", "金石老人" );
	set("id",({"older"}));
	set_short( "金石老人" );
	set_long(@C_LONG
你眼前所见的是一位面貌清矍、身材极为瘦小的老人。他鼻塌嘴阔，鼻孔掀天，两
眼深陷，眉毛甚是稀疏，全身皮肤呈现金黄色，一副不太爱理人的样子，古怪已极
。金石老人生平最喜欢收集和与人交换(exchange)奇物异宝，除此之外，没有什麽
嗜好。
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(30,0); 
        set("no_attack",1);
        set("inquiry",([
          "exchange":"@@ask_exchange",
          "fly_building":"@@ask_building"
        ]) );
}
void init()
{
   ::init();
   add_action("do_help","help_me");
   add_action("do_select","select_me");
}
int do_help(string arg)
{
    object player;
    player=this_player();
    if (!player->query_temp("golden_older_asked")) return 0;
    switch ( arg){
    case "1":
        write(@LONG
金石老人道：
遁龙桩是遁法的一种，是我早年用法术练的，不管你遭遇到什麽样的危险或者
身在千里之外，你只要(use_dragon_wood)，它都会把你带到我的住所来。　
LONG
    );
       return 1;
    case "2":
        write(@LONG  
金石老人道：
万相俱灭术是我多年研究有形无形等物质的心得而来的。万相俱灭术在於隐藏
自已的形踪变成空气中的尘埃，并在空间放著一个自己的法相用以欺骗敌人，
以达到保护自已的功用。不过，由於研究的不完全，所以只能对某些特定的怪
物而使用。使用时，你只要　(　cast-me wonderful　)　就可以了，不过请
切记，这术有使用的时效，如果想变回只需　( uncast-me wonderful )　就
可以了，据我的估计，全部有半个时辰的时效。
LONG   
    );
        return 1; 
    case "3":
        write(@LONG
金石老人道：
纯金打造的篮子，有点像狗笼之类的，可以用来装(package)动物。
LONG
    );        
        return 1;
    default:
        write("金石老人道：这并不在我跟你交换的东西之内。\n"); 
        return 1;
    }
}
int do_select(string arg)
{
    object player,item;
    player=this_player();
    if (!player->query_temp("golden_older_asked")) return 0;
    player->delete_temp("golden_older_asked");
    switch(arg) {
    case "1":
         write("你想了想，决定要遁龙桩这样东西。於是金石老人拿出了遁龙桩放在地上。\n");         
         item=new(SWITEM"flee1");
         item->move(environment());
         return 1;
    case "2":
         write("你想了想，决定要万相俱灭术这样东西。於是金石老人拿出了万相俱灭术放在地上。\n");
         item=new(SWITEM"spell2");
         item->move(environment());
         return 1;   
    case "3":
         write("你想了想，决定要金色篮子这样东西。於是金石老人拿出了金色篮子放在地上。\n");
         item=new(SWITEM"basket1");
         item->move(environment());
         return 1;
    default:
         write("金石老人道：这并不在我跟你交换的东西之内。\n");                       
         player->set_temp("golden_older_asked",1);
         return 1;
    }
}
void ask_exchange(object asker)
{
   
   if ( asker->query_temp("golden_older_asked") ) {   
       write(@LONG
金石老人道：请问你要交换下列什麽样的东西呢？

     **********************************
       1.遁龙桩(dragon wood)。
       2.万相俱灭术(wonderful-spell)。
       3.金色篮子(golden basket)。

       
如果不懂请打(help_me number)，决定好了以後选一样(select_me number)。
LONG
   );
   return;
   }

   if ( asker->query_temp("exchange_things_with_older") ) {
       write("金石老人道：怎麽，今天有带什麽东西来跟我交换吗？\n");   
       return ;
   }
   if ( !asker->query_temp("golden_older_asked") ) {
      write("金石老人白了你一眼道：小孩子没事不要来打扰我，问东问西的，讨厌死了～\n");
   return ;
   }
}
void ask_building(object asker)
{   
   if ( asker->query_temp("exchange_things_with_older") ) {
   write(@LONG
金石老人道：天都？看在你跟我交换东西的份上，我就指点你一迷津。天都是众神
　　　　　　居住的地方，想去天都得借「飞翔之笛」(fly_flute)才能到达。
LONG
   );
   return ;   
   }
  write("金石老人白了你一眼道：小孩子没事不要来打扰我，问东问西的，讨厌死了。\n");
  return ;
}
int accept_item(object player, object item)
{
    if ( !item->query("special_things") ) {
       item->remove();
       tell_object(player,@LONG

金石老人接过你给他的东西并且打量一番...
金石老人开口道：这个东西并不怎麽样，不过，既然拿了你的东西，那我也不能失礼。
接著金石老人从口袋里掏出一个银币给你，接著就不理你了。

LONG        
    ); 
       player->add("wealth/silver",1);
       return 1;
    }
    item->remove();
    player->set_temp("golden_older_asked",1);
    tell_object(player,@LONG
金石老人接过你给他的东西打量一番後瞪大了眼！
金石老人喜牧牧地开口道：嗯，的确是个非凡的东西，这样吧，我也送你一样
                       东西做为交换好了。
金石老人在四周翻倒柜拿了几样东西。
金石老人说道：嗯，下列有几样东西你挑一样吧，如果不知道那一样好，你就
              ( help_me number )好了，我会跟你说明。决定好了以後，选
              择( select_me number )一样你喜欢的，不过选择好以後就不
              准後悔了。　　

     **********************************
       1.遁龙桩(dragon wood)。
       2.万相俱灭术(wonderful-spell)。
       3.金色篮子(golden basket)。       


LONG
    );
    player->set_temp("exchange_things_with_older",1);
    return 1;
}
