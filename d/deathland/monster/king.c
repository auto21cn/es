#include "/d/deathland/echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Dwarf King Molader V", "矮人国王莫拉德五世" );
	add ("id", ({ "king", "molader", "dwarf", }) );
	set_short( "矮人国王莫拉德五世" );
	set_long(@DESC
矮人国王莫拉德五世,他看起来虽然很老,但是他的力量和战斗技巧还是数一数二的.
在数次的矮人与巨人的战争之中,他领导著矮人族击退巨人的攻击,而且他将仍继续
与邪恶的巨人族战斗下去.
DESC
	);
    set("weapon_master",1);
    set( "alignment",1600);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 21 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 30);
	set_skill("longblade",100);
	set_skill("parry",100);
        set("special_defense", (["all":35,"none":60,"monk":20,"scholar":20]) );
	set ("max_hp", 999);
	set ("hit_points", 999);
	set ("wealth", ([ "gold": 5 ]) );
	set_natural_weapon( 25, 5, 45 );
	set_natural_armor( 50, 60 );
    set ("weight", 400);
    set( "inquiry", ([
         "troll" : "@@ask_troll" ,
         "valor" : "@@ask_valor" ,
         "queen" : "@@ask_queen" ,  
           ]) );
    set ("unbleeding",1);
    set ("chat_chance", 8);
	set ("chat_output", ({    "矮人国王莫拉德五世希望一个伟大的勇者(valor)从巨人(troll)的侵略中拯救他的国家\n",
	    }) ); 
	set ("att_chat_output", ({	    "国王说:愚蠢的家伙,你不可能击败我的\n",
	    }) );
	wield_weapon(Weapon"/blacksword");
    equip_armor(Armour"/leggings02");
    equip_armor(Armour"/helmet02");
    equip_armor(Armour"/boots02");
    equip_armor(Armour"/plate03");
}

void ask_troll( object who )
{
        tell_object( who,@MSG1
巨人,有很强的生命力,我们矮人族已经与它们作战数百年了
如果你想知道更详尽的资料,或许\巨人战术研究室的卡尔(Karl)将军
能告诉你.
MSG1
);
      return ;        
}

void ask_valor(object who)
{
      
      tell_object(who,
      "我们须要一个勇者来帮助对抗巨人(troll),如果你愿意帮助我们请先去找卡尔服德\n");
      return ;
}

void ask_queen(object who)
{
     object *items,special;
     int i;
     
     tell_object(who, @ASK_QUEEN_1
国王说:唉!!自从我的大儿子法拉第死掉了之後, 她就在也没有露出笑容了. 
我也劝过她凡事要想得开一些, 但是她仍无法停止悲伤. 我也曾经请她最好
的朋友安琪拉来劝过她, 然而仍无法停止她的忧伤.
ASK_QUEEN_1
     );
     if ( (int) who->query_level() >= 10 ) {
       items=all_inventory(who);
       for(i=0;i<sizeof(items);i++) {
         if ( (string)items[i]->query("name")== "Black Box of Molader" )
           return;
         }
       tell_object(who,@ASK_QUEEN_2
这里有一个黑盒子, 当你正为了解决我们的难题时, 它将是有帮助的,
拿著它, 希望你能够早日帮助皇后恢复往日的笑容.
ASK_QUEEN_2
       );
       special=new(Object"/blackbox");
       
       switch ( (int)who->query_quest_level("queen_smile") ) {
         case 0: break;
         case 5: 
                 tell_object(who,"你已经完成了这任务,但这黑盒子的东西还是能够帮助你的.\n");
         case 4:
         case 3:  
         case 2: 
                 special->set("quest_item/crystal_card",1);
         case 1: special->set("quest_item/explorer_bell",1);
                 special->set("quest_action/invoke_bell",1);
                 tell_object(who,"你曾试著帮助过我们,这黑盒子保存著一些有用的物品.\n");
         }
       special->move(who);  
       }
     return;
}

void die()
{
	object killer,scroll;
	killer = query("last_attacker");
        if (killer)
	killer->set_explore( "deathland#37" );
	 scroll = new( "/d/mage/tower/obj/star_scroll" );
   scroll->move(environment(this_object()));

   tell_room( environment(this_object()),
     "『咚』的一声, 一件东西从矮人国王的怀中落在地上。\n",
     this_object() );
	::die(1);
}

void show_headband(object player)
{
     object key;
     tell_object(player,@MSG2
你是安琪拉介绍来的文学家吗? 希望你能让皇后重新拾起她往日的笑容.
拿著这钥匙去找皇后吧!
MSG2
     );
     key=new(Object"/key01");
     key->move(player);
     return ;
}
