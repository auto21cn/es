// altar.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("波塔祭坛广场");
    set_long(@C_LONG
你来到了一个安静的令人发毛的地方，地上到处画著神秘的符号，彷佛是
某种魔法的咒文。广场的中央有一个祭坛 (altar)，你发现祭坛上有一尊飘浮
在空中的神像 (statue) 散发著温暖的光芒，你不禁想走近看看。
C_LONG
    );
    set("exits", (["east" : AREA"rose4"]) );
    set("light", 1);
    set("item_desc", ([
	"altar" : @ALTAR 
一个散发著七彩光芒的祭坛，不知是用什麽做成的? 祭坛上刻著几行小字
写道：「至高无上的武神莉莉雅女王圣像，迷途羔羊诚心祷祝可得指引，愿女
王荣光常伴吾侪左右。」
ALTAR
,
	"statue" : @STATUE
这是一尊雕刻的栩栩如生的女神像，虽然她的容貌并不十分美丽，但是眉
宇之间隐隐透著一股威严。
STATUE
       ]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_pray", "pray");
    add_action("to_touch", "touch");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s == "altar")
    	if (p->query(QUESTNAME) >= 1)
    	{
	    tell_object(p, "祭坛上有个小六芒星 (hexagram mark)，你不禁想摸摸它 (touch)。\n");
	    return 1;
        }
    return notify_fail("你想找什麽?\n");
}

int to_touch(string s)
{
    object p;
    p = this_player();

    if (s == "mark" || s == "hexagram" || s == "hexagram mark")
	if (p->query(QUESTNAME) >= 1)
	{
	    tell_object(p, "六芒星上传来一阵波动冲击著你的意识，当你回过神时发现自己被传送到一个新的地方!\n");
	    p->move_player(AREA"min0", "SNEAK", "");
	    return 1;
        }

    return notify_fail("你想摸什麽?\n");
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "你跪下来向神像祈祷，祈祷些什麽好呢? ...\n");
    p->move("/d/noden/nodania/sealroom");
    return 1;
}

