#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(17);
        set_name( "master shu du", "达摩院首席 虚渡" );
        add ("id",({ "monk","master","shu","du"}));
        set_short("达摩院首席 虚渡");
        set("unit","位");
        set_long(@DESC
他是达摩院首席虚渡大师，虽然他拥有及胸的漆黑长髯，但是事实上他已经年近
九十了，红红的脸上时时带著笑容的他号称是少林寺数一数二的使刀名家，江湖
有言：一见修罗，群邪回避。可见他的声誉和武\功\。
DESC
        );
        set("alignment",1200);
        set("wealth/gold",50);
        set("max_hp", 950);
        set("hit_points", 950);
        set("max_fp", 2500);
        set("force_points", 2500);
        set("special_defense", ([ "all" : 40, "none" : 30 ]) );
        set("aim_difficulty", ([ "critical" : 60, "vascular" : 60, ]) );
        set_perm_stat("str",29);
        set_perm_stat("int",25);
        set_perm_stat("dex",25);
        set_natural_weapon(-12,5,8);
        set_natural_armor(67, 25);
	set_skill("longblade",100);
        set_skill("parry",100);
        set_skill("block",100);
        set ("gender", "male");
        set ("race", "human");
	set("attack_skill",CLASS"burn_blade");
	set("gonfus/burn-blade",35);
        wield_weapon(SAULIN_OBJ"blade");
        equip_armor(SAULIN_OBJ"glove3");
        equip_armor(SAULIN_OBJ"shield1"); 
        equip_armor(SAULIN_OBJ"armband1");
        set("inquiry", ([
        "燃木刀法" : "@@ask_blade" ]) );
}

int ask_blade()
{
   int gonfus,check_book_quest;
   object me;
   
   me = this_player();
   gonfus = 0;
   check_book_quest = me->query("book_quest_finish");

   if( !check_book_quest ) {
      tell_object( me, "\n虚渡喝道：身为少林武僧，不赶紧协助找回失去的楞枷经，还敢来找我学武功？\n");
      return 1;            }

   if( me->query("monk_gonfu/burn-blade") ) {
      tell_object( me, "\n虚渡说道：学过了还来？你是太闲没事做是吧.....\n");
      return 1; }

   if( me->query("monk_gonfu/body-def") == 35 ) gonfus++;
   if( me->query("monk_gonfu/bolo-fist") == 35 ) gonfus++;
   if( me->query("monk_gonfu/dragon-claw") == 35 ) gonfus++;
   if( me->query("monk_gonfu/keep-flower") == 35 ) gonfus++;
   if( me->query("monk_gonfu/power-finger") == 35 ) gonfus++;
   
   if( wizardp(me) )
      printf("\nNumber of top 72 gonfus ： %d\n",gonfus);

   if( gonfus < 1 )
      tell_object( me, "\n虚渡厉声说道：拳脚功夫这麽差，还想来学燃木刀法？再过一百年吧...\n");
   else {
      tell_object( me, @MSG

虚渡对你仔细地打量一番.

玄慈说道：不错！以你的能力的确可以学得起燃木刀法。
          来！睁大眼睛，仔细看好！
          
虚渡缓缓地将修罗刀举起，连人带刀缓缓变得赤红.....

忽地！虚渡连续使出燃木刀法中的招式，宛如一条火龙在空中翻腾,
炙热的气息在这儿弥漫开来，令你觉得喘不过气来....

只听得虚渡一声长啸，你心头一震，修罗刀已指住你的咽喉....

虚渡笑道：小子！燃木刀可不是普通的武功喔！没两下子就不要到外头给我丢人现眼...

你向虚渡点了点头.

虚渡收刀说道：好！小子，这就去吧....

MSG );
      me->set("monk_gonfu/burn-blade",0); }

  return 1;

}
