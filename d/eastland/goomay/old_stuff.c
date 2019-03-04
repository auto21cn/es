// File: /d/eastland/easta/shop.c
// Generated by Roommaker Thu Jan 27 09:58:01 1994

#include <goomay.h>

inherit SHOP;

void create()
{
	::create();
	set_short("集古斋");
	set_long( @LONG_DESCRIPTION
你现在走进了一家阴暗的商店，一块乌木屏风把你的眼光遮住，屏风上
三个金漆大字写著「集古斋」，一个长著两撇鼠须的掌柜走过来向你哈腰作
揖，满脸谄媚的表情。你可以在这里浏览买卖货物，虽然这里是本镇暴发户
钱不多的产业，但是只要你小心一点，还是不会吃亏的。
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"east" : Goomay"col23" ]) );
	set( "objects", ([
		"trashcan" : "/obj/trashcan" ]) );
	storeroom()->set( "objects", ([
		"torch" : "/obj/torch",
		"bandage" : "/obj/bandage",
		"bag" : "/obj/bag"
	]) );
	reset();
        replace_program(SHOP);
}
