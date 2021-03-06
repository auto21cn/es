#include "../moyada.h"

inherit WEAPON;

void create()
{
	set_name("Shovel", "铲子");
	add ("id",({ "shovel" }) );
	set_short("小铲子");
	set_long(
            "一把小铲子，可用来挖崛(dig)。\n"
	);
	set( "weapon_class", 10 );
        set( "type", "dagger" );
	set( "min_damage", 2 );
	set( "max_damage", 5 );
	set( "weight", 20 );
	set( "value", ({ 10, "silver" }) );
	set( "unit", "把" );
}

void init()
{
        add_action("to_dig","dig");
}

int to_dig(string str)
{
        object obj1, obj2;
        
        if ( !str || str=="" )
          write("你要挖哪 ?\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if ((int)obj2->query("dig")==1) 
              obj2->to_find_dig(str);
            else
              write("这里不能挖！\n");
          }
          else return notify_fail("你手上并没有工具。\n");  
        }
        return 1;
}
