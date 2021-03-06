#include <../mumar.h>
inherit "/d/eastland/mumar/mumar_army";
 
void create()
{
        ::create();
        set_level(10);
        set_name( "gonfu master", "教头" );
        add( "id", ({ "master" }) );
        set_short( "教头" );
        set_long( "你看到一个臭屁的教头正在对新兵指指点点地。\n" );
        set( "race", "human" );
        set( "gender", "male" );
        set( "alignment", 300 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 70 );
        set( "wealth/gold", 20 );
        set_natural_weapon( 22, 9, 17 );
        set_natural_armor( 43, 20 );
        set( "natural_weapon_class2", 28 );
        set( "natural_min_damage2", 10 );
        set( "natural_max_damage2", 22 );
        set( "chat_chance", 5 );
        set( "chat_output", ({
                "教头对新兵说道: 你怎麽那麽笨，连个马步都扎不稳。\n",
                "教头对著新兵大骂: 还摸鱼!!你就快倒大楣了!!\n",
                "教头对你说: 看什麽看!!没看过老鸟带菜鸟啊!!。\n",
                "教头用不屑的眼光正上下打量你。\n"
        }) );
        set( "att_chat_output", ({
  "教头大叫:「孩子们!把这个肉脚打成肉包吧!!把我教你们的本事都用上来!!」。\n",
        }) );
 
    equip_armor(OBJS"pants");
    equip_armor(OBJS"cloth02");
}
