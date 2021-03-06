#include <mudlib.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(1);
        set_name( "bookbug", "肥肥的蛀书虫" );
        add("id",({"bug"}) );
        set_short( "肥肥的蛀书虫" );
        set_long(@LONG
一只肥肥的小虫，不仔细看还看不到，它正高兴的啃著散落的书页，
依你的经验看起来，这麽弱小的虫虫，只要你一脚就可『踢』死它。
LONG
        );
        set( "gender", "male" );
        set( "race", "shapeshifter" );
        set( "alignment", -10 );
        set_natural_armor( 1, 2 );
        set_natural_weapon( 5 , 2 , 3 );
        set_perm_stat( "kar", 10 );
        set("exp_reward",1);
}
 
void init()
{
        add_action("to_kick","kick");
}
 
int to_kick(string str)
{
   object who, owner;
   
   who = this_player();
   owner = present( "book shop owner", environment(this_object()) );
   
   if (str != "bookbug" && str != "bug")
                return notify_fail( "你想踢啥?\n" );
   tell_object(this_player(),@LONG
你狠狠的往小虫身上踹了下去，小虫连挣扎的机会也没有，就烂成一团死掉了。
LONG
        );
   if ( (int)who->query_quest_level("bookbug") > 0 ) {
        this_object()->remove();
        return 1;    
     }  
   if( !owner ) {
        this_object()->remove();
        return 1;
     }   
                   
   tell_object(who,@LONG
书店老板感激的握著你的手说 :
谢谢你帮我杀死蛀虫! 这下子我就不必担心书会卖不出去啦!
真的是非常的感激!
 
你完成了『书店老板的烦恼』的任务，获得 300 点经验点。
LONG
        );
  
//如果不是自己找或是踢的话 任务点数会比较少。
   if ( (int)who->query_temp("findbug") < 1 )   
        who->finish_quest( "bookbug", 1 );
      
   who->finish_quest( "bookbug",2 );
   who->gain_experience(300);
   who->delete_temp("findbug");
   this_object()->remove();
  return 1;
}
 
void die()
{
  object who, owner;
  who = query( "last_attacker" );
  owner = present( "book shop owner", environment(this_object()) );
  
  if ( !who->query_quest_level("bookbug") && owner ) {
        tell_object(who,@LONG
书店老板感激的握著你的手说 :
谢谢你帮我杀死蛀虫! 这下子我就不必担心书会卖不出去啦!
真的是非常的感激!
 
你完成了『书店老板的烦恼』的任务，获得 300 点经验点。
LONG
        );
     who->finish_quest( "bookbug", 1 );
     who->gain_experience(300);
  }
     
  ::die();
}
 
