#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("空地");
        set_long( 
@LONG
你站在一片空地上，地上野草丛生，野草大约是你头的高度，使你看不到四周
的景象。抬头一望，晦暗不明的天空，乌云团簇好似一只只正在张牙舞爪的野兽，
野兽正恶狠狠地瞪著你，似乎要把你吃下腹。
LONG);
    set( "exits", ([
         "east":LAKE"village10"
    ]) );
    set( "objects", ([
        "vendor":LMONSTER"vendor1",
      "wanderer":LMONSTER"wanderer"
    ]) );    
    ::reset();
}
