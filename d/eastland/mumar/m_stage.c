#include <mumar.h>
inherit ROOM;
 
int ent;
void create()
{
        ::create();
  set_short("镜中的收藏室");
  set_long( @CLong
进入镜内，你看不见原本应该反映在镜中的珠宝、瓷器、珍奇古玩。镜外那个奢
华的房间在这儿竟是家徒四壁，就好像刚被强盗洗劫过一样，除了一面破旧而不起眼
的镜子外只有一些空箱子、空架子了。
CLong
);
set("light",1);
set("c_item_desc",([
    "mirror":"@@to_mirror"
     ]) );
 
set("exits",([
               "down":MUMAR"m_square"
             ]));
}
 
void init()
{
    add_action("to_touch","touch");
    if(this_player()) this_player()->set_explore("eastland#25");
}
 
int to_touch(string arg)
{
   if( !arg || arg != "mirror" ) return 0;
   else  {
        write("在你摸著镜子的同时，你感到一股强大的吸引力把你拉进了镜内。\n");
        this_player()->move_player(MUMAR"stage07",({
        "",this_player()->query("c_short")+"被吸入了镜子\n。",
        "",this_player()->query("c_short")+"进入了这个世界。\n",
        }),"");
        }
   return 1;
}
 
string to_mirror()
{
   return "这面镜子闪耀著一种奇异的光芒，深深地吸引著你去摸它。\n";
}
