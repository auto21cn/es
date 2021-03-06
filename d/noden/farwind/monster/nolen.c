#include <mudlib.h>
#include "../farwind.h"
inherit MONSTER;

int perform_marriage();
int perform_marriage2();
int perform_marriage3();
int perform_divorce();
void create()
{
        ::create();
    seteuid(getuid());
        set_level(5);
        set("exp_reward",0);
        set("race","human");
        set_name("Nolen","诺伦");
        set_short("牧师诺伦");
        set_long(@TEXT
在你面前的是一个身形高大, 看起来跟本不像牧师的牧师. 多年的冒
险经验告诉你, 他是因为要躲某人的追杀才在这里当牧师的.
不过话又说回来... 既然他在这里了, 你要结婚也可以找他主持.

TEXT
        );
        set("max_tp",1500);
        set("talk_points",1500);
        set("no_attack",1);
        enable_commands();
        set("wait");
    set("step",1);
    set("husband");
    set("wife");
    set("witness");
    set("male_agree",0);
    set("female_agree",0);

}

void init()
{
        ::init();
        add_action("wait_answer","answer");
        add_action("do_nod","agree");
        add_action("do_shake","refuse");

}

int perform_marriage()
{
    string n1,n2;
        object ob;
    n1=capitalize((string)query("husband"));
    n2=capitalize((string)query("wife"));
    ob=present((string)query("husband"), environment(this_object()));
    if (!ob) {
        command("say 哈... 笑死人了, 新郎临阵脱逃啊?!?");
        command("shake");
        command("say 罢了罢了... 下次吧!\n");
        set("husband");
        set("wife");
        set("witness");
        set("wait");
        set("step",1);
        return 1;
    }
    command("say "+n1+", 你愿意娶"+n2+"为妻, 并答应要好好照顾她,");
        command("say 不论经历多少 reboot, crash 或 lag, 并无条件地帮她接雷,"); 
        command("say 赚钱供她花, 保护她不受伤害吗?");
    tell_object(ob, "诺伦回头对你说: 请回答(answer) Yes 或 No.\n");
    set("wait",lower_case(n1));
        return 1;
}

int perform_marriage2()
{
    string n1,n2;
    object ob, ob1;
    n1=capitalize((string)query("husband"));
    n2=capitalize((string)query("wife"));
    ob=present((string)query("wife"), environment(this_object()));
    ob1=present((string)query("husband"), environment(this_object()));
    if (!ob1) {
        command("say 哈... 笑死人了, 新郎临阵脱逃啊?!?");
        command("shake");
        command("say 罢了罢了... 下次吧!\n");
        set("husband");
        set("wife");
        set("witness");
        set("wait");
        set("step",1);
        return 1;
    }
    command("say "+n2+", 你愿意嫁给"+n1+", 陪他渡过 reboot, crash 或 lag.");
    command("say 帮他花钱, 收集装备吗?");
    tell_object(ob, "诺伦回头对你说: 请回答(answer) Yes 或 No.\n");
    set("wait",lower_case(n2));
        return 1;
}

int perform_marriage3()
{
    string n1,n2,n3;
    object ob, ob1, ob2;
    n1=capitalize((string)query("husband"));
    n2=capitalize((string)query("wife"));
    n3=capitalize((string)query("witness"));
    ob=present((string)query("witness"), environment(this_object()));
    ob1=present((string)query("husband"), environment(this_object()));
    ob2=present((string)query("wife"), environment(this_object()));
    if ((!ob) || (!ob1) || (!ob2)) { //anyone of them is missing
        command("say 咦... 人不见了还结什麽婚啊.. 罢了罢了..");
        return 1;
    }
    if (wizardp(ob)) { // witness is a wizard
    command("smile");
    command("say 那麽在公证人"+n3+"及大家的面前, 我宣布你们正式成为夫妻!");
    command("shout "+n1+" 跟 "+n2+" 在巫师的祝福下结为夫妻了, 大家祝福他们!!!!!");
    command("say "+n1+", 你可以吻新娘了!\n");
    command("grin");
    tell_room(environment(this_object()),
    "诺伦突然跳起来, 抱起新娘猛亲.\n",this_object());
    command("hold "+n2);
    command("kiss "+n2);
    command("kiss "+n2);
    command("lkiss "+n2);
    command("say 哈.. 不过我先了.\n");
    }
    else {
    command("grin");
    command("say 照 ES 的规矩, 没有巫师当公证人的婚礼都算私奔.");
    command("say 不过呢, 既然你们这麽相爱, 等不及了...");
    command("grin");
    command("say 那麽在公证人"+n3+"及大家的面前, 我宣布你们正式成为夫妻!");
    command("shout "+n1+" 跟 "+n2+" 私奔了喔!!!!!");
    command("say "+n1+", 你可以吻新娘了!\n");
    }
    command("grin");
    command("say 祝你们幸福!\n");
    command("shout 哇... 火辣辣的镜头!!!");
    set("husband");
    set("wife");
    set("witness");
    set("wait");
    set("step",1);
    ob1->set("spouse",n2);
    ob2->set("spouse",n1);
        FARWIND"church"->marriage_done(n1,n2);
    return 1;
}


