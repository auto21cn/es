#include "../../layuter.h"
inherit MONSTER ;

void create ()
{
        ::create();
        set("exp_reward",60000);
        set_level(19);
        set_name( "evil dragon", "孽龙恨天" );
        add ("id", ({ "dragon" }) );
        set_short(" 孽龙恨天");
        set("unit", "位");
        set("alignment",-2000);
        set("weight",2000);
        set("wealth/gold",1000);
        set_long(@C_LONG
它是一只十分邪恶的恶龙，它曾经残杀无数的生灵因而被玉帝将其封於此处
，它并不好惹曾有无数的勇者死於其手。
C_LONG
        );
        set_perm_stat("int", 30);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 30);
        set_perm_stat("kar", 30);
        set_perm_stat("pie", 30);
        set_perm_stat("con", 30);
        set("max_hp",2500);
        set("hit_points",2500);
        set_natural_weapon( 95, 50, 80 );
        set_natural_armor( 100, 70 );
//	set("unbleeding",1);
        set("special_defense",
        	([ "cold" : 90, "fire" : 70, "all" : 70 , "none" : 80 ]));
        set_skill("dodge",70);
        equip_armor(Lditem"dragon_amulet");
        set("tactic_func","special_attack");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        set_c_verbs(({"%s用它的利爪向%s抓去","%s伸出它那长满利牙的嘴巴向%s咬去" }));                
}

void announce( string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], c_msg);
	}
}
       
       
int special_attack()
{// 20% use it! damage 40-70.
    object env,*inv,*victim;
    int i;
    env=environment(this_object());
    inv=all_inventory(env);
    if(random(10)<8) return 0;
    tell_room( environment( this_object() ), 
      "孽龙以它的尾巴，掀起滔天巨浪，滚滚湖水淹没湖的四周并强烈地冲击岸上每一个人。\n",
      this_object()
    );
    i = sizeof(inv);
    while(i--) {
      if (inv[i]!=this_object()) 
        {
           inv[i]->receive_damage(random(30)+40);
           "/d/magic/magic"->report( this_object(), inv[i] );
        }
    }
    return 1;
}

void die()
{
    
    object ob1;
    
    ob1=query("last_attacker");
    announce(
"\n东方大陆的上空出现朵朵祥云，而阵阵仙乐从空中传下，在天兵天将的护持\n"
"中龙神九州出现在东方大陆的上空，并对著这世界所有的人宣称：\n"
"伟大的英雄 "+ob1->query("c_name")+" 解救我那不成才的弟弟孽龙恨天\n"
"我以他为荣，再为东方的英雄史写下灿烂的一页。\n\n");
    if ((int)ob1->query_quest_level("evil_dragon")< 1 ){
       ob1->finish_quest("evil_dragon",1);
       tell_object(ob1,"你已经完成这个任务，你得到 50000点经验值\n" );
       ob1->gain_experience(50000);    
   };
  ::die(); 
}
