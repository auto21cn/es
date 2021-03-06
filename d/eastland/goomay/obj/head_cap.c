#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "miners' cap", "矿工头盔" );
	add("id",({"cap","helmet"}) );
	set_short("矿工头盔" );
	set_long(
		"这是一顶旧旧的矿工头盔，上面有一个小小的灯泡，\n"
		 "你可以把它点亮(light)当作照明用。\n"
	);
	set( "unit", "顶" );
        set("material","element");
	set( "type", "head" );
	set( "weight", 30 );
	set( "armor_class", 2 );
	set( "value", ({ 400, "silver" }) );
        set("fuel", 1800);  // fuel is measured in seconds
}
void init()
{
        add_action("light_t", "light");
        add_action("light_t", "ignite");
        add_action("extinguish_t", "extinguish");
        add_action("extinguish_t", "unlight");
}

int light_t(string str)
{
        if(!id(str)) return 0;
        if(!query("fuel"))
                return notify_fail("你试著亮起头盔上的灯泡，但是很显然的 ... 它没电了。\n");

        if(query("light"))
                return notify_fail("灯泡已经点著了。\n");

        write("你将头盔上的灯泡点亮。\n");

        set("light", 1);
        call_out("burn_out", query("fuel"));
        return 1;
}

int extinguish_t(string str)
{
        if(!id(str)) return 0;
        if(!query("fuel"))
                return notify_fail( can_read_chinese()?
                        "太迟了，电已经用完了。\n":
                        "What's the point, it's cashed.\n");

        if(!query("light"))
                return notify_fail("这顶头盔的灯泡根本没被点亮 !!\n");

        write("你将灯泡开关关掉。\n");
        set("light", 0);
        set("fuel", remove_call_out("burn_out"));
        return 1;
}

void burn_out()
{
        object owner;

        owner = environment(this_object());
        if( living(owner) )
                tell_object( owner, 
                        "你的头盔灯泡闪了几下，没电了。\n");
        set( "value", ({ 350, "silver" }));
        set( "fuel", 0 );
        set( "light", 0 );
}
