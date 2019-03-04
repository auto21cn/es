// cube.c  For magic-cube spell     By Yueh@Eastern_Story 1995/3/2  
// special thanks for Ega's help////#pragma save_binary
#include <move.h>
#include <mudlib.h>
#include <money.h>
#include "/d/magic/magic.c"
#define TYPE "misc"
inherit OBJECT;

#define TRANSFER_SP 10
#define G_EXP 4
string query_long();

void create()
{
	set_name("magic cube", "ħ������");
	add( "id", ({ "cube" }) );
	set_short("ħ������");
	set("long", "@@query_long");
	set( "extra_look", "$N����Ʈ����һ�����������â��ħ�����顣\n");
	set("weight", 0);
	set("weight_apply", 0 );
	set("max_load", 400);
	set("value", ({ 1500, "silver" }));
	set("prevent_insert", 1);
	set("prevent_drop",1);
	set("prevent_put_money", 1);
}

void init()
{
   add_action("do_transfer","transfer");
}
   
int receive_object(object ob)
{
        int weight ;
        weight = ob->query("weight") ;
        if ( weight + this_object()->query("load") >
                this_object()->query("max_load") )
                return 0;
        this_object()->add("load",weight);
        return 1;
}

int release_object(object ob)
{
        this_object()->add("load",-ob->query("weight"));
        return 1;
}
   
int help ()
{
return notify_fail( "ָ���ʽ: transfer <����> into cube \nָ���ʽ: transfer <����> from cube \n");
}

int query_sp_cost(object caster)
{
	return modify_sp_cost(caster, TRANSFER_SP, TYPE, 25);
}

int transfer_into (string this)
{
	int res, num, has,sp;
	object ths,tht,ob;
	string that ,c_word;
 
	sp = query_sp_cost(this_player());
	if (this_player()->query("spell_points") < sp){
		write ("��ķ���������\n");
		return 1;
	}

	ths = present(this, this_player());
 
	if(!ths) {
		write( "��û������������\n");
		return 1;
	}

	if((int)ths->query("prevent_drop")) {
		write( "��û�а취���������ת�ͽ�ȥ��\n");
		return 1;
	}
 
	if((int)ths->query("prevent_insert")) {
		write( "�㲻�ܰ����ֶ���ת�Ž�ȥ��\n");
		return 1;
	}

	res = (int)ths->move(this_object());

	if(res == MOVE_OK) {
		c_word = ths->query("short");
		write( "�����������������ϵ�" + c_word + "������ʧ��ħ�������\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "����������������ϵ�" + c_word + "������ʧ��ħ�������\n",
			this_player());
		this_player()->add("spell_points", -sp );
		gain_spell_experience(this_player(), TYPE, G_EXP);
		return 1;
	}
 
	if(res == MOVE_NO_ROOM) 
		write( "����ռ䲻����\n");
 
	else if(res == MOVE_TOO_HEAVY) 
		write( "��������̫���ˡ�\n");
 
	else if(res == MOVE_NOT_ALLOWED) 
		write( "�㲻��������Ŷ�����\n");
 
	return 1;

}

int transfer_from(string this)
{
	int res, i,j, num, has, sp;
	object ths, tht, *contents;
	string that, c_word;
 
// Check for the form "transfer thing from sack".

	sp = query_sp_cost(this_player());
	if (this_player()->query("spell_points") < sp){
		write ("��ķ���������\n");
		return 1;
	}

	tht = this_object();

	if (this != "all") {
		ths = present(this, tht);
		if(!ths) {
			write( "��û������������\n");
			return 1;
		}

		c_word = ths->query("short");
		res = (int)ths->move(this_player());
		if( res == MOVE_OK ) {
			write ( "��������������ħ�������зɳ�"+c_word+"���������������\n");
			tell_room( environment(this_player()), 
				this_player()->query("c_name")+"�������������ħ�������зɳ�"+c_word+"���������������\n",
					this_player() );
			this_player()->add("spell_points", -sp );
			gain_spell_experience(this_player(), TYPE, G_EXP);
			return 1;
		}
		if( res == MOVE_NOT_ALLOWED ) 
			notify_fail( "��û�а취��������������\n");
		if( res == MOVE_NO_ROOM )
			notify_fail( "������û�ж��ŵĿ�λ��\n");
			// This should never happen.
		if( res == MOVE_TOO_HEAVY )
			notify_fail("̫���ˣ����ò�����n");
		return 0;
	}

// If we got here, it means we're doing a "transfer all from cube".
	contents = all_inventory(tht);
	j = sizeof(contents);
	if ( j> 0 ) {
		for (i=0;i<j;i++) {
			ths = contents[i];
 
			if((int)ths->query("prevent_get")) {
				write( "�㲻������" + ths->query("short") + "��\n");
				continue;
			}
 
			c_word = ths->query("short");
			res = (int)ths->move(this_player());
			if (res == MOVE_OK) {
			write ( "��������������ħ�������зɳ�"+c_word+"���������������\n");
			tell_room( environment(this_player()), 
				this_player()->query("c_name")+"�������������ħ�������зɳ�"+c_word+"���������������\n",
					this_player() );
			this_player()->add("spell_points", -sp );
			gain_spell_experience(this_player(), TYPE, G_EXP);
			}
		}
	}
	else {
		write( "������ʲ��Ҳû�С�\n");
		return 1;
	}
}

int do_transfer(string str)
{
	int num;
	string this;
	if (!str) return help();
	if(!this_player()->query("vision")) {
		write( "��ʲ��Ҳ��������\n");
		return 1;
	}
	if(sscanf(str,"%d %s into cube",num, this)==2) {
	if ((this == "platinum") || (this == "gold") || (this == "silver") || (this == "copper"))
		{
		write( "�Բ���, �Ҳ����˱���Ǯ��\n");
		return 1;
		}
	return help();
	}
	if (sscanf(str, "%s into cube", this) == 1) {
		transfer_into(this);
		return 1;
	}
	if (sscanf(str, "%s from cube", this) == 1){
		transfer_from(this);
		return 1;
	}
	return help();
}

string query_long()
{
	object *inv;
	int i,j;
	mixed desc;

	desc = "����һ��Ʈ���ڿ��з��������â��ħ�����飬�ƺ����Դ��治�ٶ�����\n";
		inv = all_inventory(this_object());
		j = sizeof(inv);
		if ( j > 0 ) {
			desc += "������:\n";
			for(i=0; i<j; i++)
				desc += sprintf("  %s (%s).\n", (string)inv[i]->query("short"), (string)inv[i]->query("name"));
		}
	return desc;
}

void disappear()
{
    int i;
    object me, ths, *contents;
	me = this_object();
	contents = all_inventory(me);
	if (sizeof(contents) > 0 ) {
                tell_room(find_object_or_load("/d/mage/tower/library"),
			"һ���âʹ���������۾���\n");

		tell_room(find_object("/d/mage/tower/library"),
			"��â������ʧ�����ܿ����ˡ�\n");
		
		contents->move("/d/mage/tower/library");
	}
    tell_room( environment(environment(me)),
      "ħ���������˼��£���ʧ�ˡ�\n");

    me->remove();
}

int move( mixed place )
{
    if( objectp(place) && !living(place) )
        disappear();
    return ::move(place);
}