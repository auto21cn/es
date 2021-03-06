#include "../layuter.h"

inherit MONSTER;

void create ()
{
        ::create();
        set_level(19);
        set_name( "minotaur", "牛头人" );
        add ("id", ({ "minotaur", "minota" }) );
        set_short( "牛头人" );
        set("unit","只");
        set_long(
           " 是一种居住於迷宫或地底的牛头人身怪物，他看起来十分巨大\n"
           " 而且不友善，你最好不要惹他。\n"
        );
        set("killer",1);
        set("alignment",-1000);
        set("wealth/gold",600);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 22);
        set_perm_stat("int",15);
        set_perm_stat("kar",25);
        set_perm_stat("pie",10);
        set("max_hp",700);
        set("hit_points",700);   
        set_natural_weapon( 28, 15, 18 );
        set_natural_armor( 93, 40 );
        set ("gender", "male");
        set_c_verbs(({"用%s向%s砍去","用%s使出必杀一击向%s攻击"}));
        set_c_limbs(({"身体","头部","脚部","手臂","胸部"}));
        set_skill("parry",90);
        set_skill("dodge",60);
        set_skill("axe",100);
        wield_weapon(LWEAPON"axe");        
}

void die()
{
	object killer;
	
	killer = query("last_attacker");
   if( killer ) killer->set_explore("noden#33");
	::die();
}
