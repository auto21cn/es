//  File  :  /include/login.h
//
//  Login daemon's include macros
 
#define NEWS_FILE		"/adm/news/news"
#define MOTD_DIR		"/adm/motd/"
#define NPLAYER_INTRO	"/adm/news/nplayer_intro"
#define NPLAYER_NEWS	"/adm/news/nplayer_news"

#define DEFAULT_LOGIN_OPTIONS ([\
	"USER_LIST" : 1,\
	"IRC_USER_LIST" : 0,\
	"IRC_CHANNEL" : 0,\
	"ADMIN_LOCK": 0,\
	"ARCH_LOCK" : 0,\
        "WIZ_LOCK" : 0,\
        "MAX_USERS" : 60,\
	"EXTRA_USERS" : 0,\
	"MAX_IRC_USERS" : 0\
	])

//	This is the directory of valid user bodies, the %s is rquired for inner
//	use.
#define VALID_BODY_FILE	"/std/user_ob/%s"
 
//  The old unix-style login prompt
 
//#define LOGIN_MSG "\n" + version() + " (" + mud_name() + ")\n"
//#define LOGIN_PROMPT "\nlogin: "
//#define PASSWORD_PROMPT "password: "
 
//  Standard mud-style login prompt
#define OPEN_CHAT_ROOM 
#define LOGIN_MSG read_file("/adm/news/welcome") + "\n" + \
	capitalize(mud_name()) + "Ŀǰʹ��: " + \
	"Mudlib: " + MUDLIB_VERSION + "\n" + \
	"Driver: " + version() + "\n"

#define IP_FAIL "\n\t��Ǹ, ��Ϊ���IP ADDRESS �޷����, �޷����붫������.��\n\n"

#define BANISH_REPORT "\n\n\t��Ǹ, ��ΪĳЩԭ��, �������Ե�IP ����Ϊ�ܾ�������,��" + \
                      "\n\t�����κ�����, ���ɱ��IP �͹���������.��\n"
                      
#define WELCOME "/adm/news/welcome"
#define C_WELCOME "/adm/news/c_welcome"	
#define LOGIN_PROMPT "��������Ľ�ɫ����: (Ӣ��): "
#define PASSWORD_PROMPT "����������: "
 
#define ONE_GUEST 
 
//  Define BANISHED_NAMES if you want the name-banning code held in
//  /adm/daemons/banish.c to function.
 
#define BANISHED_NAMES

//  Define BANISHED_SITES if you want the site-banning code held in
//  /adm/daemons/banish.c to function.  This does not affect the
//  functioning of the /adm/etc/access.allow file.

#define BANISHED_SITES
 
//  Define EMAIL_REGISTRATION if you want the mail-registry code held in
//  /adm/daemons/banish.c to function.

//#define EMAIL_REGISTRATION
 
//  If NO_LOGIN_PAUSE is defined, then a pause will not be given during
//  the login process. Otherwise, a pause will be given after the
//  login news are displayed.
 
// #define NO_LOGIN_PAUSE