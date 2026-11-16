# WhisperDialog.LoadDialog icinde ara:
		self.acceptButton.SetEvent(ui.__mem_func__(self.AcceptTarget))
		if app.ENABLE_MULTI_LANGUAGE_SYSTEM:

# Altina ekle:
			self.countryFlag = ui.ExpandedImageBox()
			self.countryFlag.SetParent(self.board)
			self.countryFlag.SetPosition(130, 28)
			self.countryFlag.Show()


# WhisperDialog.Destroy icinde ara:
		self.resizeButton = None
		if app.ENABLE_MULTI_LANGUAGE_SYSTEM and app.ENABLE_EXTENDED_WHISPER_DETAILS:

# Altina ekle:
			self.countryFlag = None


# WhisperDialog icinde ara:
			exception.Abort("WhisperDialog.SetWhisperDialogSize.BindObject")
	if app.ENABLE_MULTI_LANGUAGE_SYSTEM and app.ENABLE_EXTENDED_WHISPER_DETAILS:

# Altina ekle:
		def RequestCountryFlag(self, targetName):
			if targetName:
				net.SendWhisperDetails(targetName)

			if self.countryFlag:
				fixedWidth = 280
				if messenger.IsFriendByName(targetName):
					self.countryFlag.SetPosition(fixedWidth - 159, 13.5)
				else:
					self.countryFlag.SetPosition(fixedWidth - 159, 13.5)

		def SetCountryFlag(self, countryID):
			self.countryID = countryID

			import advanced_options_runtime
			if countryID != 0 and advanced_options_runtime.Get("show_country_flag", True):
				self.countryFlag.LoadImage("d:/ymir work/ui/game/emoji/flag/%s.tga" % uiGameOption.LOCALE_LANG_DICT[countryID]["locale"])
				self.countryFlag.Show()
			else:
				self.countryFlag.Hide()


# WhisperDialog.OpenWithTarget icinde ara:
		self.ignoreButton.Hide()
		if app.ENABLE_MULTI_LANGUAGE_SYSTEM and app.ENABLE_EXTENDED_WHISPER_DETAILS:

# Altina ekle:
			self.RequestCountryFlag(targetName)
			self.countryFlag.Hide()


# WhisperDialog.OpenWithoutTarget icinde ara:
		self.ignoreButton.Hide()
		if app.ENABLE_MULTI_LANGUAGE_SYSTEM and app.ENABLE_EXTENDED_WHISPER_DETAILS:

# Altina ekle:
			self.countryFlag.Hide()


# WhisperDialog.AcceptTarget icinde ara:
			self.eventAcceptTarget(name)
			if app.ENABLE_MULTI_LANGUAGE_SYSTEM and app.ENABLE_EXTENDED_WHISPER_DETAILS:

# Altina ekle:
				self.RequestCountryFlag(name)

