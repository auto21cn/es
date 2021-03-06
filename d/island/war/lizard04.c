#include "../island.h"

inherit IWAR"i_warvalue";
void create()
{
	::create();
	set_level(17);
	set_name( "Lizardman Knight","蜥蜴人骑士" );
	add( "id", ({ "lizardman","knight" }) );
	set_short( "蜥蜴人骑士" );
	set_long(@LONG
    你看到的是蜥蜴人正规军，也就是蜥蜴人军队中战斗力最强的一
支。虽然蜥蜴人是很友善的一个种族，但是它们绝不轻言与敌人妥协，
所以你最好不要成为它的敌人。
LONG
		);
	set( "unit","名" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment",-300 );
	set_natural_armor( 59,20 );
	set_natural_weapon( 38,13,25 );
	set( "special_defense",
	([ "fire":20,"cold":15,"none":30 ]) );
	set( "aim_difficulty",
	([ "critical":75,"vascular":70,"weakest":50,"ganglion":100 ]));
	set( "stun_difficulty",60 );
	set( "wealth/silver",710 );
	set( "killer",1 );
        set( "justice",12 );
	set( "tactic","assault" );
	set_perm_stat( "str",25 );
	set_perm_stat( "dex",20 );
	set_skill( "jousting",90 );
	set_skill( "parry",90 );
	set_skill( "tactic",90 );
	set_skill( "block",90 );
	set_skill( "dodge",70 );
	set( "chat_chance",20 );
	set( "att_chat_output",({
	"\n蜥蜴人骑士大叫：你真是太天真了，蜥蜴人军团是无人能挡的！\n\n",
	"\n蜥蜴人骑士：我们的骑士军团就快到了，快快弃械投降吧！\n\n" }) );
	wield_weapon( IWARO"lance1" );
	equip_armor( IWARO"shield1" );
	equip_armor( IWARO"boots1" );
	equip_armor( IWARO"bracer1" );
	equip_armor( IWARO"plate1" );
}