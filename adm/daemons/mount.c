#include <mudlib.h>
#include <move.h>

int mount(object me,object who)
{
	object ob, *inv,mount_ob;
	string master_name;
	int master_skill, i;

	seteuid(getuid());
	master_skill = who->query_skill("riding");
	if( master_name = (string)me->query("master") ) {
		if ( !find_player(master_name) ) {
			me->delete("master");
			me->delete("mountable");
		} else
	// This beast has a master, check it.
		if( master_name != (string)who->query("name") ) {
			tell_object(who,
				sprintf("��ֻ%s�Ѿ���������.��\n",me->query("c_name")));
			return 1;
	    }		
	} 
	if( !me->query("mountable") ) {
	// This is a wild beast.
		if( master_skill/2 + random(master_skill/2) > (int)me->query_level() * 5 ) {
			me->set("mountable", 1);
			tell_object(who,sprintf("������%s�ı��ϣ����ҳɹ��ؽ���ѱ���ˣ�\n",me->query("c_name") ));
			tell_room( environment(me), 
				sprintf("%s����%s�ı��ϣ����ҳɹ���ѱ��������\n" ,
				who->query("c_name"),me->query("c_name") ), who );
			me->cease_all_attacks();
		} else {
			tell_object(who,sprintf("����ͼ����%s���ϣ����Ǻܿ��ˤ��������\n",me->query("c_name")));
			tell_room( environment(me), 
				sprintf("%s����%s�ı��ϣ����Ǻܿ�ر�ˤ��������\n",
				who->query("c_name"),me->query("c_name")), who );
			me->kill_ob(who);
			who->block_attack(8);
			return 1;
		}
	} else if( master_skill < (int)me->query_level() * 4 ) {
	// Check if the ider is qualified.
		tell_object(who, 
			"����������������������Ǳ��Եĺ�.��\n");
		return 1;
	}
	seteuid(getuid());
	mount_ob = new("/std/mount_obj");
	mount_ob->set("mount_ob",base_name(me));

	mount_ob->set_name(me->query("name"),
				me->query("c_name"));
	mount_ob->set("long",me->query("long"));
	mount_ob->set("short",me->query("short"));
	mount_ob->set("unit",me->query("unit"));
	mount_ob->set("id",me->query("id"));
	mount_ob->set("max_load",me->query("max_load"));
	mount_ob->set("hp",me->query("hit_points"));
	if( (int)mount_ob->move(who) != MOVE_OK ) {
		mount_ob->remove();
		tell_object(who,"�޷��������� !! ��֪ͨ��ʦ���� !\n");
		return 1;
	}
		
	who->set_temp("mounting", mount_ob);
	
	tell_object(who,sprintf("������%s ���ϣ����Ҫ�������� dismount��\n",me->query("c_name")));
	tell_room( environment(who), 
		sprintf("%s����%s�ı���.��\n" ,
		who->query("c_name"),me->query("c_name")), who );
         who->set("player_invisible",0);
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		inv[i]->set("on_mounted",1);
		inv[i]->delete("equipped"); 
		if( (int)inv[i]->move(who) != MOVE_OK ) {
			inv[i]->delete("on_mounted");
			inv[i]->move(environment(who));
		}
	}
	me->remove();
	return 1;
}

int dismount(object me,object who)
{
	int i;
	object *inv, horse,mount_ob;
	string horse_name;

	if ( !horse_name = (string)me->query("mount_ob") ) return 0 ;
	mount_ob = new(horse_name);
	mount_ob->move(environment(who));
	// clear all objects in new horse.
	if ( inv = all_inventory(mount_ob))
		for ( i = 0 ; i < sizeof(inv) ; i ++) {
			inv[i]->delete("equipped");
			inv[i]->remove();
		}
	// recover new horse's hp
	mount_ob->set("hit_points",(int)me->query("hp"));
	mount_ob->set("master",(string)who->query("name"));
	mount_ob->set("mountable",1);

	tell_object(who,sprintf("���%s�ı�����������.��\n",mount_ob->query("c_name") ));
	tell_room( environment(who), 
		sprintf("%s��%s �ı�����������.��\n" ,
		who->query("c_name"),mount_ob->query("c_name")),
		who );

	who->delete_temp("mounting");

	inv = all_inventory(who) - ({ me });	
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("on_mounted") ) {
			inv[i]->move(mount_ob);
			inv[i]->delete("on_mounted");
		}
	}
	me->remove();
	return 1;
}

int scare_me(object me)
{
	return 1;
}