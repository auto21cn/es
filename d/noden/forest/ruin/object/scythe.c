#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("Scythe", "镰刀");
	add ("id",({ "scythe", }) );
	set_short("镰刀");
	set_long("一把很锋利的镰刀，可用来割草(cropp)。\n");
	
	set( "unit", "把" );
	set( "weapon_class", 5 );
	set( "type", "shortblade" );
	set( "min_damage", 5 );
	set( "max_damage", 10 );
	set( "weight", 35 );
	set( "value", ({ 10, "silver" }) );
}

void init()
{
        add_action("to_cropp","cropp");
}

int to_cropp(string str)
{
        object obj1, obj2;
        
        if ( !str || str=="" )
          write("Cropp what ?\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2=environment(obj1);
            if ((int)obj2->query("cropp")==1) 
              obj2->to_find_cropp(str);
            else write("你不能割它！\n");
          }
          else return notify_fail("你手上并没有工具。\n");  
        }
        return 1;
}
