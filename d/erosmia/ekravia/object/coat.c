#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black swallaw-tail coat", "黑色燕尾服" );
	add( "id", ({ "coat" }) );
	set_short( "黑色燕尾服" );
	set_long( @LONG
这是件相当帅气的礼服, 男士们在正式的场合大多穿著这样的衣服。
以礼服来说, 这件衣服的料子还不错, 剪裁也相当用心。
LONG
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 18 );
	set( "weight", 30 );
	set( "value", ({ 500, "silver" }) );
}
