#include <mumar.h>
inherit ROOM;
 
int button = 1;
void create()
{
        ::create();
  set_short("牧马关密道");
  set_long( @CLong
这儿是牧马关地面之下的通道。几乎所有军事基地中，都会挖掘四通八达的地下
密道，以做为奇袭或撤退之用。看来这个密道挖掘的时间并不久，所以十分地狭窄而
潮□。东面的土墙上，刻著『牧马关军事重地，擅入者杀无赦』几个大字，下面则挂
了一只告示牌（sign) 。这里静得出奇，除了隧道顶上滴下的水滴声外，只有你的呼
吸声。
CLong
);
  set( "c_item_desc", ([
                "sign" : @LONG_TEXT
一只绿底白字的告示牌，你似乎感觉曾在睡梦中看过类似的东西...上面写著：
　┌——————————————┐
  │字　　号：(83)东字第Ｏ三八号│
　│工程名称：牧马关地下要塞工程│
　│施工单位：牧马关．战斗工兵团│
  │负 责 人：大将军．杨　上　昆│
  │工程说明：极　　　机　　　密│
  │                            │
  │施　工　中 ． 敬　请　期　待│
  └——————————————┘
LONG_TEXT
 ]) );
set("exits",([
               "up": MUMAR "square06" ]));
set( "search_desc", ([ "here" : "@@search_here" ]) );
        reset();
}
 
string search_here()
{
        object obj;
 
        if( !button || present("button", this_object()) ) return
                "你几乎把这儿的地给翻过来了，但没有发现任何东西。\n";
        obj = new( OBJS "button" );
        obj->move( this_object() );
        button = 0;
        this_player()->set_explore("eastland#27");
        return "你在墙角的地方发现一个金光闪闪的小东东。\n";
}
