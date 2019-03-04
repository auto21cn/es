#include <../goomay.h>

inherit OBJECT;

void create()
{
	seteuid( getuid() );
	set_name( "royal mark", "御赐金牌" );
	add( "id", ({ "mark" }) );
	set_short( "御赐金牌" );
	set_long(
		"这是一面御赐金牌，有了它，你就有了相当於当今皇上的权力。必要时你\n"
		 "可以把它亮(show)出来吓吓人 !\n"
	);
	set( "unit", "面" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
        add_action( "show_me", "show");
}

int show_me(string arg)
{
	string who,item;
	object target,ob;

        if( !arg || arg=="" || sscanf( arg, "%s to %s", item,who)!=2 )
                return notify_fail("你要亮(show)什麽给(to)谁看啊？\n");

	if (item != "mark")
                return notify_fail("这东西有什麽好现的？爱现 !!\n");

	if (!target=present(who,environment(this_player()))) 
		return notify_fail("这里没有这个人 !!\n" );
	
	if ( (string)target->query("name") == "Hsin the scribe" ) 
	{
		if ( !target->query("show") ) {
                tell_object( this_player(), @SHOW
邢师爷叫道：「原来是钦差大臣驾到，小的这就去通知史大人出来迎接。
请大人稍候 !! 来人啊 ... 有请大人」他急急忙忙的命人传讯。


不久，後堂转出一个身穿官服的人，对你长揖道：「古梅县令史耀前躬迎
钦差大人，不知大人枉驾有何见教」
SHOW
		);
		new(Mob"migastrate" )->move(environment(environment()) );
			  target->set("show",1);
			  return 1;
			  }
		
	}
        else if ( (string)target->query("name") == "Captain of Policeman")
        {
		if ( !target->query("show")) {
                tell_object(this_player(), 
                "段捕头叫道：「原来是钦差大臣驾到，大人要查监吗？唉 ... 这个 ...。\n"
		"这个是监牢的钥匙，请大人离去之前务必记得交还下官 !! 」。\n"
		"段飞鹰给你一把铁钥匙。\n");

		ob=new( Obj"key1" );
		ob->move( environment(this_object()) );
		target->set("show",1);
		return 1;
		}
	}
		tell_object( target ,this_player()->query("c_name")+"拿出一块东西在你面前乱晃。\n");
                tell_object( this_player(), 
                target->query("c_name")+"道：「好大一块金子啊 !! 值不少钱喔 !! 」\n");
                return 1;
}
