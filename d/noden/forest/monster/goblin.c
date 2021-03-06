#include "../forest.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name("goblin", "小恶鬼");
        add( "id", ({ "goblin" }) );
        set_short("小恶鬼");
        set_long(@LONG
它是一种矮小, 红眼尖耳, 有点类似猴子的类人生物。当然, 它们比猴子聪明
多了。光是从它们可以使用武器这点来看, 对初出茅庐的冒险者而言算是相当危险
的敌人。
LONG
        );
        set( "unit", "只" );
        set( "gender", "male" );
        set_natural_armor( 25, 10 );
        set_natural_weapon( 8, 3, 5 );
        set( "alignment", -100 );
        wield_weapon(OBJ"small_dagger");
}

void die()
{
		if( random(10) == 1 ) set("wealth/gold", 2);
		else set("wealth/silver", random(10));
		::die();
}
