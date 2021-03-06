#include "../island.h"
#include <money.h>

inherit SHOP;

void create()
{
    ::create();
    set_short("德记古玩行");
    set_long(@LONG
这是谪仙岛中唯一的古玩行，墙上挂的横匾写著「大小通吃」四个大
字，室内装潢非金即银，十足的不可一世，彷佛天底下有价值的古玩均已
尽入其内似的。这儿的老板有个嗜好，喜欢收集一些零零总总的器具，瞧
上眼的便收起来自己珍藏；为了能有更多的机会见识到各种器具，便开了
这家古玩行以招揽顾客。在柜台上方还有一副对联(words)。
LONG
            );
    set("light",1);
    set("item_desc",(["words":@LONG
    
                 【 你 得 认 命 】
             【                     【 
             你                     是
             不                     你
             来                     的
             他                     是
             不                     他
             来                     的
             自                     都
             有                     是
             人                     我
             来                     的 
             】                     】
LONG
          ])); 
    set("exits",(["north":ITOWN"town08"]) );
    storeroom()->set("objects",([
               "torch":"/obj/torch",
               "bag":"/obj/bag",
               "bandage":"/obj/bandage"
                ]) );
    set("objects",([
        "trashcan":"/obj/trashcan",
        "keeper":IMON"shopkeeper"
                ]) );
    reset();
    replace_program(SHOP);
}
