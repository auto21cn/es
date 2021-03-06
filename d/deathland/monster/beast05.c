#include "../echobomber.h"

inherit MONSTER;

void create()
{
    object oil;
    
	::create();
	set_level(12);
	seteuid(getuid());
	set_name( "Cold Beast", "寒兽" );
	add("id",({"beast"}));
	set_short( "Cold Beast", "寒兽" );
	set_long(
		"cold beast.\n",
		"一只奇怪的生物, 只要靠近它就会感觉寒冷.\n"
	);
	set("max_hp",350);
	set("hit_points",350);
	set( "alignment",-100 );
	set_perm_stat( "dex", 8  );
	set_perm_stat( "str", 12 );
	set_perm_stat( "kar", 16 );
	set_skill("dodge",70);
	set_natural_armor(50,20);
 	set_natural_weapon(22,12,30);
    set( "special_defense", (  [ "cold":90 , "fire": -30 ]  ) );
    oil=new(Object"/cold_oil");
    oil->move(this_object());
}

void cold_damage()
{
     if ( find_call_out("cold")==-1 )
       call_out("cold",0,0); 
}

void init()
{
     ::init();
     cold_damage();
}

void cold(int call_again)
{
     object npc,room,*player;
     int i;
     
     npc=this_object();
     room=environment(npc);
     player=all_inventory(room);
     call_again++;
     for(i=0;i<sizeof(player);i++) 
       if ( living(player[i]) && player[i]!=npc ) {
         tell_object(player[i],
         "从寒兽的身上发出的冷空气冻伤了你.\n"
         ); 
         player[i]->receive_special_damage("cold",10+random(20));
         call_again=0;
         }
     if ( call_again<3 ) call_out( "cold", 2 , call_again );    
}
