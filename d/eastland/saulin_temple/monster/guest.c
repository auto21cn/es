#include "saulin_monka.c"

void create()
{
	object ob1;
	::create();
	set_level(5);
	set_name( "temple guest", "进香客" );
	add( "id", ({ "guest" }) );
	set_short( "进香客" );
	set_long(@C_LONG
他是一个虔诚的佛教徒，怀抱非常快乐的心情来少林寺进香。
他长的很胖，提著一个大篮子，但笑咪咪的似乎一点都不累...
C_LONG
   	        );
	set( "max_hp", 145 );
	set( "hit_points",145 );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 500 );
	set( "wealth/silver", 10 );
//	set( "speed", 50);
//	set( "forgetful", 1);
//	set( "moving", 1);
	seteuid( getuid() );
	set( "wimpy", 70);
	set_perm_stat("strength",10);
	set_perm_stat("dexterity",10);
	set_perm_stat("piety",10);
	set_natural_weapon( 8, 4, 9 );
	set_natural_armor( 25, 10 );
	set_skill("dodge",50);  
	set_c_verbs( ({ "%s提起篮子，重重的向%s敲了下去",
			"%s大叫一声，用拳头向%s打下",  
			"%s一个闪身跑向前来，撞向%s", 
		}) );
	set_c_limbs(({ "光亮的秃头", "肥肥的身体", "油油的巨手", "粗粗的肥腿"}));
	ob1 = new( SAULIN_OBJ"basket" );
	ob1->move(this_object());
}
/*

int catch_huntee( object who )
{
    tell_room( environment(this_object()), 
      "进香客大叫一声: 又是 "+who->query("c_name")+" 这强盗来了，快逃命喽 !\n"
      ,  ({ this_object(), who }) );
    tell_object( who, 
      "进香客大叫一声: 又是你这个杀人不眨眼的强盗，快逃命喽 !\n" 
    );
    return 1;
}
*/
