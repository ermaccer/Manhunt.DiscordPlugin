// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "discord/discord-rpc.h"
#include "MemoryMgr.h"
#include "code/ManhuntDiscord.h"
#include <time.h>
#pragma comment (lib,"discord\\discord-rpc.lib")

using namespace Memory::VP;

DiscordRichPresence drp = {};



void UpdatePresence()
{
	drp.largeImageKey = GetLevelImage();
	drp.largeImageText = GetLevelName();
	std::string kills = "Killed: " + std::to_string(*(int*)0x7B7DA0) + " Executed: "+ std::to_string(*(int*)0x7B7D84);
	drp.details = kills.c_str();
	drp.state = GetStatus();

	Discord_UpdatePresence(&drp);
	((void(__cdecl*)())0x4D87D0)();
}

void ShutdownPresence()
{
	Discord_Shutdown();
	((void(__cdecl*)())0x628F70)();
}


void CancelInfo()
{
	drp.largeImageKey = "closed";
	drp.largeImageText = 0;
	drp.details = 0;
	drp.state = 0;
	Discord_UpdatePresence(&drp);
	((void(__cdecl*)())0x5CF780)();
	
}

void Init()
{
	Discord_Initialize("484086006048489502",0,0,0);

	drp.largeImageKey = "closed";
	drp.startTimestamp = time(0);
	Discord_UpdatePresence(&drp);
	InjectHook(0x474C23, UpdatePresence, PATCH_CALL);
	InjectHook(0x489D8C, ShutdownPresence, PATCH_CALL);
	InjectHook(0x4D845F, CancelInfo, PATCH_CALL);
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		if (*(int*)0x63BC93 != 0x24448B66)
		{
			MessageBoxA(0, "Invalid executable!", 0, 0);
		}
		else Init();
	}
}


