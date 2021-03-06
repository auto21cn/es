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
进入ES。左边墙上有一个布告栏(board), 上面贴了一张告示。右边
墙角有张展示柜(closet), □面放著1996 mud workshop 的纪念品。
C_LONG
    );
    set("c_item_desc", ([
     "closet": @C_CLOSET 
     这个展示柜□放了个1996 mud workshop, ES 提供的虚拟纪念品 -- 精美可
     储存胸章(amulet) 一个, 听说只要参加 workshop 的ES玩家, 就可以获赠
     一枚。
C_CLOSET,

	"amulet":@C_AMULET
	这是1996 M.U.D. workshop 上送的虚拟纪念品, 上面有个漂亮的
	勇者斗恶龙Mark。上面共有三个小按钮, 分别标示著(help), (login),
	以及 (check), 如果你不清楚它们的功用, 建议你先按(press) help
	按键看看。
C_AMULET,	  

    	"board" : @C_BOARD
    	
    	这张告示上面写著:
	   1996 第一届网路虚拟社区研讨会纪念品获赠名单:
	        bonbon, iop, jauyn, law, luna, lwz, moii, nausca, qer, 
	        shxteater, spice, trash, tutu, yoyo
    	        (按字典顺序排列)
    	         
        PS   ES 快速进入秘技持续公开中: 默念IRIS好帅1000次, 心诚则灵
        PS2  list 这个指令能让你知道现在所处的顺位.
        PS3  连续指令爱用者自己小心, 凡因此在这被Immortal zap 自行负责
C_BOARD,


]) );                                    
}
 
void init()
{
     add_action("do_list","list") ;
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

int sort_pio(object A,object B)
   { int aa,bb ;
     aa = A->query_temp("chat_user");
     bb = B->query_temp("chat_user");
   return  aa - bb ; }

int do_list()
{
    int piority ;
    object *usr,*tmp ;
    usr = all_inventory(this_object()) ;
    piority = member_array(this_player(),sort_array(usr,"sort_pio")) ;
    if(piority) write("你现在的顺位是第"+chinese_number(piority)+"号。\n") ;
    else ("你不是属於这个聊天室的人\n") ;
    return 1;
}

	