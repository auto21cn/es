#include "../../story.h"

inherit ROOM;

void create()
{
        object goldgod;
        ::create();
	set_short("小型殿堂");
	set_long( @LONG
地面是整片黄金制成的，除却东北出口外，其馀皆被琼阁所包围，彼此交相掩
映，壮丽非常。殿堂内陈设皆是精金美玉，珠翠珊瑚所制，富丽□皇；四角落矗立
著四根巨大玉柱，美仑美奂，上面雕工精致，刻画之物活脱活现；柱顶各盏琉璃天
灯，旋转丈许晶莹白光，照耀满堂通明。殿内之事，穷极美工富丽之限，令人叹为
观止，直所未睹。
LONG
	);
        set("light",1);
        set("exits" , ([
           "northeast" : SPALACE"x3",
        ]) );
        set("no_embattle",1);
        goldgod=new(SPMOB"goldgod");
        goldgod->move(this_object());
        set("objects" , ([
          "westgod" : SPMOB"westgod",
        ]) );
	reset();
}
int clean_up()
{  return 0; }
