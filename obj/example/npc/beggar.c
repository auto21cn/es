// googol.c
// A patrolling and talking monster.
// He uses the say command so that he may speak in different languages.
// If you just want a monster to speak in Common, you can use the
// chat_chance property instead, which is easier and faster.
// Comments on monster properties are found in /obj/foobird.c
// Mobydick, 10-2-92.

#include <mudlib.h>

inherit MONSTER;

void create ()
{
	object bo;

	::create();
	set_level(19);
	set_name( "hong chigon", "洪七公" );
	add ("id", ({ "hong", "chigon", "beggar chief", "beggar", "chief" }) );
	set_short( "Hong Chigon the Beggar Chief", "九指神丐洪七公" );
	set_long(
		"Hong Chigon is the legendary beggar and he is the leader of the\n"
		"beggar's gang. He likes eating very much and is always looking for\n"
		"delicious foods.\n",
		"洪七公是传说中丐帮的老帮主，他非常喜欢吃，常常跑遍天下寻找各种珍\n"
		"奇美味。\n"
	);
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );

	set ("max_hp", 500);
	set ("hit_points", 500);

	set ("wealth", ([ "gold":300 ]) );

	set ("gender", "male");

	set ("natural_armor_class", 40);
	set ("natural_weapon_class1", 40);
	set ("natural_min_damage1", 25);
	set ("natural_max_damage1", 60);

	set ("chat_chance", 40);
	set ("att_chat_output", ({
		"Chigon cackles and says: Let's me teach you how to fight, Kids!\n",
		"洪七公哈哈大笑: 小兔崽子，让老叫化子指点你几手。\n",
		"Chigon turns around while striking you with palms.\n",
		"洪七公转身背对著你，手掌向後推出，说道: 这招叫「神龙摆尾」。\n",
		"Chigon mumbers: Hmmm... should I beat you so easily?\n",
		"洪七公沉吟道: 唔... 要用哪一招才不会失手打死你... ？\n",
		"Chigon smiles and says: Good, it would be a match if you fight with my children.\n",
		"洪七公说道: 不错，你再练几年就可以和我徒儿郭靖过招玩玩。\n",
		"Chigon get a chicken from his bag, chews a piece of it and put the chicken in bag again.\n",
		"洪七公从容不迫地从怀里取出一根鸡腿，咬了一口又放回怀中。\n"
	}) );

	bo = new("/obj/example/weapon/bo");
	bo->move(this_object());
	wield_weapon(bo);
}

