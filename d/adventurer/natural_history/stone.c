#include <mudlib.h>

inherit "/d/eastland/liang_shan/magic";
inherit OBJECT;

void init()
{
	add_action( "throw_stone", "throw" );
}

void create()
{
	set_name("stone","小石子");
	set_short("小石子");
	set_long(
		"一颗随处可见的小圆石，看来蛮硬的，拿它来丢人一定很痛的。\n"
	);
   	set("unit","颗");
   	set("weight", 10);
   	set("value",({ 1, "silver" }) );
}
int throw_stone(string arg)
{
        string s1,s2;
        object target,owner;

        if (!arg) {
                return notify_fail(
                        "把什麽丢去那?\n");
                }
        sscanf(arg, "%s to %s", s1, s2);
        if ((!s1) || (lower_case(s1) != "stone"   )) {
                return notify_fail( 
                        "你要丢什麽呢?\n");
                }
        if (!s2) {
                return notify_fail( 
                        "你要拿石头丢谁?\n");
                }

        target = present(s2,environment(this_player()));
        
        if ( (!target) ||
                ( environment(target)!=environment(this_player()) ) ) {
                return notify_fail( 
                        "他并不在这儿唷!\n");
                }
        if ( target->query("no_attack") ) {
                 return notify_fail("这家伙－不能杀。\n");
                }
        if ( userp(target) ) {
                     if ( (int)target->query_level()< 5 ||
                      (int)this_player()->query_level()<5 )
                     return notify_fail("你不能 PK 他 !!\n");
                     }
        
        if (target == this_player()) {
                return notify_fail( 
                        "拿石头丢自己?\n");
                }
		write("你很用力的把石头丢向"+target->query("c_name")+"。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+
			"从怀中掏出一颗石头，很用力的丢向"+target->query("c_name")+"\n" , this_player()
		);
		target->receive_damage( this_player()->query_perm_stat("str")/2+random(5) );
                this_player()->gain_experience(20);
                this_player()->add("alignment",-10);
                target->set("last_attacker",this_player());
                target->kill_ob(this_player());
                report(this_player(),target);
	remove();
	return 1;
}
