#include <mudlib.h>

inherit ARMOR;

void create()
{
#include <compress_obj.h>
	set_name( "glasses", "墨镜" );
	set_short( "墨镜" );
	set_long(
		"这是一付很拉风的墨镜，可以挡住强光的照射。\n"
	);
	set( "unit", "付" );
        set("material","element");
	set( "type", "head" );
	set( "weight", 20 );
	set( "armor_class", 2 );
	set( "value", ({ 40, "silver" }) );
        set( "extra_look", "$N戴著一付很拉风的墨镜，显得十分帅气。\n" );

}
