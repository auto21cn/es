#include <mudlib.h>
#include <ansi.h>
inherit MONSTER ;

void create()
{
        ::create();
        set_level(1);
        set_name("richman",""+HIB"富人"+NOR"");
        add( "id", ({ "rat" }) );
        set_short(""+HIB"富人"+NOR"");
        set_long(""+HIR"波士的老大，很刻薄。"+NOR"\n");
        set("unit", "只");
        set_perm_stat("int", 1);
        set ("wealth", ([ "gold": 30000 ]) );
    equip_armor( "/d/mage/tower/armors/wizard_amulet" );
}
