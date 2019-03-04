#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("Maple Street","枫树大街");
	set_long(@CLong
你走在大街上, 四周人来人往, 相当热闹。街道两旁盖\满了漂亮的两
层式洋房, 楼下开了各式各样的商店。路旁还有许\多小贩叫卖著刚从田里
采来的新鲜蔬菜。
    吟游诗人之家就在大街东边, 两棵美丽的红枫之间。正对面正好是一
家古老的旅店 (tavern), 同时也是镇上最好的酒吧。
CLong
);
	set("exits", ([
		"south"		: HERE"maple_street2",
		"north"		: HERE"maple_street4",
		"west"		: HERE"tavern",
//		"east"		: HERE"bard_guild",
		]));
}
