#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "hotal boss", "旅馆老板" );
	add( "id", ({ "boss" }) );
	set_short( "旅馆老板" );
	set_long(@C_LONG
一位□著啤酒肚的中年人，他正笑嘻嘻地站在柜台旁招呼客人。
C_LONG
        );
	set( "gender", "male" );
        set( "no_attack",1);
        set( "inquiry", ([
            "golden_older":"@@ask_older",
                  "killer":"@@ask_killer"
        ]) );
}
void ask_older(object asker)
{
tell_room(environment(),@LONG

老板说道：老人？莫非你问的是居住在城外的那个脾气古怪的老人家？
　　　　　如果你想去见他，最好带特别的东西(special_things)去投
          他欢心，因为他生平最爱收集奇物异宝了。
　　
LONG
   );
}

void ask_killer(object asker)
{
write(@LONG
老板说道：刺客？你说的是那天的刺客？我什麽都不知道喔，那天我只
　　　　　看到一个黑影(shadow)翻墙而过。

LONG
   );
}