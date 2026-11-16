// int CInputMain::Chat(LPCHARACTER ch, const char * data, size_t uiBytes) icinde:
// Ara:
		snprintf(szLocaleName, sizeof(szLocaleName), "|Eflag/%s|e", get_locale(ch->GetCountryFlagFromGMList(1)));
	else if (ch->IsGM() && ch->GetCountryFlagFromGMList(2) != 0 && ch->GetCountryFlagFromGMList(2) < LOCALE_MAX_NUM)
		snprintf(szLocaleName, sizeof(szLocaleName), "|Eflag/%s|e |Eflag/%s|e", get_locale(ch->GetCountryFlagFromGMList(1)), get_locale(ch->GetCountryFlagFromGMList(2)));

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	else if (*ch->GetCountryFlag())
		snprintf(szLocaleName, sizeof(szLocaleName), "|Eflag/%s|e ", ch->GetCountryFlag());
#endif


// int CInputMain::Chat(LPCHARACTER ch, const char * data, size_t uiBytes) icinde:
// Ara:
		case 2: strEmpireFlagToken = "|Eempire/chunjo|e "; break;
		case 3: strEmpireFlagToken = "|Eempire/jinno|e "; break;
	}

// Altina ekle:
#if defined(ENABLE_COUNTRY_FLAG) && defined(ENABLE_MULTI_LANGUAGE_SYSTEM)
	{
		size_t len = strlen(szLocaleName);
		while (len && szLocaleName[len - 1] == ' ')
			szLocaleName[--len] = '\0';

		while (!strEmpireFlagToken.empty() && strEmpireFlagToken[strEmpireFlagToken.size() - 1] == ' ')
			strEmpireFlagToken.erase(strEmpireFlagToken.size() - 1);
	}
#endif


// void CInputMain::WhisperDetails(LPCHARACTER ch, const char* c_pData) icinde:
// Ara:
	GCWhisperDetails.header = HEADER_GC_WHISPER_DETAILS;
	strncpy(GCWhisperDetails.name, CGWhisperDetails->name, sizeof(GCWhisperDetails.name) - 1);
	BYTE bLanguage = LOCALE_DEFAULT;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	memset(GCWhisperDetails.szCountryFlag, 0, sizeof(GCWhisperDetails.szCountryFlag));
#endif


// void CInputMain::WhisperDetails(LPCHARACTER ch, const char* c_pData) icinde:
// Ara:
			pkDesc = pkCCI->pkDesc;
			if (pkDesc)
				bLanguage = pkCCI->bLanguage;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
			strlcpy(GCWhisperDetails.szCountryFlag, pkCCI->szCountryFlag, sizeof(GCWhisperDetails.szCountryFlag));
#endif


// void CInputMain::WhisperDetails(LPCHARACTER ch, const char* c_pData) icinde:
// Ara:
	{
		if (pkChr->GetDesc())
			bLanguage = pkChr->GetDesc()->GetLanguage();

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		strlcpy(GCWhisperDetails.szCountryFlag, pkChr->GetCountryFlag(), sizeof(GCWhisperDetails.szCountryFlag));
#endif

