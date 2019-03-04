#include <mudlib.h>

inherit WEAPON;
int box_moved;
void create()
{
	seteuid(getuid());
	set_name( "baselard", "短刀" );
   set_short( "短刀" );
	set_long(
		"这是一把短刃的小型短刀，刀柄用布条缠著。\n"
	);
	set( "unit", "把" );
	set( "type", "shortblade" );
	set( "weapon_class", 5 );
	set( "min_damage", 3 );
	set( "max_damage", 8 );
	set( "weight", 30 );
	set( "value", ({ 35, "silver" }) );
}
/*  bmp 测试用*/
void init()
{
        add_action( "do_move", "move" );
        add_action( "do_kill", "kill" );
}
int do_move(string arg)
{
        if( !arg || arg!= "." ) return 0;
        if( box_moved ) {
                write( "\n");
                box_moved = 0;
        } else {
                write("\n\n"
                );
                box_moved = 1;
        }
        return 1;
}
int do_kill(string arg)
{
        if( !box_moved ) return 0;
        box_moved = 0;
        this_player()->gain_experience(1000);
        return 1;
}

