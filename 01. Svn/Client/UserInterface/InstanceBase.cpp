// bool CInstanceBase::Create(const SCreateData& c_rkCreateData) icinde:
// Ara:
		SetLanguage(c_rkCreateData.m_bLanguage);
		SetLanguage2(c_rkCreateData.m_bLanguage2);

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		SetCountryFlag(c_rkCreateData.m_szCountryFlag);
#endif


// void CInstanceBase::__Initialize() icinde:
// Ara:
void CInstanceBase::__Initialize()
{
    m_optionQueueIndex=0;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	m_szCountryFlag[0] = 0;
#endif

