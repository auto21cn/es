
#include "../../layuter.h"
inherit WEAPON;

void create()
{
        seteuid(getuid());
        set_name( "occult knife", "神秘小刀" );
        add( "id",({ "axe" }) );
        set_short( "神秘小刀" );
        set_long(
            "这是一把解剖(vivisect)刀。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 1 );

        set( "type", "axe" );
        set( "min_damage", 1 );
        set( "max_damage", 2 );
        set( "weight", 20 );
        set( "value", ({ 1, "gold" }) );
}

void init()
{
  add_action("to_vivisect","vivisect");
 }
  
int to_vivisect(string str)
{  
   object ob1,ob2,ob3,ob4;
   
   if (!str||str==""){
     write( "你要解剖什麽\n" );
          return 1;
           }
   else if (str=="corpse"){
     ob1=environment(this_object());
     if (ob1==this_player()){ 
       ob2=environment(ob1);
       if (ob3=(present("corpse",ob2))){
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
