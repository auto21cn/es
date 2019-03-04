#include <../hole.h>

inherit MONSTER;

int cough;

void create()
{
	object obj;
	::create();
	set_level(15);
	set_name( "Old Feller","老工匠" );
	add("id",({ "lizardman","feller" }) );
	set_short( "老工匠" );
	set_long(@LONG
    你看到的是一位年约五十岁的老工匠，他可是这村落
里首屈一指的工匠喔；不管任何木材到了他手上都可以雕
刻成美妙的物品。不过，他的身体似乎不太好。
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",400 );
	set( "max_hp",450 );
	set( "hit_points",450 );
	set( "wealth/silver",150 );
	set( "special_defense",([ "none": 25,"all": 22 ]) );
	set( "aim_difficulty",(["critical":30,"vascular":80]) );
	set_perm_stat( "str",20 );
	set_perm_stat( "dex",20 );
	set_natural_armor( 70,34 );
	set_natural_weapon( 65,25,45 );
	set_skill( "parry",90 );
	set_skill( "dodge",80 );
	set( "inquiry",([ "vampire" : "@@ask_vampire",
	                  "saw"     : "@@ask_saw"  ]) );
//	obj=new( HOBJ"saw" );
//	obj->move( this_object() );
	cough=1;
}

void init()
{
	::init();
	tell_room(environment(),set_color("老工匠不停地咳嗽\n","HIY") );
}
void ask_saw()
{
     if( cough == 0 ){
        if( this_player()->query_temp("lizard_quest/o_feller") ){
         tell_room( environment(),
         "老工匠说:借锯子啊？可以啊！端碗鱼翅汤来让我喝先！\n" );
         this_player()->set_temp("lizard_quest/shark_soup",1);
         this_player()->delete_temp("lizard_quest/o_feller");
         cough = 1;
        }else{
         tell_room( environment(),
         "老工匠说:你要借锯子干嘛？借你了，我靠啥劳子过活呀？不借！\n");
         cough = 1;
        } 
        return;
       }
       tell_room( environment(),
       "老工匠好像想要说什麽，但却一直咳嗽，或许他的喉咙有问题吧！\n");
       return;
}

[BBvoid ask_vampire()
{
	if( cough==1 )
	{
	tell_room( environment(),
	"老工匠好像想说什麽，但却一直咳嗽，或许他的喉咙有问题吧！\n" );
	return ;
	}
	tell_room( environment(),"老工匠说:吸血鬼？好像没有人看过。\n" );
	cough=1;
	return ;
}

int accept_item(object me,object item)
{
	string *name;
	object ob;
	
	name=item->query("id");
	if( name[0] == "paste" ){
	      command( "drink paste" );
	      cough=0;
	      return 1;
	}else if( name[0] == "soup" ){
              if( me->query_temp("lizard_quest/shark_soup") ){
              tell_room( environment(),@LONG
老工匠大快朵颐之後，笑笑对你说：
　　　好！干得好，我遵照承诺把锯子借给你罗！
LONG
              );
              ob = new(HOBJ"saw");
              ob->move(this_object());
              command("give saw to "+(string)me->query("name") );
              me->set_temp("lizard_quest/get_saw");
              me->delete_temp("lizard_quest/shark_soup");
              return 1;
              }else{
              tell_room( environment(),
          "老工匠大快朵颐後，笑笑的说：小子，谢谢你的清汤，你好心会有好报的！\n");
              item->remove();
              return 1;
              }
              }else{
	      tell_room( environment(this_object()),"老工匠说：『请别戏弄我这老人家。』\n" );
	      command( "give "+name[0]+" to "+lower_case( (string)me->query("name") ) );
	      return 1;
              }
}
