#include "../island.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(2);
        set_name( "squirrel", "松鼠" );
        add( "id", ({ "squirrel" }) );
        set_short( "松鼠" );
        set_long(@LONG
你看到一只有著长长尾巴，灵活大眼睛的小动物在枝头间跑来跑去。
LONG
);
        set( "unit", "只" );
        set_perm_stat("kar", 3 );
        set_perm_stat("dex", 5 );
        set_natural_weapon(4,2,3);
        set_natural_armor(7,0);
        set_c_verbs( ({ "%s用爪子往%s抓去" }) );
        set_c_limbs( ({ "头部", "身体", "腿部", "尾巴" }) );
}
