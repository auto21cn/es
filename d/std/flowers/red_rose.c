#include <flowers.h>
inherit Flowers;
void create()
{
	::create();
	set_name("red roses", "红玫瑰");
        add ("id",({ "rose","roses"}));
	set_short("红玫瑰");
	set_long(
		 "这是一束美丽的红色玫瑰，人们常常用它来表达爱情。\n"
		 "它的花语是：热爱。\n"
		 "这束花上还系著一张小卡片。\n");
	set("unit", "束");
        set ("value", ({ 10, "silver" }) );
}

