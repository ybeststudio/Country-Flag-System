// Ara:
		int GuildSymbolUpload(LPDESC d, const char* c_pData, size_t uiBytes);
		void GuildSymbolCRC(LPDESC d, const char* c_pData);
		void ChangeName(LPDESC d, const char * data);

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		void ChangeCountryFlag(LPDESC d, const char * data);
#endif

