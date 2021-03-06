
#include "../../layuter.h"

inherit MONSTER;

void create()
{
	object ob1; 
	::create();
	set_level(19);
	set_name( "fire chilin", "火麒麟" );
	add ("id", ({ "chilin" }) );
	set_short( "火麒麟" );
	set_long(@C_LONG
火麒麟是一种远古的凶兽，当他出现之时，四方神火都会聚集在它的身旁形成
一种天然的屏障，而且秉性凶残，只要任何生物一靠进它的身旁大都死在它的利牙
之下，是一只不可轻侮的猛兽。
C_LONG
	);
    set("killer",1);
    set("pursuing",1);
    set( "alignment",-1000);
    set( "gender", "male" );
    set( "unit", "只" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 30);
	set_skill("shortblade",100);
	set_skill("dodge",100);
	set("special_defense", (["sleet":-25,"none":60,"fire":100]) );
	set ("max_hp", 800);
	set ("hit_points", 800);
	set ("wealth", ([ "gold": 35 ]) );
	set_natural_weapon(30,25,30);
	set_natural_armor(100,50);
	set("natural_weapon_class2",70);
	set ("natural_min_damage2", 25);
	set ("natural_max_damage2", 45);
    set ("weight", 400);
    set ("unbleeding",1);
    
	ob1 = new(Lditem"teeth");
	ob1->move(this_object());
	wield_weapon(ob1);    
}
