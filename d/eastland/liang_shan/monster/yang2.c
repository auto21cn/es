#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("Yang Zhi","杨志");
    add("id",({"yang","zhi"}) );
    set_short("杨志");
	set_long(@C_LONG
外号青面兽，关西人，五侯杨老令公之孙。忠实老练，行事不□。十八般
武艺，样样俱精，目前为梁山马军大骠骑兼先锋使。他现在正奉公孙先生的
命令(order)把守通往後山的要道。
C_LONG
	);
    set("alignment",100);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",23);
    set_perm_stat( "int",18);
    set_perm_stat( "karma",24);
    set_skill("thrusting",90);	
    set_skill("parry",90);
    set_skill("tactic",95);
    set ("max_hp",550);
    set ("hit_points",550);
    set ("time_to_heal",3);
    set ("wealth", ([ "gold":280]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(45,25);
	set ("aim_difficulty",([ "weakest":40,"vascular":40]) );
	set("special_defense", (["magic":35,"none":20]) );
    set ("weight", 400);
    set( "inquiry", ([
                    "order" :"这是公孙先生的命令，我只负责执行\n"
                    "不要问我为什麽....\n" ,
                    "why" : "叫你别问你还问，小心我K 你喔...\n",
                    "prism" : "这道铁栅是用来防止闲人进入的，以前铁栅後面的森林\n"
                    "曾经是非常好的猎场.....\n",
                    "hunt" : "打猎的事情，你最好去找老花，他最喜欢打猎了...\n",
                    "猎场" : "打猎的事情，你最好去找老花，他最喜欢打猎了...\n",
                    "打猎" : "打猎的事情，你最好去找老花，他最喜欢打猎了...\n",
                    ]) );
    equip_armor(TARMOR"lion_helmet");
    wield_weapon(TWEAPON"ironlance");
    equip_armor(TARMOR"floral_cloak");
    equip_armor(TARMOR"mirror");
    equip_armor(TARMOR"bear_cloth");
}

