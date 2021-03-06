#include <../hole.h>

inherit REPORT;
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "Vampire","小吸血蝙蝠" );
	add("id",({ "kill_vampire2","bat","vampire" }) );
	set_short( "小吸血蝙蝠" );
	set_long(@LONG
    一只吸血蝙蝠正倒挂在岩壁上，一双泛红的眼睛紧盯著你不放
，似乎正盘算著要将你当作晚餐。你最好在它攻击你之前赶快离开这里。
LONG
		);
	set( "alignment",-500 );
	set_perm_stat( "dex",15 );
	set_perm_stat( "kar",25 );
	set_skill( "dodge",45 );
	set_natural_armor( 60,10 );
 	set_natural_weapon( 30,5,20 );
 	set( "killer",1 );
	set_c_limbs( ({ "头部","身体","翅膀","爪子" }) );
	set_c_verbs( ({ "%s用它长满利牙的嘴咬向%s","%s用它的利爪抓向%s","%s用它的翅膀拍向%s" }) );
	set( "tactic_func","my_tactic" );
}

int my_tactic()
{
	object victim;
	string him;

	if( random(20)>3 || !(victim=query_attacker()) ) return 0;
	else
	{
	him = victim->query( "c_name" );
	tell_object(victim,"\n吸血蝙蝠飞到你的脖子上狠狠的吸了一大口鲜血\n\n");
	tell_room(environment(this_object()),
	"吸血蝙蝠突然飞到"+him+"的脖子上狠狠地吸了一大口鲜血\n\n",victim);
	victim->receive_damage( 10 + random(15) );
	report( victim );
	return 1;
	}
}
