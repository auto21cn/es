#include <mudlib.h>

inherit OBJECT;

void init()
{
        add_action( "quaff_potion", "drink" );
        add_action( "quaff_potion", "quaff" );
}

void create(){

        set_name("ching","竹叶青");
        add( "id" , ({ "wine","chinese wine","ching" }) );
	set_short( "竹叶青" );
      set_long("这是远风镇产的竹叶青。\n");
        set("unit","杯");
	set("ident", "CHING");
        set("weight", 10);
        set("value",({20, "silver"}) );
}

int quaff_potion(string arg)
{

        if( ! id(arg) ) return 0;
        write(
                "你喝下一杯竹叶青。感到头有点晕晕的，但是有一种兴奋的感觉。\n"
        );
        tell_room( environment(this_player()) ,
                this_player()->query("c_name")+"喝下一杯竹叶青，显得很开心的样子
。\n",
                this_player() );

        remove();
        return 1;

}

