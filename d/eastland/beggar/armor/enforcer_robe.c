#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("enforcer robe","执事者之袍");
        add("id",({"robe"}) );
        set_short("执事者之袍");
	set_long(@C_LONG
这只不过是一件普普通通的袍子,上面绣有佛家梵语,你即使不是僧侣,穿上它还真
像那麽一回事。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 3 );
	set( "value", ({ 500, "silver" }) );
}
