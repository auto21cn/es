#include <mudlib.h>

inherit MONSTER;
void die();
int calloutcheck = 0;
string laugh,*action =
     ({ "%s指著%s的ＸＸ笑得直不起腰来。\n",
        "%s在%s的四周跳来跳去，拿大鼎、翻跟斗。\n",
        "%s装上一个红红的小丑鼻子，对著%s摇头晃脑。\n",
        "%s一屁股坐在地上，指著%s哇啦哇啦的哭了起来。\n",
        "%s用泥巴乱涂%s的脸。\n" }) ;

void create()
{       
	::create();
	set_level(19);
	set_name( "Water Beast", "无支祈" );
	add( "id", ({ "beast","water beast"}) );
	set_short( "水怪 无支祈" );
	set_long(@C_LONG
这是一支善於应对言语的怪物, 形状像猿猴, 额头高, 鼻梁低, 白脑袋, 青身子,
牙齿雪亮, 眼睛闪□出金光, 力量大过九只象, 颈脖子伸出来有百尺长, 但他的
身躯却伶俐轻便。
C_LONG
);
        set("killer",1);
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 30 );
	set_skill( "unarmed", 100);
	set_natural_armor( 30, 1 );
	set_natural_weapon( 90, 40, 40 );
	set("locked",0);
	set("faint",0);
	set( "time_to_heal", 20 );
	set( "max_hp", 2500 );
	set( "hit_points", 2500 );
	set( "gender","male" );
	set( "alignment",-1000 );
        set("stun_difficulty",100);
        set("special_defense", 
          ([ "all": 30,"none":30]) );
        set("aim_difficulty",
          (["critical":100]) );
        set("tactic_func","my_tactic");        
}  
void init()
{
    ::init();
    add_action("do_joke","joke");
}

int do_joke(string arg)
{ 
   object player;
   player=this_player();
   laugh = set_color(action[random(sizeof(action))],"HIY");
   tell_object(player,
     "\n『噗哇哈哈哈』,无支祈对著你大笑著说:你难道不知道 joke 的老祖宗是谁吗?\n\n");
   tell_room(environment(this_object()),
         sprintf(laugh,"无支祈",player->query("c_name")));
   kill_ob(player);
   player->block_attack(6);
   player->set_temp("msg_stop_attack",
       "( 你现在笑得浑身没力，无法攻击！ )\n" );
   return 1;
}
int my_tactic()
{
    object *victim;
    int i;     

    if ( !victim=query_attackers() ) return 0;
    if (random(10)>1) return 0;

    laugh = set_color(action[random(sizeof(action))],"HIY");
    tell_room(environment(this_object()),
       sprintf(laugh,"无支祈","所有攻击它的敌人"));
    for (i=0;i<sizeof(victim);i++) {
       victim[i]->block_attack(4);
       victim[i]->set_temp("msg_stop_attack",
          "( 你现在笑得浑身没力，无法攻击！ )\n" );
    }
    return 0;
}
void recover_or_die(object ob)
{
   object env;
   calloutcheck=0;
   env=environment(ob);
   if ( !ob->query("locked") ) {  
      tell_room(env,"\n忽然一声大吼,无支祈又活了过来...\n\n");
      ob->set("hit_points",2500);
      ob->set("no_attack",0);
      ob->set("killer",1);
      ob->set("faint",0);
   }
   else 
     die(); 
}
void die()
{       
    object killer,obj;
    int wine;
    
    if ( !query("locked") ) {
       set("killer",0);
       set("no_attack",1);    
       cease_all_attacks();
       clean_up_attackers();
       set("hit_points",1); 
       tell_room(environment(this_object()),"无支祈一声唉嚎,昏倒在地上!!\n");
       set("faint",1);
       if (!calloutcheck) {
         call_out("recover_or_die",60,this_object());  	
         calloutcheck=1;   
       }
    }
    else 
    ::die();
}
