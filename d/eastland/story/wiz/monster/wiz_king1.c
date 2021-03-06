#include "../../story.h"
#include "../../magic.c"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(19);
	set_name( "King of wizard", "巫罗王" );
	add ("id", ({ "king","wizard"}) );
	set_short( "城主 巫罗王");
	set_long(@CLONG
你眼前所见的是一位文质彬彬，身子修长年纪看似不很大的人正坐在龙椅上。巫罗
王的五官长得秀美极了，光是那一对招子，有若寒星点点散发出闪闪银光，在深坠
的眼眸里，令人一看内心就会感到阵阵平和。巫罗城主英明有智慧，善纳谏言，擢
拔人才，他的胆识与气度相当不凡，其驾御能力更是令人望尘莫及，生平历经无数
战役鲜有败绩，伤亡更是减到最低程度，他不啻是位令人信赖的好伙伴，亦是位让
人尊敬的好上司。不知怎麽搞的，你发现巫罗王的神色中似乎带著一些烦忧 (trou
ble)。 
CLONG
	);
	set("flute",1);
	set("race","human");
        set("race","巫师");
	set("gender","male");
	set_perm_stat("str", 30 );
        set_perm_stat("dex", 30 );
        set_perm_stat("kar", 30 );
        set_perm_stat("int", 30 );
	set( "alignment", 5000 );
	set( "hit_points", 2000 );
	set( "max_hp", 2000 );
        set( "max_fp",500);
	set_natural_weapon( 25, 30, 45 );
	set_natural_armor( 86, 55 );
        set("aim_difficulty",([ 
    	  "critical":80,"vascular":80,"ganglion":80,"weakest":80 ]) );
        set("wealth/gold",500);
        set("stun_difficulty",100);
        set("conditions/_heal_hp",({ 3 , 1 }) ) ;
        set_skill("parry",100);
        set_skill("block",100);
        set_skill("jousting",100);
        set_skill("two-weapon",100);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"wiz_lance");
        equip_armor(SWARM"wiz_shield3");
        equip_armor(SWARM"wiz_ring2");
        equip_armor(SWARM"wiz_cloak1");
        equip_armor(SWARM"wiz_helmet1");
        set("special_defense",(["all":50,"none":40,"monk":40]));
        set("inquiry",([
              "great_bag":"@@ask_bag",
              "fly_flute":"@@ask_flute",
                "trouble":"@@ask_trouble",
        ]) );
}
int accept_item(object player, object item)
{
      string iname,pname,pcname;
      
      if ( !item->query("spiritball") ) {
         tell_room(environment(),"巫罗王说道：给我这东西干嘛？我又不是收垃圾的。\n");
         item->move(environment());
         return 1;      
      }
//    if ((int)player->query_quest_level("wizking")>0 ) {
      if ((int)player->query("quests/wizking")>0 ) {
         write("巫罗王说道：谢谢你再次帮忙。\n");
         return 1;
      } 
      iname=item->query("master");
      if (!(pname=player->query("org_name"))) pname=player->query("name");
      pcname=player->query("c_name");
      if ( iname!=pname ) {
         tell_room(environment(),sprintf(
           "巫罗王对著%s喊道：原来就是你偷的，给我去死吧！！\n",pcname),player);
         tell_object(player,"\n巫罗王对你喊道：原来是你偷的，给我去死！\n\n"); 
         kill_ob(player);
         item->remove();
         return 1;
      }
      write(@LONG
      
 巫罗王说道：谢谢你帮我找回巽灵珠。

 [ 由於你热心地解决了巫罗王的困难，因而获得巫罗王赏赐的 15000 点的经验值]    

LONG
      );
      // player->finish_quest("wizking",1);
      player->set("quests/wizking",1);
      player->gain_experience(15000);
      item->remove();
      return 1;
}
void ask_trouble(object asker)
{
  write(@LONG
巫罗王说道：唉，我把镇城之宝－巽灵珠(spirit_ball)给弄丢了，你能帮我找
            回来吗？详细情形你去问护国师好了，我现在没心情跟你讨论。
              
LONG
  );
}
void ask_flute(object asker)
{
   object flute;
   if( !asker->query_temp("flute_asked",1) ) {
     write("巫罗王说道：哼，无耻小贼，你到底是从那里打听到「飞翔之笛」的？\n");
     return ;
   }
   write("巫罗王说道：哦，原来是羽后跟你说要来拿回「飞翔之笛」的喔？\n");
   if( !query("flute") ) {
     write("巫罗王叹道：我已经把笛子给别人了，你似乎来的太晚了。\n");   
     return ;
   }
   flute=new(SITEM"flute1");
   if (flute->move(asker)!=0) {
     write("巫罗王说道：你带太重了，丢一些东西掉吧。\n");
     flute->remove();
     return ;
   }
   set("flute",0);
   flute->move(asker);
   write(@LONG
巫罗王说道：好吧，我就给你吧。
巫罗王给你一个「飞翔之笛」。
巫罗王续道：「飞翔之笛」现在业已没有能源(flute_energy)了，你自已想个办法吧。
LONG
   );
   tell_room(environment(),"巫罗王露出狡猾的微笑。\n");
   asker->delete_temp("flute_asked");
   call_out("back",300);
   return ;
}
void back()
{
   set("flute",1);
}
int get_bag(string name,string *names)
{ 
    int i,max;
    max=sizeof(names);
    for (i=0;i<max;i++)
      if ( name==names[i] ) return 1;
      else return 0; 
}        
void ask_bag(object asker)
{
    object env,bag,*get,ball;
    string name,*names;
    if ( !asker->query("quests/wizking") ) {
       write("巫罗王说道：嗯，无底袋是我城内的特产。\n");
       return ;
    }
    if (!(name=asker->query("org_name"))) name=asker->query("name");
    env=environment(this_object());
    names=env->query("bag_asked");
    if (!get_bag(name,names)){
       write("\n巫罗王说道：看在你帮我找回巽灵珠的份上，我就给你一个无底袋。\n\n");
       env->add("bag_asked",({name}));     
       tell_object(asker,@LONG

只见巫罗王把手举向天空并且喃喃自语....

吓！忽然从空中掉下一个无底袋来！！

巫罗王说道：嗯，好孩子，这是赏给你的，^_^。

LONG
       );
       bag=new(SWITEM"bag1");
       bag->set( "max_load", 1500);
       bag->set( "weight_apply", 25 );
       bag->set("no_sale",1);
       bag->move(env);      
       return ;
    }       
    tell_object(asker,"巫罗王以质疑的眼光看著你：咦，你不是已经跟我要过一个无底袋了吗？\n");
    return ;
}
void init()
{
   ::init();
   add_action("do_embattle","embattle");
   add_action("do_demand","demand");
}
int can_help( object ob )
{
   if ( !living(ob) ) return 0;
   if ( ob->query("bodyguard") ) return 1;
   return 0;
}

