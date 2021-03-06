#include <mudlib.h>
#define BACKSTAB_ROOM1 "/d/thief/hall/backstab_room"
#define BACKSTAB_ROOM2 "/d/thief/hall/backstab_room2"
#define TIME_LIMIT 600
inherit ROOM;

void new_mob(object trainee);

void create()
{
	::create();
	set_short( "背刺测验室");
	set_long(	@C_LONG_DESCRIPTION
这里是小偷公会的秘密训练室。专门给希望提升背刺能力的小偷们试身手
用的，这里除了北方有一点光影跳动外，似乎没有其他出口，不过东边的墙上
好像挂著一块告示(sign)，应该是一些说明吧 !! 你最好先看看。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set("c_item_desc",([
		"sign" : @SIGN
告示上写著 :
    这里是背刺测验室，你将要接受测验，在北方，有一个对手正等著你，
你可以用尽各种方法去取得他身上的钥匙，然後才能打开最北边的门回到公
会，这个过程有时间限制，小心应用你学到的各种技巧，也不要怀疑万用小
刀的威力，希望你能顺利过关 !!
 
    在你尝试闯关的过程，失败的状况有三种 :
    
    1. 被对手重伤而死 	: 你的对手都是公会的前辈化装的，出手自
			  有分寸，只会让你"假死", 不过人难免会失手, 
			  请自己小心。
    2. 时间用尽		: 时间拖太长了，对手烦了，会把你赶出测验室，那
			  你这次的测验费就白交了。
    3. 你逃走了		: 断线逾时或 quit 都视为闯关失败。
	
    此外，闯关後不论成败，请记得向泰勒斯要回你的装备(equip)。

SIGN
	]) );
	set( "exits", ([ 
		"north" : BACKSTAB_ROOM2 ]) );
	set("pre_exit_func",([ "north" : "to_north" ]) );
	reset();
}

int to_north()
{
	object *invs;
	int i;
	if ( !query("begin_test") ) {
		invs = all_inventory(find_object_or_load(BACKSTAB_ROOM2));
		for ( i = sizeof(invs)-1 ; i >=0 ; i-- )
			if ( !userp(invs[i]) ) invs[i]->remove();

		new_mob(this_player());
		set("begin_test",time()+TIME_LIMIT );
		if ((object)query("tester") == this_player())
			this_player()->set_temp("skip_dead",1);
	}
	return 0;
}

void new_mob(object trainee)
{
	object mob;
	int lv,bs_lv;
	lv = (int)trainee->query_level();
	bs_lv = (int)trainee->query("thief_level/backstab");
	mob = new("/d/thief/hall/monsters/bs_mob");
	mob->set_level(lv);
	mob->set_natural_weapon(lv*3/2,lv,lv*12/10);
	mob->set_perm_stat("karma",lv/2);

	mob->set("hit_points",10+3*bs_lv);
	mob->set("max_hp",10+3*bs_lv);
	mob->move(BACKSTAB_ROOM2);
}

int fail_to_pass(object me)
{
	delete("begin_test");
	delete("tester");
	set("using",0);
	tell_object(me,"\n一个声音说道 : 你花太多时间了 !! 下次再试吧 !!\n\n"); 
	me->delete_temp("skip_dead");
	me->move_player("/d/thief/hall/thief_guild","SNEAK");
	return 1;
}

int do_quit()
{
	tell_object(this_object(),
		"一个声音说道 : 放弃啦? 好吧, 下次再试试看可能比较好。\n");
	delete("begin_test");
	delete("tester");
	set("using",0);
	return 0;
}

do_auc()
{
	tell_object(this_object(),"你不能在这里进行交易 !!\n");
	return 1;
}

void init()
{
	int timer ;

	add_action("do_auc","auction");
	add_action("do_quit","quit");

	timer = query("begin_test") ;
	if ( ! timer ) {
		set("using",1);
		set("tester",this_player());
		return ;
	}
	if ( 
		(time() > timer) && 
		((object)this_object()->query("tester") == this_player())) {
		fail_to_pass(this_player());
	}
		return ;
}
