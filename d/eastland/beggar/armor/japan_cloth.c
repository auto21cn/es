#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("black cloth","黑色紧身衣");
        add("id",({"cloth"}) );
        set_short("黑色紧身衣");
	set_long(@C_LONG
这是一件黑色的衣服,虽然穿起来很紧, 却有利於行动。尤其是对於某些特殊的行
业,行动能更敏捷往往是玫胜的因素。 
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","thief");
	set( "armor_class", 15 );
	set("special_defense",
	     (["evil":15,"divine":-20]) );
	set( "value", ({ 1480, "silver" }) );
}
