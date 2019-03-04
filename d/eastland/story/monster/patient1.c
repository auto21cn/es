#include <mudlib.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "patient","受伤者" );
	set_short("受伤者");
	set_long(@C_LONG
这是一位受伤沈重的人，他已陷入昏迷状态；在他全身上不下千百个创口，每个创
口都深及见骨，伤口处还泊泊地流著大量的鲜血，然而，你却发现，每个伤口似乎
都有经过熟练的包扎，慢慢地不再流著鲜血。你细看，他的嘴唇黑的吓人，看来是
中了某种剧毒！但见他口中喃喃自语，似乎极需要你的帮忙。
C_LONG
	);
	set("unit", "名" );
        set("race","human");
        set("gender","male");
        set("max_hp",10000000);
        set("hit_points",1);
        set("no_attack",1);
        set( "inquiry", ([
             "help":"@@ask_help",
             "trouble":"@@ask_help",
             "poison":"@@ask_help",
             "帮忙":"@@ask_help",
             "麻烦":"@@ask_help",
             "剧毒":"@@ask_help",
        ]) );
}
void ask_help( object asker )
{
write(@C_LONG
受伤者说道：吾人到这里探险，不小心被「文蛛」所伤，因而受伤沈重。
　　　　　　伤口处已被路过的高人包扎了，但高人却束手无策关於我所
　　　　　　中之毒，唉，没想到我就要死在这里了．．
　　　　　　　
C_LONG
      );
}
int accept_item(object me, object item)
{
    string my_name,item_name;
    
    my_name=(string)me->query("name");
    item_name=(string)item->query("name");
    if ( !item->query("drink_liquid")) {
       write("受伤者不要你这个东西。\n");    
       command("give "+item_name+" to "+my_name);
       return 1;
    }    
    item->remove();
    write (@LONG       
受伤者喝下你带来给他的「文蛛」毒液，登时，他身上所中的毒全解除了！
受伤者说道：感谢你解除我身上所中之毒，有一事不敢不告诉，那就是－－
　　　　　　这里的丛林被人施之法术，不知究竟的人是无法走出去的，只
　　　　　　要你遇到「文蛛」时快折回西走，往南，再向东，那就可以脱
　　　　　　困了。
LONG
    );
//    if ((int)me->query_quest_level("patient")<1 ) {
  if ((int)me->query("quests/patient")<1 ) {
      
    write (@LONG
        
  [ 由於你热心地解除了受伤者的所中的毒，因而意外地获得到 2000 点的经验]    
    
LONG     
    );
//    me->finish_quest("patient",1);
    me->set("quests/patient",1);
    me->gain_experience(2000);
    }
    return 1;
}                  