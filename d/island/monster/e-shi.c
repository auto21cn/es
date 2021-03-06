#include "../island.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "e shi", "一虚" );
	add ("id", ({ "e", "shi","monk" }) );
	set_short( "一虚" );
	set_long(@LONG
一虚是少林百年难得一见的天才，他精通五种七十二绝技，但他的年纪
却很轻，大约近四十岁而已，虽然他武功很好，但是他最感兴趣的是历
史研究和古迹发掘，现在他在这里研究这个岛上的传说，最近他好像有
所发现，所以显得很高兴的样子，你可问他有关研究(research)的事。
LONG
	);
	set( "alignment",1000);
	set( "gender", "male" );
	set( "race", "lizardman" );
	set( "unit", "位" );
	set_perm_stat( "dex", 29 );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 29);
	set_perm_stat( "karma", 30);
	set_skill("unarmed",100);
	set_skill("dodge",100);
        set_skill("parry",80);
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 1000);
	set("max_fp", 5000);
	set("hit_points", 1000);
	set("force_effect", 5);
	set("force_points", 5000);
	set("attack_skill",CLASS"dragon_claw");    
	set("defense_skill",CLASS"body_def");
	set("monk_gonfu/dragon-claw",100);
	set("monk_gonfu/body-def",100);
	set("monk_gonfu/power-finger",100);
	set("monk_gonfu/bolo-fist",100);
	set("monk_gonfu/keep-flower",100);
	set("wealth/gold", 10);
	set_natural_weapon( 100, 15, 36 );
	set_natural_armor( 40, 15 );
        set("weight", 500);
        set("chat_chance",20);
	set("att_chat_output", ({"\n", "\n一虚喝道 ：『这便是龙爪手!!!』\n\n " 
	}) );
	call_out("mygonfu1",25);
       equip_armor( IOBJ"cloth01.c" );
       equip_armor( IOBJ"boots01.c" );
       set("inquiry",([
            "research": "@@research",
            "war"     : "@@war",
            "peace"   : "@@peace"
               ]) );
}
void mygonfu1()
{ 
  delete("att_chat_output");
  set("att_chat_output",({"\n","\n一虚断喝一声：『看看大力金刚指吧！』\n\n"}));
  delete("attack_skill");
  set("attack_skill",CLASS"power_finger");
      call_out("mygonfu2",25);
 } 
 void mygonfu2()
 {
   delete("att_chat_output");
   set("att_chat_output",({"\n","\n一虚用宏伟的声音说：『见识见识般若掌吧！』\n"}));
   delete("attack_skill");
   set("attack_skill",CLASS"bolo_fist");
   call_out("mygonfu3",25);
}
void mygonfu3()
{ 
    delete("att_chat_output");
    set("att_chat_output",({"\n","\n一虚微笑说道：『你想接接捻花指吗？』\n\n"}));
    delete("attack_skill");
    set("attack_skill",CLASS"keep_flower");
    call_out("mygonfu4",25);
    
}
void mygonfu4()
{
    delete("att_chat_output");
    set("att_chat_output",({"\n","\n一虚狂喊道：『小子！让龙爪手来收拾你吧！』\n\n"})); 
    delete("attack_skill"); 
    set("attack_skill",CLASS"dragon_claw");  
    call_out("mygonfu1",25);
}  

void research()
{
  write(@LONG
一虚埋头整理著「一大堆」的资料，头也不抬的说：
     『这位兄台，您是要问战争(war)史呢？还是问和平(peace)史？』
LONG
       );
  return ;
}

void war()
{
  write( set_color(@LONG
  
一虚突然骂道：『啥！ 哇勒热开水！我还在整理啦！ 打你唷！』
 
说完轻轻在你胸口按了一掌，你觉得好像受了内伤，最好去看医生。

LONG
      ,"HIM") );
      this_player()->set("hit_points",(int)this_player()->query("hit_points")/10 );
      if( (int)this_player()->query("force_points") )
      { 
        this_player()->set("force_points",(int)this_player()->query("force_points")/10 );
      }
         this_player()->set("spell_points",(int)this_player()->query("spell_points")/10 );
       return ;   
}

void peace()
{
  write(@LONG
  一虚像是遇到知己般的拥抱著你，眼框中渗著泪水说：

    终於......有人关心和平了；根据我的研究，这金身原是『蜥蜴人圣骑士』
，当时是该族中最强的战士，同时由於其德高望重，不插手无益的争斗，使他亦
受到其他二族的尊敬；正当三族正僵持不下时，他带著人见人怕的『创世神戟』
出来进行调停工作，但魔族的人却误以为他有私心，因而偷袭施予石化魔法，将
其元神吸走并加以监禁，後来在神仙显灵下虽获得和平，但其嫌隙仍在，总之，
目前的和平是极不稳定的，据我推测，只要元神回到金身，使圣骑士复活，并向
他祈求(beg)，不然战争还是随时会爆发的！  
LONG
      );
  return ;
}
