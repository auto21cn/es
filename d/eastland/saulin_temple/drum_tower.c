#include "saulin_temple.h"

#include <daemons.h>
#define NEED_FP   200
#define REDUCE_FP  20

inherit ROOM;
inherit STATS_D;

void create()
{
       ::create();
       set_short("鼓楼");
       set_long( @C_LONG_DESC
你沿著石阶爬上一座古楼，楼上悬著一面巨鼓(drum)，朱红的鼓身暗黄
的鼓面显示这面鼓已有多年历史了，在鼓旁有一支鼓锤，平时只有在傍晚才
有专人来敲(hit) 这面鼓，这就是所谓的 "暮鼓" 。据说这些敲鼓的人往往
身负上乘内功\，因为巨鼓一响，所发出了音波强度，真的不是普通人能受得
了的。西方是一座偏殿。
C_LONG_DESC
       );
       set("light",1);
       set("item_desc",([ "drum" : @C_LONG
这是一面巨鼓，光是鼓身就有一个人高，如果不蒙上鼓面的话，塞上五、
六个人是没问题的。现在它的鼓身鼓面都已经泛黄了，但是它的外表仍然
保持光润，显示有人常来保养它。
C_LONG
       ]));
       set("exits",([
           "west" : SAULIN"side_temple2",
       ]) );
       reset();
}

void init()
{
     add_action("hit_bell","hit");
}

int hit_bell(string str)
{
     if( !str || str != "drum" )
       return notify_fail("你要敲什麽?\n");

     if( (int)this_player()->query("force_points") < NEED_FP ) {    
       this_player()->receive_damage((int)this_player()->query("max_hp")/4);
       tell_object(this_player(), @C_LONG
  你拿起鼓槌，用力的往鼓面敲了下去，你感觉到一股音波如排山倒海般的
  从鼓面向你涌了过来，把你的五脏六腑震的四分五裂。
C_LONG
       );
       tell_object(this_player(),
         "( 你 "+status_string()+" )\n");
     } else {
       tell_object(this_player(), @C_LONG
  你拿起鼓槌，用力的往鼓面敲了下去，你感觉到一股音波如排山倒海般的
  从鼓面向你涌了过来，你赶紧运起内力抵抗。
C_LONG
       );
       this_player()->add("force_points", -REDUCE_FP);
     }
    return 1;
}       
