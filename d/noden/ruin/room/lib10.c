// lib10.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大图书馆．书库");
    set_long(@C_LONG
望著一个个堆满书本的架子井然有序地排列在这个大房间里，你知道你已经
来到了大图书馆的"心脏"书库。处在这一片书海里，你深深地感受到一个伟大文
明的力量来源，也许有些书对你有用也说不定哟！
C_LONG
    );
    set("exits", ([
	"east" : AREA"lib11",
	"west" : AREA"lib9"
	]) );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_read", "read");
}

int to_search()
{
    tell_object(this_player(), "在你面前的书架上有本红皮书是翻开的 .... ? ....\n");
    return 1;
}

int to_read(string s)
{
    if (s == "red book" || s == "红皮书")
	cat(DIARY"redbook");
    else
	tell_object(this_player(), "你想读什麽?\n");

    return 1;
}



