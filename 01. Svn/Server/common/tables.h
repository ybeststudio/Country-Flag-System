// Ara:
	HEADER_GD_GROWTH_PET_SAVE						= 147,
	HEADER_GD_GROWTH_PET_DELETE						= 148,

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	HEADER_GD_CHANGE_COUNTRY_FLAG					= 149,
#endif


// Ara:
	WORD wPort;
	BYTE skill_group;
	DWORD last_play;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	char szCountryFlag[COUNTRY_FLAG_MAX_LEN + 1];	// lower case ISO code, "" = none
#endif


// Ara:
	DWORD pid;
	char name[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGDChangeName;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
typedef struct SPacketGDChangeCountryFlag
{
	DWORD pid;
	char flag[COUNTRY_FLAG_MAX_LEN + 1];
} TPacketGDChangeCountryFlag;
#endif

