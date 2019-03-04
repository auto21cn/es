#include <mudlib.h>
inherit OBJECT;
inherit MESSAGE;

int	busy;

void	create()
{
	set_name("chain firework", "连环烟火");
	set_short( "连环烟火");
	set( "long", "@@long_desc" );
	set( "id", ({"chain", "firework"}));
	set( "unit", "个" );
	set( "weight", 20 );
	set( "value", ({ 5000, "silver" }) );
	busy = 0;
}

void	init()
{
	add_action("do_light", "light");
	add_action("write_message", "write");
}

string	long_desc()
{
	string s;

	s = @CLONG
这是一个烟火, 不过似乎大了些。点燃 (light) 它不知道会发生什麽事...
烟火的上面有块地方可以写字, 上面写著:
LONG
	;
	if (query("firework_message"))
		s = s + query("firework_message") + "\n";
	else 
		s = @CLONG1
这是一个烟火, 不过似乎大了些。点燃 (light) 它不知道会发生什麽事...
烟火的上面有块地方可以写字。
CLONG1
	;
	return s;
}

int		write_message( string s )
{
	string	msg, ob_name;
	object	ob;

	if (!s)	return notify_fail( "write <Your Messages> on firework\n" );
	if (sscanf( s, "%s on %s", msg, ob_name) != 2)
		return notify_fail( "你想把文字写到哪去?\n" );
	if (!ob = present(ob_name) || ob != this_object() )
		return notify_fail( "这东西写了也没用\n" );
	set( "firework_message", msg );
	emote( "$NS把文字写在烟火上\n", this_player() );
	return 1;
}

int		do_light(string s)
{
	object	ob;

	if (busy) return nnotify_fail( "这个烟火已经被点燃了\n" );
	busy = 1;
	if (!s) return notify_fail( "你想点燃什麽?\n" );
	if (!ob = present(s) || ob != this_object() )
		return notify_fail( "这里没有这种东西\n" );
		
	emote( "$NS将烟火点著, 然後掩住耳朵迅速地躲到一边。\n", this_player() );
	tell_room( environment( this_player()), 
		"接著传来一声砰然巨响, 你看著巨大的火焰把烟火炸上半空中\n");
	call_out( "firework_effect", 10, 0, this_object() );
	return 1;
}

void	firework_effect( int life, object me )
{
	string	*cmsg, tmsg, wmsg;
	string	*s1, *s2;
	int		color;
	object	*usr;
	int		i, user_number;

	color = random (6);
	s1 = ({ "HIR", "HIM", "HIY", "HIG", "HIB", "HIC" });
	s2 = ({ "红",  "粉红", "黄", "绿",  "蓝",  "紫" });
	
	cmsg = ({
	"「砰!」的一声中, 一枚$C色的小火球在天空爆开, 化成无数美丽的火花。\n",
	"在天空中的火花慢慢黯淡时, 又有一颗$C色的火球飞上好高、好高的天空, 然後\n"
	"展开成为美丽的极光慢慢落下。\n",
	"在极光的背景中, 三颗火球由地面飞出, 一颗在比较低的天空中爆炸, 数以千计\n"
	"的$C色火花成抛物线飞散开来。\n",
	"第二颗火球炸开, 对称散射的火焰形成了一朵漂亮的菊花。\n",
	"第三颗火球穿过菊花般的火焰, 高高地向上飞去, 炸开的火焰竟然形成了文字!\n"
	"上面写著「$W」\n"
	});
	
    if(me->query("firework_message"))
    	wmsg = me->query("firework_message");
    else wmsg = "我是呆子";
    usr = users();
    user_number = sizeof(usr);
    tmsg = replace_string(cmsg[life], "$C", s2[color]);
    tmsg = replace_string(tmsg, "$W", wmsg);
    
    for ( i=0; i < user_number; i++ )
    {
    	tell_object( usr[i], set_color( tmsg, s1[color], usr[i]));
    }
    
    if (++life < sizeof(cmsg)) 
    	call_out( "firework_effect", 10, life, me);
	else me->remove();
}