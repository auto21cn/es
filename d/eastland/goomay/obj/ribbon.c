#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "pink ribbon", "粉红色丝带" );
	add( "id", ({ "ribbon","whip" }) );
	set_short( "粉红色丝带" );
	set_long(
		"这是一条粉红色的长丝带，看起来就像是一般女孩用来绑头发的丝带。\n"
		 "但是却充满了一种奇特的魅力。\n"
	);
	set( "unit", "条" );
	set( "weight", 30 );
        set("nosecond",1);
	setup_weapon( "whip", 20, 9,18);
	set( "value", ({ 320, "silver" }) );
//        set( "hit_func", "charmed" );
	set( "wield_func","wield_ribbon");
        set_c_verbs(({"%s甩向%s","%s卷向%s","%s挥向%s"}));

}

void wield_ribbon()
{
object holder;
	holder=this_player();
		
       if ((string)holder->query("gender")!="female")
        {
        tell_room( environment(holder), 
         holder->query("c_name")+"想要学著女生扭扭捏捏地拿著粉红色丝带，真是笑死人。\n"
		, ({holder}) );
        tell_object( holder,
         "你想要学著女生用粉红色丝带，试了一阵以後，旁边的人都笑的直不起腰来。\n");
	::unwield();
		return ;
	}
	else
	{
        tell_room( environment(holder), 
         holder->query("c_name")+"优雅地拿著粉红色丝带，显得十分娇媚。\n"
	, ({holder}) );
        tell_object( holder, 
         "你拿起粉红色丝带，觉得自己简直是世界上最美丽的超级美女。\n");
		return;
	}
	return ;
}
int charmed(object victim)
{	
	object holder;
	holder=environment(this_object());
        if( random(holder->query_perm_stat("int")+
		   holder->query_perm_stat("str"))<25) return 0;
       if( victim->query("stop_attack") ) return 0;
	if ( (string)victim->query("gender")=="female" ) return 0; 

        tell_object( victim, 
          "粉红丝带散发出一种迷人的力量，你感到一阵晕眩 !!\n");
        tell_object( holder, 
          "\n你的粉红丝带散发出一种迷人的力量，敌人变的两眼无神 !!\n\n");
        tell_room( environment(holder), 
          "\粉红色丝带的魅力，使" + victim->query("c_name") +"无法攻击 !!\n\n"
	, ({ victim, this_object() }));
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack", 
          "( 你现在全身无力，沈醉在著片美丽的诱惑里 ! )\n" 
        );
        return 1;

}
