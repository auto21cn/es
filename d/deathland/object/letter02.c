// Echo/item/letter01.c
#include "../echobomber.h"
inherit OBJECT;
void create()
{
set_name("scroll","羊皮卷轴");
set_short("a scroll","羊皮卷轴");
set("c_long",@LONG_D
一张沾满著泥土的卷轴,上面写著密密麻麻的文字.\或\许\你可以试著去读(read)它.
LONG_D
);
set("no_sale",1);
set( "unit", "张");
set("weight", 5);
set("value", ({ 5, "silver" }));
}
void init()
{
add_action("read_letter","read");
}

int read_letter(string str)
{
    object ob1,room_1;
    if (!id(str)) return 0;
    else {
      ob1=environment(this_object());
      if (ob1!=this_player()) 
        return 0;
      else 
        {
          write(
          "当我向宏都拉斯借得运矿车後, 终於撞破了那堆乱石, 来到了那个\n"
          "被封印以久的邪恶神官的墓穴. 然而一道门却挡住了我的路, 我必\n"
          "须去寻找这门的钥匙..........\n"
          "不知这是幸运呢还是不幸, 我实在没有什麽把握在邪恶神官奥根的\n"
          "墓穴中会有什麽奇怪的诅咒.\n"
          "                ------矮人探险家英蒙得\n"
          );
          return 1;      
        }
    }
}
