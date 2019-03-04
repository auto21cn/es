
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_name( "Chang the richman", "钱不多" );
        add ("id",({ "chang","richman"}));
        set_short( "钱不多");
        set("unit","个");
        set_level(10);
        set_long(
@C_LONG
你看到一个矮小削瘦的人，他的年纪大约五十来岁，虽然除了一双炯炯
有神的眼眸之外没有其他特别引人注意的地方，但是他却是大名鼎鼎的
本镇第一首富－钱不多。他最大的兴趣就是赚钱，现在他正在和他的手
下讨论他们的赚钱计划，如果没事的话，你最好不要打扰他们。
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
        set ("tactic_func","kill_me");
}
void disappear()
{
	tell_room(environment(),"钱不多挥挥拳，叫道 : 给我狠狠地揍他 !! 然後就走了。\n",
			this_object());
	this_object()->remove();		
}
int kill_me()
{
	object ob1,ob2,victim;	
	if ( query("killed") ) return 1;
	victim = this_object()->query_attacker();
        tell_room( environment(), 
         "钱不多生气地叫道：「来人啊 !! 把这个不知死活的家伙轰出去 !!」。\n"
        ,this_object() );

        ob1 = new(Mob"bodyguard" );
        ob1 ->move( environment() );
        ob2 = new(Mob"watchdog" );
        ob2 ->move( environment() );
		ob1->kill_ob(victim);
		ob2->kill_ob(victim);
		this_object()->set("killed",1);	
		call_out("disappear",2);
        return 1;
}

