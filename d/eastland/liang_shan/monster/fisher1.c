#include "mudlib.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(8);
	set_name("fisher", "鱼夫");
	add ("id", ({ "fisher", "fish" }) );
	set_short( "鱼夫");
	set_long(
		"这是一位石碣村土生土长的鱼夫，有什麽事问他就对啦..\n"
		);
	set_perm_stat("str", 14);
	set_skill( "dodge", 60 );
	set( "max_hp", 180 );
	set( "hit_points", 180 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set_natural_armor( 30, 5 );
	set_natural_weapon( 25, 10, 20 );
        set( "inquiry", ([
              "fish" : "@@ask_fish",
              "da" : "@@ask_da"
              ]));
}
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "小姐" : "大娘" ;
	else
	return (!who->query("spouse")) ? "小哥" : "大哥" ;
}
void ask_fish()
{
        if (!(int)this_player()->query_temp("feed_fish")==1) {
write (
"这位鱼夫说道: " + c_call(this_player()) +"，对不起，我要□我的鱼...\n");
return ;
}
write (
"这位鱼夫说道: " + c_call(this_player()) +"，我养的这些鱼，全都是从平台上钓起\n"
"来的，您要有意思，也可以去试试看。对了，这里的鱼，非常\n"
"喜欢吃味道很重的烂鱼烂虾，否则很难钓的到。\n");
return ;
}
void ask_da()
{
        if ((int)this_player()->query_temp("da_quest/ask")<1) {
        write (
        "这位鱼夫说道: " + c_call(this_player()) +"，对不起，达婆婆住对面..\n");
        return ;
        }
        write (
        "这位鱼夫说道: " + c_call(this_player()) +"，你也知道达婆婆生病了吧.......\n"
        "我们也曾请来有名的神医安道全来看病，他说: 达婆婆没病，只是她一\n"
        "直以为身痪绝症而吃不下饭，因而营养不良。如果能找到她最喜欢吃的\n"
        "给她补一补，很快就能恢复健康，问题是，谁知道她最喜欢吃什麽?\n");
        return ;
 }       
