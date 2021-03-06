#include <../legend.h>

inherit MONSTER;
void create ()
{
        ::create();
        set_level(19);
        set_name( "yellow daoist", "茅山道士 黄天化" );
        add("id", ({"daoist"}) );
        set_short( "茅山道士 黄天化");
        set_long(@C_LONG
你眼前所见是位穿著喇□，混身肮脏又不修边幅的茅山道士。但是，你可别小看他
，因为他是现今茅山派第三十八代的掌门人，不但武功高，功力更是深厚无比，毕
生伏魔无数，颇赢得江湖人士的爱载。黄天化最近听说此处有妖魔鬼怪出现，特来
查看一番。黄天化受伤，愁眉深锁，好似遇到了什麽麻烦。
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
        set( "alignment", 400 );
        set_natural_armor( 35, 48 );
	set_natural_weapon( 53,12,36);
        set_perm_stat( "str", 25 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 28 );
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 80 );
        set_skill( "axe",75);
	set( "max_fp",500);
	set( "force_points",500);
        set( "hit_points", 900 );
        set( "max_hp", 1000000 );
        set("conditions/_heal_hp",({ 10000 , 1 }) ) ;
        set( "special_defense", ([ "all": 50,"none":40,
                "monk":40,"scholar":20]) );
        set( "stun_difficulty",50);
	wield_weapon( LWEAPON"mahogany_axe.c" );
	equip_armor( LARMOR"daoist_cloth" );
        set( "chat_chance", 10 );
        set( "att_chat_output", ({
                "黄天化喊道：「恶贼！还不退 !!」。\n",
	}) );
        set( "inquiry", ([
             "trouble":"@@ask_trouble",
             "定海珠":"@@ask_ball",
             "无支祈":"@@ask_mob",
        ]) );
        set( "tactic_func", "my_tactic" );
}
void ask_trouble(object asker)
{
write(@C_LONG
黄天化叹道：唉近来听说此处有上古神兽「无支祈」，特来收伏它。但却敌它不过，
　　　　　  受了极大的伤，并且遗失了一颗把它引出的媒物－「定海珠」，希望
　　　　　　少侠可以找回来，并收拾「无支祈」。
C_LONG
      );
}           
void ask_ball(object asker)
{
write(@C_LONG
黄天化道：你问「定海珠」?
          哦,那是一颗蓝色的原球，你只需在湖边 ( roll sea-ball ) 就可以
          把「无支祈」给引出来，但请小心，因为....
C_LONG
      );          
}
void ask_mob(object asker)
{
write(@C_LONG
黄天化道：「无支祈」本是上古神兽，它具有复活的本能，得趁它奄奄一息时用
　　　　　  大铁锁锁住方能制伏它。
C_LONG
     );
}
int my_tactic()
{
   int i,num;
   object victim,env,*all,help;
   
   if ( !victim=query_attacker() ) return 0;
   if ( random(10)>2 ) return 0;
   env=environment(this_object());
   all=all_inventory(env);
   num=0;
   for (i=0;i<sizeof(all);i++)         
     if ( all[i]->query("paperman") ) num+=1; 
   if ( num>2 ) return 0;  
   tell_room(env,"\n黄天化急忙从怀中掏出符咒，向天空一丢，化为一堆凶恶纸人！\n\n");    
   for (i=0;i<(3-num);i++) {
      help=new(LMONSTER"paperman");
      help->move(env);
   }
   return 0;        
}
void die()
{
   int i;
   object env,*all;
   env=environment(this_object());
   all=all_inventory(env);
   for (i=0;i<sizeof(all);i++)
     if ( all[i]->query("paperman") ) all[i]->remove();
   ::die();
}