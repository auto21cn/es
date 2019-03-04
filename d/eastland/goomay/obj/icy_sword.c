#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "icy sword", "玄冰剑" );
	add( "id", ({ "sword" }) );
	set_short( "an icy sword", "玄冰剑" );
	set_long(
		"You see a shortsword made by ice crystal  .\n",
	"这是一把传说中的奇剑－玄冰剑，通体透明的剑身据说是由万年玄冰\n"+
	"经过自然强风长年吹袭而成，因而能攻敌不备、无坚不摧，不过，传\n"+
	"说玄冰剑会自择其主，如果能得到天时地利人和的配合，会有不可思\n"+
	"议的事情发生。\n"
	);
	set( "unit", "柄" );
	set( "weight", 150 );
	setup_weapon( "shortblade", 30, 15, 30 );
	set( "value", ({ 300, "gold" }) );
        set("no_sale",1);
}
