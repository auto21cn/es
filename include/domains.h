// domains.h
// This file holds the array of existing domains and levels of those domains.

#ifndef __DOMAINS_H
#define __DOMAINS_H

// The functional groups wizards can belong to
#define DOMAIN_LIST ({ "abyss", "adventurer", "eastland", "healer", "island",\
	"knight", "mage", "magic", "martial", "monk", "moorth", "noden",\
	"scholar", "thief", "std","translate", "wiz","doc" })

// The names of the sub-directories of /d/
#define DOMAIN_DIRS ({ "abyss", "adventurer", "eastland", "healer", "island", \
	"knight", "mage", "magic", "martial", "monk", "moorth", "noden",\
	"scholar", "thief", "std","translate", "wiz", "doc"})

// The level of incompetance they can reach within those groups 8-)
#define LEVEL_LIST ({ "player", "hero", "noble", "lord", \
	"apprentice", "wizard", "adept", "sage", "archwizard", })

#define ENTRY_LEVEL 4
#define MIN_SPONSOR_LEVEL 7

#endif

/* EOF */
