#include "saulin_monk.c"

void create()
{
	::create();
	set_level(13);
	set_name( "guan ming", "观明" );
	add ("id", ({ "ming", "guan","monk" }) );
	set_short( "观明" );
	set_long(@C_LONG
观明是一个在少林长大的孩子，他从不知红尘人世为何，只是一直念经习武。
他生性开朗随和，一套韦陀拳却也打的虎虎生风。
C_LONG
       	        );
    set( "alignment",1200);
    set( "gender", "male" );
    set( "race", "halfling" );
    set( "unit", "位" );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "str", 14 );
	set_perm_stat( "int", 14 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 14);
	set_perm_stat( "karma", 13);
	set_skill("unarmed",100);
	set_skill("dodge",75);
        set_skill("inner-force",100);
	set("special_defense", ([ "all":15, "none":10 ]) );
	set("max_fp", 400);
	set("force_effect", 2);
	set("force_points", 400);
        set("attack_skill",FIST"wei_to");
	set("wealth/gold", 44);
	set_natural_weapon( 15, 12, 24 );
	set_natural_armor( 40, 15 );
        set("weight", 400);
    equip_armor( SAULIN_OBJ"cloth5a" );
}
