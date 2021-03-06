#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("Black Axe","黑斧");
       add("id",({"axe",}) );
       set_short("黑斧");
       set_long(
           "卡尔服德,矮人皇室侍卫长用的一把魔法斧头\n"
     	);
	
	set("no_sale",1);
	set( "unit", "把" );
 	set( "weapon_class", 40 );
    	set("type","axe");
    	set("bleeding",10);
	set( "min_damage", 17 );
	set( "max_damage", 45 );
	set( "weight", 210 );
	set( "value", ({ 300, "gold" }) );
	set("hit_func","sword_damage");
    	set("special_damage",13);
    	set("special_c_msg","挥出一道闪光,并深深地切入敌人的心脏.\n\n");
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    string c_msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
        if (!holder->query("weapon_master")) return 0;
	my_kar = (int)holder->query_stat("kar");
	vic_kar =(int)victim->query_stat("kar");
	if( random(my_kar*3) < vic_kar*2+5  )
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		c_msg = (string)query("special_c_msg");
		victim->receive_damage( dam );
		victim->set("last_attacker", holder );
		tell_object( holder, 
                        sprintf("\n你的%s%s\n",query("c_name"),c_msg));
		tell_room( environment(holder), 
                        sprintf("%s的%s%s\n",holder->query("c_name"),query("c_name"),c_msg),
			holder );
		return dam;
     }
	
}	
