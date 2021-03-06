
#include "/d/eastland/goomay/goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(18);
        set_name( "Master of blacksmith", "剑庐主人－段铁" );
        add ("id",({ "blacksmith","master"}));
        set_short( "剑庐主人－段铁");
        set("unit","位");
        set_long(
@C_LONG
他就是有当今天下第一铸剑师的剑庐主人段铁，段家铸剑已经有几百年的历
史了，其中段铁是最杰出的，传说他除了冶炼金属的本事一流以外，还拥有
将魔法注入武器中的能力，所以他亲手锻造的武器可以发出超越一般武器的
可怕威力。不过，他近年来已经很少亲自动手了，而专心於弟子的训练，所
以剑庐的锻造技术仍然冠绝当世。
C_LONG
);
        set ("gender", "male");
        set ("race", "dwarf");
        set_natural_armor( 90, 20 );
	set_natural_weapon(25,5,15 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 30 );
        set_skill( "longblade", 100 );
        set_skill( "parry", 100 );
	set("hit_points",1200);
	set("max_hp",1200);
        set( "special_defense", ([ "all": 40 ]) );
	set( "wealth/gold",100);
        wield_weapon( Obj"love_sword" );
        equip_armor( Obj"lovekey" );
        set( "inquiry", ([
                "fire"  : "@@ask_fire",
		"weapon" : "@@ask_weapon",
		"key" : "@@ask_key", 
        ]) );

}
int ask_key()
{
   tell_object(this_player(),
@ASK_KEY
段铁说道：有个锁住的门啊！嗯．．让我想想．．．．．．．．．．
我知道我的族人中有人一直保存著一块先祖所铸的封印，也许对你会
有帮助，你可以到矿坑里面去问问看，他应该还在里边做监工！
ASK_KEY
);
}
int ask_weapon()
{
        object me ;
        me=this_player();
        if( (int)this_player()->query_quest_level("Goddess_statue") > 1 ){
                tell_object(me,
                "段铁笑道：「恩人 !! 段铁愿意随时为你效劳，但是你要给我适当的材料啊 !!」\n"
			    );
                return 1;
	}
        else
        {
                tell_object(me,
                "段铁叹道：「我哪有这心情啊？炉子没火啊 !!」\n");
		return 1;
	}
}

int receive_metal()
{
   object ob;
 if (this_player()->query_temp("get_magnetite")){
      tell_object(this_player(),
@METAL
段铁拿起磁铁矿看了看道：嗯！这的确是我们家中珍贵的魔法磁铁矿，想
不到竟然可以重回到我们手里，真是太感谢你了，我拿出一些做成武器来
答谢你吧！
  说完，段铁便转身回到火炉边开始工作
METAL
);
   call_out("make_weapon",3,this_player());
}else{
	tell_object(this_player(),
@NOGET
段铁看了看你之後说：你又不是打死巨人的英雄，不过还是谢谢你把磁铁
矿送回来．
NOGET
);
}
}
int receive_cloth()
{
        object ob ;
	tell_object(this_player(),
@CLOTH
段铁讶异地接过破布片，然後仔细地读了起来，他叹了一口气道：「原来
如此 !! 难怪有不准移动炉子的祖训，我还以为只是迷信而已，看来现在
正是火妖转形的时刻了，请你务必帮我这个忙，你可以把炉子(furnace)
移开看看 ..
CLOTH
	);
}

int ask_fire()
{
	object me ;
	me=this_player();
        if( (int)this_player()->query_quest_level("Goddess_statue") > 1 ){
		tell_object(me,
		"段铁笑道：「多谢恩人的关心 !! 现在的炉火很正常」。\n");
		return 1;
	}
	else
	{
                tell_object(me,
@FIRE
段铁叹道：「唉 !! 没想到这种事居然发生在我身上，我一直以为它只是个
传说，现在真叫我给碰上了，我的炉子最近出了问题，炉火怎麽也升不起来
，古老的传说说这是火妖作祟，如果取得火妖身上的火之精就可以使炉火重
燃，可是我上哪儿去找火妖呢？还有一大批订单要赶，唉 !! 看来剑庐的信
誉要扫地了。
FIRE
			    );
	return 1;
	}
}
int fix_symbol(object me)
{
	object ob;
	tell_object(me,"段铁站了起来，拿著一面金光闪闪的东西，满脸满意的笑容。\n");
	ob = new(Obj"royal_mark");
	ob->move(this_object());
	command("give mark to "+me->query("name"));
	command("smile "+me->query("name"));
	return 1;
}
int make_weapon(object hero)
{
        object ob;
        tell_object(hero,"段铁站了起来，拿著一把通体银白的匕首，向你走了过来．\n");
        ob = new("/d/eastland/goomay_mine/obj/dagger");
	ob->move(this_object());
	ob->set("master",hero->query("name"));
	command("give dagger to "+hero->query("name"));
	command("smile "+hero->query("name"));
	return 1;
}
int accept_item(object me,object item)
{
	string name;

	name = (string) item->query("name") ;
	
	if ( name !="fire element" && name !="broken cloth" 
		&& name !="broken symbol"  ||
	 (int)this_player()->query_quest_level("Goddess_statue") > 2 ) {
	   if (name== "magic magnetite"){
	   item->remove();
   receive_metal();
	   return 1;
	       }
        tell_object(me,
	"段铁摇摇头：「谢谢 !! 我不需要这东西 !!」\n");

        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
	if ( name=="broken cloth")
	{
	item->remove();
	receive_cloth();
	return 1;
	}
	if ( name == "broken symbol" ) {
	 if ((int)this_player()->query_quest_level("Goddess_statue") != 2 ) {
		tell_object(me,
			    "段铁摇摇头：「谢谢 !! 我不需要这东西 !!」\n");
		command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
		return 1;
	 }
		item->remove();

		tell_object(me,@SYMBOL
段铁把金块翻来覆去的看，不断的喃喃自语，然後转过身去在一张小桌子
前面坐下来，开始专心的工作。
SYMBOL
		);
		call_out("fix_symbol",5,me);
		return 1;
	}
       if ((int)this_player()->query_quest_level("Goddess_statue") != 1 ) {
     tell_object(me,
        "段铁摇摇头：「谢谢 !! 我不需要这东西 !!」\n");

        command("give element to "+(string)me->query("name"));
        return 1;
	  }

     tell_object(me,
@MISSION
段铁高兴的抱住你大笑道：「谢谢你 !! 你真是我段家的恩人，剑庐又可以
继续工作了，今後有什麽需要我段铁的地方，请你尽管吩咐 !!」
段铁又道：「我的这位旅行武斗家朋友，他精通空手搏击的技巧，你可以去
试试运气」
他将火之精放入炉中，瞬时炉火转青，所有的铁匠都大声欢呼，开始努力工
作，一时之间，打铁的叮当声又响成一片。

MISSION
		);
	tell_object(me,set_color(
			"你感染了铁匠们的快乐，觉得精神为之一爽 ! [你得到 3000 点经验]\n","HIY")
		    );
                item->remove();
	me->finish_quest("Goddess_statue",2);
	me->gain_experience( 3000 );

        return 1;
}
