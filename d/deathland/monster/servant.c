#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	::create();
 set_level(7);
 set_name("servant","仆人");
 set_short("a servant","仆人");
 set_long(@LONG
A servant is busy.
LONG
    ,@C_LONG
一个忙忙碌碌的仆人.
C_LONG
	);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "个" );
    set_perm_stat( "dex",6);
    set_perm_stat( "str",12);
    set_perm_stat( "int",4);
    set_perm_stat( "con",20);
    set_perm_stat( "piety",2);
    set_perm_stat( "karma", 5);
	
   set ("max_hp",220);
   set ("max_sp",0);
   set ("hit_points",220);
   set ("spell_points",0);
   set ("wealth", ([ "silver": 160]) );
    set_natural_weapon(5,1,5);
	set_natural_armor(39,0);
    set("weight", 350);
    
    wield_weapon(Weapon"/dagger01");
}


