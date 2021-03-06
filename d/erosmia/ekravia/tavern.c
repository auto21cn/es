#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("迪诺旅店");
	set_long(
@CLong
你走进一家旅店, 迎面映入眼帘的是一张古旧的樟木柜台 (counter)
。一本厚厚的登记簿 (register) 被放在柜台上, 一张张的书页由外面进
来的阵阵大风翻阅\著。一张简单的说明 (note) 被贴在柜台旁的一角, 上
面写著一些关於住宿的说明。
    柜台的右侧後方有一道木门, 周围的石墙上面挂著几个野兽的头, 彷
佛诉说著旅馆主人当年勇敢的事迹。左右两侧各有一个回廊, 左边的回廊
不时有些喧闹声传来, 右边的回廊则充满著一股宁静的气息。
CLong
);

	set("c_item_desc", ([
		"counter"	: @ITEM_COUNTER
这个柜台由厚实的樟木所组成, 上面没有任何的雕饰, 给人一种稳重的感
觉。细看木头表面的颜色, 你发觉这个不起眼的柜台可能已经有上百年之
久的历史。
ITEM_COUNTER
		, "register"	: @ITEM_REGISTER
一本封皮已经相当古旧的册子, 不过内页是可换的, 整本册子实在是厚重
得可以。上面应该写著一些住宿的资料, 不过字迹潦草, 难以确认。
ITEM_REGISTER
		, "note"	: @ITEM_NOTE
我想你应该走近一点, 然後仔细读读 (read) 它。
ITEM_NOTE
		]) );

	set("exits", ([
		"east"		: HERE"maple_street3",
		"south"		: HERE"corridor1",
		"north"		: HERE"corridor2",
		]));
		
	set( "objects", ([
		"keeper"	: MOB"innkeeper"
	]) );
	reset();
}

void	init()
{
	::init();
	add_action( "read_note", "read");
	add_action( "do_sign", "sign");
	add_action( "do_buy", "buy");
}

int	read_note(string s)
{
	if (!s)	return 0;
	if (s=lower_case(s) != "note")	return 0;
	write( @NOTE_MSG
□住宿须知□
    如果你想住宿的话, 你必须在登记簿上签下你的名字 (sign name on 
register)。 我会收走你的钱并给你一把钥匙, 往北走上楼就可以走到你
的房间。在房间里你可以休息 (rest) 或是睡觉(sleep) 以恢复体力, 觉
得休息够了, 就离开房间, 否则别怪我动手把你撵出去。
    我们一晚的价格是 200 个银币, 另外还有优惠的银卡出售, 3200 个
银币一张。如果你需要的话, 直接跟我买。 (buy silver card)
                                                        §迪诺§
NOTE_MSG
	);
	return 1;
}

int	do_buy(string s)
{
	if (!s)	return 0;
	switch (lower_case(s)) {
		case "silver card"	:
			if (!this_player()->debit( "silver", 3200))	
				return notify_fail( "你掏掏口袋, 发现钱不够\n");
			clone_object(OBJ"silver_card")->move(this_player());
			printf("%s", "老板收下钱, 给你一张银色的卡片。\n");
			return 1;
		default	:
			return 0;
	}
}

int	do_sign(string s)
{
	if (!s)	return 0;
	switch (lower_case(s)) {
		case "name on register"	:
			if (!this_player()->debit( "silver", 200))	
				return notify_fail( "你掏掏口袋, 发现钱不够\n");
			clone_object(OBJ"tavern_key")->move(this_player());
			printf("%s", "老板收下钱, 给你一把小钥匙。\n");
			return 1;
		default	:
			return 0;
	}
}
