#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "daughter unary", "月读" );
    add( "id",({"daughter","unary"}) );
    set_short( "全副帮主的女儿 月读");
    set_long(@LONG
月读看起来约莫十五、六岁年纪,剑眉凤眼,双眉中略带一丝英气,平时更自比『花
木兰』之流,颇有巾国女英雄之貌。她生平嫉恶如仇,路见不平往往拔刀相助,所以
你最好不要做坏事喔, 被她缠上可是无法善罢干休的。
LONG
            );
    set("unit","位");
    set("race","human");      
    set("class","healer");
    set("age",17);
    set("gender","female" );
    set("alignment",6000);
    set( "forgetful",1);
    set("weight",600);
    set("wealth/silver",420);
    set_perm_stat("str",23);
    set_perm_stat("dex",22);
    set_perm_stat("int",23);
    set("hit_points",500);
    set("max_hp",500);
    set_natural_armor(40,28);
    set_natural_weapon(12,15,20);
    set_skill("dodge",70);
    set_skill("parry",75);
    set_skill("blunt",80);
    set_skill("anatomlogy",85);
    set("special_defense", ([ "all": 50,"none":30]) );
    set("aim_difficulty",
    (["critical":65,"vascular":40,"ganglion":70,"weakest":65]) );
    set("stun_difficulty",90);
    set("aiming_loc","weakest");
    wield_weapon(DWEAPON"seven_blunt");
    equip_armor(DARMOR"seven_gloves");
    equip_armor(DARMOR"seven_boots");
    equip_armor(DARMOR"seven_cloth");
    set( "inquiry", ([
              "father":"@@ask_father",
                 "uki":"@@ask_uki"
    ]) );
}        

void init()
{ 
  ::init();
  add_action("do_angry","slap");
  add_action("do_angry","kick");
  add_action("do_angry","kiss");
  add_action("do_angry","hold");
  add_action("do_angry","flog");
  add_action("do_angry","lkiss");
  add_action("do_angry","smirk");
  add_action("do_angry","excite");
  add_action("do_angry","puke");
  add_action("do_angry","snort");
  add_action("do_angry","bite");
  add_action("do_angry","lick");
  add_action("do_angry","bark");
  add_action("do_angry","fart");
  add_action("do_angry","spit");
}

void do_angry(string arg)
{
   call_out("do_kick",2,arg);
}

void do_kick(string arg)
{
    if (arg=="unary"){
       tell_object( this_player(),
          "\n月读愤怨地向你说道:你这该死的小子去死吧 !!\n\n");
       tell_room( environment(this_object()),
          "\n月读似乎对"+this_player()->query("c_name")+
          "很不爽并对他采取攻击!!\n\n",this_player());
       this_object()->kill_ob(this_player());
       this_player()->block_attack(8);
       this_player()->set_temp("msg_stop_attack","(  你太失礼了,因而被拦住了动弹不得 !!  )\n");
       return ;
    }
}
void ask_father( object asker )
{
     tell_object( asker,
       "月读说道:咦,你问我爹爹喔?我不知道他在那里耶。\n"
       "月读叹道:唉,爹爹不知道从什麽地方打听到我祖父的下落,就整个人心神不宁,\n"
       "         一直嚷嚷著要见我祖父。这几天不知道从那里来了一个奇怪的人,自\n"
       "         他来了之後,爹爹就不常理我了。\n"
       "月读说道:对了,你可以去找项长老,他和我爹最熟了。\n"
       );
     asker->set_temp("unary_asked",1);
}
void ask_uki()
{
write(@C_LONG
月读邪恶地说道:小雪子喔,她胸部很大哟!!
C_LONG 
    );
}