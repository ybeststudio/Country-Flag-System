// Ara:
		void QUERY_PARTY_SET_MEMBER_LEVEL(CPeer * peer, TPacketPartySetMemberLevel* p);
		void QUERY_RELOAD_PROTO();
		void QUERY_CHANGE_NAME(CPeer * peer, DWORD dwHandle, TPacketGDChangeName * p);

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		void QUERY_CHANGE_COUNTRY_FLAG(TPacketGDChangeCountryFlag * p);
#endif

