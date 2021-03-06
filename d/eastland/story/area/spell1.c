#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("禁地");
	set_long(@LONG
你来到了一处神秘的禁地，四周围不时传来一些细微的声音，那声音是你从来
没听过的语言，其发音古怪已极！禁地中，你还可以看到一些栩栩如生的雕像，雕
像的模像极其凶恶，令你感到畏惧，一阵阵的寒意由然而生！据说，这里曾被施以
咒语，许多到过这里探险的人，十之八九都遭遇到不测，不晓是否因为那咒语的关
系，所以，你还可以在地上看到许多骷髅头，你想想还是快离开这里吧，俗话说的
好：「宁可信其有不可信其无。」说不定，待会儿你的□体会在这里被别人发现！
LONG
	);
        set( "exit_suppress", ({
            "nd","su"}) );
	set("exits", ([
              "southup" : SAREA"hole2",
            "northdown" : SAREA"spell2",
                   "su" : SAREA"hole2",
                   "nd" : SAREA"spell2"
        ]) );
	set("light",1);
	reset();
}
void init()
{
    int i;
    object player,*all;
    add_action("do_cant","get");
    add_action("do_cant","auction");
    player=this_player();
    if ( !player->query_temp("can_pass_spell") ) {
       write("\n这禁地的咒语，让你感到天旋地转一阵昏眩！\n\n");
       player->add("hit_points",-30);
       all=all_inventory(player);
       for (i=0;i<sizeof(all);i++) {
          if ( all[i]->query("max_load") ) all[i]->set("need_drop",1);
          else if ( all[i]->query("defense_bonus")||
                    all[i]->query("armor_class") ) all[i]->set("need_drop",1);
          else if ( all[i]->query("weapon_class") ) all[i]->set("need_drop",1);
          else if ( !(all[i]->query("prevent_get")||
                      all[i]->query("prevent_drop")) ) all[i]->set("need_drop",1);
          if ( all[i]->query("need_drop") ) {
             all[i]->move(SAREA"temp_room1");
             if (all[i]->query("name")!="magic cube") all[i]->remove();
          }
       }    
    }
}
int do_cant(string arg)
{
    write("正当你想要做这动作，忽然头感到一阵剧痛，令你无法控制你的行动！！\n");
    return 1;
}