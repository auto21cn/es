#include <../goomay.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 9 );
        set_name( "Shu the migastrate of goomay", "县太爷" );
        add( "id", ({ "migastrate","shu" }) );
        set_short( "县太爷" );
        set_long(
@LONG
他就是现任的古梅镇县太爷－史耀前，肥肥胖的身材配上眯眯的眼睛，你不禁
有些怀疑他是不是真的只认识钱，虽然如此，当年他可是三元及第的红状元，
还娶他的恩师－步太师的女儿瑶莲小姐，可是当时读书人的羡慕对象。他这几
年升官不多、发财不少，十足的财运亨通。
LONG
        );
        set( "gender", "male" );
		set("race","elf");
        set_natural_armor( 40, 10 );
        set_natural_weapon( 20, 9, 22 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 100 );
        set("tactic_func","kill_me");
        set( "hit_points", 200 );
        set( "max_hp", 200 );
		set( "wealth/gold",30);
        set( "special_defense", ([ "all": 20 ]) );
        set( "inquiry", ([
                "statue"  : "@@ask_statue",
        ]) );

}
void disappear()
{
	tell_room(environment(this_object()),"县太爷趁乱溜到内堂了。\n",this_object());
	this_object()->remove();
}
int kill_me()
{
    object ob1,ob2,victim;
    if ( query("killed") ) return 1;
    victim = this_object()->query_attacker();
    tell_room( environment(this_object()),
   		"站在一边的捕快叫道：「竟敢对太爷不礼貌 !! 兄弟们 !! 把这个不知死活的家伙砍成八块 !!」。\n"
      ,this_object() );
                                                 
 	ob1 = new(Mob"cop" ); 
 	ob1 ->move_player( environment(this_object()), "SNEAK" ); 
 	ob2 = new(Mob"cop");
    ob2 ->move_player(environment(this_object()), "SNEAK" );
	ob1 -> kill_ob(victim);
	ob2 -> kill_ob(victim);
	this_object()->set("killed",1);
	call_out("disappear",2);
	return 1;  
}
int ask_statue()
{
        object me ;
        me=this_player();
        if ( (int)me->query_quest_level("Goddess_statue") > 2 )
        {
	tell_object(me,
	"县太爷道：「月神像不是已经找回来了吗？不过还是谢谢您救我一命 !!」\n"
		);
	return 1;
	}
        else
        {
	if (this_player()->query_temp("meet_jor"))
	{	
        tell_object(me,@C_STATUE
县太爷用一种很兴奋的眼光看著你道：「嘿嘿 !! 左无心那□的话也能信吗？钦差
大人啊 !! 你要怪就要怪你生了一副聪明脑袋吧 ... 哈哈哈 !!! 」他狞笑著向你
走过来，身上渐渐冒出一阵阵的火花，蓦然，「轰隆」一声，他变身成为一只浑身
冒著火焰的怪物。
C_STATUE
        );
        clone_object( Mob"fire_monster" )->move_player(environment(this_object()), "SNEAK");
        me->remove();
                return 1;
	}
	else
	{
        tell_object(me,@C_STATUE
县太爷用一种很迟缓的语调说道：「大人 !! 左无心那□穷凶极恶，下官已经通令
各捕房全力追捕了，大人代天巡守，日理万机，本镇穿窬小贼之事，就请大人不用
挂怀，小县一定尽力办案以报天恩。」
C_STATUE
        );
                return 1;
	}
}
}
