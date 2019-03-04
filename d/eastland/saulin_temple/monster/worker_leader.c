#include "saulin_monka.c"

void create()
{
        ::create();
        set_level(9);
        set_name( "worker leader", "管工" );
        add ("id", ({ "leader","worker" }) );
        set_short("管工");
        set("unit","位");
        set_long(@C_LONG
这是管工，他平日的职责是督促长工不要偷懒。他手上正拿著一条皮鞭，
看起来凶巴巴的。
C_LONG
        );
        set("alignment",-200);
        set("wealth/silver",100);
        set_perm_stat("str", 13);
        set_perm_stat("dex", 12);
        set_natural_weapon( 7, 0, 4 );
        set_natural_armor( 45, 16 );
        set_skill("whip", 50);
        set ("gender", "male");
        set ("race", "human");
        set ("pursuing",1);
        set ("chat_chance",12);
        set ("chat_output",({
        "管工说道：这些长工整天好吃懒做，让我非时时盯著他们不可，真讨厌。\n",
        }));
        wield_weapon(SAULIN_OBJ"knout");
}
