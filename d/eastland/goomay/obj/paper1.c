
#include "mudlib.h"
inherit OBJECT;
void create()
{
set_name("broken cloth","发黄的破布片");
add ("id", ({"cloth",}) );
set_short("a broken cloth","发黄的破布片");
set("long",@PAPER
这是一片已经发黄的破布片，上面用黑色的液体--好像是乾掉的血--写著密密麻麻
的文字.\或\许\你可以试著去读(read)它.
PAPER
);
set("no_sale",1);
set( "unit", "片");
set("weight", 5);
set("value", ({ 1, "silver" }));
}
void init()
{
	add_action("read_letter","read");
}

int read_letter(string str)
{
    object ob1,room_1;
    if (!str ||str!="cloth") return 0;
    else {
      ob1=environment(this_object());
      if (ob1!=this_player())
        return 0;
      else
        {
          write(
@C_MSG
警告我段家的後代子孙 ：

　　拣到这片血书的人啊 !! 请你转告住在古梅镇的段氏家族，在还没有
找到克制矿坑西南方地底的魔法阵之前，务必停止该区域的矿坑挖掘，以
免挖出我们无法预测的物体。

    我是段千钧，段家的第六代传人，在段家矿场遭遇奇怪的生物攻击後，
我和我的魔法师朋友－君莫愁一起进入事故的矿区堪察，我们发现该处有奇
特的六角形魔法阵，但在试著解开它时，启动了它的强大威力，魔法阵爆炸
解体的同时，我被震波抛入矿坑深处，巨石压住了我下半身，眼看著汨汨的
鲜血涌出，我却一点也不能感觉疼痛，我知道我完了，所以我沾了我的血，
希望能留下些什麽 ...

    後世的人，就让这个可怕的区域永远封住吧 !! 不要再来打扰这个地底
的封印了，这一定是神所留下的，不要违背了神的旨意。

    还有，我曾经把火焰的妖精封印在冶铁的火炉炉底，它会吸收火焰的精
华慢慢的成长，并将在适当的时候在极阴之物的帮助下转化成火焰的精灵，
千万不要伤了它，要努力的保护它，因为它是段家锻造魔法武器的魔法泉源
，千万不要让祖先的期望和心血白费。

    君莫愁 ... 我的朋友 ... 你还好吗？我对起你 ....

     -------------------------------------------------

    血书能看得出来的到这里，下面都烂掉了，只隐约有些奇怪的图案
C_MSG
              );
          return 1;
}
}
}
