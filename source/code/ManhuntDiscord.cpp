#include "..\pch.h"
#include "ManhuntDiscord.h"
#include "ManhuntSDK.h"

// required vars

int& CApp_ms_currLevelNum = *(int*)0x75622C;
int& hunKil = *(int*)0x7B7DA0;
int& hunExe = *(int*)0x7B7D84;


const char* GetLevelImage()
{
	switch (CApp_ms_currLevelNum)
	{
	case jury_turf:
		return "jury_turf"; break;
	case derelict:
		return "derelict"; break;
	case der2:
		return "der2"; break;
	case scrap:
		return "scrap"; break;
	case scrap2:
		return "scrap2"; break;
	case zoo:
		return "zoo"; break;
	case zoo2:
		return "zoo2"; break;
	case mall:
		return "mall"; break;
	case church2:
		return "church2"; break;
	case pharm_wks:
		return "pharm_wks"; break;
	case asylum:
		return "asylum"; break;
	case cellblock:
		return "cellblock"; break;
	case prison:
		return "prison"; break;
	case ramirez:
		return "ramirez"; break;
	case journo_streets:
		return "journo_streets"; break;
	case subway:
		return "subway"; break;
	case trainyard:
		return "trainyard"; break;
	case estate_ext:
		return "estate_ext"; break;
	case mansion_int:
		return "mansion_int"; break;
	case attic:
		return "attic"; break;
	case bonus1:
		return "bonus1"; break;
	case bonus3:
		return "bonus2"; break;
	case bonus2:
		return "bonus3"; break;
	case weasel:
		return "weasel"; break;
	default:
		return "closed"; break;
	}
}

const char* GetLevelName()
{
	switch (CApp_ms_currLevelNum)
	{
	case jury_turf:
		return "Born Again"; break;
	case derelict:
		return "Doorway Into hell"; break;
	case der2:
		return "Road To Ruin"; break;
	case scrap:
		return "White Trash"; break;
	case scrap2:
		return "Fuelled By Hate"; break;
	case zoo:
		return "Grounds For Assault"; break;
	case zoo2:
		return "Strapped For Cash"; break;
	case mall:
		return "View Of Innocence"; break;
	case church2:
		return "Drunk Driving"; break;
	case pharm_wks:
		return "Graveyard Shift"; break;
	case asylum:
		return "Mouth Of Madness"; break;
	case cellblock:
		return "Doing Time"; break;
	case prison:
		return "Kill The Rabbit"; break;
	case ramirez:
		return "Divided They Fall"; break;
	case journo_streets:
		return "Press Coverage"; break;
	case subway:
		return "Wrong Side of the Tracks"; break;
	case trainyard:
		return "Trained To Kill"; break;
	case estate_ext:
		return "Border Patrol"; break;
	case mansion_int:
		return "Key Personnel"; break;
	case attic:
		return "Deliverance"; break;
	case bonus1:
		return "Hard As Nails"; break;
	case bonus3:
		return "Monkey See, Monkey Die"; break;
	case bonus2:
		return "Brawl Game"; break;
	case weasel:
		return "Time 2 Die"; break;
	default:
		return "Unknown"; break;
	}
}

const char * GetStatus()
{
	char tmpBuffer[512];
	float health = *(float*)(*(int*)0x715B9C + 0x14);
	sprintf(tmpBuffer, "Health: %.1f", health);
	return tmpBuffer;
}

