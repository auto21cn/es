
#include "../echobomber.h"
inherit "/std/room/waterroom";

int can_enter;
void create()
{
   ::create(); 
   set("light",1);
   set("short","码头的水底");

   set("long","@@c_long");
   set("item_desc",([
    "stones":"石头上的青苔有磨损的痕迹,你可以试著移动它\n",
    "fish":"一群奇奇怪怪的鱼,似乎只有这个地方才会出现.\n"
     ]) );
   set("exits",([
              "up":Deathland"/main/d1",
              "down":Deathland"/main/d5"
             ]));

reset();
}
void init()
{
  add_action("to_move_stone","move");
  add_action("to_enter_hole","enter");
}

int to_move_stone(string str)
{
   if (!str||str=="")
     return 0;
   if (str=="stones"|| str=="stone") {
       write("你用了很大的力气去移动石头,渐渐地一个洞出现在你的眼前\n");

     can_enter=1;
     add( "item_desc",([
          "hole":"一个奇怪的洞,不能确定它通往何处.\n"
              ]) );
    this_player()->set_explore( "deathland#1" );
    return 1;
    }
}

int to_enter_hole(string str)
{
    if ( can_enter==0 ) return 0;
    if (!str||str!="hole") {
      write("进入甚麽地方 ?\n"); 
      return 1;
      }
    write("你小心翼翼地游进洞穴\n");
    say("当你看到"+this_player()->query("c_name")+
         "游进洞中,石头再度地把洞口盖\住\n");
    this_player()->move_player(Deathland"/main/d6",
    ({"%s swim to hole,then the stone close the hole\n","当你看到%s游进洞中後,石头再度地把洞口盖\住\n" ,
      "%s swim from outside.\n","%s从外面游了进来.\n"}),"");
    can_enter=0;
    return 1;
}

void reset()
{
   ::reset();
   can_enter=0;
   
}

string c_long()
{
    string longlook;

    longlook="微弱的光线从海面照射下来,你能看到一些鱼(fish)在这里游来游去.\n";
    switch( can_enter ) {         
         case 0:
           longlook+="仔细一看北方的岩石(stones)似乎常常有人搬动的样子.\n";
           break;
         case 1:
           longlook+="仔细一看北方的岩石(stones)似乎已被人搬开了,有一个洞穴\n"
                     "出现在你的面前.\n";
           break; 
          }
    return longlook;       
}

