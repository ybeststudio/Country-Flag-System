# Ara:
_originalRelease = None
DAY_MODE_DARK = 1

# Altina ekle:
_defaults = {'tooltip_blur': True, 'hide_dungeon_announcement': False, 'view_drop_ui': True, 'view_guideline': True, 'view_system_menu': True, 'view_event_icon': True, 'big_font_size': False, 'big_slot_count': False, 'save_status_window': True, 'small_affect_icon': False, 'guild_quest_window': True, 'whisper_sender_letter': True, 'guild_chat_to_whisper': False, 'small_whisper_window': False, 'show_guild_join_notification': True, 'auto_unequip_buffi_pvp': False, 'auto_equip_buffi_pvm': True, 'names_monsters_fov': False, 'show_country_flag': True, 'damage_monster': True, 'colored_damage': True, 'hide_mount': False, 'hide_buffi': False, 'queue_flash': True, 'mining_finish_flash': True, 'hide_effects_except_damage': False, 'hide_effects_from_others_players': False, 'hide_shaman_buff': False, 'hide_stone_effect': False, 'hide_monster_effect': False, 'hide_exp_effect': False, 'show_guild_grade': True, 'view_notification_history': True, 'auto_cape_after_warp': False, 'disable_level_up_confirmation': False, 'hide_metin_spawns': False, 'auto_hide_companion_map1': False, 'anti_aliasing': True, 'shadow_caster_player': True, 'shadow_caster_terrain': True, 'shadow_caster_trees': True, 'sun_rays': True, 'wet_ground': True, 'rain': False, 'storm': False, 'shooting_stars': True, 'water_ripple': True, 'enhanced_water': True, 'underwater': True, 'specular_reflection': True, 'water_reflection': True, 'local_light': True, 'death_cam_effect': True, 'speedtree_dynamic_light': True, 'speedtree_wind': True, 'speedtree_enhanced_foliage': True, 'speedtree_falling_leaves': True, 'high_performance_crowd_mode': False, 'hide_fps_minimap': False, 'font_type_index': 0, 'hide_pet': False, 'queue_effect_index': 0, 'event_stone_index': 0}


# Ara:
}
ACTOR_OPTIONS = ("hide_pet", "hide_mount", "damage_monster", "colored_damage", "damage_spacing_pos", "size_damage_pos", "death_cam_effect", "underwater", "env_volume_pos", "shadow_caster_player", "save_status_window", "env_darkness_pos", "env_saturation_pos", "env_contrast_pos", "env_temperature_pos", "anti_aliasing", "names_monsters_fov", "hide_effects_except_damage", "hide_effects_from_others_players", "hide_stone_effect", "hide_monster_effect", "guild_chat_to_whisper", "specular_reflection", "speedtree_wind", "sun_rays", "wet_ground", "local_light", "environment_color_r", "environment_color_g", "environment_color_b", "hide_shaman_buff")

# Altina ekle:
ACTOR_OPTIONS += ("show_country_flag", "shop_range_pos", "auto_hide_companion_map1", "hide_exp_effect", "water_ripple", "enhanced_water", "high_performance_crowd_mode")


# Apply icinde ara:
			systemSetting.SetPetStatusFlag(False)
		systemSetting.SetAdvancedOption(key, float(value))

# Altina ekle:
		if key == "show_country_flag" and app.ENABLE_MULTI_LANGUAGE_SYSTEM and app.ENABLE_EXTENDED_WHISPER_DETAILS:
			interface = _Interface()
			if interface:
				for dialog in interface.whisperDialogDict.values():
					if dialog.countryFlag:
						dialog.countryFlag.Show() if value and dialog.countryID else dialog.countryFlag.Hide()

