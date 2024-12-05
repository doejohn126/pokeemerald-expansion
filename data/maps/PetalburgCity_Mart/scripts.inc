# 1 "data/maps/PetalburgCity_Mart/scripts.pory"

# 2 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_MapScripts::
# 3 "data/maps/PetalburgCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/PetalburgCity_Mart/scripts.pory"

# 5 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Clerk::
# 6 "data/maps/PetalburgCity_Mart/scripts.pory"
	lock
# 7 "data/maps/PetalburgCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/PetalburgCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/PetalburgCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/PetalburgCity_Mart/scripts.pory"
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
# 11 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_Basic
# 12 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 13 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 14 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 15 "data/maps/PetalburgCity_Mart/scripts.pory"

# 16 "data/maps/PetalburgCity_Mart/scripts.pory"
	.align 2
# 17 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_Basic:
# 18 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 19 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 20 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 21 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 22 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 23 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 24 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 25 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LURE
# 26 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 27 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 28 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 29 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ORANGE_MAIL
# 30 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_NONE
# 31 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 32 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 33 "data/maps/PetalburgCity_Mart/scripts.pory"

# 34 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_ExpandedItems::
# 35 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_Expanded
# 36 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 37 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 38 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 39 "data/maps/PetalburgCity_Mart/scripts.pory"

# 40 "data/maps/PetalburgCity_Mart/scripts.pory"
	.align 2
# 41 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_Expanded:
# 42 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 43 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 44 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 45 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 46 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 47 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 48 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 49 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 50 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 51 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LURE
# 52 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 53 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 54 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 55 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ORANGE_MAIL
# 56 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_NONE
# 57 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 58 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 59 "data/maps/PetalburgCity_Mart/scripts.pory"

# 60 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Woman::
# 61 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
# 62 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 63 "data/maps/PetalburgCity_Mart/scripts.pory"

# 64 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Boy::
# 65 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
# 66 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 67 "data/maps/PetalburgCity_Mart/scripts.pory"

# 68 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Man::
# 69 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
# 70 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 71 "data/maps/PetalburgCity_Mart/scripts.pory"

# 72 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_WeakWillGrowStronger:
# 73 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Even if a Pokémon is weak now,\n"
# 74 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "it will grow stronger.\p"
# 75 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "The most important thing is love!\n"
# 76 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Love for your Pokémon!$"
# 77 "data/maps/PetalburgCity_Mart/scripts.pory"

# 78 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_RepelIsUseful:
# 79 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you use Repel?\n"
# 80 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "It keeps Pokémon away, so it's\l"
# 81 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "useful when you're in a hurry.$"
# 82 "data/maps/PetalburgCity_Mart/scripts.pory"

# 83 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
# 84 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you have any Antidotes with\n"
# 85 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "you?\p"
# 86 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "If you walk around with a poisoned\n"
# 87 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Pokémon, it will lose HP until it faints.\l"
# 88 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Take some Antidotes with you.$"

Petalburg_ExtraSalesWoman::
# 94 "data/maps/PetalburgCity_Mart/scripts.pory"
	lock
# 95 "data/maps/PetalburgCity_Mart/scripts.pory"
	faceplayer
# 96 "data/maps/PetalburgCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 97 "data/maps/PetalburgCity_Mart/scripts.pory"
	waitmessage
# 98 "data/maps/PetalburgCity_Mart/scripts.pory"
	goto_if_unset FLAG_PETALBURG_MART_EXPANDED_ITEMS, WaitHoldUp
# 99 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgSecondMart
# 100 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain
# 101 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
	end


WaitHoldUp::
# 106 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox Brucomeon
# 107 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
	end


	.align 2
# 111 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgSecondMart:
# 112 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 113 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_DUBIOUS_DISC
# 114 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GENGARITE
# 115 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GARDEVOIRITE
# 116 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AMPHAROSITE
# 117 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 118 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 119 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_MEDICHAMITE
# 120 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 121 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AGGRONITE
# 122 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_BANETTITE
# 123 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 124 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SCIZORITE
# 125 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PINSIRITE
# 126 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AERODACTYLITE
# 127 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 128 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ABOMASITE
# 129 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_KANGASKHANITE
# 130 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GYARADOSITE
# 131 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ABSOLITE
# 132 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 133 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_HERACRONITE
# 134 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_MAWILITE
# 135 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_MANECTITE
# 136 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GARCHOMPITE
# 137 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LATIOSITE
# 138 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LATIASITE
# 139 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SABLENITE
# 140 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ALTARIANITE
# 141 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GALLADITE
# 142 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AUDINITE
# 143 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_METAGROSSITE
# 144 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SHARPEDONITE
# 145 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SLOWBRONITE
# 146 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_STEELIXITE
# 147 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SLOWBRONITE
# 148 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PIDGEOTITE
# 149 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GLALITITE
# 150 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_CAMERUPTITE
# 151 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LOPUNNITE
# 152 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SALAMENCITE
# 153 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_BEEDRILLITE
# 154 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_DIANCITE
	.2byte ITEM_NONE

Brucomeon::
# 157 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Wait wait wait, hold the phone.\p"
	.string "Sorry but my shop isn't ready yet.\n"
	.string "I'd say return here when you're ready\l"
	.string "to head for Norman's gym.$"
