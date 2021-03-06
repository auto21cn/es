#include "takeda.h"

inherit ROOM;

void create()
{
	object me;
	me = this_player();
	::create();
	set_short( "钓鱼平台" );
	set_long(
	"　　这是一个小小的平台，原来似乎是设计用来停泊船只的，不过，因为\n"
	"石碣村的人们越来越不常出去打鱼了，这里反而变成钓鱼的人大显身手的\n"
	"好地方。你如果有带钓竿来的话，或许可以在此试试手气。\n");
	set( "light",1 );
        set_outside("eastland");
        set( "exits", ([
        "south" : TROOM"village2"]));
                        
        set( "objects" ,([
        "fisher" : TMONSTER"fisher"]));
        reset();
}
void init()
{
   add_action("do_fish","fish");
   add_action("do_pull","pull");
}
int do_fish()
{
   if ( !(int)this_player()->query_temp("can_fish")==1)  { 
   write(
   "\n你是姜太公吗??\n");  
    return 1; 
    }
   if ( present("fish rod",this_player()) )
     {
      write(
      "\n你把钓具准备好，找了个舒服的位子坐下，开始快乐的钓鱼...\n\n");
     
      tell_room(this_object(),
      "你看到"+this_player()->query( "c_name")+"准备好钓竿，开始快乐的钓鱼。\n",this_player());
   if (present("fisher")) 
     {
      write(
      "\n旁边的钓鱼人把头伸了过来，说道: 您也是来钓鱼的吧，钓鱼需要很大的\n"
      "耐心，不然是不可能钓的到鱼的。\n\n");
     
     
      this_player()->set_temp("fish_quest/fish",1);
      call_out("recover",30,this_player());
     return 1;
     }
  else 
      this_player()->set_temp("fish_quest/fish",1);
      call_out("recover",50,this_player());
     return 1;
    }
  else  {
    write(
    "你想用什麽东西钓鱼呢?\n");
    return 1;    
        }
}
int recover(object me)
  { 
   if (!present(me)) return 1;
   write(
   "\n正当你觉的有点无聊的时候，你的浮标突然一沉，你看到钓竿的竿先\n"
   "弯成美丽的弧型，接著一阵强烈的挣扎力顺著你的钓竿传来，你赶快\n"
   "起身，不知该不该将钓竿拉起来看看?\n\n");
   tell_room(me,
      "\n正当你觉得无聊的时候，你看到"+this_player()->query( "c_name")+"突然起身，\n"
      "\n好像是中鱼了!\n\n"
      ,this_player());
               
   this_player()->set_temp("fish_quest/fish",2);
   return 1;
   }   
 int do_pull(string arg,object me)
 {
 int i,n;
 object ob;
 
 if (!arg || arg != "rod" )
 return notify_fail(
 "想拉什麽?\n" );
 if ((int)this_player()->query_temp("fish_quest/fish")==2 )  {
 if ( !(int)this_player()->query_temp("can_fish")==1) {
 write("先装饵吧...\n");
 return 1;
 }
 if (random(6)>4) {
 write(
 "\n你大力一拉钓竿: 但是什麽都没有拉起来\n\n");
 tell_room(me,
 "\n"+this_player()->query("c_name")+"大力一拉钓竿，但是什麽都没钓到..\n\n"
 ,this_player());
 return 1;
 }
    switch (n=random(10) ){
    case 0: ob = new(TMONSTER"fish1"); break; 
    case 1: ob = new(TMONSTER"fish2"); break;
    case 2: ob = new(TMONSTER"fish3"); break;
    case 3: ob = new(TMONSTER"fish4"); break;
    case 4: ob = new(TMONSTER"fish5"); break;
    case 5: ob = new(TMONSTER"fish6"); break;
    case 6: ob = new(TMONSTER"fish7"); break;
    case 7: ob = new(TMONSTER"fish8"); break;
    case 8: ob = new(TMONSTER"fish9"); break;
    case 9: ob = new(TMONSTER"fish10"); break;            
                }
 ob->move( environment(this_player()) );
         
 write(
  "\n你大力一拉钓竿: 一条大鱼顺势飞到岸上，你感到一阵中鱼的满足，但是\n"
  "鱼仍然不停的挣扎....\n");
   tell_room(me,
   "\n"+this_player()->query("c_name")+"大力一拉钓竿，结果钓到一条大鱼。\n\n"
   ,this_player());
   ob->kill_ob(this_player());
   this_player()->kill_ob(ob);
   this_player()->delete_temp("can_fish");
   return 1;
 }
 write(
 "\n耐心点，再等等吧。\n");
 return 1;
}