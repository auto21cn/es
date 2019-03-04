#include "../../story.h"
inherit WMOB"helpmob";
void create ()
{
	::create();
	set_level(16);
	set_name( "god beast", "夔兽" );
	add ("id", ({"beast"}) );
	set_short( "夔兽");
	set_long(@CLONG
夔兽长得像牛却没有角，苍灰色的身子，足只有一只，能够自由地进出海水之中。
它的眼睛能发出一闪闪像日月般的光辉，同时大张著口吼叫，声音好像打雷，它的
肚皮也会发出声响，能激厉同伙的士气。
CLONG
	);
	set("race","神兽");
	set_perm_stat("str", 25 );
        set_perm_stat("int", 28 );
	set( "alignment", 100 );
        set( "max_fp",200);
	set( "max_hp",900);
	set( "hit_points",900);
	set_natural_weapon( 30, 15, 23 );
	set_natural_armor( 53, 35 );
        set_skill("dodge",70);
        set_skill("unarmed-parry",70);
        set_skill("unarmed",70);
        set("couple",1);
        set("special_defense",(["all":40,"none":25]));
        set( "tactic_func", "my_attack" );
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}
void heal_all()
{
   int i,max;
   object *atk;
   atk=all_inventory(environment());
   max=sizeof(atk);
   for ( i=0;i<max;i++ )
     if ( atk[i]->query("help_war") ) atk[i]->receive_healing(35);
}               
int my_attack()
{
    object *couple,victim;
    int i,max;
    if ( !victim=query_attacker() ) return 0;                     
    couple = filter_array( all_inventory(environment(this_object())),
         "can_help", this_object() );
    max=sizeof(couple);
    for( i=0; i<max; i++ ) 
       couple[i]->kill_ob(victim);
    if ( random(5)>1 ) return 0;
    heal_all();
    tell_room(environment(),"夔兽拍打自己的肚皮发出咚咚咚的声响，激厉己方的士气！\n");
    return 1;
}