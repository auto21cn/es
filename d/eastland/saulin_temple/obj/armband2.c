#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("emporer armband", "御赐臂环");
    add( "id", ({"armband", }) );
    set_short("御赐臂环");
    set_long(@C_LONG
臂环一般是头陀使用的防具, 现在一些僧侣也使用臂环以增加防御能力了。
御赐臂环是昔日少林武僧帮助李世民夺得天下时, 皇上御赐表彰的圣物... 
流传迄今, 所有少林武僧皆以配挂它为荣。
C_LONG
              );
    set( "unit", "个");
    set( "type", "arms" );
    set( "armor_class", 4 );
	set("material","stone");
    set( "defense_bonus", 4 );
    set( "weight", 30 );
    set( "value", ({ 150, "gold" }) );
}
