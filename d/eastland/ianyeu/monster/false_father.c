#include "../mad.h"

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "guey Father", "桂老爹" );
   add( "id", ({ "guey", "father" }) );
   set_short( "桂老爹" );
	set_long(
        "你看到一个状似痴呆, 面黄肌瘦的老头, 正独自怔怔地望著天空。\n"
        "而且你不时听到一种幽幽淡淡, 若有似无的叹息声。\n"
	);
   set( "race", "human" );
	set( "gender", "male" );
   set_skill( "dodge", 50 );
   set( "wealth/copper", 10 );
   set( "alt_corpse", IANMOB"zombie1" );
	set( "inquiry", ([
       "sheaumei" : "@@ask_name"
	]) );
}


void ask_name(object player)
{
	if( query_attacker() ) {
            tell_room( environment(),
              "桂老爹怒吼道: 又出现另一个淫贼! 待会再收拾你!\n",
			this_object() );
	} else {
            tell_room( environment(),
                 "桂老爹怒吼道: 为甚你要打听我女儿的名子? 啊! 你一定是淫贼! 下地狱吧!\n",
			this_object() );
		kill_ob( player );
	}
}

void die()
{
        tell_room( environment(this_object()), 
          "\n桂老爹身受重伤, 不支倒地........\n\n"
          "就在你想离去时............\n\n"
          "突然桂老爹又站了起来, 继续攻击你! 原来这老爹是□变啊!!\n\n"
          , this_object() );
        ::die(1);
}
