#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "hold_mark", "hold" );
}
 
void create()
{
        set_name( "cavalry permit", "骑兵令牌" );
        add( "id", ({ "cavalry","permit" }) );
        set_short( "骑兵令牌" );
        set_long( @C_LONG
这是一面金制的令牌，上面刻著『牧马关骑兵令』，据说这兵符和骑兵团长有同等
的地位，拿著(hold)它可以自由使用牧马关的马匹。
C_LONG
                );
                set("unit","面");
                set("weight", 10);
                set("value",({10, "silver"}) );
                set("no_sale", 1 );
}
 
int hold_mark(string arg)
{
    if( !arg || arg != "permit" ) return 0;
    if ((string)environment(this_player())->query("short")=="马房" ) {
        if (this_object()->query_temp("hold_permit") ) {
             tell_object(this_player(),
                     "马夫对你说，这面令牌的时效已过了。\n" );
             this_player()->set_temp("cavalry_mark",0);
              }
        else  {
             tell_object(this_player(),
                "你拿著令牌，马夫吓得头都不敢抬一下。\n" );
             this_player()->set_temp("cavalry_mark",1);
             this_object()->set_temp("hold_permit",1);
              }
        } else
        tell_object(this_player(),
                "你拿著令牌像个白痴一样晃呀晃呀地，可是没人理你。\n" );
        return 1;
}
