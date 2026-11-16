// Ara:
			BYTE m_bLanguage;
			BYTE m_bLanguage2;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
			char m_szCountryFlag[COUNTRY_FLAG_MAX_LEN + 1];
#endif


// Ara:
		BYTE GetLanguage() { return m_bLanguage; }
		void SetLanguage2(BYTE bLang) { m_bLanguage2 = bLang; }
		BYTE GetLanguage2() { return m_bLanguage2; }

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		void SetCountryFlag(const char* c_szFlag) { strncpy(m_szCountryFlag, c_szFlag, COUNTRY_FLAG_MAX_LEN); m_szCountryFlag[COUNTRY_FLAG_MAX_LEN] = 0; }
		const char* GetCountryFlag() const { return m_szCountryFlag; }
#endif


// Ara:
		BYTE m_bLanguage;
		BYTE m_bLanguage2;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		char m_szCountryFlag[COUNTRY_FLAG_MAX_LEN + 1];
#endif

