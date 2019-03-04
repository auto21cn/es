#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "武士城堡大门" );
   set_long(@ANGEL
这里是武士城堡的入口，你可以看见旁边高耸的城墙及全副武装的卫兵，为了防御
敌人的入侵这里时时刻刻都配置著强大了兵力，向北可以进入武士城堡，南边则是一个
哨站    
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
	set("objects",([
	    "yark":MOB"yark",
	    "guard#1":MOB"guard2",
	    "guard#2":MOB"guard2"
	      ]) );
        set( "exits", ([
                "north"  :MR"cac01",
                "south" :MR"station",
                ]) );
         reset();                     
}

