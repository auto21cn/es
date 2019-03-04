#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "半空中" );
	set_long(
	"你正在半空中，不停的向下坠落，往脚下看去，无边的黑暗正如巨兽\n"
	"张开大嘴向你迎面而来，你意识到这对你来说，可能是一个悲惨的结束\n"
	);
        set( "pre_exit_func", ([
                "down" : "check_fall"
        ])) ;        
        set( "exits", ([
                "down" : TROOM"fall2"
        ]) );
}
int check_fall()
{
write(
"\n你不停的向漆黑的空间落去。\n\n");
return 0;
}
int clean_up() { return 0; }