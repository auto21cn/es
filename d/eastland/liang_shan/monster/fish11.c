
#include "mudlib.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(1);
        set_name( "little fish", "漂亮小鱼" );
        set_short("漂亮小鱼");
        set("unit","条");
        set_long(
@C_LONG
    这是一条非常可爱的小鱼，它正好奇的看著你。
C_LONG
);
        set ("gender", "female");
        set( "likefish",1);
        set( "alignment", 300 );
        set_natural_weapon( 2, 1, 3 );

}
void init()
{
        add_action( "kill_me", "kill");
}
int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || ( name != "crumb") ) return 1;
{
     tell_object(me,
@CRUMB
小鱼开始快乐的吃著面包屑.......
CRUMB
	);
		item->remove();
		this_player()->set_temp("feed_fish",1);
        return 1;
}
}