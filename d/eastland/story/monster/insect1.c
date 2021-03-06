#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(13);
       set_name("wild insect","热带昆虫" );
       add("id",({"insect"}) );
       set_short( "热带昆虫" );
       set("unit","只");
       set_long(@LONG
一只奇形怪状的昆虫；它前面和後面各长著一个墨绿色的小头，头上的小眼骨噜噜
地正盯著你瞧，好像有什麽企图；反观它的身子却出乎意料的大，足足有二十公分
长；在它身子旁，另长著五对长长的足肢，足肢满是毛绒绒的绿毛，可怖极了！看
别看它一副雍肿的模样，行动起来却迅速已极！不晓得它是什麽动物？唉呀，它正
向你攻击！
LONG
       );
       set("killer",1);
       set("hit_points",80);
       set_perm_stat("str",20);
       set_natural_armor(65,0);
       set_natural_weapon(18,12,21);
       set_c_verbs(({"%s用它的前足肢向%s攻击",
                     "%s用它的後肢狠狠向%s一踹",
                     "%s用它的头部撞向%s"
       }));
       set_c_limbs(({"身体","头部","足肢"}));
}
void kill_reward(object killer)
{
   switch( random(3) ) {
   case 0: killer->add("hit_points",-100);
           break;
   case 1: killer->add("force_points",-150);
           break;
   default: killer->add("spell_points",-150);
           break;    
   }
   ::kill_reward(killer);
}
void die()
{
   tell_room(environment(this_object()),
      "唉呀！热带昆虫的身体胀成一个大球，忽然，大球破掉并且流出一堆绿色液体！！\n\n");
   set("alt_corpse","NONE");
   ::die(1);
}
