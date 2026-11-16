// Bul:
		to->ChatPacket(CHAT_TYPE_COMMAND, "MessengerInfo %d %s %d %d %d %ld %u", group, name, level, race, channel, mapIndex, lastSeen);

// Degistir:
#ifdef ENABLE_COUNTRY_FLAG
		to->ChatPacket(CHAT_TYPE_COMMAND, "MessengerInfo %d %s %d %d %d %ld %u %s", group, name, level, race, channel, mapIndex, lastSeen, (country && *country) ? country : "-");
#else
		to->ChatPacket(CHAT_TYPE_COMMAND, "MessengerInfo %d %s %d %d %d %ld %u", group, name, level, race, channel, mapIndex, lastSeen);
#endif


// Ara:
		LPCHARACTER member = CHARACTER_MANAGER::instance().FindPC(name);
		if (member && member->GetDesc())
		{

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
			country = member->GetCountryFlag();
#endif


// Ara:
		CCI* pkCCI = P2P_MANAGER::instance().Find(name);
		if (pkCCI)
		{

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
			country = pkCCI->szCountryFlag;
#endif

