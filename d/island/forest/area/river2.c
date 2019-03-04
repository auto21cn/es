#include "../tsunami.h"
#include <conditions.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("河中");
    set_long(@LONG
在这潺潺的小河中看，只觉得一切都好乾净、好清晰，头顶上的光透过
波浪，映在底下的沙地上，使人感觉彷佛置身於尘嚣之外，那另一个未曾探
索过的世界一般。这令人流连的境地，让你几乎忘了要呼吸了！咦～这里似
乎怪怪的耶！
LONG
            );
    set("exits",([
        "up":AREA"upriver2",
        "north":AREA"river"]) );

    set_outside("island");
    set("underwater",1);
    set("objects",([
        "turtle":TMOB"turtle" ]) );
    reset();
}

void init()
{
UNDERWATER->apply_effect(this_player(),3,2);
add_action("do_search","search");
}

int do_search(string str)
{
   if( !str || str != "here"){
   write("你要找什麽呢??\n");
   return 1;
   }
   write(@ALONG
   你正想搜索可疑之处时，突然一道漩涡将你卷进一个小洞中...
ALONG
        );   
   tell_room( environment(this_player()),
   this_player()->query("c_name")+
     "在这里翻来翻去，突然间，出现一个马桶洞大小的漩涡把他吸走了...\n",
     this_player() );
   this_player()->move_player("/d/island/8,8.island","SNEAK");
   tell_room( environment(this_player() ),
   "当你在洗脚时，突然"+this_player()->query("c_name")+"从你跨下钻了出来...\n"
   ,this_player() );
 return 1;
}    