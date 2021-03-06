//#pragma save_binary

// This command is for monk only. It list all gonfus now the monk
// has learned. Created by Angel, almost rewriten by Kyoko@Eastern.Stories.

#include <mudlib.h>

inherit DAEMON;

int cmd_gonfus()
{
	int i, s;
	string *gonfu,  msg, tmp;
	mapping known, exp;

	known = (mapping)this_player()->query("monk_gonfu");
	exp = (mapping)this_player()->query("gonfus_exp");
	if( !known || sizeof(known) == 0 ) {
		write("你目前不会任何功\夫。\n");
		return 1;
	}


	msg = "你目前所能使用的功\夫有:\n";
	gonfu = keys(known);
	for( i=0; i<sizeof(gonfu); i++ ) {
		if( gonfu[i] == "fist" || gonfu[i]=="heal" ) continue;
		msg +=
		sprintf("%14-s(%14-s)  第%3d重  (熟练经验值%d) \n", to_chinese(gonfu[i]), 
         	capitalize(gonfu[i]),  known[gonfu[i]], ( exp ? exp[gonfu[i]] : 0 )) ;
       }

	if( gonfu = known["fist"] ) {
		tmp = "\n基本拳法: " ;
		for( i=0; i<sizeof(gonfu); i++ )
			tmp += 
				sprintf("%s(%s), ", to_chinese(gonfu[i]), gonfu[i]) ;
		msg += iwrap(tmp, 60);
	}
	if( gonfu = known["heal"] ) {
		tmp = "\n医疗心法及指法: " ;
		for( i=0; i<sizeof(gonfu); i++ )
			tmp += 
				sprintf("%s(%s), ", to_chinese(gonfu[i]), gonfu[i]) ;
		msg += iwrap(tmp, 60);
	}
        if ( this_player()->query("monk_score") ) {
	msg += sprintf("\n你对少林的贡献功\劳有 %d 点\n\n",(int)this_player()->query("monk_score"));
                                                   }
	write(set_color(msg,"GRN",this_player()));
	return 1;
}

int help()
{
	write( @HELP
用法 : gonfus
这个指令会列出目前你所通晓的功夫以及等级，另外也会列出你目前对少林寺的
贡献度。

参考 : fist
HELP
	      );
	return 1;
}
