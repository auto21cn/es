#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "Sun Er Niang", "孙二娘" );
	add( "id", ({ "sun","er","niang" }) );
	set_short( "孙二娘" );
	set_long(
		"你看到一个强壮的少妇，她就是卖人肉包子的孙二娘，外号母夜叉，配\n"
		"与张青为妻，为梁山打听声息兼邀接来宾头领。\n"
	);
	set( "race", "human" );
	set( "gender", "female" );
	set( "alignment", -400 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 20 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 80 );
	set( "wealth/gold", 65 );
	set( "special_defense", (["all": 30 ]) );
	set_natural_weapon( 5, 4, 4 );
	set_natural_armor( 46, 10 );
        set("tactic_func","kick");
	set("inquiry",([
	    "meat" : "@@ask_meat"
	    ]));
	wield_weapon( "/d/eastland/obj/thin_blade" );
        equip_armor(TARMOR"red_skirt");
        equip_armor(TARMOR"ruby_ring");
}

int stop_attack()
{
	object husband, *tmp;

	husband = present( "hsin", environment() );
	if( !husband ) return 0;
	tell_room( environment(), 
		"张青喝道: 臭小子，敢欺负我老婆？看刀！\n"
	 );
   tmp =query_temp("protectors");
   if(! tmp || member_array(this_player(),tmp)==-1);
    husband->kill_ob(this_player());
 
}
int kick()
{
   object victim;
   string name,c_name;
   if (!(victim= query_attacker())) return 0;
   if ( (string)victim->query("gender") == "female" ) return 0;
   name =victim->query("name");
   c_name =victim->query("c_name");
   if(random(5)<1) {
   tell_room(environment(this_object()),
   "\n孙二娘大叫: 让你知道女人的厉害．裙底飞出一腿直击"+c_name+"要害，使它\n痛     不     欲     生\n\n"
);
   victim->receive_special_damage("evil",10);
   victim->block_attack(2);
   return 1;
}
}
void ask_meat()
{
if (!(this_player()->query_temp("fat_quest/meat")) || (int)this_player()->query_temp("fat_quest/meat")==0)
write(
"孙二娘凶巴巴的说道: 什麽肉? 想死啊?\n");
else 
{
write(
"孙二娘笑咪咪的说: 大家都很奇怪，为什麽敝店还能找到山产来做成好吃的料理。\n"
"甚至还有人传说我们是用人肉来作菜......:) \n"
"很久以前我们的确是用过人肉，但自从在山寨内开业以後，就再也没有用过了\n"
"现在我们用的肉，都是派人去幽国城西南的大森林打猎来的，但是因为是专人\n"
"处理，成本就比较贵一点呦，您要不要试看看。\n\n"
"你想，既然成本比较贵，似乎不太适合肥东这种公营事业...但是你还是认为跟肥\n"
"东讨论(consider meat)一下比较好\n");
this_player()->set_temp("fat_quest/meat",2);
}
return 0;
}