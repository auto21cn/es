#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "武士团副队长室" );
   set_long(@ANGEL
在你来到武士团副队长星卡的住所，虽说星卡是武士城堡中的第二号
人物，但是他的住所却非常的朴素，只有一张床和桌椅，没有其他多馀的
家具，墙上则是挂满了感谢状，这些都是星卡立\功\时\所\得到的奖励，床的
旁边则是星卡收放防具的箱子．
ANGEL

   
         );
	set( "light",1);
	set("objects",([
	"si_ka":MOB"si_ka"
	]));		
        set( "exits", ([
    "south"  :MR"inn04",    
                ]) );
                            
         reset();                     
}

