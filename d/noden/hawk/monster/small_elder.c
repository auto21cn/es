#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(12);
        set_name( "hawkman elder", "鸟人长老" );
        add ("id", ({ "hawkman", "elder" }) );
        set_short( "hawkman elder","鸟人长老");
        set("unit","位");
        set("alignment",500);
        set_long(@LONG
  身为鸟人族的长老，鸟人长老和鸟人族依武斗会所推选出来的领袖不一样的
是，他由多年的战斗经验，学到了一些特殊的战斗技巧。所以虽然看起来并不像
是一个强壮的战士，但决不是好欺负的。你又发现他腰间缠了条不起眼的鞭子，
不知是干啥用的，反正应该不是ＳＭ，不用太紧张。
    最近鸟人族似乎风波不断，鸟人长老不禁也是眉头深锁，你可以问问他在烦
恼些什麽，说不定你可以帮助(help)他喔。
LONG
        );
        set_perm_stat("str", 11);
        set_perm_stat("dex", 7);
        set_natural_weapon( 15, 10, 16 );
        set_natural_armor( 25, 10 );
        set ("gender", "male");
        set ("race", "hawkman");
        set("tactic_func","sp_tactic");
        set("max_hp",250);
        set("hit_points",250);
        set("special_defense",(["all":20,"none":10,"electric":40]));
        set("aim_difficulty",(["critical":10,"weakest":10,
                               "vascular":10,"ganglion":10 ])) ;
        set_skill( "parry",30 );
        set_skill( "dodge",50 );
        set_skill( "whip",80);
        set( "inquiry", ([
                "help" : "@@ask_help",
                        ]) );
}

void init()
{
        add_action("do_report","report");
}

int do_report()
{
        if (this_player()->query_temp("smore_box") == 5)
        {
                tell_object(this_player(),@LONG
长老说：你已经跟我说过了，我们大家都很感谢你。
LONG
                );
	return 1;
        }

        if (present("s_potion",this_object() ) &&
                this_player()->query_temp("smore_box") == 4)
        {
                tell_object(this_player(),@LONG
长老接过你的药瓶，仔细的看了许久，然後叹了一口气，对你说道:

谢谢你告诉我这个天大的秘密!!当年我早就怀疑阿道夫的实力能赢的了维多，只是
比赛的结果就是如此，我也不能说什麽。这些年来我们受制於阿道夫的淫威之下，
都是敢怒不敢言，幸亏有你这麽一位侠肝义胆的侠士才算解了当年之谜! 太好了，
我马上召开鸟人族大会，揭穿阿道夫的假面具，让他以後无法在鸟人族中作人！

长老转过头去，向身後的护卫吩咐了几句话，护卫点点头，就向外离去了。

接著鸟人长老带著你，穿过了重重地道，进入了鸟人族的禁地。

LONG
                );
                this_player()->set_temp("block_command",1);
                call_out("meeting_a",5,this_player() );
        }
        else if (!present("s_potion",this_object()) &&
                this_player()->query_temp("smore_box") == 4)
        {
                tell_object(this_player(),"长老说：『哦？那药水在哪啊？』\n\n" );
                return 1;
        }
        else if (this_player()->query_temp("smore_box") != 4)
                return 0;

        return 1;
}

void meeting_a()
{
        tell_object(this_player(),@LONG
你发现自己走进了一间非常古老的大厅，四周的墙都是由茅草所建。鸟人一群
群的走了进来，间歇著带有一阵阵谈论的声音。

鸟人长老清清喉咙..." 安静! 安静 !"

LONG
);
    call_out("meeting_0",5,this_player() );
}

void meeting_0()
{
    tell_object(this_player(),@LONG

四周都安静下来了.....

鸟人长老缓缓的将你所发现的药瓶展示给大家看，说" 这就是当年阿道夫所偷
用的禁药，就是用这个药物才打败了维多! 今天，我们就是要还维多一个公道
的! 阿道夫! 你还有什麽话好说!"

LONG
);
    call_out("meeting_1",10,this_player());
}

void meeting_1()
{
    tell_object(this_player(),@LONG
阿道夫脸上划过一抹的惊讶，但随即消逝，冷冷地笑笑，缓缓说道:
" 哼! 就拿一个小破烂瓶子，就要诬赖我是吗? 别以为你是长老我就怕你了! "
阿道夫指著你 "这! 这是谁啊? 不是鸟人族的人也来我们的禁地多管闲事? 找死!"

阿道夫说完就拔剑往你身上砍来!

正当千均一发之际，鸟人长老双手一伸，轻轻一拨就把阿道夫的剑挡下来!
鸟人长老目光炯炯的望著阿道夫说道:
" 阿道夫! 你这样作莫非是作贼心虚，杀人灭口吗? 有我在一切不可乱来 !"

LONG
);
    call_out("meeting_2",8,this_player());
}

