// /u/m/mad/bravar.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(12);
   set_name("Bravar","布瑞伐尔");
   add("id", ({ "man" }));
   set_short("布瑞伐尔");
	set_long(
          "布瑞伐尔先生本来是诺达尼亚的军医, 听说这屋子死了\n"
          "不少人, 而来此地调查。为何他竟会被困於这个地窖?\n"
	);
   set("race","human");
   set("gender","male");
   set("alignment",700);
   set("unit","位");
   set_perm_stat("dex",16);
   set_perm_stat("int",16);
   set_perm_stat("pie",16);
   set_natural_armor(25,10);
   set_natural_weapon(10,6,11);
   set_skill( "blunt", 50 );
   set_skill( "dodge", 60 );
   set_skill( "anatomlogy", 70 );
   set_temp( "aiming_loc", "ganglion" );
   set("chat_chance",10);
   set("chat_output", ({
           "布瑞伐尔无力地呻吟著: 食.....食......\n"
           "   (他的声音太小以致於你听不清楚...)\n"
     }) );
   wield_weapon("/d/noden/house/obj/mace");
}

int accept_item(object me,object item)
{
  string name;
  object ob;

  name=(string)item->query("name");
   if( !name || name != "cookie" ) {
    return 0;
  }

   item->remove();
   ob = new( "/d/noden/house/obj/incantation" );
   ob->move(me);
   this_player()->set_explore("noden#26");
   tell_object( me,
     "布瑞伐尔说: 谢谢...我很久没吃东西了! 这张驱邪符算是回报吧!\n" );
   return 1;
}
