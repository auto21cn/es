#include <mudlib.h>

inherit MONSTER ;

void create()
{
        ::create();
        set_level(1);
        set_name("rat","老鼠");
        add( "id", ({ "rat" }) );
        set_short("老鼠");
        set_long("这是一只又脏又小的老鼠。\n");
        set("unit", "只");
        set_perm_stat("dex", 3);
        set_perm_stat("int", 2);
        set_perm_stat("kar", 2);
        set_c_verbs( ({ "%s张嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set_c_limbs( ({ "头部", "身体", "前爪", "後腿", "尾巴" }) );
}
