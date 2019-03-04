#include <mudlib.h>
#include <move.h>
#include "/d/thief/thief.h"

#define EQ_ROOM "/d/thief/hall/eq_room"
#define MONEY_COST 300
#define BS_ROOM1 "/d/thief/hall/backstab_room"

inherit MONSTER;

mixed *skill_level_exp;

init()
{
	add_action("do_train","train");
	add_action("do_ask","ask");
	add_action("do_cost","cost");
}

void set_skill_level_exp()
{
	int exp, i;
	
	exp = MAX_SKILL_EXP;
	skill_level_exp = allocate(MAX_SKILL_LEVEL+1);
	for( i=MAX_SKILL_LEVEL; i> 0; i-- ) {
		skill_level_exp[i] = exp;
		switch( i ) {
			case  0..2  : exp -= exp /   2; break;
			case  3..6  : exp -= exp /   3; break;
			case  7..10  : exp -= exp /  4; break;
			case  11..16 : exp -= exp /  5; break;
			case  17..25 : exp -= exp /  6; break;
			case  26..28 : exp -= exp /  7; break;
			case  29..34 : exp -= exp /  7.6; break;
			case  35..40 : exp -= exp /  8.3; break;
			case  41..50 : exp -= exp /  4.5; break;
		}
	}
}

create()
{
	object ob;
	::create();
	set_level(18);
	set_name("taylers","̩��˹");
	set_short("̩��˹");
	set_long(@LONG
̩��˹ԭ����Զ�����С͵���ŵĳ���֮һ, С͵���������, �Ͽ����ϵ�Ƹ��
����С͵���ᵣ�θ��᳤, ����С͵���ɵ�ĥ�������������������ᵹ����ſ��
���ϴ��, ���������Լ������ֶ����ǵ��ˣ���ܻ������ܹ���ʲ�᣿
LONG
	);
	set( "race","halfling");
	set( "gender","male");
	set( "max_hp", 1000 );
	set( "hit_points", 1000 );
	set("no_attack",1);
	set_skill_level_exp();
	ob = new("/d/thief/uni_dagger");
	ob->move(this_object());
}


int chat(string arg)
{
	if ( arg )
		command("whisper "+arg);
	return 1;
}


int do_cost()
{
	int i,lv,min = 1,max = 1;
	if ( wizardp(this_player()) ) {
		max = MAX_SKILL_LEVEL;
		min = 1;
	} else { 
	max = min = (int) this_player()->query("thief_level/backstab");
	min = (min > (lv = (int) this_player()->query("thief_level/throw-dagger"))) ? lv : min;
	max = ( lv > max ) ? lv:max;
	min = (min > (lv = (int) this_player()->query("thief_level/steal"))) ? lv : min;
	max = ( lv > max ) ? lv : max;
	}

	printf("̩��˹˵�� : \n");
	for ( i = min ; i < max + 5 && i <= MAX_SKILL_LEVEL ; i ++ )
		printf("�����ȼ� %2d : %10d ���������飬��Ҫ������ %6d ö���ҡ�\n",
			i,skill_level_exp[i],i*MONEY_COST);
	if ( i < MAX_SKILL_LEVEL )
		printf("��������ȼ� %2d : %10d ���������飬��Ҫ������ %6d ö���ҡ�\n",
			MAX_SKILL_LEVEL,skill_level_exp[MAX_SKILL_LEVEL],MAX_SKILL_LEVEL*MONEY_COST);
	return 1;
}

do_ask(string arg)
{

string *msg=({	"�� .... �� ������",
		"�� �� ��Ҫ�� ... ",
		"�� ... ����Ϻ���� ?",
		"�� ?? Ҫѵ��(train) ??", 
		"�� ..�� ..����ʲ�� ??",
		"�Ǻ� ... ���벻������С̩�ɵ���",
		"�� .... ������͵ ... ͵�� ...ZzzZ����",
		"zZzz ... ��zZ��Z ������",
	});
string tmp1,tmp2;
object *invs,paper;
int i;

	if ( ! arg ) 
		return 0;
	if ( sscanf(arg,"%s about %s",tmp1,tmp2) == 2  && id(tmp1) ) {
		if ( tmp2 == "equip" || tmp2 == "װ��") {
//		    tell_object(this_player(),"̩��˹б������˵�� : ����У����ڵ����� ...\n");
		    tell_object(this_player(),"̩��˹���ҰѶ������������ϡ�\n");
		    invs = all_inventory(find_object_or_load(EQ_ROOM));
		    for ( i = sizeof(invs)-1 ; i >= 0 ; i -- )
			if ( (string)invs[i]->query("owner") == (string)this_player()->query("name") ) {
			if ( (int)invs[i]->move(this_player()) != MOVE_OK ) 
			    invs[i]->move(environment(this_object()));
			invs[i]->delete("owner");
			}
		    return 1;
		}
	    tell_object(this_player(),
		sprintf("̩��˹б������������ : %s\n",msg[random(sizeof(msg))]));
	    return 1;
	}
	return 0;
}

