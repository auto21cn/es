#include "../echobomber.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
    set_level(16);
    set_name("the older Annow","安洛长老");
    add("id",({"older","annow"}) );
    set_short("the older Annow","安洛长老");
	set_long(
@C_LONG
一个睿智的长老,似乎无所不知的样子.据说他曾经穿梭时空,而且到过地狱,但是假使
你问他的话, 他也只是笑一笑而不回答你
C_LONG
	);
    set("alignment",880);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "个" );
    set_perm_stat( "dex",19);
    set_perm_stat( "str",14);
    set_perm_stat( "int",26);
    set_perm_stat( "con",17);
    set_perm_stat( "piety",27);
    set_perm_stat( "karma",16);
	
    set ("max_hp",390);
    set ("hit_points",390);
    set ("wealth", ([ "gold":30]) );
    set_natural_weapon(33,15,30 );
	set_natural_armor( 65 ,30 );
    set ("weight", 350);
    
    set( "inquiry", ([
         "crystalball" : "@@ask_crystalball",
         "muse" : "@@ask_muse",
         "trouble":"@@ask_trouble",
         "chichikair":"@@ask_chichikair",
         "morr":"@@ask_morr",
         "ruin":"@@ask_ruin",
         "tower":"@@ask_tower",
         "queen":"@@ask_queen",
         "bell":"@@ask_bell",
         ]) );
    set("special_defense", (["all":33,"none":20]) ); 
    set ("aim_difficulty",(["vascular":20]) );
    set( "tactic_func", "cast_spell");
}

void ask_crystalball(object who)
{
     tell_object( who ,
       "安洛说:那颗魔法水晶球,是提供著房子飘浮的能源球.\n"
       "此外你也可以藉由著它离开这个地方.\n"
       );    
     return;  
}

void ask_cisklyph(object who)
{
     tell_object(who,
     "一个喜爱探险的流浪汉, 我们曾经一起探险邪恶的血湖, 九死一生的逃\n"
     "了出来, 而建立起我们之间良好的友谊. 喜爱冒险的他现在大概在古代\n"
     "遗迹中寻找秘密吧.\n"
);
     return; 
}

void ask_muse(object who)
{
     
     tell_object(who,
                 "缪思泉,诗人梦想的地方,听说能够给与人无穷尽的灵感.\n"
                 "我也找寻它很久了.....\n"
                 "而我的一个好朋友希斯克利夫(Cisklyph), 为了这个秘\n"
                 "密也前往传说中的古代废墟(ruin)了.\n"
                 );
     return;
}
void ask_queen(object who)
{
     tell_object(who,"可怜的皇后, 全国的人民都为了她在担心著\n");
}
void ask_trouble(object who)
{
     tell_object(who,
                 "安洛说: 有一个很大的麻烦正困扰著我们的村庄,但是知道这件事的人不多.\n"
                 "一个疯狂的矮人魔法师奇奇凯尔(chichikair),不知道从那里唤来一些幻影 \n"
                 "怪物,便自以为非常的了不起,竟然想要攻击死亡大地红色魔法高塔里的大巫\n"
                 "妖怀尔,破坏矮人与高塔数百年的和平 ,一群巨人已经够头痛了,若再加上高\n"
                 "塔(tower)里的那些邪恶魔法师,我不敢想像会有甚麽後果....."
                 ); 
     return;            
}

void ask_chichikair(object who)
{
     tell_object(who,
                 "安洛说: 疯狂的矮人魔法师奇奇凯尔,原本也是一名善良的好人,但是自从他\n"
                 "的从小到大一起长大的好友法拉第死了以後,他的性情大变,疯狂的研究起邪\n"
                 "恶的暗黑魔法,而他的同门摩儿知道了这情况,也千里迢迢地来到这里劝阻他\n"
                 ",但是奇奇凯尔却失踪了.摩耳说他隐藏在一个神秘的地方,但确实的地点并无\n"
                 "法得知,只能大概知道在矮人迷宫的外面.你应该到去找找看\n"
                 );
     who->set_explore("deathland#29"); 
     return;            

}

void ask_morr(object who)
{
     tell_object(who,
                 "一个女妖精魔法师,魔法高强,喜好安静的生活,所以她把自己的住所用魔法障壁\n"
                 "封了起来,以避免外人的打扰,想要见到她要一点勇气才行.\n"
                 );
}

void ask_ruin(object who)
{
     tell_object(who,
                 "矮人迷宫中里有一个很大的秘密. 听说有个神秘的古代遗迹隐藏於某个地方, \n"
                 "但是没有几个人能够发现它的位置. \n"
                 "听说很久以前一个矮人探险家曾经发现它的位置, 但是他却在与巨人的战争中\n"
                 "牺牲了..\n"
                 );
}
void ask_bell(object who)
{
     object *items;
     int i;
      
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) {
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/explorer_bell"))
             {
             tell_object(who,
             "安洛看了一下你黑盒子的铃当後说:\n"
             "没错: 这就是伟大探险家的铃当, 记得他曾经告\诉\我说, 这个铃当\n"
             "能够指引你到达古代遗迹去. 只要我加上适当的咒语就可以用了.\n"
             "安洛口中开始念念有辞.....\n...\n..\n.......\n..\n.....\n.\n...\n"
             "................\n.\n....\n"
             "过了数分钟後,安洛把铃当还给你并且说:\n"
             "去吧! 你的旅程才刚开始.\n"
             );
             items[i]->set("quest_action/invoke_bell",1);
             who->set_explore("deathland#23");
             if ( (int)who->query_quest_level("queen_smile") < 1 )
               who->finish_quest("queen_smile",1);
             return;
             }
       }
     tell_object(who,
     "你想问什麽铃当??\n"
     );
     return;  
}

void ask_tower(object who)
{
     tell_object(who,
                 "红色魔法高塔,他们似乎已经很久没有甚麽动静了,但是他们\n"
                 "的魔法实在是非常的可怕,由其是大巫妖怀尔,一个十分阴沉\n"
                 "的不死生物,据说他是邪神Yang的唯一传人,他的魔力没有人\n"
                 ",应该说是没有活著人曾经见到过,像那个繁华一度的兰斯城\n"
                 ",只因得罪了他,就这麽整个城沉入海底了.所以,谁愿意去招\n"
                 "惹这个魔王呢?\n"
);
}

int cast_spell()
{
    object victim;
    string name,c_name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    c_name= victim->query("c_name");
    
    if( random(10) < 6 ) {
      tell_room( environment(this_object()), 
        "\n\n安洛大叫:地狱之火........\n" );
      victim->receive_special_damage("fire", 14+random(6));
      return 0;
    }
    if( (this_object()->query("hit_points")<180) && (random(100)<50) ) {
      tell_room( environment(this_object()), 
        "安洛使用天地之气医疗他自己。\n" 
      );
      this_object()->receive_healing(35+random(30));
      return 1;
    }
    
    return 0;
}

