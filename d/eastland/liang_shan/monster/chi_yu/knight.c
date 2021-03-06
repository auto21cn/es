#include <mudlib.h>

inherit "/d/eastland/liang_shan/monster/chi_yu_group";

void create()
{

	::create();
	set_level(17);
	set_name( "snaky warrior", "蛇人战士" );
	add( "id", ({ "warrior" }) );
	set_short( "蛇人战士" );
	set_long(@C_LONG
蛇人其实可以说是没有脚的蜥蜴人，虽没有蜥蜴人那麽强壮
但是却有远高於他们的智慧。尽管如此，经过严格训练的蛇
人还是可以成为勇猛的战士，并且能够自由使用许多不同的
战术。
C_LONG	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -500 );
	set_natural_weapon(20,15,15);
	set_natural_armor(20,20);
	set( "special_defense", ([ "all": 20,"none":10 ]) );
        
        set("aim_difficulty",
        ([ "critical":25, "vascular":20, "weakest":35, "ganglion":5 ]));

	set("chi_yu_group",1);
	set( "wealth/silver", 250 );
	set_perm_stat( "str", 24 );
	set_perm_stat( "dex", 24 );
	set( "aiming_loc", "weakest" );
	set_skill( "anatomlogy",60 );
	set_skill( "longblade", 90 );
	set_skill( "parry", 80 );
	set_skill( "block",85 );
	set("tactic","berserk");
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"[1m蛇人战士大叫: 蚩尤大王就快过来了，大家快把垃圾清乾净！[0m\n",
		"[1m蛇人战士说道: 丢下武器，不要做无谓的抵抗！[0m\n",
		"[1m蛇人战士喝道: 黄钟毁弃，瓦釜雷鸣，你们的英雄都到那去了！[0m\n"
	}) );

        wield_weapon( "/d/deathland/weapon/sword03" );
//        equip_armor( "/d/noden/drow/arm/a18" );
  //      equip_armor( "/d/noden/drow/arm/a10" );
    //    equip_armor( "/d/noden/drow/arm/a14" );
}

int my_tactic()
{
	object victim;
        
        if ( !victim = query_attacker()) return 0;
	
	if( random(20)<3 ) {
        tell_object(victim,set_color( "说时迟，那时快，蛇人战士用他长长的尾巴向你下盘扫去，你一个\n"
        "不小心，被他打翻在地上。\n","HIM",victim));
        tell_room(environment(this_object()),set_color("说时迟，那时快，蛇人战士用他长长的尾巴向"
        +victim->query("c_name")+"的下盘扫去，将他打倒在地。\n","HIM",victim),victim);
        victim->block_attack(3);
        victim->set_temp("msg_stop_attack", "\n（ 你现在摔倒在地无法动弹 ）\n\n");
        victim->receive_damage(5);
        return 1;
	} else return 0;
}

void relay_message(string class, string str)
{
        int i,hitp,hp1,hp2;
        string name,direction,tmp,guild;
        object victim,mob,env,*who,bandage;
        mixed bandaged,bleed;
        ::relay_message(class,str);
        
        
        if( !str || str == "" ) return;
        if( sscanf(str,"%s(%s)走了过来。", tmp,name)==2 ) {
        name = lower_case(name);
        victim = present(name, environment(this_object()));
        if( !victim || victim->query("npc") || victim->query("no_attack")) return ;
        
        if( victim->query_level() > 5 && !victim->query("ghost") && victim->query("alignment") >100 ) {  
        
        if( !pointerp(attackers) || member_array(victim, attackers)==-1 ) {
        
        tell_object(victim,query("c_name")+"叫道 : 通通去死吧，同时不怀好意的往你这里冲过来....\n");
         kill_ob(victim);
         } } }
        if( sscanf(str,"%s往%s离开。", tmp,direction)==2) {
        if ( query_attacker() ) return ;
        hp1 = query("max_hp")/2;
        hitp = query("hit_points");
        if ( bleed = query("conditions/bleeding") || hitp < hp1  )        
        tell_room(environment(this_object()),
        "蛇人战士(warrior)说道: 敌人已经逃走了，快来帮我治疗吧.....\n",this_object());
        return ;
        }  
}        
 