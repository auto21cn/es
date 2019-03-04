
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield;

        ::create();
        set_level(18);
        set_name( "woman fighter alisa", "龙人女战士 亚里莎" );
        add ("id", ({ "woman", "fighter","alisa" }) );
        set_short( "龙人女战士 亚里莎");
        set("unit","位");
        set("alignment",1000);
        set("weight",400);
        set("wealth/gold",100);
        set_long(@C_LONG
亚里莎是龙人族中最美丽的女性，虽然她是战士群中的一员但是她的温。
柔依旧没被激烈的战斗所抹煞，她的柔情可以融化所有男人的心，她现今
是龙穴参观者的接待人。
C_LONG
        );
        set_perm_stat("int", 35);
        set_perm_stat("dex", 25);
        set_perm_stat("str",25);
        set_perm_stat("kar",25);
        set("max_hp",600);
        set("hit_points",600);
        set("max_fp",600);
        set("force_points",600);
        set_skill("inner-force",100);
        set("force_effect",6);
        set("natural_defense_bonus",30);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 10);
        set ("natural_max_damage1", 20);
        set ("natural_armor_class", 50);
        set ("special_defense",(["all":60,"none":60]));
        set ("gender", "female");
        set_skill("dagger",100);
        set_skill("dodge",100);
        set_skill("block",100);
        
        set_c_limbs(({"身体","头部","脚部","手臂"}));
      
        wield_weapon(Lditem"dagger");
        equip_armor(Lditem"ring");
        equip_armor(Lditem"chainmail1");
        equip_armor(Lditem"shield2");
                
}

void init()
{
   npc::init();
  tell_room(environment(this_object()),"欢迎光临，此处是龙穴，低等级的玩家请离开此处\n");
}
