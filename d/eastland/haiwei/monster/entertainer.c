#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "martialist", "卖艺师傅" );
	add( "id", ({ "entertainer" }) );
	set_short("卖艺师傅" );
	set_long(
		"这位卖艺师傅原来是一家镖局的镖师，因为镖局倒闭所以出来靠\n"
		"卖艺维生，他的拳脚功\夫在这一带是很有名的。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 300 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 18 );
	set_skill( "dodge", 90 );
	set( "wealth/gold", 20 );
	set_natural_weapon( 40, 20, 35 );
	set_natural_armor( 55, 25 );
	set( "natural_weapon_class2", 30 );
	set( "natural_min_damage2", 13 );
	set( "natural_max_damage2", 25 );
	set( "chat_chance", 20 );
	set( "chat_output", ({
		"卖艺师傅说道: 小弟才疏学浅，请各位看倌多多指教。\n",
		"卖艺师傅纵身一跳，跃起大约四公尺高，然後飘然落地。\n",
		"卖艺师傅打了一套「黑虎拳」，拳出如风，身形矫健。\n",
		"卖艺师傅堆起六块砖块，然後用一根手指往砖块按下，六块石砖一齐碎裂。\n"
	}) );
#include <replace_mob.h>
}
