// entrance 0

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("米达尔墓穴");
    set_long(@C_LONG
你现在在一个黑暗潮湿的洞穴里，不过奇怪的是虽然这里弥漫著很重的湿
气，墙壁上却是一点青苔也没有。处於这个阴森森的洞穴里，你不由得打了个
机伶伶的冷战 .... 你觉得还是赶快离开这个鬼地方比较好。
C_LONG
    );
    set("item_desc", ([
	"face" : "这石像的脸雕刻的很是精美，你不禁想摸摸它 ....\n",
	"statue" : "这石像雕刻的很是精致，看起来倒有点儿像魔族。\n",
	"wall" : "西边的墙上似乎嵌著一尊石像，不过你看不清楚它的脸。\n",
	"board" : @BB
告示牌上面写著：

	这是一个全新的区域，包含了一个非常高难度的任务。由於这个区域
    曾经困住过不少的巫师，所以如果你找不到这个房间的出路的话，请键入
     pray 这个命令，万能的天神会把你送到安全的地方去。

	这个任务会在你完成一个阶段之後予以储存，在第三阶段之後由於和
    黑无常签下赞助合约，所以如果不小心的话，可能会直接回远风镇露天英
    雄馆去，希望你能留意。加油吧！努力去完成任务！ 

				调教师  女王 (Lilia) 
BB
	]) );
    reset();
}

void init()
{
    add_action("to_touch", "touch");
    add_action("to_search", "search");
    add_action("to_pray", "pray");
}

int to_touch(string str)
{
    object p;
    p = this_player();

    if (str == "face")
    {
	tell_object(p, "石像的眼睛突然发出了一阵异样的光芒笼罩著你，你发现自己被传送到别的地方!\n");
	if (p->query(QUESTNAME) >= 1)
	    p->move_player(AREA"rose0", ({"%s被一阵诡异的光芒传送走了!\n", "%s伴随著一阵光芒出现在这里。\n"}), "" );
	else
	{
	    p->set_temp("lilia_0", 1);
	    p->move_player(AREA"en1", ({"%s被一阵诡异的光芒传送走了!\n", "%s伴随著一阵光芒出现在这里。\n"}), "" );
	}
	return 1;
    }
    else
	return notify_fail("你想摸什麽? 随便乱摸是不好的行为哦 ....\n");
}

int to_search()
{
    write("墙角似乎挂著一块告示牌 (board)。\n");
    return 1;
}

int to_pray()
{
    write("你跪下来祈祷 .... 祈祷些什麽好呢? ....\n");
    this_player()->move("/d/noden/nodania/sealroom");
    return 1;
}
