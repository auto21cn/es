#include "/d/noden/elf/layuter.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(7);
        set_name( "icers", "艾瑟斯" );
        set_short( "艾瑟斯");
        set("unit","位");
        set_long( @LONG
艾瑟斯是一位才气纵横的雕刻家，在他的一生中创造了不少
不朽的杰作，例如广场上的希纳斯雕像，就是他花了五年的时光所
完成的旷世巨作，但是他最近陷入创作的低潮，他没有创作的灵感
与欲望，正到处走来走去，好像很无助的样子，不知你是否可以帮
助(help)他。
LONG
        );
        set_perm_stat("str", 10);
        set_natural_weapon(10, 6, 10);
        set_natural_armor( 30, 14 );
        set ("gender", "male");
        set ("race", "elf");
        set_c_verbs(({"%s用他的雕刻刀向%s刺去","%s用他的脚向%s踢去","%s用他的拳头向%s攻击"}));
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        wield_weapon(LWEAPON"guard_sword");
        equip_armor(LARMOR"wind_cloak");
        equip_armor(LARMOR"wind_boots");

        set("inquiry",([
           "help": 
                   "我心爱的雕像(statue)不见了，它是我心灵的寄托，没有了它我不知道\n"
                   "活在这世上有何意义，而我以前如泉涌般敏捷的灵感也因而消失殆尽，你是否可以帮\n"
                   "我找回它呢?\n",
           "statue": 
                   "那是高25公分石雕作品,是我为我太太□□□所刻的雕像,还记的那天是她\n"
                   "28岁生日，当我把雕像放在她的面前时，她喜悦地抱著雕像旋转飞舞，仿如一个快乐 \n"
                   "的小天使，我永远也忘不了那一夜的情景，希望你帮我找回来，我想一定是某人偷(steal)\n"
                   "了他。\n ",
           "steal": 
                   "最近村里时常掉东西，我想一定有人在背後作怪，但是我们各处都找遍了\n"
                   "，就是没有找到任何的蛛丝马迹，本来我们想进入恶魔迷宫搜查，但是从迷宫传出的\n"
                   "怪物吓退了我们。唉!雕像你到底在哪里。\n"
      ]));
}

int accept_item(object player, object ob)
{
    if( !ob || !(ob->query("get_my_statue")) ) return 0;
	if( (string)ob->query("killer") != (string)player->query("name") ) {
		tell_object(player,
			"非常感谢你为我带回我心爱的雕像，我又有创作之心了，愿神永远保护你\n"
			"如果他日有空，请顺便与那位找回雕像的英雄同来，让我好好谢谢你们!!\n"
			 );
		tell_room(environment(player), 
			"艾塞斯把他心爱的雕像收藏起来。\n");
		ob->remove();
		return 1;
	}

    tell_object(player,
       "非常感谢你为我带回我心爱的雕像，我又有创作之心了，愿神永远保护你。\n"
       );
    if( (int)player->query_quest_level("icers") < 1 ) {
       player->finish_quest("icers",1);
       player->gain_experience(10000);
       tell_object(player,
          set_color("[你完成雕刻家艾瑟斯的任务，得到 10000 点经验值]\n","HIY",player));
       }
       ob->remove();
       tell_room(environment(player), 
           "艾塞斯把他心爱的雕像收藏起来。\n");
	return 1;
}
