#include <mudlib.h>
#include "/u/s/smore/hawk.h"
inherit MONSTER;

void create ()
{
        ::create();
        set_level(7);
        set_name("Hawkman Flamen","鸟人族祭司");
        add("id",({"","hawkman","flamen"}) );
        set_short("鸟人族祭司");
        set_long(@C_LONG
你看到一个在祭檀上诚心祈导的老头子，大概是鸟人族的祭司吧。你觉得他在
这边说不定已经好久好久了。
C_LONG
        );
        set("alignment",300);
        set( "gender", "male" );
        set( "race", "hawkman");
        set( "unit", "位" );
        set_perm_stat( "dex",5);
        set_perm_stat( "int",12);
        set_perm_stat( "karma",3);
        set_natural_weapon(12,10,20);
        set_natural_armor(25,10);
        set("inquiry",([
                "story":"@@ask_story",
                        ]) );
        set("aim_difficulty",(["critical":30, "vascular":30]) );
}

int ask_story()
{
        tell_object(this_player(),@LONG
鸟人族祭司对你说：
　　祭坛底下就是每年举行武斗大会的地方，参加比武的勇士们在这儿接受神的祝
福。不过最近裘拉根在武斗场养了许许多多从黑暗世界来的怪物，真不知道他在想
些什麽，长老和阿道夫要是不采取一些行动，神明一定会发怒的。
LONG
        );
        return 1;
}
