#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("fighter's dagger","战士□匕");
    add("id",({"dagger"}) );
    set_short("战士□匕");
    set_long(@C_LONG
一把由妖精长老用千年精铁经百年不灭□火熔铸而成的武器，呈黑色光泽，断石切
玉削铁如泥，恁地锋利异常。
C_LONG
       );
    set("unit","把");
    setup_weapon( "dagger", 20, 13, 23 );
    set("weight",60);
    set("value",({60,"gold"}));
}
