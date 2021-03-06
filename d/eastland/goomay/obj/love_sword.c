#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "sword of love", "断掉的还情剑" );
        add( "id", ({ "sword" }) );
        set_short( "断掉的还情剑" );
        set_long(
                "这是一把通体呈青碧色的剑，你把剑刃向著亮光处一照，竟是半点\n"
                "光泽也没有。你隐约可以感觉到剑身散发出一种温和愉悦的感觉，\n"
                "在剑柄近锷处，你发现刻著一行小字 ： 情丝难斩 断剑还情。\n"
        );

	set( "unit", "柄" );
	set( "weight", 150 );
	setup_weapon( "longblade", 40, 20, 40 );
	set( "value", ({ 400, "gold" }) );
        set("no_sale",1);

//	set("hit_func","love_damage");
	set("special_damage",10);
    set("special_c_msg","你的还情剑的断处突然发出光辉，一道青芒直直贯入你的胸膛，\n
你突然想起了过去曾有的温柔时光，心中一阵剧痛，几乎连武器也握不住了 .\n\n");
	set("special_c_msg2","%s的还情剑断处突然发出光辉，一道青芒直直贯入%s的胸膛 .\n\n");
}
void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim))
   );
}
int love_damage(object victim,int damage)
{
    object holder;
    int dam,max;
    string c_msg;

    if ( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;
    if ( (int)holder->query_skill("longblade")<85 ) {
      tell_object(holder,
		  query("special_c_msg"));
      holder->receive_special_damage("mental",dam+random(15));
      report(holder,holder);
      victim->set("last_attacker", holder );
      return 0;
    }
    else {
    dam = (int) query("special_damage") ;
	max=random(100);
      if ( max < 20 )  {
                c_msg = (string)query("special_c_msg2");
                victim->receive_special_damage( "mental",dam+max );
                victim->set("last_attacker", holder );
                tell_object( holder, 
                        sprintf(c_msg,"\n你",victim->query("c_name")));
                tell_room( environment(holder), 
                        sprintf(c_msg,holder->query("c_name"),victim->query("c_name")),
                        holder );
            return dam;
}
      return 0;
}
}
