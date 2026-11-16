# Ara:
import uiToolTip
import uiScriptLocale

# Altina ekle:
if app.ENABLE_COUNTRY_FLAG:
	import uiCountryFlag


# Ara:
def GetSlotData(realSlot, key):
	return net.GetAccountCharacterSlotDataInteger(realSlot, key)

# Altina ekle:
class CountryFlagBox(ui.Button):
	IMAGE_PATH = "d:/ymir work/ui/game/common/button_xlarge_%s.png"
	ARROW_IMAGE = "d:/ymir work/ui/game/advanced_game_options/arrow_down.png"

	def __init__(self):
		ui.Button.__init__(self)
		self.SetUpVisual(self.IMAGE_PATH % "norm")
		self.SetOverVisual(self.IMAGE_PATH % "hover")
		self.SetDownVisual(self.IMAGE_PATH % "down")

		self.flag = ui.ImageBox()
		self.flag.SetParent(self)
		self.flag.AddFlag("not_pick")

		self.name = ui.TextLine()
		self.name.SetParent(self)
		self.name.AddFlag("not_pick")
		self.name.SetPosition(46, self.GetHeight() / 2 - 7)
		self.name.SetPackedFontColor(uiCountryFlag.TEXT_COLOR)
		self.name.Show()

		self.arrow = ui.ImageBox()
		self.arrow.SetParent(self)
		self.arrow.AddFlag("not_pick")
		self.arrow.LoadImage(self.ARROW_IMAGE)
		self.arrow.SetPosition(self.GetWidth() - self.arrow.GetWidth() - 9, (self.GetHeight() - self.arrow.GetHeight()) / 2)
		self.arrow.Show()

	def __del__(self):
		ui.Button.__del__(self)

	def SetCountry(self, code):
		if code:
			self.flag.LoadImage(uiCountryFlag.FLAG_PATH % code)
			self.flag.SetPosition(7, (self.GetHeight() - self.flag.GetHeight()) / 2)
			self.flag.Show()
			self.name.SetText(uiCountryFlag.GetCountryName(code))
		else:
			self.flag.Hide()
			self.name.SetText("-")


# SelectCharacterWindow.__init__ icinde ara:
		self.descStartLine = 0
		self.hoverIndex = -1

# Altina ekle:
		self.countryFlagBoard = None
		self.countryFlagBox = None
		self.countryFlagDropdown = None


# SelectCharacterWindow.Close icinde ara:
			self.toolTip.Hide()
		self.toolTip = None

# Altina ekle:
		if self.countryFlagDropdown:
			self.countryFlagDropdown.Destroy()
		self.countryFlagDropdown = None
		self.countryFlagBox = None


# SelectCharacterWindow.__LoadBoardDialog icinde ara:
		self.chrRenderer.AddFlag("not_pick")
		self.chrRenderer.Show()

# Altina ekle:
		self.__CreateCountryFlagControls()


# SelectCharacterWindow icinde ara:
		return TRUE
	# country flag

# Altina ekle:
	def __CreateCountryFlagControls(self):
		self.countryFlagBoard = self.dlgBoard.GetChild2("country_flag_board")
		self.countryFlagBox = None
		self.countryFlagDropdown = None
		if not self.countryFlagBoard:
			return

		if not app.ENABLE_COUNTRY_FLAG:
			self.countryFlagBoard.Hide()
			return

		box = CountryFlagBox()
		box.SetParent(self.countryFlagBoard)
		box.SetPosition((self.countryFlagBoard.GetWidth() - box.GetWidth()) / 2, (self.countryFlagBoard.GetHeight() - box.GetHeight()) / 2)
		box.SetEvent(ui.__mem_func__(self.ToggleCountryFlagDropdown))
		box.Show()
		self.countryFlagBox = box

		self.countryFlagDropdown = uiCountryFlag.CountryFlagDropdown()
		self.countryFlagDropdown.SetEvent(ui.__mem_func__(self.OnSelectCountryFlag))

	def __GetSelectedCountryFlag(self):
		if self.displaySlot < 0:
			return ""
		return net.GetAccountCharacterSlotDataString(self.filledSlots[self.displaySlot], net.ACCOUNT_CHARACTER_SLOT_COUNTRY_FLAG)

	def __RefreshCountryFlagControls(self):
		if not self.countryFlagBox:
			return

		if self.displaySlot < 0:
			self.countryFlagBoard.Hide()
			self.CloseCountryFlagDropdown()
			return

		self.countryFlagBoard.Show()
		self.countryFlagBox.SetCountry(self.__GetSelectedCountryFlag())

	def ToggleCountryFlagDropdown(self):
		if not self.countryFlagDropdown or self.displaySlot < 0:
			return

		if self.countryFlagDropdown.IsOpened():
			self.CloseCountryFlagDropdown()
			return

		(x, y) = self.countryFlagBox.GetGlobalPosition()
		height = self.countryFlagDropdown.GetHeight()
		belowY = y + self.countryFlagBox.GetHeight() + 2
		dropY = belowY if belowY + height <= wndMgr.GetScreenHeight() else y - height - 2
		self.countryFlagDropdown.SetCurrent(self.__GetSelectedCountryFlag())
		self.countryFlagDropdown.Open(x, dropY)

	def CloseCountryFlagDropdown(self):
		if self.countryFlagDropdown and self.countryFlagDropdown.IsOpened():
			self.countryFlagDropdown.Close()

	def OnSelectCountryFlag(self, code):
		if self.displaySlot < 0:
			return

		net.SendChangeCountryFlagPacket(self.filledSlots[self.displaySlot], code)
		self.__RefreshCountryFlagControls()


# SelectCharacterWindow.SelectSlot icinde ara:
			self.gauges[i].SetPercentage(min(stats[i], STAT_GAUGE_MAX), STAT_GAUGE_MAX)
		self.__ShowCharacter(realSlot)

# Altina ekle:
		self.__RefreshCountryFlagControls()


# SelectCharacterWindow.__ClearSelectedInfo icinde ara:
	def __ClearSelectedInfo(self):

# Altina ekle:
		self.__RefreshCountryFlagControls()


# SelectCharacterWindow.OnPressExitKey icinde ara:
	def OnPressExitKey(self):

# Altina ekle:
		if self.countryFlagDropdown and self.countryFlagDropdown.IsOpened():
			self.CloseCountryFlagDropdown()
			return TRUE

