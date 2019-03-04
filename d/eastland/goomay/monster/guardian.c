
#include "../goomay.h"
#include <stats.h>
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "Guardian", "会场守卫" );
        add ("id",({ "guardian"}));
        set_short( "会场守卫");
        set("unit","位");
        set_long(
@C_LONG
他是一个长的极为可怕的蜥蜴人守卫，布满细细鳞片的身上泛著诡异的油光，
他发现你正盯著他看，便向你喝道：「看什麽看？付钱啊 ! 每人黄金五十两 !」
C_LONG
);
		set("no_attack",1);
        set ("gender", "male");
        set("exp_reward",61) ;
        set_natural_weapon(65 , 30 , 45) ;
        set_natural_armor( 80, 40 ) ;
        set ("race", "lizardman");
}

void init()
{
        add_action( "pay_me", "pay");
}

int pay_me(string arg)
{
        string who, type;
        int num;
	object obj;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail("付谁？多少钱？\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
         tell_room( environment(), 
          "守卫叫道: 你聋了吗？不是跟你说要金币吗？\n",
          this_object() );
                return 1;
	}
       if( !this_player()->debit(type, num) ) return notify_fail( 
           "你没有那麽多金币。\n");

        if( num < 50 ) {
         tell_room( environment(), 
          "守卫叫道: 你想骗老子吗？钱不够 ! 没收 !!\n" ,
          this_object() );
                return 1;
	}

	obj = this_player();
	if (num>=50) 
	{
        tell_room( environment(), 
         "守卫向"+obj->query("c_name")+"点点头说道: 好 !! 进去吧 ! 并且把他推进武斗大会场。\n"
		, ({obj}) );
        tell_object( obj, 
         "守卫向你点点说道: 好 ! 进去吧 !! 并且很粗鲁的把你推进武斗大会场。\n"
                );
      obj->move_player( Goomay"coliseum2", "SNEAK" );
        tell_room( Goomay"coliseum2", 
          obj->query("c_name") + "跌跌撞撞的跑进来。\n"
	,obj );

	return 1;
	}

}
