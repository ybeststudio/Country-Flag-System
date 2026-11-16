// Ara:
	rkNetStream.SendChangeNamePacket((BYTE)iIndex, szName);
	return Py_BuildNone();
}

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
PyObject *netSendChangeCountryFlagPacket(PyObject *poSelf, PyObject *poArgs)
{
	int iIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iIndex))
		return Py_BuildException();
	char *szFlag;
	if (!PyTuple_GetString(poArgs, 1, &szFlag))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendChangeCountryFlagPacket((BYTE)iIndex, szFlag);
	return Py_BuildNone();
}
#endif


// void initnet() icinde:
// Ara:
		{ "SendSelectEmpirePacket", netSendSelectEmpirePacket, METH_VARARGS },
		{ "SendSelectCharacterPacket", netSendSelectCharacterPacket, METH_VARARGS },
		{ "SendChangeNamePacket", netSendChangeNamePacket, METH_VARARGS },

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
		{ "SendChangeCountryFlagPacket", netSendChangeCountryFlagPacket, METH_VARARGS },
#endif


// void initnet() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ACCOUNT_CHARACTER_SLOT_LAST_PLAYTIME", CPythonNetworkStream::ACCOUNT_CHARACTER_SLOT_LAST_PLAYTIME);
	PyModule_AddIntConstant(poModule, "ACCOUNT_CHARACTER_SLOT_MAPINDEX", CPythonNetworkStream::ACCOUNT_CHARACTER_SLOT_MAPINDEX);

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	PyModule_AddIntConstant(poModule, "ACCOUNT_CHARACTER_SLOT_COUNTRY_FLAG", CPythonNetworkStream::ACCOUNT_CHARACTER_SLOT_COUNTRY_FLAG);
#endif

