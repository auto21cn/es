#include "oldcat.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
        set_short("看守室" );
        set_long(
@LONG
这是一间阴森森的矮灵族的看守室，是个看守他们抓来祭品的地方，你似乎听到从
东边传出求救的声音。
LONG
        );
	set( "exits", ([
        "out" : ONEW"varea6",
        "east" : ONEW"wcave2"
	]) );
        set( "pre_exit_func",([
             "east":"to_east"
              ]) );
        set( "objects",([
               "wjailor" : OMONSTER"wjailor"
             ]) );
        create_door( "east","west", ([
                     "keyword" : ({"door","thick door"}),
                     "name" : "thick door",
                     "c_name" : "厚厚的门",
                     "status" : "locked",
                     "lock" : "WGUARD",
                     "desc" : "You see a door.\n",
                     "c_desc" : "一扇厚厚的木门上面有个钥孔。\n"
                    ]) );
        reset();
}

int to_east()
{
  if(!present("guard")) {
      return 0;
  }
  else {
      write("守卫说道：想劫狱，等通过我这一关在说吧。\n");
      return 1;
  }
}
