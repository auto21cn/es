//公会门口的广场
#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
     set_short( "广场" );
        set_long(
       "一个漂亮的喷水池坐落在广场中央,泉水纯净而美丽。广场上布满鸽子，\n"
  "人们或站或坐，或看或喂，呈现出一片和平的景象\n"
          );
     set( "light",1 );
     set( "exits", ([
          "north" : "/u/s/sage/home/work.c",
        "south" : "/u/s/sage/guild/killer_guild.c",
        ]) );
     create_door("south", "north", ([
                "keyword"       : ({ "tree door", "door" }),
                "name"          : "tree door",
                "c_name"        : "木门",
                "c_desc"        : "一扇破烂的木门",
                "status"        : "closed",
        ]) );

}
