#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("pansy", "三色堇");
	add ("id",({ "pansy"}));
	set_short("三色堇");
	set_long(
		 "这是一束美丽的三色堇，人们常常用它来表达思念之意。\n"
		 "它的花语是：思念。\n"
		 "这束花上还系著一张小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

