#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("platinum tiger finger", "白金指虎");
        add( "id", ({ "ring","finger" }) );
        set_short( "白金指虎" );
        set_long(
@C_LONG
这是一只造型奇特的装饰品，弯曲的白金绕过手腕而扣住你的两指
，上面写了很多奇怪的符号，在扣腕的地方好像刻了一行小小的字
，你可以戴看看。
C_LONG
        );
        set( "unit", "件");
        set( "type", "finger" );
        set( "material", "heavy_metal" );
        set( "defense_bonus", 1 );
   set( "special_defense",([ "fire": 8, "cold" : -5 ]) );
        set( "weight", 20 );
        set( "value", ({ 650, "gold" }) );
        set( "no_sale", 1);
        set( "equip_func","equip_ring" );
        set( "unequip_func","unequip_ring" );
}
int equip_ring()
{
        string bonus;
        bonus=this_player()->query( "knighthood" );
         switch(bonus)
         {
                case "baron":
                        set( "defense_bonus",2 );
                        return 1;
                        break;
                case "vicomte":
                        set( "defense_bonus",4 );
                        return 1;
                        break;
                case "earl":
                        set( "defense_bonus",6 );
                        return 1;
                        break;
                case "marquess":
                        set( "defense_bonus",8 );
                        return 1;
                        break;
                case "duke":
                        set( "defense_bonus",9 );
                        return 1;
                        break;
                case "lord":
                        set( "defense_bonus",10 );
                        return 1;
                        break;
                case "overlord":
                        set( "defense_bonus",10 );
                        return 1;
                        break;
         }
         return 1;
}

int unequip_ring()
{
        set( "defense_bonus",1 );
   return 1;
}
