#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "snake platemail", "盔甲" );
	add( "id", ({ "plate", "platemail" }) );
	set_short( "蛇盔甲" );
	set_long( @C_LONG
之所以被称为蛇甲, 乃因为这铠甲是由数千只墨绿色的小蛇制成.
这些蛇不知用甚麽金属打造的, 遍体闪著绿光, 眼睛射出暗暗的红
光, 你甚至怀疑那是活的.
C_LONG
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 30 );
	set( "defense_bonus", 3);
	set( "special_defense",
	     ([ "fire":3, "acid":5, "poison":5, "electric":-6 ]) );
	set( "weight", 400 );
	set( "no_sale", 1);
	set( "value", ({ 8100, "silver" }) );
}
