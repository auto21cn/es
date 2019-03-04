
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big cave of Drawf mine ","矮人矿坑的大洞穴");
  set_long(@Long
Long
,@CLong
一个很黑很暗的大洞穴,曾经是个含量丰富的矿坑.在这里的地上充满了黑色的
泡沫,似乎一些极可怕的生物栖息在这里
CLong
);
set("exits",([
             "west":Mine"/d05",
             "east":Mine"/d03",
             ]));
set("objects",([
    "shadow#1":Monster"/evilshadow",
    "shadow#2":Monster"/evilshadow",
    "shadow#3":Monster"/evilshadow",
    "evilfighter":Monster"/evilfighter",
    ]) );
set("pre_exit_func",([
    "west":"to_west"
    ]) );
reset();
}

int to_west()
{
     if (!present("evilfighter")) {
       return 0;
       }
     else {
       write("邪恶的幻影战士挡住你的去路而不让你过去.\n");
       return 1;
       }  
}

