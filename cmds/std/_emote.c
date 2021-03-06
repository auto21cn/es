//#pragma save_binary

/*
// Help added by Brian (1/28/92)
// Revised by Buddha@TMI (8/1/92)
*/

#include <mudlib.h>

inherit DAEMON ;

int cmd_emote(string str) {
    string first,tail,insert;

    if(!str) {
      write("你看起来表情丰富.\n");
      say(this_player()->query("c_name")+"作出丰富的表情.\n");
      return 1;
    }
    if (!wizardp(previous_object())) first = "-> ";
    else first = "";
    if (sscanf(str," %s",tail)==1) insert = "";
    else if (sscanf(str,"'%s",tail) == 1) insert = "";
    else insert = " ";
    write(wrap("你表达 : " + first + this_player()->query("c_name") +
	 insert + str));
    say(wrap(first + this_player()->query("c_name") + insert + str));
    return 1;
}

int
help() {
  write(@HELP
指令格式: emote <动作词>
这条指令可以让你表达一个系统没有预设的动作词。
系统会将你输入的文字后加上你的姓名后显示给同一个地区的生物看。

例：emote 大笑
    在同一地区的生物都会看到：->x大笑 (x=使用指令人名)

相关指令有：semote
HELP
);
  return 1;
}
/* EOF */
