#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

#define SPOILED_TIME 500

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
        
        seteuid(getuid());
	set_name("lu wei","龙门卤味");
	add( "id" , ({ "lu","wei" }) );
   set_short("龙门卤味");
   set_long(@LONG
龙门客栈特制什锦卤味，专为您下酒用的小菜。
LONG
	);
   	set("unit","盘");
   	set("weight", 10);
   	set("value",({ 150, "silver" }) );
	call_out("be_spoiled", SPOILED_TIME );
	set("spoiled",0);
}

int eat_food(string arg)
{
        
	if( !arg ||( arg != "liu wei" && arg !="lu" && arg!= "wei") ) return 0;
	if( query("spoiled") )
	 {
		write(@LONG
		
哇!酸掉了～～～来不急了你已经吞下去了！你肚子怪怪的，可能生病了。

LONG
     );	
        SICK->apply_effect(this_player(),5,10,5);    
     	tell_room( environment(this_player()),this_player()->query("c_name")+"吃了一口卤味，脸色怪怪的，可能是卤味坏了...\n", this_player());
		}
	        else {
		write( "果然是名不虚传的卤味，要是能喝些酒就更好了...:)\n" );
		tell_room( environment(this_player()), 
		this_player()->query("c_name")+"张大了口，三两下就把卤味吃完了。\n" , this_player());
		this_player()->receive_healing( 20+random(20) );
	}
	remove();
	return 1;
}

void be_spoiled()
{
	object owner;
	owner = environment(this_object());
	set ("value", ({ 1, "silver" }));
	set_short("龙门卤味(发酸)");
	set_long(@LONG
龙门客栈特制什锦卤味，专为您下酒用的小菜。(已经酸了，不知道能不能吃)	
LONG
      );
	set("spoiled",1);
	tell_object( owner,"好像有股酸味，是你的袜子传出来的吗?\n" );
}



