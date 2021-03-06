#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("tiger finger","手指虎");
       add("id",({"finger","tiger"}) );
       set_short("手指虎");
       set_long(
       "手指虎其实就像是有刺的手套，可以以此攻击敌人，但由於使用他的\n"
       "人必需与敌人贴身肉搏，因此不论攻击敌人或自身遭受攻击都较平常来的\n"
       "严重许多。也因此，较强的山贼特别偏爱这种武器。\n"
	);
	
	set( "unit", "套" );
 	set("block_tactic",0);
 	set( "weapon_class", 17 );
        set("type","unarmed");
	set( "min_damage", 10 );
	set( "max_damage", 19 );
	set( "nosecond", 1 );
	set( "weight", 65 );
	set("bleeding",2);
	set( "value", ({ 42, "gold" }) );
	set( "wield_func","wield_finger" );
	set( "unwield_func","unwield_finger" );
}	
