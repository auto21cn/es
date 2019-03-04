
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(18);
        set_name( "Master Fan", "九城名捕－方傲天" );
        add ("id",({ "fan","master"}));
        set_short( "九城名捕－方傲天");
        set("unit","位");
        set_long(
@C_LONG
    他就是名闻天下的「飞鹰」方傲天，也就是当今皇上眼下最红的一位
名捕，在他的手下，不知道破了多少奇案、斩了多少奸恶。听说他一向在
皇帝面前当差，不知道为什麽现在在这里出现，这应该不是偶然吧 !!
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
	set("alignment",1000);
        set_natural_armor( 90, 40 );
        set_natural_weapon( 10, 10, 23 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 30 );
        set_skill( "shortblade", 100 );
        set_skill( "parry", 100 );
        set_skill( "block", 100 );
        set( "hit_points", 900 );
        set( "max_hp", 900 );
        set( "special_defense", ([ "all": 40 ]) );
        set( "wealth/gold", 100 );
        wield_weapon( Obj"icey_sword" );
        equip_armor( Obj"flame_shield" );
	
        set( "inquiry", ([
                "wine" : 
@WINE
「嗯 !! 本座一向久仰赵燕居的酒名，今天还特地来一试，
没想到也没什麽大不了的，跟京城的太白楼也相差不多，真是颇为失望，难道这里真
的没有好酒吗？ ...」
WINE
]));

}
int accept_item(object me,object item)
{
     if ((string) item->query("name") !="old wine" ) return 1;
     tell_object(me,
@MISSION
方傲天拍开老酒的封泥，一阵酒香已经透了出来，他竖起拇指对你笑道：「好酒 !!」。
於是你们连桌共饮，谈天说地不亦快哉 !! 喝到後来，他跟你谈起此行的任务 ...
原来皇上获得密报，诚王有意谋反，意图在皇上观赏武道大会之时派杀手刺杀他，
於是命方傲天前来查办。方傲天已经派了一个得力助手贾老六先来了，可是一直没
有消息，所以他自己赶来查探。
MISSION
	);
                item->remove();
	return 1 ;
}
