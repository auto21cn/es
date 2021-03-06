//#pragma save_binary
 
// File: /cmds/std/_give.c
// based on TMI-2 version
// completely rewritten...cleaned up...modified
// added give all to <player>
// added give all <gold | coins> to <player>
// by Zeus, 13/03/1993
// clean up ! totally ! by Ruby@Eastern.Stories , 2/21/'94 

#include <mudlib.h>
#include <money.h>
#include <move.h>
 
#define C_CAP_NAME this_player()->query("c_name")
 
inherit DAEMON;
 
int help();
int give_item(object ob,object me,object target) 
{
        int res;
	int is_log;
   	string short,unit;

        if( !wizardp(me) || member_group(me->query("name"), "admin") ||
             wizardp(target) ) is_log = 0;
        else is_log = 1;

        
                res = ob->move(target);
                if(res == MOVE_OK) {
	    if(is_log) log_file("GIVE", extract(ctime(time()), 4, 15)+"  "+
                     me->query("name")+" give "+base_name(ob)+
                     " to "+target->query("name")+"\n" );
            if( !(short = (string)ob->query("short")) ) short = "某物";
                        if( !(unit = (string)ob->query("unit")) ) unit = "个"; 
                write(
                    sprintf("你给%s一%s%s。\n",
                                target->query("c_name"),unit,short )
                     );
                tell_room( environment(me),
                        sprintf("%s给%s一%s%s。\n",
                    me->query("c_name"),target->query("c_name"),unit,short),
                                        ({me, target}) );
                tell_object(target,
                        sprintf("%s给你一%s%s。\n",
                    me->query("c_name"),unit,short )
                    );
                        // if target is NPC, call special func if exists.
                        if( !userp(target) )
                                target->accept_item( me, ob );
                        return 1;
                }
                write(target->query("c_name")+"拿不动了。\n");
                return 1;
} 
int cmd_give(string str)
{
        object *items, *inv, ob, target;
    int res, amount, i, money;
        string short, who, item, word, *types, type, unit;
        mapping coins;
 
        if( !str ) return help();
        if( !this_player()->query_vision() )
        return notify_fail("这里一片漆黑，什麽也看不见。\n");
 
        this_player()->block_attack(2);
        if( sscanf(str, "%d %s to %s", amount, type, who) == 3 ) {
                money = this_player()->query("wealth/"+type);
                if( money < amount )
            return notify_fail("嘿....你没有那麽多钱。\n");

        who = lower_case(who);
                target = present(who, environment(this_player())) ;
                if( !target || !living(target) || !visible(target,this_player()) )
            return notify_fail("给谁 ?\n");
                if( target->query("prevent_give_money") )
              return notify_fail("它身上不能带钱!\n");
           // Add by Yueh to prevent wizard giving money to others
             if ((wizardp(this_player()))&&(living(target)))
                return notify_fail("巫师不能给其它生物钱！\n");
              
                this_player()->debit( type, amount );
                if( !target->credit( type, amount ) ) {
                        this_player()->credit( type, amount );
            return notify_fail(
                target->query("c_name")+"已经搬不动其他东西了。\n");
                }
                
                // if target is NPC, call special func if exists.
                if( !userp(target) )
                        target->accept_money(type, amount);
                
        write(
            sprintf("你从口袋掏出 %d 枚%s给%s。\n",amount,to_chinese(type+" coin"),
            target->query("c_name") )
             );
        tell_room( environment(this_player()),
                sprintf("%s从口袋掏出 %d 枚%s给%s。\n",
                        this_player()->query("c_name") ,amount,
                        to_chinese(type+" coin"),target->query("c_name")),
                        ({ this_player(), target }) );
        tell_object(target,
                sprintf("%s从口袋掏出 %d 枚%s给你。\n",
                        this_player()->query("c_name"),amount,
                        to_chinese(type+" coin") ) );
                return 1;
        }
 
                // give all such a type to target, added by Kyoko.
        if( sscanf(str, "all %s to %s",type, who) == 2 ) {

            who=lower_case(who);
                target = present(who, environment(this_player()));
                if( !target || !living(target) || !visible(target, this_player()) )
            return notify_fail( "这里没有这个人....。\n" );
                if( target->query("prevent_give") )
            return notify_fail( "他身上不能带任何东西!\n");
 
                items = filter_array(all_inventory(this_player()),
                        "is_this_type", this_object(), type );
                        
                if( sizeof(items) == 0 )
            return notify_fail("你身上没有这类物品。\n" );
                        
                for( i=0; i<sizeof(items); i++ ) {
                        if( items[i]->query("prevent_drop") ||
                                items[i]->query("secure") ) continue;

                        give_item(items[i],this_player(),target);
                }
                return 1;
        }
                
        if( sscanf(str, "all to %s", who) == 1 ) {
            who=lower_case(who);
                target = present(who, environment(this_player()));
                if( !target || !living(target) || !visible(target, this_player()) )
            return notify_fail( "这里没有这个人....。\n" );
                if( target->query("prevent_give") )
            return notify_fail( "它身上不能带任何东西!\n");
 
                inv = all_inventory(this_player());
                for(i = 0; i < sizeof(inv); i++) {
                        if( !inv[i] || inv[i]->query("prevent_drop") ||
                                inv[i]->query("secure") ) continue;
                give_item(inv[i],this_player(),target);
                }
                return 1;
        }
        
        if( sscanf(str, "%s to %s", item, who) == 2 ) {
                ob = present(item, this_player());
                if( !ob )
            return notify_fail("你身上并没有这样东西。\n");
         
                if( ob->query("prevent_drop") || ob->query("secure") )
            return notify_fail("你不能把这样东西给人.\n");
 
        who =lower_case(who);
                target = present(who, environment(this_player()));
                if( !target || !living(target) )
            return notify_fail("这里没有这个人。\n");
                give_item(ob,this_player(),target);
                return 1;
        }
        return help();
}
 
int is_this_type(object ob, string type)
{
        if( ob->id(type) && !ob->query("prevent_drop") && !ob->query("secure") ) 
                return 1;
        return 0;
}
 
int help()
{
        write( @LONG
使用格式: give <物品名或all> to <生物>
          give <数目> <物品类型> to <生物>
                 
这个指令将给生物物品，但这生物必须在同一场景.

例子: give all to echobomber(将身上全部物品给echobomber) ,
      give 100 silver to kyoko(将身上100silver给kyoko) .

相关指令:get,put
LONG
        );
        return 1;
}
