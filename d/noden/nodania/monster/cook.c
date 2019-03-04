#include "mudlib.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("cook", "厨师");
	set_short("忙碌的厨师");
	set_long(@CLONG
这个厨师正在替整个王宫中的人准备食物——没错，整个王宫，包括
国王一家人、仆役、侍从、及宫女。
CLONG
	);
	set_perm_stat( "kar", 30 );
	set_skill( "dodge", 50 );
	set( "natural_armor_class", 40 );
	set( "natural_weapon_class1", 9 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 9 );
	set( "alignment", 150 );
	set( "wealth/gold", 5 );
        set( "inquiry", ([
	        "fat": "@@ask_fat",
        ]) );
}
int ask_fat()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/fish")) || this_player()->query_temp("fat_quest/fish")<3) {
write(
"厨师疑惑的看著你，说道: 我不算很胖吧??\n");
}
else {
write(
"\n你一五一十的把肥东的困难告诉了厨师，一阵沉默之後，厨师说道: 我这个徒弟\n"
"真是不长进，一点小小的问题就灰心丧志，真是让我失望，一个厨师如果自己都失\n"
"去信心，那客人又怎麽会有信心呢? 我十几年前只教他一半，就是要他自己成长，\n"
"看来我是做错了.......\n");
call_out("help_fat",10,this_player());
return 1;
}
}
int help_fat(object ob1)
{
	object ob;
      if ( present("cook note",ob1) ) return 0;
      else {
write(
"厨师继续说道: 算了，谁叫他是我徒弟呢，再帮他一次忙好了。说完转身从\n"
"身後的箱子中翻出了一本小小的笔记本。说道: 这是我这些年来做鱼料理的\n"
"心得，应该可以帮上一点忙。不过要求得最高深的鱼料理技术，我想去找卖\n"
"鱼的人可能最快，你可以去找他们并且把心得抄在笔记上一起带回去....\n");
ob1->set_temp("fat_quest/skill",1);
   ob = new("/d/eastland/liang_shan/obj/note");
   ob->move(ob1);
return 1;
}
}
