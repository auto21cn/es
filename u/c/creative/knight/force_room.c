#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
    set_short("东方武术塔\心法房");
        set_long( @LONG_DESCRIPTION
这里是东方武术研究所的心法房,东方武术能以空手对会强悍的敌人和怪物
的原因是神秘内功,现在研究所终于可以为骑士学习基本的内功心法,以更好
的对抗敌人。心法房里面有一堵（wall）刻着内功心法，能否学到就要靠自
己的造化了。
LONG_DESCRIPTION
        );

    set("c_item_desc",([
         "wall":@WALL
墙後草草的写了几个字...
『杨家内功基础心法』  
你可以用(study basic) 学到此内功\心法。
注意∶还要练好基本内力技巧才会有内力  
WALL
         ,"wall":@BOOK
书皮上写著『杨家内功心法』  
只要大叫『万能的天神 请赐给我神奇的力量』(god help) 你将会学到此内功\心法。
注意∶内力值大小和 [所习心法] 及 [基本内功\] 有关 
BOOK
]));         
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/u/c/creative/workroom",
                 "up"     : "/u/b/boss/workroom"]));
                 reset();
}

void init()
{
 add_action("to_study","god");
 add_action("basic","study");
}



int basic(string arg)
{
  string class;

  class=(string)this_player()->query("class");
  if ( !arg || arg!="basic") return 0;
  else if ( class !="knight"){
     write("抱歉你不是本公会的人所以你不能学此心法\n");
     return 1;
                           }
 
        else if ((int)this_player()->query("force_effect")>=1){
write(
" 一个在一旁练功\的骑士看看你，大声的笑道 \n 
『你是白痴啊! 你已经学过基础心法或更好的心法了啦!!! 还闹!』\n\n" );
          return 1;
                                                              }       
        else {
write(
"\n\n 你看见书中发出一道光芒照耀著你 \n");

call_out("idle_teme",10); 
write("一个很柔和的声音说道...... \n

        欢迎加入保卫国家的行列
        基础心法只是很基本的心法，希望它对你有所助益 \n\n"); 
        this_player()->set("force_effect",1);
        return 1;  
             } 

}

int to_study(string arg)
{
  string class;
  int level;

  level=(int)this_player()->query_level(); 
  class=(string)this_player()->query("class");
  if ( !arg || arg!="help") return 0;
  else if ( class !="knight"){
     write("抱歉你不是本公会的人所以你不能学此心法\n");
     return 1;
                           }
    else if (level<18){
    write("『天神说: 兄弟啊!!! 只有骑士将军才能教授内功心法啦!』\n\n");
         return 1;
                     } 
        else if ((int)this_player()->query("force_effect")>=2){
write(
" 神累了一天，又被你吵的不能睡觉... 他很不爽的看著你骂道\n 
『你是白痴啊! 你已经学过心法了不能再学啦!!!』\n\n" );
return 1;
                                                              }       
        else {

call_out( "idle_time",5);
write(
"\n\n突然天上一声大吼...... \n");
call_out("idle_time",10);
write(" 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    
@@@ 杨家列祖神明乍现大喝，你终於领悟到杨家内功心法的奥义 @@@ 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n" );
             this_player()->set("max_fp", "@@query_max_fp");
        this_player()->set("force_effect",2);
        return 1;  
             } 
}

 
void idle_time()
{
write(" \n");
}
 

