#include "mudlib.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(6);
	set_name("Da", "阿达");
	add ("id", ({ "da", "Da" }) );
	set_short( "阿达");
	set_long(
		"瘦弱的少年，为了不知名的原因来此打工．\n"
		);
	set_perm_stat("str", 10);
	set_skill( "dodge", 30 );
	set( "max_hp", 120 );
	set( "hit_points", 120 );
	set( "gender", "male" );
	set( "race", "beholder" );
	set( "alignment", 20 );
	set_natural_armor( 10, 2 );
	set_natural_weapon( 10, 4, 10 );
        set( "chat_chance",5);  
        set("chat_output",({"阿达喃喃自语: 奶奶的病还没好，怎麽办??\n",
                            "少年阿达正拼了命的工作....\n"}));
        set( "inquiry", ([
              "sick" : "@@ask_sick",
              "grandmother" : "@@ask_grama",
              "fish" : "@@ask_fish"
              ]));
}
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "姐姐" : "大娘" ;
	else
	return (!who->query("spouse")) ? "哥哥" : "大叔" ;
}
void ask_grama()
{
write (
"少年阿达叹了一口气，说道: 你认识我的奶奶吗? 那你应该知道她\n"
"生病的事情吧?\n");
this_player()->set_temp("da_quest/ask",1);
return ;
}

void ask_sick()
{
if ((int)this_player()->query_temp("da_quest/ask")<1) {
write (
"少年阿达说道: 喔，这位" + c_call(this_player()) +"生病了吗? 也许\你可以找我们寨\n"
"中的第一神医，安道全先生......\n");
return ;
}
write (
"少年阿达说道: 这位好心的" + c_call(this_player()) +"，我家就在大湖东的石碣村，家中人丁单薄\n"
"只有奶奶和我相依为命，但是两三年前，她突然得了一种奇怪的病，我也曾请\n"
"寨中的第一神医，安道全先生去看过，但仍然是无效，所以我现在在努力打工\n"
"赚钱，看能不能把奶奶带去默尔斯国医治....\n");
return ;
}
void ask_fish()
{
if ((int)this_player()->query_temp("da_quest/ask")<1) {
write (
"少年阿达说道: 喔，这位" + c_call(this_player()) +"，对不起，我正在工作\n"
);
return ;
}
write (
"少年阿达说道: 这位好心的" + c_call(this_player()) +"，您是要问我奶奶喜欢的鱼吧?\n"
"我奶奶常说，以前这湖里有一种黄金色的鲤鱼，是她最喜欢的食物，不过，这几年来\n"
"已经很少见到了....\n");
return ;
}
