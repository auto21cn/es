#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(18);
	set_name( "Basge", "巴斯格" );
	add( "id", ({ "basge" }) );
	set_short( "矮灵族酋长 巴斯格" );
	set_long(
	 "酋长巴斯格是矮灵族中的强者，你看他全身肌肉结实，好像充满了精力似的，双眼\n炯炯有神，太阳穴微微隆起，全副武装，手里执著一只权杖，感觉很有威严，为了\n族人他就算牺牲生命也在所不辞。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", -900 );
	set_perm_stat( "str", 30 );
        set_perm_stat( "int", 20 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "kar", 20 );
	set_skill( "blunt", 100 );
	set_skill( "parry", 100 );
        set_skill( "block", 100 );
	set_skill( "dodge", 100 );
        set( "aim_difficulty",([ "critical":80,"weakest":80,"ganglion":80,"vascular":80 ]) );
	set( "wealth/gold", 80 );
        set( "hit_points", 750);
        set( "max_hp", 750);
        set("natural_armor_class",38);
        set("natural_defense_bonus",26);
        set_natural_weapon(8,5,15);
        ob1=new(OWEAPON"w_staff");
        ob1->move( this_object() ); 
	wield_weapon( ob1 );
        equip_armor(OARMOR"mail5");
        equip_armor(OARMOR"legging1");
        equip_armor(OARMOR"shield1");
        equip_armor(OARMOR"armband2");
        equip_armor(OARMOR"helmet1");
        set("chat_chance",15);
        set("chat_output",({
          "酋长说：为了平息火神，为了族人的安危，我们猎人头实在是不得已的。\n",
        }) );
        set("inquiry", ([
            "volcano":"@@ask_volcano",
            "god":"@@ask_god",
            ]) );
}

void ask_volcano(object who)
{
  tell_object(who,
   "酋长说：这座火山实在是我们的最大祸害，想起50年前的爆发，真是让人心悸犹存，不过\n我们族中最有智慧的长老已经在想办法解决这个问题了，希望他能尽早想出来。\n"
  );
}

void ask_god(object who)
{
  tell_object(who,
   "酋长说：在我们族中，大家都相信火山爆发是因为火神发怒的关系，所以我们年年猎人头\n来祭祀火神，在每年特定的日子，在火山顶由巫师将祭品投入火山之中。\n"
  );
}

int stop_attack()
{
	object slave, *tmp;

	slave = present( "wolf", environment() );
	if( !slave ) return 0;
	tell_room( environment(),
                "竟敢攻击我的主人，不要命了！\n" 
		"巴斯格的宠物--暴狼 向你扑了过来。\n"
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
