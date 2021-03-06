#include "../ekravia.h"
inherit OBJECT;

int		charge;
int		use_card();

void	create()
{
//	::create();
	set_name("silver card");
	set_short("银卡");
	set( "long", "@@long_desc");
	add( "id", ({"card", "silver card"}) );
	set( "weight", 0);
	set( "unit", "张");
	set( "value", 0);
	set( "no_drop", 1);
	charge = 10;
}

string	long_desc()
{
	string	s;
	s = sprintf("%s\n%s%s%s\n", "这是一张银色的卡片, 上面印著迪诺旅店的标志",
			 "这张银卡还可以使用", chinese_number(charge), "次。" );
	return s;
}

/*
使用卡片进入房间时被呼叫, 如果卡上还有 charge 的话则传回 1,
否则传回 0。
*/
int		use_card()
{
	if (--charge > 0)	return 1;
	call_out( "remove_card", 5, this_player(),this_object() );
	if (charge == 0)	return 1;
	return 0;
}

void	remove_card( object player, object this_ob)
{
	tell_object(player, "银卡的次数已经用完了。\n");
	this_ob->remove();
}
