#include <mudlib.h>

inherit ROOM;

#include <ansi.h>
void create()
{
        ::create();
     set_short( "睡房" );
       set_long(
 "    这是圣人的睡房，比外面干净多了，屋子中间放着的不用说了是床，\n"
 "没有什么特别的,床头挂着一张照片(picture)。在床的旁边放着一张化\n"
 "妆桌，上面摆设齐全，看来圣人很喜欢他的妻子\n"
        );
     set( "light",1 );
     set("item_desc",([
              "picture" : "这是圣人和他未过门的妻子的合照，从他脸上可\n"
                          "看出，他是非常幸福的，在照片右下角，有几行\n"
                          "小字："RED"女神(qwe)：虽然你离我而去，但我总是忘\n"
                          "不了你，我愿意等你一生一世。"NOR"\n"
         ]));
     set( "objects", ([
          "knight" : "/u/s/sage/test/deathknight.c",
         ]) );
     set( "exits", ([
           "west"  : "/u/s/sage/workroom",
           "south" : "/u/s/sage/guild/gc.c",
        ]) );
}
