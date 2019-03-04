#include "../hawk.h"
inherit MONSTER;
int thank;
void create()
{
        ::create();
        set_level(12);
        set_name( "smith","神秘老铁匠" );
        add("id",({"smith"}) );
        set_short( "神秘老铁匠" );
        set_long(@LONG
一个古怪的老头，在这个打铁铺工作很久了，脸上被火熏的黑黝黝的，强壮的
肌肉大概也是长年的工作所锻练出来的。
LONG
        );
        set( "inquiry", ([
                "god": "@@story",
                "armor" : "@@god_armor"]));
        set( "alignment", 100 );
        set( "gender","male" );
        set( "race","dwarf" );
        set_natural_armor( 30, 22 );
        set_natural_weapon( 25 , 13 , 17 );
        set( "wealth/silver", 20 );
}

void init()
{
        add_action("to_thank","bow");
}

int story()
{
        tell_object(this_player(),@LONG
    老铁匠自言自语道：诸神都在天上享福，凡人受苦受难他们又哪有办法知
道呢？不过如果有人能找齐他们的信物，那麽我也有办法为他打造出一件前所
未见的完美装备(armor)。
LONG
        );
        return 1;
}

int god_armor()
{
        if ((this_player()->query_temp("smore_armor/arcold") == 1)
         && (this_player()->query_temp("smore_armor/elder") == 1)
         && (this_player()->query_temp("smore_armor/las") == 1)
         && (this_player()->query_temp("smore_armor/knight") == 1)
         && (this_player()->query_temp("smore_armor/minister") == 1))
        {
           if (
                (!present("zeus amulet",this_object()))
              ||(!present("spark leggings",this_object()))
              ||(!present("diamond ring",this_object()))
              ||(!present("hades veil",this_object()))
              ||(!present("jupiter armband",this_object()) )
              )
                {
                        tell_object(this_player(),@LONG
老铁匠懒洋洋的说：你不给我材料我哪有办法给你好东西用....笨....
LONG
                        );
                        return 1;
                }
                else
                {
                        tell_object(this_player(),@LONG
老铁匠抬起头，看看你，喃喃的说：
罢了，或许也该是让众人了解诸神的意志的时候了....。
老铁匠深吸一口气，拿起材料，一阵叮叮当当，火焰越来越炽热，只见你
脸上越胀越红，豆珠般大的汗水如潮水般涌出....你受不了高热而晕倒了。
LONG
                        );
                        this_player()->set_temp("block_command",1);
                        call_out("finish",10,this_player() );
                        return 1;
        }
                }
        else
                {
                        tell_object(this_player(),"老铁匠理都不理你。\n");
                        return 1;
                }
        return 1;
}

int finish()
{
        tell_object(this_player(),@LONG

　　过了良久良久，你清醒了过来，看到老铁匠手中拿著一袭精美绝伦的东西
，有著多年战斗经验的你，竟也说不出那是盔甲、盾牌，还是什麽。你只知道
，这件泛著金黄色光挥的防具一定不是人间凡人所能拥有的，或许就是那拿著
神赐之宝保卫人间，传说中的龙战士？
LONG
        );
        this_player()->set_temp("block_command",0);
        call_out("finish2",5,this_player() );
        return 1;
}

int finish2()
{
        tell_object(this_player(),@LONG
　　扯了半天，老铁匠如果不给你你也是没戏唱，看来你得要好好"感谢"他一
下，让他肯把东西交给你。
LONG
        );
        this_player()->set_temp("thank_smith",1);
        return 1;
}

int to_thank(string str)
{
        object obj;
        if (str != "smith" || this_player()->query_temp("thank_smith") != 1)
                return 0;
        tell_object(this_player(),@LONG
　　你必恭必敬的向老铁匠打躬作揖，老铁匠终於还是把这件『诸神的礼
赞』交给了你。
LONG
        );
        obj = new(ARMOR"gift");
        obj -> move(this_object() );
        command("give gift to " + this_player()->query("name") );
        return 1;
}

