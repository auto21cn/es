// File: /d/eastland/haiwei/temple.c
// Generated by Roommaker Thu Dec 30 02:04:36 1993

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("镇海将军庙");
        set_long( @C_LONG_DESCRIPTION
你现在正站在镇海将军庙的大殿里，一张朱红色的大供桌上排满了各式鲜花
素果，镇海将军的神像威风凛凛地站在你面前的供桌上，两边的石柱上刻著一副
对联(distich)，北边和南边的圆形拱门通往将军庙旁的回廊，东边敞开的大门
门板上画著两个手执方天画戟的威武将军(lieutenant)，正对庙里的人们瞪视著
。你可以向镇海将军拜拜许\愿(worship)，说不定他会保佑你。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "item_desc", ([ 
                "distich" : "上面写著:\n      风调雨顺、国泰民安\n", 
                "lieutenant" : "这是镇海将军当年打败海盗时的副将，人称「左将军」与「右将军」。\n" ]) );
        set( "exits", ([ 
                "west" : "/d/eastland/haiwei/temple_square" ]) );
        reset();
}
void init()
{
	add_action("do_worship","worship");
}
int do_worship()
{
	tell_object(this_player(),
	"你双手合什，向镇海将军的神像拜拜，默默的祈求 ES 风调雨顺，\n"
	"每一个 ES 的朋友都幸福快乐 !!\n");
	this_player()->save_me();
        this_player()->set_explore("eastland#17");
	"/adm/daemons/backup"->user_backup(this_player());
	return 1;
}
