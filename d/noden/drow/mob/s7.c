#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

 void create()
{
        ::create();
        set_level(18);
        set_name("mad snake","猛暴海蛇");
        add("id",({"snake"})); 
        set_short("猛暴海蛇");
	set_long(@C_LONG
猛暴海蛇－通常，海蛇的毒性一般要远远超过陆蛇
的一百倍上以上，这条眼露青光的海蛇正在水中游
走著，亮丽的黄－黑相间的条纹正要说明它那凶残
并且拥有令人致命的毒性。
C_LONG
        );
        set( "unit", "条" );
	set( "alignment", -1500 );
         set( "max_hp", 500 );
          set( "hit_points", 500 );
   set_perm_stat( "dex", 30 );
	set("likefish",1);
        set( "natural_weapon_class1", 46 );
        set( "natural_min_damage1", 24 );
        set( "natural_max_damage1", 38 );
        set( "tactic_func", "emit_poison" );
        set_c_limbs( ({ "头部", "闪亮的身体", "美丽的尾巴" }) );
        set_c_verbs( ({ "%s回游旋绕，向%s优柔地环曲咬下" }) );
   set( "killer", 1 );
}
int emit_poison()
{
        object victim;

        if( random(15)>6 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "猛暴海蛇回游到你身边，优雅地咬向你，一阵松麻传来\n", 
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
5, 36 );
        return 1;
}       
void die()
{   object obj,who;
    tell_room(environment(this_object()),
@DIE

猛暴海蛇卷曲扭动，口中翻出一个手镯，吐了口气，回姥姥家了!

DIE
,this_object());
   obj=new("/d/noden/drow/arm/lucky_bracers");
    obj->move(this_object());
   ::die(1);
   }


