
#include <zeus.h>

inherit ROOM;
int dog;
void create()
{
  ::create();
  set_short("竹桥");
  set_long(@CLong
这是一座看起来简单却很坚固的竹桥 (bridge)，好像可以承受极大的重量
．两旁的水以非常快的速度流著，桥下还张著一个网子(net)，可是不知道这有
什麽用，地上的铁轨到了这里似乎已经到达终点．桥边有一条小路通往桥下．　
CLong
);
set("exits",([
             "south":ZROOM"/m_enter",
             "north":ZROOM"/mine01",
             "down":ZROOM"/port",
             ]));
set("item_desc",(["net":
"一张破破的网子，似乎不是用来抓鱼的，也\许\你可以找人问问他的作用是什麽．\n",
"bridge":@BB
一座简简单单的竹桥，走在上面摇摇晃晃的，感觉满舒服的．你想摇摇(shake)
它试试看坚不坚固吗?
BB
]));
  reset();
 }
 void reset()
 {
    ::reset();
    dog=1;
 }
void init()
{
   add_action("do_shake","shake");
}
int do_shake(string str)
{  object ob;
   if(!str||str!="bridge"){
   write("你想干什麽???\n");
    return 1;
   }
   
   if(dog){
   ob=new(ZMOB"/dog");
   ob->move(this_object());
   dog=0;
   return 1;
   }
   else {
   write("这桥早就被摇得破破烂烂的了！再摇下去就断了！\n");
   return 1;
   }
   
}   
   