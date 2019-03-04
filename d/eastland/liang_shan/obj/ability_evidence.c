#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "evidence of ability", "武艺证明书" );
	add( "id", ({ "evidence" }) );
	set_short( "evdence of ability", "武艺证明书" );
	set_long(
		".\n",
		"一张烫金的很漂亮的纸，上面写了一些字，或许\你可以\n"
		"读读看上面写些什麽。\n"
	);
	set( "unit", "张" );
	set( "weight", 10 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
void init()
{
//      set("owner",environment(this_object()));
        add_action( "do_read", "read");
}

int do_read(string str)
{
     object owner;
     owner = query("owner");
     if (!str || str != "evidence" )
     return notify_fail(
          "读什麽?\n");
          tell_object( this_player(),"[1;33m上面用很整齐的小楷写著:   \n" 
          "兹证明"+owner->query("c_name")+"武艺已达甲种山贼特等甄试标准，\n"
          "请准予参加梁山山贼行列。\n\n"
          "见证人: 神机军师朱武[0m \n");
          return 1;
}
