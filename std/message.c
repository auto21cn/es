/*
Message: 用来简化一些常见动作讯息的写作
Wrote by EGA, 11-21-1994
添加关於延迟效果的演出	/EGA, 3-8-1995
*/

/* Document
NAME
	emote - 将一个动作的叙述转换成适当的文字传送给在场的人
	
SYNOPSIS
	varargs void emote( string format, object me, 
						object where, object victim);
DESCRIPTION
	format 是一个特殊格式的字串, 里面以 $NS, $NO 等符号代表动作
	者的名字、动作对象的名字等。emote 会根据後面的各个参数对这个
	字串做适当的代换, 并将处理後的讯息送给 me, victim, 以及 where
	里的所有人。
	me 是动作者, victim 则是动作的对象, where 则是动作发生的房间
	
	victim 可以略去, 此时 $NO, $GO 两个参数将不会生效。
	
	where 与 victim 可以一起略去, 此时 where 将自动被设定为 me 
	所在的房间。
	
	format 里可用的参数如下:
	$NS		me 的名字
	$NO		victim 的名字
	$GS		me 的代名词, 依性别为他、她或它
	$GO		victim 的代名词
	
	要使用 emote 函数, 你必须在你的 object 中
	inherit "/std/message.c";
	如果你先前曾经 include <mudlib> 的话, 你也可以写成:
	inherit MESSAGE;
	个人比较推荐後者。
               
EXAMPLE
	emote( "$NS抬起$GS的脚, 向$NO的屁屁重重地踢下去\n", ppla, 
			environment(ppla), pplb );
	ppla 将会看到: 你抬起了你的脚, 向 pplb 的屁屁重重地踢下去
	pplb 则会看到: ppla 抬起了他的脚, 向你的屁屁重重地踢下去
	如果 ppla 是男的话, 房间中的其他人则会看到: ppla 抬起了他的脚, 
		向 pplb 的屁股重重地踢下去
	
SEE ALSO
	emote_message
*/

/*
NAME
	emote_message_me
	emote_message_victim
	emote_message_other - 将一个动作的叙述转换成适当的文字
	
SYNOPSIS
	varargs string emote_message_me( string format, object me, 
						object where, object victim);
	varargs string emote_message_victim( string format, object me, 
						object where, object victim);
	varargs string emote_message_other( string format, object me, 
						object where, object victim);
DESCRIPTION
	与 emote 相同, emote_message_xx 会将 format 里的字串做适当的
	代换。不过并不会将讯息直接出去, 而是作为一个传回值, 让呼叫它
	的巫师自己处理。
	emote_message_me 所传回的是由 me 所会看到讯息
	emote_message_victim 所传回的则是由 victim 所会看到讯息
	emote_message_other 所传回的则是在场的旁观者所会看到讯息
	
	有时候, 一个动作的对象可能有很多个而非一个, 此时 emote 就无
	法使用。你必须对每个动作的对象做一次 emote_message_victim()
	以其传回值做 tell_object() 的动作才能得到正确的结果。
	
	emote_message 系列的函数也可以省略掉 where 与 victim, 不过
	当你省掉 victim 时, emote_message_victim 会传回空字串。因为
	没有动作的对象了。
	
	另外, me 与 victim 两个变数可以放入「非生物」的物件, 但是此
	时 format 字串中若有$GS, $GO 两个参数, 结果将无法预料。
	
SEE ALSO
	emote
*/

//PUBLIC FUNCTIONS
varargs	void	emote( string format, object me, object where, object victim);
varargs	string	emote_message_me( string format, object me, object where, 
				object victim);
varargs	string	emote_message_victim( string format, object me, object where,
				object victim);
varargs	string	emote_message_other( string format, object me, object where, 
				object victim);
varargs void	step_tell_object( mixed ob, string msg, int time_step);
varargs void	step_tell_room( mixed room, string msg, mixed exclude,
				int time_step);
varargs	void	step_object_msg( mixed ob, string message, object me, 
				object player);
varargs	void	step_room_msg( mixed room, string message, mixed exclude,
				object me, object player);

//VARIBLES
mapping	gender = (["male" : "他", "female" : "她", "neuter" : "它" ]);

