// Ara:
	strlcpy(pdb.name, p->name, sizeof(pdb.name));
	db_clientdesc->DBPacket(HEADER_GD_CHANGE_NAME, d->GetHandle(), &pdb, sizeof(TPacketGDChangeName));
}

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
void CInputLogin::ChangeCountryFlag(LPDESC d, const char * data)
{
	if (!d)
		return;

	const TPacketCGChangeCountryFlag * p = (const TPacketCGChangeCountryFlag *) data;
	TAccountTable & r = d->GetAccountTable();

	if (!r.id || p->index >= PLAYER_PER_ACCOUNT || !r.players[p->index].dwID)
		return;

	char flag[COUNTRY_FLAG_MAX_LEN + 1];
	strlcpy(flag, p->flag, sizeof(flag));

	const size_t len = strlen(flag);
	if (len != 0 && len != COUNTRY_FLAG_MAX_LEN)
		return;

	for (size_t i = 0; i < len; ++i)
		if (flag[i] < 'a' || flag[i] > 'z')
			return;

	strlcpy(r.players[p->index].szCountryFlag, flag, sizeof(r.players[p->index].szCountryFlag));

	TPacketGDChangeCountryFlag pdb;
	pdb.pid = r.players[p->index].dwID;
	strlcpy(pdb.flag, flag, sizeof(pdb.flag));
	db_clientdesc->DBPacket(HEADER_GD_CHANGE_COUNTRY_FLAG, d->GetHandle(), &pdb, sizeof(pdb));
}
#endif


// int CInputLogin::Analyze(LPDESC d, BYTE bHeader, const char * c_pData) icinde:
// Ara:
		case HEADER_CG_CHANGE_NAME:
			ChangeName(d, c_pData);
			break;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		case HEADER_CG_CHANGE_COUNTRY_FLAG:
			ChangeCountryFlag(d, c_pData);
			break;
#endif

