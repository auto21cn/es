#include <mudlib.h>

void create(object ob)
{
		if ( ! ob ) return ;
        ob->set_level(14);
        ob->set_name( "rhinoceros", "犀牛" );
        ob->set_short("犀牛" );
        ob->set_long(@C_LONG
这只动物看起来很呆呆的, 似乎没什麽攻击性....
咦, 不对, 它的角上沾满了血迹, 恐怕有人丧命於他,
最好还是提高警觉!
C_LONG
        );
        ob->set("unit","只");
        ob->set_perm_stat( "str", 22 );
        ob->set_perm_stat( "dex", 15 ); 
        ob->set_perm_stat( "int", 12 );
        ob->set_skill( "dodge", 80);
        ob->set("max_hp", 600);
        ob->set("hit_points",600);
        ob->set("special_defense", ([ "all":25, "none":10,"fire":5 ]) );
        ob->set("aim_difficulty",
                ([ "vascular":10, "weakest":20 ]) );
        
        ob->set( "alignment", 200 );
        ob->set_natural_weapon(40,15,25);
        ob->set_natural_armor(40,30);
        ob->set_c_verbs( ({ "%s凶猛地向%s一口咬去",
                        "%s用它的角全力向%s顶过去"  }) );
        ob->set_c_limbs( ({ "头部", "身体", "脚部"}) );
}
