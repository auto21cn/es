
#include "../takeda.h"
#include <stats.h>
#include <conditions.h>

inherit SELLER ;
inherit "/std/teacher";
inherit MONSTER ;
inherit DAEMON ;

void init()
{
	::init();
	teacher::init();
	seller::init();
	add_action( "tip_me", "pay");
}

void create()
{
	object bandage;
	int payed;
	::create();
	set_level(8);
        set_name( "Ann Dao Chun", "安道全" );
        set_short( "安道全" );
	add( "id", ({ "doctor","healer","ann","dao","chun" }) );
	set_long(@C_LONG
你看见一个中年人，作游方郎中的打扮，他就是闻名的神医安道全．建康府人
，医术通神，任何疑难杂症遇到他，只需要花点小钱就可以解决，现为梁山泊内
专治内外科诸病医士。
C_LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "pie", 25 );
        set_perm_stat( "kar", 20 );
        set_lessons( ([
	"depoison": ({ 150, 80 })
	]) );
	set_perm_stat("int",22);
        set_perm_stat( "dex", 18 );
        set_skill( "dodge", 100 );
        set_skill( "anatomlogy", 85 );
        set_skill( "bandage",90);
	set("defense_type","dodge");
	payed=0;
        set( "aiming_loc", "ganglion" );
        set( "max_hp", 150 );
        set( "hit_points", 150 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 25 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
        set( "special_defense", ([ "evil": 30,"none":20]) );
        set( "alignment", 1500 );
        set( "wealth/gold", 30 );

        set( "inquiry", ([
                "heal": "@@ask_heal",
		"clot": "@@ask_clot",
		"cure": "@@ask_cure",
	        "sick": "@@ask_sick",
	        "diet": "@@ask_diet",
	        "bandage": "@@ask_bandage",
	        "sister": "@@ask_sister",
                "da": "@@ask_da",
                "depoison" : "@@ask_depoison"
        ]) );
        set_inventory( ({
                    ({ "/d/noden/farwind/items/plaster",40,40 }),
                    ({ "/d/noden/farwind/items/white_plaster",40,40 }),
                    ({ "/d/eastland/easta/obj/spicy_plaster",30,30 }),
                    ({ TOBJ"snow_lily",3,3 })
                    }));
        wield_weapon( TWEAPON"poblade" );
        equip_armor( TARMOR"small_cloth" );
        equip_armor( TARMOR"simple_boots");
          bandage=new("/obj/bandage");
          bandage->move(this_object());
}
    
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_room( environment(), 
        "安道全怒道: 卑鄙的家伙 !! 打我还叫我医你 !! 看我怎麽教训你 ! \n" ,
        this_object() );
        (CONDITION_PREFIX +"simple_poison")->apply_effect(this_player(),8,5);
        return 1;
	}
	return 0;
}

int ask_heal()
{
int num,hpmax,hp;

	if (I_hate_killer()) return 1;
      	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_room( environment(), 
	"安道全说道: 你身体很好呀? \n" ,
	this_object() );
	return 1;
	}
	num=(hpmax-hp)*3;
        if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"安道全摇摇头道：「无钱免谈。」\n",
	this_object() );
	return 1;
        }
	tell_room( environment(), 
	"医生说道：哈哈..有钱好办事，拿出一瓶小药膏涂在你的伤口上，一阵清凉的感觉後，\n"+
	"你的伤连疤痕都没留下。\n" ,
	this_object() );
	this_player()->set("hit_points",hpmax);
	return 1;

}
int ask_cure()
{
int num;

	if (I_hate_killer()) return 1;
        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/simple_poison"))
        {
        tell_room( environment(), 
        "安道全笑道: 你没有中毒啊? 要不要我帮你施点毒?? \n" ,
        this_object() );
        return 1;
	}
        num=25;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"安道全摇摇头道：「无钱免谈。」\n",
	this_object() );
	return 1;
        }
        tell_room( environment(), 
        "安道全拿出一匙黑色的刺鼻药水，捏著你的鼻子灌了下去，你感觉全身酸软无力，\n"+
	"头重脚轻，但体内毒素似乎都消失了。\n" ,
        this_object() );
        this_player()->delete("conditions/simple_poison");
        command("say 在荒郊野外，毒虫猛兽特别多，如果没有学过解毒技巧，最好不要到处探险.......");
        return 1;

}

