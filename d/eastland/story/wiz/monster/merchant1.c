#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "merchant", "路边卖蚵仔煎的" );
	add( "id", ({ "merchant" }) );
	set_short( "路边卖蚵仔煎的" );
	set_long(@C_LONG
一位卖蚵仔煎的路边小贩，他正满头大汗地招览客人。
C_LONG
        );
	set( "gender", "male" );
        set( "wealth/silver",100);
        set_natural_armor(55,2);
        set_natural_weapon( 19,10,20 );
        set("chat_chance",3);
        set("chat_output",({
            "来哟，赶紧来吃好好吃的蚵仔煎哟。\n"
        }) );
        set( "inquiry", ([
            "fly_building":"@@ask_building",
        ]) );
}
void ask_building(object asker)
{
tell_room(environment(),@LONG

卖蚵仔煎的说道：天都？我以前好像有看过喔．．对了，我曾经路过城外南
　　　　　　　　边的山岭上看过一栋漂浮在空中的建筑物，不晓得是不是
　　　　　　　　你所说的天都？不过，你可以去请教郊外一家草芦的老人
　　　　　　　　家名叫「金石老人」(golden_older)，他常说他年轻时到
		过天都。唉哟，先不要管这个，你要不要来盘蚵仔煎啊？　　
　　
LONG
   );
}
