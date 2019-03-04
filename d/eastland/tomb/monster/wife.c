#include "mudlib.h"
 
inherit MONSTER;
 
void create()
{
	
	::create();
	set_level(18);
	set_name( "Archmaster's Wife Hsiao", "萧小小" );
	add ("id", ({ "wife","hsiao" }) );
	set_short( "萧小小" );
	set_long(
"在你面前的就是大国师的妻子 -- 萧小小。她有著花一般的容貌，玉一样的\n"
"肌肤，腰枝袅娜，身材苗条，真是行一步也可人意儿，看一眼也使人魂消。\n"
"然而在她的眉宇之中，却隐含著一股淡淡的忧愁，让人觉得好生心疼。也许\\n"
"你可以问问她是如何跟大国师相识的。\n"
	);
    set( "gender", "female" );
    set( "race", "human" );
    set( "unit", "位" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 17 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 23);
	set ("max_hp", 799);
	set ("hit_points", 799);
	set ("wealth", ([ "gold": 150 ]) );
	set_natural_weapon(20,10,25);
	set_natural_armor(99,36);
	set ("special_defense",(["all":33,"none":33,"monk":33,"scholar":33]));
	set("aim_difficulty",(["vascular":30,"weakest":30,"ganglion":30]) );
    set ("weight", 400);
    set_skill("dodge",90);
    set_skill("dagger",100);
    set_skill("anatomlogy",70);
    set("aiming_loc","weakest");
    equip_armor("/d/eastland/tomb/armors/cloth");
    equip_armor("/d/eastland/tomb/armors/armband1");
    wield_weapon("/d/eastland/tomb/weapons/dagger");
    set( "inquiry", ([
         "archmaster" : "@@ask_master" ,
         "master" : "@@ask_master",
         "nickname" : "@@ask_name" ,
         "jade" : "@@ask_jade",
         "box" : "@@ask_box"
           ]) );
}
 
void ask_box()
{       object obj;
        if (this_player()->query_temp("tombkey") == 1) {
        command("bonk "+(string)this_player()->query("name"));
        command("say 箱子就是用来装东西的啦....你要问几次啊？\n");
        command("gag "+(string)this_player()->query("name"));
        } else {
        command("smile "+(string)this_player()->query("name"));
        command("say 箱子不是用来装东西的吗....不然你以为呢？\n");
        tell_object(this_player(), @ASK
 
萧小小顺手把箱子一移，在原来箱子的底下的位置有一只钥匙，不过她似乎没有发现到。
 
奸诈的你趁著她一个低头不注意，偷偷把钥匙捡起。
 
ASK );
        obj=new("/d/eastland/tomb/item/key1");
        obj->move(this_player());
        this_player()->set_temp("tombkey",1);
        return;
        }
}
 
void ask_name()
{
        command("giggle");
        command("say 妾身小名叫 「阿福」。\n");
        command("blush");
        return;
}
 
void ask_master()
{
	command("sigh");
	command("say 不要再问了.....\n");
	command("twiddle");
	return;
}
