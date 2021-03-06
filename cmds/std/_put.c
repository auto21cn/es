//#pragma save_binary

// _put.c
// This is kind of a bad hack. The _put command is defined in the container
// object. But you want players to be able to get help on it like any other.
// The solution is to make up this little command file, which traps two
// cases: first, the player using put when he doesn't have any containers;
// and second, the player typing "help put".
// Probably this isn't the best solution, but it's a short quick fix.
// Embarrassingly written by Mobydick@TMI-2, 1-22-92
// Part of the MudOS mudlib. Please retain at least this part of the header
// if you use this code.
 
#include <mudlib.h>
 
inherit DAEMON; 

int help() {
 
   write( @HELP
使用格式: put [物品] into [目标]

这个指令将物品放入容器内.

相关指令: get, open, close, lock, unlock.
HELP
);
 
return 1; }

int cmd_put() {
 
   notify_fail("把什麽放到什麽里面啊？\n");
 
return 0; }
 
