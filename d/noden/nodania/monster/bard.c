#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level(14);
	set_name( "Minaceus", "米娜修斯" );
	add( "id", ({ "minaceus", "bard" }) );
	set_short(  "流浪诗人米娜修斯" );
	set_long(@CLONG
米娜修斯是诺达尼亚著名的吟游诗人，她优雅的歌声和美丽的脸庞不知道
风靡了多少王公贵族，但是她宁愿一个人自由自在的到处旅行，因为她认
为世界上没有比四处旅行和音乐更令人陶醉的事。
CLONG
	);
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 22 );

	set( "race", "elf" );
	set( "gender", "female" );
	set( "wealth/silver", 220 );
	set( "alignment", 400 );

	set_skill( "dagger", 90 );
	set_skill( "dodge", 70 );
	set_skill( "parry", 40 );
	set( "natural_armor_class", 55 );
	set( "natural_defense_bonus", 24 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 8 );

	ob1 = new("/d/noden/nodania/obj/ivory_dagger");
	ob1->move(this_object());
	wield_weapon(ob1);

	ob2 = new("/d/noden/nodania/obj/white_suit");
	ob2->move(this_object());
	equip_armor(ob2);

	ob3 = new("/d/noden/nodania/obj/white_cape");
	ob3->move(this_object());
	equip_armor(ob3);
}
