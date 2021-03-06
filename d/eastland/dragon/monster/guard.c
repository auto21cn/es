
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(18);
        set_name( "draconian guard", "龙人守卫" );
        add ("id", ({ "draconian", "guard" }) );
        set_short( " 龙人守卫");
        set("unit","位");
        set("alignment",-400);
        set("weight",400);
        set("wealth/gold",100);
        set_long(@C_LONG
龙人族据说是古代龙与人杂交所生出的种族，而龙人守卫则是从族人中精选
出最不具有龙之血统的战士，性情较温和较能沟通。
C_LONG
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 25);
        set_perm_stat("str",25);
        set_perm_stat("kar",20);
        set("max_hp",500);
        set("hit_points",500);
        set("natural_defense_bonus",30);
        set ("natural_weapon_class1", 35);
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
      
        dagger= new(Lditem"guardsword");
        dagger->move(this_object());
        wield_weapon(dagger);
        
        boots=new(Lditem"plate1");
        boots->move(this_object());
        equip_armor(boots);
        
        shield=new(Lditem"shield1");
        shield->move(this_object());
        equip_armor(shield);
        
        
}
       
