// Ara:
const D3DXCOLOR c_TextTail_Player_Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
const float c_fTextTailCountryFlagScaleX = 16.0f / 33.0f;
const float c_fTextTailCountryFlagScaleY = 12.0f / 20.0f;

static float __GetLanguageFlagWidth(CGraphicImageInstance* pInstance, bool bScaled)
{
	return bScaled ? 16.0f + 2.0f : float(pInstance->GetWidth());
}

static float __GetLanguageFlagTop(bool bScaled)
{
	return 11.0f;
}
#endif


// static void ComputeCharacterTextTailBounds(CPythonTextTail::TTextTail* pTextTail, const CPythonTextTail::TChatTailMap& rChatTailMap) icinde:
// Bul:
				left -= (float(pTextTail->pLanguageInstance->GetWidth()) + 16.0f);

// Degistir:
				#ifdef ENABLE_COUNTRY_FLAG
				left -= (__GetLanguageFlagWidth(pTextTail->pLanguageInstance, pTextTail->bLanguageScaled) + 16.0f);
#else
				left -= (float(pTextTail->pLanguageInstance->GetWidth()) + 16.0f);
#endif


// static void ComputeCharacterTextTailBounds(CPythonTextTail::TTextTail* pTextTail, const CPythonTextTail::TChatTailMap& rChatTailMap) icinde:
// Bul:
			left -= (float(pTextTail->pLanguageInstance->GetWidth()) + 12.0f);

// Degistir:
			#ifdef ENABLE_COUNTRY_FLAG
			left -= (__GetLanguageFlagWidth(pTextTail->pLanguageInstance, pTextTail->bLanguageScaled) + 12.0f);
#else
			left -= (float(pTextTail->pLanguageInstance->GetWidth()) + 12.0f);
#endif


// void CPythonTextTail::ArrangeTextTail() icinde:
// Bul:
					pLanguageInstance->SetPosition(pTextTail->x - (iNameWidth / 2) - iTitleWidth - iLevelWidth - pLanguageInstance->GetWidth() - 16.0f, pTextTail->y - 11.0f);

// Degistir:
					#ifdef ENABLE_COUNTRY_FLAG
					pLanguageInstance->SetPosition(pTextTail->x - (iNameWidth / 2) - iTitleWidth - iLevelWidth - __GetLanguageFlagWidth(pLanguageInstance, pTextTail->bLanguageScaled) - 16.0f, pTextTail->y - __GetLanguageFlagTop(pTextTail->bLanguageScaled));
#else
					pLanguageInstance->SetPosition(pTextTail->x - (iNameWidth / 2) - iTitleWidth - iLevelWidth - pLanguageInstance->GetWidth() - 16.0f, pTextTail->y - 11.0f);
#endif


// void CPythonTextTail::ArrangeTextTail() icinde:
// Bul:
			const float fFlagGap = 12.0f;

// Degistir:
#ifdef ENABLE_COUNTRY_FLAG
			const float fFlagGap = 10.0f;
#else
			const float fFlagGap = 12.0f;
#endif


// void CPythonTextTail::RegisterCharacterTextTail(DWORD dwGuildID, DWORD dwVirtualID, const D3DXCOLOR & c_rColor, float fAddHeight) icinde:
// Ara:
	pTextTail->pLanguageInstance = nullptr;
	pTextTail->pLanguageInstance2 = nullptr;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
	pTextTail->bLanguageScaled = false;
#endif


// void CPythonTextTail::RegisterCharacterTextTail(DWORD dwGuildID, DWORD dwVirtualID, const D3DXCOLOR & c_rColor, float fAddHeight) icinde:
// Bul:
		if(pCharacterInstance->IsPC() && bLanguage)

// Degistir:
#ifdef ENABLE_COUNTRY_FLAG
		if (pCharacterInstance->IsPC() && (bLanguage || *pCharacterInstance->GetCountryFlag()))
#else
		if(pCharacterInstance->IsPC() && bLanguage)
#endif


// void CPythonTextTail::RegisterCharacterTextTail(DWORD dwGuildID, DWORD dwVirtualID, const D3DXCOLOR & c_rColor, float fAddHeight) icinde:
// Ara:
			}
			char szFileName[256];
			snprintf(szFileName, sizeof(szFileName), "d:/ymir work/ui/game/emoji/flag/%s.tga", langName.c_str());

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
			if (*pCharacterInstance->GetCountryFlag())
			{
				char szCountryFile[256];
				snprintf(szCountryFile, sizeof(szCountryFile), "d:/ymir work/ui/language_system/flags/%s.png", pCharacterInstance->GetCountryFlag());
				if (CResourceManager::Instance().IsFileExist(szCountryFile))
				{
					CGraphicImage* pCountryImage = (CGraphicImage*)CResourceManager::Instance().GetResourcePointer(szCountryFile);
					if (pCountryImage)
					{
						CGraphicExpandedImageInstance* pCountry = CGraphicExpandedImageInstance::New();
						pCountry->SetImagePointer(pCountryImage);
						pCountry->SetScale(c_fTextTailCountryFlagScaleX, c_fTextTailCountryFlagScaleY);
						prLanguage = pCountry;
						pTextTail->bLanguageScaled = true;
					}
				}
			}

			if (!prLanguage)
#endif

