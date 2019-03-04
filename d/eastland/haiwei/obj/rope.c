#include <mudlib.h>

inherit CONTAINER;

void create()
{
        
        seteuid(getuid());
        set_name( "rope", "绳子" );
        set_short( "绳子" );
   set_long( "一根长绳子。\n" );
        set( "weight", 18 );
        set( "value", ({ 1, "silver" }) );
}

void init()
{
  add_action("to_throw","throw");
 }
  
int to_throw(string str)
{
  object ob1,ob2;
  int test;
   if (str!="rope")  return 0;      
   else if (str=="rope"){
     ob1=environment(this_object());
     if (ob1==this_player()){ 
       ob2=environment(ob1);
       test=ob2->query("layuter_hole");
       if (test==1){
       tell_room(this_object(),this_player()->query("c_name")+"丢出一条绳子，跟著进入了洞中。\n",this_player());
       write("你把绳子丢出勾住洞外大石，然後沿著绳子爬入洞内，你顺手将绳子收起来。\n");
       this_player()->move_player("/d/eastland/haiwei/hole1","SNEAK");
       return 1;
        } 
      else write("你将绳子抛上抛下的玩著。\n");            
      }
    return notify_fail("你身上并没有绳子！\n");
  } 
 }
