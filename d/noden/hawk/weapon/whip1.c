#include <mudlib.h>
#include <daemons.h>
#include <explore.h>

inherit WEAPON;

string C_NAME=("寂然长鞭");
void create()
{
        set_name( "Silent Whip",C_NAME );
        add( "id",({ "whip","silent whip"}) );
        set_short( C_NAME );
        set_long(@LONG
这是长老多年前在东方游历时无意间发现到的鞭子，看起来并不起眼
不过好像隐藏了一股神秘的力量，不知道谁能将这股力量发挥出来
LONG
                );
        set( "unit","条" );
        set( "type","whip" );
        set( "weapon_class",35 );
	set( "min_damage",17 );
	set ("max_damage",30 );
        set( "weight",90 );
        set( "value",({ 2300,"silver" }) );
        set( "wield_func","wi_func");
        set( "unwield_func","unwi_func");
}

void wi_func()
{
        int explore,allexp,power;
        explore = (int)this_player()->query_explore_points();
	allexp = (int)EXPLORE_D->query_total_explore();
	power = explore/allexp; // from 0% -- 100%
        set("min_damage",15 + power*10);
        set("max_damage",30 + power*10);
}

void unwi_func()
{
	set( "min_damage",15);
	set("max_damage", 30);
}

