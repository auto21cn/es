#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "fox", "狐狸" );
	add( "id", ({ "fox" }) );
	set_short( "狐狸" );
	set_long("这是一种传闻中很狡滑的动物，不过近看道还满可爱的。\n");	
	set("unit","只");
    set( "alignment", 200 );
	set_perm_stat( "dex", 10 );
	set_c_verbs( ({ "%s，用嘴咬向%s", "%s用前爪往%s抓下" }) );
	set_c_limbs( ({ "头部", "身体", "脚部","尾巴" }) );
#include <replace_mob.h>
}
