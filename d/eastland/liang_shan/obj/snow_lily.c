#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name( "snow_lily", "天山雪莲" );
	add( "id", ({ "lily" }) );
	set_short( "天山雪莲" );
	set_long(@C_LONG
这是一朵练武之人梦寐以求的宝物天山雪莲，服用(eat)它可以使人神完气足
，功\力恢复。
C_LONG
	);
	set( "no_sale", 1 );
	set( "unit","朵");
	set( "weight", 1 );
	set( "value", ({ 450, "gold" }) );
}

int eat_food(string arg)
{
	if( !arg || ( arg !="lily" && arg !="snow_lily")  ) 
	return notify_fail("吃什麽??"); 
	write( 
	"你吃下一朵天山雪莲，从丹田升起一股真气，游走全身...\n" );
	tell_room( environment(this_player()), 
	this_player()->query("c_cap_name")+
	"吃下一朵天山雪莲，又回复了生龙活虎的样子\n" , this_player()
		);
		this_player()->receive_healing( 3+random(2) );
	        this_player()->set("force_points",(int)this_player()->query("max_fp"));
	remove();
	return 1;
}

