#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "drink_water", "drink" );
}

void create()
{
        set_name( "Pool of Radiance", "光芒之池" );
        add( "id", ({ "pool" }) );
        set_short( "光芒之池" );
        set_long(@C_LONG
这是一个散发出奇特光芒的小池，看起来十分诡异，但是传说它的池水有
起死回生的功\效，喝(drink)喝看吗？
C_LONG
		);
   		set("unit","池");
   		set("weight", 100000);
}

int drink_water(string arg)
{
	if( !arg || arg != "water") return 0;
	write(
		"你喝了一口池水，突然一阵疲累，好像全身的力量都被吸乾了...:)\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"从池中喝了一口水，然後脸色马上转成苍白...\n"
		, this_player()
	);
		this_player()->set_heart_beat(1);
                this_player()->set("hit_points", 1);
	return 1;
}
