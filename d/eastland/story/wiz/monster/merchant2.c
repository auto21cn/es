#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "merchant", "路边卖米粉羹的" );
	add( "id", ({ "merchant" }) );
	set_short( "路边卖米粉羹的" );
	set_long(@C_LONG
一位卖米粉羹的路边小贩，他正满头大汗地招览客人。
C_LONG
        );
	set( "gender", "male" );
        set( "wealth/silver",100);
        set_natural_armor(55,2);
        set_natural_weapon( 19,10,20 );
        set("chat_chance",3);
        set("chat_output",({
            "来哟，来吃香喷喷好好吃的米粉羹哟。\n"
        }) );
        set( "inquiry", ([
             "entrance_palace":"@@ask_enter",
        ]) );
}
void ask_enter(object asker)
{
tell_room(environment(),@LONG

卖米粉羹的说道：喔，你想要进去皇宫咩？我是不太清楚啦，不过，你可以去
　　　　　　　　请教大官看看。先不要管这个，你要不要来一碗米粉羹啊？

卖米粉羹喊道："来哟，来吃香喷喷好好吃的米粉羹哟。\n"

LONG
   );
}
