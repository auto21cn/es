#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        set_level(3);
	set("drink",0);
        set_name( "Traito","雷多" );
        add("id",({"traito"}) );
        set_short( "雷多" );
        set_long(@LONG
你看到一名身材瘦小又小头锐面的男子，不过他可是天空之城当今第一大
红人唷。自从阿道夫当上了鸟人族的领袖，雷多的地位就如火箭升空一般的向
上窜，如今就像个螃蟹一样在鸟人城中横行霸道。
LONG
        );
        set( "inquiry", ([
                "wine" : "@@ask_wine",
                "vito" : "@@ask_vito",
                "plan" : "@@ask_plan",
                ]) );
        set( "alignment", -400 );
        set( "gender","male" );
	set( "max_hp",100 );
	set( "hit_points",99 );
        set( "race","hawkman" );
        set( "no_attack", 1 );
}

void init()
{
        add_action("to_inform","inform");
}

int to_inform()
{
        if (this_player()->query_temp("get_wine") != 2)
        {
                tell_object(this_player(),"雷多说：疑，你真的有找到吗？\n");
                return 1;
        }

        else
        {
                tell_object(this_player(),@LONG
雷多一听到你告诉他酒在哪儿，马上兴冲冲的出门了。
LONG
                );
                this_object()->move("/d/std/rooms/void");
		call_out("come_back",40,this_object() );
                return 1;
        }
        return 1;
}

int come_back()
{
	object obj;
	message("tell_room","你看到雷多摇摇晃晃的从外面走了进来。\n",
		HAWK"traroom",this_object() );
	obj = new(MOB"traitoa.c");
	obj->move(HAWK"traroom");
	this_object()->remove();
	return 1;

}

int ask_wine()
{
	if (!this_object()->query("drink") )
	{
        	tell_object(this_player(),@LONG
雷多说：酒啊，我最喜欢酒了。威士忌啊，白兰地啊，我都满喜欢的。不过
听说东方有一种陈年高粱，味道很好，可惜到现在我都还没喝过，如果人能帮助
我拿到那种酒来喝，我一定会很高兴的。这样吧，你就去帮我找吧，找到以後来
告诉(inform)我酒在哪儿买，我自己去喝，这样好不好啊？
LONG
        );
        	this_player()->set_temp("get_wine",1);
        	return 1;
	}
	else
	{
		tell_object(this_player(),
			"雷多说：酒？....我已经历遍世上所有美酒罗....\n");
		return 1;
	}
}

int ask_vito()
{

        if ((int)this_player()->query_temp("traito") == 1)
        {
                tell_object(this_player(),@LONG
雷多说：嘿嘿，柏妮丝还不死心吗？你去告诉她他的维多早就已经死了
啦！死了这条心吧。成者为王败者为寇，这不是我们每年举办武斗大会推举
领袖的精神吗？不要妄想什麽有人陷害他啦，技不如人就要服输。如果不相
信，可以再去和阿道夫较量较量啊。哈哈哈....
LONG
                );
                this_player()->set_temp("traito",2);
                call_out("look_look",20,this_player());
                return 1;
        }
        else
        {
                tell_object(this_player(),@LONG
雷多说：维多？是谁叫你来问的....？他是我们以前的领袖，不过去年被自己的
弟弟打败，从此就不见人影了，可能是觉得没脸见人吧。
LONG
                );
                return 1;
        }
        return 1;
}

int ask_plan()
{
        if( this_player()->query_temp("smore_box") < 3) return 0;
        tell_object(this_player(),@LONG
雷多面如土色....颤抖的说：
　　天啊～～你都知道了是吗？....没想到....没想到我们多年来的辛苦努力，
全毁在我贪杯误事! 既然事到如今，我就告诉你背後的秘密吧！不过你可要答应
我帮我在长老及众人面前求情啊！

　　事情是这样的....当初阿道夫为了想要夺取比武大赛的冠军，裘拉根就花了三个
月的时间收集各种神奇药草，用肉食兽的唾液作引，所熬出来一瓶通筋活血的秘药，
喝了之後不但如有神助般的力大无穷，而且皮坚如石，也难怪当初神勇如维多也会败
在阿道夫的手下啊! 不过....这个药有个致命弱点，就是阿道夫喝了以後，发现翅膀
肌肉硬化，羽毛也全部骨质化，换句话说，身为鸟人族领袖的阿道夫竟然不会飞呀!!

哈哈哈哈..........哈哈哈哈...............哈哈哈哈...........

雷多仰天狂笑不止，倒地不起，竟然笑死了!!
慢慢地，雷多的尸体冒出一股清烟，一会儿之後，他的尸体竟然气化了!
你觉得应该把雷多的话报告(report)给长老听, 也许可以还维多一个清白!

LONG
        );
        this_player()->set_temp("smore_box",4);
	this_object()->remove();
}

int look_look()
{
        tell_object(this_player(),@LONG
过了一会儿，你突然想到刚刚雷多的眼睛一直在瞄著墙边的一个大铁
箱(box)，不知道在干嘛。
LONG
        );
        this_player()->set_temp("smore_box",1);
        return 1;
}

