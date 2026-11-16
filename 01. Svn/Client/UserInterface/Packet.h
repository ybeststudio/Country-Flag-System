// Bul:
	//HEADER_CG_EMPTY							= 222,

// Degistir:
#ifdef ENABLE_COUNTRY_FLAG
	HEADER_CG_CHANGE_COUNTRY_FLAG				= 222,
#else
	//HEADER_CG_EMPTY							= 222,
#endif


// Ara:
	BYTE index;
	char name[CHARACTER_NAME_MAX_LEN+1];
} TPacketCGChangeName;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
typedef struct SPacketCGChangeCountryFlag
{
	BYTE header;
	BYTE index;
	char flag[COUNTRY_FLAG_MAX_LEN + 1];
} TPacketCGChangeCountryFlag;
#endif


// Ara:
	WORD wPort;
	BYTE bySkillGroup;
	DWORD dwLastPlay;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	char szCountryFlag[COUNTRY_FLAG_MAX_LEN + 1];	// lower case ISO code, "" = none
#endif


// Ara:
	DWORD adwShining[2];	// WEAR_SHINING_WEAPON, WEAR_SHINING_ARMOR

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	char szCountryFlag[COUNTRY_FLAG_MAX_LEN + 1];
#endif

