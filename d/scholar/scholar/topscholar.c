#define SIZE 15

#include <daemons.h>

mapping levels1;
string *top_list1;
string* sort_level(mapping lvs,string* top,string myname);

void log_player(object player)
{

	int mylevel, myage, *savedata1;
	int myguild1;
	string myname;

	if( !player ) return;
	if((string)player->query("class")!="scholar") return;
	myname = (string)player->query("name");
	if( wizardp(player) ) return;
	if( PROMOTION_D->in_wiz_list(myname) ) return;

	myguild1=(int)player->query("scholar_gonfu/han");

	mylevel = (int)player->query_level();
	myage = (int)player->query_age();
	savedata1 = ({ myguild1, mylevel, myage });
	
	if( !levels1 ) levels1 = ([]);

	if( !top_list1 ) top_list1 = ({});
	
	levels1[myname] = savedata1;

	top_list1=sort_level(levels1,top_list1,myname);
}

string* sort_level(mapping lvs,string* top,string myname)
{
	int i,loc;
	loc = member_array( myname, top );
	if( loc==-1 ) {
		if( sizeof(top) < SIZE ) {
			loc = sizeof(top);
			top += ({ myname });
		}
		else loc = SIZE;
		while( loc > 0 && (int)lvs[myname][0] >= (int)lvs[top[loc-1]][0] ) {
			if( loc < SIZE ) top[loc] = top[loc-1];
			top[loc-1] = myname;
			loc--;
		}
	} else {
		i = loc;
		while( i > 0 && (int)lvs[myname][0] > (int)lvs[top[i-1]][0] ) {
			if( loc < SIZE ) top[i] = top[i-1];
			top[i-1] = myname;
			i--;
		}
		i = loc;
		while( i < sizeof(top)-1 && (int)lvs[myname][0] < (int)lvs[top[i+1]][0] ) {
			if( loc < SIZE ) top[i] = top[i+1];
			top[i+1] = myname;
			i++;
		}
	}
	return top;
}

varargs string get_list()
{
	int i,day, hour, *savedata;
	string msg="\n";

	if( !sizeof(top_list1) ) return 	"剑法等级排行榜目前是空的。\n";
	msg += "\n汉赋剑法等级排行榜前 " + sizeof(top_list1) + " 名:\n";
	msg += sprintf(" 名次  玩家姓名           等级          上线时间                    剑法等级\n");
	for(i=0; i<sizeof(top_list1); i++) {
		savedata = levels1[top_list1[i]];
		day = savedata[2]/86400;
		hour = savedata[2]%86400/3600;
		msg += 
			sprintf("  %2d. %20-s %2d %10d 天 %2d 小时 %20d\n",i+1, 
			top_list1[i], savedata[1], day, hour, savedata[0] );
	}
	return msg;
}

int clean_up()
{
                return 0;
}
