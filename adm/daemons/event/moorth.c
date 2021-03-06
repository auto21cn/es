// war.c
// This daemon controls the wars in the mud. 
// By Annihilator@Eastern.Stories (1-6-94)

#define NODANIA "/d/noden/nodania/"
#define MOORTH_NPC "/d/moorth/monster/"

mapping attackers = ([
	NODANIA"nodania_r1": ({
		MOORTH_NPC"knight",
		MOORTH_NPC"mage",
		MOORTH_NPC"soldier",
		MOORTH_NPC"healer"}),
	NODANIA"castle_r1": ({
		MOORTH_NPC"knight",
		MOORTH_NPC"mage",
		MOORTH_NPC"soldier",
		MOORTH_NPC"healer"}),
	NODANIA"castle_r1": ({
		MOORTH_NPC"knight",
		MOORTH_NPC"mage",
		MOORTH_NPC"soldier",
		MOORTH_NPC"healer"}),
	NODANIA"castle_r2": ({
		MOORTH_NPC"officer",
		MOORTH_NPC"officer",
		MOORTH_NPC"soldier",
		MOORTH_NPC"soldier",
		MOORTH_NPC"soldier"}),
	NODANIA"s_gate": ({
		MOORTH_NPC"warlord",
		MOORTH_NPC"knight",
		MOORTH_NPC"knight",
		MOORTH_NPC"soldier",
		MOORTH_NPC"soldier",
            MOORTH_NPC"warlock",
		MOORTH_NPC"healer" })
]);

int on_war;
object *army;

void create()
{
	seteuid(getuid());
}

void announce( string msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
	usr[i]->quick_message(set_color(msg,"HIY",usr[i]));
	}
}

void start_war()
{
	if( sizeof(army)!=0 ) return;
	announce(
		"\n你听到天空中传来一阵尖细的笑声 ....　\n"
		"\n这个声音随後发出一阵狂笑，说道: 那个骑士已经死了，去禀告女皇陛下 ....\n"
		"\n随著声音的消失，天空整个暗了下来　\n"
	);
	call_out( "start_war1", 15 );
}

void start_war1()
{
	string *loc;
	int i, j;
	object ob, room;

	loc = keys(attackers);
	army = ({});
	call_out( "check_war", 300 );
	announce(
		"\n忽然，一道闪亮刺眼的闪电伴随著隐隐的雷声划破寂静的天空 ....　\n"
		"\n西方的天空中出现许\多像是彩虹一般的光晕，使得天空中呈现一股诡异的气氛 ....　\n"
		"\n雷思骑士团长大叫: 默尔斯人又来了！皇家骑士们，为诺顿的光荣而战吧！\n\n" );
	// Clone the attackers and put them to the pre-defined rooms.
	for(i=0; i<sizeof(loc); i++ ) {
		if( !(j= sizeof(attackers[loc[i]])) ) continue;
		// Find the room to put.
		room = find_object(loc[i]);
		if( !room ) call_other( loc[i], "???" );
		room = find_object(loc[i]);
		if( !room ) continue;

        tell_room( room,
            "突然你看到一阵烟雾从空气中升起，里面走出几条人影！\n" );
		while( j-- ) {
			ob = new( attackers[loc[i]][j] );
			ob->move( room );
			army += ({ob});
		}
	}
	for( i=0; i<sizeof(army); i++ )
		army[i]->enable_war();
}


void check_war()
{
	// Remove those victims in the war.
	army -= ({ 0 });
	remove_call_out( "check_war" );
	if( !sizeof(army) ) {
           announce( "\n*** 战争结束了 ***\n\n" );
		on_war = 0;
		return;
	}
	call_out( "check_war", 300 );
}
