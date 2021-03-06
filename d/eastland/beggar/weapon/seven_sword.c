#include <mudlib.h>

#define INT(x)  (int)x->query_perm_stat("int")
#define ALI(x)  (int)x->query("alignment")
#define NAME(x) (string)x->query("c_name")
inherit WEAPON;

void create()
{
    set_name( "seven-star shortsword","名刀 七星剑" );
    add("id",({"shortsword"}) );
    set_short( "名刀 七星剑" );
    set_long(@C_LONG
七星剑的剑身镶有七颗七彩宝石,分别照著北斗七星的方式排列。七星剑原本是上
古神兵利器, 但随著三国时代『董卓』的灭亡而消失了好一阵子, 直到『明太祖』
挖掘『赵王陵』时又重现了出来。相传七星剑一出, 就会带来给人类一场大浩劫,
『董卓』乱政就是一个最好的例子。
C_LONG
            );
    set("unit","柄");
    setup_weapon("shortblade",30,15,20);
    set("weight",30);
    set( "bleeding", 10 );
    set("value",({2400,"silver"}) );
    set( "wield_func","wield_shortsword");
    set( "unwield_func","unwield_shortsword");
    set_c_verbs( ({ "手持%s暗捏剑诀,使出了一式『白虹贯日』快速地刺向%s",
                    "用%s刷刷刷连三剑,飞快地砍向%s",
                    "和%s身剑合一,一道人影电射向%s",
                    "把%s对准%s一丢,然後又捡了回来",
                  }) );   
}