int ask_clot()
{
int num;

	if (I_hate_killer()) return 1;

        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/bleeding"))
        {
        tell_room( environment(), 
        "安道全说道: 你一滴血都没流，省省吧... \n" ,
        this_object() );
        return 1;
	}
        num=15;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"安道全摇摇头道：「无钱免谈。」\n",
	this_object() );
	return 1;
        }
        tell_room( environment(), 
        "医生说道：好 !! 看我金针封穴，突然拿出一大把金针插入你的身体，你的流血\n"+
	"暂时停止了。\n" ,
        this_object() );
        this_player()->delete("conditions/bleeding");
        return 1;
}
int ask_sick()
{
  int num;
     if(I_hate_killer()) return 1;
     command("look "+(string)this_player()->query("name"));
     if (!this_player()->query("condition/sick"))
 {
     tell_room(environment(),
     "安道全说道: 你很健康呀? 奇怪...\n",
     this_object());
     return 1;
 }
      num=30;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"安道全摇摇头道：「无钱免谈。」\n",
	this_object() );
	return 1;
        }
       tell_room(environment(),
       "安道全拍著你的头念道: 抓邪抓鬼，驱魔除病，抓邪抓鬼，驱魔除病.....\n"
       "，虽然头被拍受伤，但你发现你的病完全治好了．\n",
       this_object());
       this_player()->receive_special_damage("none",3);
       this_player()->delete("condition/sick");
       this_player()->set("medication_resistance",(int)this_player()->query("medication_resistance")*8/10);
       return 1;
}
int ask_diet()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/fish")) || this_player()->query_temp("fat_quest/fish")<3)
write(
"安道全说道: 你当我是干什麽的啊??\n");
else {
write(
"\n安道全说道: 我们东方的医术，是缓慢且温和的，你如果要快速减肥，我可能\n"
"做不到，但是假如你身体够好的话，你可以去找那个兽医，他好像有一种让马\n"
"下痢的药喔，天天吃，一定可以瘦下来的。说完，");
command("grin "+(string)this_player()->query("name"));
return 1;
}
}
int ask_bandage()
{
 int num,hpmax,hp;
	if (I_hate_killer()) return 1;
      	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_room( environment(), 
	"安道全说道: 你身体很好呀? \n" ,
	this_object() );
	return 1;
	}
	if (this_player()->query_temp("bandaged")!=0)
	{
	tell_room( environment(),
	"安道全笑道: 你已经接受过包扎医疗了.....\n",
	this_object() );
	return 1;
	}
	num=6;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"安道全摇摇头道：「无钱免谈。」\n",
	this_object() );
	return 1;
        }
	if( !present("bandage",this_object() ) )
	{
	tell_room(environment(),
	"安道全叹道：早知道那麽好卖，就多拿点绷带出来。现在除非你能给我\n"
	"一些绷带，否则我可是无能为力的。\n",
	this_object() );
	return 1;
	}
	command("bandage "+(string)this_player()->query("name"));
	command("rub "+(string)this_player()->query("name"));
        this_player()->set_explore("eastland#23");
	return 1;

}

int ask_sister()
{
write(
"\n安道全说道: 没错，我是有一个妹妹，叫作安小慧，生性刁蛮古怪，从小就不\n"
"太听我的话，不过因为她是我唯一的妹妹，我也对她非常好，只是偶而会亏亏她\n"
"有一天，我有一个病人送我一颗大珍珠，由於小慧自小就非常喜欢珍珠，所以我\n"
"回家就把珍珠送给她，顺便亏了她几句人老珠黄之类的话，没想到她就离家出走\n"
"了..........现在想想真是後悔.....................\n\n");
call_out("ask_sister2",10,this_player());
return 1;
}
int ask_sister2()
{
write(
"安道全抬头看了你一眼，又说道: 是皇甫端告诉你的吧? 他这个人倒还好，只是\n"
"很喜欢道听途说，说话都要打对折，你还是不要抱太大的希望....\n"
"说完，安道全嘴里叽哩咕噜的走回柜台，仔细一听，好像是在说什麽女子很难养\n"
"的，但是他说的不清不楚，你听的也很模糊。\n");
this_player()->set_temp("fat_quest/diet",1);
return 1;
}
int ask_da()
{
write (
"安道全想了一下，说道: 你问的是石碣村的达婆婆吗? 她是少数我治不好的病人\n"
"之一。事实上，她根本只是营养不良而已，只是因为她相信自己活不久了，不相信我\n"
"的话，不吃药，也不吃饭，才会搞成现在这个样子。只要她肯吃饭和吃药，她的病，\n"
"对我来说根本不是问题。说完，安道全继续做他的事。\n");
return 1;
}
int ask_depoison()
{
command("say 你如果是常常在野外冒险的话，我倒是可以教你一些基本的解毒技巧，但是.......");
return 1;
}

int check_trainee(object trainee)
{
	if( (string)trainee->query("class")=="adventurer" 
	&& (int)trainee->query_level() > 9 && (int)trainee->query_temp("give_money")==1 )
		return 1;
	else
             return notify_fail( 
                    "安道全说道: 我只教够资格的冒险者，如果你愿意表现一下你的\n" 
                    "诚意的话，我就教你解毒的方法。\n");
}
int tip_me(string arg)
{
        string who, type;
        int num;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail(
                        "付谁？多少钱？\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
                tell_room( environment(), 
                        "安道全说道: 好汉 ! 对不起，我只收金币。\n" ,
                        this_object() );
                return 1;
	}
	if ( num < 100 ) {
	tell_room( environment(), 
                 "安道全说道: 好汉 ! 你的诚意不够喔？\n" ,
                        this_object() );
		return 1;
	}
        tell_room( environment(), 
                 "安道全点点头道: 好汉 ! 你现在就要开始学解毒术(depoison)了吗？\n" ,
                        this_object() );

	this_player()->set_temp("give_money",1);
	return 1;
}

