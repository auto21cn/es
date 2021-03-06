#include "../echobomber.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("lightning morningstar","闪电流星□");
       add("id",({"morningstar",}) );
       set_short("闪电流星□");
       set_long(
           "一把能够召唤闪电攻击敌人的黑色流星□\n"
     	);
	
	set("no_sale",1);
	set( "unit", "把" );
 	set( "weapon_class", 30 );
   set("type","chain");
	set( "min_damage", 7 );
	set( "max_damage", 30 );
	set( "weight", 210 );
	set( "value", ({ 300, "gold" }) );
	set("hit_func","morningstar_damage");
    set("special_damage",14);
    set("special_c_msg","发出一道迅雷,快速而准确的击中敌人的要害.\n\n");
}

int morningstar_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam,my_int,vic_int;
    string c_msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_kar = (int)holder->query_stat("kar");
	vic_kar =(int)victim->query_stat("kar");
	my_int = (int)holder->query_stat("int");
	vic_int =(int)victim->query_stat("int");
	if( random(my_kar*3) < vic_kar*2+5  &&  (damage_count++)<=10)
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		c_msg = (string)query("special_c_msg");
		victim->receive_special_damage( "electric",dam+my_int-(vic_int/2) );
		victim->set("last_attacker", holder );
		tell_object( holder, 
			"\n你的"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder), 
			holder->query("c_name") + "的"+query("c_name")+c_msg+"\n",
			holder );
		damage_count=0;
		return dam;
     }
	
}	
