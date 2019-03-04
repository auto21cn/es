#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
inherit OBJECT;
int bee_out=0;
void create()
{
        set_name("amazing flower", "奇异之花");
        add ("id",({ "flower"}));
        set_short("奇异之花");
        set_long(
                 "这是一朵具有七彩花瓣的花。\n"
                 "它的花语是：没有不可能的事。\n"
                 "这朵花上还系著一张小卡片。\n");
        set("unit", "朵");
        set( "weight", 1 );
        set ("value", ({ 10, "silver" }) );
        set("message","BLANK");
	set("no_sale",1);
	set("c_smell","一阵沁鼻的馨香直透入你的心房，令你感觉精神振奋全身舒坦。");

}
void init()
{
	add_action("write_msg","write");
	add_action("read_msg","read");
	add_action("look_card","look");
	add_action("smell_me","smell");
}
string get_c_sex(object who)
{
	string sex;
	sex=who->query("gender");
	if (sex=="male")
	  return "他的"; 
        if (sex=="female")
          return "她的";
	return "它的" ;
}
int look_card(string arg)
{
	if (arg !="card")
	return 0;

	write(
		"这是一张飘著清新花香的洁白小卡片，它可以为人们传送更直接的心意。\n"
		"你可以试著读它或写些什麽。\n" );
	return 1;
}
int write_msg(string arg)
{
	string msg,item;
	object target;
	if ( !arg || arg=="" || sscanf(arg,"%s on %s",msg,item) != 2) 
	  return notify_fail(
			"要写些什麽呢？ Syntax : write <message> on <flower>.\n" );
	target = present(item, this_player());
	if(!target)
		return notify_fail("你没有这种花....。\n");
	
	if ((string)target->query("message") != "BLANK")
          return notify_fail(
			"这张卡片上已经写上字了，嗯 !! 擦不掉 !! 换一张吧 !!\n" );
	target->set("message",msg);
	write("你在"+(string)target->query("c_cap_name")+"的卡片上写道："+msg+"\n" );
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"背对著你，在"+get_c_sex(this_player())+"花卡上涂涂抹抹。\n",
		this_player() );
	
	return 1;
}

int read_msg(string arg)
{
	string msg;
	object target;
        if ( !arg || arg=="")
          return notify_fail(
			"要读什麽呢？ Syntax : read <flower>\n" );
        target = present(arg, this_player());
        if(!target)
                return notify_fail("你没有这种花....。\n");

	msg=target->query("message");
        if ( !msg || msg=="BLANK" )
          return notify_fail(
		(string)target->query("c_cap_name")+"上系著一张空白卡片，上面什麽都没写。\n" );

	write(target->query("c_cap_name")+"的卡片上写著 ： "+msg+"\n" );
        tell_room( environment(this_player()), 
		this_player()->query("c_name")+"背对著你，专心的读著"+get_c_sex(this_player())+"花卡。\n",
                this_player() );
	return 1;
}
int smell_me(string arg)
{
	string msg,c_msg;
        object target;
        if ( !arg || arg=="")
          return notify_fail(
		"要闻什麽呢？ Syntax : smell <flower>\n" );
        target = present(arg, this_player());
        if(!target)
                return notify_fail("你没有这种花....。\n");

        c_msg=target->query("c_smell");
	msg  =target->query("smell");
	write("你把你的"+target->query("c_cap_name")+"凑近鼻端，"+c_msg+"\n" );
        tell_room( environment(this_player()), 
		this_player()->query("c_name")+"轻轻的闻著"+get_c_sex(this_player())+target->query("c_cap_name")+"。\n",
                this_player() );

	if (random(20)==10 && !bee_out)
	{
	write("突然一只蜜蜂从花里飞出来，在你的鼻子上螫了一下，哇 !! 好痛 !! 鼻子肿起来了 !!\n" );
	this_player()->receive_damage(5);
       (CONDITION_PREFIX + "simple_poison")->apply_effect( this_player(), 5, 3 );
        tell_room( environment(this_player()), 
		"突然，一只蜜蜂从"+this_player()->query("c_name")+"的花里飞出来，在"+get_c_sex(this_player())+"鼻子上螫了一下，"+get_c_sex(this_player())+"鼻子马上肿了起来 !! \n",
                this_player() );
		bee_out=1;
	}
        return 1;
}
