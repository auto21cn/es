#include "../island.h"

inherit IWAR"i_warvalue";

void create()
{
    ::create();
    set_level(19);
    set_name("General Hamiya","火美猛将军");
    add("id",({"general","hamiya"}) );
    set_short("定远将军 火美猛");
    set_long(@LONG
定远将军火美猛是魔族远征部队的总指挥，归神武将军直辖。他的身上布满了
历次战争中留下的大小伤痕，嗯.......或许他杀过的人比你吃过的米多哦！	
LONG
            );
    set("unit","位");
    set("gender","male");
    set("race","daemon");
    set("alignment",-1000);
    set("time_to_heal",5);
    set("pursuing",1);
    set("killer",1);
    set_natural_armor(51,20);
    set_natural_weapon(35,15,25);
    set_perm_stat("str",22);
    set_perm_stat("dex",25);
    set_perm_stat("int",30);
    set_perm_stat("kar",20);
    set("max_hp",600);
    set("hit_points",600);
    set_skill("tactic",100);
    set_skill("parry",100);
    set_skill("longblade",100);
    set_skill("block",100);
    set("justice",15);
    set("tactic","flank");
    set("wealth/gold",150);
    set("special_defense",(["all":30,"none":20]) );
    set("aim_difficulty",(["critical":80,"vascular":10,"ganglion":0]) );

    wield_weapon(IWARO"sword3");
    equip_armor(IWARO"t_shield2");
    equip_armor(IWARO"t_helmet1");
    equip_armor(IWARO"t_boot1");
    equip_armor(IWARO"t_mail2");
}

