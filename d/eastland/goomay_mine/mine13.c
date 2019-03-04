
#include <zeus.h>

inherit ROOM;

void create()
{
	::create();
	set_short("水流上游");
	set_long(@CLong
这是一个不大的地方，有一点像小型的港口，想必又是一个运送货物的
地点，铁轨到了这儿又是一个终点．这里似乎弥漫著一股血腥的气息，一阵
阵肃杀的气氛令人不寒而栗，南方是一条湍急的水流(river) ，如果想通过
它，没有十分高超的游泳技术是不行的．
CLong
);
set("item_desc",(["river":
"这是一条流速非常快的河流，河对面不知是什麽地方，也许\可以过去看看．．\n"
	]) ); 

set("exits",([ "north":ZROOM"/mine12"
	]));

reset();
}
void init()
{
add_action("do_pass","pass");
}
int do_pass(string str){
 	int skills;
	skills = (int)this_player()->query_skill("swimming");
	if(!str||str!="river"){
	write("你想通过什麽?\n");
	return 1;
		}
	if ( random(skills) < 40 && skills < 40){
	write("\n你很想游过去，但是很不幸的被水给冲走了．．．\n");
	tell_room(environment(this_player()),(
	"你看到"+this_player()->query("c_name")+"很帅气的跳进水中，不过却边游边喊救命！\n")
	,this_player());
	this_player()->move_player(ZROOM"/port.c","SNEAK");
	return 1;
	}
	if (random(skills) < 40  && skills >40 ){
	write("\n你很努力的往前游，但是被水给冲回来了．．．\n");
	tell_room(environment(this_player()),(
	"你看到"+this_player()->query("c_name")+"以一种可笑的姿势，慢慢的游了回来．\n")
	,this_player() 
	              );
	return 1;
	}
	write("你凭藉著高超的泳技，克服汹涌的浪涛抵达彼岸！！\n");
	tell_room(environment(this_player()),(
	"你看到"+this_player()->query("c_name")+"很辛苦地游到了对岸！！\n")
	,this_player());
	this_player()->move_player(ZROOM"/store_room.c","SNEAK");
	return 1;
}