// void CClientManager::ProcessPackets(CPeer * peer) icinde:
// Ara:
			case HEADER_GD_CHANGE_NAME:
				QUERY_CHANGE_NAME(peer, dwHandle, (TPacketGDChangeName *) data);
				break;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
			case HEADER_GD_CHANGE_COUNTRY_FLAG:
				QUERY_CHANGE_COUNTRY_FLAG((TPacketGDChangeCountryFlag *) data);
				break;
#endif

