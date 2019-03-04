inherit ARMOR;
void create()
{
     set_name( "lock armband","乱环环" );
     add( "id",({ "armband" }) );
     set_short( "乱环环" );
     set_long(@C_LONG
乱环环原是用来锁住那些罪大恶极的人，一旦被套上，决无挣脱之理，永远受其锢
制，并且全身遭受火焰一般的痛楚。
C_LONG
     );
     set( "unit","双" );
     set( "weight",100 );
     set( "type","arms" );
     set( "material","heavy_metal" );
     set( "armor_class",3 );
     set( "defense_bonus",3 );
     set( "value",({ 2320,"silver" }) );
     set( "equip_func","equip_ring");
     set( "unequip_func","unequip_ring" );
}
void init()
{
    add_action("do_remove","remove");
}
int do_remove(string arg)
{
    object player,armband;
    player=this_player();
    if ( (!armband=present(arg,player)) || 
         (!armband->query("equipped"))||(armband!=this_object()) )
    return 0;     
    if ( player->query("alignment") > 0 )
    return 0;
    write("\n乱环环紧紧扣住你的双手，令你无法挣脱！\n\n");
    return 1;
}
int equip_ring()
{
     if ( this_player()->query("alignment") > 0 ) return 1;
     write("\n\n乱环环忽然像个火炭一般，灼痛了你的双手！\n\n\n\n");
     this_player()->add("hit_points",-100);
     set("armor_class",1);
     set("defense_bonus",1);
     return 1;    
}
int unequip_ring()
{
     set("armor_class",3);
     set("defense_bonus",3);
     return 1;
}