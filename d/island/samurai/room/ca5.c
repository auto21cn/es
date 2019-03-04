#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "城墙" );
   set_long(
@ANGEL
你走在一个武士城堡的外围城墙上，这个城墙很高，当你试著从城墙边往
下看时，你会有一股心里毛毛的感觉，因为城墙实在太高了，城墙上还有数位
看守的武士，他们对你的到来似乎有点不满.
ANGEL
);
	set( "objects",([
	"guard#1":MOB"guard3",
	"guard#2":MOB"guard3"]));
	set("light",1);
	set_outside("eastland");
        set( "exits", ([
    "north" :MR"ca4",
    "south" :MR"ca6",
                ]) );
         reset();                     
}

