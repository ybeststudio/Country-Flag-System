# GameWindow icinde ara:
			import uiGuildApplication
			self.interface.OpenGuildJoinNotification(int(GID), name.replace("\x1f", " "), uiGuildApplication.Decode(desc))

# Altina ekle:
	def ServerCommand_MessengerInfo(self, group, name, level, race, channel, mapIndex, lastSeen, countryFlag = "-"):
		if app.ENABLE_MESSENGER_DETAILS and self.interface and self.interface.wndMessenger:
			self.interface.wndMessenger.OnMemberInfo(int(group), name, int(level), int(race), int(channel), int(mapIndex), int(lastSeen))


# GameWindow icinde ara:
			self.interface.bigBoardControl.SetTip(message)
	if app.ENABLE_EXTENDED_WHISPER_DETAILS and app.ENABLE_MULTI_LANGUAGE_SYSTEM:

# Altina ekle:
		def BINARY_RecieveWhisperDetails(self, name, country, countryFlag = ""):
			if self.interface:
				self.interface.RecieveWhisperDetails(name, country, countryFlag)

