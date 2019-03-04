
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The protect room","矮人村落的避难所");
    set_long(@Long
Long
,@CLong
一间为了保护矮人的安全而做的避难所.但是似乎并没有使用过,但是这个地方依旧保
持著一尘不染.
CLong
    );
    set("exits",([
                "west":Deathland"/village/v54",
             ]));
    create_door("west","east",([
               "keyword":({"archdoor","door"}),
               "status":"locked",
               "c_desc":"一个圆形的拱门",
               "c_name":"拱门",
               "name":"archdoor",
               "desc":"a archdoor",
               "lock":"ECHO_VILLAGE_ARCHDOOR",
               ]) );
    ::reset();
}

void init()
{
  this_player()->set_explore( "deathland#11" );
}
