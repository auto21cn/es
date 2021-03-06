// Created by Aquarius@EasternStory
#include "mudlib.h"
#define TIME 120 	// 120 秒後消失
inherit OBJECT;
int droped = 0;		// 是否已被洒在地上
int xx = 0;		// 这这.. 总之, 必要的 flag
int life=0;		// 这枚图钉的有效期限
int dam=0;		// 所造成的伤害 , dam = skill/5;
object tricker;		// 放图钉的人

void create()
{
     set_name("pushpin","图钉");
     set_short("图钉");
     set_long(@LONG
一把图钉, 看起来不太起眼, 若是洒(spread)在地上, 不小心踩到的人
一定会痛的哇哇叫。
LONG
      );
     set( "unit", "把");
     set("weight",5);
     set("value", ({ 50, "silver" }));
}

void init()
{
    object who,mount_ob,*obs,env;
    int i;
    mapping exits;
    string dir,*dirs;

	// 正在对某人(骑马)作用中, 另一个同时进这个房间的人不会被刺到 .
    if ( xx ) return ;

    if ( ! droped ) {
        add_action("do_spread","spread");
	return;
    }

    if ( life < time() ) {
	this_object()->remove();
	return ;
    }


    who = previous_object();
    env = environment(who);
    
    if( ! who || ! living(who) || who->query_temp("flying") ) 
	return ;

    if ( who == tricker && dam > random(23) ) {
	tell_object(who,"你小心的避开自己洒的图钉。\n");
	return ;
    }


    if ( random(dam) > 18 ) 
	return ;

    if ( (mount_ob = who->query_temp("mounting")) ){
	xx=1;
    	tell_object(who,
		set_color("你的座骑突然一阵鸣嘶,人立起来,把你摔到地上!!\n","HIR",who));
	tell_room( environment(who),
		who->query("c_name") + "的座骑突然惨叫一声, 把"+who->query("c_name")+"摔在地上.\n",who);
	who->block_attack(6);
	who->set_temp("msg_stop_attack","( 你被摔的痛死了, 爬不起来, 无法攻击 )" );
//	call_other("/adm/daemons/mount","dismount",mount_ob,who);
	"/adm/daemons/mount"->dismount(mount_ob,who);
	// 笨比 .. 害我写不出来 ...
//	mount_ob->set("moving",1);
//	mount_ob->set("speed",40);
	this_object()->remove();
    } else {
	xx = 1;
    	tell_object(who,
		set_color("你脚下一痛, 好像被什麽刺到了!!\n","HIR",who));
    	who->set_temp("msg_stop_attack","( 你的脚被钉住了, 动弹不得 )\n");
    	who->block_attack(4);
    	who->add("hit_points",-dam);
    	this_object()->remove();
    }
    return ;
}

int do_spread(string arg)
{
	object env,*inv;
	int skill,i,num;
	if ( ! arg || arg == "" || ! id(arg) )
		return 0;
	if ( (int)this_player()->query_skill("trick") < 5) {
		tell_object(this_player(),"你笨手笨脚的, 不小心刺到自己, 痛死了!!\n");
		this_player()->add("hit_points",-10);
		return 1;
	}
	env = environment(this_player());
	inv = all_inventory(env);
	for(num = 0,i=sizeof(inv)-1;i>=0;i--)
		if ( (string) inv[i]->query("name") == "pushpin" )
			num++;

	if ( num > 2 ) {
		tell_object(this_player(),"这里满地都是图钉, 就别再洒啦。\n");
		return 1;
	}

	tell_object(this_player(),
		"你抓起一把图钉, 偷偷的洒在地上。\n");
	if( (int) this_player()->query_temp("hide_score") < 100  &&
	    this_player()->query("player_invisible") != 1 )
		tell_room(environment(this_player()),
	          sprintf("%s有点鬼鬼祟祟的,不知道在做什麽。\n",this_player()->query("c_name")), this_player() );
	life = time()+TIME;
	this_object()->set("prevent_get",1);
	this_object()->set("player_invisible",1);
	this_object()->move(env);
	tricker=this_player();
	dam = (int) this_player()->query_skill("trick")/5;
	droped = 1;
   	remove_action("do_spread","spread");
	return 1;	
}

