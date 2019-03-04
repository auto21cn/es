#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("溪谷沙岸");
	set_long( @LONG
你立足之处是一溪谷里的沙岸，前面溪水缓缓从东北流向西南而去。这溪谷两
岸都是千仞高的山峰，除非胁生两翼、步纵万尺，否则断难攀越而过。这溪谷上方
不时有鸟类飞过或时而停在山壁老枯枝上引吭高歌，发出的声音引起山壁相互共鸣
。东北处有块大石，大石一半底下长满了青苔，地上有些风乾了的鱼饵，并非是个
人烟俱灭的地方。
LONG
	);
        set("light",1);
	set( "exits", ([ 
          "southwest" : SAREA"bottom2"
        ]) );
        set("objects", ([
             "fisher" : SMOB"fisher1"
        ]) );
	reset();
}
void init()
{
    add_action("do_up","神恩如海天威如岳系系矩忙罗");
}
int do_up(string arg)
{
    object player;
    player=this_player();
    write("\n忽然，从你脚底下刮起一阵风把你吹了上去，旋即把你乱丢！\n\n");
    tell_room(this_object(),sprintf(
      "\n忽然一阵怪异的风把%s往上吹去！\n",player->query("c_name")),player);
    player->move_player(SAREA"stone1","SNEAK");
    return 1;
}
