#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(16);
        set_name( "Red phoenix","[0;31m□[1;31m□[0;37m[0;31m□[1;31m□[0;37m[0;31m□[1;31m□[m"  );
        add( "id", ({ "phoenix" }) );
        set_short( "[0;31m□[1;31m□[0;37m[0;31m□[1;31m□[0;37m[0;31m□[1;31m□[m" );
        set_long(@C_LONG
一只颛顼养的宠物，全身火炭也似的凤凰，全身羽毛毫无斑杂，俊美极了。这只火
凤凰正在剔翎刷毛，神情颇为自在。
C_LONG
        );        
        set( "unit", "只" );
        set( "race", "monster");
        set( "race","凤鸟");
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "con", 25 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,33,53 );
        set_natural_armor( 76,39 );
        set_skill("dodge",60);
        set( "alignment", 0 );
        set( "mountable", 1);
        set( "max_load", 2600 );
        set_c_limbs( ({ "凤冠", "身体", "爪", "尾巴","翅膀" }) );
        set_c_verbs( ({ "%s抬起凤爪, 往%s一抓", 
                        "%s用它的喙子往%s一啄"}) );
}
void init()
{
    mount::init();
}
int stop_attack()
{
   object king;
   if ( king=present("ra-shan",environment()) ) {
      tell_room(environment(),"火凤凰招唤它的主人来攻击它的敌人！\n\n");
      king->kill_ob(this_player());
   }
   return 0;
}
int do_mount(string arg)
{
   object king;
   
   if ( arg!="phoenix" ) return ::do_mount(arg);
   if ( this_player()->query_temp("mounting") ) return ::do_mount(arg);
   if ( king=present("ra-shan",environment()) ) {
     tell_room(environment(),sprintf("%s怒道：想偷我的凤凰，门都没有，看来我不好好教训你，你是不知道偷窃是犯法的，给我死死去！！\n"
      ,king->query("c_name")));
     king->kill_ob(this_player());
   }
   else ::do_mount(arg);
   return 1;
}
