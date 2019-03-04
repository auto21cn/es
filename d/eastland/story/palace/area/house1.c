#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("水晶殿堂");
	set_long( @LONG
这是一座通体水晶建成的小型殿堂，除却东南出口，其馀皆被琼阁所包围，彼
此交相掩映，一派壮丽非常。殿堂内陈设皆是精金美玉，珠光宝气，富丽□皇；四
角落矗立著四根巨大玉柱，美仑美奂，上面雕工精致，刻画之物活脱活现；柱顶各
盏琉璃天灯，旋转丈许晶莹白光，照耀满堂通明。大祗殿内之事，穷极美工富丽之
限，令人叹为观止，从所未睹。
LONG
	);
        set("light",1);
        set("exits" , ([
           "southeast" : SPALACE"x1",
        ]) );
        set("pre_exit_func",([
           "southeast":"can_pass"]));
        set("objects" , ([
           "northgod" : SPMOB"northgod",
        ]) );
	reset();
}
int can_pass()
{
    if ( !query("cast") ) return 0;
    if ( !this_player()->query_attacker() ) return 0;
    write("漫天冰雪阻挡了你的去路！！\n");
    return 1;
}
