#include "../iigima.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "Drow guard","黑暗精灵守卫" );
        add ("id", ({ "drow", "guard" }) );
        set_short( "Drow guard","黑暗精灵守卫" );
        set("unit","位");
        set_long(
@C_LONG
他是这个黑暗村落内的守卫，正像死鱼般的站著。
C_LONG
        );
        set_perm_stat("str", 15);
        set_perm_stat("dex", 14);
        set ("natural_weapon_class1", 15);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 6);
        set("natural_armor_class",34);
        set("natural_defense_bonus",6);
   set( "special_defense", ([
      "all":15,"fire":-10,"cold":-10,"evil":30,"divine":-30,"none":5 ]) );
       set_skill("parry",50);
        set ("gender", "male");
        set("wealth/silver",50);
   set( "weight", 700 );
        set ("race", "drow");
        set_c_verbs(({"%用%s向%s砍去","用%s向%s刺去"}));
        set_c_limbs(({"身体","头部","手臂"}));
        wield_weapon(OBJ"copper_hammer");
        equip_armor(ARM"copper_arm");
        // equip_armor(ARM"a23");
        equip_armor("/d/noden/asterism/armor/leggings02");
}
//Ending QC.