varargs	void	emote( string format, object me, object where, object victim)
{
	string	me_message, victim_message, other_message;
	
	if	(where && victim)	{
//填入行动者的名字
		me_message = replace_string( format, "$NS", "你");
		victim_message = replace_string( format, "$NS", me->query("c_name") );
		other_message = replace_string( format, "$NS", me->query("c_name") );
//填入行动对象的名字
		me_message = replace_string( me_message, "$NO", victim->query("c_name") );
		victim_message = replace_string( victim_message, "$NO", "你");
		other_message = replace_string( other_message, "$NO", victim->query("c_name") );
//填入行动者的性别
		me_message = replace_string( me_message, "$GS", "你" );
		victim_message = replace_string( victim_message, "$GS", gender[me->query("gender")] );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
//填入动作对象的性别
		me_message = replace_string( me_message, "$GO", gender[victim->query("gender")] );
		victim_message = replace_string( victim_message, "$GO", gender[victim->query("gender")] );
		other_message = replace_string( other_message, "$GO", "你" );
//发送讯息给在场的人
		tell_object( me, me_message );
		tell_object( victim, victim_message );
		tell_room( where, other_message, ({me, victim}) );
	}
	else if (!victim)
	{
//填入行动者的名字
		me_message = replace_string( format, "$NS", "你");
		other_message = replace_string( format, "$NS", me->query("c_name") );
//填入行动者的性别
		me_message = replace_string( me_message, "$GS", "你" );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
//发送讯息给在场的人
		if (!where)	where = environment(me);
		tell_object( me, me_message );
		tell_room( where, other_message, me );
	}
}

// emote_message_me: 传回一个给动作者本身的讯息
varargs	string	emote_message_me( string format, object me, object where, object victim)
{
	string	me_message;
	mapping	gender = (["male" : "他", "female" : "她", "netural" : "它" ]);
	
	
	if (!format || !me) return "";
	if	(where && victim)	{
		me_message = replace_string( format, "$NS", "你");
		me_message = replace_string( me_message, "$NO", victim->query("c_name") );
		me_message = replace_string( me_message, "$GS", "你" );
		me_message = replace_string( me_message, "$GO", gender[victim->query("gender")] );
	}
	else if (!victim)
	{
		me_message = replace_string( format, "$NS", "你");
		me_message = replace_string( me_message, "$GS", "你" );
	}
	return me_message;
}

// emote_message_victim: 传回一个给动作对象的讯息
varargs	string	emote_message_victim( string format, object me, object where, object victim)
{
	string	victim_message;

	if (!format || !me) return "";	
	if	(where && victim)	{
		victim_message = replace_string( format, "$NS", me->query("c_name") );
		victim_message = replace_string( victim_message, "$NO", "你");
		victim_message = replace_string( victim_message, "$GS", gender[me->query("gender")] );
		victim_message = replace_string( victim_message, "$GO", gender[victim->query("gender")] );
	}
	else if (!victim)
	{
		victim_message = "";
	}
	return victim_message;
}

// emote_message_other: 传回一个给旁观者的讯息
varargs	string	emote_message_other( string format, object me, object where, object victim)
{
	string	other_message;
	
	if (!format || !me) return "";
	if	(where && victim)	{
		other_message = replace_string( format, "$NS", me->query("c_name") );
		other_message = replace_string( other_message, "$NO", victim->query("c_name") );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
		other_message = replace_string( other_message, "$GO", "你" );
	}
	else if (!victim)
	{
		other_message = replace_string( format, "$NS", me->query("c_name") );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
	}
	return	other_message;
}

varargs void	step_tell_object( mixed ob, string msg, int time_step)
{
	string	*msg_array;
	int		i;

	if (!time_step) time_step = 2;
	msg_array = explode( msg, "\n" );
	for ( i = 0; i < sizeof(msg_array); i++ )
	{
		call_out( "step_object_msg", i * time_step, ob, msg_array[i]+ "\n", 
					this_object(), this_player() );
	}
}

varargs void	step_tell_room( mixed room, string msg, mixed exclude,
				int time_step)
{
	string	*msg_array;
	int		i;
	
	if (!time_step) time_step = 2;
	msg_array = explode( msg, "\n" );
	for ( i = 0; i < sizeof(msg_array); i++ )
	{
		call_out( "step_room_msg", i * time_step, room, msg_array[i]+"\n", 
					exclude, this_object(), this_player() );
	}
}

varargs	void	step_object_msg( mixed ob, string message, object me, 
				object player)
{
	if ( (!me) || (!ob) )	return;
	tell_object( ob, message );
}

varargs	void	step_room_msg( mixed room, string message, mixed exclude,
				object me, object player)
{
	if ( (!me) || (!room) )	return 0;
	tell_room( room, message, exclude);
}
