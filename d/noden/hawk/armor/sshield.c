inherit ARMOR;

void create()
{
        set_name("sky shield","天界之盾");
        add("id",({"shield"}) );
        set_long(@LONG
这把盾牌外形非常怪异，像一只猛虎作势要扑向敌人一样，看来拿这把
盾牌不但可以充当防具，还有吓唬敌人的效果唷。
LONG
        );
        set_short( "sky plate","天界之盾");
        set( "no_sale",1);
        set( "unit", "把" );
        set( "weight", 100 );
        set( "type", "shield" );
        set( "armor_class", 6 );
        set("material","light_metal");
        set( "defense_bonus", 6 );
        set( "value", ({ 720, "silver" }) );
}
