// CPacketInfoCG::CPacketInfoCG() icinde:
// Ara:
	Set(HEADER_CG_MYSHOP,							sizeof(TPacketCGMyShop),					"MyShop");
	Set(HEADER_CG_REFINE,							sizeof(TPacketCGRefine),					"Refine");
	Set(HEADER_CG_CHANGE_NAME,						sizeof(TPacketCGChangeName),				"ChangeName");

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	Set(HEADER_CG_CHANGE_COUNTRY_FLAG,				sizeof(TPacketCGChangeCountryFlag),			"ChangeCountryFlag");
#endif

