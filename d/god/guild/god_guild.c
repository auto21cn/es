#include <mudlib.h>
#include <stats.h>
#include <org.h>
#include "../god.h"
#include <ansi.h>

#define BOARD GOD"god_board"

inherit NEW_GUILD;
void create()
{
    object guild_master;

        ::create();

    set_short("魔神公会");
        set_long(
                 @C_LONG_DESCRIPTION
你现在来到魔神进修的乐地，了是整个东方大陆最邪恶的地方。虽然这
是邪恶的地方。但同公会中的人是很友好,中间有一把邪剑(sword)上面
好象有字（runes),你不知不觉的想去看它。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "c_item_desc", ([
                "runes" : @LONG_TEXT
    ——————————————————————————————
      欢迎来本会一游，这儿是一些高级玩完的快土(如果你是低级玩家
      请要不伤心。努力奋斗一定能平步青云，出人头地的,那时本公会
      欢迎你加入。)如果想了解本公会的能力请打。
              (help guild)。             (read book)。
      ——————————————————————————————
LONG_TEXT
,
                "sword" : HIB "这邪神剑似乎具有某种不可思议的魔力。\n" NOR
 ]) );
    set( "exits", ([
                  "east" : "/d/god/guild/pk.c",
                  "south" : "/d/god/guild/shop.c",
                  "west" : "/d/god/guild/tech.c",
        ]) );
        set_guild("god");
        BOARD->frog();

        reset();
}
void init()
{
        ::init();
        add_action( "do_read", "read" );
}
int do_read(string arg)
{
        if( !arg || arg!="book" ) return 0;
        write("
"+HIY"积力量和智慧于一面，邪恶的是它的生命只有PK
玩家才能得到真正的力量。\n"
"如果想要用经验来做到成功，可能一百年都不可
能(ES的时间)所以杀玩家。\n"
"是唯一生长最快的的“经验”。\n\n\n"
"公会所提供的属性提升上限为:(可能少了请POST)\n\n"
   "      力量: 30            智慧: 40\n"
   "      敏捷: 35            体质: 25\n"
   "      虔诚: 10            运气: 30\n"+NOR""
              );
        return 1;

}
