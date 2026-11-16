// void CInputDB::PlayerLoad(LPDESC d, const char * data) icinde:
// Ara:
	ch->BindDesc(d);
	ch->SetPlayerProto(pTab);
	ch->SetEmpire(d->GetEmpire());

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	{
		const TAccountTable & r = d->GetAccountTable();
		for (int i = 0; i < PLAYER_PER_ACCOUNT; ++i)
			if (r.players[i].dwID == pTab->id)
			{
				ch->SetCountryFlag(r.players[i].szCountryFlag);
				break;
			}
	}
#endif


// void CInputDB::PlayerLoad(LPDESC d, const char * data) icinde:
// Ara:
		p.bLanguage = ch->GetLanguage();

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		strlcpy(p.szCountryFlag, ch->GetCountryFlag(), sizeof(p.szCountryFlag));
#endif

