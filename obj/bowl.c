#include <mudlib.h>
#define MIXD "/d/healer/mixd"
#define MESS_OB "/d/healer/mess"

inherit CONTAINER;

void create()
{
	::create();
	seteuid(getuid());
	set_c_open_long(
		"这是一个行医者用来研磨草药的药钵，将你要研磨的药材放进药钵，然後\n"
		"用 mix 指令即可。\n" );
#include <compress_obj.h>
	set_name( "herb bowl", "药钵" );
	add( "id", ({ "bowl" }) );
	set_short( "an herb bowl", "药钵" );

	set( "weight", 10 );
	set( "value", ({ 100, "silver" }) );
	set( "max_load", 40 );
	set( "weight_apply", 50 );
	set( "prevent_insert", 1 );
	set( "prevent_put_money", 1 );
}

void init()
{
	::init();
	add_action( "do_mix", "mix" );
}

int do_mix(string arg)
{
	object *inv, potion;
	int i;

	if( arg && !id(arg) ) return 0;
	if( !environment() || environment()!=this_player() ) return 0;
	inv = all_inventory();
	if( !sizeof(inv) ) return notify_fail( can_read_chinese()?
		"你的药钵里什麽也没有....。\n": "Your herb bowl contains nothing.\n" );
	potion=MIXD->mix(this_object());
	for(i=0; i<sizeof(inv); i++)
		inv[i]->remove();
	if( potion ) {
		potion->move(this_object());
		write( 
			"你将药钵里的药材混合磨碎，配成" + potion->query("c_name") + "。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "将药钵里的药材混合磨碎。\n" ,
			this_player() );
		return 1;
	} else {
		potion = new(MESS_OB);
		potion->move(this_object());
		write( 
			"你将药钵里的药材混合磨碎......结果变成一团烂泥。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "将药钵里的药材混合磨碎。\n",
			this_player() );
		return 1;
	}
}
