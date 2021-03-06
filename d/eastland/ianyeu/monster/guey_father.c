#include "../mad.h"

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "guey Father", "桂老爹" );
   add( "id", ({ "guey", "father" }) );
   set_short( "桂老爹" );
	set_long(
        "你看到一个状似痴呆, 面黄肌瘦的老头, 正独自怔怔地望著天空。\n"
        "而且你不时听到一种幽幽淡淡, 若有似无的叹息声。\n"
	);
   set( "race", "human" );
	set( "gender", "male" );
   set_skill( "dodge", 50 );
   set( "wealth/copper", 10 );
	set( "inquiry", ([
       "cut" : "去问我女婿吧!\n",
       "sheaumei" : "TEST\n",
       "sheaumei" : @DAUGHTER
唉 .... 我可怜的女儿 ........

我深深记得半年之前, 那个月色昏暗的夜晚 ........
小梅和女婿行完大礼, 并送走宾客之後; 老伴正忙著
收拾杯盘残肴, 而女婿却已醉卧於地, 老夫只好先去
安抚女儿。而当我甫至房前时, 竟见大门敞开, 女儿
倒卧於地! 於是急忙冲入房内探视小女, 可叹已无力
回天 ...............

但於踏入房门之际, 曾见一黑影跃窗而出, 其背影竟
彷佛一只大犬! 老夫真恨不得生吞此畜牲之心!!
大侠, 您能否助我完成此愿?
DAUGHTER
	]) );
}

int accept_item(object who,object item)
{
   object devil;

   if ( !item->query_cutted() ) {
         tell_room( environment(), 
@NOEAT
桂老爹喜道: 多谢大侠。
桂老爹拿起狼心欲一口吞下 ......
但很明显地, 他无法吞下它 ......
桂老爹叹道: 大侠, 您能再帮我切碎(cut)它吗?
NOEAT
   );
         command("give heart to "+who->query("name"));
         return 1;
             }
   item->remove();

     tell_room( environment(), 
@CHANGE
桂老爹喜道: 多谢大侠。
桂老爹拿起切碎的狼心一口吞下 ......

突然桂老爹面色狰狞, 大笑道: 哈 ...哈 ...哈 ......
那只畜牲终於死了! 那个可恨的家伙总是与我争夺猎物,
多谢你替我除去一大麻烦。而女儿其实是我杀的, 因为她
『抵死不从』, 不肯『孝敬』。至於你, 愚蠢的人, 下地
狱陪她们吧!

CHANGE
   );

   devil = new( IANMOB"devil" );
   devil->move(environment(this_object()));
   devil->kill_ob(who);
   this_object()->remove();
   return 1;
}
