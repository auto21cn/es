
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The road of the dwarf village","矮人村落的小路");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村庄的环庄道路上,这里有著非常和平安详的气氛,恍佛是一个世
外桃源.这里已经多年没有战争了,矮人们的童年几乎在此渡过.东边有个拱门,通向一个
避难所.
CLong
    );
    set("exits",([
                "east":Deathland"/village/vr4",
                "north":Deathland"/village/v55",
                "south":Deathland"/village/v53",
             ]));
    create_door("east","west",([
               "keyword":({"archdoor","door"}),
               "status":"locked",
               "c_desc":"一个圆形的拱门",
               "c_name":"拱门",
               "name":"archdoor",
               "desc":"a archdoor",
               "lock":"ECHO_VILLAGE_ARCHDOOR",
               ]) );
    set("objects",([
        "guard":Monster"/guard03"
        ]) );
    ::reset();
}
