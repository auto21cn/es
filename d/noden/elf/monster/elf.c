#include "../layuter.h"

inherit MONSTER;

void create()
{
        object boots,sword,cloak;

        ::create();
        set_level(5);
        set_name( "elf", "精灵" );
        add ("id", ({ "elf" }) );
        set_short( "精灵" );
        set("unit","位");
        set_long(
           " 他是位和蔼可亲的精灵，脸上总是带著亲切的笑容\n"
        );
        set("alignment",100);
        set("wealth/silver",10);
        set_perm_stat("str", 6);
        set_perm_stat("dex", 4);
        set ("natural_weapon_class1", 2);
        set ("natural_min_damage1", 1);
        set ("natural_max_damage1", 4);
        set ("natural_armor_class", 15);
        set ("gender", "male");
        set ("race", "elf");
        set_c_verbs(({"用%s向%s砍去","用%s向%s攻击","用%s向%s刺去"}));
        set_c_limbs(({"身体","头部","脚部","手臂"}));
       
        sword= new(LWEAPON"elf_sword");       
        sword->move(this_object());
        wield_weapon(sword);
        
        boots=new(LARMOR"wind_boots");
        boots->move(this_object());
        equip_armor(boots);

        cloak=new(LARMOR"wind_cloak");
        cloak->move(this_object());
        equip_armor(cloak);
}
