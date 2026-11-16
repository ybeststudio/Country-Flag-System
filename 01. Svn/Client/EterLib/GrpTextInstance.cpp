// void CGraphicTextInstance::Update() icinde:
// Ara:
			SEmoji & rEmo = *itor;
			if (rEmo.pInstance)
			{

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
				if (rEmo.bExpanded)
					CGraphicExpandedImageInstance::Delete(static_cast<CGraphicExpandedImageInstance*>(rEmo.pInstance));
				else
#endif


// void CGraphicTextInstance::Update() icinde:
// Ara:
						_snprintf(szPath, sizeof(szPath), "d:/ymir work/ui/game/emoji/%s.tga", retBuf);

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
						bool bCountryFlag = false;
						float fEmojiScaleX = 16.0f / 33.0f;
						float fEmojiScaleY = 12.0f / 20.0f;
						float fEmojiYOffset = 0.0f;
						if (strncmp(retBuf, "flag/", 5) == 0 && strlen(retBuf) == 7)
						{
							char szFlagPath[255];
							_snprintf(szFlagPath, sizeof(szFlagPath), "d:/ymir work/ui/language_system/flags/%s.png", retBuf + 5);
							if (CResourceManager::Instance().IsFileExist(szFlagPath))
							{
								strncpy(szPath, szFlagPath, sizeof(szPath) - 1);
								szPath[sizeof(szPath) - 1] = '\0';
								bCountryFlag = true;
							}
						}
						else if (strncmp(retBuf, "empire/", 7) == 0)
						{
							bCountryFlag = true;
							fEmojiScaleX = 18.0f / 16.0f;
							fEmojiScaleY = 14.0f / 12.0f;
							fEmojiYOffset = 3.4f;
						}
#endif


// void CGraphicTextInstance::Update() icinde:
// Ara:
						{
							CGraphicImage * pImage = (CGraphicImage *)CResourceManager::Instance().GetResourcePointer(szPath);
							int iEmojiWidth = pImage->GetWidth();

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
							if (bCountryFlag)
							{
								CGraphicExpandedImageInstance* pFlag = CGraphicExpandedImageInstance::New();
								pFlag->SetImagePointer(pImage);
								pFlag->SetScale(fEmojiScaleX, fEmojiScaleY);
								kEmoji.pInstance = pFlag;
								kEmoji.bExpanded = true;
								kEmoji.fScale = fEmojiScaleY;	// vertical centring
								kEmoji.fYOffset = fEmojiYOffset;
								iEmojiWidth = int(pImage->GetWidth() * fEmojiScaleX + 0.5f);
							}
							else
#endif


// void CGraphicTextInstance::Update() icinde:
// Ara:
							}
							m_emojiVector.push_back(kEmoji);
							memset(&kEmoji, 0, sizeof(SEmoji));

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
							kEmoji.fScale = 1.0f;
#endif
#ifdef ENABLE_COUNTRY_FLAG
							// flag / emblem: the text after it is placed by these spaces, so they must stay;
							if (bCountryFlag)
							{
								const int iSpaceAdvance = max(1, (int)pSpaceInfo->advance);
								const int iSpaceCount = (iEmojiWidth + iSpaceAdvance / 2) / iSpaceAdvance;
								for (int i = 0; i < iSpaceCount; ++i)
									x += __DrawCharacter(pFontTexture, dataCodePage, ' ', dwColor);
							}
							else
#endif


// void CGraphicTextInstance::Render(RECT * pClipRect) icinde:
// Bul:
				rEmo.pInstance->SetPosition(fStanX + rEmo.x, (fStanY + 7.0) - (rEmo.pInstance->GetHeight() / 2));

// Degistir:
#ifdef ENABLE_COUNTRY_FLAG
				rEmo.pInstance->SetPosition(fStanX + rEmo.x, (fStanY + 7.0) - (rEmo.pInstance->GetHeight() * rEmo.fScale / 2) + rEmo.fYOffset);
#else
				rEmo.pInstance->SetPosition(fStanX + rEmo.x, (fStanY + 7.0) - (rEmo.pInstance->GetHeight() / 2));
#endif

