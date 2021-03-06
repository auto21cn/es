#include "/d/noden/moyada/moyada.h"
inherit MONSTER;

void create ()
{
    object ob1;
	::create();
	seteuid( getuid() );
	set_level(14);
	set_name( "Fast turtle", "快速龟" );
	add ("id", ({ "turtle", }) );
	set_short( "快速龟" );
	set_long( @C_LONG
你看到一只穿跑鞋绑头巾的小乌龟,它有一双大大的眼睛,翠绿的身体...
它是传说中风神养的乌龟,可别让它一下子就溜走啦!!!。
C_LONG
	);
	set( "alignment", 2000 );
    set( "unit", "只" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 30 );
	set_perm_stat( "karma", 20 );
	set ("max_hp", 1500);
	set ("hit_points", 1500);
	set ("natural_weapon_class1", 250);
	set ("natural_defense_bonus",10);
	set ("natural_armor_class", 25);
	set ("natural_min_damage1", 3); 
	set ("natural_max_damage1", 5);
	setenv( "C_MIN", "一只$N很快的跑了过来。");
	setenv( "C_MOUT", "$N快速的往$D方跑走了。");
	set ("aim_difficulty", ([ "critical" : 100, "weakest" : 1, ]) );
	set ("special_defense",
	    ([ "all" : 10, "none" : 10 ]) );
	set ("wimpy", 50);
	set ("moving", 1);
        set ("speed",50);
    set ("weight", 100);
    set ("exp_reward", 3000);
    set ("chat_chance",14);
    set ("chat_output", ({
"『你知道龟兔赛跑 乌龟为什麽会赢吗? 因为是由我代表参加啦!!!』『哈哈!!!』\n"
    }) );
    
set("att_chat_output",({
   "哈哈哈!!! 凭你们是抓不到我的啦!!! \n" ,
   "哈哈哈!!! 放弃吧!!! 去抓幸运兔啦!!! 慢脚虾!!! :p\n"
   }));
 
    set_c_verbs( ({ "一下弹起用它的龟壳敲向你的背上", "用尾巴扫你的脑袋",
                    "在你的背上画一只大乌龟!!!" }) );
    set_c_limbs( ({ "龟甲","四肢","尾巴","鼻子"  }) );
    set( "c_death_msg", 
"%s说:『大哥 我认输!!! 明年由你代表乌龟去比赛好了!!!』它摇摇头,然後就死了。\n" );
    ob1=new( "/u/a/angel/item/ac.c" );
    ob1->move(this_object()); 
}


int catch_huntee( object who )
{
    tell_room( this_object(), 
      "快速龟看见 "+who->query("c_name")+" 大叫『你是坏人!』惊吓地大叫\n"
    ,  ({ this_object(), who }) );
    tell_object( who, 
      "快速龟看见你之後，大叫『你是坏人!!!』迅速地逃开\n" 
    );
    return 1;
}
