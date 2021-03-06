#include "hawk.h"

inherit ROOM;
int be_move;
void create()
{
        ::create();
        set_short("绝壁");
        set_long(@LONG
你延著小路踩著碎石来到了这块光秃秃的石地上。东边有块颜色深褐的
怪石(rock)，兀立在旁跟其他的岩块看起来很不搭调，北边及南边的杂
草丛生，环绕著陡峭的绝壁而生(precipice) ，远风吹来阵阵的山岚，
可是你感觉到的不是清爽，而是一股不寒而栗。不知哪儿传来细微的人
声兽语，可是你仔细的环顾四周都没有发现生物的踪迹。在这种可怕的
地方，如果你乱走的话，可能会失足落崖。
LONG
);

        set_outside("noden");
        set("c_item_desc",([
                "rock":"@@to_rock",
                "lever":"@@to_lever",
                "precipice":" 深不见底的峭壁, 要是一个不小心摔下去, 大概小命就没了。\n"
                                ]) );

        set("search_desc",([
                "rock":"@@to_search_rock",
                        ]) );
        set("exits",([
                "southwest" : HAWK"room1-1"
                        ]) );
        reset();
}

void init()
{
        add_action("to_move","move");
        add_action("to_pull","pull");
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southwest" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(70);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "从高耸的绝壁上摔下来!\n"+
                "竟然没死! 真是命大啊!\n",this_player());
        return 1;
}

int to_pull(string str)
{
        if ((!str) ||(str!="lever") || (be_move<2) )
        return notify_fail("要拉面回家去拉啦!\n");
        tell_object(this_player(),
                "你用力的拉下扳杆..."+
                "忽然你脚下的石板震动起来......\n\n\n ”匡啷！！”\n"+
                "你整个人被石板弹到一个新的地方.....\n" );
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name") +
                "被石板弹到空中去了!\n",this_player());
        this_player()->move_player(HAWK"room1-3","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "像只鸟儿似的从天而降!\n",this_player());
        return 1;
}

int to_move(string str)
{
        if ((!str) || (str !="rock" )) return notify_fail("你要移动什麽呀?\n");
        if (be_move==0)
        {
                tell_object(this_player(),
                        "你使尽吃奶的力气就是推不动石块。\n");
                tell_room(environment(this_player()),
                        "你看到"+(string)this_player()->query("c_name")+
                        "使尽吃奶的力气在移动石头，"+
                        "但是石块纹风不动。\n",this_player());
        }
        else
        {
                be_move=2;
                tell_object(this_player(),
                        "你非常用力的推挤石头....\n\n\n"+
                        "终於把石头搬开了几公分之宽....石头後面似乎还有什麽秘密...\n"+
                        "你伸手到石头後面挖呀挖的, 竟发现有个拉杆(lever)! \n");
                tell_room(environment(this_player()),
                        "你看到"+(string)this_player()->query("c_name")+
                        "奋力的把石块推开了一点距离。\n",this_player() );}
        return 1;
}

string to_search_rock()
{
        if ((be_move==0) || (be_move==1))
        {
                be_move=1;
                return "当你仔细的检察这块石头时, 细心的你发现石块有点松动。\n"
                "也许可以尝试去移动(move)看看。\n";
        }
        else
        {
        return "一个被移动过的石头, 後面有个拉杆(lever)\n" ;
        }
}

string to_rock()
{
        if ( (be_move==0)||(be_move==1) )
                return "一块颜色诡异的巨石,不知为何会出现在这里。\n";
                return  "一块被移动过的巨石,石头後面有支拉杆(lever)。\n";
}

string to_lever()
{
        if ((be_move<2) ) return "这里没有这样东西。\n";
        return "这个拉杆看来可以拉动(pull), 不知道会有什麽结果。\n";
}
void reset()
{
        ::reset();
        be_move=0;
}
