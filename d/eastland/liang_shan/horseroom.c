#include "takeda.h"

#define HORSEDIR TMONSTER"horse_"

inherit ROOM;

#define PRICE ({ 0, 1500, 2000, 3000 })
#define HORSES ({ "none", "spot_horse", "red_horse", "whitefoot_horse" })
#define AMOUNT ({ 0, 4, 2, 2 })

void create()
{
	::create();
	set_short( "马市" );
	set_long(
	"这里是一块小小的空地，人们的吆喝声此起彼落，间或夹杂著马匹\n"
	"的长啸声，这里就是梁山泊内最大的马市，由皇甫端所出资开设。\n"
	"马匹的腥□气和人们汗水的气味混杂在一起，却成了另一种充满生。\n"
	"命力的气息。在空地中央，贴了一张告示(note)。\n"
	);
	set( "light",1 );
        set_outside("eastland");
        set( "exits", ([
                "west"  : TROOM"path1",    
        ]) );
        set( "objects",([
             "boss" : TMONSTER"huanpo"
             ]));
        set("item_func",(["note": "note_msg", ]));
        set( "amount", AMOUNT );
        reset();
}

void init()
{
        add_action( "buy_horse", "buy");
        add_action( "sell_horse", "sell");
}

int note_msg()
{
	int *amount;
	amount = this_object()->query("amount");

write(
"这张告示上写著：\n\n"
"    本店提供各类马匹，价钱公道，童叟无欺，以下为现有的马种\n\n"
"     马种:                    价格:\n\n"
"   小花马  (spot_horse)     "+PRICE[1]+" 银币    只剩 "+amount[1]+" 只  \n"
"  红鬃烈马  (red_horse)     "+PRICE[2]+" 银币    只剩 "+amount[2]+" 只  \n"
"  踏雪乌骓(whitefoot_horse) "+PRICE[3]+" 银币    只剩 "+amount[3]+" 只  \n\n"
"         　　　　　ps 凡本店卖出的马匹，若不满意，本店可以半价购回\n"                                      
	);
	return 1;
}


int sell_horse(string arg)
{
 	object horse;
 	int i=0, *amount;
 	if( !arg || arg != "horse" ) {
 		return notify_fail("指令格式 : sell horse (如果你有).\n");
 		                     }
 	horse = this_player()->query_temp("now_mount");
	if( !horse )                 
		return notify_fail("老板说道:你有在这买马吗?\n");
	if( !present(horse, this_object())	) {
		tell_object( this_player(),
            "老板说道: 没错，先让我看看马吧!\n" );
        return 1;
	}

	switch( (string)horse->query("name") ) {
        case "spot_horse"  : i=1;  break;
        case "red_horse"  : i=2;  break;
        case "whitefoot_horse" : i=3;  break;
        default :
          tell_object( this_player(), 
            "老板说道: 对不起，本店不收这种东西。\n" );
          return 1;
    }

	if( i<1 || i>3 ) return 0;
	
    this_player()->credit("silver", PRICE[i]/2);
    this_player()->set_temp("now_mount", 0);
    horse->remove();
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
    tell_object(this_player(), 
        "你卖掉你的马，得到 "+(PRICE[i]/2)+" 块银币。\n"
		);
    return 1;
}

int buy_horse(string arg)
{
	object horse;
	int i=0, *amount;

	if( !arg || arg == "" )
		return notify_fail("指令格式 : buy + <马的名称>.\n");
	
	if( this_player()->query_temp("now_mount") )
    	return notify_fail("老板摇头说道: 对不起, 一个人只能买一匹马。\n");
          
	amount = this_object()->query("amount");
	if( !amount )
		return notify_fail("老板笑道: 对不起, 本店所有的马都已卖完了。\n");
          
	switch (arg) {
        case "spot_horse"  : i=1;  break;
        case "red_horse"  : i=2;  break;
        case "whitefoot_horse" : i=3;  break;
        default :
          tell_object( this_player(), 
            "老板说道: 对不起，本店没有卖 "+arg+" 这种马。\n" );
          return 1;
          break;
    }
    if( i<1 || 1>3 ) return 0;
    if( amount[i] < 1 ) {
    	tell_object( this_player(), 
          "老板说道: 对不起，本店 "+arg+" 这种马已经卖完了。\n" );
        return 1;
    }
    
    if( !this_player()->debit("silver",PRICE[i] ) )
        return notify_fail("你没有那麽多银币。\n");

	amount[i]--;
	this_object()->set("amount", amount);
    horse = new( HORSEDIR+HORSES[i] );
    horse->move( this_object() );
    
      this_player()->set_temp("now_mount", horse);
      horse->set_master( this_player() );

    tell_object(this_player(), 
        "老板牵来一匹马，邪恶地笑道：「下次记得再来喔 !!」边说边把□绳交给你\n");
    return 1;
}

void add_amount(string type)
{
	int i=0, *amount;
	
	if( !type || type == "" ) return;
	switch (type) {
        case "spot_horse"  : i=1;  break;
        case "red_horse"  : i=2;  break;
        case "whitefoot_horse" : i=3;  break;
        default : return;
    }
    if( i<1 || i>3 ) return;
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
}

void reset()
{
	set("amount", AMOUNT );
	::reset();
}
int clean_up() { return 0; }
