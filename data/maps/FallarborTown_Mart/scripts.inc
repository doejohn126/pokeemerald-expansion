# 1 "data/maps/FallarborTown_Mart/scripts.pory"

# 2 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_MapScripts::
# 3 "data/maps/FallarborTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/FallarborTown_Mart/scripts.pory"

# 5 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_Clerk::
# 6 "data/maps/FallarborTown_Mart/scripts.pory"
	lock
# 7 "data/maps/FallarborTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/FallarborTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/FallarborTown_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/FallarborTown_Mart/scripts.pory"
	pokemart FallarborTown_Mart_Pokemart
# 11 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/FallarborTown_Mart/scripts.pory"
	release
# 13 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 14 "data/maps/FallarborTown_Mart/scripts.pory"

# 15 "data/maps/FallarborTown_Mart/scripts.pory"
	.align 2
# 16 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Pokemart:
# 17 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 18 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 19 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 20 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 21 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 22 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 23 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 24 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 25 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 26 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 27 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 28 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 29 "data/maps/FallarborTown_Mart/scripts.pory"
	pokemartlistend
# 30 "data/maps/FallarborTown_Mart/scripts.pory"

# 31 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_Woman::
# 32 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
# 33 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 34 "data/maps/FallarborTown_Mart/scripts.pory"

# 35 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_PokefanM::
# 36 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
# 37 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 38 "data/maps/FallarborTown_Mart/scripts.pory"

# 39 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_Skitty::
# 40 "data/maps/FallarborTown_Mart/scripts.pory"
	lock
# 41 "data/maps/FallarborTown_Mart/scripts.pory"
	faceplayer
# 42 "data/maps/FallarborTown_Mart/scripts.pory"
	waitse
# 43 "data/maps/FallarborTown_Mart/scripts.pory"
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
# 44 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
# 45 "data/maps/FallarborTown_Mart/scripts.pory"
	waitmoncry
# 46 "data/maps/FallarborTown_Mart/scripts.pory"
	release
# 47 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 48 "data/maps/FallarborTown_Mart/scripts.pory"

# 49 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_DecidingSkittyEvolve:
# 50 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "I'm having a hard time deciding if I\n"
# 51 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "should make my Skitty evolve or not.\p"
# 52 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "I only have to use this Moon Stone,\n"
# 53 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "but it's so hard to decide…\p"
# 54 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "If I make it evolve, it will become\n"
# 55 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "much stronger.\p"
# 56 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "But it will look so different, too.$"
# 57 "data/maps/FallarborTown_Mart/scripts.pory"

# 58 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_Skitty:
# 59 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "Skitty: Miyao?$"
# 60 "data/maps/FallarborTown_Mart/scripts.pory"

# 61 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_SellNuggetIFound:
# 62 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "This Nugget I found here…\n"
# 63 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "I suppose I'll have to sell it, seeing\l"
# 64 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "as how it has no other use.$"

Fallarbor_ExtraSalesWoman::
# 70 "data/maps/FallarborTown_Mart/scripts.pory"
	lock
# 71 "data/maps/FallarborTown_Mart/scripts.pory"
	faceplayer
# 72 "data/maps/FallarborTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 73 "data/maps/FallarborTown_Mart/scripts.pory"
	waitmessage
# 74 "data/maps/FallarborTown_Mart/scripts.pory"
	pokemart FallarborSecondMart
# 75 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain
# 76 "data/maps/FallarborTown_Mart/scripts.pory"
	release
	end


	.align 2
# 80 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborSecondMart:
# 81 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_LINKING_CORD
# 82 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_FIRE_STONE
# 83 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_WATER_STONE
# 84 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_LEAF_STONE
# 85 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_THUNDER_STONE
# 86 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_MOON_STONE
# 87 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_SUN_STONE
# 88 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_SHINY_STONE
# 89 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_DUSK_STONE
# 90 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_DAWN_STONE
# 91 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_ICE_STONE
# 92 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_DEEP_SEA_SCALE
# 93 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_DEEP_SEA_TOOTH
# 94 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_DRAGON_SCALE
# 95 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_UP_GRADE
# 96 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_KINGS_ROCK
# 97 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_METAL_COAT
# 98 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_OVAL_STONE
# 99 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_PRISM_SCALE
# 100 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_RAZOR_CLAW
# 101 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_SACHET
# 102 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_WHIPPED_DREAM
# 103 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_AUSPICIOUS_ARMOR
# 104 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_BLACK_AUGURITE
# 105 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_CHIPPED_POT
# 106 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_CRACKED_POT
# 107 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_GALARICA_CUFF
# 108 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_GALARICA_WREATH
# 109 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_MALICIOUS_ARMOR
# 110 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_MASTERPIECE_TEACUP
# 111 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_SWEET_APPLE
# 112 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_TART_APPLE
# 113 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_SYRUPY_APPLE
# 114 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_UNREMARKABLE_TEACUP
	.2byte ITEM_NONE
