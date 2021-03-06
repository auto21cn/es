#include "../echobomber.h"

//inherit EXPLORE;
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	seteuid(getuid());
	set_name( "Gigger", "齐格" );
	add ("id", ({ "gigger", }) );
	set_short( "Dwarf royal mage Gigger", "矮人宫廷魔法师齐格" );
	set_long(
	"矮人宫廷魔法师齐格. 一个老资格的魔法师. 已经为了莫拉德王国贡献出\n"
	"他的一生, 以他的魔法守护著这个古老的矮人王国.\n"
	);

    set("alignment",-100);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "dex", 22 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "karma", 20);
	set_skill("dodge",100);
	set_skill("target",100);
    set_skill("elemental",100);
    set_skill("black-magic",100);
    set_skill("concentrate",100);
	set("magic_delay",1);
	set("spells/sleet",4);
    set("spells/fireball",4);
    set("special_defense", (["all":30,"none":40]) );
	set ("aim_difficulty",([ "vascular": 25, "weakest":20 ]) );
	set ("wealth", ([ "gold": 25 ]) );
	set_natural_weapon( 35, 15, 20 );
	set_natural_armor( 60, 55 );
    set("echo_dwarfsoldier",1);
    set( "tactic_func", "cast_spell");
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("echo_dwarfsoldier") ) return 1;
    return 0;
}

int cast_spell()
{
    object victim,*guard;
    string name;
    int i;
    
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room( environment(this_object()), 
        guard[i]->query("c_name")+"为了帮助夥伴而开始攻击你!\n", guard[i]
      );
      guard[i]->kill_ob(victim);
    }
    
    if( random(10) < 3 ) {
      command("cast sleet on "+name);
      return 1;
     }
    else if (random(10)< 3) {
      command("cast fireball on "+name);
      return 1;
      }
    else return 0;   
}

