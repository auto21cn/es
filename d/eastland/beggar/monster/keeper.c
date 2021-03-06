#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "keeper hau", "霍先生" );
    add( "id",({"keeper","hau"}) );
    set_short( "帐房 霍先生");
    set("no_attack",1);
    set_long(@C_LONG
霍先生约莫四、五十岁年纪, 戴著一只小小的玻璃镜片,镜片里好像看不到任何有
关眼睛的讯息。顶著镜片的是一个红红鼻子, 呼吸间有著浓浓的酒臭味,走起路来
一摇一摆的好像被风一吹就会摔倒在地,可见他平时喝酒之多。他看起来好像遇到
麻烦了,也不去平时去的『薪胆村』酒店喝酒。
C_LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",45);
    set("gender","man" );
    set("no_attack",1);
    set("chat_chance",4);
    set("chat_output",({
            "霍先生不停地走来走去。\n",
            "霍先生停下来望著天花板似乎在想事情。\n",
            "霍先生深深地叹了一口气,霍先生叹到:唉~~。\n"
    }) );
    set("inquiry", ([
             "trouble":"@@ask_trouble",
             "help":"@@ask_help" 
    ]) );
}        
void ask_trouble(object asker)
{
    tell_object(asker,
     "霍先生说道:这位英雄好汉,请问你能帮助 ( help ) 我吗?\n"
       );
}
void ask_help(object asker)
{
    tell_object(asker,
     "霍先生说道:事情是这样的:有一天晚上,我妻子替我看管监狱的钥匙, 不知道\n"
     "           是谁, 从她背後偷偷地下了一个重手以致於她现在奄奄一息, 倒\n"
     "           床上昏昏沈沈的要死不活。於是我去请教过大夫, 大夫说她中了\n"
     "           某种厉害的掌力,需要『天山九转熊蛇丸』( pill ) 才能够医治\n"
     "           她,可是这里离天山那麽远,我又有要事在身不克前往, 请问你能\n"
     "           帮我取来吗?我会很感激你的\n"   
                );
}
int accept_item(object me, object item)
{
      string name,my_name;
      object ob;
      
      name=(string)item->query("name");
      my_name=(string)me->query("name");
         
      if ( (name!="bear-snake pill") && (name!="sun pill") )
         return 0;
      
      switch ( name ) {
      case ( "bear-snake pill"):
         if ( ( item->query("master") ) != my_name ) {
            tell_object( me,
            "霍先生说道:咦,你这是从那里偷来的九转熊蛇丸? 拿回去吧, 我宁\n"
            "           死也不愿用你偷来的药!!\n");      
            command("give pill to "+my_name);
            return 1;}
         else {
            tell_object( me,
            "霍先生很感激地接过你的熊蛇丸,并对你说请等一下,我拿去给内人服用...\n"
            "霍先生把你的熊蛇丸拿给身边的童子交由他带到内室去。\n");
            item->remove();
            me->set_temp("keeper_finish1",1);
            call_out("recover1",10,me);
         }
         return 1;
      case ( "sun pill" ):
         if ( ( item->query("master") ) != my_name ) {
            tell_object( me,
            "霍先生说道:咦,你这是从那里偷来的六阳正气丹? 拿回去吧, 我宁\n"
            "           死也不愿用你偷来的药!!\n");
            command("give sun pill to "+my_name);
            return 1;}
         else {
            tell_object( me,
            "霍先生接过你的正气丹,交由身边童子带到内室去。\n");
            item->remove();
            me->set_temp("keeper_finish2",1);
            call_out("recover2",10,me);
         }              
      }
}      
void recover1( object obj)
{
    tell_object( obj,
      "\n你忽然听到一个凄惨的叫声!!!!\n\n\n"
      "内室有一个童子跑到霍先生的身旁咬耳朵。\n"
      "霍先生说道:怎麽会这样?快快快,你快去找医生救命!!我内人服用了你带来的\n"
      "           九转熊蛇丸之後就口吐白沫晕倒了!!\n"
        );     
}
void recover2( object obj)
{
    tell_object( obj,
      "从内室跑出来的童子依旧到霍先生的身旁咬朵耳。\n"
      "霍先生微笑地向你谢道:大恩不言谢,内人的病终於好了。\n"
      "霍先生说道:对了,跟你说一件事,内人刚说那天偷袭他的人好像跑往\n"  
      "           监狱 ( jail ) 那个方向,如果你想知道监狱在那里,可\n"
      "           以去请教帮中高层份子。\n" );
}