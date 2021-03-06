#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(5);
	set_name( "The boy", "矮灵族小男孩" );
	add( "id", ({ "boy" }) );
	set_short( "矮灵族小男孩" );
	set_long(
          "一个矮灵族的小男孩，正在这里玩泥巴。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 0 );
	set_perm_stat( "str", 8 );
	set( "wealth/gold", 5 );
        set( "hit_points", 100);
        set( "max_hp", 100);
        set("natural_armor_class",12);
        set("natural_defense_bonus",5);
        set("chat_chance",15);
        set("chat_output",({
        "小男孩说：好心的叔叔阿姨们给个糖吃吧。\n" }) );

        ob1=new(OWEAPON"wgun");
        ob1->move( this_object() ); 
	wield_weapon( ob1 );

        equip_armor(OARMOR"dudo2");
}

int accept_item(object me,object item)
{
   string name;
   int candy;
   
   name=(string)item->query("name");
   item->remove();
   if (this_player()->query_temp("ohio")>=2) {
     tell_object(me,
        "\n告诉你一个秘密：有一天，我在外面玩的时候，碰到过一个快要死的人。\n"
        "我很害怕就急急忙忙的跑回来了。\n");
     return 1; }

   switch(name) {
   case "gold_chocolate" :
         if (this_player()->query_temp("gold_chocolate"))
            tell_object(me,
              "小男孩说：这种糖果我已经吃过了，有没有别的?\n");
         else {
            this_player()->set_temp("gold_chocolate",1);
            tell_object(me,
              "小男孩说：好好吃，谢谢。\n"); }
         break;
   case "silver_chocolate" :
         if (this_player()->query_temp("silver_chocolate"))
            tell_object(me,
              "小男孩说：这种糖果我已经吃过了，有没有别的?\n");
         else {
            this_player()->set_temp("silver_chocolate",1);
            tell_object(me,
              "小男孩说：好好吃，谢谢。\n"); }
         break;
   case "red_chocolate" :
         if (this_player()->query_temp("red_chocolate"))
            tell_object(me,
              "小男孩说：这种糖果我已经吃过了，有没有别的?\n");
         else {
            this_player()->set_temp("red_chocolate",1);
            tell_object(me,
              "小男孩说：好好吃，谢谢。\n"); }
         break;
   case "blue_chocolate" :
         if (this_player()->query_temp("blue_chocolate"))
            tell_object(me,
              "小男孩说：这种糖果我已经吃过了，有没有别的?\n");
         else {
            this_player()->set_temp("blue_chocolate",1);
            tell_object(me,
              "小男孩说：好好吃，谢谢。\n"); }
         break;
   case "yellow_chocolate" :
         if (this_player()->query_temp("yellow_chocolate"))
            tell_object(me,
              "小男孩说：这种糖果我已经吃过了，有没有别的?\n");
         else {
            this_player()->set_temp("yellow_chocolate",1);
            tell_object(me,
              "小男孩说：好好吃，谢谢。\n"); }
         break;
   default :
             return 1;
   };

   candy=0;
   if (this_player()->query_temp("gold_chocolate"))
     candy+=1;
   if (this_player()->query_temp("silver_chocolate"))
     candy+=1;
   if (this_player()->query_temp("red_chocolate"))
     candy+=1;
   if (this_player()->query_temp("blue_chocolate"))
     candy+=1;
   if (this_player()->query_temp("yellow_chocolate"))
     candy+=1;

   if (candy==5 && this_player()->query_temp("ohio")) {
      this_player()->set_temp("ohio",2);
      tell_object(me,
          "\n告诉你一个秘密：有一天，我在外面玩的时後，碰到一个快要死的人。\n"
          "我很害怕就急急忙忙的跑回来了。\n"); }
   return 1;

}
