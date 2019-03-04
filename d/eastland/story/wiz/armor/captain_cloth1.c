inherit ARMOR;
void create()
{
     set_name( "captain's cloth","长袖对襟棉袍" );
     add( "id",({ "cloth" }) );
     set_short( "长袖对襟棉袍" );
     set_long(@C_LONG
以棉布制成的一件乌黑色棉袍，它的重量非常的轻，适合那些行动敏捷的人所穿。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "defense_bonus",5 );
     set( "value",({ 2000,"silver" }) );
     set("special_defense",
        (["evil":-20]) );
}
