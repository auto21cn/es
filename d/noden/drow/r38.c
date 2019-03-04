#include "iigima.h"

inherit ROOM;

void create()
{

        ::create();
        set_short( "stone floor","地下石阶");
        set_long(

@C_LONG
这里是一处冗长的石阶，蜿蜒向下，你看不到石阶的尽头，墙上微弱
的火把还在闪烁著，但是好像快熄灭了，阶梯湿漉漉的，长有不少青苔，
你要小心步行，千万别滑倒了。
C_LONG
        );
        set( "light",1 );
        set( "exits", ([           
                     "southeast": DROW"r39",
                    "north":DROW"r28"
        ]) );
}
