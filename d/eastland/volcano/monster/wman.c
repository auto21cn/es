#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(10);
	set_name( "The young man", "矮灵族青年" );
	add( "id", ({ "man" }) );
	set_short( "矮灵族青年" );
	set_long(
         "一个矮灵族的青年，有著略带苍白的脸孔，忧郁的眼神，微卷的头发。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 0 );
	set_perm_stat( "str", 16 );
        set_perm_stat( "dex", 16 );
	set( "wealth/gold", 2 );
        set( "hit_points", 150);
        set( "max_hp", 150);
        set("natural_armor_class",45);
        set("natural_defense_bonus",15);
        set_natural_weapon(18,9,15);
        set("chat_chance",15);
        set("chat_output",({
            "青年正喃喃自语：唉、除非老天爷帮助我，不然我是没有指望了。\n"
            }) );
        set( "inquiry", ([
             "trouble" : "@@ask_trouble",
             "help" : "@@ask_trouble",
             "rose" : "@@ask_rose",
             ]) );
}

void ask_trouble(object who)
{
  tell_object(who,
     "\n青年说：我爱上了部落里最美的那位女孩子，但是．．．．．．\n"+
     "唉 ! 那位冰山美人竟然说：假如我带著蓝色的玫瑰花向她求婚，她就答应。\n"+
       "但谁都知到这世界上蓝色的玫瑰花根本就不存在。\n\n");
}

void ask_rose(object who)
{
  tell_object(who,
     "\n青年说：我需要一朵真正的蓝色玫瑰花，拜托你找一朵给我好吗。\n\n"
  );
}

int accept_item(object me,object item)
{
  string name;
  object ob;

  name=(string)item->query("name");
  if (!name || name!="blue rose") {
    return 0;
  }

  if (this_player()->query_temp("blue_rose")) {
    write("青年说：非常谢谢你，让我终於可以娶到一位美娇娘。\n");
    write("        我已经不再须要这朵玫瑰了。\n");
    item->move(me);
    return 1;
  }
  
  if (item->query(me->query("name"))) {
    write("青年说：啊 ! 这真的是那蓝玫瑰，非常谢谢你，我求婚有望了。\n");
    write("另外再告诉你一个秘密：我曾听过我父亲说过我们村落好像有个关於\n");
    write("广场的秘密，但我不太记得了．．．你可以去问我父亲关於广场(square)的事。\n");
    me->set_temp("blue_rose",1);
    item->remove();
    return 1;
  }
  
  write("他看了你给他的玫瑰一眼，唉、这是人造的吧。\n");
  write("我需要的是真正的玫瑰，谢谢。\n");
  item->move(me);
  return 1;

}
