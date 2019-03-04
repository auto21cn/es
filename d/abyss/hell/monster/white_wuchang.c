#include <mudlib.h>
#include <ansi.h>

#define NAIHER_BRIDGE "/d/abyss/hell/bridge"
#define REVIVE_ROOM "/d/noden/farwind/cemetery"
#define JUDGE_ROOM "/d/abyss/hell/hall"
inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "White Wuchang", "白无常" );
	add( "id", ({ "wuchang" }) );
	set_short( "White Wuchang", "白无常" );
	set_long(
		"You see the White Wuchang, agent of the Death.\n",
		"你看到一个脸色苍白，面无表情的白衣怪人，这就是来自地狱的勾魂使者\n"
		"白无常，他和另一位黑无常负责将死去的亡魂带到阎王面前受审。\n"
	);
	set( "gender", "male" );
}

void start_death(object ghost)
{
	object env;

	env = environment(ghost);
	if( !env ) return;
	if( environment() ) tell_room( environment(), ({
		"Black Wuchang says: Hmm... another one dies, what a day ....\n"
		"Black Wuchang's figure fades and disappears.\n"
		"With only one second, Black Wuchang returns with another ghost.\n",
		"黑无常说道: 又有人死掉了，今天是什麽日子 .....\n"
		"黑无常的身影消失在一片朦朦的雾气中。\n"
		"只一眨眼的功夫，黑无常又用铁链拖著另一个鬼魂从一片雾气中出现。\n" }),
		this_object() );
	tell_object(ghost, can_read_chinese(ghost)?
		"\n你看到一个又高又瘦的黑色人影，无声无息地走到你的身边 ....\n"
		"\n黑无常说道: 你已经死了，随我赴阴司受审吧。\n"
		"\n黑无常将一条又粗又重的铁□往你头上一套，很粗暴地拖著你向前走。\n"
		"\n你只见眼前许多云雾像刀一样刮过你的脸，然後出现了一座石桥 ....\n":
		"\nYou see a tall slim figure appears behind you silently ....\n"
		"\nBlack Wuchang says: YOU HAVE DIED, MORTAL ONE.\n"
		"\nBlack Wuchang put a heavy iron chain on your neck and draw you forth.\n"
		"\nYou see many white mist fly pass your face.\n" );
	ghost->move(NAIHER_BRIDGE);
	move(NAIHER_BRIDGE);
	call_out( "death1", 10, ghost );
}

void death1(object ghost)
{
	tell_object(ghost, can_read_chinese(ghost)?
		"\n黑无常说道: 鬼卒，我带来了一个亡魂，你进去通报一声！\n"
		"\n黑无常转头对你说道: 好好在这里呆著，过了奈何桥就是阴间了。\n":
		"\nBlack Wuchang says: Guards, I have brought a new ghost, announce it!\n"
		"\nBlack Wuchang turns to you and says: WAIT HERE.\n" );
	call_out( "death2", 30, ghost );
}
void death2(object ghost)
{
     tell_object(ghost,can_read_chinese(ghost)?
     "\n跟著我来,黑无常说道,\n":
     "\n Follow me,Black wuchang says.\n"
     );                     
    
     ghost->move_player(JUDGE_ROOM,"SNEAK");
     call_other(JUDGE_ROOM,"death3",ghost); 
}
void death3(object ghost)
{
	tell_object(ghost, can_read_chinese(ghost)?
		"\n鬼卒说道: 算你运气好，森罗殿还在整修当中，回阳间去吧！\n"
		"\n鬼卒抓起你往云雾中一丢，一阵天旋地转之後，你又见到一片熟悉的景象 ...\n":
		"\nHell Guard says: THE HELL IS NOT READY FOR GHOSTS, GO BACK!\n"
		"\nHell Guard throw you into the moar, you see something familiar ....\n" );
	ghost->move(REVIVE_ROOM);
	ghost->revive();
}
