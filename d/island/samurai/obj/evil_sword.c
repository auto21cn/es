/*
 * 原作者：Mercury (1995.1)
 * 修改者：Ishige (1995.12)
 */
#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("Evil Sword","妖刀村雨");
	add("id",({"sword"}) );
	set_short("Evil Sword","妖刀村雨");
	set_long(@AAA
这是一把传说中的「妖刀村雨」，刀身上泛出一股诡异的光芒。据说
此刀隐含有无比强大的神秘力量，但是想要使用这种力量必须以自己
的生命作为交换。
AAA
);
	set("unit","把");
	set("weapon_class",45);
	set("type","longblade");
	set("min_damage",25);
	set("max_damage",47);
	set("weight",170);
	set("value",({130,"gold"}));
	set("hit_func","sword_damage");
	set("special_c_msg","开始吸取持刀者的生命力！！ \n"
        "妖刀村雨刀身上发出一道强烈的光芒，射入敌人的心脏！！！\n");
}

int sword_damage(object victim,int damage)
{
	object holder;
	int my_kar,dam;
	string c_msg,msg; 
	
	/*由於会损耗持刀者自己的 HP，因此有较高的 damage. */
	dam = 30;

	if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	
	my_kar = (int)holder->query_stat("kar");
	if( random(30) > my_kar/3 )
		return 0;
	else {
		c_msg = (string)query("special_c_msg");
		holder->receive_damage( 5+random(10) );
		victim->receive_special_damage( "none",dam );
		victim->set("last_attacker", holder );
		tell_object( holder,"\n你的"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder),
		holder->query("c_name") + "的"+query("c_name")+c_msg+"\n",
		holder );
		return dam;
	}
}