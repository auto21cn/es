
#include </u/b/boss/demogorgon/mudlib.h>
#include </u/b/boss/demogorgon/stats.h>
#include </u/b/boss/demogorgon/guilds.h>
#include <ansi.h>

#define BOARD "/u/b/boss/demogorgon/board"

inherit GUILD;

void create()
{
        ::create();
      set_short( "魔神公会" );
set_long(
"你现在来到魔神进修的乐地，了是整个东方大陆最邪恶的地方。虽然这是邪
恶的地方。但同公会中的人是很友好，中间有一把邪剑(sword)上面好象有
字（runes),你不知不觉的想去看它。\n",
        );

        set( "light",1 );
        set( "exits", ([
    "east" : "/u/b/boss/demogorgon/guild1.c",
    "south" : "/u/b/boss/demogorgon/shop.c",
    "west" : "/u/b/boss/demogorgon/guild2.c",

        ]) );

        set("item_desc", ([
                "runes" : CYN
" —————————————————————————————
   欢迎来本会一游，这儿是一些高级玩完的快土(如果你是低级玩家
   请要不伤心。努力奋斗一定能平步青云，出人头地的,那时本公会
   欢迎你加入。)如果想了解本公会的能力请打(help guilds)。
   (help damogorgon)。
   ————————————————————————————— \n"NOR,
                "sword" : HIB "这邪神剑似乎具有某种不可思议的魔力。\n" NOR
        ]) );


       // set_guild("mage");
        set_guild("/u/b/boss/demogorgon/dema.c");
        BOARD->frog();
        reset();

}

#include </u/b/boss/demogorgon/mudlib.h>
#include </u/b/boss/demogorgon/stats.h>
#include </u/b/boss/demogorgon/guilds.h>
#include <ansi.h>

#define BOARD "/u/b/boss/demogorgon/board"

inherit GUILD;

void create()
{
        ::create();
      set_short( "魔神公会" );
set_long(
"你现在来到魔神进修的乐地，了是整个东方大陆最邪恶的地方。虽然这是邪
恶的地方。但同公会中的人是很友好，中间有一把邪剑(sword)上面好象有
字（runes),你不知不觉的想去看它。\n",
        );

        set( "light",1 );
        set( "exits", ([
    "east" : "/u/b/boss/demogorgon/guild1.c",
    "south" : "/u/b/boss/demogorgon/shop.c",
    "west" : "/u/b/boss/demogorgon/guild2.c",

        ]) );

        set("item_desc", ([
                "runes" : CYN
" —————————————————————————————
   欢迎来本会一游，这儿是一些高级玩完的快土(如果你是低级玩家
   请要不伤心。努力奋斗一定能平步青云，出人头地的,那时本公会
   欢迎你加入。)如果想了解本公会的能力请打(help guilds)。
   (help damogorgon)。
   ————————————————————————————— \n"NOR,
                "sword" : HIB "这邪神剑似乎具有某种不可思议的魔力。\n" NOR
        ]) );


       // set_guild("mage");
        set_guild("/u/b/boss/demogorgon/dem.c");
        BOARD->frog();
        reset();

}
