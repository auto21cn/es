/*
	这个小女孩是 QUEST 的第一个动机
*/
#include "/d/erosmia/ekravia/ekravia.h"
#include <mudlib.h>

inherit MONSTER;
inherit MESSAGE;

int		looked;

void	create()
{
	::create();
	set_level(3);
	set_name( "little girl", "小女孩" );
	add( "id", ({ "girl" }) );
	set_short( "一个小女孩站在墙边, 看著你" );
	set_long(@LONG
你看到一个约十岁左右的小女孩。她穿著白色洋装、头上带著顶红色的
大草帽, 一双睁得大大的眼睛天真无邪地看著你。
LONG
	);
	set( "gender", "female" );
	set( "alignment", 100 );
	set( "no_attack", 1);
	looked = 0;
}

void	init()
{
	add_action( "do_look", "look" );
	::init();
}

int		do_look( string s )
{
	object	target;


	if (!s) return 0;
	target = present(s, environment(this_player()) );
	if ( (!target = present(s, environment(this_player())) ) ||
		(target != this_object()) )	return 0;
		
// 已确定 player 所看的正是这个小女孩, 开始干活了!
	tell_room( environment(this_object()), emote_message_other(
		"$NS将$GS的视线投向小女孩身上。\n", this_player()),
		({ this_player(), this_object() }) );
	tell_object( this_player(), query("long") );
// 小女孩被看到後的动作。
	
	if (looked)	return 1;
	looked = 1;
	call_out( "do_disappear", 5, this_object(), this_player() );
	return 1;
}

void	do_disappear( object me, object player )
{
	if (environment(me) != environment(player)) return;
	
	emote( "$NS张开双手, 带著轻快的笑声跑向$NO身边。然而就在一瞬间,\n" +
		"她如同海市蜃楼般消失了, 只留下阵阵无邪的笑声在空气中回响著...\n",
		me, environment(player), player );
	find_object_or_load( QUEST"girl" )->girl_disappear();
}