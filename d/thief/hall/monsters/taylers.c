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
	set_name("taylers","泰勒斯");
	set_short("泰勒斯");
	set_long(@LONG
泰勒斯原本是远风镇的小偷集团的长老之一, 小偷公会成立後, 毕克林老爹聘请
他到小偷公会担任副会长, 负责小偷技巧的磨练。他现在正醉的歪歪倒倒的趴在
地上打呼, 恐怕连他自己的名字都不记得了，你很怀疑他能够做什麽？
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

	printf("泰勒斯说道 : \n");
	for ( i = min ; i < max + 5 && i <= MAX_SKILL_LEVEL ; i ++ )
		printf("熟练等级 %2d : %10d 点熟练经验，需要报名费 %6d 枚银币。\n",
			i,skill_level_exp[i],i*MONEY_COST);
	if ( i < MAX_SKILL_LEVEL )
		printf("最大熟练等级 %2d : %10d 点熟练经验，需要报名费 %6d 枚银币。\n",
			MAX_SKILL_LEVEL,skill_level_exp[MAX_SKILL_LEVEL],MAX_SKILL_LEVEL*MONEY_COST);
	return 1;
}

do_ask(string arg)
{

string *msg=({	"啊 .... 啊 ～～～",
		"酒 ～ 我要酒 ... ",
		"啊 ... 你是虾米郎 ?",
		"啊 ?? 要训练(train) ??", 
		"背 ..背 ..背刺什麽 ??",
		"呵呵 ... 你想不想试试小泰飞刀？",
		"不 .... 不可以偷 ... 偷我 ...ZzzZｚＺ",
		"zZzz ... ＺzZｚZ ～～～",
	});
string tmp1,tmp2;
object *invs,paper;
int i;

	if ( ! arg ) 
		return 0;
	if ( sscanf(arg,"%s about %s",tmp1,tmp2) == 2  && id(tmp1) ) {
		if ( tmp2 == "equip" || tmp2 == "装备") {
//		    tell_object(this_player(),"泰勒斯斜著醉眼说道 : 如果有，就在地上啦 ...\n");
		    tell_object(this_player(),"泰勒斯胡乱把东西塞到你身上。\n");
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
		sprintf("泰勒斯斜著醉眼喃喃自语 : %s\n",msg[random(sizeof(msg))]));
	    return 1;
	}
	return 0;
}

int accept_item(object who,object item)
{
	if ( ! item->id("wine") ) {
	    tell_object(who,
		sprintf("泰勒斯茫茫的看著你, 顺手把%s丢到地上。\n",item->query("c_name")));
	    item->move(environment(this_object()));
	} else	{
	    tell_object(who,
		"泰勒斯两眼精光大炽, 拿起你给他的"+item->query("c_name")+"喝了起来 !!\n");
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
		return notify_fail("你要训练什麽?\n");
	if ( arg == "steal" )
		return notify_fail(@R1
一阵烟雾过後, 汽水瓶出现在你面前。
汽水瓶愁眉苦脸的说道: 给我一点时间吧 :~~~
R1
			);
	trainee = this_player();
/*
	if ( trainee->query_temp("pass_test/"+arg) ) {
		trainee->delete_temp("pass_test/"+arg) ;
		trainee->add("thief_level/"+arg,1);
		tell_object(trainee,
		"泰勒斯拍拍你的肩膀说 : 你还要我来帮你什麽？你自己的努力，\n"
		"已经让你的能力获得提升了 !! 继续朝更高的技术努力吧 !!\n"
		);
		return 1;
	}
*/
	if ( (int)trainee->query_temp("taylers") <= (int)trainee->query("thief_level/"+arg)/5)
//		return notify_fail("泰勒斯翻了一个身，理都不理你。\n");
		return notify_fail("泰勒斯翻了翻白眼, 说 : 拿酒来 !\n");

	//check exp
	if ( (int)trainee->query("thief_level/"+arg) >= MAX_SKILL_LEVEL )
		return notify_fail("泰勒斯摇摇头笑笑 : 抱歉啦 ! 你已经太强啦 ... 没人能帮你考试了 ...\n");
	if ( (int)trainee->query("thief_exp/"+arg) < 
		skill_level_exp[(int)trainee->query("thief_level/"+arg)+1] ) 
		return notify_fail("泰勒斯茫茫的看著你，摇头道 : 你的经验还不够 ...\n");

	trainee->add("thief_level/"+arg,1);
	tell_object(trainee,
	"泰勒斯说道: 小瓶子说先不用测验了, 直接升级吧!!\n"
	"你的等级升到第 "+ trainee->query("thief_level/"+arg) +"级.\n"
	);
	trainee->delete_temp("taylers");
#if 0
	cost = ((int) trainee->query("thief_level/"+arg)+1)* MONEY_COST;
//	cost = ( cost < MONEY_COST ? MONEY_COST : cost );
	if ( (int)trainee->query("wealth/silver") < cost ) {
		return notify_fail("泰勒斯瞪你一眼, 说道: 你这穷小子又付不起学费, 想跟我学啥 ?\n");
	}
	//check if someone else is trainning
	if ( (int)("/d/thief/hall/"+arg+"_room")->query("using") || (int)("/d/thief/hall/"+arg+"_room")->query("begin_test") > time() )
		return notify_fail("泰勒斯说道 : 有人正在训练室里接受考验, 你改天再来吧.\n");
 
	trainee->delete_temp("taylers");
	trainee->add("wealth/silver",-cost);
	tell_object(trainee,@P1
泰勒斯在你身上摸了一把, 你发现自己已经光溜溜的, 不由的一阵害臊...

接著他伸手在墙上摸了一下, 你突然觉得脚下一空, 筐啷一声跌进一个大洞。
泰勒斯的声音从头上传来 : 孩子, 证明你的技术再来见我吧 !!
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

