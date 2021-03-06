#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "little boy", "小男孩" );
	add( "id", ({ "boy" }) );
	set_short( "小男孩" );
	set_long(
		"这个小男孩有黑色的眼珠和红色的头发，他看起来饿了许多天，眼中流露出\n"
		"害怕的眼神。\n"
	);
	set_skill( "dodge", 10 );
   set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 1000 );
	set( "alt_corpse", "/d/noden/house/monster/devil" );
	set( "chat_chance", 10 );
	set( "chat_output", ({
		"小男孩说道: 陪我玩游戏好吗？\n",
		"小男孩好奇地打量著你。\n",
		"小男孩愉快地对著你微笑。\n"
	}) );
	set( "inquiry", ([
		"name" : "我....没有名字，爸爸妈妈在我出生的时候就死了....\n" 
	]) );
}

void die()
{
	tell_room( environment(this_object()), 
		"小男孩咳出几口鲜血，倒在地上 ....\n\n"
		"你听到一阵沙哑的声音从小男孩的尸体发出: 「你以为这样就完了吗？休想！」\n\n"
		"小男孩的尸体又站了起来！\n\n" ,
		this_object() );
	::die(1);
}
