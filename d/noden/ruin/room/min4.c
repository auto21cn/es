// min4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿祭坛");
    set_long(@C_LONG
你的前方有个一个六芒星状的黑色祭坛，六芒星的尖端各立著一根白色的
蜡□，祭坛上有著几个暗红色的符号 (alphabet) ，似乎是用血涂上去的。你
仔细一看，六芒星的中心似乎有被火烧过的痕迹。
C_LONG
    );
    set("objects", (["archbishop" : MOB"archbishop"]));
    set("exits", ([
	"north" : AREA"min5",
	"south" : AREA"min3"
	]) );
    set("pre_exit_func", ([ "north" : "exits_open" ]));
    reset();
}

int exits_open()
{
    if (present("archbishop",this_object()))
    {
	if (this_player()->query_temp("lilia_pass") >= 2)
	    return 0;
        write ("大祭司挡住你的去路并且说道：对不起，先打倒我才能向前走。\n");
        return 1;
    }
    else return 0;
}

