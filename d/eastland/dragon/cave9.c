// File: /u/l/layuter/elf/elf1.c
// Generated by Roommaker Thu Nov 11 14:52:14 1993

#include "../layuter.h"

inherit ROOM;
int layuteraa;

void create()
{
	::create();
	set_short("龙穴");
	set_long( @C_LONG_DESCRIPTION
此处是一个火山熔洞，四周都是奇怪的火红色岩石，并且有时有一些奇怪的岩石结晶
，当其被火光映照之时，会反射出绚丽的光线，此处有一个奇怪的巨石，其旁有许\多摩擦
的痕迹，地上并有许\多石屑，在此处的东方有一个用稻草覆盖\的窝，其旁并有许\多的血迹
，也许\是某一猛兽的巢穴。
C_LONG_DESCRIPTION
	);
set("item_desc",([
    "stone":"这块石头看起来十分奇怪。\n"]));

	set("objects",([
	    "Chilin": Ldmonster"chilin"]));
	set( "light", 0 );
	set( "exits", ([
	    "east" : Lcave"cave8"
	]) );
	reset();
}

void init()
{
 add_action("do_move","move");
 }
 
int do_move(string arg)
{
  if (!arg||arg!="stone") return 0;
  if ((int) this_player()->query_stat("str")<15) 
  {
   write("你的力量不够搬不动石头，回去练一练力量再来吧!!\n");
   }
  else if (layuteraa==1)
   {
   tell_room(this_object(),"石头缓缓移动，遮住往下的楼梯\n");
   layuteraa=0;
   set("exits",([
       "east":Lcave"cave8"]));
       }  
  else{
   layuteraa=1;
   tell_room(this_object(),"石头缓缓移动，露出一个往下的楼梯\n");
   add("exits",([
       "down":Lcave"cave10"]));           
        this_player()->set_explore("eastland#1");
  }     
  return 1;
}


void reset()
{
   ::reset();
   set("exit",([
       "east":Lcave"cave8"
       ]));   
   layuteraa=0;    
}


