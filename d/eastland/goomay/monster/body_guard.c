
#include "../goomay.h"
#include <stats.h>
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(15);
        set_name( "Bodyguard", "赌场保镖" );
        add ("id",({ "guard"}));
        set_short( "赌场保镖");
        set("unit","位");
        set_long(
@C_LONG
他是一个长的极为可怕的蜥蜴人守卫，布满细细鳞片的身上泛著诡异的油光，
他正一边摆\动著他的尾巴一边看人下注，好像也很想下场试试，不过看他的
样子似乎没什麽钱，大概都输光了吧 !! 他发现你正盯著他看，便向你笑道
：「客人你好 !! 快来发财吧 !」
C_LONG
);
        set ("gender", "male");
        set ("race", "lizardman");
        set_natural_armor( 45, 10 );
        set_natural_weapon( 0, 5, 10 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_skill( "axe", 90 );
        set_skill( "two-weapon", 90 );
        set_skill( "parry", 60 );
        set( "hit_points", 600 );
        set( "max_hp", 600 );
        set( "special_defense", ([ "all": 20 ]) );
        wield_weapon( Obj"iron_axe" );
        wield_weapon2( Obj"iron_axe" );
        equip_armor( Obj"steel_tail" );
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
                return notify_fail(
                        "付谁？多少钱？\n");
        if( !id(who ) ) return 0;
       if( !this_player()->debit(type, num) ) return notify_fail(
		           "你没有那麽多钱。\n");

         tell_room( environment(), 
          "守卫搓著手笑道：谢谢你 !! 要下场试试手气吗？ \n" ,
          this_object() );
                return 1;

}
