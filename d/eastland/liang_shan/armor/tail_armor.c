#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "ancient tail armor", "蚩尤尾甲" );
	add( "id", ({ "tail","armor" }) );
	set_short( "蚩尤尾甲" );
	set_long(
		"这是一套泛著奇怪光泽的尾甲，相传是古时蚩尤大战黄帝时所穿\n"
	        "著，不但拥有非凡的防御力，似乎还有其他不为人知的力量。\n"
	);
	set( "unit", "套" );
	set( "type", "tail" );
        set("material","leather");
	set( "weight", 120 );
	set("armor_class",10);
	set("defense_block",4);
	set( "value", ({ 320, "gold" }) );
}
int stop_equip()
{
   object holder;	
	holder=this_player();
       if ((int)holder->query("alignment")>-1200)
        {
        tell_room( environment(holder), 
         holder->query("c_cap_name")+"想要穿上蚩尤尾甲，但尾甲突然猛烈跳动而不受控制。\n"
		, ({holder}) );
        tell_object( holder,
         "你想要穿上蚩尤尾甲，但尾甲发出强大的邪恶抗力使你无法如愿。\n");
		return 1;
	}
        return 0;
}
