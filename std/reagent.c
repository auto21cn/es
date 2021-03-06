//#pragma save_binary

#include <mudlib.h>
#include <conditions.h>
inherit OBJECT;

// This is inherit file for reagents.
// reagents can set the following attributes:
//  1. savour /味道/
//       legal values are acidity    酸
//                        bitter     苦 
//                        acrimony   辣
//                        sweet      甜
//  2. effects => can be set to simple_poison, weak or slow
//  3. if effect is set to simple_poison then the following 
//     need to be setted
//
//     duration => how many times to be poisoned
//     damage   => hp lost in each duration 
//
//  4. if effect is set to weak or slow, then need to set 
//     the following
//                          
//     frequency => how many heart beats to recover 1 time
//     difference=> how many str or dex to be decreased.

void init()
{
  add_action("do_taste","taste");
}
  
int do_taste(string str)
{
   int duration;
   int damage;
   object me;
   
        seteuid(getuid());
	if( !id(str) ) return notify_fail(
		"你要□试什麽东西？\n");

        if ( query("savour")=="bitter") {
          write( 
                 "你将" + query("c_name") + "放在嘴边尝试,哇!!苦死了!!\n");
        }else if ( query("savour")=="acidity") {
          write( "你小心的舔了一下"+query("c_name")+", 哇勒, 好酸啊!!\n");
        } else if ( query("savour")=="acrimony" ){
          write( "你轻轻的舔了"+query("c_name")+"一下....哇!!快喷火了!!哪□有水??");
        } else if (query("savour")=="sweet") {
          write ("你试了试"+query("c_name")+",疑,还蛮甜的嘛!莫非是毒药甜嘴?\n");
	} else {
	  write ( "你尝了尝" + query("c_name") +",但感觉不出特别的味道。\n");
	}  
	if ( query("effect")=="simple_poison") {
	  duration=(int)query("duration");
	  damage=(int)query("damage");
          me = this_player();
        ("/std/conditions/simple_poison")->apply_effect(me,duration,damage);
	}else if ( query("effect")=="weak") {
	  duration=(int)query("frequency");
	  damage=(int)query("difference");
          me = this_player();
        ("/std/conditions/weak")->apply_effect(me,duration,damage);
	}else if ( query("effect")=="slow") {
	  duration=(int)query("frequency");
	  damage=(int)query("difference");
          me = this_player();
        ("/std/conditions/slow")->apply_effect(me,duration,damage);
	} else {	
	write(
		"你将" + query("c_name") + "放在嘴边□试，并没有感觉什麽特殊作用。\n");
	}
	
	tell_room( environment(this_player()),
		this_player()->query("c_name") + "将" + query("c_name") + "放在嘴边□试。\n",
		this_player() );
	return 1;
}
