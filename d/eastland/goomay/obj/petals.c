#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("petals", "花瓣");
        set_short("petals", "花瓣");
        set_long(@LONG
This is a lot of petals . sprinkle it at somebody will bring fun.
LONG
, @CLONG
婚礼或庆点时用的花瓣，当它被撒(sprinkle)向空中时，将会形成一幅绝美的图案。\n
CLONG
        );
        set("unit", "把");
        set( "weight", 0 );
        set ("value", ({ 10, "silver" }) );
        seteuid( getuid() );
}

void init()
{
        add_action("do_use","sprinkle");
}

int do_use(string arg)
{
        string cmsg, cmsg1, cmsg2;
        object target;

        if ( !arg || arg=="" )
	return  notify_fail( 
                "你想对谁撒花瓣 ？  uasge : sprinkle <who> \n" );

        target = present( arg , environment(this_player() )) ;
	if ( !target )
	return notify_fail( "这里没有这个人。\n" );

        if (target == this_player()) 
                {
                   write(
                        "你把花瓣撒向天空，霎时天空落下一阵花雨。\n" );
                  tell_room( environment(this_player()), 
			             target->query("c_name") +
                         "将一把花瓣撒向天空，霎时落下一阵缤纷花雨， 你觉得有点心醉。\n",
			  this_player() );  
                  remove() ;
                  return 1 ;       
                }
        else {
                cmsg = "你将花瓣向"+
                        target->query("c_name") +
                        "的身上一撒，霎时构成一幅人面桃花相映红的图案。\n";
                cmsg1 = this_player()->query("c_name")+
                        "将花瓣洒向"+
                        target->query("c_name") +
                        "的身上，霎时构成一幅人面桃花相映红的图案。\n";
                cmsg2 = this_player()->query("c_name")+
                        "将一把花瓣向你洒来，在缤纷的花瓣雨中，你觉得心醉了。\n";

                tell_object( this_player(), cmsg );
                tell_room( environment(this_player()), cmsg1 ,
                        ({ this_player(), target }) );
                tell_object( target, cmsg2 );

                remove();
                return 1;
        }
}
