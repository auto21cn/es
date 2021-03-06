#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(19);
    set_name("Chin Ming ","秦明");
    add("id",({"chin","ming"}) );
    set_short("秦明");
	set_long(@C_LONG
外号霹雳火，开州人，性格急燥，行为勇猛，使一条铁蒺藜骨朵，有万
夫不当之勇。现为梁山泊马军五虎将中第三大将。
C_LONG
	);
    set("alignment",500);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",20);
    set_perm_stat( "str",33);
    set_perm_stat( "int",15);
    set_perm_stat( "karma",25);
    set_skill("blunt",100);
    set_skill("parry",100);	
    set ("max_hp",900);
    set ("max_sp",300);
    set ("hit_points",900);
    set ("spell_points",300);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(60,32);
	set ("aim_difficulty",([ "weakest":50,"vascular":50]) );
	set("special_defense", (["magic":50,"none":20]) );
    set ("weight", 400);
    equip_armor(TARMOR"gold_helmet");
    wield_weapon(TWEAPON"ironclub");
    equip_armor(TARMOR"beastface");
    equip_armor(TARMOR"beast_cloak");
    equip_armor(TARMOR"deer_boots");
    equip_armor(TARMOR"fire_plate");
}

