
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(11);
        set_name( "draconian woodman", "龙人樵夫" );
        add ("id", ({ "draconian", "woodman"}) );
        set_short( " 龙人樵夫");
        set("unit","位");
        set("alignment",100);
        set("weight",400);
        set("wealth/gold",50);
        set_long(
           "龙人樵夫是一各勤奋的工作者。\n"
        );
        set_perm_stat("int", 15);
        set_perm_stat("dex", 16);
        set_perm_stat("kar",10);
        set("max_hp",200);
        set("hit_points",200);
        set("natural_defense_bonus",10);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 5);
        set ("natural_max_damage1", 16);
        set ("natural_armor_class", 20);
        set ("special_defense",(["all":20,"none":20]));
        set ("gender", "male");
        set_skill("axe",60);
        set_skill("parry",80);
        set_c_limbs(({"身体","头部","脚部","手臂"}));
      
        set("chat_chance",3);
        set("chat_output",({
          "樵夫说：唉!我的酒瘾又犯了，我真想喝陈年女儿红。\n",
           }));
       
        dagger= new(Lditem"axe");
        dagger->move(this_object());
        wield_weapon(dagger);
        
        boots=new(Lditem"chainmail");
        boots->move(this_object());
        equip_armor(boots);
}

int accept_item(object ob1,object ob2)
{
    object ob3,ob4;
    if (!ob2|| (int)(ob2->query("layuter_beer"))!=1) return 0;
    if ((int)(ob2->query("layuter_beer"))==1){
    tell_object(ob1,"非常感谢你为我带来的酒，光是酒香就令我的酒虫大作。\n");    
    if (ob3=(present("axe",this_object()))){
      tell_object(ob1,
         "我身上没什麽值钱的东西，但是这把斧头以跟了我二十年了，但依旧锋利无比，就把它当作礼物送给你。\n"
         );        
         ob3->move(environment(this_object()));
        this_player()->set_explore("eastland#4");
       }
    ob2->remove();
    tell_room(environment(ob1), "樵夫坐在椅子上开始喝著酒.\n");       
   }
   
}

void die()
{  
  object ob3;
  
  
  if (ob3=(present("axe",this_object())))
    ob3->set("woodman_die",1); 
  ::die();  
    
}
