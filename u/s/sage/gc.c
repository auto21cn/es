//公会门口的广场
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
      set_short( "boss的婆家" )
        set_long(
       "这是圣人的睡房，比外面干净多了，屋子中间放着的不用说了是床，没有什么特别的,\n"
  "特别的是床头挂着一张照片，一个年轻美貌的少女的照片，你不禁看呆了\n"
  "真想走过去吻她。。。。。。。。。。在照片的右下角写着:\n"
 "                           my wife:qwe\n"
        );
     set( "light",1 );
     set( "exits", ([
          "north" : "/u/s/sage/home/work.c",
        ]) );
