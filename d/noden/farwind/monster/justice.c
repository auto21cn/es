// justice.c
// The justice of the peace of Farwind. 
// Nominally performs marriages, although the marriage code is in the
// courthouse and not in the monster.

#include <mudlib.h>

inherit MONSTER ;

int time=0;
void create ()
{
	::create() ;
	set_level(19);
	set_name("allynia", "艾里妮雅");
	add ("id", ({ "justice", "judge" }) ) ;
	set_short("法官艾里妮雅");
	set_long(
		"艾里妮雅一生最大的嗜号就是为人主持婚礼。\n"
	);
	set ("no_attack", 1);
	set ("gender", "female");
	set ("race", "imp");
}

void init()
{
        ::init();
        add_action("wedding_word","wedding");
}

int wedding_word(string str)
{
	object ppl,ppl2;
	string who1,who2;
	int crazy;
	if ( !wizardp(this_player()) ) return 0;
        if( !str || sscanf( str, "%s to %s", who1, who2 ) != 2 )
                return notify_fail( "Syntax : wedding <boy> to <girl>" );

	if (!present(who1,environment()) || !present(who2,environment()) )
	return notify_fail( 
	      "法官摇摇头：「 新郎或新娘不在这里 !!」\n" );

	if ( time==0 )
	{
	tell_room( environment(), 
	"法官庄严地对著 "+capitalize(who1)+" 说道：「 "+capitalize(who1)+" !! 你愿意一辈子照顾 "+capitalize(who2)+" ，\n"+
	"不论刮风下雨，reboot 或 crash ，天天拼命赚钱供 "+capitalize(who2)+" 挥霍，\n"+
	"并且尽自己所有的能力来爱护她，以使她快乐吗？」\n" ,
        this_object() );
		time=1;
		crazy=0;
	return 1;
	}

        if ( time==1 )
        {
        tell_room( environment(), 
	"法官转头对著 "+capitalize(who2)+" 说道：「 "+capitalize(who2)+" !! 你真的愿意成为 "+capitalize(who1)+" 的新娘，\n"+
	"承诺一生一世爱他、敬他、帮他花钱，不论 reboot 或 crash ，\n"+
	"天天伴在 "+capitalize(who1)+" 的身旁，直到昏倒在电脑前吗？」\n" ,
        this_object() );
                time=2;
        return 1;
	}

        if ( time==2 )
        {
        tell_room( environment(), 
	"法官微笑地说道：「恭喜你们 !! "+capitalize(who1)+" 和 "+capitalize(who2)+" !!! \n"+
	"我宣布你们成为正式的夫妻，请交换戒指，同时别忘了登记喔 !!」\n",
        this_object() );
                time=3;
        return 1;
	}

        if ( time==3 )
        {
        tell_room( environment(),
	"艾里妮雅法官突然跳起来，拍手叫道：「 我要亲新郎 !! 其他人排我後面 !!」\n"+
	"说著，不由分说的抱著 "+capitalize(who1)+" 猛亲 ... 亲 ...亲 ...\n\n"+
	"你终於理解 ...... 这家伙 ... 是个... 花痴 !!!! \n\n" ,
        this_object() );
                time=0;
	command("hold "+who1);
	command("kiss "+who1);
        command("lkiss "+who1);
        command("lkiss "+who1);
	command("lkiss "+who1);
        return 1;
	}

	return 0;
}
