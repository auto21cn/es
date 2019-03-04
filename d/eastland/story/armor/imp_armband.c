inherit ARMOR;
void create()
{
     set_name( "fighter's armband","战士□臂环" );
     add( "id",({ "armband" }) );
     set_short( "战士□臂环" );
     set_long(@C_LONG
一双由「羽民族大首领  羽后」用天然矿石制成的臂环，上面再加以防雷电咒语，
同时在臂环内侧还有缝有丝质布料，穿戴起来非常舒适。
C_LONG
     );
     set( "unit","双" );
     set( "weight",30 );
     set( "type","arms" );
     set( "material","element" );
     set( "armor_class",3 );
     set( "defense_bonus",4 );
     set( "value",({ 720,"silver" }) );
     set("special_defense",
        (["energy":-20,"electric":20]) );
}