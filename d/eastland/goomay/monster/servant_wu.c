#include <../goomay.h>
inherit Mob_special ;
int payed;
void create ()
{
        ::create();
        set_level(4);
        set_name( "Wu the servant", "王八老吴" );
        add ("id",({ "servant","wu"}));
        set_short( "王八老吴");
        set("unit","个");
        set_long(
@C_LONG
你看到一个猥琐矮小的汉子，他约莫四五十岁，可是看起来却更老，
营养不良的脸上还留著纵欲过度的痕迹，他提著一只大茶壶，专门
服侍妓院中的嫖客和妓女。
C_LONG
);
        set("alignment",-350);
        set("wealth/silver",10);
	payed=0;
        set_perm_stat("str",7);
        set_perm_stat("dex",7);
        set_perm_stat("kar",6); 
        set_natural_weapon(5,4,9);
        set ("natural_armor_class", 25);
        set_skill("dodge",65);
        set("natural_defense_bonus",5);
        set ("gender", "male");
        set ("race", "human");
        set( "defense_type","berserk");
        set_c_verbs(({"%s用双手向%s乱抓",
                      "%s用脚向%s乱踢",
                      "%s用头向%s撞去"}));
       
        set( "inquiry", ([
                "jor" : "@@ask_jor"]));
        set("special_attack",(["damage_type" : "none","main_damage" : 10,
                                "random_dam" : 5 , "hit_rate" : 20]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"老吴用他的大茶壶洒出滚烫烫的热水，一古脑儿淋在你身上，你感到一阵剧痛...\n\n");
set("c_room_msg","老吴用热水淋向");
set("c_room_msg2", "，把他烫得哇哇叫 ... \n");
	
}

void init()
{
	::init();
        add_action( "tip_me", "pay");
}
int tip_me(string arg)
{
        string who, type;
        int num;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail( 
                        "付谁？多少钱？\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
               tell_object( this_player(),
                        "老吴贼贼的笑道: 大爷 ! 对不起，今年好像流行金币耶。\n");
                return 1;
	}
	if (num<50)
	{
		tell_object(this_player(), 
                 "老吴说道: 大爷 ! 小的一条贱命难道只值这些钱吗？\n" );
		return 1;
	}
	if (num>=50 && payed==0)
	{
                tell_object(this_player(), 
                 "老吴说道: 大爷 ! 小的这就知无不言啦 !! 请问吧 !!\n" );
		payed=1;
                return 1;
	}
        if (num>=500 && payed==1)
        {
                tell_object(this_player(), 
                "老吴说道: 好 !! 我这就带你去 !! \n他带著你穿过怡红院的侧门\n"
		"一路沿著围墙直钻，走著走著，他不知道在墙边按了什麽机关，你\n"
		"突然一脚踏空，直摔了下去\n.\n.\n.\n.\n.\n.\n");
        this_player()->move_player( Goomay"in_yi_hong", "SNEAK" );
		remove();
                return 1;
	}

}

int ask_jor()
{
if (payed==1)
{
	tell_object(this_player(),
@C_WU
老吴道：「既然您已经知道我的事了，我想也用不著瞒您啦，没错 !! 
左无心确实躲在怡红院内，他躲在一个很隐秘的地方，只有我知道，如
果你能再付给我衙门的赏金，我会考虑要不要带你去 !! 不要怀疑啊 !!
这可是卖命的事，你不给自然有人会给。」
C_WU
);
        return 1;
}
else
{
tell_object(this_player(), 
	    "老吴笑道: 大爷 !! 您也是知道的，小的最近手头上有点紧，嘴巴自然也松不下来喽 !!\n" );
	return 1;
}
}
