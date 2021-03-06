#include <mudlib.h>
inherit WEAPON;

#define NEED_ALIGNMENT 6000

void create()
{
    set_name("small dagger","小小银针");
    add("id",({"dagger","needle"}) );
    set_short("小小银针");
    set_long(@C_LONG
小小银针是『一代神医 小雪子』拿来治疗病患用的。它通体纯白,既轻且薄,两端
极其锋利,对於用来针炙、治病是再好不过了。相传小小银针是由六六三十六个铁
匠,经由七七四十九天以精火练制而成,虽然所花费的工程浩大,不过和被它活命的
人数来比,却也是值得的。 
C_LONG
       );
    set("unit","把");
    setup_weapon( "dagger", 40, 1, 1 );
    set("weight",40);
    set("value",({150,"gold"}));
    set( "wield_func","wield_dagger");
    set( "unwield_func","unwield_dagger");
}

int stop_wield()
{
     object holder;
     int my_ali;
         holder = this_player();
         my_ali = (int)holder->query("alignment");
         if (my_ali > NEED_ALIGNMENT )
            return 0;
         else {
               notify_fail(
                   "你还不够善良使得小小银针不听你的指挥，令你握不住它。\n\n"
                                                  );
               return 1; 
          }
}

int wield_dagger()
{
   int my_int;
   
   my_int=this_player()->query_perm_stat("int");
   set( "min_damage",my_int);
   set( "max_damage",my_int+10);
     return 1;
}
                  
int unwield_dagger()
{
   set( "min_damage",1);
   set( "max_damage",1);
     return 1;
}
