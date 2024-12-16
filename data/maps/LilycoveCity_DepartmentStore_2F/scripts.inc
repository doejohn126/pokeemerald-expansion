# 1 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_MapScripts::
# 3 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 5 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_Cook::
# 6 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly, MSGBOX_NPC
# 7 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 8 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 9 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_PokefanF::
# 10 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
# 11 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 12 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 13 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_Sailor::
# 14 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
# 15 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 16 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 17 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft::
# 18 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 19 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 20 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message gText_HowMayIServeYou
# 21 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 22 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart1
# 23 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 24 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
# 25 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 26 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 27 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.align 2
# 28 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Pokemart1:
# 29 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 30 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 31 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 32 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FAST_BALL
# 33 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LEVEL_BALL
# 34 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LURE_BALL
# 35 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HEAVY_BALL
# 36 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LOVE_BALL
# 37 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FRIEND_BALL
# 38 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MOON_BALL
# 39 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SPORT_BALL
# 40 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NET_BALL
# 41 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 42 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 43 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 44 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TIMER_BALL
# 45 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LUXURY_BALL
# 46 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 47 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 48 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 49 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PARK_BALL
# 50 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DREAM_BALL
# 51 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BEAST_BALL
# 52 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_CHERISH_BALL
# 53 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_STRANGE_BALL
# 54 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 55 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 56 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 57 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 58 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 59 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ICE_HEAL
# 60 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_AWAKENING
# 61 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
# 62 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NONE
# 63 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
# 64 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 65 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 66 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight::
# 67 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 68 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 69 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message gText_HowMayIServeYou
# 70 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 71 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart2
# 72 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 73 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
# 74 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 75 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 76 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.align 2
# 77 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Pokemart2:
# 78 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_POTION
# 79 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 80 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 81 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 82 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 83 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REVIVE
# 84 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REPEL
# 85 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LURE
# 86 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 87 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 88 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_WAVE_MAIL
# 89 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MECH_MAIL
# 90 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NONE
# 91 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
# 92 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 93 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 94 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly:
# 95 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "Learn to use items properly.\n"
# 96 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "That's basic, really.$"
# 97 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 98 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband:
# 99 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "My husband is waiting at home.\n"
# 100 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "What would make a good gift for him?$"
# 101 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 102 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems:
# 103 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "I'm leaving on a long journey soon.\n"
# 104 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "I need to stock up on items.$"

Lilycove_ExtraSalesWoman1::
# 110 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 111 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 112 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message gText_HowMayIServeYou
# 113 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 114 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart LilycoveSecondMart
# 115 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox gText_PleaseComeAgain
# 116 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
	end


Lilycove_ExtraSalesWoman2::
# 121 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 122 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 123 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message gText_HowMayIServeYou
# 124 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 125 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart LilycoveSecondMart2
# 126 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox gText_PleaseComeAgain
# 127 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
	end


	.align 2
# 131 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveSecondMart:
# 132 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 133 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ABILITY_PATCH
# 134 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LINKING_CORD
# 135 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FIRE_STONE
# 136 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_WATER_STONE
# 137 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LEAF_STONE
# 138 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_THUNDER_STONE
# 139 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MOON_STONE
# 140 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SUN_STONE
# 141 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SHINY_STONE
# 142 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DUSK_STONE
# 143 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DAWN_STONE
# 144 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ICE_STONE
# 145 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DEEP_SEA_SCALE
# 146 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DEEP_SEA_TOOTH
# 147 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DRAGON_SCALE
# 148 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_UP_GRADE
# 149 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_KINGS_ROCK
# 150 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_METAL_COAT
# 151 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_OVAL_STONE
# 152 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PRISM_SCALE
# 153 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_RAZOR_CLAW
# 154 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SACHET
# 155 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_WHIPPED_DREAM
# 156 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_AUSPICIOUS_ARMOR
# 157 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BLACK_AUGURITE
# 158 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_CHIPPED_POT
# 159 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_CRACKED_POT
# 160 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GALARICA_CUFF
# 161 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GALARICA_WREATH
# 162 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MALICIOUS_ARMOR
# 163 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MASTERPIECE_TEACUP
# 164 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SWEET_APPLE
# 165 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TART_APPLE
# 166 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SYRUPY_APPLE
# 167 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_UNREMARKABLE_TEACUP
# 168 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PEAT_BLOCK
# 169 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SCROLL_OF_DARKNESS
# 170 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SCROLL_OF_WATERS
# 171 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_METAL_ALLOY
# 172 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ELECTIRIZER
# 173 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAGMARIZER
# 174 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PROTECTOR
# 175 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_NONE

	.align 2
# 178 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveSecondMart2:
# 179 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PINK_NECTAR
# 180 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PURPLE_NECTAR
# 181 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_RED_NECTAR
# 182 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_YELLOW_NECTAR
# 183 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_METEORITE
# 184 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ADAMANT_CRYSTAL
# 185 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LUSTROUS_GLOBE
# 186 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DNA_SPLICERS
# 187 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REINS_OF_UNITY
# 188 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GRACIDEA
# 189 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REVEAL_GLASS
# 190 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GRISEOUS_CORE
# 191 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_WELLSPRING_MASK
# 192 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_CORNERSTONE_MASK
# 193 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HEARTHFLAME_MASK
# 194 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_RUSTED_SHIELD
# 195 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_RUSTED_SWORD
# 196 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BLUE_ORB
# 197 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_RED_ORB
# 198 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PRISON_BOTTLE
# 199 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_N_LUNARIZER
# 200 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_N_SOLARIZER
# 201 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SOUL_DEW
# 202 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SCEPTILITE
# 203 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BLAZIKENITE
# 204 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SWAMPERTITE
# 205 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 206 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 207 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_VENUSAURITE
# 208 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BLASTOISINITE
# 209 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GENGARITE
# 210 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GARDEVOIRITE
# 211 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_AMPHAROSITE
# 212 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 213 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 214 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MEDICHAMITE
# 215 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 216 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_AGGRONITE
# 217 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BANETTITE
# 218 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 219 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SCIZORITE
# 220 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PINSIRITE
# 221 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_AERODACTYLITE
# 222 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 223 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ABOMASITE
# 224 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_KANGASKHANITE
# 225 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GYARADOSITE
# 226 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ABSOLITE
# 227 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 228 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HERACRONITE
# 229 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAWILITE
# 230 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MANECTITE
# 231 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GARCHOMPITE
# 232 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LATIOSITE
# 233 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LATIASITE
# 234 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SABLENITE
# 235 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ALTARIANITE
# 236 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GALLADITE
# 237 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_AUDINITE
# 238 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_METAGROSSITE
# 239 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SHARPEDONITE
# 240 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SLOWBRONITE
# 241 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_STEELIXITE
# 242 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SLOWBRONITE
# 243 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PIDGEOTITE
# 244 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GLALITITE
# 245 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_CAMERUPTITE
# 246 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LOPUNNITE
# 247 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SALAMENCITE
# 248 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BEEDRILLITE
# 249 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DIANCITE
	.2byte ITEM_NONE
