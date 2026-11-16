// Ara:
	}
	return SendSequence();
}

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
bool CPythonNetworkStream::SendChangeCountryFlagPacket(BYTE index, const char* flag)
{
	if (index >= PLAYER_PER_ACCOUNT4)
		return false;

	TPacketCGChangeCountryFlag packet;
	packet.header = HEADER_CG_CHANGE_COUNTRY_FLAG;
	packet.index = index;
	strncpy(packet.flag, flag, COUNTRY_FLAG_MAX_LEN);
	packet.flag[COUNTRY_FLAG_MAX_LEN] = '\0';

	if (!Send(sizeof(packet), &packet))
	{
		Tracen("Failed to SendChangeCountryFlagPacket");
		return false;
	}

	strncpy(m_akSimplePlayerInfo[index].szCountryFlag, packet.flag, sizeof(m_akSimplePlayerInfo[index].szCountryFlag));
	return SendSequence();
}
#endif

