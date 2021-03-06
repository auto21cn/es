#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "ghostly face", "鬼脸" );
	add( "id", ({ "face" }) );
	set_short("鬼脸" );
	set_long(
		"你看到一张鬼魅般的脸浮现在墙壁上，她对著你邪恶地笑著。\n"
	);
   set( "race", "undead" );
	set( "gender", "female" );
	set( "alignment", -300 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 30 );
	set("unbleeding",1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "tactic_func", "my_tactic" );
	set( "wealth/silver", 70 );
	set_c_verbs( ({"%s从空气中伸出一只手，抓向%s", "%s发出一阵尖锐的叫声，往%s一撞"}) );
	set_c_limbs( ({ "鼻子", "眼睛", "耳朵" }) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers() ) || random(20)>5 ) return 0;
	tell_room( environment(this_object()), 
		"鬼脸突然变大，张开她的血盆大口，发出一阵极其刺耳的尖叫声！\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "mental", 15 );
	return 1;
}

