#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "upstair of Chung Yi Hall", "忠义厅楼上" );
	set_long(
	"这是一间小小的房间，布置的很像灵堂的样子，一张香案摆\在正中，供的\n"
	"正是前代首领\托塔天王晁盖\，上面插了几只香烛，正静静的燃烧，香灰轻轻\n"
	"的落下，令人顿悟世事之无常。\n"
	);
        set( "exits", ([
                "down" : TROOM"hall"
        
        ]) );
        set( "objects",([
                "bandit":TMONSTER"small_bandit",
                "wizard":TMONSTER"wizard"
        ]) );        
        reset();
}
int clean_up() { return 0; }