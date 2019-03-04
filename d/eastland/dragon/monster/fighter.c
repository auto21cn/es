
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield;

        ::create();
        set_level(19);
        set_name( "draconian fighter", "龙人战士" );
        add ("id", ({ "draconian", "fighter" }) );
        set_short( " 龙人战士");
        set("unit","位");
        set("killer",1);
        set("alignment",-400);
        set("weight",400);
        set("wealth/gold",100);
        set_long(@C_LONG
龙人族据说是古代龙与人杂交所生出的种族，而龙人战士则是从族人中精选
出最有龙之血统的战士，所以其有很强的战斗力．恢复力．甚至防魔法的能力，
故其是一可怕的敌人。
C_LONG
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 25);
        set_perm_stat("str",25);
        set_perm_stat("kar",20);
        set("max_hp",500);
        set("hit_points",500);
        set("max_fp",600);
        set("force_points",600);
        set_skill("inner_force",100);
        set("force_effect",6);
        set("natural_defense_bonus",30);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 20);
        set ("natural_max_damage1", 30);
        set ("natural_armor_class", 70);
        set ("special_defense",(["all":60,"none":60]));
        set ("gender", "male");
        set_skill("longblade",100);
        set_skill("parry",100);
        set_skill("block",100);
        
        set("tactic_func","sleet_tactic");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
      
        dagger= new(Lditem"longsword");
        dagger->move(this_object());
        wield_weapon(dagger);
        
        boots=new(Lditem"plate");
        boots->move(this_object());
        equip_armor(boots);
        
        shield=new(Lditem"shield");
        shield->move(this_object());
        equip_armor(shield);
        
        
}

int sleet_tactic()
{

  }
       
