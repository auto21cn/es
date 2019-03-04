#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wonderful hat", "����˼���ñ��" );
	add( "id", ({ "hat", }) );
	set_short( "a wonderful hat", "����˼���ñ��");
	set_long( @LONG
	This hat is used by wizard Rashudi. It is made by magical cloth,
so spreads a strong power of magic.
LONG
    , @C_LONG
	����ħ��ʿ���޵۴��Ĳ���˼��֮ñ�ӣ���Ҫ����ֻ������ͨ�Ĳ�֯�ɣ�������ӵ��
����������֮��ķ���������˵���ֿܵ�����ħ����
C_LONG
	);
	set( "unit", "��" );
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
	     "$N������ñ����ɢ����һ�ɲ���˼��Ĺ�â��\n" );
}

void heal_sp()
{
    object player;
    player = environment(this_object());
    tell_object( player, can_read_chinese(player) ?
      "һ�ɲ���˼��Ĺ�â��ñ��ɢ������Χ���㡣\n" :
      "A wonderful light spreates out from hat.\n"
    );
    player->set_temp("sp_heal_apply", ({ 4, -10 }));
}

void stop_heal_sp()
{
    object player;
    player = environment(this_object());
    tell_object( player, can_read_chinese(player) ?
      "�����ϲ���˼��Ĺ�â��ʧ�ˡ�\n" :
      "Your wonderful hat has disappeared.\n"
    );
    player->delete_temp("sp_heal_apply");
}