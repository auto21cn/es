#include "../mad.h"
#include <ansi.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "elder Guo", "郭长老" );
        add ("id", ({ "elder", "guo" }) );
        set_short( "郭长老" );
        set("unit","位");
        set_long(@C_LONG
你看到一位白须垂胸, 面色略显严肃的高瘦老者。相传他曾於三十六岁时,
不腾挪半步, 独自静坐於大海旁危□之上, 达七昼夜之久, 而最後终於顿悟
出江湖中人人渴求敬畏的『怒潮三曲』。且三十年前, 郭长老为了搭救至友
刑老爹, 於牧马关外一役, 凭著一把玉箫, 独力歼灭追杀之敌数百人!
C_LONG
        );
        set("alignment",1200);
        set("wealth/copper",100);
        set("gender","male");
        set("race","human");
        set("tactic_func","special_attack");
        set("hit_points",850);
        set("force_points",2500);
        set("max_hp",850);
        set("max_fp",2500);
        set_perm_stat("str",25);
        set_perm_stat("dex",30);
        set_perm_stat("pie",30);
        set_perm_stat("kar",24);
        set_perm_stat("con",22);
        set_perm_stat("int",28);
        set_natural_weapon(30, 12, 28);
        set_natural_armor(100,50);
   set( "special_defense", ([ "all": 60, "none": 20 ]) );
        set( "aim_difficulty",([ "weakest":25,"vascular":30,"ganglion":20 ]) );
        set( "stun_difficulty",50 );
        set_skill("dodge",100);
        set_skill("shortblade",100);
        set_skill("parry",100);
        set_skill("inner-force",100);
        wield_weapon( IANOBJ"flute" );
        set("inquiry", ([
          "hsin" : "老刑!?老夫甚久未与他碰面了.....\n"
                   "听说他隐居於西方的大陆之中, 还收了不少徒子徒孙!\n",
          "burglar" : @C_LONG
约莫半年之前, 本村突现一采花贼, 辣手摧残无辜
少女, 於是许\多有闺女之人家纷纷迁离此处, 以致本村凋敝若今
。而当老夫奋力追查其踪时, 恶贼竟闻风而逃, 销声□迹! 此後
, 老夫遍寻四方, 盼能捕捉并手刃此贼。不意, 此贼竟又回至此
处! 老夫由幽国城日夜兼程赶回, 宵旰巡查--可叹仍然一无所获
。或许\小张曾发现其踪(trace),您去问问他吧。
C_LONG
        ]) );
}

void init()
{
   npc::init();
   add_action( "inform_me", "inform" );
}

int inform_me(string arg)
{
   object hero;

   hero = this_player();

   if( !arg || ( arg!="elder" && arg!="guo" ) )
        return notify_fail( "你要通知谁啊?\n" );
   if( (int)hero->query_quest_level("iywolf")<1 ) {
        if( !hero->query_temp("kill_ian_devil") )
        return notify_fail( "郭长老摇头道: 去! 去! 老夫没空听你说书...\n" );
        tell_object( hero, @OK
郭长老叹道: 原来淫魔竟是桂老的化身! 无怪乎小梅在小张
之羽翼下仍遭毒手 ........
感谢大侠您为本村及世上除去一大害。老夫代表本村致十万
分之谢意, 并奉上一点薄礼, 望您笑讷。

[ 郭长老翻箱倒柜找出一袋钱币交给你 ]
[ 你完成了『烟雨村之狼』的任务, 得到八千点经验值 ]
OK
        );
   if( (string)hero->query("class")=="adventurer"
     && (int)hero->query_level()> 4 )
   tell_object( hero,
        "噢！差点忘了！大侠您可以去找小张教您某个技巧(skill)。\n" );
        hero->finish_quest("iywolf",1);
        hero->gain_experience(8000);
        hero->credit("copper",5000);
        return 1;
   }
   write(
"郭长老微笑道: 大侠, 您的作为, 老夫深感敬佩,\n"
"但本村地小人穷, 实在没有多馀的钱给您了。\n" );

   return 1;
}

