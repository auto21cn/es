#include "../island.h"
#include <mudlib.h>
inherit MONSTER;

void create()
{       
	object ob1, ob2 ,ob3;

	::create();
	set_level(9);
	set_name("lizardman hunter", "蜥蜴人猎人");
	add( "id", ({ "hunter" }) );
	set_short( "蜥蜴人猎人");
	set_long(@LONG
这个蜥蜴人全身披著油亮的深绿色鳞片，看起来好像身手不错的样子的样子。
LONG
	);
	set( "unit", "名" );
	set_perm_stat("str", 11);
	set_perm_stat("dex", 11);
	set( "time_to_heal", 3 );
	set_skill( "shortblade", 55 );
	set_skill( "dodge", 50 );
	set( "race", "lizardman" );
	set( "gender", "male" );
	set( "wealth/gold", 7 );
	set_natural_weapon( 10 , 7 , 10 );
	set_natural_armor( 15,10 );
	set( "alignment", -500 );

	ob1 = new(IWEP"sword01");
	ob1->move(this_object());
	wield_weapon(ob1);

	ob2 = new(IOBJ"plate01");
	ob2->move(this_object());
	equip_armor(ob2);
	
	ob3 = new(IOBJ"bag");
	ob3->move(this_object());
}
