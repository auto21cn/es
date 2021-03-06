#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(14);
    set_name("Zhan Shung","张顺");
    add("id",({"zhan","shung"}) );
    set_short("张顺");
	set_long(@C_LONG
外号浪里白条，江州人，浑身雪练也似一般白肉，深通水性，水底下伏得七日
七夜，水□行起就如一根白条，又兼精通武艺，为梁山四寨水军大统领。
C_LONG
	);
    set("alignment",100);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",20);
    set_perm_stat( "int",18);
    set_perm_stat( "karma",22);
    set_skill("dagger",60);	
    set_skill("dodge",70);
    set ("max_hp",400);
    set ("hit_points",400);
    set ("time_to_heal",5);
    set ("wealth", ([ "gold":180]) );
    set_natural_weapon(25,13,25);
	set_natural_armor(35,20);
	set ("aim_difficulty",([ "weakest":40,"vascular":30]) );
	set("special_defense", (["magic":30,"none":10]) );
    set ("weight", 400);
    set ("inquiry",([
         "fish" : "@@ask_fish",
         "whirl" : "@@ask_whirl"
         ]));
    equip_armor(TARMOR"fish_skin");
    wield_weapon(TWEAPON"waterdagger");
    equip_armor(TARMOR"hat");
}
void ask_fish()
{
if (!(this_player()->query_temp("fat_quest/fish")) || (int)this_player()->query_temp("fat_quest/fish")<1) {
write(
"张顺说道: 要鱼，湖里多的是，自己不会去抓呀?\n");
return 0;
}
else write(
"张顺说道: 是吴用先生叫你来的吗? 刚才吴用先生派来一个使者，把事情都告诉了我。\n"
"以後每天我们都会送一篮新鲜的鱼虾过去，相信对肥东应该有些帮助。\n");
call_out("suggest_diet",5,this_player());
return 0;
}
int suggest_diet()
{
write(
"当你转身欲行，张顺突然叫住了你，并且说道: \n"
"关於这件事，我有别的建议，据我的手下所言: 他们不去吃的原因，除了没有\n"
"肉之外，肥东的厨房非常的不卫生，这也是一个重要的原因。\n\n"
"听了张顺的话，你觉得，除了找到肉以外，设法维持厨房的清洁也是很重要的\n"
"但是肥东根本不能打扫，难不成要带他去减肥(diet)吗?\n");
this_player()->set_temp("fat_quest/fish",2);
return 0;
}
void ask_whirl()
{
write(
"张顺说道: 湖边的渔民们有一个传说，在湖的最深处住著一只千年的大河蚌\n"
"当它在用水管吸水时，就产生了湖中的漩涡，详情是如何我也不清楚....\n");
return 0;
}
