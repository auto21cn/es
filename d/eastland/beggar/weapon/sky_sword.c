#include <mudlib.h>

#define DETECT_ALI(x) (int)x->query("alignment") 
#define DETECT_SCORE(x) (int)x->query("war_score")
inherit WEAPON;

void create()
{
    set_name( "blood sword","赤血剑" );
    add("id",({"blood","sword"}) );
    set_short( "赤血剑" );
    set_long(@C_LONG
一把剑身呈红色的长剑。赤血剑的来源已不可考,只知道是在三国时代一位伟大的
铸剑师制成。这把剑还有一段不为人知的历史;想当初那位铸剑师为了让这把剑有
了灵气,不惜投身於火炉之中,於是在剑身似乎还留有一丝丝红色的血气。
C_LONG
            );
    set("unit","柄");
    setup_weapon("longblade",20,15,15);
    set("weight",50);
    set("value",({400,"silver"}) );
}
