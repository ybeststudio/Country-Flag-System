// bool CPythonNetworkStream::RecvCharacterAdditionalInfo() icinde:
// Ara:
		kNetActorData.m_bLanguage = chrInfoPacket.bLanguage;
		kNetActorData.m_bLanguage2 = chrInfoPacket.bLanguage2;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		strncpy(kNetActorData.m_szCountryFlag, chrInfoPacket.szCountryFlag, COUNTRY_FLAG_MAX_LEN);
		kNetActorData.m_szCountryFlag[COUNTRY_FLAG_MAX_LEN] = 0;
#endif

