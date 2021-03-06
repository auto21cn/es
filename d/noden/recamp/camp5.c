#include <mudlib.h>
#include "camp.h"
inherit ROOM;

void create()
{
	::create();
   set_short("地道");
   set_long( @LONG_DESCRIPTION
这条神秘的地道，建造的年代似乎相当久远，但是却相当的宽敞与坚固，壁上镶
镶著耀眼明亮的珠子，照亮整个通道，壁上还绘著奇奇怪怪的动物图案，与不知名的
古文，相当吸引人的留意。门上还各有个牌子(sign)。
LONG_DESCRIPTION
);

   set("light",1);
   set( "exits", ([ 
    "up"   : CAMP"camp4",   
    "east" : CAMP"camp6",  
    "west" : CAMP"camp8", 
   ]) ) ;

   set( "item_func", ([ 
    "sign":"look_sign", 
   ]) ) ;

   set( "objects", ([ 
	"mob1" : CAMPMOB"mob1"
   ]) );

   reset();
}

// int look_sign()
// {
//  write("    /~~~~~~~~~~~~~~~~~~~~~~~~~~~/~\\  \n"
//        "   | It is a great invention   |___| \n"
//        "   |     of ink && paper ..    |     \n"
//        "/~~~~~~~~~~~~~~~~~~~~~~~~~~/   |     \n"
//        "\\__________________________\\__/      \n") ;
//   return 1 ;
// }


int look_sign()
{
 write("    /~~~~~~~~~~~~~~~~~~~~~~~~~~~/~\\  \n"
       "   |    这是一大发明           |___| \n"
       "   |            墨水和纸张     |     \n"
       "/~~~~~~~~~~~~~~~~~~~~~~~~~~/   |     \n"
       "\\_________________________\\__/      \n") ;
  return 1 ;
}
