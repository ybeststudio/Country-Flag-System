// bool CPythonNetworkStream::RecvWhisperDetails() icinde:
// Bul:
	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_RecieveWhisperDetails", Py_BuildValue("(si)", packet.name, packet.bLanguage));

// Degistir:
#ifdef ENABLE_COUNTRY_FLAG
	packet.szCountryFlag[COUNTRY_FLAG_MAX_LEN] = 0;
	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_RecieveWhisperDetails", Py_BuildValue("(sis)", packet.name, packet.bLanguage, packet.szCountryFlag));
#else
	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_RecieveWhisperDetails", Py_BuildValue("(si)", packet.name, packet.bLanguage));
#endif

