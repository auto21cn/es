#include <mudlib.h>

inherit WEAPON ;

void create()
{
	set_name("holy blade", "少林戒刀");
	add ("id", ({ "holy","blade" }) );
	set_short( "少林戒刀" );
	set_long(
		"这是少林的戒律院执事僧所惯用的兵器 一般人称之为戒刀\n"
	);
	set("type", "longblade");
	set("weapon_class", 25);
	set("min_damage", 12);
	set("max_damage", 25);
	set("weight", 150);
	set("value", ({ 500, "silver" }) );
	set_c_verbs( ({
		"%s从一个奇怪的角度砍了出来，砍在%s",
		"%s从上向下直劈 劈向%s",
		"将%s挥成一片刀幕，伤到%s",
		"手中的%s卷起一阵呼呼的风声，刺在%s",
	}) );
}
