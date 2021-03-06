#include <mudlib.h>

inherit OBJECT;
#include "/d/mage/tower/detect-magic.h"
#define USE_SP 20
int do_use(string str);

void create()
{
		//seteuid( getuid() );
	    set_name( "crystal orb", "水晶球" );
        add( "id", ({ "orb"}) );
        set_short( "水晶球" );
//        set_long(@LONG
//			这是一颗水晶球，光线照射进球内，发散出五彩的光芒。使你不禁想使用(use) 看看。
//			LONG );
	set_long(@LONG
这是一颗水晶球，光线照射进球内，发散出五彩的光芒。使你不禁想使用(use) 看看。
LONG);
        set("unit","颗");
        set("weight", 20);
        set( "value", ({ 20, "silver" }) );
        set("no_sale",1);

}

void init()
{
        add_action( "do_use", "use" );
}

int help ()
{
return notify_fail( "指令格式: use orb to identify 〈防具〉 \n");
}

int do_use(string str)
{
	int num;
	string this1,class1;
	object dest;
	if (!str) return help();
	class1 = (string)this_player()->query("class");
	if(!( wizardp(this_player()) || class1=="mage" || class1=="necromancer" ||
		class1=="sage")) {
		write("你不是魔法师，不知道如何使用这个水晶球。\n");
    		return 1;
	}	
	if (this_player()->query("spell_points") < USE_SP){
		write ("你的法力不够！\n");
		return 1;
	}
	if (!this_player()->query("vision")) {
		write("你什麽也看不见。\n");
		return 1;
	}
	if (sscanf(str, "orb to identify %s", this1) == 1){
		if ( !dest= present( this1, this_player() ) )
			return notify_fail( "你没有这样东西。\n");
		num=this_player()->query_skill("identify");
		this_player()->add("spell_points", -USE_SP );
	write("你运用法力使用水晶球，水晶球发出了一阵异样的光芒。\n");
	tell_room(environment(this_player()),this_player()->query("c_name")+"身上的水晶球发出了一阵异样的光芒。\n",this_player());
		write(identify_armor(dest,num));
		return 1;
	}
	return help();
}

