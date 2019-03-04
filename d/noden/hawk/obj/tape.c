// Created by Smore@EasternStory --> modified from Aqurius's tape ... :)
#include <mudlib.h>
inherit OBJECT;

void create()
{
        seteuid(getuid());
        set_name("scotch tape","测试用");
        add("id",({"tape"}));
        set("short","@@query_short");
        set("invisible",1);
        set( "unit", "卷");
        set("weight",0);
}

void init()
{
        add_action("do_tear","tear");
        add_action("do_say","say");
        add_action("do_say","shout");
        add_action("do_cast","cast");
        add_action("do_say","whisper");
        add_action("do_say","knight");
        add_action("do_say","monk");
        add_action("do_say","scholar");
        add_action("do_say","adv");
        add_action("do_say","mage");
        add_action("do_say","healer");
        add_action("do_say","tell");
        add_action("do_say","es");
        add_action("do_say","chat");
        add_action("do_say","songin");
        call_out("do_ok",240,this_player() );
}

int do_ok()
{
        tell_object(this_player(),
                "你终於觉得喉咙舒服点了，应该可以说话了。\n");
        this_object()->remove();
        return 1;
}


int do_say(string arg)
{
        write("你的喉咙受了重伤，还是多休息少说话吧。\n");
        return 1;
}
