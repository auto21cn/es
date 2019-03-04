#include <../hole.h>        
        
inherit MONSTER;
void create ()
{
	::create();
	set_level(8);
	set_name( "Dragon Fish","红龙" );
	set ( "id",({ "fish" }) );
	set_short( "红龙" );
	set_long(@LONG
这是一条巨大的红龙鱼。
LONG
		);
	set( "likefish",1 ) ;
	set( "unit","条" );
	set( "alignment",1000 );
	set( "moving",1 );
	set( "speed",30 );
	set_natural_weapon( 35,5,16 );
	set_skill( "unarmed",80 );
	set_natural_armor( 25,8 );
	set_c_verbs( ({ "%s用巨大的尾鳍扫向%s","%s张开长满利牙的大嘴咬向%s" }) );
	set_c_limbs( ({ "鱼鳍","尾巴","头部" }) );
	setenv( "C_MIN","一条很大尾的$N慵懒地游了过来" );
	setenv( "C_MOUT","一条很大尾的$N慵懒地向$D游了过去" );
}