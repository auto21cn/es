#include <money.h>
#include <move.h>
#include <mudlib.h>

inherit DAEMON;

int help();

void init()
{
  add_action("do_drop","drop");
  add_action("do_auction","auction");
//  add_action("do_get_off","get_off");
}

int do_get_off()
{
  tell_object(this_player(),
              "你不知道著了什麽魔，居然弃船跳下水......\n"
              "咕噜咕噜喝了一肚子水，差一点就淹死，总算福大命大又爬回船上来．\n"
              );
  this_player()->receive_damage(20);
  return 1;              
}

int do_auction(string arg)
{
  tell_object(this_player(),
    "茹比货运公司的经理跑来对你说 :对不起, 我们没有提供送货到水上的服务喔!!\n");
  return 1;
}

int do_drop(string str)
{
	mapping coins;
	object *inv, ob, env, player;
	int res, amount, capac, i, money;
	string short, *types, type, word, tmp, unit, c_name, cap_name, name;

    player = this_player();
    env = environment(player);
	c_name = (string)player->query("c_name");
	name = (string)player->query("name");
	
	if( !str ) return help();
	if( !env )
		return notify_fail("你没有办法在这里丢任何东西。\n");

	player->block_attack(2);
	if(sscanf(str, "%d %s %s", amount, type, tmp) == 3 ||	
	sscanf(str, "%d %s", amount, type) == 2) {
		if( !player->debit( type, amount) )
			return notify_fail( 
				"你没有那麽多"+to_chinese(type+" coin")+"。\n"
				);
		ob = clone_object(COINS);
		ob->set_type(type);
		ob->set_number(amount);
		res = ob->move(env);
		if( res != MOVE_OK ) {
			player->credit( type, amount );
			ob->remove();
			return notify_fail( 
				"你不能再丢东西了。\n");
		}
		if(amount == 1) word = "coin"; else word = "coins";
		write( "你丢下 "+amount+" 枚"+to_chinese(type+" coin")+"。\n"
			);
		tell_room( env, 
		c_name+"丢下一些"+to_chinese(type+" coin")+"。\n", player);
		    tell_room( env, 
			  "但是全部都滚到水底下去了。\n"
		    );
		    ob->remove();
		return 1;
	}

	if( str == "all" ) {
		inv = all_inventory(player);
		if( !pointerp(inv) && sizeof(inv)<1 )
			return notify_fail( 
				"你身上没有任何东西可丢。\n");
		for( i=0; i<sizeof(inv); i++ ) {
			if( !inv[i] || inv[i]->query("prevent_drop") ||
				inv[i]->query("secure") ) continue;
			res = inv[i]->move(env);
			if( !inv[i] || res != MOVE_OK ) continue;

			short = (string)inv[i]->query("short");
			if( !(unit = inv[i]->query("unit")) ) unit = "个";
			if( !short ) short = "某物";
			write( "你丢下一"+unit+short+"。\n");
			tell_room( env, 
				c_name+"丢下一"+unit+short+"。\n", player
			);
			inv[i]->delete("on_mounted");
			  tell_room( env, 
			    "只听见扑通一声，就沉入到水底下去了。\n", player
		      );
			  inv[i]->remove();
		}
		write( "你将身上所有能丢的东西丢下。\n");
		return 1;
	}
	if(str == "all coins") {
		coins = player->query("wealth");
		if(!mapp(coins) || sizeof(coins) == 0)
			return notify_fail(
				"你身上没有任何钱币。\n");
		types = keys(coins);
		if(!pointerp(types) || sizeof(types) == 0) 
			return notify_fail(
			"你身上没有任何钱币。\n");

		for(i = 0; i < sizeof(types); i++) {
			money = coins[types[i]];
			if(money == 0) continue;
			player->debit( types[i], money );
			ob = clone_object(COINS);
			if (!ob) { 
				write("钱币发生错误,请通知巫师处理 !!\n");
			    continue;
			}  
			ob->set_type(types[i]);
			ob->set_number(money);

			res = ob->move(env);

			if(res != MOVE_OK) {
				player->credit( types[i],money );
				ob->remove();
				continue;
			}
			if(money == 1) word = "coin"; else word = "coins";
			write( 
				"你丢下 "+money+" 枚"+to_chinese(types[i]+" coin")+"。\n");
			tell_room( env, 
				c_name+"丢下一些"+to_chinese(types[i]+" coin")+"。\n",player
			);
			  tell_room( env, 
			    "只听见扑通一声，就沉入到水底下去了。\n"
		      );
			  ob->remove();
		}
		return 1;
	}

	if(sscanf(str, "all %s", type) == 1) {
		money = player->query("wealth/"+type);
		if(!money)
			return notify_fail(
				"你身上没有这种钱币。\n");

		player->debit( type, money );
		ob = clone_object(COINS);
		ob->set_type(type);
		ob->set_number(money);
		res = ob->move(env);
		if(res != MOVE_OK) {
			player->credit( type, money );
			ob->remove();
			return notify_fail(
				"你不能再丢东西了。\n");
		}
		write( "你把身上所有的" + to_chinese(type+" coin")+"丢下。\n"
			);
		tell_room( env, 
			c_name+"丢下一些"+to_chinese(type+" coin")+"。\n",player
	    );
		    tell_room( env,
			    "只听见扑通一声，就沉入到水底下去了。\n"
		    );
			ob->remove();
		return 1;
	}

	ob = present(str, player);
	if( !ob )
		return notify_fail("你身上没有这样东西。\n");
 
    if( ob->query("prevent_drop") || ob->query("secure") )
 		return notify_fail( "你没有办法将它丢掉。\n");

	res = ob->move(env);
	if(res != MOVE_OK)
		return notify_fail( "你没有办法把它丢在这里。\n");

	if( !(unit= ob->query("unit")) ) unit = "个";
	write( "你丢下一"+unit+ob->query("short")+"。\n");
	tell_room( environment(this_player()), 
		c_name+"丢下一"+unit+ob->query("short")+"。\n",player
    );
    ob->delete("on_mounted");
		tell_room( env, 
			"只听见扑通一声，就沉入到水底下去了。\n");
        ob->remove();
	return 1;
}

int help()
{
	write(@HELP
Usage: drop <item | all>
This makes your character try to drop the specified
item.  If all is used then your character drops all
items carried. If you type \"drop all gold\" or other
type, then all of your coins of that type are dropped.
\"Drop all coins\" drops all your money.

See also: get, put.
HELP
);
	return 1;
}
