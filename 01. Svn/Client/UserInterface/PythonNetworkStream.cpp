// const char* CPythonNetworkStream::GetAccountCharacterSlotDataz (UINT iSlot, UINT eType) icinde:
// Ara:
		case ACCOUNT_CHARACTER_SLOT_GUILD_NAME:
			return m_astrGuildName[iSlot].c_str();
			break;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		case ACCOUNT_CHARACTER_SLOT_COUNTRY_FLAG:
			return rkSimplePlayerInfo.szCountryFlag;
			break;
#endif

