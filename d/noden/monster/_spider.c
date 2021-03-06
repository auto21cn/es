#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(1);
	ob->set_name( "green spider", "绿蜘蛛" );
	ob->add( "id", ({ "spider" }) );
   ob->set_short( "绿蜘蛛" );
	ob->set_long(
		"你看到一只绿色的大蜘蛛，这种蜘蛛并不会结网，它们是专靠快速的行动\n"
		"与强有力的肢体捕食小动物，这只蜘蛛的体型颇大，它看起来好像饿了。\n"
	);
   ob->set( "race", "insect" );
	ob->set_perm_stat( "dex", 2 );
	ob->set( "alignment", -300 );
	ob->set( "aggressive", 1 );

	ob->set( "unit", "只" );
	ob->set_c_verbs( ({ "%s张著两只大牙，往%s咬下", "%s用毛茸茸的前肢往%s一刺" }) );
	ob->set_c_limbs( ({ "头部", "身体", "腿部" }) );
}
