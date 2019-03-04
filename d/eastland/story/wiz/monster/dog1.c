#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "white dog Lucky", "小白狗 吉利" );
	add("id",({"dog","lucky"}));
	set_short( "小白狗 吉利" );
	set_long(@C_LONG
一只全身纯白毫无杂毛的小狗。它原是护国师孙女儿养的，前几天因为追逐著某东
西却不幸掉在这里，受伤沈重，奄奄一息。它正不停地舔著伤口，哀哀作响，可怜
极了。如果你有篮子，或著可以把它装著带上去。   
C_LONG
        );
        set("unit","只");
        set("no_attack",1);
        set("lucky",1);
        set("max_hp",100000);
        set("hit_points",1);
        set("chat_chance",10);
        set("chat_output",({
           "呜～呜～呜～～\n"
       }) );
}
