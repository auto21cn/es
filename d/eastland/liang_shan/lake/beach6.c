#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("湖滨");
	set_long( @C_LONG_DESCRIPTION
你来到一片平坦的沙地，柔细的黄沙使得你的身後，留下一行深深的足印，偶尔
清风吹起，湖面泛起阵阵涟漪，不禁令人有出世之想，沙地旁的草丛长满了不知名的
野花。东面有一些民家，但是这里好像没有办法走过去....
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"west" : TROOM"shallow8",
	        ]));
	set( "pre_exit_func",([
	        "west":"check_enter"
	        ]));
	reset();
}
int check_enter()
{
    if ((int)this_player()->query_skill("swimming")-random(5)<13){
    write (
    "你走入水中，突然想起你不太会游泳，连忙跑回岸上\n");
    return 1;
    }
    else return 0;
 }   