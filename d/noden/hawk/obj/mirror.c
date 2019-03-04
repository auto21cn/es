
#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("Darkgreen Mirror", "墨绿色的寂思");
seteuid(getuid());
        add( "id", ({ "darkgreen mirror","mirror" }) );
        set_short( "墨绿色的寂思" );
        set("long","这是一面底部墨黑色的镜子，你可以拿来看看(see)自己的尊容唷。\n");
        set( "weight", 3 );
        set( "unit", "面" );
}

void init()
{
        add_action("to_see","see");
}

int to_see(string str)
{
        string gen;
        gen = this_player()->query("gender");
        if (str != "mirror")
                return 0;
        if (gen == "male")
        {
                tell_object(this_player(),@LONG
哇！你在镜子里看到一个大帅哥。
你不禁得意的笑了起来～～～
.....................
LONG
                );
                call_out("m_next",5,this_player());
                return 1;
        }

        if (gen == "female")
        {
                tell_object(this_player(),@LONG
哇～你在镜中看到一个绝世大美女。
你不禁顾影自怜，对著镜子骚首弄姿～～～～
.....................
LONG
                );
                call_out("f_next",5,this_player() );
                return 1;
        }

        if (gen == "neuter")
        {
                tell_object(this_player(),@LONG
镜子忽然碎掉了～～～～

可能是不喜欢你吧....
LONG
                );
                this_object()->remove();
                return 1;
         }
}

void m_next()
{
        tell_object(this_player(),@LONG
你突然发现镜子里的你没有跟你一起笑，反而用血红的双眼瞪著你～～～
你受不了这个惊吓，两眼一翻腿一蹬就死了。
LONG
                );
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "对著镜子傻笑一番，忽然脸色一变～～～～\n",
                this_player() );
        call_out("die",3,this_player() );
}

void f_next()
{
        tell_object(this_player(),@LONG
你突然发现镜中的你没有和你一起活动，反而用死鱼般的眼死瞪著你～～～
你受不了这个惊吓，晕死在地上。
LONG
                );
        tell_room(environment(this_player()),
                "你看到"+
                (string)this_player()->query("c_name")+
                "对著镜子一阵骚首弄姿，突然满脸惊惧的转过头来，然後就晕死在地上。\n",
                this_player() );
        call_out("die",3,this_player());
}

int die()
{
        object wuchang;
        tell_object(this_player(),@C_LONG

你死了。

你有种奇怪的感觉....轻飘飘的....

你看到你自己毫无力气地躺在地上....。

你看到一个又高又瘦的黑色人影，无声无息地走到你的身边 ....
黑无常说道: 你已经死了，随我赴阴司受审吧。
黑无常将一条又粗又重的铁链往你头上一套，很粗暴地拖著你向前走。
你只见眼前许多云雾像刀一样刮过你的脸，然後出现了一座石桥 ....
C_LONG
        );
        tell_room(environment(this_player()),
                (string)this_player()->query("c_name")+
                "发出一声凄厉的惨叫，跌在地上 ... 死了。\n"+
                "你看到一缕白色的影子从"+
                (string)this_player()->query("c_name")+
                "的尸体中飘起。\n",this_player() );

        call_out("die1",10,this_player() );
	this_player()->move_player("/d/abyss/hell/bridge","SNEAK");
        wuchang=new("/d/abyss/hell/monster/black_wuchang");
        wuchang->move("/d/abyss/hell/bridge");
	this_player()->move_player("/d/abyss/hell/bridge","SNEAK");
        return 1;
}

int die1()
{
        tell_object(this_player(),@C_LONG
黑无常说道: 鬼卒，我带来了一个亡魂，你进去通报一声！
黑无常转头对你说道: 好好在这里呆著，过了奈何桥就是阴间了。
C_LONG
        );
        call_out("die2",10,this_player() );
        return 1;
}

int die2()
{
        tell_object(this_player(),@C_LONG
鬼卒说道: 算你运气好，森罗殿还在整修当中，回阳间去吧！
鬼卒抓起你往云雾中一丢，一阵天旋地转之後，你又见到一片熟悉的景象 ...
你觉得一阵晕眩，感觉自己又回到了熟悉的身体里。
资料备份 ... 完毕。

C_LONG
                );


        this_player()->move_player("/d/noden/farwind/cemetery","SNEAK");
        this_player()->set("hit_points",10);
        this_player()->set("spell_points",1);
        if ( (string) this_player()->query("class") == "monk" )
        {
                this_player()->set("force_points",0 );
        }
        this_object()->remove();
        return 1;
}

