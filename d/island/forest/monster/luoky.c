#include "../tsunami.h"
#include "/include/move.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(10);
    set_name( "luoky", "魉皇鬼" );
    add( "id",({"luoky"}) );
    set_short( "魉皇鬼" );
    set_long(@LONG
这是一只长相像兔子，叫声却像猫的小动物，很可爱吧！它可是砂纱美公主的
宠物呢！你千万不要欺负它哦！否则你会遭天谴的哦！如果你喂它萝卜(radish)
的话，它就会和你亲近哦！
LONG
            );
    set("aligment",1000);
    set_c_verbs( ({"%s用它锋利的牙齿咬向%s","%s强而有力的後腿踢向%s",
                   "%s用它大大的耳朵甩向%s"}) );
    set_perm_stat( "str", 10);
    set_perm_stat( "dex", 10);
    set_perm_stat( "int", 15);
    set( "chat_chance",5);
    set( "chat_output", ({
  "魉皇鬼用鼻子边闻边叫著: 喵～～喵，我要萝卜，喵～～喵～～喵～～\n"
       }));
    set("hit_points",200);
    set("max_hp",200);
    set_natural_weapon( 30, 15, 30 );
    set_natural_armor(35,10);
    set("c_death_msg","由於你最後一下补得太猛了，%s的鲜血喷得你满脸都是！\n");
}

int accept_item(object player,object obj)
{ 
   object *item, ob1, ob2;
   int i;
   ob1 = ( present("luoky")); 
   ob2 = new(TOBJ"crystal");
   
   if(!obj || !(obj->query("give_me_radish")) ) {
   tell_room(environment(),
   "魉皇鬼挂著两行汤匙般大的泪珠哭道：喵～～喵～～喵，萝卜萝卜啦！\n");
   return 1;
   }
   
   if( (string)obj->query("owner") != (string)player->query("name") ){
   tell_object(player,"魉皇鬼哭道：呜喵，你没有诚意喵，居然给我一只不新鲜的萝卜，喵～喵！\n");
   obj->remove();
   return 1;
   }
   
   tell_room(environment(),
     "魉皇鬼很愉快的咬著萝卜，变成一棵水晶，围绕著"+player->query("c_name")+
     "飞舞........\n");
   tell_object(player,"魉皇鬼对你说：请你带我回我的主人那儿去!!\n");
   ob2->set("winner",(string)player->query("name"));
   ob2->move(player);
   item = all_inventory(ob1);
   for( i=0; i<sizeof(item); i++ ) item[i]->remove();
   ob1->remove();
   return 1;
} 

void die()
{
   object killer;
   killer = query( "last_attacker" );
   
   if( !killer ){
   ::die();
   return;
   }
   killer->set_temp("luoky_killer",1);
   ::die();
}   
            
