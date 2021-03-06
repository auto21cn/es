#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level( 3 );
	set_name( "Oregon", "俄勒冈" );
	add( "id", ({ "oregon" }) );
	set_short("俄勒冈" );
	set_long(
		"他是在火山附近探险时被抓的。"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 800 );

	set("max_hp", 200);
	set("hit_points", 200);
	set( "wealth/silver", 40 );
        set_natural_armor( 10, 3 );
}

void give_mark(object me,object ore)
{
  tell_object(me,@LONG
正当你要转身离开时，俄勒冈突然叫住你并说道：『咦，看你应该是书生吧。我被关在
这里的时候，有一晚听到守卫跟科拉克，罗索兄弟喝醉酒时说的话，内容大概是巫师科
拉克的祖先曾经救过一名在若岚皇城偷盗被皇城禁军杀成重伤的大盗，那位大盗送了他
们一本从皇宫内宝库盗出的『剑法秘笈』，可惜他们家族向来只在魔法上有钻研，对剑
术实在是不行，矮灵族也没有什麽人能够锻□，所以一直锁在神殿里没用。或许你可以
去偷出那本秘笈，如果你能学会的话，一定对你很有用处。』   
LONG);
  me->set_temp("known_book_of_sword",1); 
  ore->remove();
  return;
}

int accept_item(object me, object item)
{
    string name;
    object ob1;
        
        name=(string)item->query("name");
        if ( !name || (name!="ohio ring") ) {
          return 0;
        }

	tell_room( environment(),
          "俄勒冈向"+me->query("c_name")+"拜倒，说道: 谢谢你来救我！\n"
	, me );
    tell_object( me, 
        "俄勒冈说：啊! 这是我兄弟的戒指。\n"
        "俄勒冈向你拜倒，说道: 谢谢你来救我，不过我已经挖地道脱险了。\n");
        ob1 = new( OOBJ"oregon_ring" );
        ob1->move(this_object());
        ob1->set(me->query("name"),1);
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)this_player()->query("name")));
        item->remove();
        tell_object(me,"俄勒冈说：：请将这个戒指拿去给俄亥俄，让他知道我已经脱险了。\n        我也该走了，再见 !\n\n");
        command("wave "+lower_case((string)this_player()->query("name")));
        if (me->query("class")=="scholar")
          call_out("give_mark",2,me,this_object());     
        else 
          this_object()->remove();
        return 1;
}
