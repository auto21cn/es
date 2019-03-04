#include "farwind.h"
#define MARRIAGE_FILE "d/noden/data/marriages.o"

inherit ROOM;

string *couples, *pending;
int i, j, numcouples, numpending;
string str ;


void create()
{
        ::create();
        seteuid(getuid()) ;
    set("objects", ([ "priest" : FARWIND"monster/nolen" ]) );
//    set("objects", ([ "priest" : "/u/e/elon/nolen" ]) );
    reset() ;
        set ("light", 1) ;
    set_short("教堂");
    set_long(@TEXT
这是一间小小的教堂, 地上铺著光滑的石砖, 从天花板上照下来的光使得
地面看来闪闪发亮. 两边墙上挂了一些画及各式浮雕, 其中一片墙上刻著历年
来在这个世界上结为夫妻的人名. 正前方有一个讲台, 旁边立了一个告示牌(sign).

TEXT
    );
        set("exits", ([ "south" : FARWIND"ebazz" ]) );
    set("item_desc", ([
//    "wall" : "@@list_couples",
    "sign" : @SIGN
查看已结过婚的人:

couples

如何结婚:
首先, 找个结婚对象. 然後找个公证人,(注: 跟据这个世界的某些不成文的规
订, 我们会建议您请一个巫师级的人物当公证人, 不过如果您坚持不要找巫师
当证婚人, 我们也不会反对).找齐观礼人後由公证人输入:
marry <男方> <女方>
这里的牧师就会为您主持婚礼了.

注: 要取消婚礼... 用 cancel 指令.
    只有公证人可以取消一场婚礼, 如果公证人不在场则任何人都可以取消.

如何离婚:
    必须请一位巫师级的人物公证离婚, 由他(她)输入:

    divorce <男方> <女方>
这里的牧师就会为您主持婚礼了.
SIGN
    ]) );
//    numpending = 0 ;
//    pending = allocate(10) ;
        str = read_file(MARRIAGE_FILE,1,1) ;
        if (!str) {
                numcouples = 0 ;
                couples = allocate(1) ;
                return ;
        }
        if (sscanf(str,"%d",numcouples)!=1) {
        write ("嗯... 墙上的字有点模糊不清, 你最好跟教堂工作人员讲一下!\n") ;
                return ;
        }
        couples = allocate(numcouples+1) ;
        for (i=0;i<numcouples;i++) {
                str = read_file(MARRIAGE_FILE,i+2,i) ;
                sscanf (str,"%s\n",couples[i]) ;
        }
        set("busy",0);

}
void divorce_end()
{
    set("busy",0);
}
void init()
{
    add_action("setup_marriage", "marry");
    add_action("cancel_marriage", "cancel");
    add_action("list_couples", "couples");
    add_action("setup_divorce", "divorce");
}

int cancel_marriage()
{
    object ob;
    if (!query("witness")) return notify_fail("没有正在进行的婚礼!\n");
    ob=present(query("witness"),this_object());
    if ((string)this_player()->query("name")!=(string)query("witness"))
        {
        if (ob) {
                return notify_fail("你没有权取消这场婚礼!\n");
        }
    }
    set("witness");
    tell_room(environment(this_player()), "婚礼取消了!!\n", this_object());
    // clean up everything..
    ob=present("nolen",this_object());
    ob->set("husband");
    ob->set("wife");
    ob->set("witness");
    ob->set("step",1);
    ob->set("wait");
        set("busy",0);
    return 1;
}

int setup_marriage(string str)
{
    string n1,n2,n3;
    object ob1, ob2;
    if (!str) return notify_fail("语法: marry <男方> <女方>\n");
    if ((int)query("busy") == 1) return 
      notify_fail("有人正在结婚或离婚... 请稍等一会!\n");
    if (sscanf(str,"%s %s",n1,n2)!=2) return
        notify_fail("语法: marry <男方> <女方>\n");
    n3=(string)this_player()->query("name");
    if ((n3==lower_case(n1)) || (n3==lower_case(n2))) return
        notify_fail("帮自己证婚? 这麽可怜, 没人要帮你证婚啊?\n"+
            "去去去... 路上抓个人来不会啊.\n");
    ob1=present(lower_case(n1),this_object());
    ob2=present(lower_case(n2),this_object());
    if ((!ob1 || !ob2)) return notify_fail("人没到齐结什麽婚啊?!\n");
    if (ob1->query("spouse") || ob2->query("spouse")) return
        notify_fail("嗯..... 两人之中有一个已婚了... 还是不要...\n");
    if (ob1->query("npc") || ob2->query("npc")) return
        notify_fail("你只能帮玩家证婚.\n");
    if ( ((string)ob1->query("class") == "monk" && (int)ob1->query("18brass") != 2) ||
       ((string)ob2->query("class") == "monk" && (int)ob2->query("18brass") != 2) ) return
        notify_fail("和尚不能结婚! \n");
    ob1=present("nolen",this_object());
    if (!ob1) return notify_fail("那个... 牧师今天放假. 改天吧!\n");
    ob1->set("husband",lower_case(n1));
    ob1->set("wife",lower_case(n2));
    ob1->set("witness",this_player()->query("name"));
    set("witness",this_player()->query("name")); // for cencel
        set("busy",1);
    return ob1->perform_marriage();
}

