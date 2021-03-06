#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "Gnome child", "地精小孩" );
	add ("id", ({ "child", "gnome", }) );
   set_short( "地精小孩" );
	set_long(
                 "虽说是个小孩,但他怎麽看都比你老。他正看著墙上的符号，\n"
                 "口中念念有词，好像在背诵什麽似的。\n");

        set( "alignment",-10);
        set( "gender", "male" );
        set( "race", "gnome" );
        set( "unit", "个" );
	set_perm_stat( "str", 5 );
	set ("wealth", ([ "gold": 3 ]) );
	set_natural_weapon(3,1,4);
	set_natural_armor(17,2);
        set("weight", 200);
	wield_weapon(WEAPONS"small_dagger");
}
