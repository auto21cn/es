//#pragma save_binary

// A bank card. Keeps track of how much money the player has in the bank.
// Autoloading. Can't be moved except by the player. Thus, only the player
// can pick it up if he drops it, etc.
// The actual account data is stored on the player, not on the card.
// This is done so that if the card gets dested or some such, nothing
// is lost. Only the name of the owner is kept on the card proper.
// be careful to keep track of it... :)
// The property "wealth" is a mapping whose keys are the names of the coins
// and whose values are the number of each type the player has in the bank.
// Thus, if the owning player had 50 gold and 70 sludge coins in the bank,
// the wealth property would be set to ([ "gold" : 50, "sludge" : 70 ]).
// You can put any kind of coins into this mapping you like; there are no
// checks or restrictions on the keys.
// Created by Mobydick at TMI-2, 8-28-92.

#define FILENAME "/std/cards/credit_card"

#include <move.h>
#include <mudlib.h>

inherit OBJECT;
inherit COINVALUE;

string *types;

void assign (object fellow);

void create()
{

// These are null descriptions. They should never appear in practice because
// when the bank creates a card for the player it also sets new descriptions.
// See the assign function.
	seteuid(getuid());
	set_name( "credit card", "东方故事金卡" );
	set_short( "an unowned credit card.\n", "一张空白的信用卡" );
	set_long(
		"This card lets you get money out of the bank in ES.\n",
		"你只要持有这张卡片，就可以让你在东方故事内的任何银行存钱、提款。\n"
	);
	set ("id", ({ "credit card", "card" }) ) ;
	set ("weight", 5);
	set ("prevent_drop", 1);
}

// This causes the card to be cloned and assigned to the player when he
// logs in.
// See the man page on query_auto_load for more information.
mixed *query_auto_load()
{
	return ({ FILENAME, query("owner") });
}

// This procedure sets the "wealth" property when the card is autoloaded.
// See the top comments for more information on how wealth is stored on
// the card.
void init_arg (mixed *arg)
{
	set ("owner",arg) ;
	assign(find_player(query("owner")));
}

// Probably not a good idea to let this be shadowed.
int query_no_shadow()
{
	return 1;
}

// The player can check his balance any time he wants as long as he has his
// card. If you want, you can move this procedure into the bank object; then
// he'll only be able to check his balance when he's at the bank.
void init()
{
	add_action ("balance", "balance");
}

// The assign procedure sets the short and long descriptions to include the
// player's name, and moves it into his inventory. You should never clone
// a bank card unless you immediately assign it to a player.

void assign(object owner)
{
//	seteuid(geteuid(owner));
	set_short( (string)owner->query("cap_name")+"'s golden credit card",
		(string)owner->query("c_name")+"的东方故事金卡");
	set_long(
		"This golden credit card lets "+(string)owner->query("cap_name")
		+" get money from the any bank in ES.\n"+
		"Typing 'balance' will show your bank balance.\n",
		"这是一张属於"+(string)owner->query("c_name")
		+"的黄金信用卡，你可以用它在东方故事中的任何银行存、提款。\n"+
		"用 balance 指令可以查看你目前的帐户金额。\n") ;
	::move(owner) ;
	set ("owner", owner->query("name")) ;
}

// Only the player has the right to move his bank card, ie drop it and pick
// it up. This improves security on it tremendously.

int move(mixed dest)
{
	string str ;

	sscanf (query("short"), "%s's bank card",str) ;
	if ((string)this_player()->query("cap_name")==str) {
		return ::move(dest) ;
	} else {
		if (str && dest == present( str, environment( this_player()) ) ) {
			return ::move(dest) ; /* give it back to the owner */
		}
	}
	return MOVE_NOT_ALLOWED ;
}

// Set_val sets the number of coins of type str on the player's card.

int set_val (string str, int amount)
{
	find_player(query("owner"))->set("bank_balance/"+str,amount) ;
	return 1 ;
}

// Add_val increases the number of coins of type str on the player's card.

int add_val (string str, int amount)
{
	int i ;
	object owner ;

	owner = find_player(query("owner")) ;
	if (!owner) return 0 ;
	i=owner->query("bank_balance/"+str) ;
	owner->set("bank_balance/"+str,i+amount) ;
	return 1 ;
}

// Query_val returns the number of coins of type str on the player's card.

int query_val (string str)
{
	return (int)find_player(query("owner"))->query("bank_balance/"+str) ; 
}

// Balance writes out the name of each kind of coin for which the player has
// positive amounts in the bank, and writes out the amount.

int balance()
{
	int i, flag, chinese_mode;
	mapping wealth;
	string *types;

	flag = 0;
	chinese_mode = can_read_chinese();
	wealth = find_player(query("owner"))->query("bank_balance") ;
	if (!wealth || wealth==([])) {
		write ( chinese_mode?
			"你现在银行里半毛钱也没有。\n":
			"You have no money in your bank account.\n") ;
		return 1 ;
	}
	types = keys(wealth) ;
	for (i=0;i<sizeof(types);i++) {
	    if (wealth[types[i]]>0) {
		if (flag==0) 
		    write( chinese_mode?
		    	"你目前在银行里的存款有:\n":
		    	"Your bank account contains the following coins:\n");
		write( chinese_mode?
			sprintf("   %-12s : %d\n", to_chinese(types[i]+" coin"), wealth[types[i]]):
			sprintf("   %-12s : %d\n", capitalize(types[i]), wealth[types[i]]) );
		flag=1 ;
	    }
	}
	if (flag==0)
		write ( chinese_mode?
			"你现在银行里半毛钱也没有。\n":
			"You have no money in your bank account.\n") ;
	return 1 ;
}
