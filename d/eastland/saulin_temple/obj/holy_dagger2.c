#include "../saulin_temple.h"

inherit WEAPON;

void create()
{
    set_name("Holy dagger of Tenshin","����С��");
    add("id", ({ "dagger", }) );
    set_short("����С��");
    set_long(
     	"һ�ѷ����º͹�â��С���������Ĵ�ʦΪ����ҽ��ʱ���õ���������\n"
    );
	set( "unit", "��" );
 	set( "weapon_class", 36 );
	set( "type","dagger" );
	set( "min_damage", 15 );
	set( "max_damage", 32 );
	set( "weight", 100 );
    set( "value", ({ 190, "gold" }) );
    set( "no_sale", 1 );
    set( "second", 1 );
//    set( "hit_func","holy_damage" );
    set( "special_damage", 15);
    set( "special_c_msg","����һ��ʥ�⣬������˵����ࡣ\n\n");
}

int holy_damage(object victim,int damage)
{
	object holder;
   	int my_ali,vic_ali,dam,max;
   	string c_msg;
    
   	if( !victim ) return 0;
   	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
   	my_ali =(int)holder ->query("alignment");
   	vic_ali = (int)victim->query("alignment");
   	dam = (int)query("special_damage");
   	if( my_ali < vic_ali )
      if( my_ali < 400 ) {
        tell_object(holder,"\n����С������һ��ʥ�⣬"
      	    "ȴ�˵������Լ�������ı����˺�ѡ�\n\n");
        holder->receive_special_damage("divine", random(dam));
        victim->set("last_attacker", holder );
        return 1;
      } else return 0;
   	else {
 	  max = (my_ali-vic_ali)/100;
 	  if( max < 0 ) max = 0;
 	  if( max > 20 ) max = 20;
	  if( random(40-max) > 5 ) return 0;
	  c_msg = (string)query("special_c_msg");
	  victim->receive_special_damage( "divine",dam );
	  victim->set("last_attacker", holder );
	  if( !c_msg ) return 0;
	  tell_object( holder,
		"\n���"+query("c_name")+c_msg+"\n");
	  tell_room( environment(holder), 
		holder->query("c_name") + "��"+query("c_name")+c_msg+"\n",
		holder );
	  return dam + random(max);
    }
}