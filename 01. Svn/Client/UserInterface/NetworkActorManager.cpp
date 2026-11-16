// void SNetworkActorData::__copy__(const SNetworkActorData& src) icinde:
// Ara:
	m_bLanguage = src.m_bLanguage;
	m_bLanguage2 = src.m_bLanguage2;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	memcpy(m_szCountryFlag, src.m_szCountryFlag, sizeof(m_szCountryFlag));
#endif


// SNetworkActorData::SNetworkActorData() icinde:
// Ara:
	m_bLanguage = 0;
	m_bLanguage2 = 0;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	m_szCountryFlag[0] = 0;
#endif


// CInstanceBase* CNetworkActorManager::__AppendCharacterManagerActor(SNetworkActorData& rkNetActorData) icinde:
// Ara:
	kCreateData.m_bLanguage = rkNetActorData.m_bLanguage;
	kCreateData.m_bLanguage2 = rkNetActorData.m_bLanguage2;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	memcpy(kCreateData.m_szCountryFlag, rkNetActorData.m_szCountryFlag, sizeof(kCreateData.m_szCountryFlag));
#endif

