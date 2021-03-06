#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("树林");
    set_long(@LONG
这儿四周长满了奇形怪状的植物，大多是目前尚不为人知的。风也已经
和缓多了，不像狭道中那般强劲可怕；四处传来的是一连串的悦耳鸟鸣，偶
而出现几声令人胆寒的低鸣，不知道何处会出现可怕的怪物呢！南边的草丛
(thicket)中似乎有点古怪！
LONG
             );
    set("exits",([
            "north":AREA"way13"]) );
    set_outside("island");
    set("c_item_desc",(["thicket":@HOLE

           哇！！！原来这儿有个洞耶，大概可以钻进去(enter)看看！

HOLE
                       ,"hole":@C_LONG
这个洞黑黑窄窄的，看起来似乎有点吓人；里面不知道躲了什麽怪物？
C_LONG
                       ]) );
    reset();
}

void init()
{
    add_action("do_enter","enter");
}

int do_enter(string str)
{
    object victim;
    
    if( !str || str!="hole" )
         return notify_fail("你要进哪儿？\n");
         write("\n．．你带著些微的颤抖缓慢的向洞中滑步前进．．\n\n");
         tell_room( environment(this_player()),
           this_player()->query("c_name")+"蹲下身来，用力把自己挤进洞中！\n"
           ,this_player() );
         this_player()->move_player(AREA"hole1","SNEAK");
         tell_room( environment(this_player()),
           this_player()->query("c_name")+"用力的将自己的身躯给挤了进来！\n"
           ,this_player() );
         return 1; 
}
