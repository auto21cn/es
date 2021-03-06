//	_coat.c		淬毒术
//
//		Lilia@Eastern.Stories

// 所需技能：毒物学 50
// 伤害力为毒药本身伤害力 * skill%
// 命中率为毒药本身困难度 + 阵营值/10000
	////#pragma save_binary
#include <mudlib.h>

inherit DAEMON;

int cmd_coat(string arg)
{
    object p, weapon, poison;
    int ali, i, skill;
    string wname, pname;

    p = this_player();

    if (!arg || arg == "")
	return notify_fail("你想做什麽?\n");

    sscanf (arg, "%s with %s", wname, pname);
    if (!wname || wname == "" || !pname || pname == "")
	return notify_fail("你想做什麽?\n");

    if (weapon = present(wname, p))
	if (weapon->query("weapon_class"))
	    ;
	else
	    return notify_fail("这不是武器。\n");

    if (poison = present(pname, p))
        if (poison->query("poison_type"))
            ;
        else
            return notify_fail("这不是毒药。\n");

    if (weapon && poison)
    { 
    	skill = p->query_skill("venomlogy");
    	if (skill < 50)
	    return notify_fail("远处传来女王的笑声: 年青人，别傻了，练个十年再来吧!\n");

	ali = this_player()->query("alignment");
        if (ali >= 0)
            return notify_fail("你心中一阵天人交战，下不了这个手 ...\n");

    	if (p->query("stop_attack") != 0)
	    return notify_fail("你上个动作还没有完成，不能替武器淬毒。\n");

    	if (weapon->query("poisoned/type"))
	    return notify_fail("这个武器已经上过毒了，没有办法重复淬毒。\n");

        write("你替"+weapon->query("c_name")+"涂上"+poison->query("c_name")+"。\n");

    	weapon->set("poisoned/type", poison->query("poison_type"));
    	weapon->set("poisoned/time", poison->query("poison_time"));
    	weapon->set("poisoned/duration", poison->query("poison_duration"));
    	weapon->set("poisoned/harm", poison->query("poison_harm") * skill / 100);
    	i = 100 - poison->query("poison_diff") - ali/10000;
    	i = (i > 100) ? 100 : i;
    	weapon->set("poisoned/hit_rate", i);
        poison->remove();
    	return 1;
    }
    else
	return notify_fail("你没有这样东西。\n");
}

int help()
{
    write(
    @C_HELP
指令格式： coat <武器> with <毒药>

这个指令可以让你替某样武器涂上毒药，使武器的威力增强。这个指令
必须是受过良好毒物学训练的邪恶医师方可使用。
C_HELP
    );
    return 1;
}

