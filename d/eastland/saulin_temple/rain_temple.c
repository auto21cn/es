#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "雨花院" );
       set_long( @C_LONG_DESC
你走到个小院不禁有些诧异，空汤汤的院里居然没有任何佛像，只正中
摆\了块七色彩石(stone)， 相传昔日佛祖说法，说的顽石点头天女散花
，天花坠地化为彩石，莫非就是这块石头？东方是普贤殿。
C_LONG_DESC
       );
       set("item_desc",([ "stone" : @C_LONG
你看著这块石头，它好像只是一块普通的彩石嘛! 真不知道为什麽少林寺要郑重
其事的把它供奉起来？
C_LONG
       ]));
       set("light", 1);
       set("exits",([
		"east" : SAULIN"pusan_temple",
		"west" : SAULIN"forest7",
       ]) );
       reset();
}

void init()
{
       add_action( "touch_stone", "touch" );
}

int touch_stone(string arg)
{
	if( !arg || arg !="stone" )
		return notify_fail("喂喂! 你不要到处乱摸啊!\n" );
	if( this_player()->query("quest/elephant") ) {
        tell_object( this_player(), @SHADOW_OUT
你把这块石头拿起来，用袖子使劲的擦，擦了老半天什麽事也没发生，正感到
一阵失望？咦？等等，它的七彩花纹好像会动呢! 天啊! 这块石头是活的？你
不禁双手发颤，不小心把石头摔落在地，石头应声破裂，发出一股轻烟，强烈
的晕眩向你扑来，你想要夺门而逃已经来不及了。你晕了过去 !

你突然感到有人在摇你，睁开眼睛一看，原来是美丽可爱善良温柔又有气质的
茹比，她笑咪咪的解释：对不起! 还在帮石头整理内部。等到开放了再通知你
，好吗 ？她拿出一把大棒子往你头上一敲，你又晕过去了。
SHADOW_OUT
		);
	}
    else
		tell_object( this_player(), @SHADOW_OUT
你把这块石头拿起来，用袖子使劲的擦，擦了老半天什麽事也没发生。
SHADOW_OUT
		);
	return 1;
}
