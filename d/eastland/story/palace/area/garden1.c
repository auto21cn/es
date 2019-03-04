#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("回廊");
	set_long( @LONG
到了这里已经是属於天都後殿了。回廊地面乃白玉砌成，光滑细润，不染一点
沙尘；廊道栏杆雕饰精细，廊外琼枝碧叶，上缀各色繁花，花大如钱或碗，馨香沁
人心脾。北边是回廊的延伸，不时传来泉水铿锵有劲之声。西边连接著殿内廊道，
东南边则是通往後花园的小径。

LONG
	);
        set("light",1);
        set("exits" , ([
                "west" : SPALACE"x4",
               "north" : SPALACE"garden2",
               "south" : SPALACE"garden3"
        ]) );
	reset();
}
