#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("iron pick", "铁十字镐");
        add ("id",({ "pick" }) );
        set_short("铁十字镐");
        set_long(
            "一把十字镐，可用来开凿(excavate)矿物。\n"
        );
        set( "unit", "把" );
        set( "weapon_class", 15 );
        set( "type", "thrusting" );
        set( "min_damage", 5 );
        set( "max_damage", 10 );
        set( "weight", 120 );

        set( "value", ({ 165, "silver" }) );
}

void init()
{
        add_action("to_excavate","excavate");
}

int to_excavate(string str)
{
        object obj1, obj2;

        if ( !str || str=="" )
          write("Excavate what ?\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if ((int)obj2->query("excavate")==1)
              obj2->to_find_excavate(str);
            else
              write(
              "这里不能开凿！\n");
	  }
          else return notify_fail(
            "你手上并没有工具。\n");
	}
        return 1;
}
