# 1 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_MapScripts::
# 3 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 5 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft::
# 6 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 10 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins
# 11 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 13 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 14 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 15 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 16 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins:
# 17 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PROTEIN
# 18 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CALCIUM
# 19 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_IRON
# 20 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ZINC
# 21 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CARBOS
# 22 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_HP_UP
# 23 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemartlistend
# 24 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 25 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight::
# 26 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 27 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 28 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 29 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 30 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters
# 31 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 32 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 33 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 34 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 35 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 36 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters:
# 37 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SPEED
# 38 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 39 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_ATTACK
# 40 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 41 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 42 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 43 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 44 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemartlistend
# 45 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 46 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM::
# 47 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
# 48 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 49 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 50 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_PokefanM::
# 51 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
# 52 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 53 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 54 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_Woman::
# 55 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
# 56 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 57 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 58 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
# 59 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "For quickly toughening up Pokémon,\n"
# 60 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "items are the best.\p"
# 61 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "Protein boosts Attack,\n"
# 62 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and Calcium raises Sp. Atk.$"
# 63 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 64 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance:
# 65 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I want my Pokémon to have more\n"
# 66 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "endurance.\p"
# 67 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I'm trying to decide whether to raise\n"
# 68 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "Defense with Iron, or Sp. Def with Zinc.$"
# 69 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 70 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
# 71 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I gave a Carbos to my Pokémon,\n"
# 72 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and its Speed went up.$"

Lilycove_ExtraSalesWoman3::
# 78 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 79 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 80 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 81 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 82 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveSecondMart3
# 83 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain
# 84 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
	end


Lilycove_ExtraSalesWoman4::
# 89 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 90 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 91 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 92 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 93 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveSecondMart4
# 94 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain
# 95 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
	end


	.align 2
# 99 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveSecondMart3:
# 100 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ABILITY_SHIELD
# 101 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ABSORB_BULB
# 102 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ADRENALINE_ORB
# 103 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_AIR_BALLOON
# 104 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_AMULET_COIN
# 105 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ASSAULT_VEST
# 106 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BIG_ROOT
# 107 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BINDING_BAND
# 108 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BLACK_BELT
# 109 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BLACK_GLASSES
# 110 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BLACK_SLUDGE
# 111 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BLUNDER_POLICY
# 112 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BRIGHT_POWDER
# 113 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BUG_GEM
# 114 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CELL_BATTERY
# 115 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CHARCOAL
# 116 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CHOICE_BAND
# 117 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CHOICE_SPECS
# 118 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CHOICE_SCARF
# 119 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CLEANSE_TAG
# 120 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_COVERT_CLOAK
# 121 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_DAMP_ROCK
# 122 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_DARK_GEM
# 123 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_DRAGON_GEM
# 124 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_EJECT_BUTTON
# 125 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_EJECT_PACK
# 126 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_EXPERT_BELT
# 127 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_FIGHTING_GEM
# 128 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_FIRE_GEM
# 129 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_FLAME_ORB
# 130 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 131 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_FLYING_GEM
# 132 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_FOCUS_BAND
# 133 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_FOCUS_SASH
# 134 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GHOST_GEM
# 135 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GRASS_GEM
# 136 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GRASSY_SEED
# 137 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GRIP_CLAW
# 138 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GROUND_GEM
# 139 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_HARD_STONE
# 140 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_HEAT_ROCK
# 141 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ICE_GEM
# 142 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ICY_ROCK
# 143 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_IRON_BALL
# 144 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LAGGING_TAIL
# 145 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LEEK
# 146 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LEFTOVERS
# 147 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LIFE_ORB
# 148 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LIGHT_CLAY
# 149 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LOADED_DICE
# 150 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LUCKY_EGG
# 151 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LUCKY_PUNCH
# 152 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LUMINOUS_MOSS
# 153 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MAGNET
# 154 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 155 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_METAL_POWDER
# 156 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_METRONOME
# 157 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MIRACLE_SEED
# 158 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MISTY_SEED
# 159 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MUSCLE_BAND
# 160 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MYSTIC_WATER
# 161 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_NEVER_MELT_ICE
# 162 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_NORMAL_GEM
# 163 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_POISON_GEM
# 164 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_POWER_HERB
# 165 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PROTECTIVE_PADS
# 166 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PSYCHIC_GEM
# 167 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PSYCHIC_SEED
# 168 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_QUICK_CLAW
# 169 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_RED_CARD
# 170 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_RING_TARGET
# 171 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ROCK_GEM
# 172 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ROCKY_HELMET
# 173 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ROOM_SERVICE
# 174 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SAFETY_GOGGLES
# 175 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SCOPE_LENS
# 176 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SHARP_BEAK
# 177 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SHED_SHELL
# 178 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SHELL_BELL
# 179 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SILK_SCARF
# 180 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SILVER_POWDER
# 181 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SMOKE_BALL
# 182 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SMOOTH_ROCK
# 183 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SNOWBALL
# 184 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SOFT_SAND
# 185 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SOOTHE_BELL
# 186 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SPELL_TAG
# 187 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_STEEL_GEM
# 188 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_STICKY_BARB
# 189 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_TERRAIN_EXTENDER
# 190 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_THROAT_SPRAY
# 191 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_TOXIC_ORB
# 192 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_TWISTED_SPOON
# 193 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_UTILITY_UMBRELLA
# 194 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_WEAKNESS_POLICY
# 195 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_WHITE_HERB
# 196 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_WIDE_LENS
# 197 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ZOOM_LENS
	.2byte ITEM_NONE

	.align 2
# 200 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveSecondMart4:
# 201 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_DESTINY_KNOT
# 202 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_EVIOLITE
# 203 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_EVERSTONE
# 204 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_POWER_ANKLET
# 205 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_POWER_BAND
# 206 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_POWER_LENS
# 207 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_POWER_BELT
# 208 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_POWER_BRACER
# 209 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_POWER_WEIGHT
# 210 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MACHO_BRACE
# 211 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LIGHT_BALL
# 212 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MIRROR_HERB
	.2byte ITEM_NONE
