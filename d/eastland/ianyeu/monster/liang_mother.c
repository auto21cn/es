#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(6);
   set_name( "liang mother", "梁母" );
   add( "id", ({ "liang", "mother" }) );
   set_short( "梁母" );
	set_long(@C_LONG
一位年约三十的中年妇女。当你注视她时, 明显觉得她对你不怀好感,
甚至想立刻赶你出门。
C_LONG
	);
	set( "race", "human" );
   set( "gender", "female" );
   set( "alignment", 350 );
   set_perm_stat( "str", 10 );
   set_perm_stat( "dex", 10 );
   set_perm_stat( "kar", 5 );
   set_skill( "dodge", 40 );
   set( "wealth/copper", 50 );
	set_natural_weapon( 8, 8, 8 );
   set_natural_armor( 40, 8 );

   set( "chat_chance", 15 );
   set( "chat_output", ({
        "梁母道: 宝宝别怕! 妈在这.\n"
        }) );
}
