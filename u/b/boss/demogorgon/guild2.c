#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( ""+HIW"PK会场"+NOR"" );
set_long(
"这是玩家专用的PK场地，这儿满地"+HIR"鲜血"+NOR"、"+HIW"尸体"+NOR"。\n"NOR,
"一定有许多玩家死在这儿，看起来极恐怖。突然，\n"
""+HIB"死神"+NOR"对你邪恶一笑。\n"NOR,
        );
        set( "light",1 );
        set( "exits", ([
    "east" : "/u/b/boss/demogorgon/demogorgon.c",
        ]) );
}
