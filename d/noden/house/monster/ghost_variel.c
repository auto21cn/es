#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "Ghost of Variel", "薇莉儿的鬼魂" );
	add( "id", ({ "ghost", "variel" }) );
	set_short( "薇莉儿的鬼魂" );
	set_long(
		"你看见一个悲伤的女人，她看起来十分美丽，但是你从她淡淡的身影可\n"
		"以断定她只是个鬼魂。\n"
	);
   set( "race", "undead" );
	set( "gender", "female" );
	set( "alignment", 500 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 30 );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "tactic_func", "my_tactic" );
	set( "unbleeding",1);
	set( "alt_corpse", "NONE" );
	set_c_verbs( ({"%s伸手抓向%s"}) );
	set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "chat_chance", 10 );
	set( "chat_output", ({
		"薇莉儿的鬼魂说道: 请埋葬(bury)我可怜的孩子 ....\n",
		"薇莉儿的鬼魂悲伤地叹气。\n",
		"薇莉儿的鬼魂说道: 我的孩子(son)是无辜的 ....\n"
	}) );
	set( "inquiry", ([
		"son" :"我的孩子不是恶魔(devil)，我爱我的孩子 ...." ,
		"bury" : "请把我的孩子从恶魔手中救出来，埋在墓园里，和我及我丈夫一起 ...." ,
		"devil" : "恶魔几乎是无法消灭的，你必须找到那张符咒(incantation) ...." ,
		"incantation" :"就是从前那个东方人给我丈夫的驱魔咒 ...." 
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
		victim[i]->receive_special_damage( "mental", 15 );
	return 1;
}

void die()
{
	tell_room( environment(this_object()), 
		query("c_cap_name") + "的影子化成一股白烟，消失了 ....\n",
		this_object() );
	::die(1);
}

// This function is called when the quest finished
void quest_finished(object player)
{
	tell_room( environment(player), 
		"薇莉儿的鬼魂微笑著说道: 非常谢谢你，"+player->query("c_cap_name")+"。\n",
		this_object() );
	die();
}
