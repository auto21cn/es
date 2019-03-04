
#include "../../layuter.h"
inherit WEAPON;

void create()
{
        
        seteuid(getuid());
        set_name( "stell axe", "钢斧" );
        add( "id",({ "axe" }) );
        set_short( "钢斧" );
        set("long","@@layuter_c_long");     
        set( "unit", "把");
        set( "weapon_class", 20 );
        set( "type", "axe" );
        set( "min_damage", 6 );
        set( "max_damage", 15 );
        set( "weight", 180 );
        set( "value", ({ 100, "gold" }) );
}

void init()
{
  add_action("to_chop","chop");
 }
 
 string layuter_c_long()
 {
  if (query("woodman_die"))
    return "这是一把沾满血迹的斧头。\n";
  else 
    return "这是樵夫所用以砍(chop)树的斧头。\n";  
 } 
  
int to_chop(string str)
{  
   object ob1,ob2,ob3,ob4;
   int layuter_test;
   
   layuter_test=this_object()->query("woodman_die");
   if (!str||str==""){
     write("你要砍什麽\n");
          return 0;
           }        
   else if (str=="tree"){
     ob1=environment(this_object());
     if (ob1==this_player()){ 
       ob2=environment(ob1);
       layuter_test=this_object()->query("woodman_die");
       if (layuter_test==1){
           write("这把斧头上因沾满血迹而变得太滑，你不能拿它砍树。\n");
           return 1;
           }
       else if (ob3=(present("layuter_tree",ob2))){
         ob3->remove(); 
         ob4=new(Lditem"layuter_tree1");
         ob4->move(ob2);
         write("你拿起斧头开始砍树，当你砍开此树你在树心发现一根奇特的木棍\n");
         return 1; 
          }              
        else {
          write("这里并没有你想砍的树\n");
            return 1; 
            } 
        }
    else {
      write(
       " 很抱歉，你并没有合适的工具可以砍树\n");
       return 1;
       }
    }   
}
