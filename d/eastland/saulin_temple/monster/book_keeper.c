#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(16);
        set_name( "The library keeper", "掌阁僧" );
        add ("id", ({ "bonze","monk","keeper" }) );
        set_short( "掌阁僧");
        set("unit","位");
        set_long(@DESC
他是一位中年和尚，身材魁梧气度不凡，虽然带著亲切的笑容，但是
看他手迟步涩、太阳穴高高鼓起，就知道他一定是内外兼修的高手，
DESC
        );
        set("alignment",800);
        set("wealth/silver",500);
        set_perm_stat("str", 25);
        set_perm_stat("dex", 25);
        set_perm_stat("int", 29);
        set("max_hp", 600);
        set("hit_points", 600);
        set("max_fp", 200);
        set("force_points", 200);
	set("force_effect",2);
        set_natural_weapon(27, 20, 36);
        set_natural_armor(72, 20);
        set("special_defense", ([ "all" : 30, "none" : 20 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50, ]) );
        set_skill("parry",100);
        set_skill("unarmed",100);
        set ("gender", "male");
        set ("race", "human");
        set ("tactic_func","group_attack");
	set("attack_skill",CLASS"bolo_fist");
	set("monk_gonfu/bolo-fist",80);
        set ("chat_chance",7);
        set ("chat_output",({
          "掌阁僧说道：藏经阁乃是本寺重地，请施主留步。\n"
        }));
        set("att_chat_output",({
          "掌阁僧喝道：施主一意孤行，请恕小僧失礼了!!\n"
        }));
	equip_armor(SAULIN_OBJ"grey_pallium");
	equip_armor(SAULIN_OBJ"necklace01");
}

int check_partner(object obj)
{
   if( obj->query_attacker() ) return 0;
   if( (string)obj->query("name") == "The library Guardian" ) return 1;
   return 0;
}

int group_attack()
{
    object victim,*guard;
    int i;
    victim = query_attacker();
    if (!victim) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "check_partner",this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room(environment(this_object()),
        "守阁僧大喊：大胆狂徒，竟敢擅闯藏经阁！师兄！我来助你 ！！\n");
      guard[i]->kill_ob(victim);
    }
}     

void die()
{
	object killer;
        tell_room( environment(), 
			"\n掌阁僧吐出几口鲜血，大叫道：你会得到报应的 ....\n"
			"\n他从怀里掏出一个黑管向天空掷去，那黑管发出一道尖利的啸声，\n"
			"\n划成一道青色长虹。\n\n"
			,	this_object()
		);
	killer=query("last_attacker");
        find_object_or_load("/adm/daemons/event/saulin")->start_war();
        ::die(1);
}

