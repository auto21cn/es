//暂时给精灵不见时使用的物件, 并不十分妥善, 取代方法考虑中.
#include <body.h>

inherit OBJECT;

void create()
{       
	set_name("spirit_stone","精灵之石" );
	set_short("精灵之石");
	set_long(@LONG
	
一块淡绿色半透明的结晶石，据说能帮助你招换失去的精灵。(touch spirit_stone)。

LONG);
	set("unit","块");
        set("prevent_get",1);
}

void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
  if (!arg || arg != "spirit_stone")
    return 0;
  if (!this_player()->query_temp("summon_rest")) {
    write("精灵之石微微的震动了一下，但是没有发生任何事情。\n");
    return 1;
  }
  write("精灵之石发出五彩的光芒，使你恢复招换精灵的能力。\n");
  this_player()->delete_temp("summon_rest");
  return 0;   
}