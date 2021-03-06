#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level( 4 );
	ob->set_name( "orc rogue", "半兽人流氓" );
	ob->add( "id", ({ "rogue", "orc" }) );
	ob->set_short( "半兽人流氓" );
	ob->set_long(
		"这个半兽人长得又凶又丑，专门喜欢欺负弱小。\n"
	);
	ob->set_perm_stat( "str", 7 );
	ob->set_perm_stat( "int", 1 );
	ob->set_perm_stat( "kar", 2 );
	ob->set_skill( "unarmed", 40 );
	ob->set( "alignment", -700 );
	ob->set( "natural_weapon_class1", 5 );
	ob->set( "natural_min_damage1", 3 );
	ob->set( "natural_max_damage1", 6 );
	ob->set( "wealth/copper", 80 );
	ob->set( "chat_chance", 10 );
	ob->set( "chat_output", ({
		"半兽人流氓大叫: 把你的钱交出来，不然我揍你。\n",
		"半兽人流氓在你面前展示它的肌肉。\n",
		"半兽人流氓说道: 快一点，老子今天没什麽耐心。\n"
	}) );
}
