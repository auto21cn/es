#include <mudlib.h>
#include "../legend.h"
inherit LAKE"lakeii";
inherit ROOM;

void create()
{
    ::create();
    set( "light",1);
    reset();
}
void init()
{
    object *all;
    int i;
    ::init();
    all=all_inventory(this_object());
    for (i=0;i<sizeof(all);i++)
       if (!living(all[i]))
           all[i]->remove(); 
    add_action("do_get_off","get_off");
}

int do_get_off()
{
  tell_object(this_player(),@LONG
你不知道著了什麽魔，居然弃船跳下水......
咕噜咕噜喝了一肚子水，差一点就淹死，总算福大命大又爬回船上来．
LONG
  );
  this_player()->receive_damage(20);
  return 1;
}