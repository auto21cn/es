#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black platemail", "黑色盔甲" );
	add( "id", ({ "plate", "platemail" }) );
	set_short( "黑色盔甲" );
	set_long(@AA
这是一套和黑色护膝不同质料的盔甲，不过它虽然不起眼，却能提供相当不错的防御力。
AA
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 33 );
	set( "equip_func","bonus_up");
	set( "unequip_func","stop_bonus_up");
	set( "weight", 270 );
	set( "value", ({ 2000, "silver" }) );
}
void bonus_up()
{
    object ob;
    if((ob=present("wooden armband",environment(this_object()) ))&&
        (ob->query("equipped"))){
        set( "defense_bonus",6);
        set( "armor_class",35);
        tell_object(environment(this_object()),
"当你穿上黑色盔甲时，发现他和黑木臂环紧紧密合形成一套极棒的战斗服\n"
);
return 0;
}
}
void stop_bonus_up()
{
set( "defense_bonus",0);
set( "armor_class",33 );
}
