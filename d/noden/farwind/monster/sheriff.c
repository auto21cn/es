// town_guard.c
// A pursuing monster. That is, if you are in combat with him, and
// you leave, he'll go after you. You can lose him if you run fast
// enough but otherwise he's pretty lethal.
// Also, if A attacks B, then the guard will attack A.
// Comments on monster properties are found in /obj/foobird.c
// Written by Mobydick, 6-20-93.

#include "/d/noden/farwind/farwind.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(15);
	set_name( "ebbruce", "艾柏鲁斯" );
	add( "id", ({ "sheriff" }) );
	set_short( "远风镇保安官艾柏鲁斯");
	set_long(@C_LONG
艾柏鲁斯是这个镇上的保安官，他的任务就是维护远风镇的和平宁静，
这个人十分严肃，最好别在远风镇打架或干坏事 (至少别在他面前让他
看到) 。
C_LONG
                );
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "natural_armor_class", 50 );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 10 );
	set( "max_hp", 450 );
	set( "hit_points", 450 );
	set( "moving", 1 );
	set( "speed", 30 );
	set( "patrol", ({ "north", "south", "west", "west", "east", "east",
		"south", "north" }) );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 18 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set( "special_defense", ([ "all": 20 ]) );

	wield_weapon( FARWIND"items/b_sword");
	equip_armor( FARWIND"items/leather_boots");
	equip_armor( FARWIND"items/breast_plate");

	set ("pursuing", 1) ;
	set ("inquiry", ([
"lucksis": "@@ask_lucksis"
	]) ) ;
}

void init()
{
   npc::init();
   add_action( "kill_killer", "kill" );
}

int kill_killer(string arg)
{
   object killer;

   killer = this_player();
   if( arg && present(arg,environment(this_object()))
        && arg != "ebbruce" && arg != "torch" )
   {
     if(killer) {
            kill_ob(killer);
            killer->kill_ob(this_object());
            tell_object(killer,
         "艾柏鲁斯瞪你一眼，说道: 你竟敢公然在远风镇撒野？\n");
            tell_room(  environment(killer),
         "艾柏鲁斯横眉一竖,胡子一翘,立刻出手海Ｋ"+killer->query("c_name")+
        "......!\n", killer );
     }
   }
}

void ask_lucksis(object who)
{
     if (!(who->query_temp("lucksis_quest")) || (int)(who->query_temp("lucksis_quest/ask"))==0 ) 
       tell_object(who,"艾柏鲁斯依旧不微言笑的站著.\n"
                       );
     else
       {
         tell_object(who,"艾柏鲁斯说:你是拉克希丝派来的?\n"
                         "那个小女子现在还有没有动不动就哭泣?\n"
                         "艾柏鲁斯露出难得一见的笑容.然後对你说:\n"
                         "对不起,我必须维护这地方的安全了,请别打搅我.\n"
                         "\n\n你感觉出艾柏鲁斯对於拉克希丝似乎并无任何的\n"
                         "感情.或许艾柏鲁斯根本并不会对任何人产生感情.\n"
                    );
         who->set_temp("lucksis_quest/ebbruce",1);             
       }
     return;
}

