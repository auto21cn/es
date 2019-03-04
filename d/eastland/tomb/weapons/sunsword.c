#include "../almuhara.h"

inherit WEAPON;

int damage_count=0;
void create()
{
    set_name("Sun Sword", "金虹剑" );
    add("id", ({"sword","sunsword",}) );
    set_short("金虹剑");
	set_long(
           "一把金光闪闪的短剑，剑身薄且窄，但是却非常有弹性。在靠近剑锷之处铸了\n"
           "两个小\篆\  --- 『金虹』\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 30 );
        set( "type","shortblade");
	set( "min_damage", 18 );
	set( "max_damage", 35 );
	set( "second", 1);
	set( "weight", 80 );
	set( "value", ({ 210, "gold" }) );
//    set("hit_func","sword_damage");
    set("special_damage",18);
    set("special_c_msg","爆射出强烈的金黄色光芒，刺痛你的眼。\n\n");
}

int sword_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    string c_msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_kar = (int)holder->query_stat("kar");
	vic_kar =(int)victim->query_stat("kar");
	if( random(my_kar*3) < vic_kar*2+5  &&  (damage_count++)<=4)
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		c_msg = (string)query("special_c_msg");
		victim->receive_damage( dam );
		victim->set("last_attacker", holder );
		if( !c_msg ) return 0;
		tell_object( holder, 
			"\n你的"+query("c_name")+set_color(c_msg,"HIY")+"\n");
		tell_room( environment(holder), 
                        holder->query("c_name") + "的"+query("c_name")+set_color(c_msg,"HIY")+"\n",
			holder );
		damage_count=0;
		return dam;
     }
	
}	
