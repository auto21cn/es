#include <mudlib.h>
//int box_moved;
inherit WEAPON;

void create()
{
//	seteuid(getuid());
	set_name( "short spear", "短矛" );
	//set_name( "短矛",({"short spear","spear"]) );
	add( "id", ({ "spear" }) );
	set( "id", ({ "spear" }) );
   set_short( "短矛" );
	set_long("一把很短的矛，它的尖端是用石头磨尖而成的。\n"	);
	set( "unit", "把" );
	set( "type", "polearm" );
	set( "weapon_class", 6 );
	set( "min_damage", 3 );
	set( "max_damage", 8 );
	set( "weight", 40 );
	set( "value", ({ 20, "silver" }) );
}
/* bmp 测试用
void init()
{
        add_action( "do_move", "move" );
        add_action( "do_kill", "kill" );
}
int do_move(string arg)
{
        if( !arg || arg!= "矛尖" ) return 0;
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
        this_player()->set("wealth/gold",100);
        return 1;
}
*/
