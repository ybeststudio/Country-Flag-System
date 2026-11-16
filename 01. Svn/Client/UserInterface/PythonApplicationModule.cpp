// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_GLOBAL_RANKING", 0);

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	PyModule_AddIntConstant(poModule, "ENABLE_COUNTRY_FLAG", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COUNTRY_FLAG", 0);
#endif

