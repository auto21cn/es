#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
        object ob;

	::create();
	set_short("龙宫大殿" );
	set_long(
@LONG
这是井龙宫的大殿，殿内藻井正中雕俯首金龙一条，八边有团光水藻及福禄寿喜万
五字行图案围绕，殿顶盖\黄琉璃瓦镶绿剪边，十六道五彩琉璃脊，宝瓶火□珠攒尖顶，
美伦美奂，金碧辉煌。殿前两根红漆圆柱上雕有凌空欲飞的金龙，姿态生动。平常在宝
座上坐的是井龙王，两旁站的是左右护卫，英姿挺拔，目光炯炯有神。这个大殿是龙王
和大臣们讨论事情的地方，但在这小小的井中似乎可讨论的事并不多。西边可通到龙王
的寝宫，东边可通到公主的寝宫。
LONG
	);
	set( "exits", ([
             "south" : OTEMP"palace2",
             "west" : OTEMP"palace4",
	     "east" : OTEMP"palace5",
	]) );
        set("objects", ([
            "lift_guard":OMONSTER"left_guard",
            "right_guard":OMONSTER"right_guard"
            ]) );
        set("light",1);
        reset();
}
