// File: /d/eastland/easta/bank.c
// Generated by Roommaker Thu Jan 27 10:10:43 1994

#include <goomay.h>

inherit "/std/bank";
inherit "/std/exchange";
inherit ROOM;

void create()
{
	exchange::create();
	room::create();
	set_short("金蟾钱庄");
	set_long( @LONG_DESCRIPTION
这里是一家颇负盛名的钱庄，老板是若岚城鼎鼎大名的张大财主，这家钱庄的
业务不但遍布东方大国，连诺达尼亚和莫尔斯等地的银行都有往来，如果你在远风
镇或默拉迪亚的银行有帐户的话，也可以在这里存提款，或者是在这里开户(open)
，只要 25 枚金币就可以将你的钱寄放在钱庄里。钱庄里除了存提款，也提供钱币
的兑换服务，你可以用 convert 指令兑换身上的钱币。
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"east" : Goomay"col22" ]) );
	reset();
}

void init()
{
	bank::init();
	exchange::init();
}