int accept_item(object who,object item)
{
	if ( ! item->id("wine") ) {
	    tell_object(who,
		sprintf("̩��˹ãã�Ŀ�����, ˳�ְ�%s�������ϡ�\n",item->query("c_name")));
	    item->move(environment(this_object()));
	} else	{
	    tell_object(who,
		"̩��˹���۾�����, �����������"+item->query("c_name")+"�������� !!\n");
		command("drink wine");
		who->add_temp("taylers",1);
	}
	return 1;
}

int do_train(string arg)
{
	string *skills = ({ "backstab","throw-dagger","steal", });
	object trainee,*invs,obj,obj2;
	int total,cost,i;


	if ( ! arg || member_array(arg,skills)== -1) 
		return notify_fail("��Ҫѵ��ʲ��?\n");
	if ( arg == "steal" )
		return notify_fail(@R1
һ����������, ��ˮƿ����������ǰ��
��ˮƿ��ü������˵��: ����һ��ʱ��� :~~~
R1
			);
	trainee = this_player();
/*
	if ( trainee->query_temp("pass_test/"+arg) ) {
		trainee->delete_temp("pass_test/"+arg) ;
		trainee->add("thief_level/"+arg,1);
		tell_object(trainee,
		"̩��˹������ļ��˵ : �㻹Ҫ��������ʲ�᣿���Լ���Ŭ����\n"
		"�Ѿ������������������� !! ���������ߵļ���Ŭ���� !!\n"
		);
		return 1;
	}
*/
	if ( (int)trainee->query_temp("taylers") <= (int)trainee->query("thief_level/"+arg)/5)
//		return notify_fail("̩��˹����һ���������������㡣\n");
		return notify_fail("̩��˹���˷�����, ˵ : �þ��� !\n");

	//check exp
	if ( (int)trainee->query("thief_level/"+arg) >= MAX_SKILL_LEVEL )
		return notify_fail("̩��˹ҡҡͷЦЦ : ��Ǹ�� ! ���Ѿ�̫ǿ�� ... û���ܰ��㿼���� ...\n");
	if ( (int)trainee->query("thief_exp/"+arg) < 
		skill_level_exp[(int)trainee->query("thief_level/"+arg)+1] ) 
		return notify_fail("̩��˹ãã�Ŀ����㣬ҡͷ�� : ��ľ��黹���� ...\n");

	trainee->add("thief_level/"+arg,1);
	tell_object(trainee,
	"̩��˹˵��: Сƿ��˵�Ȳ��ò�����, ֱ��������!!\n"
	"��ĵȼ������� "+ trainee->query("thief_level/"+arg) +"��.\n"
	);
	trainee->delete_temp("taylers");
#if 0
	cost = ((int) trainee->query("thief_level/"+arg)+1)* MONEY_COST;
//	cost = ( cost < MONEY_COST ? MONEY_COST : cost );
	if ( (int)trainee->query("wealth/silver") < cost ) {
		return notify_fail("̩��˹����һ��, ˵��: ������С���ָ�����ѧ��, �����ѧɶ ?\n");
	}
	//check if someone else is trainning
	if ( (int)("/d/thief/hall/"+arg+"_room")->query("using") || (int)("/d/thief/hall/"+arg+"_room")->query("begin_test") > time() )
		return notify_fail("̩��˹˵�� : ��������ѵ��������ܿ���, �����������.\n");
 
	trainee->delete_temp("taylers");
	trainee->add("wealth/silver",-cost);
	tell_object(trainee,@P1
̩��˹������������һ��, �㷢���Լ��Ѿ��������, ���ɵ�һ����...

������������ǽ������һ��, ��ͻȻ���ý���һ��, ���һ������һ���󶴡�
̩��˹��������ͷ�ϴ��� : ����, ֤����ļ����������Ұ� !!
P1
	);

	// remove trainee's eq
	invs = all_inventory(trainee) ;
	for ( i = sizeof(invs)-1 ; i >=0 ; i-- ) {
		if (invs[i]->query("prevent_drop") && invs[i]->query("prevent_insert") ) 
			continue ;
		if ( (int)trainee->query("make-up") == 1)
		    invs[i]->set("owner",trainee->query("org_name"));
		else
		    invs[i]->set("owner",trainee->query("name"));
		invs[i]->move(EQ_ROOM);
	}
/*
	obj = new("/obj/bandage");
	obj->move("/d/thief/hall/"+arg+"_room");
	obj2 = new("/d/noden/farwind/items/plaster");
	obj2->move("/d/thief/hall/"+arg+"_room");
*/
	trainee->delete("seller_channel");
	trainee->move("/d/thief/hall/"+arg+"_room");
#endif
	return 1;
}
