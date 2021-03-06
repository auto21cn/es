#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("The vault door","库房大门");
  set_long(@Long
Long
,@CLong
这里是牧马关武器库的大门，墙上贴了一堆『生人勿近』、『严禁烟火』之类的
标语。这儿的地面上尽是一些凌乱的脚印，你可以想见一群士兵在紧急战备时到这来
领取装备的景像。从这儿往东可以回到教场上，西边就是武器库。
CLong
);
set_outside("eastland");
set( "pre_exit_func", ([ "west" : "check_guard" ]) );
set("exits",([
               "west": MUMAR "vault01",
               "east": MUMAR "square04"
             ]));
set("objects",([
               "guard#1": MOB "guard",
               "guard#2": MOB "guard"]));
reset();
}
 
int check_guard()
{
        if( wizardp(this_player()) || !present("guard") ) return 0;
   { if(this_player()->query_temp("army_mark") )    {
        tell_object(this_player(), can_read_chinese() ?
                    "守卫说道:长官好....。同时做出持枪敬礼的动作。\n":
                    "The guard said : Good morning, Sir!" );
	this_player()->set_explore("eastland#35");
        return 0;
          }
      else   {
        tell_object(this_player(), can_read_chinese() ?
                "库房守卫说: 那里是本关重地，你不能进去。\n" :
                "The guard says: Sorry, you can't go there.\n" );
        return 1;
             }
}
}
