#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "石板路" );
	set_long(
	"这是点将台後的一条石板路，比起天王大道来不算大，说小却又能供五马\n"
	"并行，路的尽头，赫然是座辉宏华丽的大院，千椽万瓦，灯火辉煌。门口(gate)\n"
	"蹲踞著两只狰狞的石狮子，你不知道是不是该进去(enter)。\n"
	);
	set( "light",1 );
        set_outside( "eastland" );
        set( "no_monster",1);
        set( "exits", ([
                "south"  : TROOM"plate",    
        ]) );
        reset();
}
void init()
{
add_action("do_pass","enter");
}
int do_pass(string arg)
{
 if ( !arg || arg != "gate")
    return notify_fail(
    "你想要进去那儿?\n");
    write (
    "你双手推开门板，大步走了进去...\n");
    tell_room(this_object(),
    "你看到"+this_player()->query("c_cap_name")+ "大步走进了门内。\n" ,
    this_player());
    this_player()->move_player(TROOM"chuyi_hall","SNEAK");
return 1;
}
int clean_up() { return 0; }    