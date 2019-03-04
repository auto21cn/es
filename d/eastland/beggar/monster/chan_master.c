#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "a drunk man", "倒在桌上的醉汉" );
    add( "id",({"man"}) );
    set_short( "倒在桌上的醉汉");
    set("no_attack",1);
    set_long(@C_LONG
一个倒在桌上的醉汉。
C_LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",18);
    set("gender","man" );
    set("no_attack",1);
    set("weight",300);
    set("chat_chance",2);
    set("chat_output",({
         "醉汉道:店小二,拿酒来。\n"
    }) );
                                    

}        
int accept_item(object me, object item)
{
      string name,my_name;
      
      name=(string)item->query("name");
      my_name=(string)me->query("name");
                  
      if (name!="chan letter")
         return 0;
//     if( (int)me->query_quest_level("dony1") ) {
       if ( me->query("finish_dony") ){
         tell_object( me,"醉汉说道:谢谢。\n");
         item->remove();
         return 0;
      }   
      if ( ( item->query("master") ) != my_name ) {
         tell_object( me,
           "醉汉说道:你这是打那儿来的东西啊?\n");
         command("give chan letter to "+my_name);
      }
      else {
         tell_object( me,
           "醉汉接过你的信件...........\n");
         item->remove();
         call_out("recover1",15,me);
      }
      return 1;
}
void recover1(object me)
{
     object ob1;
     
     tell_object( me ,
        "醉汉激动地说道:这.这这...是..是是......\n"
        "醉汉叹道:唉,全然错了。看了我父亲给我的信之後,我才知道原来他老人家是咎由自取\n"
        "         ,这跟我所想的完全不一样,我本想救他老人家出来,然後杀了震八方替他报\n"
        "         仇可是,幸亏有你带来的信,否则........................................\n"
        "         烦麻你把这根打狗棒送还给帮主,并且跟他老人家说我太对不起他了无颜见他\n"
        "         ,最後我只有一个心愿,吾之女儿还请你代嫁。\n");
     ob1=new(DITEM"dog_blunt");
     ob1->set("master",me->query("name"));
     ob1->move(this_object());
     command("give dog blunt to "+me->query("name"));   
     tell_object( me ,
        "醉汉说完之後就不见了。\n");
     this_object()->remove();   
}      