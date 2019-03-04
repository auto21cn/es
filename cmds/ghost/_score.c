//#pragma save_binary
// _score.c
// Informs the ghost that he has no scores in death.
// When we get death times working, should be changed to indicate how long
// it has been since death. Or maybe that should be another command.
// Mobydick, 11-14-92.

int cmd_score()
{
	write( can_read_chinese()?
		"一死百了，你也不用计较什麽属性、状态了。\n":
		"Dead. Dead, dead, dead, dead, dead. Dead!\n"
		"You are in a immaterial state and have no other scores.\n");
	return 1 ;
}
