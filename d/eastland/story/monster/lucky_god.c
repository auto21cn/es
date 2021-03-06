#include "../story.h"
inherit MONSTER;
int receive_damage(int damage);
void create()
{
    ::create();
    set_level(17);
    set_name( "lucky god", "泰逢" );
    add ("id", ({ "god" }) );
    set_short( "吉神 泰逢");
    set_long(@LONG
泰逢长的一个人的身子而後面又拖著一条长长的孔崔羽毛。他的身体的周围不时伴
随著闪闪的光□，并不是「恶神耕父」一类的凶光，而是一种「吉祥止止」的可爱
光芒，也就是我们中国善良人民的希望之光。据说，泰逢对於人们有降福作用，如
遇到他那就表示你快要有喜事临门了！泰逢现在正准备要到霍太山山神那里喝酒，
背後聆著一个大胡芦。
LONG
            );
    set("unit","位");
    set("race","god");      
    set("age",59);
    set("gender","male" );
    set("weight",1000);
    set("wealth/gold",100);
    set_temp("be_joke",100);
    set_temp("bs",10000);
    set_perm_stat("str",22);
    set_perm_stat("dex",25);
    set_perm_stat("kar",30);
    set_perm_stat("int",30);
    set("hit_points",500);
    set("max_hp",500);
    set("max_fp",250);
    set_natural_armor(1,100);
    set_natural_weapon(300,15,9);
    set_skill("dodge",100);
    equip_armor(SARM"lucky_cloth");
    set( "tactic_func", "my_tactic" );
}        
int receive_damage(int damage)
{
   if ( damage > 40 ) damage=40;
   ::receive_damage(damage);
}
int my_tactic()
{
     object victim,env,*atk;
     int select;     
     
     if (!(victim= query_attacker())) return 0;
     if (random(8)>6) return 0;
     env=environment(this_object());
     tell_room(env,"泰逢怒道：该死的小鬼，我大人有大量，不跟你计较了。\n");
     atk=env->query("exit");
     select=random(sizeof(atk));
     command(sprintf("go %s",atk[select]));
     return 0;          
} 
void die()
{
   object card,gourd;
   gourd=new(SITEM"gourd1");
   gourd->move(environment());
   card=new(SITEM"card1");
   card->move(environment());
   tell_room(environment(),"从泰逢的背後掉下一个葫芦和一张纸。\n");
   ::die();
}                 