#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid( getuid() );
        set_level(5);
        set_name( "daoist", "道士" );
        set_short( "道士" );
        add( "id", ({ "groom" }) );
        set_long( "一个相貌怪异、行动神秘的道士，全身沾满了草屑。\n" );
        set( "gender", "male" );
        set( "natural_armor_class", 26 );
        set( "natural_defense_bonus", 12 );
        set( "no_attack",1 );
        set_natural_weapon(11,4,14);
        set( "chat_chance", 25 );
        set( "chat_output", ({
                "道士自言自语道: 在这里打个盹也会被吵醒...\n",
                "道士抬头望著牧马关说道: 这牧马关怎麽妖气(ghost)冲天啊...\n",
        }) );
        set( "inquiry", ([
        "ghost" : "@@ask_ghost" ]) );
}
 
int ask_ghost()
{ object obj;
if ( this_player()->query_temp("under") >=2 ) {
tell_object(this_player(),
@ASK
 
道士指著牧马关的上空对你说道: 牧马关上笼罩著团团紫色的气体, 看到没？
你顺著道士所指看去, 似乎真的看到了许多似烟的紫气从牧马关内冒出......
道士说道: 我夜观星象, 算得在这作怪的应是一头修□千年的异兽, 此兽在此
　　　　　军事重地, 必然为害......。我也算得今日必有福星出现, 也许这
　　　　　福星就应在你身上了。
道士从袖中取出一支钉子。
道士说道: 这只七星追魂钉可以将那畜生的元神击破, 它就不能再害人了, 你
          可要收好啊......贫道还有要事在身, 这里就拜托你了......
 
ASK );
this_player()->set_temp("under",3);
obj=new(OBJS"nail");
obj->move(this_object());
command("give nail to "+lower_case((string)this_player()->query("name")));
tell_object(this_player(),
@ASK
 
道士转了个身，消失在草丛之中。
ASK );
}
else {tell_object(this_player(),
@ASK
 
道士说道: 什麽都不懂的人不要吵我睡觉......
 
道士话一说完就转身消失在草丛之中......
ASK
); }
this_object()->remove();
return 1;
}
