#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "gorden dreaming carp", "黄金梦幻鲤鱼" );
        add ("id", ({ "fish","carp" }) );
        set_short( "黄金梦幻鲤鱼");
        set("unit","尾");
        set_long(
           "    哇！多漂亮的一条鲤鱼呀，黄金色的鳞片闪耀著炫目的光芒，这大概\n"
           "就是达婆婆口中所说的黄金梦幻鲤鱼吧。\n"
        );
        set( "likefish",1);
        set( "unbleeding",1);
        set( "max_hp",300 );
        set( "hit_points",300 );
        set("alignment",200);
        set_perm_stat("str", 18);
        set_perm_stat("dex", 22);
        set_perm_stat("kar",15);
        set_natural_weapon( 30, 20, 35 );
        set_natural_armor( 50, 30 );
        set ("gender", "male");
        set_c_limbs(({"头部","身体","尾鳍"}));
        set_c_verbs( ({ "%s张嘴，往%s咬去","%s尾鳍用力一甩，甩向%s" }) );
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(TOBJ"sashimi");
   killer = query("last_attacker");
   if( !killer ) {
     ::die(1);
     return;
   }
   tell_room(environment(this_object()),
      "\n你的最後一击终於打扁了这条不乖的鲤鱼的头，这世界上从此又少了一条\n"
      "梦幻黄金鲤鱼了，为了纪念你钓上这种鱼，於是你把它身上的肉割下来，做\n"
      "成了生鱼片，并且顺手把剩下的□体埋在附近的地上，焚香祭拜。\n",
      this_object());
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die(1);   
}
