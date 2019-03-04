#include "../zeus.h"
inherit ARMOR;

void create()
{
        set_name("wooden armband","黑木臂环");
        add( "id", ({ "wooden","armband" }) );
        set_short("wooden armband", "黑木臂环");
        set_long(@CLONG
这是一双由千年铁树树心磨制成的臂环，不知道是什麽缘故使它的
颜色变成了墨黑色，如果和黑色的盔甲搭配的话，刚好浑然一体好
看的不得了
CLONG
);
        set( "unit", "双");
        set( "type", "arms" );
        set( "material", "wood");
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "equip_func","bonus_up");
        set( "unequip_func","stop_bonus_up");
        set( "special_defense",
               ([ "all":4 ]));
        set( "weight", 70 );
        set( "value", ({ 1800, "silver" }) );
}
void bonus_up()
{     object ob;
      if((ob=present("black platemail",environment(this_object()) ))&&
         (ob->query("equipped"))){
         set( "defense_bonus",5);
         set( "armor_class",4);
         tell_object(environment(this_object()),
 "当你穿上黑木臂环时发现它和黑色盔甲紧密结合，形成一套非常合身的装备！\n"
         );
         return 0;
         }
         }
void stop_bonus_up()
 {
 set("defense_bonus",4);
 set("armor_class",3);
 }
