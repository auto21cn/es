// chinese_d.c
// A minor chinese-english or english-chinese converter.
// by Annihilator@Eastern.Stories 09-27-93
#include <mudlib.h>

#define DICTIONARY "/adm/etc/dictionary"
#define OLD_DICTIONARY "/adm/etc/dictionary.old"

inherit SAVE;

string *c_digit;
string *c_num;

mapping dict = ([]);

void add_translate( string key, string chinz );
void remove_translate( string key );
varargs void make_dictionary();
varargs void read_dictionary();

void create()
{
	seteuid(getuid());
	set_persistent(1);
	save::create();
	make_dictionary(1);
	read_dictionary();
	c_digit = ({
		"零", "十", "百", "千", "万", "亿", "兆"
	});
	c_num = ({
		"零", "一", "二", "三", "四", "五", "六", "七", "八", "九", "十"
	});
}

// This is called by to_chinese() simul_efun
string chinese(string str)
{
	if( !undefinedp( dict[str] ) ) return dict[str];
	else return str;
}

void remove_translate( string key )
{
	map_delete( dict, key );
	save_data();
}

void add_translate( string key, string chinz )
{
	dict[key] = chinz;
	save_data();
}

varargs void make_dictionary(int old)
{
	string *key, dictionary;
	int i;

	if( !old ) dictionary = DICTIONARY;
	else dictionary = OLD_DICTIONARY;
	rm(dictionary);
	key = sort_array( keys(dict), "sort_dictionary", this_object() );
	for( i=0; i<sizeof(key); i++ )
		write_file(dictionary, key[i] + "==" + dict[key[i]] + "\n" );
}

varargs void read_dictionary(int old)
{
	string *entry, key, chinz, dictionary;
	int i;

	if( old ) dictionary = OLD_DICTIONARY;
	else dictionary = DICTIONARY;
	entry = explode( read_file(dictionary), "\n" );
	for( i=0; i<sizeof(entry); i++ ) {
		if( sscanf(entry[i], "%s==%s", key, chinz)!=2 ) continue;
		dict[key] = chinz;
	}
}

string c_number(int i)
{
	if( i<11 ) return c_num[i];
	if( i<20 ) return c_num[10] + c_num[i-10];
	if( i<100 ) {
		if( i%10 ) return c_num[i/10] + c_digit[1] + c_num[i%10];
		else return c_num[i/10] + c_digit[1];
	}
	if( i<1000 ) {
		if( i%100==0 )
			return c_num[i/100] + c_digit[2];
		else if( i%100 < 10 )
			return c_num[i/100] + c_digit[2] + c_num[0] + c_number(i%100);
		else if( i%100 < 20 )
			return c_num[i/100] + c_digit[2] + c_num[1] + c_digit[1] + c_num[i%10];
		else return c_num[i/100] + c_digit[2] + c_number(i%100);
	}
	if( i<10000 ) {
		if( i%1000==0 )
			return c_num[i/1000] + c_digit[3];
		else if( i%1000 < 100 )
			return c_num[i/1000] + c_digit[3] + c_digit[0] + c_number(i%1000);
		else
			return c_num[i/1000] + c_digit[3] + c_number(i%1000);
	}
	return c_number(i/10000) + c_digit[4] + ((i%10000<1000)? c_digit[0]:"") + c_number(i%10000);
}

int sort_dictionary(string str1, string str2)
{
	if( str1 > str2 ) return 1;
	else if( str1 < str2 ) return -1;
	else return 0;
}
