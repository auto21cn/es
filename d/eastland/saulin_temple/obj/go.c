#include "../saulin_temple.h"

inherit WEAPON;

int damage_count=0;
void create()
{
    set_name("ru-li go","������");
    add("id",({"sword","go",}) );
    set_short("������");
	set_long(@C_LONG
����Ϊ����֮һ��, ��������������������,��ν֮�����١�... 
��������������ʹ�õķ���, �������������������æ��
C_LONG
	);
	set( "unit", "��" );
 	set( "weapon_class", 35 );
	set( "type", "longblade");
	set( "min_damage", 18 );
	set( "max_damage", 30 );
	set( "weight", 175 );
	set( "no_sale", 1);
	set( "value", ({ 100, "gold" }) );
//    set( "hit_func","sword_damage");
    set( "special_damage", 20);
    set( "special_c_msg",
	"\n�򱱷�һ��, ���ӷ���������Х��... ��ʱ��ػ谵������... \n"
	"�����������ǿ�Ĳ������������ٻ�����, ������ĵ���!!! \n\n"
	);
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
	if( random(my_kar*2)<vic_kar || (damage_count++)<11 )
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		c_msg = (string)query("special_c_msg");
		victim->receive_damage( dam );
		victim->set("last_attacker", holder );
		if( !c_msg ) return 0;
		tell_object( holder, 
			"\n���"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder), 
			holder->query("c_name") + "��"+query("c_name")+c_msg+"\n",
			holder );
		damage_count=0;
		return dam;
    }
}	