int special_attack()
{
   object *victim, *weapon1, *weapon2;
   int i, num;
    
   victim = (object *)this_object()->query_attackers();
   weapon1 = victim->query("weapon1");
   weapon2 = victim->query("weapon2");
   num = sizeof(victim);

   if( !victim || random(20)<15 ) return 0;

   if( num == 2 ) {
     tell_room( environment(this_object()),
        "\n郭长老开始吹奏『怒潮三曲』之『惊涛骇浪』........\n\n"
        "一种无形的声浪袭向你的身体!!\n\n",
     this_object() );
     (CONDITION_PREFIX + "confused")->apply_effect( victim[1], 6, 10 );
     (CONDITION_PREFIX + "confused")->apply_effect( victim[0], 6, 10 );
     victim[1]->block_attack(10);
     victim[0]->block_attack(10);
     victim[1]->set_temp("msg_stop_attack", 
        "( 你被一种无形的声浪困住, 无法攻击！ )\n" );
     victim[0]->set_temp("msg_stop_attack", 
        "( 你被一种无形的声浪困住, 无法攻击！ )\n" );
     return 1;
     }

   if( num == 3 ) {
     tell_room( environment(this_object()),
        "\n郭长老开始吹奏『怒潮三曲』之『推波助澜』........\n\n"
        "你们竟不自主地攻击同伴!!\n\n" );
     victim[1]->cease_all_attacks();
     victim[2]->cease_all_attacks();
     victim[0]->cease_all_attacks();
     victim[1]->kill_ob(victim[2]);
     victim[2]->kill_ob(victim[0]);
     victim[0]->kill_ob(victim[1]);
     return 1;
     }

   if( num > 3 ) {
    for( i=0; i<sizeof(victim); i++ ) {
     tell_object( victim[i],
        "\n郭长老开始吹奏『怒潮三曲』之『排山倒海』........\n\n"
        "你们被一阵音浪冲撞, 武器脱手, 飞出屋外!!\n\n" );
     if( victim[i]->query("weapon2") ) {
        weapon2[i]->unwield();
        weapon2[i]->move(environment(this_object()));
        victim[i]->calc_weapon_class();
        weapon1[i]->unwield();
        weapon1[i]->move(environment(this_object()));
        victim[i]->calc_weapon_class();
        }
     if( !victim[i]->query("weapon2") && victim[i]->query("weapon1") ) {
        weapon1[i]->unwield();
        weapon1[i]->move(environment(this_object()));
        victim[i]->calc_weapon_class();
        }
     }
    for( i=0; i<sizeof(victim); i++ ) {
        victim[i]->receive_special_damage("energy",100);
        victim[i]->move_player(IAN"hamlet_path2",
                   "你被震出屋外!\n", "一团黑影从北方的屋中摔出!\n" );
        }
    return 1;
   }
   return 1;
}

int accept_item(object who,object item)
{
   if( item->id("corpse") ) {
     tell_room( environment(this_object()),
        "郭长老道: 老夫虽然酷爱收藏物品, 但□体还是免了!\n"
        "[ 郭长老说著说著就把"+item->query("c_name")+"丢在地上! ]\n"
        , this_object() );
     item->move(environment(this_object()));
     return 1;
     }
   tell_room( environment(this_object()),
        "郭长老道: 多谢! 老夫最喜爱收藏物品!\n"
        "[ 郭长老说著说著就把"+item->query("c_name")+"收了起来! ]\n"
        , this_object() );
   item->remove();
   return 1;
}

void die()
{
   object *flute, pipe;

   flute = children( "/d/eastland/ianyeu/obj/flute" );
   pipe = present( "flute", this_object() );
   if( sizeof(flute ) > 1 ) {
        tell_room( environment(this_object()),
		"郭长老大叫一声: 不! 我不能死! 你们想要我的玉箫？等下辈子吧!\n"
		"郭长老把玉箫插进自己的心脏并同时折断玉箫!\n",
                this_object() );
        pipe->remove();
   }
   ::die();
}
