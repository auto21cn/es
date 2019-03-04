#include "mudlib.h"
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(4);
        set_name( "little boy", "童子" );
        add ("id",({ "boy"}));
        set_short( "童子");
        set("unit","位");
        set_long("",
@C_LONG
他是一个十岁大的孩子，正没精打彩的坐在药炉边守著炉火。手中的扇子
偶而会晃一下, 又停了。看他无聊的样子, 可能希望有人陪他聊聊吧。
C_LONG
);
        set("alignment",0);
        set("wealth/silver",15);
        set_perm_stat("str",10);
        set_perm_stat("dex",8);
        set_perm_stat("kar",8); 
        set_natural_weapon(5,3,6);
        set ("natural_armor_class", 20);
        set_skill("dodge",35);
	set("defense_type","dodge");
        set("natural_defense_bonus",2);
        set ("gender", "male");
        set ("race", "human");
	 set( "inquiry" , ([
		"wang" : "师父在书房歇著, 您有事吗?",
		"herb" : "珍贵的药材通常都很难找..上次去采药还差点被毒蛇咬死。\n",
		"oven" : "师父炼的药都是用这个炉子炼的。\n", 
		"painting" : "@@ask_painting",
	]));
       
}

void ask_painting(object who)
{
	tell_object(who, 
"你是说师父墙上挂的画吗? 自从来到这里後, 师父常常对这那画发呆。有一次我\n"
"走进书房里, 师父不在, 可是过一会儿却从书房走出来 ... 好奇怪喔 \n"
	);
}


