//room1-6.c
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include "mudlib.h"
#include "hawk.h"
inherit ROOM;
int moves;
void create()
{
        ::create();
        set_short("石板小径");
        set_light(1);
        set_long( @LONG_DESCRIPTION
走到这里，远远的你可以看到一座奇型怪状的城，不过让你觉得奇怪的是，
这座城似乎在缓缓的移动著。两旁的森林(forest)被砍伐掉了许多，大概是拿去
作为建设城堡的原料吧。
    你注意路边传来一阵阵的水声，不过你四处望望，还是搞不清楚这声音
是从哪边传来的。
LONG_DESCRIPTION
        );
          set( "exits", ([
                  "southwest" : HAWK"room1-7",
                  "north" : HAWK"room1-5",
                  ]) );
        set("c_item_desc",([
                "forest":"@@to_forest",
                "fountain":"@@to_fountain"
                ]) );
        reset();
}//end of creat

void init()
{
        add_action("do_search","search");
        add_action("to_drink","drink");
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southwest" || str=="north" )
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

string to_forest()
{
        return "整个森林都被砍得光秃秃的，难道这些人都不懂得要水土保持吗？？\n";
}

int to_drink(string s)
{
        if ((s == "fountain") || (s == "water"))
        {
                if (moves == 0)
                {
                        tell_object(this_player(),"What?\n");
                        return 1;
                }

                if (moves == 3)
                {
                        tell_object(this_player(),@LONG
水已经被喝光光了，你不禁开始咒骂哪个讨厌鬼让你没水喝。
LONG
                        );
                        return 1;
                }  

                if ( ( this_player()->query_temp("touch_ball")==1) &&
                        (this_player()->query_temp("drink_water")==0) )
                {
                        tell_object(this_player(),
                        "你把嘴巴靠近这喷水池，努力的开始喝水池里的水。\n");
                        this_player()->set_temp("drink_water",1);
                        (CONDITION_PREFIX + "simple_poison")->
                                apply_effect( this_player(),8, 10 );
                return 1;
                }
                if ( this_player()->query_temp("touch_ball") == 0)
                {
                        tell_object(this_player(),
                        "你喝了几口，就觉得全身不大对劲，眼前一片金星乱冒，"+
                        "而且七孔流血。\n你感到一阵麻痹，一转眼你已经倒在地上"+
                        "爬不起来了。\n");
                        (CONDITION_PREFIX + "simple_poison")->
                                apply_effect( this_player(),8, 10 );
                        (CONDITION_PREFIX + "slow")->
                                apply_effect( this_player(),8, 5 );
                        (CONDITION_PREFIX + "bleeding")->
                                apply_effect( this_player(),8, 8, 10 );
                return 1;
                }

                if (this_player()->query_temp("drink_water") == 1);
                {
                        tell_object(this_player(),
                        "你一口接著一口的把水池里的水给喝完了，周围的人都给"+
                        "了你热烈的掌声。\n不过这种虚荣心的满足还是比不过你身"+
                        "体上的病痛，你觉得还是好好歇会儿比较恰当。\n");
                        (CONDITION_PREFIX + "simple_poison")->
                                apply_effect( this_player(),8, 10 );
                        this_player()->set_temp("drink_water",2);
                        moves = 3;
                return 1;
                }
		
        }
        if ((s != "water") && (s != "fountain"))
        {
                tell_object(this_player(),
                        "What?\n");
                return 1;
        }
}
int do_search(string s)
{
        object obj;
        if (s == "forest")
        {
        	moves = 1;
        	tell_object(this_player(),@LONG
你在森林的深处找到了一条清彻的小溪，原来就是你刚刚听到的水声，
你沿著河流慢慢往上走，看到了一个泛著惨绿色的喷水池(fountain)。
你心里觉得奇怪，不知道这个喷泉池放在这边干嘛。
LONG
		);

		call_out("smell",10,this_player() );
        	return 1;
        	}

        if (s == "fountain")
        {
        switch(moves)
                {
                case 3:
                        tell_object(this_player(),
                                "你在喷水池底长的青苔里找到一张小纸片。\n");
                        obj = new("/u/s/smore/obj/paper.c");
                        obj->move(this_player());
                        moves = 4;
                        return 1;
                case 2:
                        tell_object(this_player(),
                                "你把你的手伸近喷泉....不过那麽恶心"+
                                "的水....你想想还是算了。\n");
                        return 1;
                case 1:
                        tell_object(this_player(),
                                "你觉得没事还是不要找事做比较好！\n");
                        return 1;

                case 0:
                        tell_object(this_player(),
                                "你找了又找，并没有发现任何东西。\n");
                        return 1;
                case 4:
                        tell_object(this_player(),
                                "你找了又找，并没有发现任何东西。\n");
                        return 1;
                }
        }

        if ((s != "fountain") || (s != "forest"))
        {
                tell_object(this_player(),
                        "你找了又找，并没有发现任何东西。\n");
                return 1;
        }
}

string to_fountain()
{
        if (moves == 0)
        {
                return "哪来的喷泉啊？你走晕头了吧....\n";
        }

        if (moves == 1)
        {
                moves = 2;
                return "这是一个年久失修的喷水池，池边长满了青苔，联带著连"+
                       "喷出来的泉水也被染成恶心的绿色，因此看起来似乎深不"+
                       "见底，不晓得里面还会不会有啥恶心的东西放在里面。\n";
        }
        if ((moves == 3) || (moves == 4))
        {
                return "喷水池的水不知道被谁给喝的一乾二净了。\n";
        }
}

int smell()
{
	string name;
	name = (string)this_player()->query("name");
	tell_object(this_player(),
		"你忽然觉得口乾舌燥，可能是到处砍杀过度劳累吧。" );
	if (present(name,this_object() ))
	{
		tell_object(this_player(),@LONG
你看著眼前的泉水....
好像勉强可以喝(drink)....
LONG
		);
		return 1;
	}
	tell_object(this_player(),@LONG
你想到刚刚找到的那个
喷水池(fountain)，觉得虽然恶心，不过喝(drink)一些应该没有大碍。
LONG
	);
	return 1;
}

void reset()
{
        ::reset();
        moves = 0;
}
