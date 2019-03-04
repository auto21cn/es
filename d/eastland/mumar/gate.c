#include <mumar.h>
inherit ROOM;
 
int daoist = 1;
void create()
{
        ::create();
        set_short("牧马关南城门");
        set_long( @C_LONG_DESCRIPTION
你现在来到一座雄伟的关门口，城门上刻著三个雄伟的大字「牧马关」。这里
是东方大国防守北方的重要据点，因此派驻了重兵防守，所有来自关外的旅客都要
在这里接受盘查才能通过。城门口两尊巨大的武神雕像威风凛凛地守护著这座大城
。城门外的荒野中埋著不少古时候战死的枯骨，据说在晚上常常有人听到杀伐声与
战鼓声。
C_LONG_DESCRIPTION
        );
 
        set_outside( "eastland" );
        set( "exits", ([
                "north" : MUMAR"road1",
                "south" : "/d/eastland/12,1.east" ]) );
set( "search_desc", ([ "here" : "@@search_here" ]) );
        reset();
}
string search_here()
{
        object obj;
        if( !daoist || present("daoist", this_object()) ) return
                "你几乎把这儿的地给翻过来了，但没有发现任何东西。\n";
        obj = new( MOB"daoist" );
        obj->move( this_object() );
        daoist = 0;
        return "你在四周的草丛中找著找著，忽然被一只脚绊了一跤...\n"; }
