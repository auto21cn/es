//sage修改于： 98-6-11
#include "/d/monk/guild/saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
        ::create();
    set_short("杀手武功练习室");
        set_long( @LONG_DESCRIPTION
这是一个很潮湿阴暗的房间，整个房间弥漫一股血腥香味。由於长没有人来过，你发
现地上的石板都长满了厚厚的一层青苔。    
这个房间的正中央有一具骸骨，不知道是何用意，墙上贴了一张纸(paper) 。  
LONG_DESCRIPTION
        );
    set("c_item_desc",([
         "bone":@BOOK
          一具很陈旧的骸骨，可能是某个武林高手在这里死后留下来的唯一的纪念
      品，想到这里，你从心底下产生了一种敬仰之情，要不是怕别人看见，你真想
      跪下去个给这位老前辈磕几个头。        
BOOK
         "paper":@BOOK
                         
                           偷兵器剑法修习资格

       1. 是本公会护法以上身份。
       2. 要非常邪恶。  
       3. .............(不可告人的条件，看你是否有缘)。 

       达到以上资格者，才能在此练习偷兵器剑法(practice getsb-sword) 

       注: 本公会绝技众多，但本公会一向主张在精不在多的原则，每个会员只能择
           其一学之。
BOOK
]));         
        set( "light", 1 );
        set( "exits", ([ 
//             "down" : SAULIN"72" ]) );  
               "west" : "/d/killer/guild/killer_guild"]) );
        reset();
}

void init()
{
        add_action("to_study","ketou");
//      add_action("to_delete","sangon");
}

/*
int to_delete(string arg)
{
        object me;
        if( !arg || arg != "bone" ) return 0;
        me = this_player();
        if( undefinedp( me->query("monk_gonfu/power-finger") ) )
             { write(" 你跟本不曾学过大力金刚指! \n");
               return 1;
             }
        else {
        write("你的金刚指力暂时消失了!!! \n"); 
                me->delete("monk_gonfu/power-finger");
                me->set("monk_learn/72",0);
                return 1;  
         }
} 
*/      /*暂时决定不能散功*/

int to_study(string arg)
{
        object me;

        if( !arg || arg != "getsb-sword" ) return 0;

        me = this_player();
        if( !wizardp(me) && (string)me->query("class") != "killer" )
                write("你不是本公会的人所以不能学此功\夫。\n");
//        else if( (int)me->query_level() < 15 )
//                write("『 你的职级太低，没资格学。\n");
//        else if( (int)me->query_perm_skill("inner-force") < 72 )
//                write("『 你的基本内功\(inner-force)技巧太差，没资格学。\n");
//        else if( ((int)me->query_perm_stat("str") < 17) 
//                          )
//                write(" 你的力量不够，还没资格学大力金刚指。\n");
//        else if( !undefinedp(me->query("monk_gonfu/power-finger")) ) {
//                if((int)me->query("monk_gonfu/power-finger")==35) {
//                        write("你已经完全了解大力金刚指的要义了，可以再去练习另一种绝技。\n\n");
//                        me->set("monk_learn/72",0); }   
//                else write("你已经学会大力金刚指了，快去练习吧!\n"); }
          else if( me->query("killer_learn/72") )
                  write("你已经学过一项绝技了!\n");
          else {
                write(@LONG
        
       突然，骸骨站了起来冲着你一阵阴笑，你立刻毛骨悚然，吓得双脚一软，
   跌到在地，骸骨伸出两只鬼抓向你脑袋抓来，你只觉得脑袋一阵剧痛，心想
   到：“我命休已。”就昏了过去。

LONG
                );  
                me->set("monk_gonfu/power-finger", 0);
                me->set("monk_learn/72",1);
        }  
    return 1;  
} 

int clean_up() 
     { return 1; }
