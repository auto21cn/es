//#pragma save_binary

// A basic coin exchange which inherits the standard coin exchange object.
// Needs to call ::create() like the shop does.

#include "farwind.h"
#include <money.h>

inherit "/std/exchange";
inherit ROOM;

void create()
{
	room::create() ;
	set("light",1) ;
    set_short( "钱币兑换中心");
	set_long(@C_LONG
你现在位於远风镇远近驰名的钱币兑换中心。 在这里你可以把身上的
各种钱币换成金币、银币、铜币等。只要下 convert [数量] [甲钱币] to
[乙钱币] 命令就可以把指定数量的甲钱币换成等值的乙钱币。如果你不指
定 [数量]，就会把你身上所有的甲钱币换成乙钱币。
在左方的墙上有个钱币兑换表(sign)。
C_LONG
                );
	set ("exits", ([ "down" : FARWIND"bank" ]) );
   set( "c_item_desc", ([
          "sign" : 
@LONG
    目前世面上流通的钱币只有四种:
----------------------------------------------------------
  一. 白金币(platinum): 一枚白金币可兑换十枚金币.
  二. 金币(gold): 一枚金币可兑换十枚银币.
  三. 银币(silver): 一枚银币可兑换十枚铜币.
  四. 铜币(copper).
----------------------------------------------------------
LONG
     ]) );
}
