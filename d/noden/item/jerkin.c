#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "leather jerkin", "皮制短衣" );
	add( "id", ({ "jerkin" }) );
   set_short( "皮制短衣" );
	set_long(
		"这件皮制短衣做得相当细心，接缝处都用较粗的皮绳绑紧，你发现"
		"短衣的口袋上还用粉红色的丝线绣著「黛姆」的字样。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "leather");
	set( "armor_class", 7 );
	set( "weight", 90 );
	set( "value", ({ 25, "silver" }) );
}
