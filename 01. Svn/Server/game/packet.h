// Bul:
	//HEADER_CG_EMPTY						= 222,

// Degistir:
#ifdef ENABLE_COUNTRY_FLAG
	HEADER_CG_CHANGE_COUNTRY_FLAG			= 222,
#else
	//HEADER_CG_EMPTY						= 222,
#endif


// Ara:
	BYTE bLanguage;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	char szCountryFlag[COUNTRY_FLAG_MAX_LEN + 1];
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

