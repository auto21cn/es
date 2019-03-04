//#pragma save_binary
#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("军官办公室");
  set_long( @CLong
这儿是一间军官办公室。一张五尺见方的檀木桌子就放在办公室的中央，桌上则
整整齐齐地放著文房四宝，檀香炉里飘出阵阵檀香，使你感觉彷佛置身仙居。桌子後
面放了两张红桧大椅，桌後的墙上则是悬著一个大字－『忍』，旁边的对联则是用狂
草所书，你怎麽也看不懂。这里的南北两侧各有一间军官寝室，楼下则是育乐中心。
CLong
);
set("light",1);
set("no_monster",1);
set("exits",([
               "north":MUMAR"stage04",
               "south":MUMAR"stage05",
               "down":MUMAR"stage01"
             ]));
#include <replace_room.h>
}
