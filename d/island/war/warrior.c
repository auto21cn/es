#include "../island.h"

inherit IWAR"i_warvalue";

void create ()
{

	::create();
    set_level(12);
    set_name("Daemon warrior","魔族狂战士");
    add ("id", ({ "warrior","daemon"}) );
    set_short("魔族狂战士");
	set_long(@C_LONG
一位狡勇善战的魔族狂战士。
C_LONG
	);
    set("alignment",-100);
    set("gender","male");
    set("race","daemon");
    set("unit","位");
    set("justice",3);
    set_perm_stat("dex",13);
    set_perm_stat("str",17);
    set_perm_stat("int",8);
    set_perm_stat("pie",8);
    set_perm_stat("kar",15);
    
    set_skill("block",60);
    set_skill("parry",55);
    
    set ("max_hp",350);
    set ("hit_points",350);
    set ("wealth/gold",20);
    set ("killer",1);
    set ("pursuing",1);
    set ("chat_chance",20);
    set ("att_chat_output",({
        "狂战士喝道：高贵圣洁的守护灵们，请赐与我力量拯救这些悲苦的人们吧！！！\n",
        "狂战士大吼著：Ｐｏｗｅｒ　ｕｐ.........代替诸神处置你们这些背信者！！！\n"
        }) );
    set_natural_weapon(15,6,12);
    set_natural_armor(41,11);
    set ("weight", 750);
    wield_weapon( IWARO"spear1");
    equip_armor( IWARO"t_shield3");
}


