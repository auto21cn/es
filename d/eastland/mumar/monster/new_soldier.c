#include <../mumar.h>
inherit "/d/eastland/mumar/mumar_army";
 
void create()
{
        object ob1;
 
        ::create();
        set_level(4);
        set_name( "new soldier", "新兵" );
        add( "id", ({ "soldier","rookie" }) );
        set_short( "新兵" );
        set_long(
                "你看到一个瘦弱但很坚定的新兵，正在操场上战斗教练。\n"
        );
        set( "gender", "male" );
        set( "alignment", 100 );
        set( "wealth/silver", 20 );
        set( "natural_armor_class", 20 );
        set( "natural_defense_bonus", 6 );
        set_perm_stat( "str", 2 );
        set_perm_stat( "dex", 7 );
        set_skill( "dodge", 30 );
 
        ob1 = new( OBJS"wooden_blade" );
        ob1->move(this_object());
        wield_weapon(ob1);
}
