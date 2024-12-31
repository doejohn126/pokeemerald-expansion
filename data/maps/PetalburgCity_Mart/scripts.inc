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
	pokemartlistend
# 31 "data/maps/PetalburgCity_Mart/scripts.pory"

# 32 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_ExpandedItems::
# 33 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_Expanded
# 34 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 35 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 36 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 37 "data/maps/PetalburgCity_Mart/scripts.pory"

# 38 "data/maps/PetalburgCity_Mart/scripts.pory"
	.align 2
# 39 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_Expanded:
# 40 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 41 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 42 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 43 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 44 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 45 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 46 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 47 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 48 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 49 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LURE
# 50 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 51 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 52 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 53 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ORANGE_MAIL
# 54 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemartlistend
# 55 "data/maps/PetalburgCity_Mart/scripts.pory"

# 56 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Woman::
# 57 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
# 58 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 59 "data/maps/PetalburgCity_Mart/scripts.pory"

# 60 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Boy::
# 61 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
# 62 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 63 "data/maps/PetalburgCity_Mart/scripts.pory"

# 64 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Man::
# 65 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
# 66 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 67 "data/maps/PetalburgCity_Mart/scripts.pory"

# 68 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_WeakWillGrowStronger:
# 69 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Even if a Pokémon is weak now,\n"
# 70 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "it will grow stronger.\p"
# 71 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "The most important thing is love!\n"
# 72 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Love for your Pokémon!$"
# 73 "data/maps/PetalburgCity_Mart/scripts.pory"

# 74 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_RepelIsUseful:
# 75 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you use Repel?\n"
# 76 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "It keeps Pokémon away, so it's\l"
# 77 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "useful when you're in a hurry.$"
# 78 "data/maps/PetalburgCity_Mart/scripts.pory"

# 79 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
# 80 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you have any Antidotes with\n"
# 81 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "you?\p"
# 82 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "If you walk around with a poisoned\n"
# 83 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Pokémon, it will lose HP until it faints.\l"
# 84 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Take some Antidotes with you.$"

Petalburg_ExtraSalesWoman::
# 90 "data/maps/PetalburgCity_Mart/scripts.pory"
	lock
# 91 "data/maps/PetalburgCity_Mart/scripts.pory"
	faceplayer
# 92 "data/maps/PetalburgCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 93 "data/maps/PetalburgCity_Mart/scripts.pory"
	waitmessage
# 94 "data/maps/PetalburgCity_Mart/scripts.pory"
	goto_if_unset FLAG_PETALBURG_MART_EXPANDED_ITEMS, WaitHoldUp
# 95 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgSecondMart
# 96 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain
# 97 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
	end


WaitHoldUp::
# 102 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox Brucomeon
# 103 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
	end


	.align 2
# 107 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgSecondMart:
# 108 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 109 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_DUBIOUS_DISC
# 110 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GENGARITE
# 111 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GARDEVOIRITE
# 112 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AMPHAROSITE
# 113 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 114 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 115 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_MEDICHAMITE
# 116 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 117 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AGGRONITE
# 118 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_BANETTITE
# 119 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 120 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SCIZORITE
# 121 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PINSIRITE
# 122 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AERODACTYLITE
# 123 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 124 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ABOMASITE
# 125 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_KANGASKHANITE
# 126 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GYARADOSITE
# 127 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ABSOLITE
# 128 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 129 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_HERACRONITE
# 130 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_MAWILITE
# 131 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_MANECTITE
# 132 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GARCHOMPITE
# 133 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LATIOSITE
# 134 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LATIASITE
# 135 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SABLENITE
# 136 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ALTARIANITE
# 137 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GALLADITE
# 138 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AUDINITE
# 139 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_METAGROSSITE
# 140 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SHARPEDONITE
# 141 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SLOWBRONITE
# 142 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_STEELIXITE
# 143 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SLOWBRONITE
# 144 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PIDGEOTITE
# 145 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GLALITITE
# 146 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_CAMERUPTITE
# 147 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LOPUNNITE
# 148 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SALAMENCITE
# 149 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_BEEDRILLITE
# 150 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_DIANCITE
	.2byte ITEM_NONE

Brucomeon::
# 153 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Wait wait wait, hold the phone.\p"
	.string "Sorry but my shop isn't ready yet.\n"
	.string "I'd say return here when you're ready\l"
	.string "to head for Norman's gym.$"
