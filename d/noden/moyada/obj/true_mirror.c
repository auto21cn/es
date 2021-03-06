#include "../moyada.h"

inherit OBJECT;

void create()
{
        set_name( "Mirror of True", "拉之镜" );
        add( "id", ({ "mirror" ,}) );
        set_short("拉之镜");
        set_long(@CLONG
一面闪闪发亮的镜子，据说能映出一个人的真面目。
你可以用它照(show)怪物来识破他的伪装。
CLONG
        );
        set("weight", 15 );
        set("no_sale",1);
        set("value", ({ 200 , "silver" }) );
        set("unit", "面");
}           

void init()
{
    add_action( "to_show", "show");
}

int to_show( string msg )
{
    string who;
    object ob;
    if( !msg ) return 0;
    if( sscanf( msg, "mirror to %s", who )!=1 ) 
      return notify_fail("Show what to whom ??\n");
    ob = present( who, environment(this_player()) );
    if( !ob ) {
      tell_object( this_player(), "这里没这个人。\n");
      return 1;
    }
    if( undefinedp(ob->change(ob, this_player())) )
      tell_object( this_player(), 
        ob->query("c_name")+"说: 你干什麽?\n" );
    return 1;
}
