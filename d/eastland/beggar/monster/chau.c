#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "chau", "赵无极" );
	add( "id", ({ "chau" }) );
	set_short( "赵无极" );
	set_long(@C_LONG
赵无极说是年纪很老,似乎倒也不老,说他年纪轻,却又全然不轻, 总之是三十岁到
七十岁之间,相貌说丑不丑,说俊不俊。一副神经兮兮的样子,整天口里念念有词谁
也不知道他到底在念什麽? 
C_LONG	
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -1200 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "kar", 20 );
        set_perm_stat( "dex", 30 );
	set_skill( "parry", 50 );
        set_skill( "block", 50 );
	set_skill( "dodge", 50 );
        set_skill( "unarmed", 50 );
        set("special_defense", ([ "all": 35,"none":40]) );
        set( "aim_difficulty",([ 
               "critical":60,"weakest":40,"ganglion":50,"vascular":80 ]) );
	set( "wealth/gold", 110 );
        set( "hit_points", 480);
        set( "max_hp", 480);
        set("max_fp", 400);
        set("force_points", 400);
        set("force_effect", 5);
        set_natural_armor(65,55);
        set_natural_weapon(55,23,33);
        equip_armor(DARMOR"chau_cloth");
        set("chat_chance",5);
        set("chat_output",({
          "赵无极喃喃自语说道:原来如此,原来如此。早知这般,悔不当初。受她打几掌,又有何难?\n"
        }) );
        set_c_verbs( ({ "%s使了一招『偷龙转凤』向%s递了过去",
                        "%s祭出一式 『大江东去』砍向%s",
                        "%s两支手摇摇不定地向%s偷袭"
        }) );
}
int stop_attack()
{
	object slave, *tmp;

	slave = present( "donkey", environment() );
	if( !slave ) return 0;
	tell_room( environment(),
                "大笨驴说道:竟敢攻击我的主人，不要命了！\n" 
		"大笨驴向你扑了过来。\n"
	);
	tmp = query_temp( "protectors" );
	if( !tmp || member_array( slave, tmp )==-1 ) {
		add_temp( "protectors", ({ slave }) );
		slave->add_temp( "protectees", ({ this_object() }) );
	}
	tmp = slave->query_attackers();
	if( !tmp || member_array( this_player(), tmp )==-1 )
		slave->kill_ob( this_player() );
}
void init()
{
    ::init();
    add_action("do_mount","mount");
}
int do_mount(string arg)
{
     object me;
     me=this_player();
     if (!(me->query("class")=="knight"))
        return 0;
     tell_object(me,"赵无极说道:ㄟ想偷我的驴子啊?\n");    
     return 1;
}