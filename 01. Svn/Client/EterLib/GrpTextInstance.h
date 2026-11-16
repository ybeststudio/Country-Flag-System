// Dosyanin uygun bir yerine ekle:
#if defined(ENABLE_EMOTICONS_SYSTEM) || defined(ENABLE_COUNTRY_FLAG)
	#include "GrpExpandedImageInstance.h"
#endif


// Ara:
		{
			short x;
			CGraphicImageInstance *pInstance;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
			bool bExpanded;
			float fScale;
			float fYOffset;
#endif


// Ara:
			SEmoji() : x(0)
			{
				pInstance = nullptr;

// Altina ekle:
#ifdef ENABLE_COUNTRY_FLAG
				bExpanded = false;
				fScale = 1.0f;
				fYOffset = 0.0f;
#endif

