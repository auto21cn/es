
#include "../takeda.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(2);
        set_name( "guest","食客" );
        set_short( "食客");
        set("unit","位");
        set("alignment",100);
        set("weight",400);
        set("wealth/gold",2);
        set_long(
           "这是一个慕孙二娘之名而来的食客，他正津津有味的享用著食物...\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        set_c_verbs(({"%s用她的手掌打向%s", "%s用她的舌头向%s舔去" }));
        set("chat_chance", 7);
        set("chat_output",({
          "食客说：听说大演武场上有一个奇怪的黑市商人....\n",
          "食客说：吃遍东方大陆，还是这家的东西最好吃。\n",
          "食客说：听说肥东的厨房脏的要命，难道没有人在打扫(sweep)厨房吗？\n",
          "食客大叫：老板，来两斤牛肉，再多切点小菜。\n",
          "食客满足的拍拍肚子，一副意犹未尽的样子....\n"
        }));
}
