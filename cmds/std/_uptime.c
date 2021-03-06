//#pragma save_binary

// uptime.c
// Tells you how long the mud is up.
// Lord knows who wrote it.
// Mobydick added header and help, 11-20-92

#include <mudlib.h>
#include <reboot.h>

inherit DAEMON;

int cmd_uptime()
{
	printf("东方故事已经连续执行了 %s，\n", format_c_time(uptime(), 1));

	if( REBOOT_DELAY-uptime() > 0 )
	printf("离 Reboot 还有 %s。\n",format_c_time(REBOOT_DELAY-uptime(), 1) );
	else
	  this_player()->quick_message("已经进入 Reboot 倒数计时了。\n" );
	return 1;
}

int help()
{
	write (@HELP
使用格式: uptime

显示游戏已经运行多少时间.
HELP
);
	return 1;
}
