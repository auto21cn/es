#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( "技术进修场" );
set_long(
"好多"+HIB"魔神战士"NOR"走来走去，大家都在努力的进修自己。\n"
"希望成为最终的"+HIR"强者"+NOR"。\n"
  NOR
        );
        set( "light",1 );
        set( "exits", ([
    "west" : "/u/b/boss/demogorgon/demogorgon.c",
        ]) );
}
