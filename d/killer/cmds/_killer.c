#include "../killer.h"

inherit DAEMON;

int cmd_killer(string arg)
{
        seteuid(getuid());
        ORG_OBJ->guild_line(arg);
        return 1;
}

int help()
{
        write( @HELP
用法 : killer message
这个指令用来同目前线上的杀手通信。

参考: killer
HELP
              );
        return 1;
}
