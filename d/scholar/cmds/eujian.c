//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

int help();
/*
int cmd_eujian(string str)
{
	object me,weapon;
	mapping where;
	int i;
	string msg,dest,*node_name,first,second,n,d;
	
	me = this_player();
	weapon = (object)me->query("weapon1");
	
        if ( !str ) return help();
        
        if ( !weapon || (string)weapon->query("type") != "longblade" ) 
        	return notify_fail( "你没有适当的武器耶 !!\n" );
        
        if ( me->query_attackers() )
        	return notify_fail( "喂 !! 你还在战斗中耶，想被打下来吗 ??\n" );
        	
        if ( me->query("gonfu_busy") || me->query_temp("gonfu_busy") ) 
        	return notify_fail( "你正在使用其他功\夫，所以无法驭剑。\n" );
        
	if ( str == "where" ) {
		where = (mapping)me->query("node");
		
		if (!where || sizeof(where) == 0 ) {
			write("你不记得任何地方可以驭剑飞去。\n");
			return 1; }
		else {
		
		msg = "你目前记得的地方有 : \n" ;
		
		node_name = keys(where);
		for( i=0; i < sizeof(node_name); i++ ) 
			msg += sprintf("  %d : %s\n", i+1, node_name[i]);
		write(msg);
		return 1; } 
		}
	if ( sscanf(str, "%s %s", first, second) ) {
		write(first+second+"\n");	
		n = (string)environment(me)->query("short");
		d = base_name(environment(me));
		
		if ( first == "here" ) {
			where = (mapping)me->query("node");
		
			if (!where || sizeof(where) == 0 ) {
				me->set("node/"+n, d);
				return 1; }
			} 
		else return help(); } 
	
        if ( str == "guild" ) {
        	tell_object( me,
        		"你聚精会神、默运玄功\於剑身上，身剑合一向目的地飞去 !!\n" );
 		tell_room( environment(me), 
 			sprintf("%s手掐剑诀，身剑合一向远方飞去 !!\n", me->query("c_name")), me );       		
        	me->move_player( "/d/scholar/scholar/scholar_guild", "SNEAK" );
        	tell_room( "/d/scholar/scholar/scholar_guild", 
        		sprintf("一道银白色的剑气载著%s而来 !!\n", me->query("c_name")), me );
 		return 1; }      
	return 1;
}
*/

int help()
{
		write( @C_HELP
指令格式: eujian <参数>

这个指令让你用来驭剑飞行。你可以加上下列的参数 :

	where       :     列出你目前所记得的地方。
	guild       :     飞回公会。
	here 1,2,3  :     记住此地。
	1,2,3       :     驭剑到那儿。 
C_HELP
		);
    return 1;
}
