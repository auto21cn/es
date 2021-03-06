#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Samurai sika", "武士 星卡" );
	add( "id", ({ "samurai","sika" }) );
	set_short( "Samurai sika", "武士 星卡" );
	set_long(@AAA
你眼前是一位年轻的武士，虽然他年纪轻，但他以得到影流剑法奥义,目前是
武士团中的副队长，但根据可靠消息来源指出，他的剑技已是武士之冠！！！
而在另一方面星卡也是著名的史学家，你如果有兴趣可以问他历史(history)
的事，又据说只要是他带兵出去就不会输，你也可以问他关於战争不败之法
(win)！！
AAA
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 18 );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "kar", 20 );
        set_perm_stat( "pie", 20 );    
        set( "max_hp",650 );
        set( "hit_points",650 );
 	set_natural_armor( 45,25 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 35 ); 
        set( "time_to_heal",30);
        set( "special_defense",([ "all":25,"none":25 ])); 
        set( "aim_difficulty",([ "critical":80,"weakest":20,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty/ma",15);  
	set( "alignment", 1000 );
	set_c_limbs( ({ "头部", "身体", "手腕", "咽喉" }) );
	set_c_verbs( ({ "%s右手手刀往%s的咽喉猛力一劈", "%s左手直拳向%s的小腹击来" }) );
        set_skill( "parry",85 );
        set_skill( "longblade",100 );
        set_skill( "dagger",100 );
        set( "wealth" , ([ "gold": 100 ]) );
        set( "tactic_func", "att_gonfus");
        set( "weight", 400 );    
        wield_weapon(MOBJ"black_ya_sha");
        equip_armor(MOBJ"samurai_gloves.c");
        equip_armor(MOBJ"samurai_cloth.c");
        equip_armor(MOBJ"samurai_boots.c"); 
        set("inquiry",([
            "win":"@@ask_win",
            "history":"@@ask_history",
            "continue"  :"@@ask_part",
            "war"       :"@@ask_war"
            ]));
}
int ask_win()
{
write(@AAA
星卡说道：其实不败的秘诀很简单，就是不打没有把握的仗，当退则
　　　　　退，决不拖泥带水，就如同打怪物时要设wimpy，wimpy跑
          时就跑那就不会死了，不过逃不掉时是例外啦！！
AAA
);
return 1;
}
int ask_history()
{
write(@AAA
星卡说道：其实我们的老祖先应该是诺顿王国的人吧，只是当初因为对於
　　　　　军队改革的立场不同，和当时诺顿骑士团的当权者有意见上的
　　　　　冲突，而後来因为有心人的煽风点火，进而演变成武力上的对
　　　　　决，而那时我们毕竟只是一个新起的流派，人数上不是正统骑
　　　　　士的对手，所以被迫迁徙到这个岛来，刚到这里时，环境还很
　　　　　好，我们也在此过的不错，人口也大幅提升，那时和蜥蜴人也
　　　　　和平相处，只是後来发生一些灾变，为求生存就必须和蜥蜴抢
　　　　　夺剩下来少数能居住的土地了，那时因为蜥蜴人没有组织，即
　　　　　使我们只用接受骑士训练的骑士就能打败他们，所以早期并没
　　　　　有像现在有如此大的武士团，．．hmm 我喝口水．你如果还想
　　　　　再听下去就在问我 (continue)
AAA
);
return 1;
}
int ask_part()
{
write(@AAA
星卡说道：那为什麽现在有如此大的武士团组织，那是由於在我们击败
　　　　　蜥蜴人之後，蜥蜴人不知道从哪里得到消息，知道我们的部队是
　　　　　在诺顿大陆得到的训练，於是他们就秘密派了一批较为聪明的蜥
　　　　　蜴人到诺顿去，而这批人回来後就组成相当有名的蜥蜴骑士团，
　　　　　由於蜥蜴人天生体格强健，我们人类组成的骑士团遇到他们根本
　　　　　就不是对手，在战况不利的状况下，当初我们所谓能实行的改革
　　　　　军队方案又搬上台面了，那时我们开始秘密训练武士团，而就在
　　　　　训练完成的时候，我们一口气突击了蜥蜴人数个据点，终於板回
　　　　　我们军事上的劣势，所以目前我们和蜥蜴人是在个平衡状态，而
　　　　　再三十年前突然发现东方山区内有个魔族的势力，本来试想一口
　　　　　气将其占领并吞其力量，那我们就可以消灭蜥蜴人的势力了，然
　　　　　後就．．．．．想再听就问(war)吧！！！
AAA
);
return 1;
}
int ask_war()
{
write(@AAA
星卡说道：那一战可说是武士团成军以来最大的挫败，那时我们集结了三个
　　　　　大队的精锐武士，由当时的副团长牙神幻十郎带领，另外还有当
　　　　　时年轻武士的佼佼者地场卫．鹰村守．以及我的师父日向左近等
　　　　　好手带领，这些人出战连蜥蜴人都要惧怕三分，但没想到魔族本
　　　　　身的战力虽不及蜥蜴人，但凭藉著其天险，在我们攻进他们城内
　　　　　时，以少了一半的兵力，剩下来的部队在敌人占多数的情形下也
　　　　　只好撤退，而当时带队的牙神也为了掩护撤退儿战死，鹰村和地
　　　　　场则是在城内被围杀而亡，只有我师父留下，而由此战後我方战
　　　　　力大伤，但魔族也好不到哪去，虽然攻入城内的人不多，但是仍
　　　　　给魔族造成不小伤害，而在我们失败後蜥蜴人也采取了攻势，虽
　　　　　然他们也派出了蜥蜴人最强的部队，但是被魔族．．．．．．．
　　　　　　据说是他们守护神显灵啦，才击退蜥蜴人，总之从那战之後呢
　　　　　三国势力又成一个均衡形式，而也在个奇怪的情况下签下和平条
　　　　　约，而怎麽签下我是觉得太夸张了，所以我现在仍在研究中，你
　　　　　可别相信魔族那只白痴鹫羽的说法，怎麽会有神呢？我可是不相
　　　　　信那种说法一点历史概念都没有．．．．．！！！
AAA
);
return 1;
}



int att_gonfus()
{
     object victim;
     int dam;
     
     if( !(victim = query_attacker()) || (random(20)>2) ) return 0;
     tell_room(environment(this_object()), 
	"\n星_卡大声喝到:小子我要让你知道你有多愚蠢来向我挑战\n突然间，你发现星＿卡的刀消失了！！　\n\n"+
     "星_卡大喝一声：接我的″不～动～冥～王～斩″\n\n"+
     "那把消失的刀突然在面前出现,并在"+victim->query("c_name")+"的胸前划出一到极深的伤口\n"
      );
      dam = 20 + random(25);
      victim->receive_special_damage("energy", dam );
      report(this_object(),victim);
      return 1;
      
}
