#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void init()
{
  add_action("eat_pill","eat");
}  
void create()
{
	set_name("dragon pill", "青龙丹" );
	add( "id", ({"pill"}) );
	set_short("青龙丹");
	set_long(
		"这种药丸是蛮有名气的补药, 对於乱服成药造成的身体不适:p\n"
		"颇有疗效。如果你觉得头昏眼花, 建议你立刻吃(eat)一颗青龙\n"
		"丹。不过如果你已经生病, 这种补药并不能治病, 你还是应该去\n"
		"看医生。\n"
	);
	set( "can_eat", 1 );
	set( "unit", "粒" );
	set( "weight", 15 );
	set( "value", ({ 3000, "silver" }) );
}

int eat_pill(string str)
{
    int stat;
    object player;
        
        if (!str || str!="pill") 
          return notify_fail("你要吃什麽?\n");
        player=this_player();
	stat = (int) player->query("medication_resistance");
	// 1 dragon pill can recover from 3 makira potion
	stat = stat - 210 ;
	if (stat<0) stat=0; 
	player->set("medication_resistance",stat);	
        tell_object(player,"你觉得身体状况好多了, 头也不再那麽晕。\n");
        remove();
        return 1;
}
