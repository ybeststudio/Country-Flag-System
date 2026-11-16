// void CHARACTER::Initialize() icinde:
// Ara:
	m_iRealAlignment = 0;
	m_iKillerModePulse = 0;
	m_bPKMode = PK_MODE_PEACE;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	m_szCountryFlag[0] = '\0';
#endif


// void CHARACTER::EncodeInsertPacket(LPENTITY entity) icinde:
// Ara:
			}
			addPacket.sAlignment = m_iAlignment / 10;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
			strlcpy(addPacket.szCountryFlag, m_szCountryFlag, sizeof(addPacket.szCountryFlag));
#endif


// void CHARACTER::WarpEnd() icinde:
// Ara:
		p.bLanguage = GetLanguage();

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		strlcpy(p.szCountryFlag, m_szCountryFlag, sizeof(p.szCountryFlag));
#endif

