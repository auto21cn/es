#include <mudlib.h>
#include "../../story.h"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(16);
	set_name( "gardener", "招英" );
	add ("id", ({"gardener"}) );
	set_short( "後花园管理者 招英");
	set_long(@CLONG
招英生得一个马的身子、人的脸、背上长著一对翅膀、通身是老虎斑纹。他常飞行
在空中，周游四海，发出大声的叫喊。招英乃是管理後花园，你最好不要在此处滋
事，以免遭到他的惩罚。　 
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 27 );
	set( "alignment", 100 );
        set( "max_fp",200);
	set_natural_weapon( 5, 4, 10 );
	set_natural_armor( 68, 30 );
        set_skill("dodge",70);
        set_skill("parry",70);
        set_skill("shortblade",100);
        wield_weapon(SPWEA"scissors");
        equip_armor(SPARM"gardener_belt");
        set("Hking",1);
        set("special_defense",(["all":30,"none":25]));
}
void init()
{
   if ( this_player()->query_temp("kill_huang") ) {
      write("招英哼道：竟敢在花园里给我乱来，看我不好好教训你才怪哩！！\n\n");
      kill_ob(this_player());
      this_player()->delete_temp("kill_huang");
   }
   ::init();
}