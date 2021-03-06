#include "../dony.h"

inherit ROOM;

void create()
{
	::create();
        set_short( "east9", "阴暗房间" );
	set_long(@C_LONG
你来到了一个阴暗的房间,因为这里长久欠缺阳光的照射,所以总有股挥之不去
的发霉味道。这里没什麽摆设,空洞洞的,墙壁上只有几根快烧完的火把, 地上也没
什脚印之类的东西,毕竟这里很少人来。
C_LONG
	);
	set("light",0);
	set( "exits", ([
                      "north":DBEGGAR"east10.c",
                      "south":DBEGGAR"east8.c"
	]) );
        set("objects",([
                      "guard1":DMONSTER"jail_guard",
                      "guard2":DMONSTER"jail_guard",
                      "guard3":DMONSTER"jail_guard",
                      "guard4":DMONSTER"jail_guard",
                      "guard5":DMONSTER"jail_guard",
                      "guard6":DMONSTER"jail_guard",
                      "guard7":DMONSTER"jail_guard",
                      "guard8":DMONSTER"jail_guard",
                      "guard9":DMONSTER"jail_guard",
                     "guard10":DMONSTER"jail_guard", 
        ]) );
        set("pre_exit_func",([
                "north":"do_show"]));
     reset();
}
void init()
{ 
   add_action("do_show","show"); 
}

int do_show( string arg )
{
   if( !present("jail guard"))
      return 0;
    
   if ( !arg || arg != "password" ){
      write(@C_LONG
守卫把你拦住不让你过。
守卫说道说道:如果你有手谕拿给我看 ( show password ),那麽我就可以让你过去。
C_LONG
           );
      return 1;        
   }
   
   if ( present("password",this_player()) ){
      write(@C_LONG
守卫说道:嗯,你可以过去了,不过不要做坏事。
C_LONG
            );
      this_player()->move_player(DBEGGAR"east10");
      return 1;
   }      
}