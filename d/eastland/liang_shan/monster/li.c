#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("Li Kui ","李逵");
    add("id",({"li","kui"}) );
    set_short("李逵");
	set_long(@C_LONG
外号黑旋风，沂州沂水县人，一身横练筋肉，胸前一片黑毛，梁山好汉要数他最好
杀人，行为粗鲁，使一蚩尤七杀斧，目前为梁山步军大统领之一。
C_LONG
	);
    set("alignment",-1000);
    set( "gender", "male" );
    set( "race", "lizardman");
    set( "unit", "个" );
    set_perm_stat( "dex",20);
    set_perm_stat( "str",30);
    set_perm_stat( "int",10);
    set_perm_stat( "karma",30);
    set_skill("axe",90);	
    set_skill("parry",90);
    set ("chat_chance",20);
    set ( "att_chat_output",({
    "李逵叫道: 杀杀杀杀杀杀杀........\n"
        }));
    set ("max_hp",660);
    set ("hit_points",660);
    set ("time_to_heal",2);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(28,18,33);
	set_natural_armor(50,26);
	set ("aim_difficulty",([ "weakest":40,"vascular":50]) );
	set("special_defense", (["magic":40,"none":20]) );
    set ("weight", 400);
    wield_weapon(TWEAPON"flower_axe");
    equip_armor(TARMOR"buddha_hood");
    equip_armor(TARMOR"fur_armband");
    equip_armor(TARMOR"cowskin_boots");
    equip_armor(TARMOR"tail_armor");
    equip_armor(TARMOR"vest");
}

