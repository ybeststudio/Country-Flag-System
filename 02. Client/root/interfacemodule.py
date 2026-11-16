# Interface icinde ara:
		self.__CheckGameMaster(name)
	if app.ENABLE_EXTENDED_WHISPER_DETAILS and app.ENABLE_MULTI_LANGUAGE_SYSTEM:

# Altina ekle:
		def RecieveWhisperDetails(self, name, country, countryFlag = ""):
			if app.ENABLE_COUNTRY_FLAG and self.wndWhisperMessenger:
				self.wndWhisperMessenger.SetCountryFlag(name, countryFlag)

			if self.whisperDialogDict.has_key(name):
				self.whisperDialogDict[name].SetCountryFlag(country)
			else:
				btn = self.__FindWhisperButton(name)
				if btn != 0:
					btn.countryID = country

