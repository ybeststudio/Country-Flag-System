# Ara:
FACE_IMAGES = ("warrior_m", "assassin_w", "sura_m", "shaman_w", "warrior_w", "assassin_m", "sura_w", "shaman_m", "wolfman_m")
EMPIRE_FLAG_PATH = "d:/ymir work/ui/game/guild_application/empire_%d.png"

# Altina ekle:
COUNTRY_FLAG_PATH = "d:/ymir work/ui/language_system/flags/%s.png"
COUNTRY_FLAG_SCALE_X = 16.0 / 33.0
COUNTRY_FLAG_SCALE_Y = 12.0 / 20.0


# WhisperMessenger.__Build icinde ara:
		self.headerCountry.SetParent(self)
		self.headerCountry.AddFlag("not_pick")

# Altina ekle:
		self.headerCountry.LoadImage(COUNTRY_FLAG_PATH % "tr")
		self.headerCountry.SetScale(COUNTRY_FLAG_SCALE_X, COUNTRY_FLAG_SCALE_Y)


# WhisperMessenger.__Build icinde ara:
		self.headerCountry.Hide()

# Altina ekle:
		self.countryFlags = {}


# WhisperMessenger.__RequestConversationInfo icinde ara:
		self.conversationInfo[name] = (info or (0, 0, -1, 0, "-", 0))[:5] + (now,)
		net.SendChatPacket("/anka_whisper_info " + name)

# Altina ekle:
		if app.ENABLE_COUNTRY_FLAG and name not in (GLOBAL_NAME, GUILD_NAME):
			net.SendWhisperDetails(name)


# WhisperMessenger icine ekle:
	def SetCountryFlag(self, name, countryFlag):
		self.countryFlags[name] = countryFlag
		if name == self.current:
			self.__RefreshHeader()

	def __IsShowCountryFlag(self):
		try:
			import advanced_options_runtime
			return advanced_options_runtime.Get("show_country_flag", True)
		except:
			return True


# WhisperMessenger.__RefreshHeader icinde ara:
				self.headerFlag.LoadImage(EMPIRE_FLAG_PATH % info[1])
				self.headerFlag.Show()

# Altina ekle:
			countryFlag = self.countryFlags.get(name, "")
			if countryFlag and self.__IsShowCountryFlag():
				self.headerCountry.LoadImage(COUNTRY_FLAG_PATH % countryFlag)
				self.headerCountry.SetScale(COUNTRY_FLAG_SCALE_X, COUNTRY_FLAG_SCALE_Y)
				self.headerCountry.Show()

