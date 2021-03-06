#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "Zhuan Shiao Chi", "阮小七" );
	add("id",({"zhuan","shiao","chi"}));
	set_short( "阮小七" );
	set_long(
		"阮小七外号活阎罗，小二，小五是他哥哥，本以打鱼维生，兄\n"
		"弟三人随吴用落草，现俱为水军头领．他现在正在找他哥哥小二，似\n"
		"乎有什麽事情。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -80 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 11 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 25 );
	set_skill( "dodge", 40 );

	set( "wealth/gold", 30 );
	set( "special_defense", (["all": 16 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 25, 8 );
        set( "inquiry",([
        "whirl" : "@@ask_whirl",
        "brother" : "@@ask_brother"
        ]));
	wield_weapon( TWEAPON"fishman_dagger" );
        equip_armor( TARMOR"hat");
        equip_armor( TARMOR"fish_skin");
}
void ask_whirl()
{
write(
"阮小七说道: 湖边的渔民们有一个传说，在湖的最深处住著一只千年的大河蚌\n"
"当它在用水管吸水时，就产生了湖中的漩涡，详情是如何我也不清楚....\n");
return 0;
}
void ask_brother()
{
write(
"我哥哥阮小二前天说他在湖中发现了一个大秘密，昨天他一个人到湖里\n"
"结果到现在都不见人影，真是令人担心....\n");
return 0;
}
