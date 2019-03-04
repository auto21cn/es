// File: /d/eastland/haiwei/temple1.c

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("道观");
        set_long( @C_LONG_DESCRIPTION
这是一间道观，其上供奉的是真武大帝，虽然不太大，但是十分乾净，左侧
有一个香炉，现今有几许\轻烟袅袅，看来此间道观的信徒不少，右侧有一个大箱
子(box)。
C_LONG_DESCRIPTION
        );
    set("objects",([
        "toaist":"/d/eastland/haiwei/monster/toaist"]));
        set( "light", 1 );
        set( "item_desc", ([ 
                "box" : "这是一个供俸箱\n"]) );
        set( "exits", ([ 
                "west" : "/d/eastland/haiwei/temple_square" ]) );
        reset();
}


void init()
{
        add_action( "do_put", "put" );
}

int do_put(string arg)
{
        string type;
        int num;
        object ob1;

        if( !arg || arg=="" || sscanf( arg, "%d %s",num, type)!=2 )
                return notify_fail( can_read_chinese()?
                        "放什麽？\n": "Put whom what?\n" );
        if( !this_player()->debit(type, num) ) return notify_fail( can_read_chinese()?
                "你没有那麽多钱。\n": "You don't have that many coins.\n" );
    if (present("toaist",this_object())){
       this_player()->credit(type,-num);
       write(can_read_chinese()?
          "老道说：既然你已表达你的诚意，就给你一张收妖符吧。\n":
          "\n");
       ob1=new("/d/eastland/haiwei/obj/paper");
       ob1->move(this_object());
       return 0; 
      }  
}       
