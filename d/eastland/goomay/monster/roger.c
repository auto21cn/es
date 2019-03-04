
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(12);
        set_name( "Jor the roger", "左无心" );
        add ("id",({ "jor","roger"}));
        set_short( "左无心");
        set("unit","个");
        set_long(
@C_LONG
他就是最近闹的满城风雨的大盗左无心，一个十分魁梧的汉子，却有著
锐利的眼神，他正倚在洞穴的另一端，肆无忌惮的打量著你。
C_LONG
);
        set("alignment",-550);
        set("wealth/gold",30);
        set_perm_stat("str",20);
        set_perm_stat("dex",25);
        set_perm_stat("int",17);
        set_natural_armor( 72, 11 );
        set_natural_weapon( 20, 13, 20 ); 
        set_skill("dodge",65);
        set_skill("unarmed",100);
        set ("gender", "male");
        set ("race", "human");
        set( "special_defense", ([ "all": 20 ]) );

        set( "inquiry", ([
                "statue": "@@ask_statue",
        ]) );

}
int ask_statue()
{
        tell_object(this_player(),
	"左无心邪笑道：「知道我在这里，你就领死吧 !! 任何事对你都不重要了 !!」\n" 
		    );

		command("kill "+(string)this_player()->query("name"));
		return 1;
}
void die()
{
	object killer;
	killer = this_object()->query("last_attacker");
	tell_room( environment(), 
	"左无心惨叫一声，摔倒在地，再也爬不起来了，他恶狠狠地瞪著你，可是却无力再战 ...\n\n" ,
	this_object() );
        tell_object(killer,
@C_STATUE
左无心突然大声狂笑：「被打败了 ...哈哈哈 ...你还要问吗？我说的话你会信吗？
自从偷了那一尊见鬼的神像後老子就倒了楣了，我真是鬼迷了心窍才会满屋子金银财
宝不拿，偏偏抱著那尊神像乱跑，每天被一些奇奇怪怪的妖魔鬼怪追来追去，最後我
被两只怪物打败了，一只全身冒著火焰，一只人头蛇身，他们以为我昏迷了，开始商
量该怎麽利用我，我记得那个声音，後来我又听到那个声音了－在我受审的时候，那
是县太爷的声音，这就是我为什麽拼了老命都要逃的原因，小偷被逮大不了几年牢饭
，可是落在妖怪的手里... 就算不死也要变成妖怪了。至於那尊神像，早就被他们拿
去了，我还留著它做什麽？妖怪们留我一条狗命，只不过要利用我引开别人的注意力
罢了。信不信由你，老子现在两手空空，早知道会被王八老吴给卖了。」

他的笑声越来越低，最後头一歪，倒在地上，死了 !!
C_STATUE
                        );
        killer->set_temp("meet_jor",1);
	::die(1);

	return;
}
