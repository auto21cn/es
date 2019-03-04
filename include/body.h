//  File  :  /include/body.h
//
//  The general user body defines (used by USER, GHOST, and MONSTER)
//  ----------------------------------------------------------------
 //  Define DEBUG if you wish to get a debug output of various
//  user processes, particularily during setup()
//#define DEBUG
 
//  Define LOGOUT_MSG to be the message displayed to users as they
//  logout from the mud.
#define LOGOUT_MSG 	"���� ES ֮��, ��һ�����! С����Ĺ���Ŷ ^_^ �ݰݡ�\n"

//  Define IDLE_DUMP to equal the number of seconds a player 
//  may be idle before call_idle_dump() is initiated within the player.
//  WIZ_IDLE_DUMP is for wizard players. Added by Annihilator@Eastern.Stories
#define USE_IDLE_DUMP
#define IDLE_DUMP 		  20 * 60
#define WIZ_IDLE_DUMP	  60 * 60
#define ADM_IDLE_DUMP    180 * 60

//  Define LINKDEAD_DUMP to equal the number of seconds a linkdead
//  statue can exist before it is removed.
#define USE_LINKDEAD_DUMP
#define LINKDEAD_DUMP 	     20 * 60
#define WIZ_LINKDEAD_DUMP    60 * 60
#define ADM_LINKDEAD_DUMP    60 * 60

//  Define AUTOSAVE to the number of seconds in the interval between
//  the auto save of character data.
#define AUTOSAVE 	23 * 60

//  Define GHOST_START_LOCATION to where you want the ghost of a player
//  to appear after their death.  Simply undefine it if you want it to
//  stay with the player's corpse.
#define GHOST_START_LOCATION	"/d/noden/farwind/cemetery"

//  Define BAD_FORCE_VERBS to be an array of verbs that you do not wish
//  called by the body.c's force_me() - command() combination.
#define BAD_FORCE_VERBS	({ "nuke", "rm", "rmdir", "demote", "shutdown", \
	"dewiz", "changepath", "cp", "mv", "master", "force", "makewiz",\
	"wall", "tsh","sponsor", "trace", "path", })
 
// Define REAPPEAR_AT_QUIT if you want players to reappear at the place
// they were when they quit, next time they log in.
// #define REAPPEAR_AT_QUIT 1
 
// Define MESSAGE_BUFFER if you wish to allow users to store incoming messages
// in a buffer while they are busy (ie: writing a board/mail note)
#define MESSAGE_BUFFER

// the max number of alias & nickname a user can set.
#define MAX_ALIAS_SIZE       120
#define MAX_ALIAS_NUMBER     40
#define MAX_NICKNAME_NUMBER  20
#define MAX_TICK	8
// enable the okip check.
#define ENABLE_OKIP_CHECK     1
// enable total wealth check.
#define ENABLE_MONEY_CHECK    1
// the max money each level can carry, unit silver coin.
#define MAX_MONEY_EACH_LEVEL  60000

// the default corpse object.
#define DEFAULT_CORPSE        "/obj/corpse_new.c"
