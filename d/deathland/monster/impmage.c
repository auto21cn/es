#include "../echobomber.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
    set_level(15);
    set_name("Imp mage Morr","妖精魔法师摩儿");
    add("id",({"imp","mage","morr"}) );
    set_short("Imp mage Morr","妖精魔法师摩儿");
	set_long(@LONG
??
LONG
    ,@C_LONG
一个身上长著一对翅膀的妖精魔法师.似乎有著强大的法力.
C_LONG
	);
    set("alignment",-400);
    set( "gender", "female" );
    set( "race", "imp");
    set( "unit", "个" );
    set_perm_stat( "dex",21);
    set_perm_stat( "str",11);
    set_perm_stat( "int",25);
    set_perm_stat( "con",13);
    set_perm_stat( "piety",17);
    set_perm_stat( "karma",22);
	
    set ("max_hp",340);
    set ("max_sp",1300);
    set ("hit_points",340);
    set("spell_points",1300);
    set ("wealth", ([ "gold":21]) );
    set_natural_weapon(22,12,17);
	set_natural_armor(65,24);
    set ("weight", 160);
    set_skill("target",100);
    set_skill("elemental",100);
    set_skill("concentrate",100);
    set_skill("dodge",98);
    set_skill("wand",100);
    set("magic_delay",2);
    set("spells/sleet",4);
    set("spells/fireball",4);
      set( "inquiry", ([
         "rune" : "@@ask_rune",
         "bottle" : "@@ask_bottle",
         "painting" : "@@ask_painting",
         "chichikair":"@@ask_chichikair",
         "book":"@@ask_book",
         "charge":"@@ask_charge",
         ]) );
    set("special_defense", (["all":35,"none":10]) ); 
    set ("aim_difficulty",(["vascular":20]) );
    set( "tactic_func", "cast_spell");
    wield_weapon(Weapon"/wand");
}

void ask_rune(object who)
{
     tell_object( who ,@MSG1
这些魔法书籍上记载著种种召唤邪恶生物的方法,但是由於这些文字实在是太难了.
所以目前我也只会召唤出幻影来帮助我,只不过我并没有把握能控制住它.
MSG1
       );    
}

void ask_bottle(object who)
{
     object *items;
     int i;
     
     tell_object( who,@MSG2
这个瓶子是我的老师给我的,这个魔法瓶....
嘿嘿,这是一个秘密.
MSG2
                 );
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_action/find_book")) {
              tell_object( who,@MSG3
但是既然你帮我拿回了这本研究心得, 那麽告诉你也无妨 : 
这是一个锁魂瓶, 它能够把他人的灵魂锁於其中, 但是由於 
在使用锁魂瓶的时候, 使用者必须把自己的生命力注入於内 
, 因此通常是事先注入於内, 像这个锁魂瓶已经有我的生命 
力在其中了, 所以你不能使用 ,如果你找到了锁魂瓶, 你可 
以拿来, 我能够注入(charge)你的力量而让你能使用它 .
MSG3
                 );
           } 
      return;           
}

void ask_painting(object who)
{
     tell_object( who,"摩儿回答你:喜欢我的自画像吗?\n");

}

void ask_chichikair(object who)
{
     tell_object(who,@MSG4
摩儿说: 奇奇凯尔, 原本在我们暗黑魔法研究小组中最有心得的一位高级魔法师 ,
想不到他会变得如此疯狂. 他偷走了我们辛苦多年的研究心得, 如果你能够帮我找
回那本研究心得(book), 我想我会很感激你的 .
MSG4
                 );
}

void ask_charge(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
          if ( items[i]->query("quest_action/find_book") ) { 
          if ( items[i]->query("quest_item/ancient_bottle") ) {
          tell_object(who,@MSG5
我将尽我所有的力量来帮助你.....
摩儿开始口中念念有辞..
世
间
的
魔
神
魔
瓶
须
要
你
们
的
力
量
一道耀眼的光芒进入你的眼中.
此时摩儿说:
你已经可以使用这索魂瓶了.
MSG5
          );
          items[i]->set("quest_action/charge_bottle",1);
          if ( (int)who->query_quest_level("queen_smile") < 3 ) 
             who->finish_quest( "queen_smile" , 3 );
          }
          else 
          tell_object(who,"先找出索魂瓶吧.\n");
          return;          
          }
     tell_object(who,"摩儿以奇怪的眼神看著你.\n");
     return;     
}
void ask_book(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
          if ( items[i]->query("quest_item/study_book") ) { 
          tell_object(who,@MSG6
你找到我的书了.谢谢你.
摩儿拿回她的书并说:谢谢,如果有须要帮助的
话, 尽管开口.
MSG6
          );
          items[i]->set("quest_item/study_book",0);
          items[i]->set("quest_action/find_book",1);
          return;
          }
     tell_object(who,"我们多年的研究心得,已经消失了, 希望你能帮我找回来.\n");
     return;
}

int cast_spell()
{
    object victim;
    string name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    
    if( random(10) < 3 ) {
      command("cast sleet on "+name);
      return 1;
     }
    else if (random(10)< 2) {
      command("cast fireball on "+name);
      return 1;
      }
    else return 0;   
}

