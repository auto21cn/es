#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("yellow roses", "黄玫瑰");
	add ("id",({ "rose","roses"}));
	set_short("黄玫瑰");
	set_long(
		 "这是一束美丽的黄色玫瑰花，人们常常用它来表达嫉妒的心痛。\n"
		 "它的花语是：嫉妒。\n"
		 "这束花上还系著一张小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

