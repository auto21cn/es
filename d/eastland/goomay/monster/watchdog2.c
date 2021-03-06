#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "watchdog", "大狼狗" );
	add( "id", ({ "dog" }) );
	set_short( "a watchdog", "大狼狗" );
	set_long(
		"This is a big , terrible watchdog, it is looking at you now .\n",
		"这是一只凶恶的大狼狗，专门对付那些不受欢迎的人，它现在正盯著你看。\n"
	);
        set("unit","只");
        set_natural_armor( 30, 10 );
        set_natural_weapon( 7, 7, 12 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );

	set_c_limbs( ({ "後腿", "前脚", "头部", "尾巴", "身体" }) );
	set_c_verbs( ({ "%s张嘴往%s一咬", "%s用它的爪子抓%s" }) );
	set_skill( "dodge", 60 );
	set( "chat_chance", 15 );
	set( "att_chat_output", ({
		"大狼狗对著你汪汪叫。\n",
		"大狼狗扑到你身上。\n"
	}) );
#include <replace_mob.h>
}
