#include "../mad.h"

inherit MONSTER;

void create()
{
   object key;

	::create();
   set_level(5);
   set_name( "poor scholar", "穷酸书生" );
   add( "id", ({ "scholar" }) );
   set_short( "穷酸书生" );
	set_long(
        "一个看起来落破穷酸的中年书生, 他正一个人在角落独自饮茶.\n"
	);
   set( "gender", "male" );
	set( "race", "human" );
   set( "alignment", -50 );
   set_perm_stat( "dex", 8 );
   set_skill( "dodge", 50 );
   set( "natural_weapon_class1", 15 );
   set( "natural_min_damage1", 12 );
   set( "natural_max_damage1", 30 );
   set( "wealth/copper", 10 );
   set( "chat_chance", 12 );
   set( "chat_output", ({
        "穷酸书生拿起茶壶斟了一杯茶, 然後一口饮尽.\n",
        "穷酸书生吟道: 吾家有女粗长成, 藏在深闺人不知;\n"
        "              可怜毛贼视茫茫, 莫名垂涎无盐色.\n"
	}) );
   set( "inquiry", ([
        "daughter" : "唉..........\n",
     ]) );

   key = new( IANOBJ"key" );
   key->move(this_object());
}
