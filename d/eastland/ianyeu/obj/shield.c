#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "topaz shield", "闪晶盾" );
        add( "id", ({ "shield" }) );
        set_short( "闪晶盾" );
        set_long(
        "你看到一块硕大质纯的酒黄宝石, 当你注视它时,\n"
        "彷佛看到如夕阳般美丽的景色。你是否想要擦(rub)\n"
        "去上面的灰尘, 以便看得清楚些?\n"
        );
        set("unit","块");
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense", ([
               "fire" : -15, "cold": -15, "acid" : -15,
               "energy" : 12, "magic" : 12, "electric" : 12
          ]) );
        set( "weight", 100 );
        set( "value", ({ 2150, "silver" }) );
        set( "no_sale", 1 );
}

void init()
{
   add_action( "rub_shield", "rub" );
}

int rub_shield(string str)
{
   if( !str || !id(str) )
        return notify_fail( "你要摩擦什麽?\n" );
   if( (int)this_player()->query("spell_points")<50 )
        return notify_fail( "你的精神太差了, 无法有效摩擦盾牌。\n" );
   if( query("light") )
        return notify_fail( "它已经被摩擦过了。\n" );
   write( "你用力地摩擦盾牌, 盾牌逐渐地发出微弱的光芒。\n" );
   this_player()->add( "spell_points", -50 );
   set( "light", 1 );
   call_out( "run_out", 240 );
   return 1;
}

void run_out()
{
   object owner;

owner = environment(this_object());

   if( living(owner) )
   tell_object( owner, "闪晶盾的电光渐渐微弱...最後终於停止发光...\n" );
   set( "light", 0 );
}
