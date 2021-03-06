#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Ro Yubin", "骆语冰" );
	add( "id", ({ "ro", "yubin", "scholar" }) );
	set_short( "玉剑书生 骆语冰" );
	set_long("@@query_long");
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 1000 );
	set( "hit_points", 1000 );
	set( "max_hp", 1000 );
	set( "max_fp", 3000 );
	set( "force_points", 3000 );
	set_natural_armor( 120, 50 );
	set_natural_weapon( 28, 10, 15 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "pie", 20 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "kar", 30 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "inner-force", 100 );
	set_skill( "tactic", 100 );
	set( "tactic", "melee" );
        set( "tactic_func", "my_tactic");
        set( "flute",0);
	set( "force_effect", 8 );
	set( "force_type", "cold" );
	set( "wealth/gold", 300 );
	set( "attack_skill", "scholar/poem" );
	set( "scholar_gonfu/poem", 50 );
        set( "class", "scholar");
	set( "special_defense", ([ "all": 50,"none":60 ]) );
	set( "aim_difficulty", ([ "vascular":80 ]) );
   
//	wield_weapon( "/d/scholar/scholar/weapons/ebonysword" );
}

string query_long()
{
  if (!(this_object()->query("flute")))
    return  "你看到一位相貌俊雅的少年书生，坐在一张黑檀木长桌旁边，桌上摆\著一只古玉萧，\n"+
  "手中一本残破不堪的旧书，正聚精会神地读著。\n";
  else
    return "你看到一位相貌俊雅的少年书生，坐在一张黑檀木长桌旁边，一只手拿著一只古玉萧，\n"+
  "另一只手中拿著一本残破不堪的旧书，正聚精会神地读著。\n";
}

int my_tactic(string arg)
{
  object ob;
  int rrr;

  ob=this_object()->query_attacker();
  if (this_object()->query("flute")) {
    rrr=random(15);
    if (rrr<4) {
      tell_room(environment(this_object()), set_color(
         "\n骆语冰突然把古玉箫拿到嘴边吹出一阵奇异的声音.....\n\n"
      ,"HIR",ob));
    }
    if (rrr<5) {
      switch (rrr) {
       case 0:
         tell_object(ob,set_color( "你见到地面突然裂开，大地精灵从中冲了出来向你施展它的必杀技：十字锁喉反扣。\n","HIM",ob));
         tell_room(environment(this_object()),set_color("你见到地面突然裂开，大地精灵从中冲了出来向"+ob->query("c_name")+"施展它的必杀技：十字锁喉反扣。\n","HIM",ob),ob);
         ob->block_attack(2);
         ob->set_temp("msg_stop_attack", "（ 你现在被大地精灵扣住，动弹不得，无法攻击 ）\n");
         command("scholar 可恶的"+(string)ob->query("c_name")+"竟敢跑到书生公会来撒野 !!\n");
         break;      
       case 1:
         tell_object(ob,set_color("突然晴天一声霹雳，火精灵挟著雷霆之势从天而降，火精灵把口一张，从嘴里向你射出一团火□。\n","HIR",ob));
         tell_room(environment(this_object()),set_color("突然晴天一声霹雳，火精灵挟著雷霆之势从天而降，火精灵把口一张，从嘴里向"+ob->query("c_name")+"射出一团火□。\n","HIR",ob),ob);
         ob->receive_special_damage("fire",20);
         command("scholar 书生们 ! 等我把"+(string)ob->query("c_name")+"给宰了，你们就可以来分装备了 !!\n");
         break;
       case 2:
         tell_object(ob,set_color( "你感觉到一道剑气直射而至，剑魂化成一把宝剑在空中飞舞著，突然，宝剑一气化三元，三把宝剑剑锋向你吐出红蓝绿三色剑芒。\n","HIW",ob));
         tell_room(environment(this_object()),set_color( "你感觉到一道剑气直射而至，剑魂化成一把宝剑在
空中飞舞著，突然，宝剑一气化三元，三把宝剑剑锋向"+ob->query("c_name")+"吐出红蓝绿三色剑芒。\n","HIW",ob),ob);
         BLEEDING->apply_effect(ob,4,5);
         if ((string)ob->query("class")=="scholar")
           command("scholar 想不到 ... "+(string)ob->query("c_name")+"竟是我们公会里的叛徒，那我就不客气了 !!\n");
         else
           command("scholar 嘿嘿 ! 不要命的"+(string)ob->query("c_name")+"，不给你一点颜色瞧瞧，你是不会乖乖听话的 !!\n");
         break;
       case 3:
         tell_room(environment(this_object()),set_color("你见到天空一朵乌云飘来，水精灵从中飘了出来，水精灵用手触摸骆语冰的伤口之後，水精灵又随著乌云飘走了。\n","HIB",ob));
         this_object()->receive_healing(20);
         command("scholar 书生们 ! 大家来ＰＫ"+(string)ob->query("c_name")+"吧 !!\n");
         break;
      default: 
         command("scholar "+(string)ob->query("c_name")+" !! 明年的今天就是你的忌日 !!\n");
         break;
      };
    }
    return 0;
  }
  tell_room(environment(this_object()),"玉剑书生 骆语冰从长桌上拿起古玉萧\n");
  ob=new("/d/scholar/scholar/weapons/flute");
  ob->move(this_object());
  command("wield flute");
  ob=new("/d/scholar/jade_mark");
  ob->move(this_object());
  this_object()->set("flute",1);
  return 1; 

}

void die()
{
	object killer,weapon,ob;

	killer = query("last_attacker");
	if ( !killer) {
		::die();
		return ; 
	}
        command("scholar "+(string)killer->query("c_name")+" !! 虽然我不小心被你打败，但我的冤魂会永远的缠著你的 !!!\n");
        ob=query("guild");
        ob->remove();
        weapon=query("weapon1");
        weapon->set("killer",killer);
	::die();
	return;
}
