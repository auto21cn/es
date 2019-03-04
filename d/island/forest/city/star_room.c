#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("星河");
    set_long(@LONG
你身处於一片浩瀚的星河中，四周布满了一闪一闪的小星星，好像
是在对你招手似的！往下一看，只见到三块独立的大陆，中间夹了个小
小的岛屿，原来东方故事中的版图是这样的啊！待在这里的感觉是挺不
错的，只是．．该怎麽下去呢？
LONG
            );
    set("light",1);
    set("exits",(["northup":CITY"garden2"]) );
    set("exit_suppress",({"northup"}) );
    reset();
#include <replace_room.h>
}    