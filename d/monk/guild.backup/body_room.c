#include "saulin_temple.h" 

inherit ROOM;

void create()
{
	::create();
    set_short("Body defense room","少林金刚不坏体神功\习练房");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
一进入房间，你的目光首先被房中一个看起来很瘦的老僧所吸引，角落中用草书
写著『少林金刚不坏神功\』。你可以发现大部份的绝技都是攻击用的，少数如金刚不
坏体神功\则是纯粹防御用的功\夫。要学哪一种则完全是你的选择了。 
墙边贴了一张的纸条(paper)，上面似乎写了一些字，北边可回七十二绝技房。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper" : @BOOK
                         
                           金刚不坏体神功\修习资格

       1. 有七十二绝技僧以上之资格。
       2. 敏捷到达18。  
       3. 个性温和，不喜滥造杀孽者。       

       达到以上资格者，可在此习练金刚不坏体神功\(practice body-def)

       注: 如果你想改练别的绝技，可以用散功\ (sangon body-def)，
           你的本绝技经验点仍会被保留，只是不能用。  
BOOK
	]) );
	set("light", 1 );
	set("exits", ([ 
		"north" : SAULIN"72" ]) );
	set("objects", ([
		"Monk" : SAULIN_MONSTER"kon-gem" ]) );
	reset();
}

void init()
{
	add_action("to_study", "practice");
	add_action("to_delete","sangon");
}

int to_delete(string arg)
{
	object me;
	if( !arg || arg != "body-def" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/body-def") ) )
	     { write(" 你跟本不曾学过金刚不坏体神功\! \n");
               return 1;
             }
        else {
        write("你的金刚不坏体神功\暂时消失了!!! \n"); 
        write("但如重练时旧经验值仍然不变 \n\n"); 
 		me->delete("monk_gonfu/body-def");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 
int to_study(string arg)
{
	object me;
	
	if( !arg || arg != "body-def" ) return 0;

	me = this_player();	
  	if( !wizardp(me) && (string)me->query("class") != "monk" )
  		write("你不是本公会的人所以不能学此功\夫\。\n");
  	else if( (int)me->query_level() < 15 )
		write("空见摇头说: 你的位阶太低，不该练金刚不坏体神功\。\n\n");
	else if( (int)me->query_perm_stat("dex") < 18 )
		write("空见说: 你的敏捷不够，没办法教你。\n\n");
	else if( (int)me->query("alignment") < 1000 )
		write("空见合十道: 阿弥陀佛... 施主杀孽太重, 不宜习此武功\!。\n\n" );
	else if( !undefinedp(me->query("monk_gonfu/body-def")) )
		write("空见叹了一口气说: 你已经学过金刚不坏体神功\了，要专精就快去练习!。\n\n" );
    else if( me->query("monk_learn/72") )
		write("空见双手合十道: 不行，你已经学过一项绝技了。\n\n" );
	else {
		write( @LONG

  好! 那我现在就教你金刚不坏体神功\的口诀吧! 空见笑道:
   
      身法八要... 起落进退反侧收纵...
      
      足法... 起落翻挣，忌踢宜踩....
      
      意与气合，气与力合，起身如风，以意统之...
      ...........................................
      
      虚势中有玄而若虚，实势中无玄而若实....
      ...........................................
      
      御气於檀中，驾意於百汇，屯神於气海.....
      
      空见大师一句句的向你解释著练功\的要诀...                
      ..................................

      你终於学完了金刚不坏体神功\了...
      
LONG
		);
		me->set("monk_gonfu/body-def", 0);
		me->set("monk_learn/72", 1);
	}
	return 1;
} 
