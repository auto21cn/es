// Echo/item/letter01.c
#include "../echobomber.h"
inherit OBJECT;
void create()
{
set_name("paper","破旧的纸张");
set_short("a paper","破旧的纸张");
set("c_long",@ScryBall
一张已经发黄的纸张,上面写著密密麻麻的文字.\或\许\你可以试著去读(read)它.
ScryBall
);
set("no_sale",1);
set( "unit", "张");
set("weight", 5);
set("value", ({ 5, "silver" }));
}
void init()
{
add_action("read_letter","read");
}

int read_letter(string str)
{
    object ob1,room_1;
    if (!str ||str!="paper") return 0;
    else {
      ob1=environment(this_object());
      if (ob1!=this_player()) 
        return 0;
      else 
        {
          write("当我在矮人迷宫中研究了四十几天之後, 我终於发现了通往矮人村的\n"
                "正确方法,但是同样地矮人牧师底斯宜尔也发现了我,他使用该死的静\n"
                "止术然後把我捉来这里 ,我的巨人族同伴们试著把我救出但是却一一\n"
                "失败了.最後该死的矮人把这里的出口封住,把我困死在这里 .在我生\n"
                "命的尽头,我把这个令矮人活著如此久的该死迷宫秘密计录下来.希望\n"
                "我的巨人伙伴能得知,让矮人族的生活永远处在恐惧之中,不得安宁.\n"
                "这秘密是:进入迷宫之後,走,东,南,南,北,西,北,西,矮人的财富与生\n"
                "命就在你的掌握之中了........哈!哈!哈.\n"
                "\n\n                        _______巨人魔法师林顿(Lindn)...\n"        
              );
          return 1;      
        }
    }
}
