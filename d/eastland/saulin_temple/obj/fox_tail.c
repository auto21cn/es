#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "hold_tail", "hold" );
}

void create()
{
        set_name( "fox's tail", "狐狸尾巴" );
        add( "id", ({ "tail" }) );
        set_short( "狐狸尾巴" );
        set_long(@C_LONG
这是一条蓬蓬松松的狐狸尾巴，据说握著(hold)千年狐狸精的尾巴可以使人
暂时隐身，不知道是真是假？
C_LONG
		);
   		set("unit","条");
   		set("weight", 10);
   		set("value",({10, "silver"}) );
        set("no_sale", 1 );
}

int hold_tail(string arg)
{
	if( !arg || arg != "tail" ) return 0;
    if ((string)environment(this_player())->query("short")=="藏经阁前" ) {
    	tell_object(this_player(), 
    		"你拿出狐狸尾巴举在胸前，那些僧人们好像什麽都没看见。\n" 
        );
        this_player()->set_temp("book_quest/step",1);
	} else
        tell_object(this_player(), 
         	"你把狐狸尾巴举在胸前，旁边路过的人都掩著嘴偷笑。\n"
        );
	return 1;

}
