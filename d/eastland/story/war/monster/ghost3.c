#include "../../story.h"
#include <conditions.h>
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(16);
	set_name( "special ghost", "魉鬼" );
	add( "id", ({ "ghost" }) );
	set_short( "魉鬼" );
	set_long(@LONG
魉鬼长的像个三岁娃娃，通身黑□透红，长耳朵，红眼睛，乌黑光□的长头发，喜
欢学人说话的声音来迷惑人。魉鬼最怕的是一种龙的声音，因为那种声音回环宛转
，会使得它周身胆寒，如痴似醉，丧失战斗力。
LONG
	);
        set( "race","鬼");
	set( "unit", "个" );
	set( "alignment", -300 );
	set_natural_armor(50,25);
	set_natural_weapon(20,7,11);
        set( "special_defense", ([ "all":20,"none":10 ]) );
        set( "aim_difficulty",
           ([ "critical":20, "vascular":20, "weakest":20 ]));
	set( "wealth/silver", 200 );
	set( "killer", 1 );
	set( "pursuing",1);
        set( "unbleeding",1);
        set( "moving",1);
        set( "speed",30);
        set( "war_points", 130 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_skill( "longblade", 100 );
	set_skill( "parry",60 );
	set_skill( "dodge", 60 );
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"scythe1");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),"魉鬼发出迷惑人的声音！\n");
    (CONDITION_PREFIX + "confused")->apply_effect( victim, 5, 10 );          
    hurt_all("evil",45);
    return 1;    
}
