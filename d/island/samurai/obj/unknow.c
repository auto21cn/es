#include <mudlib.h>

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("unknow sword","无名剑");
       add("id",({"sword"}) );
       set_short("无名剑");
	   set_long(@AAA
一把烂烂且不起眼的剑，据说曾是一代剑神无名的爱剑
AAA
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 45 );
    set("type","longblade");
	set( "min_damage", 25 );
	set( "max_damage", 45 );
	set( "weight", 110 );
	set( "value", ({ 501, "gold" }) );
//    set("hit_func","staff_damage");
    set("special_damage",5);
}

int staff_damage(object victim,int damage)
{
    object holder;
    int my_int,vic_int,dam,n;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_int = (int)holder->query_stat("int");
	vic_int =(int)victim->query_stat("int");
        if( (random(my_int*3) < vic_int*2) && ((damage_count++)<=5))
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		
		switch (n=random(4) )
{ case 0:			 
 {    
     tell_object(holder,
     "\n你使出无名剑法第一是 大漠风暴 ，剑如飞逝的流星一般射向敌人\n\n");
     tell_room(environment(holder),
      "\n"+holder->query("c_name")+"的剑如飞逝的流星一般射向敌人\n\n",
      holder);
    victim->receive_special_damage("magic",dam);
    victim->set("last_attacker",holder);
    damage_count =0;
    return dam;
 }
 case 1:   
 {
      tell_object(holder,
      "\n你使出无名剑法第二式 冰城银雪 ，剑身上泛起朵朵明亮的剑花\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"的剑身上泛起朵朵明亮的剑花刺向敌人\n\n",
      holder);
      victim->receive_special_damage("magic",dam+10);
      victim->set("last_attacker",holder);
      damage_count =0;
 return dam;
   }
 case 2:
   {
      tell_object(holder,
      "\n你使出无名剑法第三式 怒涛惊天 剑身上泛出无数剑气射向敌人 \n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"的剑身上泛出无数剑气向敌人射去\n\n",
      holder);
      victim->set("last_attacker",holder);
      victim->receive_special_damage("magic",dam+15);
      damage_count =0;
      return dam;
   }
 case 3:
   {
     
     tell_object(holder,
      "\n你使出无名剑法第四式 毁天灭地 ，你人剑合一向敌人冲去\n\n");
      tell_room(environment(holder),
      "\n"+holder->query("c_name")+"身剑合一整个人向冲敌人了过去\n\n",
      holder);
      victim->set("last_attacker",holder);
      victim->receive_special_damage("magic",dam+20);
      damage_count =0;
   return dam;
   }
  }
 }
}  
