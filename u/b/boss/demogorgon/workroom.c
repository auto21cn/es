//butterfly's workroom

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        ::create() ;
        set("short", HIG "百花园" NOR);
        set("long", 

"这里是"+BLINK HIM"蝴蝶"NOR"的工作室。你还没有走进花园，花香就
已经扑面而来了。在花园摆放着各种各样正在盛开的鲜
花，花园的正中长着一棵汁液茂盛而你叫不上名字的大
树(tree)。在树下摆放着一对石桌和石凳，石桌上放了
一朵"+HIR"玫瑰花"+NOR"(rose)和一个"+HIW"贺卡"+NOR"(letter)。\n"
  NOR
  );

        set("light",1);
        set("virtual_server",1);
        set("no_cast",1);
        set("no_enhant",1);
 
        set("exits", ([
                "thi" : "/d/thief/hall/thief_guild",
                "mon": "/d/monk/guild/monk_guild",
                "kni": "/d/knight/fortress/knight_guild",
                "mag": "/d/mage/tower/mage_guild",
                "hea": "/d/healer/building/healer_guild",   
                "guild" : "/d/wiz/wiz_hall",
                "sch": "/d/scholar/scholar/scholar_guild",
        ]));
        set( "objects", ([
                "zhu": "/u/b/bfly/butterfly"
        ]) );
 
set("item_desc", ([
                "rose" : HIR "这是一朵情人互赠很普通的红玫瑰花。\n" NOR,
                "letter" : HIG "偷看别人的信不太好吧！\n" NOR,
                "tree" : CYN "不知道你能不能爬(climb)上去。\n" NOR
        ]));

        reset();

}

void init()
{
        add_action( "climb_tree", "climb" );
        add_action( "break_rose", "break" );
        add_action("to_search", "search");
}
int climb_tree( string arg )
{
        if( !arg || arg!="tree" )
                return notify_fail( "爬什麽？\n" );
                
        this_player()->move_player( "/u/b/bfly/tree", "SNEAK" );
 write( "你爬到树上。\n");

        tell_room( this_object(), 
                this_player()->query("c_name") + "爬到树上。\n",
                this_player() );
        return 1;
}
int break_rose( string arg )
{
       object rose;
        rose = new(__DIR__"rose");
        if( !arg || arg!= "rose" )
                return notify_fail( "你想干什么？\n" );
           rose->move(this_player());
  write(              
"你从花园中摘下一朵"+HIR"红玫瑰"NOR"。\n");
       tell_room( this_object(), 
  this_player()->query("c_name") + "从花园中摘下一朵"+HIR"红玫瑰"NOR"。\n",
                this_player() );
        return 1;

}
int to_search(string arg)
{
    object o;

    write("突然你发现在花丛有一个"+HIY"手绢"NOR"！\n");
    o = new("/u/b/bfly/paper");
    o->move(this_object());
    return 1;
}
