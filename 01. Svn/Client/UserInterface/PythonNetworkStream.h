// Ara:
			ACCOUNT_CHARACTER_SLOT_LAST_PLAYTIME,
			ACCOUNT_CHARACTER_SLOT_MAPINDEX,

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
			ACCOUNT_CHARACTER_SLOT_COUNTRY_FLAG,
#endif


// Ara:
		bool SendSelectEmpirePacket(DWORD dwEmpireID);
		bool SendSelectCharacterPacket(BYTE account_Index);
		bool SendChangeNamePacket(BYTE index, const char *name);

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		bool SendChangeCountryFlagPacket(BYTE index, const char *flag);
#endif

