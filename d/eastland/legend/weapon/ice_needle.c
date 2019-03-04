#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("ice needle","冰魄银针");
    add("id",({"needle","dagger"}) );
    set_short("冰魄银针");
    set_long(@C_LONG
冰魄银针是由千年寒冰制成。银针本身隐隐透出一阵阵的寒气,即使是相隔三尺也
能感受。
C_LONG
       );
    set("unit","把");
    setup_weapon( "dagger",37,19,33);
    set("weight",40);
    set("value",({350,"gold"}));
    set("extra_skills",(["anatomlogy":10]));
}
