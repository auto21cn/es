#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "merchant", "鱼贩" );
	add( "id", ({ "fish merchant" }) );
	set_short( "鱼贩" );
	set_long("一个长相普普通通的鱼贩。\n");
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_skill( "dodge", 40 );
	set( "wealth/gold", 5 );
	set( "natural_weapon_class1", 4 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 5 );
        set( "inquiry", ([
	        "fish": "@@ask_fish",
                "cook": "@@ask_cook"
        ]) );
}
int ask_fish()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/skill")) || this_player()->query_temp("fat_quest/skill") < 1) {
write(
"鱼贩说道，我的鱼很好吃的哟??\n");
}
else {
write(
"鱼贩笑道: 看你的样子好像很贤慧，要不要我教你怎麽料理(cook)鱼呢?\n");
return 1;
}
}
int ask_cook(int ob1)
{
      if ( present("cook note",this_player()) ) {
write(
"鱼贩说道: 你有没有什麽可以抄下来的，这样你才不会忘记。於是你把厨师的笔记\n"
"拿给鱼贩，只见他在笔记上涂涂写写之後，然後满意的把笔记还你.....\n");
this_player()->set_temp("fat_quest/skill",2);
return 1;
}
else 
    write("鱼贩说道: 你有没有笔记之类的东西啊??\n");
    return 1;
}
