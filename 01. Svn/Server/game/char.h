// Ara:
		BYTE GetLanguage() const;
		bool ChangeLanguage(BYTE bLanguage);
		BYTE GetCountryFlagFromGMList(BYTE bFlag, const char* TargetName = "", bool bMessenger = false);

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		const char* GetCountryFlag() const { return m_szCountryFlag; }
		void SetCountryFlag(const char* c_szFlag) { strlcpy(m_szCountryFlag, c_szFlag, sizeof(m_szCountryFlag)); }
	protected:
		char m_szCountryFlag[COUNTRY_FLAG_MAX_LEN + 1];
	public:
#endif

