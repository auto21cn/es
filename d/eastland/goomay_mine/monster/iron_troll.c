#include <../zeus.h>

inherit MONSTER;

void create()
{       int wine; 
	object ob1, ob2;

	::create();
	set_level(20);
	set_name( "steely troll", "钢铁巨人" );
	add( "id", ({ "troll" }) );
	set_short( "a steely troll", "钢铁巨人" );
	set_long(@LONG
你彷佛看见一座山矗立在你面前，他的全身布满了钢甲．他是段家特地
聘来看守储藏室的．他曾经到过少林寺学武，擅长般若掌，目前没有人
知道他的缺点．可是他对所有来这里的人都用一种敌视的眼光，连段家
的人也不例外，事情似乎不太寻常，找人问问看吧！
LONG
);
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "kar", 30 );
	set_perm_stat( "int", 30 );
	set_skill( "unarmed", 100);
	set_skill( "parry", 100);     
	set_natural_armor( 120, 60 );
	set_natural_weapon( 70, 30, 70 );
	set( "time_to_heal", 6 );
          set("attack_skill","monk/general/bolo_fist");
          set("monk_gonfu/bolo-fist",25);
	set( "max_hp", 1500 );
	set( "max_fp",600);
	set( "force_effect",2);
	set( "force_points",600);
	set( "hit_points", 1500 );
	set( "gender", "male" );
	set( "alignment",-500 );
	set( "wealth/gold", 100 );
	set( "wine",0);
}  
int accept_item(object me,object item)
{       int wine; 
        if ((string)item->query("name")!="da chu"){
	tell_object(me,
	"巨人道：想贿酪我吗？．．．．可是我不喜欢这东西，换点新花样吧！\n\n"
	"说著巨人就把东西丢下了．\n",
	);
        command("drop all");
        return 1;
        }
        if(query("wine"))
        {
        tell_room(environment(this_object()),
        "巨人拿起酒来如灌水般将酒倒进嘴里，道一声：好酒！！\n"
        "然後脚步蹒\跚\地走到河边，噗！一声！倒了下去．\n\n"
        "你看见一把药丸从巨人的口袋中掉出来，滚啊滚到河里去了．\n\n"
                  );
        item->remove();
        set_short("醉倒的巨人");
        set_name("troll","酒醉的巨人");
        set_natural_armor(100,40);
        set("monk_gonfu/bolo-fist",20);
        return 1;
        }else{ 
        tell_room(environment(this_object()),
	"巨人拿起酒来如巨鲸吸水般将所有的酒吸乾，然後擦擦嘴巴意犹未尽\n\n"
	"道：还有没有呢？快拿来孝敬大哥吧！\n\n"
	);
	item->remove();
        set("wine",1);
      	return 1;
               }
}
void die()
{       object killer,obj;
        int wine;
 	if (query("wine")){
 	killer=query("last_attacker");
 	killer->set_temp("get_magnetite",1);
 	tell_room(environment(this_object()),
 	"巨人以忏悔的声音道：四处找找吧，我已经把你要的东西．藏起来了！\n",
 	this_object());
 	set("exp_reward",36000);
 	::die(1);
 	}else{
 	tell_room(environment(this_object()),
 		"巨人大叫道：你想打败我吗？别傻了孩子！\n"
 		"突然巨人从口袋里抓出一把药丸往嘴里一塞．\n\n"
 		"又一个生龙活虎的钢铁巨人．\n",
 		this_object());
 	set ("exp_reward",10); 
 	set ("alt_corpse",ZMOB"/iron_troll.c");
 	::die(1);
 	}
 	}