#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("井底");
        set_long( 
@LONG
噗的一声，你从水底探头而出，深吸了一口气，心想好险，差点就被奄死了。
你攀住手边的岩块，好奇地往周围打探了一下，发现你身处井底。井水泌凉，井壁
上光滑乾净，鲜有青苔，看来定是口常被使用的水井。你想附近就应该有人烟，也
许大叫救命就会有人听得见，顺便拉你出井。
LONG);
    set( "light",1);
    ::reset();
}

void init()
{
   add_action("do_shout","shout");
}

int do_shout(string arg)
{
    
   object player,env;
  
   if ( !arg || arg!="救命" && arg!="help" ) return 0;
   player=this_player();
   env=find_object_or_load(LAKE"village9");
   call_out("help1",3,player,env);
   return 0;
}
void help1(object player,object env)
{     
   if ( !present("woman",env) ) {
     tell_object(player,"你等了一会儿，\n竟然给它没有人，『口年口年』！\n");
     return ;
   }
   tell_object(player,"\n你听到井边一阵骚动，抛下了一根绳索．．．．\n");
   player->move_player(LAKE"village9","SNEAK");
   tell_object(player,"你伸手一拉，攀了上来．．．．．\n");
   tell_room(env,@LONG

井边正在洗衣服的妈妈桑大喊著说：『么寿喔！没事乱跑到井里~!@#$%^&*....』

LONG);
   return;
}     


