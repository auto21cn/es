#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "nail_spirit", "nail" );
}
 
void create()
{
        set_name( "seven nail", "七星追魂钉" );
        add( "id", ({ "nail" }) );
        set_short( "七星追魂钉" );
        set_long( @C_LONG
这是一支七寸长的红色木钉，整只钉子散发著檀香和某种你说不上来的奇异力量。
这只木钉的钉头看起来并不十分锋利，让你怀疑是不是真的能钉(nail)住些什麽。
C_LONG
                );
        set("unit","支");
        set("weight", 10);
        set("value",({1, "silver"}) );
        set("no_sale", 1 );
}
 
int nail_spirit(string arg)
{
    if( !arg || arg != "mark" ) return 0;
    if ((string)environment(this_player())->query("short")=="库房大门" ) {
        tell_object(this_player(),
                "你拿著令牌，守卫对你一幅必恭必敬的样子。\n" );
        this_player()->set_temp("army_mark",1);
        } else
    if ((string)environment(this_player())->query("short")=="密道岗哨" ) {
        tell_object(this_player(),
                "你拿著令牌，守卫对你一幅必恭必敬的样子。\n" );
        this_player()->set_temp("army_mark",1);
        } else
        tell_object(this_player(),
                "你拿著令牌像笨蛋一样晃呀晃呀地，可是没人理你。\n" );
        return 1;
}
