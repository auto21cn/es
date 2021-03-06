// File: 7,2.island.c

#include <mudlib.h>
#include "island.h"
#define GATE_OBJ "/d/island/island_gate"

inherit ROOM;
string location;

string long=("你身处在一片美丽的桃花林中，这里正是所谓的『落英缤纷，芳草鲜\n"+
       "美』，要是仔细观察此处的桃树，你会发现它们以某种特殊的次序排列著\n"+
       "；在这里站的越久，你越觉这儿的桃树好像太密了，而且....好像会移动\n"+
       "，事有蹊跷，你想你最好仔细观察一下，说不定会有收获唷！\n" );

void create()
{
        ::create();
        set_short("桃花林");
        set("long","@@query_gate");

        set_outside( "island" );
        set( "exits", ([ 
                "down"  : "/d/noden/6,6.noden",
                "west"  : ISLAND"6,2.island", 
                "north" : ISLAND"7,1.island", 
                "east"  : ISLAND"8,2.island",
                "south" : ISLAND"7,3.island",
                ]) );
        set( "original", ISLAND"7,2" );
        set( "virtual_server", ISLAND"virtual/island_server" );
        set( "x_coordinate", 7 );
        set( "y_coordinate", 2 );
        set( "no_monster" , 1 );
        reset();
}
string query_gate()
{     
        string describe;
        if (location == "virtual" )
        {
              describe = long ;
              return describe ;
        }
        else
        {
              describe = long +"吓！ 地上竟有个闪闪发光的大洞！\n" ;
              return describe ;
        }
        
}
varargs void set_location( string new_loc , string exit )
{
        location = new_loc ;
        if (location=="virtual" || !exit )
        {
          delete("exits");
          set( "exits" , ([
                 "west"  : ISLAND"6,2.island",
                 "north" : ISLAND"7,1.island",
                 "east"  : ISLAND"8,2.island",
                 "south" : ISLAND"7,3.island",
                 ]) );
          GATE_OBJ->move( "/d/island/chaos" );
          tell_room( find_object(ISLAND"7,2.island"),@LONG
          
白光一闪，一切都恢复原样了。

LONG
              );
        }
        else
        {
         
          set("exits" , ([
                   "down"  : exit ,
                   "west"  : ISLAND"6,2.island",
                   "north" : ISLAND"7,1.island",
                   "east"  : ISLAND"8,2.island",
                   "south" : ISLAND"7,3.island"
                         ]) );
          GATE_OBJ->move( exit );
          tell_room( find_object(ISLAND"7,2.island"),@LONG
          
林中的地面忽然隐隐发光，接著便出现一个洞穴了！

LONG
             );
        }
        
 }       
      
  
