#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wonderful hat", "不可思议的帽子" );
	add( "id", ({ "hat", }) );
	set_short( "a wonderful hat", "不可思议的帽子");
	set_long( @LONG
	This hat is used by wizard Rashudi. It is made by magical cloth,
so spreads a strong power of magic.
LONG
    , @C_LONG
	这是魔导士拉修帝戴的不可思议之帽子，不要看它只是用普通的布织成，它可是拥有
出乎你意料之外的防御力，据说还能抵抗各种魔法。
C_LONG
	);
	set( "unit", "顶" );
	set( "weight", 15 );
	set( "type", "head" );
	set( "material", "cloth" );
	set( "armor_class", 10 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "none": 6 ]) );
	set( "extra_skills", ([ "runes": 10 ]) );
	set( "no_sale", 1);
	set( "value", ({ 3000, "silver" }) );
	set( "equip_func", "heal_sp" );
	set( "unequip_func", "stop_heal_sp" );
	set( "extra_look", 
	     "A holy light comes from the wonderful hat which $N wears.\n" );
	set( "c_extra_look", 
	     "$N戴著的帽子中散发出一股不可思议的光芒。\n" );
}

void heal_sp()
{
    object player;
    player = environment(this_object());
    tell_object( player, can_read_chinese(player) ?
      "一股不可思议的光芒从帽子散出并包围著你。\n" :
      "A wonderful light spreates out from hat.\n"
    );
    player->set_temp("sp_heal_apply", ({ 4, -10 }));
}

void stop_heal_sp()
{
    object player;
    player = environment(this_object());
    tell_object( player, can_read_chinese(player) ?
      "你身上不可思议的光芒消失了。\n" :
      "Your wonderful hat has disappeared.\n"
    );
    player->delete_temp("sp_heal_apply");
}
