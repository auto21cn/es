#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;

	ob->set_level( 4 );
	ob->set_name( "boarman shaman", "野猪人巫医" );
	ob->add( "id", ({ "boarman", "shaman" }) );
        ob->set_short( "野猪人巫医" );
	ob->set_long(
		"唔....嗯....如果你的审美观没有错的话，这位野猪人算是个美女了，她\n"
		"的皮肤比她的同类白，而且毛比较少，至少脖子上的鬃毛比较短....。\n"
	);
	ob->set( "gender", "female" );
	ob->set_perm_stat( "str", 5 );
	ob->set_perm_stat( "dex", 7 );
	ob->set( "max_hp", 80 );
	ob->set( "hit_points", 80 );
	ob->set_skill( "blunt", 40 );
	ob->set_skill( "parry", 30 );
	ob->set( "natural_armor_class", 15 );

	ob->wield_weapon("/d/noden/recamp/obj/staff");
	ob->equip_armor("/d/noden/recamp/obj/cloak");
}
