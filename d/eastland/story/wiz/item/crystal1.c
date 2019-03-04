#include <mudlib.h>
inherit OBJECT;
void create()     
{
        set_name( "crystal glass", "水晶玻璃球" );
	add("id",({"glass"}));
	set_long(@LONG
一颗晶莹剔透的水晶球，它上面的萤光物质使得它不时在黑暗中发出些微磷光。	
LONG
        );	
	set_short("水晶玻璃球");
	set( "unit", "颗" );
	set("weight", 40);
	set("value", ({ 100, "silver" }));
        set("light",1);
        call_out("disappear",1800,this_object());
}
void disappear(object ob)
{
    object owner;
    owner=environment(this_object());
    if (!owner)
       printf("这颗水晶球上的萤光物质业已消耗殆尽失去光泽了...！\n");
    remove();
}
