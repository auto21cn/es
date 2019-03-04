
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(15);
        set_name( "draconian artisan", "龙人工匠" );
        add ("id", ({ "draconian", "artisan"}) );
        set_short(" 龙人工匠");
        set("unit","位");
        set("alignment",400);
        set("weight",400);
        set("wealth/gold",100);
        set_long(@C_LONG
龙人工匠他熟习各种器物的制造，在这个世界上还没有任何依样物品是
他造不出来的！
C_LONG
        );
        set( "inquiry", ([
         "drumstick" : "@@ask_drum",
           ]) );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 16);
        set_perm_stat("kar",20);
        set("max_hp",300);
        set("hit_points",300);
        set("natural_defense_bonus",10);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 11);
        set ("natural_max_damage1", 16);
        set ("natural_armor_class", 40);
        set ("special_defense",(["all":20,"none":20]));
        set ("gender", "male");
        set_skill("shortblade",80);
        set_skill("dodge",100);
        set("tactic_func","sleet_tactic");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
      
       
        wield_weapon(Lditem"dagger1");
        equip_armor(Lditem"boots");
}



void ask_drum( object who )
{
        tell_object( who, @ALONG
如果你想要制造龙神鼓槌，你必须要找到一根世上最坚硬的木头，加上
我原有的麒麟皮即可制造出龙神鼓槌，所以快去找世上最坚硬的木头来
吧，当你找到之後再来找我，我自然会帮你的。
ALONG
                   );
      return ;        
}
int accept_item(object ob1,object ob2)
{
    object ob3,ob4;
    if (!ob2|| (int)(ob2->query("layuter_club"))!=1) return 0;
    if ((int)(ob2->query("layuter_club"))==1){
    tell_object(ob1,
         "好既然你已经得到世上最坚硬的木头，那我就帮你造龙神鼓槌。\n");
    tell_room(environment(this_object()),"龙人工匠开始敲敲打打地努力於工作\n");  
    call_out("aaa",15,this_object());
    ob3=new(Lditem"club");
    ob3->move(environment(this_object()));
       }
    else {
       tell_room(environment(this_object()),"龙人工匠说：谢谢你的礼物。\n");  
       }
          
    ob2->remove();   
   }  

void aaa(object who)
{
  tell_room(environment(who),"龙人工匠终於完成这艰钜的工作，此时他已累的满头大汗。\n");
   tell_room(environment(this_object()),"龙人工匠说：这是你要的鼓槌 ，希望你能好好的利用它\n");  
 
}
