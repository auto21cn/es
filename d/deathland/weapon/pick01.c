#include "../echobomber.h"

inherit WEAPON;

void create()
{
    seteuid(getuid());
	set_name("Pick", "十字镐");
	add ("id",({ "pick" }) );
	set_short("a dwarven pick", "矮人的十字镐");
	set_long(
            "一把矮人的十字镐，可用来开凿(excavate)\或\是挖掘(dig)。\n"
	);
	set( "unit", "只" );
	set( "weapon_class", 7 );
	set( "type", "thrusting" );
	set( "min_damage", 5 );
	set( "max_damage", 18 );
	set( "weight", 120 );
	set( "value", ({ 460, "silver" }) );
}

void init()
{
        add_action("to_excavate","excavate");
        add_action("to_excavate","dig");
}

int to_excavate(string str)
{
        object obj1, obj2;
        
          if ( !str || str=="" )
           return notify_fail("你想挖什麽东西?\n"); 
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if (!( obj2->query("direction") )) 
               return notify_fail("破坏环境是不好的行为.\n");
            
            if ((string)obj2->query("direction")=="block" ) 
              obj2->to_find_excavate(str);
             // write ("当你试著挖掘时,一只可怕的怪兽向你冲来,\n");
            else
              return notify_fail( 
                "由於这里是矮人的地盘,你不能在这里开凿！\n");
            }
          else return notify_fail( 
            "你手上并没有工具。\n");  
        return 1;
}
