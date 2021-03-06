#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(17);
    set_name("Hua Rong","花荣");
    add("id",({"hua","rong"}) );
    set_short("花荣");
	set_long(@C_LONG
外号小李广，青州人，嫉恶如仇，忠勇仗义，使一副弓箭，箭术通神，百步穿
杨，目前为梁山马军大骠骑兼先锋使。他最大的嗜好是上山打猎。
C_LONG
	);
    set("alignment",400);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",30);
    set_perm_stat( "str",21);
    set_perm_stat( "int",20);
    set_perm_stat( "karma",20);
    set_skill("blunt",90);	
    set_skill("dodge",100);
    set ("max_hp",470);
    set ("hit_points",470);
    set ("time_to_heal",3);
    set ("wealth", ([ "gold":280]) );
    set_natural_weapon(25,15,25);
	set_natural_armor(40,22);
	set ("aim_difficulty",([ "weakest":20,"vascular":30]) );
	set("special_defense", (["magic":30,"none":10]) );
    set ("weight", 400);
    set( "inquiry", ([
             "hunt" :"@@ask_hunt1",
             "打猎" :"@@ask_hunt1",
             ]) );
    equip_armor(TARMOR"fur_hat");
    wield_weapon(TWEAPON"bow");
    equip_armor(TARMOR"mirror");
    equip_armor(TARMOR"beast_plate");
    equip_armor(TARMOR"darkgreen_cloak");
}
int ask_hunt1()
{
    command("sigh "+(string)this_player()->query("name"));
    call_out("ask_hunt2",5,this_player());
    return 1;
}
int ask_hunt2()
{
    write(@C_LONG
花荣说道: 打猎是我唯一的休闲娱乐，可是自从上次，有两个笨蛋
在後山被一条金色的大蛇拖进那个山洞之後，山寨就再也不准大家上山
打猎了，其实，以我的功夫和箭术，一百条大蛇我也不放在眼里。
C_LONG);
    command("snort ");
    return 1;
}           