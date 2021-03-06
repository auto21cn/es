// /d/abyss/hell/monster/lord_chinguan.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name("Lord Chin-Guan", "秦广王");
	add( "id", ({ "lord", "chin-guan", "chin", "guan" }) );
	set_short("Lord Chin-Guan", "秦广王");
	set_long(
		"You see the Lord Chin-Guan.\n",
		"秦广王是掌管森罗殿的冥王，他的职责是审判世人在阳间的所作所为是\n"
		"否该入地狱受罚，他的两眼能看透人心，在秦广王面前没有任何人能说\n"
		"谎骗他。\n"
	);
	set( "gender", "male" );
	set( "no_attack", 1 );
}
