#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "ghost of Harold", "哈洛德的鬼魂" );
	add( "id", ({ "ghost", "harold" }) );
	set_short( "哈洛德的鬼魂" );
	set_long(
		"你看到一个表情忧愁的中年绅士，他看起来正在沈思。\n"
	);
   set( "race", "undead" );
	set( "gender", "male" );
	set( "alignment", 10 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 50 );
	set( "natural_armor_class", 30 );
	set( "natural_weapon_class1", 12 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 11 );
	set( "unbleeding",1);
	set( "tactic_func", "my_tactic" );
	set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "alt_corpse", "/d/noden/house/obj/cellar_key" );
	set_c_verbs( ({"%s伸手抓向%s"}) );
	set( "inquiry", ([
		"key" : "钥匙？什麽钥匙 .... 我没有钥匙 .... " 
	]) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers() ) || random(20)>5 ) return 0;
	tell_room( environment(this_object()), 
		"鬼魂的影子变得模糊，然後你觉得有人在你的耳边吹气....\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "mental", 20 );
	return 1;
}

void die()
{
	tell_room( environment(this_object()), 
		query("c_cap_name") + "的影子化成一股白烟，消失了 .... 你听到某个东西掉在地板上。\n",
		this_object() );
	::die(1);
}