int stop_attack()
{
    int i,max;
    object *tmp, env, *atk;
        
    env=environment();
    atk=filter_array(all_inventory(env),"can_help",this_object());
    max=sizeof(atk);
    for ( i=0;i<max;i++ ) {
        tell_room( env,sprintf(
           "%s冲到巫罗王面前，并且大声喊道：有刺客，大家快保护城主的安全！\n"
           ,atk[i]->query("c_name")) );
        tmp = query_temp( "protectors" );
        if( !tmp || member_array( atk[i], tmp )==-1 ) {
           add_temp( "protectors", ({ atk[i] }) );
           atk[i]->add_temp( "protectees", ({ this_object() }) );
        }
        atk[i]->kill_ob(this_player());
    }
    return 0;
}
int do_embattle(string arg)
{
   object player;
   player=this_player();
   if ( player->query("class")!="scholar" ) return 0; 
   write("巫罗王看穿了你想结阵法的企图，於是给你一个重重的痛击！\n");
   player->add("hit_points",-20);
   player->add("spell_points",-40);
   return 1;
}
int do_demand(string arg)
{
   object player;
   player=this_player();
   if ( player->query("class")!="scholar" ) return 0;
   write("巫罗王把你所招唤的精灵一口吃了下去！\n");
   player->add("spell_points",-40);
   add("hit_points",200);
   return 1;
}
int my_tactic()
{
    int i;
    object victim,env;
    string name;
    
    if ( !victim=query_attacker() ) return 0;
    env = environment( this_object() );
    name=victim->query("c_name");
    switch(random(60)){
    case 0..3 : 
        tell_object(victim,set_color(
           "\n\n糟糕！巫罗王似乎发现了你的致命弱点！\n\n","HIW"));
        tell_room(env,sprintf(
           "巫罗王发现了%s的致命弱点！\n",name),victim);
        victim->set("hit_points",victim->query("hit_points")/3);
        return 1;
    case 4..9:    
        tell_object(victim,
        "\n巫罗王手中的霸王枪宛如一条灵蛇，对著你连刺三十六枪，枪枪致命！\n\n");
        tell_room(env,sprintf("巫罗王对著%s连刺好几枪!\n",name),victim);
        victim->receive_damage(70+random(10));
        report(this_object(),victim);
        return 1;
    default :
        return 0;
    }   
}
