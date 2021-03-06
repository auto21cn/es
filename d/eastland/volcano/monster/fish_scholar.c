#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "The Scholar", "文臣" );
	add( "id", ({ "scholar" }) );
	set_short( "文臣" );
	set_long(
		"你看到一位长满白胡子的鱼头人身的怪物，他是龙王的咨询对象。\n"
	);
	set( "unit", "名" );
	set( "race", "monster" );
	set( "gender", "male" );
	set( "alignment",  800 );
        set( "likefish",1);
	set( "max_hp", 500 );
	set( "hit_points", 500 );
	set( "special_defense", ([ "all": 40, "none" : 20, ]) );
	set( "aim_difficulty", ([ "critical" : 35, "vascular" : 25, ]) );
	set_natural_armor( 53, 23 );
	set_natural_weapon( 5, 0, 10 );
	set( "wealth/gold", 10 );
	set( "tactic_func", "my_tactic" );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "int", 28 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 23 );
	set_skill( "dodge", 90 );
        set("chat_chance",10);
        set("chat_output",({
         "文臣：龙王最近愁眉深锁，不知道发生了什麽事。\n"
        }) );

	wield_weapon(OWEAPON"dagger03" );
	equip_armor( OARMOR"ring2" ); 
	equip_armor( OARMOR"cloth2" );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers()) ) return 0;
	if( random(20)>2 ) return 0;
	tell_room( environment(this_object()),
	  "文臣口中念道:『阴阳顺逆妙难穷，二至还乡一九宫。』\n"
          "文臣口中念道:『若能了达阴阳理，天地都来一掌中。』\n"
	  "\n突然，四周的水开始急速的旋转，如一大旋涡般的把你卷入其中 !\n"
	, this_object()
	);
	for ( i=0; i < sizeof(victim) ; i++) {
	  victim[i]->receive_special_damage("divine", random(10));
          victim[i]->block_attack(5);
          victim[i]->set_temp("msg_stop_attack",
            "( 你被转得七晕八素的，身体完全不能控制 ! )\n");
        }
	return 1;
}
