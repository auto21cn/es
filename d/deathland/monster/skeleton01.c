#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "skeleton black knight", "骇骨族黑武士" );
	add("id",({"skeleton","knight",}));
	set_short( " a skeleton black knight", "骇骨族黑武士" );
	set_long(
		"a terrible skeleton knight.\n"
		"一个令人惧怕的骇骨族黑武士,残忍嗜杀,冷酷无情,\n"
		"最可怕的是一击必杀的可怕必杀技.\n"
	);
	set( "gender", "male" );
	set( "alignment", -2000 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "kar", 30 );
	set_skill( "dodge", 100 );
	set_skill( "parry", 100 );
	set_skill( "longblade",100 );
	set_natural_armor(110,0);
 	set_natural_weapon(45,25,55);
    set( "special_defense", (  ["all":60, "none": 55,"divide":-40,"fire":-30]  ) );
    set ("aim_difficulty",([ "critical":33,"weakest":32 ]) );
    set("unbleeding",1);
    set("killer",1);
    set( "tactic_func", "my_tactic");	
    wield_weapon(Weapon"/sword05");
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "骇骨族黑武士看准你的弱点快.准.狠.地猛击你.\n" );
      tell_room(environment(this_object()),
          "骇骨族黑武士快.准.狠.地猛击"+victim->query("c_name")+".\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 75 + random(55) );
      report(this_object(),victim);
      return 1;
      }
}
