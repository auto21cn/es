#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(17);
        set_name( "shu ju", "扫地僧 虚竹" );
        add ("id", ({ "monk","shu","ju" }) );
        set_short( "扫地僧 虚竹");
        set("unit","位");
        set_long(@C_LONG
在少林寺众多的高僧中，虚竹要算是最没有名气的了。他从年轻的时候就开始
负责藏经楼的打扫工作，平日甚少跟外界接触，就连少林寺中知道他的也没有
几个人。但是多年来打扫藏经楼的结果，他几乎读遍所有的经书，所以如果你
要找人讨论经书的话，他应该是最合适的人选了。
C_LONG
        );
        set("alignment",2000);
        set("wealth/silver",38);
        set("gender","male");
        set("race","human");
        set("chat_chance",10);
        set("max_hp", 600);
        set("hit_points", 600);
        set("max_fp", 400);
        set("force_points", 400);
        set("special_defense", ([ "all" : 45, "none" : 40 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50 ]) );
        set_perm_stat("str", 24);
        set_perm_stat("dex", 28);
        set_perm_stat("pie", 30);
        set_perm_stat("kar", 18);
        set_natural_weapon( 35, 20, 35 );
        set_natural_armor( 75, 20 );
        set_skill("dodge",100);
	set("defense_skill",CLASS"body_def");
	set("monk_gonfu/body-def",10);
        set_skill("bo",100);
        set ("chat_output",({
        	"虚竹说道：最近藏经楼好像有小偷，掉了几本经书(sutra)。\n"
        }));
        wield_weapon( SAULIN_OBJ"whisk" );
//	equip_armor( SAULIN_OBJ"boot2" );
//	equip_armor( SAULIN_OBJ"shield3" );
        equip_armor( SAULIN_OBJ"grey_pallium" );
        equip_armor( SAULIN_OBJ"ring3" );
        set("inquiry",(["sutra":
@C_LONG
最近寺中清点经书的时候发现掉了几本，大部分都不是很重要的
经书，可是其中有一本愣加经似乎方丈特别重视，要求我们一定要找回来，可
是这本经书对我们研究佛经的人来说并不是很重要，实在有点奇怪。不过既然
是方丈的意思，我们只有照著做。
C_LONG
]));

}

