#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("blade of hell", "修罗刀");
	add ("id", ({ "hell","blade" }) );
	set_short( "修罗刀" );
	set_long(@C_LONG
这是达摩院首席虚渡大师最锺爱的兵器，相传它原本是某位江洋大盗的兵器，
不知道已经沾染了多少鲜血，最後他被大师感化，於是将这把刀送给大师，大
师也以此刀自戒自勉。
C_LONG
                 );
	set("type", "longblade");
	set("weapon_class", 35);
	set("min_damage", 20);
	set("max_damage", 37);
	set("weight", 200);
	set("value", ({ 755, "silver" }) );
	set("no_sale", 1);
}
