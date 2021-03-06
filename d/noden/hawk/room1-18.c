#include "hawk.h"

inherit ROOM;

int hole;

void create()
{
        ::create();
        set_short("山谷");
        set_light(1);
        set_long( @LONG_DESCRIPTION
你身处在一个伸手不见五指的阴暗山谷底，周围一片暗茫茫的，头上
的树不停的在滴水，脚下的腐泥也不断的散发出恶心的沼气，四周的蜘蛛
网坚轫的有如尼龙绳，完全封住了你的去路，你看了半天，还是不知道该
怎样离开这个恐怖的地方，或许"Quit"会是你唯一的选择，不想Quit的话
还是赶快在『四周』找找，看看有什麽方法可以离开这个鬼地方。
LONG_DESCRIPTION
);
        set("c_item_desc",([
                "tunnel":"@@to_tunnel"
                        ]) );
        set("objects", ([
                "bug" : MOB"spider"
                        ]) );

    reset();
}//end of creat

void init()
{
	call_out("report",1,this_object() );
        add_action("to_go","go");
        add_action("to_find","search");
        add_action("to_enter","enter");
}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

int to_go()
{
        if ( present("spider",this_object()) )
        {
           tell_object(this_player(),"蜘蛛张牙舞爪著，不让你过去。\n");
           return 1;
        }
        tell_object(this_player(),"这里没有任何出路。\n");
        return 1;
}

string to_tunnel()
{
        if ((this_player()->query_temp("find_hole") == 1) && (hole == 1))
        {
                return "一个阴森潮湿的地洞，你要进去(enter)吗？\n";
        }
        else
        {
                return "你想看什麽？\n";
        }
}

int to_find(string s)
{
        if (present("spider"))
        {
                tell_object(this_player(),
                        "蜘蛛张牙舞爪，你吓得不敢乱动。\n");
                return 1;
        }

        else if (s != "everywhere")
        {
                tell_object(this_player(),
                        "你找了又找，并没有发现任何东西。\n");
                return 1;
        }
        else
        {
                tell_object(this_player(),
                        "你到处找来找去，最後在东北角的大树旁，找到"+
                        "一个小地道(tunnel)。\n");
                this_player()->set_temp("find_hole",1);
                hole = 1;
		this_player()->set_explore("noden#40");
                return 1;
        }
}

int to_enter(string s)
{
	if ((this_player()->query_temp("find_hole") == 1) && (hole == 1) && s == "tunnel")
        {
                tell_room(environment(this_player()),
                "你看到"+this_player()->query("c_name")+
                "像狗一样钻到洞里去了。\n",
                this_player() );
                tell_object(this_player(),
                        "你一头栽进洞里，跑到另一个地方罗。\n");
                this_player()->move_player(HAWK"room1-1","SNEAK");
                return 1;
        }
        tell_object(this_player(),"你想进去那里？诗摩尔的闺房吗？\n");
        return 1;
}

void reset()
{
        ::reset();
        hole = 0;
}