int setup_divorce(string str)
{
    string n1,n2,n3;
    object ob1, ob2,me,nolen;
    seteuid(getuid());
    me=this_player();
    if ( !wizardp(me) ) return notify_fail("离婚必须由巫师为见证人!\n");
    if (!str) return notify_fail("语法: divorce <男方> <女方>\n");
    if ((int)query("busy") == 1) return 
      notify_fail("有人正在结婚或离婚... 请稍等一会!\n");
    if (sscanf(str,"%s %s",n1,n2)<2) return
        notify_fail("语法: divorce <男方> <女方>\n");
    n3=(string)this_player()->query("name");
    n1=lower_case(n1);     n2=lower_case(n2);
    ob1=present(n1,this_object());
    ob2=present(n2,this_object());
    if(!ob1 && ! ob2) return notify_fail("没人要离婚啊.... \n");
    nolen=present("nolen",this_object()); 
    if (!nolen) return notify_fail("那个... 牧师今天放假. 改天吧!\n");

    if(!ob1)
      if( lower_case(ob2->query("spouse"))==n1 )
       if(file_size("/data/std/connection/"+n1[0..0]+"/"+n1+".o")<0) 
       {
           tell_object(ob2,"原来配偶死了, 熬不住了?\n");
           tell_object(ob2,"好吧， 就完成你的心愿吧!\n");
           shout(ob2->query("c_name")+"自从丧偶后，欲火中烧, 终于熬不住要离婚了!!!\n");
           tell_object(ob2,"好了, 你的心愿完成了!\n");
           ob2->delete("spouse");
           return 1;
        }
      else  return notify_fail("夫妻双方都健在的必须同时到场! \n");
    
    if(!ob2)
      if( lower_case(ob1->query("spouse"))==n2 )
       if(file_size("/data/std/connection/"+n2[0..0]+"/"+n2+".o")<0) 
       {
           tell_object(ob1,"原来配偶死了, 熬不住了?\n");
           tell_object(ob1,"好吧， 就完成你的心愿吧!\n");
           shout(ob1->query("c_name")+"自从丧偶后，欲火中烧, 终于熬不住要离婚了!!!\n");
           tell_object(ob1,"好了, 你的心愿完成了!\n");
           ob1->delete("spouse");
           return 1;
        }
      else  return notify_fail("夫妻双方都健在的必须同时到场! \n");

    if(!ob1 || !ob2) return notify_fail("你是不是敲错名字了? \n");
    if (! ob1->query("spouse") || ! ob2->query("spouse")) return
        notify_fail("喂..... 还没结婚就想离婚?\n");
    if(lower_case(ob1->query("spouse"))==n2 && lower_case(ob2->query("spouse"))==n1)
    {
      if(ob1->query("gender")=="male") 
      {
        nolen->set("husband",n1);
        nolen->set("wife",n2);
      }
      else
      {
        nolen->set("husband",n2);
        nolen->set("wife",n1);
      }
      nolen->set("witness",me->query("name"));
      nolen->set("male_agree",1);
      nolen->set("female_agree",1);
      set("busy",1);

      return nolen->perform_divorce();

    }
    else return notify_fail("你们俩可不是夫妻哦! \n");
    return 1;
}


int list_couples()
{
        int i ;
        string s1, s2, date ;

        if (numcouples==0) {
        write("现在并没有任何正式登记的夫妻 ....可怜喔...\n");
        return 1;
    }
        for (i=0;i<numcouples;i++) {
                sscanf( couples[i],"%s-%s %s",s1, s2, date);
                write( i + "." +s1+" 和 "+s2+" 於 "+date+" 结婚.\n");
        }
    return 1;
}

int marriage_done(string n1, string n2)
{
        seteuid(getuid());
    shout("你听到远风镇的教堂钟声欢欣地当当齐响 .... \n"+
          "路人们都欢欣唱道：「恭喜这对新人 !! 祝福 "+capitalize(n1)+" 和 "+capitalize(n2)+
         " 永远幸福快乐 !!」\n");
    couples[numcouples] = n1+"-"+n2+" "+ctime(time());
        numcouples++;
        set("witness");
        set("busy",0);
        rm(MARRIAGE_FILE) ;
        write_file(MARRIAGE_FILE, numcouples+"\n") ;
        for (i=0;i<numcouples;i++)
                write_file (MARRIAGE_FILE, couples[i]+"\n") ;
        return 1;
}
