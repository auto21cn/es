// File: /d/noden/asterism/tower2-3.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮人高塔的第三层");
	set_long(
		@C_LONG_DESCRIPTION
这里是艾斯特律恩城中矮人高塔的第三层,一阵肃杀的气氛笼罩与此地.这里的防护
十分强大,除了有著守卫看守著之外,这高塔的每一层都用上了厚厚的锁 .这里在往上一
层就是矮人王阿莱特斯四世的住处了.一本厚厚的黑皮书(blackbook)被放置於一个空空
的书橱(closet)上面.除此之外这里就没有任何其它有趣的东西了.
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"up" : ASTR"tower2-4",
		"down":ASTR"tower2-2",
		]) );
	set("c_item_desc",([
	    "blackbook":"你可以试著去读它.\n",
	    "closet":"除了一本黑皮书外,并没有甚麽东西放在上头.\n",
	    ]) );	
//	set("objects",([
//	    "guard#1":MOB"dwarf_guard01",
//	    "guard#2":MOB"dwarf_guard01",
//	    ]) );
	reset();
}

void init()
{
     add_action("to_read","read");
}

int to_read(string str)
{
   if (!str||str!="blackbook") return 0;
   
   write(can_read_chinese()?
         "             --------阿莱特斯王朝的历史:--------\n\n"
         " 一群精英武士骑著狮鹫兽,从死亡大地的深处飞出来,为了找寻理想的家园,\n"
         " 不辞辛劳地日夜奔波,而领导这群武士的就是阿莱特斯王.               \n"
         " 当这群武士来到了贝基尔山脉的时候,他们了解到要再找到像这样的地方是\n"
         " 很困难的事了,於是他们就从狮鹫兽上走了下来.但是却遇到了固执的地精.\n"
         " 地精,一群强烈排外的种族,他们并不欢迎矮人的到来.但是世事就是这麽的\n"
         " 的凑巧,一群半身人正好被魔族所追杀著而逃到了这里,而半身人的族长与地\n"
         " 精长老有著深厚的交情,而且地精与魔族的大战争已经发生过两次了,因此地\n"
         " 精,半身人与魔族展开了第三次地精魔族战争.前两次地精以强力的神圣魔法\n"
         " 勉强的抵挡住邪恶的魔族,但是这次魔族有备而来,可怕的魔族大魔导士比里\n"
         " 来尔司德思终於发现了抵抗神圣力量的方法,准备这次一举消灭地精们,但是\n"
         " 魔族们没有想到强力的战士会出现,阿莱特斯的精英武士与地精半身人的魔法\n"
         " 师联手之下,终於击溃了魔族大军,并把比里来尔司德斯的灵魂给禁锢了起来.\n"
         " 这一次战役後,矮人,地精,半身人签下了和平共处协议,并建造了艾斯特律恩.\n":
         "ENGLISH MODE NEED TRASLATE.\n" );
   return 1;
}
