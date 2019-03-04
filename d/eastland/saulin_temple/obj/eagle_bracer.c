#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "eagle bracers", "银鹰功\力护腕" );
	add( "id", ({ "bracers" }) );
	set_short( "银鹰功\力护腕" );
	set_long(@C_LONG
这是鹰爪门的镇门之宝，相传它能够提升一个人的基本内功\能力。
它看起来是由某种黑色的丝绸做成的，上面绣著一只银色的鹰。
C_LONG
	);
	set( "unit", "双" );
	set( "type", "hands" );
	set( "no_sale", 1 );
	set( "armor_class", 1 );
	set( "extra_skills", (["inner-force":5]) );
        set("material","cloth");
	set( "weight", 70 );
	set( "value", ({ 1760, "silver" }) );
}
