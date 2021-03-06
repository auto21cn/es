#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("草原");
	set_long(@LONG
你来到了一处空旷的草原，西和南边是草原的延伸，北边是大树群。在草原上
长满了些小小的矮花，矮花的颜色很鲜□，靠近一闻，鼻子中满是浓郁的香味。除
此之外，一群野蜂正悠哉悠哉地穿梭在花丛间，恣意地采著蜂蜜。你东边是一面千
仞高的山壁，上面突出来大大小小的岩块如叠格子般一层层的井然有序，与其说这
山壁是经由石头堆积起来的！岩块间有许多裂缝，你试了试发现其大小正足可以容
纳一只脚的体积，如果你攀爬技术纯熟，或许可以籍此登上( climb )。
LONG
	);
	set("light",1);
	set("exits", ([ 
            "west" : SAREA"plain3",
           "south" : SAREA"plain2",
        ]) );
	reset();
}
void init()
{
   add_action("do_climb", "climb" );
}
int do_climb()
{    
   int climb_skill;
   object player;
   string name;
   player=this_player();
   name=player->query("c_name");
   climb_skill = (int)player->query_skill("climbing");
   if( random(climb_skill) < 20 ) {
      write("\n\n虽然你使劲了全身的力量却一个不小心踩错地方跌了下去！\n\n");
      tell_room(this_object(),sprintf(
         "%s踩著石缝想往上爬，结果失败跌了下来。\n",name),player);
      player->receive_damage(20);
      return 1;
   }
   write("\n你头也不回气也不喘地专心往上爬去．．\n\n\n\n\n\n");
   player->move_player(SAREA"mountain1",({
        "%s费力地往上爬去。\n",
        "%s从下面爬了上来。\n"}),"");
   return 1;                   
}