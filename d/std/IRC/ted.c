#include <mudlib.h>
 
inherit MONSTER;
 
void create ()
{
        ::create();
        seteuid( getuid() );
        set_level(19);
        set_name( "ted", "泰德" );
        add ("id", ({ "barman" }) );
        set_short( "Ted the barman", "店主泰德" );
        set_long(@LONG
This is Ted, the owner of Ted\'s place. He looks a bit old.
Just another typical barman.
 
LONG
        , @CLONG
泰德 -- 这间小店的店主. 他看起来有点老, 除此之外没啥特色.
 
CLONG
        );
        set( "alignment", 2500 );
        set( "gender", "male" );
        set( "race", "human" );
        set( "unit", "位" );
        set("weight", 650);
        set("exp_reward", 1 );
        set("no_attack",1);
}
 
