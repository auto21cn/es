#include "../legend.h"
#include <mudlib.h>

inherit OBJECT;

void create()
{
     seteuid(getuid());
     set_name("Sea Ball", "定海珠");
     add("id", ({ "sea ball","ball" }) );
     set_short("定海珠");
     set_long(@C_LONG
一颗靛蓝色的珠子,隐隐约约传来海的讯息。
C_LONG
     );                             
     set( "unit", "颗" );
     set( "no_sale",1);
}
void init()
{
   add_action("do_roll","roll");
}
int do_roll(string arg)
{
    object holder,env;
    if ( !arg || arg!="sea-ball" ) 
       return 0;
    holder=environment(this_object());
    if ( !living(holder) ) 
       return 0;    
    env=environment(holder);
    if ( !env->query("can_use_sea_ball") )
       return 0;
    if ( env->query("exits/tunnel") ) {
       tell_object(holder,"这里己经有一条通道 ( tunnel ) 了!\n");       
       return 1;
    }
    if ( present("water beast",env) ) 
      return 0;
    holder->set_temp("block_command",1);
    tell_object(holder,set_color(
        "\n\n       你口中喃喃自语地用手摩擦著定海珠..\n\n\n",
        "HIC"));
    tell_room(env,set_color(sprintf(
        "\n\n       %s口中喃喃自语地用手摩擦著定海珠..\n\n\n",holder->query("c_name")),
        "HIC"),holder);   
    call_out("recover1",2,holder,env);       
    return 1;
}
void recover1(object holder,object env)
{
    tell_room(env,set_color(
       "\n\n       忽然间！！湖面波浪□天、雷电交加，甚是险恶....\n\n"
       "       你心里闪过不好的预感！！\n\n"
       ,"HIC"));
    call_out("recover2",6,holder,env);
}    
void recover2(object holder,object env)
{
    object beast; 
    holder->delete_temp("block_command");
    tell_room(env,set_color( 
       "\n\n       轰！一道闪电垂直轰向湖面！！\n\n" 
       "       在闪电过後，湖面隐隐约约地出现一条甬道 ( water-tunnel ) ！！\n\n\n"
       ,"HIC"));
    if ( !beast=present("water beast",env) ) {
       beast=new(LMONSTER"water_mob");
       beast->move(env);  
    }
    env->add("exits/tunnel",LAKE"lake1");
    env->add("c_item_desc/water-tunnel","一条水道 ( tunnel ),两旁都是丈高的水墙。\n");
    env->set( "exit_suppress", ({
                   "tunnel"}) );
    this_object()->remove();
}
