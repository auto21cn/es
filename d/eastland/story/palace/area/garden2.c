#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("回廊");
	set_long( @LONG
回廊往这个方向己经是到了尽头。抬头一望，前面一缕飞瀑凌空而降，宛如一
条白色匹练，自天际缺口处急泻下来，於瀑底形成□天银浪，各方推挤攒簇犹如万
马奔腾之势，前锋广流十丈才渐趋平缓。廊道栏杆雕饰精细，西边一面约百亩圆形
湖荡，沿岸不是瑶草琪花，便是碧枝琼树；湖面若镜，绿波鳞鳞，锦麟游泳，暗香
时闻。湖面一座拱桥，雕镂精细，巧夺天工，通体水晶建成，银光灿烂，耀眼生辉
；湖中心一座四方形楼阁，高出水面约三尺，造型特朱，气派庄严。

LONG
	);
        set("light",1);
        set("exits" , ([
             "south" : SPALACE"garden1",
            "bridge" : SPALACE"bridge1",
        ]) );
        set("pre_exit_func",([
            "bridge":"can_pass"]));
	reset();
}
int can_pass()
{
   if ( this_player()->query("palace_war") ) return 1;
   return 0;
}
