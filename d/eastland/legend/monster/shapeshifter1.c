#include "../legend.h"

inherit MONSTER;

void create()
{

	::create();
	set_level(16);
	set_name( "crystal shapeshifter", "水晶变形虫" );
	add( "id",({ "shapeshifter" }) );
        set_short( "水晶变形虫" );
	set_long(@LONG
一只通体透明的变形虫，形状就像面团一般，缓缓的在你面前蠕动著。变形虫一口一
口吞食著树薇，细碎的光点慢慢流进体内，看来十分有趣。 
LONG	);
	set_skill( "dodge", 100);
	set( "alignment", 1000 );
	set( "max_hp",300);
	set( "hit_points", 300);
	set( "special_defense",([ "all":80, "none":30 ]));
	set( "max_fp",1000);
	set( "race", "shapeshifter" );
	set( "gender", "female" );
	set_natural_armor( 10, 200 );
	set_natural_weapon( 80, 15, 20 );
        equip_armor( LARMOR"kernel1" );
}
