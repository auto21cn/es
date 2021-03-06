#include <../goomay.h>


inherit SELLER ;
inherit Mob_special;

void create()
{
	::create();
	set_level(4);
	set_name( "flower girl", "卖花女" );
        add ("id",({ "girl"}));
	set_short( "卖花女" );
	set_long(
		"她是一个看起来很清秀的卖花女，如果你有需要的话，可以向她买花，只要\n"
		"问她关於花(flower)的事，她就会很乐意地向你介绍她的花。\n"
	);
	set( "race", "elf" );
	set( "gender", "female" );
	set_inventory( ({
		({ Obj"petals", 10, 10 }),
		({ "/d/std/flowers/red_rose", 10, 10 }),
        ({ "/d/std/flowers/yellow_rose", 10, 10 }),
		({ "/d/std/flowers/tuberose", 10, 10 }),
        ({ "/d/std/flowers/pansy", 10, 10 }),
        ({ "/d/std/flowers/lili", 10, 10 }),
        ({ "/d/std/flowers/ironweed", 10, 10 }),
        ({ "/d/std/flowers/laurel", 10, 10 }),
	}) );

	set( "inquiry", ([
		"flower" : "@@show_menu"
	]) );
        set_natural_weapon( 5, 4, 9 );
        set_natural_armor( 40, 20 );
        set_c_verbs(({"%s用指甲抓向%s","%s用花篮砸向%s","%s用脚踹向%s"}));
        set("special_attack",(["damage_type" : "magic","main_damage" : 6,
				"random_dam" : 4 , "hit_rate" : 15]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "卖花女用她的花篮往你的腰间砸来..\n\n");
set("c_room_msg","卖花女像疯了似的用花篮乱砸");
set("c_room_msg2", "，把他打得哎哎叫 ...\n");

}

void init()
{
	seller::init();
	mob_special::init();
}