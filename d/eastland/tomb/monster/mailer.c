#include <../almuhara.h>
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid( getuid() );
        set_level(5);
        set_name( "mail man", "信差" );
        set_short( "信差" );
        add( "id", ({ "man" }) );
        set_long(
@C_LONG_DESCRIPTION
你看到一个官差打扮的人，他的胸前有一处很深的刀伤，正奄奄一息地在这寻找
出路。对於你的来到，他似乎相当高兴，不过他好像已经没有力气向你求助了。
C_LONG_DESCRIPTION);
        set( "gender", "male" );
        set( "max_hp",120);
        set( "hit_points",1);
        set( "natural_armor_class", 20 );
        set( "natural_defense_bonus", 10 );
        set( "no_attack",1 );
        set_natural_weapon(12,5,15);
        set( "inquiry", ([
        "help" : "@@ask_help" ]) );
}
 
int ask_help()
{
object obj;
tell_object(this_player(),
@ASK
 
信差用微弱的声调说：盗..贼......玉........佩.国....师.......
当你想问个清楚时.....却发现他已经断气了.......
 
一块玉佩从信差垂下的手中掉落。
 
也许是身中剧毒，信差的□体迅速地化成血水......渗入地面......
ASK);
obj=new("/d/eastland/tomb/item/break_jade1");
obj->move(environment(this_object()));
this_object()->remove();
}
