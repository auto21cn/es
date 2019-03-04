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
            if( !(short = (string)ob->query("short")) ) short = "ĳ��";
                        if( !(unit = (string)ob->query("unit")) ) unit = "��"; 
                write(
                    sprintf("���%sһ%s%s��\n",
                                target->query("c_name"),unit,short )
                     );
                tell_room( environment(me),
                        sprintf("%s��%sһ%s%s��\n",
                    me->query("c_name"),target->query("c_name"),unit,short),
                                        ({me, target}) );
                tell_object(target,
                        sprintf("%s����һ%s%s��\n",
                    me->query("c_name"),unit,short )
                    );
                        // if target is NPC, call special func if exists.
                        if( !userp(target) )
                                target->accept_item( me, ob );
                        return 1;
                }
                write(target->query("c_name")+"�ò����ˡ�\n");
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
        return notify_fail("����һƬ��ڣ�ʲ��Ҳ��������\n");
 
        this_player()->block_attack(2);
        if( sscanf(str, "%d %s to %s", amount, type, who) == 3 ) {
                money = this_player()->query("wealth/"+type);
                if( money < amount )
            return notify_fail("��....��û�������Ǯ��\n");

        who = lower_case(who);
                target = present(who, environment(this_player())) ;
                if( !target || !living(target) || !visible(target,this_player()) )
            return notify_fail("��˭ ?\n");
                if( target->query("prevent_give_money") )
              return notify_fail("�����ϲ��ܴ�Ǯ!\n");
           // Add by Yueh to prevent wizard giving money to others
             if ((wizardp(this_player()))&&(living(target)))
                return notify_fail("��ʦ���ܸ���������Ǯ��\n");
              
                this_player()->debit( type, amount );
                if( !target->credit( type, amount ) ) {
                        this_player()->credit( type, amount );
            return notify_fail(
                target->query("c_name")+"�Ѿ��᲻�����������ˡ�\n");
                }
                
                // if target is NPC, call special func if exists.
                if( !userp(target) )
                        target->accept_money(type, amount);
                
        write(
            sprintf("��ӿڴ��ͳ� %d ö%s��%s��\n",amount,to_chinese(type+" coin"),
            target->query("c_name") )
             );
        tell_room( environment(this_player()),
                sprintf("%s�ӿڴ��ͳ� %d ö%s��%s��\n",
                        this_player()->query("c_name") ,amount,
                        to_chinese(type+" coin"),target->query("c_name")),
                        ({ this_player(), target }) );
        tell_object(target,
                sprintf("%s�ӿڴ��ͳ� %d ö%s���㡣\n",
                        this_player()->query("c_name"),amount,
                        to_chinese(type+" coin") ) );
                return 1;
        }
 
                // give all such a type to target, added by Kyoko.
        if( sscanf(str, "all %s to %s",type, who) == 2 ) {

            who=lower_case(who);
                target = present(who, environment(this_player()));
                if( !target || !living(target) || !visible(target, this_player()) )
            return notify_fail( "����û�������....��\n" );
                if( target->query("prevent_give") )
            return notify_fail( "�����ϲ��ܴ��κζ���!\n");
 
                items = filter_array(all_inventory(this_player()),
                        "is_this_type", this_object(), type );
                        
                if( sizeof(items) == 0 )
            return notify_fail("������û��������Ʒ��\n" );
                        
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
            return notify_fail( "����û�������....��\n" );
                if( target->query("prevent_give") )
            return notify_fail( "�����ϲ��ܴ��κζ���!\n");
 
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
            return notify_fail("�����ϲ�û������������\n");
         
                if( ob->query("prevent_drop") || ob->query("secure") )
            return notify_fail("�㲻�ܰ�������������.\n");
 
        who =lower_case(who);
                target = present(who, environment(this_player()));
                if( !target || !living(target) )
            return notify_fail("����û������ˡ�\n");
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
ʹ�ø�ʽ: give <��Ʒ����all> to <����>
          give <��Ŀ> <��Ʒ����> to <����>
                 
���ָ���������Ʒ���������������ͬһ����.

����: give all to echobomber(������ȫ����Ʒ��echobomber) ,
      give 100 silver to kyoko(������100silver��kyoko) .

���ָ��:get,put
LONG
        );
        return 1;
}