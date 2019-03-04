#include "../story.h"

inherit SMOB"pmob";
void create()
{
	::create();
        set_level(19);
        set_name( "Blue-Face scorpio's tail", "人面蓝蝎" );
        add( "id", ({ "tail","scorpio" }) );
        set_short( "人面蓝蝎的尾部" );
        set_long(@C_LONG
你眼前所见的是只体型巨大无比，全身泛出紫蓝色的蝎子，它的尾部比起前半身足
足大有一倍！末端的螯刺更是大的骇人，它不时用螯刺在你面前晃啊晃的，一付挑
衅的样子。
C_LONG
        );
	set("tail",1);
	set("pname","人面蓝蝎");
	set( "alignment", -1000 );
        set_skill("dodge",100);
        set("hit_points",2000);
        set("max_hp",2000);
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 30 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "pie", 25 );
        set_natural_armor(10,45);
        set_c_limbs( ({ "螯刺", "尾部"}) );
}
