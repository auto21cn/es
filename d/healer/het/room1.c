#include <mudlib.h>
#include <conditions.h>
#include "wang.h"
inherit ROOM;

void init()
{
	add_action("do_pick","pick");
}
void create()
{
 	::create();
        set_short("花圃");
	set_long(@LONG
走到这里，让你眼前一亮。这里开满了各种花，放眼望去，一片花海。阵阵花香，
让你觉得彷佛身在仙境。红的、黄的、白的、蓝的、紫的甚至稀有的黑色的花，这里
都可以看到。水桶，小铲子，锄头等等工具四处散著，显然这里的花是有人细心照顾
的。南方不远处隐隐约约有个茅屋。
LONG
);
	set("light", 1);
	set("exits",([
		"south" : WANG"room2" ,
		"east" : WANG"room7" ,
		"west" : "/d/eastland/forest/4,2.forest", 
	]));
	set("pre_exit_func", ([
	     "west" : "leaving",
	    ]));
	set("item_desc", ([
	     "flower"     : 
"这里的花开的很漂亮，蓝色的花(blue flower)更引起你的好奇心，想要看清楚些。\n",
	     "blue flower" : "一朵蓝色的花，闻起来有股淡淡的香。想不想摘下来(pick) ?\n",
	     "red flower" : "一朵红色的花，看起来很漂亮。想不想摘下来(pick) ?\n",
	    ]));

	set( "objects" ,([
	     "boy" : WANG_MOB"boy01"
	]));

	reset();
}


do_pick(string str)
{
	string *arg, color,item,tmp;
	object who;
        string whoname;


	if ( ! str ) 
		return notify_fail("你要摘什麽?\n");

	who = this_player();
	arg = explode(str," ");
	
	if ( sizeof(arg) < 2 )
		return notify_fail("你要摘什麽?\n");

	color = arg[0]; item = arg[1];
	if ( item != "flower" ) 
		return notify_fail("这里没有这种东西。\n");

	whoname = (string)who->query("c_name");

	switch ( color ) {
	   case "red" :
		tell_object(who,"你摘下一朵红花，凑往鼻边一闻，没想到奇臭无比，一惊之下，随手把它丢了。\n");
		tell_room(this_object(),
			sprintf("%s摘了一朵花，随即把花丢掉。\n",whoname));
		break;
	   case "blue" :
		tell_object(who,
"你选了一朵最漂亮的花，轻轻的摘下来，但是不小心被旁边的小刺扎到，有点麻麻的。\n");
		tell_room(this_object(),
			sprintf("%s摘了一朵花。\n",whoname));
		call_out("little_poison",8,who);
		break;
	   default :
		tell_object(who,"这花还没开，换摘别的花吧。\n");
		break;
	}
	return 1;
}


int leaving()
{
object who;
	who = this_player();
	if ( (int) who->query_temp("kill_wang") == 0) 
		return 0;
	else { 
		tell_object(who,
"当你要离开这花圃时，一阵花香飘过来.. 你觉得很舒服.... \n"
"突然间你想到这边是王药师的花圃，但是已经来不及了!!\n"
		);
		(CONDITION_PREFIX + "simple_poison")->
			apply_effect(who,15,6);
		call_out("again",30,who);		
		who->delete_temp("kill_wang");
	}
	return 0;/* still can leave */
}

void little_poison(object who)
{
	tell_object(who,"你忽然手臂渐渐发麻... 刚刚的蓝花原来是有毒的!!\n");
	(CONDITION_PREFIX + "slow") ->apply_effect(who,5,5);
}

void again(object who)
{
	tell_object(who,"你忽然一阵不舒服，原来王药师的毒不只这样...\n");
	(CONDITION_PREFIX + "weak") ->apply_effect(who,30,15);
	(CONDITION_PREFIX + "slow") ->apply_effect(who,30,15);

}
