#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;

	ob->set_level( 5 );
	ob->set_name( "boarman leader", "野猪人领袖" );
	ob->add( "id", ({ "boarman", "leader" }) );
        ob->set_short( "野猪人领袖" );
	ob->set_long(
		"这个野猪人长得很「凶猛」，满脸横肉，绿豆般大的眼睛却精神亦亦地\n"
		"打量著你这个不速之客。\n"
	);
	ob->set( "gender", "male" );
	ob->set_perm_stat( "str", 8 );
	ob->set_perm_stat( "con", 8 );
	ob->set( "max_hp", 100 );
	ob->set( "hit_points", 100 );
	ob->set_skill( "axe", 50 );
	ob->set_skill( "parry", 30 );
	ob->set( "natural_armor_class", 20 );
	ob->wield_weapon("/d/noden/recamp/obj/axe");
	ob->equip_armor("/d/noden/recamp/obj/chainmail");
}
