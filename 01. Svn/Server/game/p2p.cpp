// void P2P_MANAGER::Boot(LPDESC d) icinde:
// Ara:
		p.bLanguage = ch->GetLanguage();

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		strlcpy(p.szCountryFlag, ch->GetCountryFlag(), sizeof(p.szCountryFlag));
#endif


// void P2P_MANAGER::Login(LPDESC d, const TPacketGGLogin * p) icinde:
// Ara:
		pkCCI->bLanguage = p->bLanguage;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		strlcpy(pkCCI->szCountryFlag, p->szCountryFlag, sizeof(pkCCI->szCountryFlag));
#endif

