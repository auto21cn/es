// gate.c: an object for spell 'ASTRAL-GATE'////#pragma save_binary
#include <mudlib.h>

inherit OBJECT;

void	set_destination(object dest);
object	gate_destination;

void	create()
{
	set_name("astral gate", "星界之门");
	add( "id", ({ "gate" }) );
	set_short( "星界之门" );
	set( "long", "@@query_long");
	set( "weight", 0);
	set( "unit", "道");
	set( "prevent_insert", 1);
	set( "prevent_drop", 1);
	set( "prevent_get", 1);
}

void	init()
{
   add_action( "enter_gate", "enter");
}

void	set_destination( object dest )
{
	gate_destination = dest;
}

int		enter_gate( string s)
{
	if (!s)	return notify_fail( "你想进入什麽东西?\n" );
	if ( (!present(s)) || (present(s) != this_object()) )	return 0;
// prevent bugs
	if ( (!gate_destination) || (gate_destination->query("no_teleport")) ) 
	{
		tell_room( environment( this_object()), 
			"在你接触光门时, 门忽然剧烈地摇动起来, 发出强烈的闪光而消失。\n"
		);
		::remove();
		return 0;
	}
	
	this_player()->move_player( gate_destination,
		this_player()->query("c_name") + "走进了星界之门" );
	return 1;
}

int		remove()
{
	tell_room( environment( this_object() ), 
		"光门渐渐地转为黯淡, 消失了。\n"
	);
	return ::remove();
}

string	query_long()
{
	string s;
	
	s= "光门有点摇摇晃晃的, 看不到门的彼方。\n";
	if (gate_destination) {
		s = "你透过光门, 看到门的另一侧:\n";
		s = s + gate_destination->query("long");
		return s;
	}
	else return s;
}
