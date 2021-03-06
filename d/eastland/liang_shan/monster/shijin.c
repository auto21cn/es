#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("Shi Jin","史进");
    add("id",({"shi","jin"}) );
    set_short("史进");
	set_long(@C_LONG
外号九纹龙，华阴县人，肩膊胸膛上共刺有九条绣纹青龙。重义气，轻钱财，
精擅棍法，目前为梁山马军大骠骑兼先锋使。他最近得到了一根新棍子，正拿
在手上把玩。
C_LONG
	);
    set("alignment",400);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",25);
    set_perm_stat( "int",20);
    set_perm_stat( "pie",25);
    set_perm_stat( "karma",23);
    set_skill("blunt",90);	
    set_skill("parry",90);
    set ("max_hp",520);
    set ("hit_points",520);
    set ("max_fp",1000);
    set ("force_points",1000);
    set ("time_to_heal",5);
    set ("wealth", ([ "gold":280]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(45,25);
	set ("aim_difficulty",([ "weakest":40,"vascular":40]) );
	set("special_defense", (["magic":40,"none":20]) );
    set ("weight", 400);
    equip_armor(TARMOR"iron_plate");
    wield_weapon(TWEAPON"elemental_staff");
    equip_armor(TARMOR"mirror");
    equip_armor(TARMOR"white_robe");
    equip_armor(TARMOR"silk_hood");
}

