#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("Sky eye", "苍天之眼");
        add( "id", ({ "eye","sky" }) );
        set_short("苍天之眼");
        set_long(@C_LONG
你看到一个像眼珠的东西，散发出一片淡蓝色祥和温暖的光茫。 
这相传是地藏王菩萨看见邪恶横行，众生惨遭屠害，由它的叹息所幻化成的。 
它的防护力并不高，但相传戴上它後便具有看清虚幻不实物品之能力。 
C_LONG
                   );
        set("unit","颗");
        set( "type", "head" );
        set( "material", "wood");
        set( "armor_class", 1 );
        set( "defense_bonus", 2 );
	set( "equip_func", "angel" );
	set( "unequip_func", "ruby" );
        set( "special_defense",
               ([ "fire":1, "cold":1, "electric":1 ]) );
        set( "weight", 10 );
        set( "value", ({ 10, "gold" }) );
} 

void angel()
{
int ali; 
object holder;

 holder = environment(this_object());
 ali=(int)holder->query("alignment");
 if (ali < 1500) {

     tell_object( holder, 
     "\n\n眼珠突然射出一阵光芒，它似乎不愿臣服於你，蹦的一声掉在地上... 
   \n"); 
        this_object()->move(environment(environment(this_object())) );
                   }
       else {

    tell_object( holder, 
 "\n『万能的天神，赐给这位善良的人看清虚幻不实物体的力量吧!!!』
『但是别忘了，要为正义和公理加油啊!』眼球散发出天蓝色的光辉\n"
     ); 
	holder->set_temp("detect_invi",1);
            }   
}

void ruby()
{
object holder;

 holder = environment(this_object());


    tell_object( holder, 
 "\n
『别忘了，还是要为正义和公理加油啊!』眼球恢复成原本的淡蓝色\n"
     ); 
	holder->set_temp("detect_invi",0);
}

