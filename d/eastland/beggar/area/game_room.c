#include "/d/eastland/beggar/dony.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "『吉祥』赌坊" );
        set_long(@C_LONG
你立足之地是『薪胆村』里面最大的赌坊,这里的空气有点混浊, 吆喝声特别
大。在村里,平时人们没有什麽地方可以去游憩的,也没有什麽东西好娱乐的,只有
来这儿赌上一、两把赚赚外快, 你也可以来这里试试你的手气喔。不过俗话得好:
『十赌是九输』,你应该不会这麽傻吧。墙壁上有一张纸。
C_LONG
        );
        set( "c_item_desc", ([
            "paper" :@C_LONG
斗大的字上面写著:
        本赌坊的赌法采一次开三个骰子的方式;你先要 ( bet number type )
        如: bet 100 silver 表示你一局押 100 个银币的筹码,再 ( select 
        number number number ) 如: select 2 3 5 表示你押 2 3 5 这三个
        数字。三个数字都完全命中则赔你 200 倍的筹码;除此之外就没有了。 
C_LONG
        ]) );
                                         
        set("exits",([
             "west":DBEGGAR"north1"
        ]) );
        set("objects", ([
             "merchant":DMONSTER"ch_waiter"
        ]) );     
        reset();
}
void init()
{
      add_action("do_bet","bet" );
      add_action("do_select","select");
}

int do_bet(string arg)
{
   object who;
   string type,weal_type;
   int num,weal;
                           
   if ( !arg || arg=="" || sscanf( arg, "%d %s", num, type)!=2 )
       return notify_fail("你要押多少？什麽种类的钱？\n");
   if ( type!="silver" )
       return notify_fail("请你以银币为单位,谢谢。\n");
   who=this_player();
   weal=who->query("wealth/silver");                        
   if ( num > weal )
       return notify_fail("对不起,你身上所带的钱不够喔。\n"); 
   if ( num > 5000 )
       return notify_fail("对不起,小小的店面请不要超过 5000 银币。\n");
   who->set_temp("money_bet",num);
   tell_object(who,
      "你押 "+num+" 个银币。\n");
   return 1;    
}
int do_select(string arg)
{
   object me;
   int num1,num2,num3,number1,number2,number3,bet_money;
   
   if ( !arg || arg=="" || sscanf( arg, "%d %d %d", num1, num2, num3)!=3 )
       return notify_fail("你到底要押那几个数字呀？\n");
          
   if ( num1>6 || num1<1 || num2>6 || num2<1 || num3>6 || num3<1 ) 
       return notify_fail("你是不是输昏了头,骰子有不是小或等於六的正整数吗?笨!\n");
   
   me=this_player();
   bet_money=me->query_temp("money_bet");

   if ( !bet_money )
       return notify_fail("对不起,你得先押一些筹码。\n");
   if ( bet_money > (me->query("wealth/silver")) )
       return notify_fail("对不起,你身上所带的钱不够哟。\n");
   
   tell_object(me,
      "你现在一共押了 "+num1+" "+num2+" "+num3+" 这三个数字。\n");
   me->add("wealth/silver",-bet_money);
   number1=random(6)+1;
   number2=random(6)+1;
   number3=random(6)+1;        

   tell_object(me,
      "开出来的结果是 "+number1+" "+number2+" "+number3+" 个数字。");
   if ( ( num1==number1 ) && 
        ( num2==number2 ) && 
        ( num3==number3 ) ) {
         me->add("wealth/silver",201*bet_money);
         tell_object(me,"PERFECT!!竟然完全被你猜中,厉害厉害!!\n");
         tell_room(this_object(),                
"天空传来一声宁丹的叹息声,"+me->query("c_name")+"竟中了二百倍的奖金!!\n",me);
   } else
      tell_object(me,"可惜,没猜中。\n"); 
   return 1;                     
}