void meeting_2()
{
    tell_object(this_player(),@LONG
柏尼丝也娇声说:
" 阿道夫，我很希望你是清白的，只是这些年来我始终无法了解你是怎麽打败维多
的，也许今天在这里，你可以当大家的面把事情澄清，现在出现了这瓶禁药，而且
刚刚族人也相继的发现裘拉根和雷多都不见了? 这些疑点未免太过蹊跷了吧? "

柏尼丝转过身来望著你 "对了，朋友，你还知道些什麽有力的证据吗? "

LONG
);
    call_out("meeting_3",5,this_player());

}

void meeting_3()
{
    tell_object(this_player(),@LONG
你站了出来，当著全鸟人族的面前朗声说道 :
" 各位亲爱的鸟人族朋友们! 阿道夫的走狗--雷多，跟裘拉根他们三人当年联合串
通好，让阿道夫服用了增强肌力及抗力的药物，打败了维多，然而这药却是你们鸟
人族的禁药，因为，他会让鸟人的翅膀硬化，飞不起来，也就是说....

    阿～道～夫～他～～他～现～在～根本就～～不～会～飞!!!  "

你话一说完，鸟人们开始蛊噪起来，纷纷的用不屑的眼神看著阿道夫!

LONG
);
    call_out("meeting_4",10,this_player());
}

void meeting_4()
{
    tell_object(this_player(),@LONG

阿道夫眼睛充满鲜红杀气，大叫" 说谎! 说谎! 不要相信他!!"

鸟人长老拿起火炬往地上一扔，火势沿著稻草顺势就烧了起来!
鸟人长老看了看阿道夫说:
" 现在，就是给你证明的机会了! "

鸟人长老把你一把抱起来，拍拍翅膀，你觉得身体有种奇怪的感觉，双脚竟离
开了地面..... 慢慢的，其他的鸟人也跟著飞到了空中，真是奇妙的感受!
只见阿道夫在那间审判室中惨叫，原来他真的飞不动了，看他被火焚烧的可怜
样子，在场却没有任何一位鸟人愿意下去解救他，可见他真的是作恶多端啊!

你听到火焰中传来一阵阵凄厉的惨叫声：『对不起～～～我错了～～～』，不
由得於心不忍，说到：『算了，放过他吧，你们还需要他的力量来抵御外族人
的侵掠呢。』
LONG
        );
    call_out("meeting_5",5,this_player() );
}

void meeting_5()
{
        tell_object(this_player(),@LONG

鸟人长老略一迟疑，点点头，说到：『在下次比武大会之前，还是让阿道夫先
暂代领袖职务吧，首恶裘拉根已经受到了应有的处罚，那就够了。』

长老手一挥，一阵大雨将熊熊大火浇熄，留下被烈火烧的奄奄一息的阿道夫，
两个守卫飞过去把阿道夫抱了起来带回城内。

鸟人长老带著你回到了村落。... ....

LONG
        );

        this_player()->move_player("/u/s/smore/hawk/room3-2","SNEAK");
        this_player()->set_temp("block_command",0);
        this_player()->set_temp("smore_box",5);
	call_out("ending",5,this_player() );
}

void ending()
{
	tell_object(this_player(),@LONG
长老对你说：感谢你为我们做了那麽多，听你说你找到了维多的坟墓，那麻
烦你再到维多的墓前，告诉他他的冤辱已经被你洗刷了。
LONG
        );
}

int ask_help()
{
        tell_object(this_player(),@LONG

鸟人长老叹了口气，说：
    最近真是流年不利啊，战争打的损伤惨重，看来阿道夫真不是个好的领
袖，可是偏偏他又赢了武斗大会。真希望维多能够回来重新领导鸟人族，不然看
来鸟人族就要败亡在我们这一代了。前一阵子听说维多的手下有回来过，却不幸
死在森林里，如果能找到他带回来的东西，说不定就能探听出维多的下落。
LONG
        );
        return 1;
}

int sp_tactic()
{
        object magics;
        int dam;
        if ( !(magics=query_attacker()) || (random(12)>3)) return 0;
        magics->set_temp("kill_elder",1);
        tell_room(environment(),
        "\n\n鸟人长老忽然用手中的长鞭紧紧的绞在对手的脖子上。\n",
        this_object() );
        dam = 10 + random(5);
        magics->receive_damage(dam);
        magics->block_attack(2);
        magics->set_temp("msg_stop_attack",
                "( 你被长鞭紧紧的勒住，失去一次行动的机会 )\n");
        return 1;
}

void die()
{
        object *attackers, elder;
        int i;
        tell_room( environment(this_object()),
        "鸟人长老大声狂笑： 唷呵呵....你还不错嘛 .... \n\n"
        "一阵狂风吹来，鸟人长老竟又站了起来\n"
        "鸟人长老大叫：见识一下我真正的实力吧\n\n"
        "只见鸟人长老似乎越长越高，全身的肌肉也都鼓了起来，再从身後拿出
几件防具穿上....\n\n"
        ,this_object() );
        elder = new("/u/s/smore/mob/elder.c");
        elder->move( environment(this_object()) );
        attackers = this_object()->query_attackers();
        for( i=0; i<sizeof(attackers); i++ )
                elder->kill_ob( attackers[i] );
        this_object()->remove();
        ::die(1);
}
