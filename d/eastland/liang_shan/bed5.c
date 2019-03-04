#include <takeda.h>

inherit ROOM;

void create()
{
	object chin;
	::create();
	set_short( "军官休息室" );
	set_long(
	"这里是梁山泊典型的军官休息室，隐藏在四棵巨大的松树後面，\n"
	"由窗内看去，则是一片水洗般的青翠，触目皆是绿意盎然的树木，有\n"
	"如一个大盆景摆\在你面前，空气中有著高山的冷冽，但却使人倍感舒\n"
	"畅。\n"
	);
	set( "light",1 );
        set( "exits", ([
                "south"  : TROOM"yard1",    
        ]) );
        chin = new(TMONSTER"chin");
        chin->move(this_object());

        reset();
}
int clean_up() { return 0; }
