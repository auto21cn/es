
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("palace2","神宫主殿");
       set_long(@C_LONG
富丽堂璜的摆设，一幅诺顿大陆的全图彩绘就画在天幕
上，令你不禁摒息注视这巧夺天工的黑暗精灵杰作，这就是
黑暗精灵村为纪念赛亚达所建造的大神宫，一座用紫水晶雕
成的雕像放在主殿前方，主殿墙上并挂了一面盾牌，上面绘
有耶拉曼皇室的符号，地上铺有一块毛绒绒的地毯，整个神
宫宁静而安详，光线柔和，但你不明白的是：这里是地底王
城，但为何如此明亮？
C_LONG );
       set("exits",([
                     "west":"/d/noden/drow/r65",
                     "east":"/d/noden/drow/r67"
                    ]));
       set("light",1);
}
