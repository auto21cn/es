#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山腰小径");
	set_long( @LONG
你走在山腰崎岖小径上，小径两旁有几本山松山柏，还有些需要三、四人合抱
的参天的古桧，耸立云端见底不见头。在天空中不时有飞鸟吭啼或者停驻在那些高
木枝上剔翎刷羽，其神情极为悠闲自在。在地上，几盆灵花异卉，花朵之大，馥郁
芬香扑鼻，微风吹来，不禁令你神清气爽为之一□，无身毫不舒畅，格的是化外之
境。 
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
            "swu","nwd" }) );
	set( "exits", ([ 
       	     "southwestup" : SAREA"wiz1",
           "northwestdown" : SAREA"wiz3",
                     "swu" : SAREA"wiz1",
                     "nwd" : SAREA"wiz3"
        ]) );
        set("objects", ([
           "vendor":SMOB"vendor1"
        ]) );
	reset();
}
