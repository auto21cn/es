#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿起居室");
	set_long( 
@LONG_DESCRIPTION
这是一间神殿起居室，除了长老之外，在这个神殿□工作的所有人都睡在这儿，
你看到排的整整齐齐的石床(bed)，床上的被褥比你在"成Ｘ岭"的表现好上一千倍，
你正觉的脸红时，突然发现最靠角落的一张床好像还有人(man)在睡觉。
LONG_DESCRIPTION
	);
set( "exits", ([
     "west": OTEMP"temple14",
     ]) );
set("item_desc",([
    "bed":"@@look_bed",
    "man":"一个睡的很熟的人，偶而还会放个屁。\n",
    ]) );
reset();
}

string look_bed()
{
write("\n躺在床上那个人翻了个身子，嘴里还说著梦话：我才不相信有黑龙宝盒勒。\n");
write("\n你有问题想问他，想叫他但又不好意思...............\n");
return "你想了想，决定还是叫(call)他起床。\n\n";
}

void init()
{
  add_action("do_call","call");
}

int do_call(string arg)
{
  if (!arg || (arg!="man" && arg!="人")) return 1;

  write("\n那个人把头转过去，很不耐烦的说：吵什麽吵，没看到老子在睡觉吗?\n");
  write("\n你不死心，又叫了一次，那个人还是不回头......\n");
  write("你终於不耐烦的大叫：起床啦，没看过坏人啊，再睡就把你的ＸＸ剪掉。\n");
  write("\n那人一听，反而把头缩在被子里，好啦，我跟你讲：村子的那口井，\n");
  write("有一天晚上我看到有一道光芒从那口井发出，不知道是不是我眼花了。\n");
  write("\n这就是我所知道的....大人有大量..让我继续睡吧...............\n");
  write("\n只见他翻了个身又打起鼾来了...\n");
  return 1;
}
