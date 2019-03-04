#include "mudlib.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(8);
	set_name("fisher", "钓客");
	add ("id", ({ "fisher", "fish" }) );
	set_short( "钓客");
	set_long(
		"这是一位专程来此钓鱼的钓客，不过似乎成绩并不理想...\n"
		);
	set_perm_stat("str", 12);
	set_skill( "dodge", 40 );
	set( "max_hp", 150 );
	set( "hit_points", 150 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set_natural_armor( 25, 5 );
	set_natural_weapon( 20, 6, 15 );
        set( "chat_chance",16);  
        set("chat_output",({"钓客把钓竿用力一扯，但是什麽都没有...\n",
                            "钓客把钓竿拉起低头重绑鱼饵...\n",
                            "钓客说道: 今天真倒霉....\n",
                            "钓客不停的玩弄他的脚趾....\n"}));
        equip_armor("/d/eastland/liang_shan/obj/rod");
        equip_armor("/d/eastland/liang_shan/armor/hat");
        set( "inquiry", ([
              "fish" : "@@ask_fish"
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
write (
"这位钓客说道: " + c_call(this_player()) +"，这□有很多鱼呦...\n");
return ;
}

