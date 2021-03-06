////#pragma save_binary
#include <mudlib.h>

inherit DAEMON;

int cmd_aid(string arg)
{
	object dest;
	int hp, max_hp, skill ;
        string target,target1,myname ;

        if( this_player()->query("stop_attack")!=0) 
             return notify_fail( "你的上个动作还没完成,无法施行急救。\n" );

	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail( "你要对谁施行急救？\n" );

	if( !living(dest) ) 
		return notify_fail( "那个「东西」不需要急救。\n" );
        
        target  = dest->query("c_name") ;
        target1 = dest->query("c_name") ;
        
	if( dest->query("ghost") ) return notify_fail( 
		sprintf("太迟了 .... %s已经死了。\n",target ) );
	if( dest->query("no_aid") ) return notify_fail(
	        dest->query("c_name") +
	        "笑著对你说:谢谢你的好意, 不过我想有必要时, 我自己动手可能比较好。\n"
	);	
        if( dest->query_current_attacker()!=0) 
             return notify_fail( "你的目标正在战斗中,你无法对他急救。\n" );

	hp = (int)dest->query( "hit_points" );
	max_hp = (int)dest->query( "max_hp" );

//   伤太重则不能对自己急救...

	if( dest==this_player()&& hp < max_hp/6 ) 
               return notify_fail( "你伤势太重而无法对自己施行急救。\n" );        

        if(dest == this_player())
           {
               target = "自己" ;
               target1 = "你自己" ;
            }                    

	if( hp==max_hp ) return notify_fail( 
		sprintf( "%s并没有受伤。\n",target1 ) );

	if( dest->query_temp("aided") ) return notify_fail( 
		sprintf( "%s已经被急救过了。\n",target1 ) );

	if( hp > max_hp/3 ) return notify_fail(
		sprintf("%s的伤势还没有严重到需要急救的地步。\n",target1) );

	skill = (int)this_player()->query_skill( "first-aid");
	if( !skill ) return notify_fail( 
		"你并没有学过急救的技能。\n");


	write(sprintf("你对%s进行急救 ....\n",target1) );

        myname = this_player()->query("c_name") ;
        
        if(dest != this_player())
     	    tell_object( dest, 
		sprintf("%s对你进行急救 .... 你觉得好多了！\n",myname ) );

	tell_room( environment(this_player()), 
		sprintf("%s对%s进行急救 ....\n",myname,target),
		({ this_player(), dest }) );
		
	if( dest!=this_player() ) this_player()->add( "alignment", 25 );
	dest->receive_healing( skill/2 + random(skill/2) );

 //    急救对玩家最多只能加到一半的 HP
	hp = (int)dest->query( "hit_points" );
        if( !wizardp(this_player()) && hp > max_hp/2 ) 
           dest->set("hit_points",max_hp/2) ;

	dest->set_temp( "aided", 1 );
	this_player()->receive_experience( skill );
	call_out( "remove_aided", 300, dest );
    return 1;
}

void remove_aided(object player)
{
	if( player ) player->set_temp("aided", 0);
}

int help()
{
    write(
    @C_HELP
指令格式: aid <某人>

这个指令让你对某个人物( 或 NPC )施行急救，有关急救的细节与限制请参
考 help first-aid。
C_HELP
	);
    return 1;
}
