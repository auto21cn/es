
#include <mudlib.h>
inherit MONSTER;

void create()  {
	::create();
	set_level(5);
	set_name("pig8");
	set("race","human");
	set("gender","male");
	set_short("The evil pig", "猪八戒");
	set_long(
"\n",
"猪八戒是色狼协会的守护神. 它有圆圆的身体, 大大的耳朵, 色眯眯的\n"+
"嘴脸. 并不时从嘴脚流出淫荡的唾液! 让你看了觉得十分舒服, 很想鼓\n"+
"起勇气, 上前跟它抱抱!\n"
	);
	set("no_attack",1);
	set("chat_chance",5);
	set("chat_output",({
"Pig8 says to you with its EVIL looking face:Believe in me and you'll\n"+
"have a permanent life!\n",
"猪八戒色眯眯的对你说道：信我者得永生!\n"
	}));
}

void init()  {
	if ((int)this_player()->query("CWA") == 1) {
		write(can_read_chinese()?
"你大老远就听到色狼守护神猪八戒亲切地对你说："+this_player()->query("c_cap_name")+"! 我的子民! 欢迎你回家!\n" :
"Welcome HOME! "+this_player()->query("cap_name")+"! My lovely child!\n");
		tell_room(environment(this_player()), ({
"Let's stand up to welcome "+this_player()->query("cap_name")+"'s coming\n",
"猪八戒兴奋地说道：让我们起立鼓掌欢迎色狼英雄"+this_player()->query("c_cap_name")+"的到来!\n"}),
		this_player());
	} else {
		write(can_read_chinese()?
"你还未踏进大厅, 就听道猪八戒的声音："+this_player()->query("c_cap_name")+"! 我注意你很久了! 像你这麽色的人应该赶快加入我们神圣的色狼协会!\n" :
"I've been watching you for a loooong time! "+this_player()->query("cap_name")+"! I think ppl\nas color as you better join us CWA ASAP!\n");
	}

}
