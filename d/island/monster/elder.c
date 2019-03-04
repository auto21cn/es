//#include "../island.h"
#include <mudlib.h>
inherit MONSTER;

void create()
{
	
	::create();
	set_level(1);
	set_name( "Daemon Elder Ivan","魔族长老 伊凡" );
	add ("id", ({ "daemon", "elder", "ivan", }) );
	set_short( "魔族长老 伊凡" );
	set_long(@LONG
他是魔族派在村里的代表，此外他还负责训练魔族战士的事，你可以问问
他有关训练的事(train)。	
LONG
	);

        set( "gender", "male" );
        set( "race", "daemon" );
        set( "unit", "个" );
	set_perm_stat( "dex", 1 );
	set_perm_stat( "str", 1 );
	set_perm_stat( "int", 1 );
	set_perm_stat( "con", 1 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "kar", 1 );
	set("no_attack",1);
	set("no_steal",1);
        set ("weight", 300);
        set( "inquiry", ([
         "train" : "@@ask_train" ,
         "drill" : "@@ask_drill"
           ]) );
}

//void init()
//{
//     ::init();
//     add_action("to_comfort","comfort");
//}

void ask_train(object who)
{ 
  tell_object(who,"伊凡偷偷告诉你说：「关於训练的事，我们基本上是希望训练一批中间份子，\n");
  tell_object(who,"  所以基础太差的人我是不收的，但是相对的你要是太强，我希望你不要妨碍\n");
  tell_object(who,"  後进的训练，要是确实想训练的话，可以问我有关受训的事(drill)。」\n");
  return;     
}
void ask_drill(object who)
{ 
  int check;
  if((check=who->query_level())>15)
  { tell_object(who,"伊凡告诉你：「我想你已经可以自立了，孩子，多出去逛逛吧。」\n"); }
  else if(check<7)
  {  tell_object(who,"伊凡告诉你：「你的基础不足，我怕你会在训练的地方挂点，先到大草原练练吧。」\n"); }
  else
  {
    tell_object(who,"Bmp走到你面前说:xixi,虽然你达到了要求，但....这个功能还没有开放，\n");
    tell_object(who,"你再等等，或催催负责这里的wizard吧。    祝你走运。\n");
//  看下文，原来这个功能还未有，我先把他原来的wizard name //掉。
//  tell_object(who,"奥丁走到你面前说：「我最近期末考，所以暂时不能写完，\n");
//  tell_object(who,"我的构想是写一个给 7到15及练功的地方，完成了一定会告\n");
//  tell_object(who,"诉大家的。」\n");
  }
  return;
}  
