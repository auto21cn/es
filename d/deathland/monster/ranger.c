
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	seteuid(getuid());
	set_name( "Moorth Ranger Cisklyph", "默尔斯流浪汉希斯克利夫" );
	add ("id", ({"ranger", "cisklyph"}) );
	set_short( "a moorth ranger Cishlyph ", "默尔斯流浪汉希斯克利夫" );
	set_long(@DESC
一个从默尔斯大陆流浪而来的流浪汉希斯克利夫, 他是一个多才多艺的人, 不仅是
个普通的流浪汉而已, 他还是个探险家, 科学家. 他的一生充满著传奇, 而且他的
知识更是非常的渊博.
但是他却是一个很自闭的人, 喜欢孤独地做研究. 孤独一人思考问题. 他的朋友并
不多,书本应该是他最好的朋友吧.
DESC
	);

    set("alignment",800 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "个" );
	set_perm_stat( "dex", 28 );
	set_perm_stat( "str", 19 );
	set_perm_stat( "int", 29 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 30);
	set_skill("dodge",99);
	set ("max_hp", 890);
	set ("hit_points", 890);
	set ("wealth", ([ "gold": 30 ]) );
    set_natural_weapon( 44, 15, 45 );
	set_natural_armor( 88, 35 );
    set ("weight", 400);
    set("special_defense", (["all":30,"none":25]) );
    set("aim_difficulty",([ "critical":35,"weakest":30,"vascular":35 ]) );
    set( "inquiry", ([
         "muse" : "@@ask_muse",
         "annow": "@@ask_annow",
         "ruin" : "@@ask_ruin",
         "cart" : "@@ask_cart",
         "statue": "@@ask_statue",  
           ]) );
    
}

void ask_statue(object who)
{
     tell_object(who,@MSG1
这些以东北角的雕像最为奇怪, 那些雕像的底部都有一个很深的洞. 但
是却无法了解到里面有甚麽? 我也试著丢一些东西下去, 但是只传来一
些奇怪的回音, 而其他的雕像也是奇怪的很..
MSG1
     );
     return;     

}

void ask_cart( object who )
{
     tell_object(who ,@MSG2
对的, 那些运矿车是我建造的, 我和矮人的长老安洛是好朋友, 当他向我提起
他们的矿坑采矿的速度太慢, 须要改进的时候, 我就义不容辞的帮他建造了那
个系统了. 
MSG2
     );
}

void ask_ruin(object who)
{
    tell_object(who ,@MSG3
这座遗迹我已经研究很久了, 这里的文明本来很发达的, 但是一夜之间却被邪
恶的大魔法师怀尔给毁灭了. 虽是如此, 还是有很多重要的文献留了下来, 其
中最重要的就是谬思泉的证实. 这些地下人的探险技术是一流的, 他们似乎已
经找到了谬思泉, 但是我翻遍了所有的书籍却无法找到详细的记载..........
还有这座城的地底似乎有著一些隐藏的房间, 但是我始终无法找到正确的位置
. 只知道城市四个角落的雕像似乎是关键的所在..
MSG3
    );
}
void ask_muse( object who )
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
           if (items[i]->query("quest_action/muse_filled")) {
           tell_object(who,@MSG4
你发现了谬思泉了, 很好, 这世上真的有谬思泉的存在.
传说中谬思泉有著很多神奇的\功\能. 根据这里的文献记载著.
当年有一场很大的火灾侵袭这个城市, 而当时莱特正好带著红
色的谬思泉回来. 一不小心莱特把泉水到洒在火上, 瞬间大火
熄灭掉了.
还有......
对不起我太噜苏了.总之谢谢你证实了谬思的存在.
MSG4
           );     
           who->set_explore("deathland#28");
           return;
           }
      tell_object( who, 
          "如果你发现谬思泉的话, 希望你能带一些泉水回来给我看.我会很感激你的.\n"
);
      return ;        
}

void ask_annow(object who)
{
      tell_object(who,"安洛长老, 一个有丰富知识的智者.我最好的朋友.\n");
      return ;
}

