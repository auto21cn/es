
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The squire of the dwarf village","矮人村落的广场");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村庄的大广场上,这里有著非常和平安详的气氛,矮人们经常在此地
游玩及嬉戏.北边有一个很大的水塘(pool),是矮人饮用水的来源 ,在水塘的中央有一个飘
浮的房子(house),你不能想像为何它能浮在空中而不掉下来.在水塘的旁边有一个标志(si
gn),上面似乎写著一段文字.
CLong
    );
    set("c_item_desc",([
        "pool":"一个大水塘,由於矮人的饮用水取於此地,所以此水塘禁止游泳.\n",
        "house":"一间飘浮的房子,它有著奇怪的力量,当你注视著它的时候,你发现有一\n"
                "奇异的光线从里面射了出来.\n",
        "sign":"\nOSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSO\n"
               "O              飘扶之屋,闲人勿进                        O\n"
               "O              回答(answer)密语,请君入□                O\n" 
               "O              ...........长老 安洛(Annow)              O\n"
               "OSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSO\n"
                ]) ); 
    set("exits",([
                "west":Deathland"/village/v22",
                "east":Deathland"/village/v42",
                "south":Deathland"/village/v31",
             ]));
    ::reset();
}

void init()
{
     add_action("to_answer","answer");
}

int to_answer(string str)
{
    if (!str ||str!="intelligence")
    return notify_fail(
           "房屋中传来一阵笑声,说:愚蠢的人愚蠢的答案.\n");
    else
           write("一阵柔和的光线把你传送至飞天小屋内.\n");
           this_player()->set_explore("deathland#26");
           this_player()->move_player(Deathland"/village/v33",({
           "一阵光束笼罩著%s,然後他就消失了.\n",
           "%s被送到这里.\n"}),"" );       
           return 1;
}  
   
