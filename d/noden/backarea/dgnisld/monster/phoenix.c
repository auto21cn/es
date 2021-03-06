#include <mudlib.h>

inherit MONSTER;

void create ()
{

  ::create();
   set_level(20);
	set_name( "Phoenix", "不死鸟" );
   add( "id", ({ "phoenix", "bird" }) );
   set_short( "不死鸟浴火凤凰" );
   set_long(
	    "不死鸟浴火凤凰全身都是火。据说每隔六百年她会冲进火山口中\n"
	"，重新获得新生命。传说喝了她的血可以长生不死。\n"
	);
	
   set( "max_hp", 4000 );
   set( "max_sp", 4000 );
   set( "hit_points", 4000 );
   set( "spell_points", 4000 );
   set_natural_armor( 35, 35 );
   set_natural_weapon( 35, 30, 50 );
   set( "wealth/gold", 500 );
   set( "weight", 800 );
   set( "gender", "female" );
   set( "unit", "只" );
   set( "exp_reward", 50000 );
   set( "immortal", 1 );
   set( "chat_chance", 10 );
   set( "chat_output", ({
	    "浴火凤凰说到：杀我没用的，我是不死的。\n",
    }) );
}
