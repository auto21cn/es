// File: /d/noden/drow/r12.c
// Generated by Roommaker Mon Nov 27 14:22:14 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("诺思大神殿");
	ob->set_long( @LONG_DESCRIPTION
当你进来时，被眼前巨大的神像所吸引，一股香烟袅袅的气味扑鼻而来，    
来，这里就是黑暗精灵村中最伟大的建筑工艺－－诺思大神殿－－。
黑暗精灵族人供奉的邪神－司娜可女神－是个有八个头的巨大神像，相传
在古老的年代时，就有勇者曾企图打败她，而被封在水晶中，这故事似乎
有一段渊源，你是否该看看这神像呢？
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"north" : "/d/noden/drow/r06" ]) );
	ob->set( "objects", ([ 
		"salin" : "/d/noden/drow/mob/salin" ]) );
	ob->reset();
}
