#include <mudlib.h>

inherit OBJECT;

void init()
{
        add_action( "quaff_potion", "drink" );
        add_action( "quaff_potion", "quaff" );
}

void create()
{
        set_name("old wine","陈年老酒");
        add( "id" , ({ "wine" }) );
        set_short("陈年老酒");
        set_long(
		 "这是一□上好的陈年老酒，□上有著暗黄的泥封，破碎的标签都难以辨识了。\n");
        set("unit","□");
        set("weight", 10);
        set("value", ({20, "silver"}) );

}

int quaff_potion(string arg)
{
        if( ! arg || !id(arg) ) return 0;
        write( 
                "你咕嘟咕嘟地喝下一整□老酒，好像有一把利刃把你从中劈开一般。\n");
        tell_room( environment(this_player()), 
                this_player()->query("c_name")+"咕嘟咕嘟地灌下一整□老酒，然後醉的满地乱爬。\n"
		, this_player()
        );
        remove();
        return 1;
}
