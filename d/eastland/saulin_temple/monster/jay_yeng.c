#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/mob_special";

int be_released;

void create()
{
        ::create();
        set_level(18);
        set_name( "jay yeng", "觉远大师" );
        add ("id", ({ "monk","jay","yeng" }) );
        set_short("觉远大师");
        set("unit","位");
        set_long(@C_LONG
你眼前的这位中年僧人长的斯斯文文的，但他肩上挑著两个大铁桶不说
脚上还拖著两条粗大的铁□，最奇怪的是他竟然从山下把水挑到山上的
井里。虽然他挑著装满水的大铁桶，在山路上走起来却如履平地，想必
内功必是十分的惊人。他的嘴里一直喃喃著什麽经书什麽的，或许你可
以跟他问个清楚。
C_LONG
        );
        set( "inquiry", ([
             "book" : ({ @BOOK
阿弥陀佛 ! 贫僧真是倒霉 ! 那日轮到贫僧值守藏经阁，正好有一
		位昔日老友天竺僧释法蓝前来，我俩相谈甚欢。当晚达摩院首座
		来查经，有一本楞枷经竟然遍寻不著，楞枷经虽然很普遍，但是
		那本经书乃是达摩老祖自天竺携来的，意义实在不同凡响。现在
		糟了，老纳受罚不打紧，拖累了老友也被监禁在寺，真是太过意
		不去了。唉! 老纳若能回藏经阁(library) 一趟，一定能查出什
		麽蛛丝马迹。
BOOK
			}), "library" : ({@LIBRARY
对了，你可以帮贫僧回去查查吗？藏经阁内有两扇长窗，只要把
              两扇窗同时一拉(pull)就会出现一道楼梯了，你可以帮我到密阁
              查查... 但是... 要怎麽进入藏经阁呢？阁外守卫那麽严密，要
              进去除非是隐形(invisible) 了，那怎麽可能呢？可是偏偏有人
              能偷的了书去 ... 唉 ～～

觉远大师又开始自言自语，摇摇头好像忘了你的存在，随著一阵阵喃喃声，
他又挑著铁桶走了。
LIBRARY
			}),
		]));

        set("alignment",1400);
        set("wealth/gold", 10);
        set("gender", "male");
        set("race", "human");
        set("chat_chance",10);
//	set("moving",1);
//	set("speed",25);
//	set("patrol",({"north","north","north","north","south",
//		"south","south","south",}));
        set_perm_stat("str", 25);
        set_perm_stat("dex", 28);
        set_perm_stat("int", 20);
        set("max_hp", 700);
        set("hit_points", 700);
        set("max_fp", 2000);
        set("force_points", 2000);
        set("special_defense", ([ "all" : 40, "none" : 50, "monk":20 ]) );
        set("aim_difficulty", ([ "critical" : 60, "vascular" : 60 ]) );
        set_natural_weapon( 25, 20, 40 );
        set_natural_armor( 70, 30 );
        set_skill("chain",100);
        set ("chat_output",({@C_LONG
觉远说道：不知道是谁偷走了那本愣枷经，方丈要我在这里挑水反省。
C_LONG
        }));
        setenv("C_MIN", "$N挑著两个大水桶走了过来" );
        setenv("C_MOUT", "$N挑著两个大水桶向$D离开" );
	wield_weapon( SAULIN_OBJ"coul" );
        equip_armor( SAULIN_OBJ"cloth4" );
        equip_armor( SAULIN_OBJ"necklace" );
//	equip_armor( SAULIN_OBJ"armband1" );
 set("special_attack",(["damage_type" : "energy","main_damage" : 30,
                                "random_dam" : 20 , "hit_rate" : 25]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"\n觉远将两个大桶互相撞击，发出「当」的一声巨响，把你震的晕头转向 ...\n\n");
set("c_room_msg","觉远用他的大桶互相撞击，把");
set("c_room_msg2", "震的晕头转向 ...\n");
}

void init()
{
    add_action( "do_release","release");
}

int do_release(string arg)
{
    if ( !arg || ((arg != "Jay yeng") && (arg!= "yeng") && (arg!= "jay yeng")))
    {
        tell_object(this_player(),"你想要释放谁?\n");
        return 1;
    } 
    if ( this_player()->query_temp("book_quest/step") != 5 )
    {
        tell_object(this_player(),@MSG1
觉远说：施主您的好意, 老衲心领了!
不过, 没有方丈法旨, 老衲不敢擅离。
MSG1
);
        return 1;
    }
    if ( be_released == 1 )
    {
        tell_object(this_player(),
        "咦! 奇怪了! 刚刚已经有人传过方丈的法旨了。莫非你是在骗我吗?");
        return 1;
    }

    tell_object(this_player(),@MSG2
觉远感激地说道：多谢施主, 为老衲洗清这桩冤枉。
                老衲终於又可以再次加入早课、晚课和诵经的行程了
                对了! 说到诵经.....

你看到觉远不管三七二十一地开始喃喃自语了起来, 听起来好像是在诵经。
MSG2
                );
    if (this_player()->query("force_effect") < 4) {
       tell_object(this_player(),
       "\n你听了觉远的话, 心中若有所悟, 似乎发现到了武学中新的天地.....\n\n");
       this_player()->set_temp("block_command",1);
       call_out("check_gonfus", 20, this_player());
                                                  }
     this_player()->add("alignment",1000);
     this_player()->set("book_quest_finish",1);
     be_released = 1;
     set("chat_chance",0);
     return 1;
}

void check_gonfus()
{
	object* eqs;
	int i;

       if (this_player()->query("monk_score") > 1800) {
       if (this_player()->query("force_effect") == 3) {
          tell_object(this_player(),@MSG3
过去所学的种种, 都在你的脑海中如走马灯般重现, 你”啊！”的一声！
你顿悟了九阳神功的至理, 你的全身真气迅速地在你的体内流通, 循环了
一十八个大周天後, 你已练成了九阳神功！
MSG3
);
          this_player()->set("force_effect",4);
          this_player()->set("force_points",this_player()->query("max_fp"));
                                                       }}
       else {
          tell_object(this_player(),@MSG4
”唉！”你长叹一声, 觉远所念的每一句话, 对你来说都太深奥了,
你实在是无法体会, 心想要回去好好地再练练功夫。
MSG4
);
            }
      tell_room(environment(this_player()),
          "\n你看著觉远自顾自地在念念有词，渐渐走远了! \n");
       this_player()->set_temp("block_command",0);
       eqs=all_inventory(this_object());
        this_object()->delete("weapon1");
        for ( i=sizeof(eqs)-1 ; i >-1 ; i--) {
                if (eqs[i]->query("equipped")) eqs[i]->delete("equipped");
                eqs[i]->remove();
        }
       remove();
}

