
#include "saulin_war.h"

inherit War;

void create()
{

        ::create();
        set_level(17);
        set_name( "Arch bishop of evil", "玄阴教主" );
        add ("id", ({ "bishop", "arch", }) );
        set_short( "玄阴教主" );
        set_long(@C_LONG
他是崇拜邪恶阴神的玄阴教教主阴玄冰，生平作恶多端，残害生灵不计其数，
最震憾人心的是两年前的数十名孕妇惨遭剖腹取子的血案，他也因为这件惨案
而遭全天下正派人士的追缉。
C_LONG
                 );
	set("alignment",-2000);
	set( "gender", "male" );
	set( "race", "daemon" );
	set( "unit", "个" );
	set("monk_value",80);
        set_perm_stat( "str", 20 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 25 );
        set ("wealth", ([ "silver": 200 ]) );
        set_natural_weapon(18,13,22);
        set_natural_armor(30,40);
        set("special_defense",(["all":40,"none":30]) );
        set("aim_difficulty",(["critical":15,"weakest":15,"vascular":15]) );
	set ("weight", 400);
	set_skill("mace",98);
	set_skill("parry",70);
        wield_weapon(Obj"snake_staff");
	equip_armor(Obj"ice_cloth");
	equip_armor(Obj"ice_cloak");
        equip_armor(Obj"ice_amulet");
	set( "tactic_func", "cast_spell");
}

void report( object attacker, object victim )
{
   string c_message;
   seteuid(getuid());
   c_message= "/adm/daemons/statsd"->c_status_string(victim);
   tell_object( victim,
      "( 你"+c_message+" )\n"
   );
}

int cast_spell()
{
    object victim;
    string c_name;
    if( !(victim = query_attacker()) ) return 0;

    c_name= victim->query("c_name");

    if( random(10) < 4 ) {
      tell_room( environment(this_object()), 
        "\n玄阴教主喷出出一团冰雾，罩向"+c_name+"\n\n"
       );
      victim->receive_special_damage("ice", 23+random(12));
      report(this_object(),victim);
      return 1;
    }
    return 0;
}
