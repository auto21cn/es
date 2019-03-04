#include <mudlib.h>

inherit OBJECT;

void create()
{
	seteuid( getuid() );
	set_name( "peace stone", "和平纪念碑" );
	add( "id", ({ "stone" }) );
	set_short( "和平纪念碑" );
	set_long(@LONG
代表和平的纪念碑，不过倒置的武器造型，让你觉的相当有趣！
LONG
	);
	set( "unit", "座" );
	set( "prevent_get",1 );
}

void init()
{ 
	add_action( "do_beg", "beg" ); 
}

int do_beg(string arg)
{
	object obj,obj1,env,player;
	int i;
	string pname;

	env=environment(this_object());
	player=this_player();
	pname=player->query( "c_name" );

	if( !arg )
		return notify_fail( "你想做什麽！？\n" );

	if( arg == "holy_knight" )
	{
	if( (int)player->query_level()<=3 )
		return notify_fail( "小小年纪，不要学做坏事！\n" );
		
	else
	{
	  if( !(obj=present("lizardman holy knight",env)) )
		return notify_fail("人不在这儿啊！\n");
	  	
	    if( (int)player->query_temp("jousting")==1 )
	    {
	      if( (int)(obj->query("no_jousting"))==0 )
	      {
//		obj1=new( IWEP"jousting" );
//		obj1->move( player );
		i=player->query( "max_tp" );
		player->set( "talk_points",i );
		player->force_me( "shout 对不起，我不小心把战争发动了～～～" );
		obj->set("no_jousting",1);
		write("\n圣骑士将石碑拔起交给了你，咦？竟变成创世神戟了！\n\n");
		tell_room(env,set_color(
		"\n你看到圣骑士伸出双手用力地握住石碑，石碑的外壳立刻化为碎片；\n"+
		"就在石碑碎掉的同时，一道耀眼的光芒由圣骑士手上发出，令你几乎张不开眼睛。\n"+
		"你好奇的往圣骑士双手看去。咦，那不就是传说中的『创世神戟』吗？\n\n"+
		"接著圣骑士便把戟交给了"+pname+"\n","HIY"),player );
//		obj->command("go up");
		call_out("s_war",2);
		return 1;
		}
		
              else
              return notify_fail( "\n圣骑士对你说：『抱歉，神戟早被ㄎㄧㄤ走了。』\n\n" ); 
              }
              
          i=(int)( player->query("max_tp") );
	  player->set( "talk_points",i );
	  player->force_me( "shout 我要发动谪仙岛三族战争罗！各路英雄好汉和战争狂快快会和吧！ " );
	  tell_room( environment(player),set_color( 
	  "\n圣骑士举起手掌，轻轻在石碑上一拍，石碑就灰飞湮灭了\n","HIR" ) );
	  obj->leave();
	  call_out("s_war",2);
	  return 1;
	  }
	}
	else
	{
	write("求谁啊？\n");
	return 1;
	}
}

void s_war()
{
	find_object_or_load("/open/odin/island/war/islandwar")->start_war();
	remove();
}
