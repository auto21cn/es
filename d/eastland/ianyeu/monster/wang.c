#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "wang wuu", "王五" );
   add( "id", ({ "wang", "wuu" }) );
   set_short( "王五" );
	set_long(
        "一位年约三十, 看起来穷困潦倒的中年人.\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
   set_perm_stat( "dex", 8 );
   set_skill( "dodge", 50 );
   set( "natural_weapon_class1", 15 );
   set( "natural_min_damage1", 12 );
   set( "natural_max_damage1", 25 );
   set( "wealth/copper", 1 );
   set( "chat_chance", 12 );
   set( "chat_output", ({
        "王五叹道: 采花贼(burglar)又回来了! 不知道那家姑娘要受害了!\n",
        "王五自语: 幸好我尚未娶妻.\n"
	}) );
   set( "inquiry", ([
        "burglar" : "郭长老正调查此事, 你去问他老人家吧!\n"
     ]) );
}
