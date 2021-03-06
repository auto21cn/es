
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	seteuid(getuid());
	set_name( "homdlaser", "宏都拉瑟" );
	set_short( "a dwarf experienced miner homdlaser", "矮人专家矿工宏都拉瑟" );
	set_long(
	" Dwarf experienced miner,homdlaser is the manager for the factory,and he knows \n"
	"many knowledge.So cart can get the best effivelity.To talk with him,maybe you get\n"
	"some messages.\n",
	"矮人专家矿工宏都拉瑟,已经管理炼矿厂很多年了.而且对於矮人矿坑(mine)里的地\n"
	"形地物非常了解.所以矮人运矿车(cart)在他的调度下发挥了最大的效率.和他谈谈\n"
	"\或\许\你会有意想不到的收获.\n"
	);

    set("alignment",400 );
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 24 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 30);
	set_skill("unarmed",88);
	set_skill("dodge",88);
	set ("max_hp", 770);
	set ("hit_points", 770);
	set ("wealth", ([ "gold": 55 ]) );
	set_natural_weapon(35,22,33);
	set_natural_armor(70,35);
    set ("weight", 400);
    set( "inquiry", ([
         "cart" : "@@ask_cart",
         "carts": "@@ask_cart",
         "valor": "@@ask_valor",
         "mine" : "@@ask_mine",
           ]) );
    set("echo_valor",1);
    set ("chat_chance", 7);
	set ("chat_output", ({
	    "Homdlas says: Notice safety\n",
	    "宏都拉斯说:注意安全,这矿坑充满著危险.\n",
	    "Homdlas says:if you want to help us,please prove you are a valor first.\n",
	    "宏都拉斯说:假如你是来帮助我们的,先证明你是一个勇者(valor).\n"
	    }) ); 
}

void ask_cart( object who )
{
     tell_object(who ,can_read_chinese(who) ?
     "一个从默尔斯来的流浪汉,希斯克利夫(Cisklyph),我想他可能是世界上最聪明的人,\n"
     "帮助我们建立了很完整的开矿与□矿系统.像你问起的运矿车,就是一个很复杂的机器\n"
     ",构造连我也不是很了解,只知道它能很快速地在轨道上移动.但是运矿车的确帮助我\n"
     "们的采矿速度加快了.\n"
     :
     " \n"
     );
}
void ask_mine(object who)
{
    tell_object(who ,can_read_chinese(who) ?
    "矿坑,一个充满黄金的地方,但是也充满了危险与死亡\n"
    "我们矮人已经开发了大部份的地方,但是还有一些特别危险的地方,已经被我们封住.\n"
    "假使你对於探险有著很高的兴趣,拿起你的铲子去挖掘吧!通常在轨道的尽头若是没\n"
    "有一个缓冲器(让运矿车停住的机器),那麽\或\许\你将发现在那儿将有大量的财富在\n"
    "等著你.当然也有凶猛的怪物在等著你\n"
    :
    "\n"
    );
}
void ask_troll( object who )
{
        tell_object( who, can_read_chinese(who) ?
          "巨人,有很强的生命力,我们矮人族已经与它们作战数百年了\n"
          "如果你想知道更详尽的资料,或许巨人战术研究室的卡尔(Karl)将军\n"
          "能告诉你.\n"
          :
          "troll\n" );
      return ;        
}

void ask_valor(object who)
{
      
      tell_object(who,can_read_chinese(who) ?
      "去找皇室侍卫队长卡尔服德,他将告诉你更详尽的资料\n "
      :
      " \n"
     );
      return ;
}

int echo_valor(object ob1,object ob2)
{
     if (!ob2 || (int)(ob2->query("echo_quest_card"))!=1) return 0;
     if ((int)(ob2->query("echo_quest_card"))==1) {
        if( ob1->query("name")!=ob2->query("someone_id") )
          {
          tell_object(ob1,
          "我想这卡片是非法得来的.所以我不能帮助你这个贼.\n"
           );
          }
        else {
        tell_object(ob1,can_read_chinese(ob1) ?
        "勇者你好.宏都拉斯说\n"
        "宏都拉斯向你敬礼.\n"
        "我想你已经证明你的勇气了.我们的圣地正遭受了很大的威胁,骸骨族黑武士\n"
        "的攻击使得目前在圣地研究反黑魔法的艾尔与齐格的一番心血完全泡汤 .希\n"
        "望你的出现能帮助他们.\n"
        :
        " \n"
        );
       call_out("cart_open",2,this_object());
      // ob2->move(ob1);
      // tell_object(environment(),"宏都拉斯把卡片还给"+ob1->query("c_short")+"\n");
          }
     }     
     return 1;  
}

int cart_open(object ob1)
{
    object ob3,ob4;
    
    switch ((int)environment(ob1)->query("open_cart"))
      {
      case 1:   
         ob3=new(Mine"/obj_cart");
         ob4=new(Mine"/room_cart");
         ob3->set_roomcart(ob4);
         ob4->set_objcart(ob3);
         ob3->move(environment(ob1));
         tell_room(environment(ob1),"宏都拉斯把希斯克利夫运矿车开了出来.\n");
         environment(ob1)->set("open_cart",2);
         break;
      case 2:
         tell_room(environment(ob1),"运矿车已经在这里了.\n");
         break ; 
     
      }     
    return 1;
}
