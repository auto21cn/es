#include "../hole.h"

inherit ENEMY;
void create()
{
	::create();
	set_level(16);
	set_name( "Lizardman Lifeguard", "蜥蜴人禁卫军" );
	add( "id", ({ "lizardman","guard","lifeguard" }) );
	set_short( "Lizardman Soldier", "蜥蜴人禁卫军" );
	set_long(@LONG
    你看到的是一位保卫王宫的卫兵。
LONG
		);
	set( "unit","名" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment",500 );
	set( "wealth/silver",300 );
	set_natural_armor( 40,25 );
	set_natural_weapon( 20,5,8 );
	set_perm_stat( "str",20 );
	set_perm_stat( "dex",20 );
	set_skill( "shortblade",90 );
	set_skill( "jousting",90 );
	set_skill( "tactic",90 );
	set_skill( "parry",90 );
	set( "tactic","melee" );
	set( "chat_chance",10 );
	set( "att_chat_output",({
	"蜥蜴人卫兵说：别在这里屠杀我族人，否则我不会放过你的！\n",
	"蜥蜴人卫兵说：没事的别在这里逗留，去别的地方赚经验值吧！\n" }) );
	wield_weapon( HWEAPON"lance2" );
	equip_armor( HARMOR"tail2" );
	equip_armor( HARMOR"plate8" );
}