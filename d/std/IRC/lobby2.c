#include <irc.h>
#define BOARD "/d/std/IRC/irc_board"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Lobby","大厅" );
    set_long(
@C_LONG
这是一间陈设简单的方形大厅. 许多人正席地而坐, 静静排队等待
进入ES。左边墙上有一个布告栏(board), 上面贴了一张告示。
C_LONG
    );
    set("c_item_desc", ([
    	"board" : @C_BOARD
    	
    	这张告示上面写著:
	
    	本实验室将於今年七月十三日星期六於交大工程三馆举办关於网路虚拟社会
    	的研讨会, 欢迎踊跃参加。同时并公开徵求论文, 只要有关网路虚拟社会的
    	文章均欢迎投稿。稿件请寄新竹市交通大学资科所智慧型远距教学实验室或
    	email 至 workshop@cindy.cis.nctu.edu.tw。详情请见各大 BBS Mud 版。
    	         
	P.S. ES 快速进入秘技持续公开中: 默念IRIS好帅1000次, 心诚则灵

C_BOARD
]) );                                    
}
 
void init()
{
	add_action("do_kill","kill");
	add_action("do_auction","auction");
	add_action("do_drop","drop");
//      banish mage commands
	add_action("do_cast", "cast");
        add_action("do_meditate", "meditate");
//      banish thief commands
	add_action("do_backstab", "backstab");
	add_action("do_steal", "steal");
//      banish monk commands	
        add_action("do_exercise", "exercise");
        add_action("do_songin", "songin");
        add_action("do_eungon", "eungon");
//      banish scholar commands
	add_action("do_brood","brood");
        add_action("do_chutan","chutan"); 
        add_action("do_embattle","embattle");
        add_action("do_demand","demand");       
//      banish healer commands
	add_action("do_clot","clot");
	add_action("do_aid","aid");
	add_action("do_acupunct","acupunct");
//      banish adventurer commands
	add_action("do_hang","hang");
}

int do_drop()
{
	write("这□不准乱丢垃圾。\n");
	return 1;
}



int do_acupunct()
{
	write("这□不准针灸。\n");
	return 1;
}

int do_hang()
{
	write("这□不准绞杀。\n");
	return 1;
}



int do_aid()
{
	write("这□不准急救。\n");
	return 1;
}

int do_clot()
{
	write("这□不准止血。\n");
	return 1;
}

int do_demand()
{
	write("这□不准召唤。\n");
	return 1;
}


int do_embattle()
{
	write("这□不准结阵。\n");
	return 1;
}


int do_chutan()
{
	write("这□不准聚丹。\n");
	return 1;
}


int do_brood()
{
	write("这□不准打坐。\n");
	return 1;
}


int do_eungon()
{
	write("这□不准运功。\n");
	return 1;
}


int do_songin()
{
	write("这□不准诵经。\n");
	return 1;
}


int do_exercise()
{
	write("这□不准打坐。\n");
	return 1;
}

int do_meditate()
{
	write("这□不准冥思。\n");
	return 1;
}

int do_steal()
{
	write("这□不准偷窃。\n");
	return 1;
}


int do_backstab()
{
	write("这□不准背刺。\n");
	return 1;
}

int do_cast()
{
	write("这□不准施法。\n");
	return 1;
}

int do_auction()
{
	write("这□不准交易。\n");
	return 1;
}

int do_kill()
{
	write("这□不准械斗。\n");
	return 1;
}	
	