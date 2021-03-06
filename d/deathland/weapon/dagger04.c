#include "../echobomber.h"

//inherit Echo+"/magic";
inherit WEAPON;
int damage_num = 20;

void create()
{
       set_name("night shadow dagger","夜影小刀");
       add("id",({"dagger",}) );
       set_short("a night shadow dagger","夜影小刀");
	set_long("@@desc");
	
	set( "unit", "把" );
 	set( "weapon_class", 24 );
    set("type","dagger");
	set( "min_damage", 15 );
	set( "max_damage", 26 );
	set( "weight", 34 );
	set( "value", ({ 2050 , "silver" }) );
    set("hit_func","evil_damage");
    set("special_damage",7);      
    set("special_c_msg","说:让我们把敌人的生命毁灭吧,我的主人.\n\n");
}

int evil_damage(object victim,int damage)
{
    object holder;
    int my_ali,vic_ali,dam,max;
    string c_msg;
    
    if ( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;
    my_ali =(int) holder ->query("alignment");
    vic_ali= (int) victim->query("alignment");
    dam = (int) query("special_damage") ;
    if ( my_ali > vic_ali &&  my_ali > -400 ) {
      tell_object(holder,"这把邪恶的小刀发出邪恶的笑声:我只服从邪恶的人.\n\n");
      holder->receive_special_damage("evil",dam+random(15));
     // report(holder,holder);
      victim->set("last_attacker", holder );
      return 0;
      }
    else {
	if (damage_num == 0) return 0;
        if (!holder->query("weapon_master")) damage_num--;
      max= my_ali > 0 ? 0 :(my_ali<-2000 ? 20 :(-my_ali)/100  ) ; 
      if ( random(35-max) < 5 )  {
		c_msg = (string)query("special_c_msg");
		victim->receive_special_damage( "evil",dam );
		victim->set("last_attacker", holder );
		tell_object( holder,
                        sprintf("\n你的%s%s\n",query("c_name"),c_msg));
		tell_room( environment(holder), 
                        sprintf("%s的%s%s\n",holder->query("c_name"),query("c_name"),c_msg),
			holder );
        if ( vic_ali <= 0 ) 
            return dam;  
        else
            return dam+random(max/3);
	if (damage_num == 0)
		tell_object( holder,"\n夜影小刀上的黑色光泽渐渐消失了。\n");
        }
      return 0;
      }    
}
string desc()
{
if (damage_num == 0)
return ("一把神秘而且奇怪的小刀,能够很隐秘地刺入敌人的心脏而不被发觉，但是却似乎失去了原有的光泽。\n");
else 
return ("一把神秘而且奇怪的小刀,能够很隐秘地刺入敌人的心脏而不被发觉，上面有著神秘的黑色光泽。\n");
}
