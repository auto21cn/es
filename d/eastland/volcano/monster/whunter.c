#include "../oldcat.h" 

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(14);
	set_name( "The hunter", "矮灵族猎头者" );
	add( "id", ({ "hunter" }) );
	set_short( "矮灵族猎头者" );
	set_long(
          "他是一个冷酷的猎人，负责找到每年祭拜火神所需的祭品。\n"
	);
	set( "max_hp", 400 );
	set( "hit_points", 400 );
	set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "kar", 20 );
	set_skill( "axe",80);
	set_skill( "parry", 80 );
	set_skill( "dodge", 80 );
	
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", -500 );
	set( "natural_armor_class", 45 );
	set( "natural_defense_bonus", 30 );
	set( "wealth/gold", 15 );
        set( "killer",1);
        set( "chat_chance", 15);
        set( "att_chat_output",({
             "猎头者向你说：对不起，猎你的项上人头也是不得已的。\n"
             }) );
//        set( "moving",1);
//        set( "speed", 30);

        ob1=new(OWEAPON"waxe");
        ob1->move( this_object() );
	wield_weapon(ob1);
        equip_armor(OARMOR"mail3");
}
