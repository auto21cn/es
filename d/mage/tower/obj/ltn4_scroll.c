//  Created by Yueh in Eastern Story 1995/11/10
#include <mudlib.h>
#define SLAB_FILE "/d/mage/data/slab.txt"
inherit OBJECT;
void create()
{
	set_name( "blue magic scroll", "蓝色魔法卷轴" );
	add( "id", ({ "scroll" }) );
	set_short( "蓝色魔法卷轴" );
	set("long","@@desc");
	set( "unit", "张" );
	set( "weight", 5 );
	set( "no_sale", 1 );
}


void init()
{
        add_action( "recite_runes", "recite" );
}

int recite_runes(string arg)
{
        object env,me;
	me=this_player();
        if( !arg || arg!="runes" )
                return notify_fail("想吟诵什麽？\n");
        if ((this_player()->query_skill("runes")< 90))
                return notify_fail("你根本看不懂，想吟诵什麽？\n");
        if ((this_player()->query("spell_levels/black-magic")< 50))
                return notify_fail("你吟诵了半天，还是不知道正确的使用方式，大概是你对黑魔法还不够熟练吧！\n");
if ((undefinedp (this_player()->query("spells/lightning"))) || (this_player()->query("spells/lightning")< 3))
return  notify_fail("你吟诵著咒文，但是以目前你的幻雷术等级不知道该如何使用！\n");

if ((this_player()->query("spells/ether-bolt")== 8)||(this_player()->query("spells/fireball")== 7))
return notify_fail("你已经学了其它高等攻击魔法，无法在学了！\n");

if (this_player()->query("spells/lightning")== 4)
return notify_fail("你吟诵了咒文，对这个咒文记得更清楚了。\n");
	write("你开始吟诵卷轴上的咒文：拉·依古玛·得拉哈坦....。\n\n");
	tell_room( environment(me), sprintf("%s对著卷轴开始喃喃自语。\n", me->query("c_name")), me);
	printf(set_color("卷轴发出了蓝色的光芒，化作了几百团的游离的电气，围绕在你四周快速移动著，不时闪出电光.... \n ...\n ...\n", "HIB") );
	tell_room( environment(me), set_color(sprintf("\n%s手上的卷轴发出了蓝色的光芒，化作了几百团的电气，围绕在%s四周快速移动著，不时闪出电光.... \n",me->query("c_name"),me->query("c_name")),"HIB" ), me);

	call_out("effect",1,me);
        return 1;
}
void effect(object reciter)
{
string fame;
seteuid(getuid());
fame = "     "+(string)reciter->query("c_name")+"("+
                (string)reciter->query("name")+")"+" 於 "+
                "/adm/daemons/weather_d"->query_c_game_time()+" 习得幻雷术[4] !!\n";
                write_file(SLAB_FILE, fame+"\n");
	write("从观察游离电气的移动，你领略出如何使用幻雷术[4]！！\n> ");
	tell_room( environment(reciter), sprintf(set_color("\n游离的电气愈来愈弱，渐渐的消失不见了.... \n\n> ", "HIB") ));
	this_player()->set("spells/lightning",4);
	remove();
}

string desc()
{
if ((this_player()->query_skill("runes")< 50))
return ("这张蓝色卷轴上写了一些你看不懂的奇怪文字。\n");
else
if ((this_player()->query_skill("runes")< 90))
return ("这张蓝色卷轴上写了一些魔法文字，但是你只看懂了一半，大概是你对魔法文字的认识还不够吧。\n");
else
if ((undefinedp (this_player()->query("spells/lightning"))) || (this_player()->query("spells/lightning")< 3))
return ("这张蓝色卷轴上面似乎记载著幻雷术的咒文，但是以目前你的幻雷术等级不知道该如何使用。\n");
else
if (this_player()->query("spells/lightning")== 4)
return("这张蓝色卷轴上面记载著幻雷术第四级的咒文。\n");
else
return("依你对幻雷术的了解，上面记载著似乎是幻雷术的一种咒文，可是你以前从没看过这些咒文，\n想试著吟诵(recite)这些咒文(runes)看看吗？\n");
}