int wait_answer(string str)
{
        if (!query("wait")) {
    tell_room(environment(this_player()),(string)this_player()->query("c_name")+
    "嘀嘀咕咕地不知道在跟牧师说什麽.\n",({this_player(), this_object()}));
    command("?");
        return 1;
        }
        if ((string)this_player()->query("name")!=query("wait"))
        {
    tell_object(this_player(),"你说道: 我愿意!\n");
    tell_room(environment(this_player()),(string)this_player()->query("c_name")+
    "说道: "+"我愿意!\n",({this_player(), this_object()}));
    command("slap "+(string)this_player()->query("name"));
    command("say "+capitalize((string)this_player()->query("name"))+", 我不是问你!");
        return 1;
        }
    if (!str || member_array(lower_case(str), ({"yes","y"})) == -1)
        {
        tell_object(this_player(),"你想了一会, 还是不要吧.\n");
        tell_room(environment(this_player()),
        (string)this_player()->query("c_name")+"面有难色, 说道: "+
        "嗯... 这个... 我想还是算了.\n",({this_player(), this_object()}));
        command("kick "+(string)this_player()->query("name"));
        command("say 决定好再来! 没事不要烦我.. 小心我 Z..A..P 你喔!");
        command("grin");
    set("wait"); // clear wait stat
        return 1;
        }
    set("wait"); // clear wait stat
    tell_object(this_player(),"你说道: 我愿意!\n");
    tell_room(environment(this_player()),(string)this_player()->query("c_name")+
    "说道: "+"我愿意!\n",({this_player(), this_object()}));
    if ((int)query("step")==1) { // ask the girl
        perform_marriage2();
        set("step",2);
        return 1;
    }
    if ((int)query("step")==2) { // here we go
        perform_marriage3();
        set("step",3); // set to 3 until finish this
        return 1;
    }
    return 1;
}
void divorce_end()
{
    set("husband");
    set("wife");
    set("witness");
    set("male_agree",0);
    set("female_agree",0); 
    FARWIND"church.c"->divorce_end();
 
}

int perform_divorce()
{
      command("say 你们真的要离婚吗? ");
      command("say 你们要慎重考虑一下, 到底是同意(agree),还是拒绝(refuse)?");

      return 1;
}

int do_shake(string str)
{
    object ob1,ob2,wiz,me;
    string n1,n2;
    if((int)query("male_agree")==0 || (int)query("female_agree")==0) return 0;
    me=this_player();
    n1=(string)query("husband");
    n2=(string)query("wife");
    if(n1!=me->query("name") && n2!=me->query("name"))
    {
       command("slap "+(string)me->query("name"));
       command("say "+(string)me->query("c_name")+", 我不是问你!");
       return 1;        
    }
    if(n1==lower_case(me->query("name")) ) 
    {
       command("say "+capitalize(n1)+" 不同意离婚, 离婚失败!");
    }
    else
    {
       command("say "+capitalize(n2)+" 不同意离婚, 离婚失败!\n");
    }
    command("kick");
    command("spit");
    command("say 没准备好就别来烦我, 他XX的!");
    divorce_end();
    return 1;
}
int do_nod(string str)
{
    object nolen,ob1,ob2,wiz,me,this_room;
    string n1,n2;
    if((int)query("male_agree")==0 || (int)query("female_agree")==0) return 0;
    me=this_player();
    n1=(string)query("husband");
    n2=(string)query("wife");

    if(n1!=me->query("name") && n2!=me->query("name"))
    {
       command("slap "+(string)me->query("name"));
       command("say "+(string)me->query("c_name")+", 我不是问你!");
        return 1;        
    }
    if(n1==me->query("name") ) 
    {
       command("say "+capitalize(n1)+"同意了离婚!");
       if( query("female_agree") <= 1 )
         command("say 那么你呢, "+capitalize(n2)+"?");
       set("male_agree",2);
    }
    if(n2==me->query("name") ) 
    {
       command("say "+capitalize(n2)+"同意了离婚!");
       if( query("male_agree") <= 1)
         command("say 那么你呢, "+capitalize(n1)+"?");
       set("female_agree",2);
    }
    if(query("male_agree")>1 && query("female_agree")>1)
    {
       this_room=environment(this_object());
       wiz=present(query("witness"),this_room);
       ob1=present(n1,this_room);
       ob2=present(n2,this_room);
       if(!ob1 || !ob2 || !wiz)
       {
          command("say 人不全，无法继续下去!\n");
          divorce_end();
          return 1;
       }
       command("shout "+capitalize(n1)+"和"+capitalize(n2)+"离婚了!");
       if((string)wiz->query("name")=="moon")
command("shout "+"是不是"+capitalize(n2)+"迷上了风流倜傥的"+wiz->query("c_name"));
       else
command("shout "+wiz->query("c_name")+"为什么这么主动的做见证人, 是不是做了第三者!");
      
       ob1->delete("spouse");
       ob2->delete("spouse");
       divorce_end();
       return 1;
     }
     return 1;
}
