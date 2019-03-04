#include <mudlib.h>
#define MSPECIAL "/u/m/mercury/obj/special";

inherit MSPECIAL 

void create()
{
        set_name( " ", "  ");
        add ("id",({ "dagger"}) );
        set_short( "  ");
        set("unit", "把");
        set_long(
            
            " !!!!\n"
        );
        set( "type","dagger");
        set("weapon_class",30);
        set("min_damage",15);
        set("max_damage",30);
        set("special_attack",(["damage_type" : "cold","main_damage" : 18 ,
                                "random_damage" : 22  ,"hit_rate" : 20 ]) );

//        set("hit_func","special_attack");
        set("wield_func","wield_dagger");
        set("unwield_func","unwield_dagger");
        set( "weight", 100 );
         
   set("c_msg","\n你招演 ***浪子回头*** 一道冰雾化为龙形向他而去!!\n\n");
   set("c_enemy_msg","\n的玉尺招演 ***浪子回头*** 你只见一股龙形冰雾向你袭来!!\n\n");
   set("c_fail_msg","\n你的武器喷出一片奇冷的寒气，却冰到你自己 ! \n\n");
   set("c_fail_room_msg","的武器喷出一片奇冷的寒气，却冰到他自己 ! \n\n");
   }

 int fail_to_use()
 {
      if ( (string)this_player()->query("gender")=="female")
              return 0;
          else
              return 1;
}

void unwield_ferule()
{
 if(query("form"))
        {
        set( "weapon_class", 15 );
        set( "min_damage", 10);
        set( "max_damage", 20);
        tell_room( environment(this_player()), ({
        this_player()->query("c_name")+"的冰寒玉尺光芒退去，变回平凡的银尺.......\n"
        }), ({this_player()}) );
        tell_object( this_player(),
         "你的冰寒玉尺冷光敛去，变成平凡的银尺............\n"
                );

        set_name( "silver ferule", "银戒尺");
        set_short( "silver ferule", "银戒尺");
        set("form",0);
                return ;
        }
        return ;
}

void wield_ferule()
{
        int pi,iq,i ;

        if ( (string)this_player()->query("class")=="healer")
        {
        pi=this_player()->query_perm_stat("pie");
        iq=this_player()->query_perm_stat("int");
        i = (pi+iq)/2+random(20);
        set("weapon_class",30);
        set("min_damage",15);
        set("max_damage", i );
        tell_room( environment(this_player()), ({
         this_player()->query("c_cap_name")+"的银戒尺发出一阵光芒，与他的手结合，变成他身体的一部份。\n"
        }), ({this_player()}) );
        tell_object( this_player(),
         "你的戒尺泛出万丈光芒，变成一把晶莹剔透的玉尺........。\n"
                );
        set_name( "cold ferule", "冰寒玉尺");
        set_short( "cold gerule", "冰寒玉尺");
        set("form",1);
                return ;
        }
}
 
