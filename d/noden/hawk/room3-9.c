
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("鸟人祭坛");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
这里是鸟人族最重要的圣地，高高的矗立在天空之城的最顶点。你往下
一望，只看到无穷无尽的绿色薄雾，虚无飘缈的感觉让你不禁有点脚软。
LONG_DESCRIPTION
        );
        set( "jumped",0);
        set( "exits", ([
                "northwest" : HAWK"room3-7",
                     ]) );
        set( "objects",([
                "prayer" : MOB"god1" ]) );
	reset();
}//end of creat

void init()
{
        add_action("to_jump","jump");
}

int to_jump()
{
	int alig,lev;
        lev = (int)this_player()->query_level();
        alig = (int)this_player()->query("alignment");

	if (!present("valor amulet",this_player() ))
        {
                tell_object(this_player(),@LONG
一阵带有浓厚血腥味的大风从祭坛边吹起，顿时让你打消了往下跳的念头。
LONG
                );
                return 1;
        }

        if (lev < 17)
        {
                tell_object(this_player(),
                        "年纪轻轻不要太冲动，乖，不要乱跳嘛。\n" );
                return 1;
        }

	if (alig > 0)
	{
		this_player()->move_player(HAWK"square1","SNEAK");
		return 1;
	}
        else
        {
                this_player()->receive_damage(70);
                this_player()->move_player(HAWK"room1-18","SNEAK");
                return 1;
        }
        return 1;
}
