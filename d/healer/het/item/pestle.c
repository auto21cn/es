#include <mudlib.h>
inherit WEAPON;

int damage_count=0;
void create()
{
	set_name("poison pestle","毒王药杵");
        add("id",({"mace","pestle"}) );
       	set_short("毒王药杵");
       	set_long(@LONG
这本是毒王沙无味的武器, 不知为何流落到王药师手中,
整支杵上闪烁著青绿色的磷光, 显得极为诡异。
LONG
        );
	set("no_sale",1);
	set( "unit", "把" );
 	set( "weapon_class", 36 );
        set("type","blunt");
	set( "min_damage", 13 );
	set( "max_damage", 33 );
	set( "weight", 160 );
	set( "value", ({ 350, "gold" }) );
//        set("hit_func","blunt_damage");
//        set("special_damage",15);
//        set("special_c_msg","爆出一大蓬恐怖的磷光,笼罩住敌人.\n\n");
}
/*
int blunt_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    int my_int,vic_int;
    string c_msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_kar = (int)holder->query_stat("kar");
	vic_kar =(int)victim->query_stat("kar");
	my_int = (int)holder->query_stat("int");
	vic_int =(int)victim->query_stat("int"); 
	if( random(my_kar*4) + my_int < random(vic_kar*5) + 10 + vic_int  &&
	    (damage_count++) <= 8 )
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		c_msg = (string) query("special_c_msg") + "\n";
		victim->receive_special_damage( "poison" , dam );
		victim->set("last_attacker", holder );
		tell_object( holder,
			"\n你的"+query("c_name")+c_msg);
		tell_room( environment(holder), 
			holder->query("c_cap_name") + "的" + query("c_name") + c_msg,
			holder );
		damage_count=0;
		return dam;
     }
	
}
*/
