#include "/d/eastland/story/story.h"

inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "Wing Archelder Queen", "羽后" );
	add ("id", ({ "elder","archelder","queen"}) );
	set_short( "羽民族大首领 羽后");
	set_long(@CLONG
一个岁数很大的羽民族人；他满脸皱纹纵横，牙齿业已掉落大半，翅膀渐渐退化只
剩下两个突起的肉瘤，弯腰驼背走起路来一□一□的全□著手中木杖搀扶。虽然他
年纪大，头脑相楚清楚一点也不含糊，平时果断公正兼之阅历丰富遂成了村中最有
权威的人，凡事悉听他裁决。羽后同时是个可怕的施法者，即使是小小的法术一到
他手中便会变得威力无匹，厉害非常。
CLONG
	);
	set("gender","male");
        set("race","羽民");
	set_perm_stat("str", 28 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 25 );
        set_perm_stat("int", 30 );
	set( "alignment", -1000000 );
	set( "hit_points", 1800 );
	set( "max_hp", 1800 );
        set( "max_fp",400);
        set( "weight",100);
        set_natural_weapon( 20, 15, 20 );
	set_natural_armor( 50, 28 );
        set("aim_difficulty",([ 
    	  "critical":80,"weakest":50,"vascular":40,"ganglion":50 ]) );
        set("wealth/gold",200);
        set("stun_difficulty",100);
        set_temp("bs",10);
        set_temp("be_joke",3);
        set("conditions/_heal_hp",({ 4 , 1 }) ) ;
        set_skill("concentrate",100);
        set_skill("target",100);
        set_skill("black-magic",100);
        set_skill("elemental",100);
        set_skill("dodge",100);
        set_skill("parry",80);
        set_skill("wand",80);
        set("spells/lightning",2);
        set("spells/ether-bolt",6);
        set("spells/flare",2);
        set("spells/sleet",4);
        set("spells/fireball",6);
        set("spells/heart-griping",4); 
        set("guild_levels/black-magic",50) ;
        set("guild_levels/elemental",50);
        set("guild_levels/guild",50);
        set("tactic_func","my_tactic");
        set("magic_delay",3);
        wield_weapon(SWEA"imp_wand");
        equip_armor(SARM"imp_leggings");
        equip_armor(SARM"imp_cloak");
        equip_armor(SARM"imp_ring");
        equip_armor(SARM"imp_amulet");
        equip_armor(SARM"imp_cloth");
        set("special_defense",(["all":100,"none":40,"energy":-10]));
        set( "inquiry", ([
          "forbidden_ground":"@@ask_help",
                   "history":"@@ask_history",
             "great_vampire":"@@ask_vampire",
                 "fly_flute":"@@ask_flute",
              "flute_energy":"@@ask_energy"
        ]) );
        set("chat_chance",10);
        set("att_chat_output",({
              "羽后嘲笑你的无知：哼，吾人宝刀未老尚可斩汝老贼，还不速退！\n",
        }) );
}
void init()
{
   ::init();
   add_action("do_embattle","embattle");
}
void ask_energy(object asker)
{
write(@LONG
羽后说道：「飞翔之笛」的能源？噢，「飞翔之笛」是以「天堂之水」(heaven_water)
          为发动能源的，至於「天堂之水」在那里，我一点头绪都没有，你去请教高
          人吧。
LONG
   );
}
void ask_flute(object asker)
{
   asker->add_temp("flute_asked",1);
write(@LONG
羽后说道：你问「飞翔之笛」？喔，我已经把它借给「巫咸城」之主－「巫罗王」
　　　　　了，你就带我的口信去跟他要吧。   
LONG
);
}
void ask_vampire(object asker)
{
write(@LONG
羽后说道：妖□谷辰乃修练万年的僵□，他早在千年前被人收伏。最近
　　　　　听人说起，它又出来为害世间，如果能收伏它，将是第一功德
　　　　　。妖□谷辰几乎毫无弱点可言，惟一怕的是「灭魔符」(ghost
          -killed spell)，若你想收伏它，那怕是千辛万苦，都要找出
          来，很抱歉，我不知道现在那符的下落，你还是多去打听打听
          。　　　　　
LONG
   );
}
void ask_help(object asker)
{
   write(@LONG
羽后说道：传说在我们居住村落的北方有个禁地，那里设有某种禁制，
　　　　　需要穿著天神祝福的防具通过才能确保无虞，所以一般人是
　　　　　无法轻易到那里去的。说起天神祝福的防具，我身上就有一
　　　　　件，不过，我是不可能轻易给你的。
LONG
   );   
}
void ask_history(object asker)
{
   write(@LONG
羽后说道：千百年前，吾人本是黄帝手中一员骁将，多建功绩。因感岁月
　　　　　如白驹过隙，又感手中杀伐之多，特於蚩尤战败之後，得准告
　　　　　老还乡，但因家园饱受战祸摧残不复往昔，遂觅得此处招得乡
　　　　　人若干准备长住於斯，顺便为玉帝看守北方禁地，千百年来，
　　　　　不曾涉及尘事。由於长期住在地上，吾族飞行的能力也就消失
　　　　　了。　   
LONG
   );
}
int my_tactic()
{
    int i,k;
    object victim;
    
    string power,name;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10)> 1 ) return 0;
    if ( query_temp("cast_busy") ) return 0;
    k=1+random(2);
    switch ( k ) {
    case 1 :
        power="max";
        break;
    default : 
        power="normal";    
        break;
    } 
    name=victim->query("name");
    for ( i=0;i<k;i++ ) {
       switch ( random(6) ) {
         case 0:command(sprintf("cast %s fireball on %s",power,name));
                break;
         case 1:command(sprintf("cast %s sleet on %s",power,name));
                break;
     	 case 2:command(sprintf("cast %s flare on %s",power,name));
                break;
         case 3:command(sprintf("cast lightning on %s",name));
                break;
         case 4:command(sprintf("cast %s ether-bolt on %s",power,name));
                break;
         case 5:
                command(sprintf("cast %s heart-griping on %s",power,name));
                break;
         default :
                command("say 有虫虫:~~\n");
                break;
       }
    }
//    set("stop_attack",0);
    return 1;
}
void die()
{
     set("alignment",2000);
     ::die();
}
