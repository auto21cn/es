#include <mudlib.h>

inherit MONSTER;

void create()
{

        ::create();
        set_level(1);
        set_name( "dove", "鸽子" );
        add ("id", ({ "dove" }) );
	set( "unit", "群" );
        set_short( "很多只鸽子" );
        set_long(
           "一只温驯的小白鸽，正悠闲地在广场上漫步。\n"+
           "他似乎注意到，除了和善的精灵外，你正注视著他，\n"+
           "又对著你摆\了摆\头，好像想告诉你什麽......。\n"
        );
        set_perm_stat("str", 1);
        set_perm_stat("dex", 5);
        set ("natural_armor_class", 10);
        set ("gender", "male");
        set ("race", "鸽子");
        set("alignment",300);
        set("natural_max_damage1",10);
        set("natural_min_damage1",5);
        set_c_limbs(({"身体","头部","翅膀","脚部"}));
	set_c_verbs(({ "%s用它的嘴吧向%s啄去"}));
}

void init()
{
 add_action("kill_dove","kill");
}

int kill_dove(string arg)
{
 if( arg == "dove" && random(10) > 4 )
 {
  object dove;
  dove=this_object();

   tell_room( environment(this_object()),
        "鸽群似乎受到了惊吓，成群结队地飞起．．．．\n"+
        "盘旋在空中．．．．",
        this_object());
    dove->remove();
   return 1;
 }
 else
 {
  this_player()->command("kill"+arg);
 }
}

void die()
{
   object killer;

   killer = query("last_attacker");
   if( killer ) killer->set_explore("noden#37");
   ::die();
}
