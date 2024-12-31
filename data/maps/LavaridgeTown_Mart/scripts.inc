# 1 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 2 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_MapScripts::
# 3 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 5 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_EventScript_Clerk::
# 6 "data/maps/LavaridgeTown_Mart/scripts.pory"
	lock
# 7 "data/maps/LavaridgeTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/LavaridgeTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/LavaridgeTown_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/LavaridgeTown_Mart/scripts.pory"
	pokemart LavaridgeTown_Mart_Pokemart
# 11 "data/maps/LavaridgeTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/LavaridgeTown_Mart/scripts.pory"
	release
# 13 "data/maps/LavaridgeTown_Mart/scripts.pory"
	end
# 14 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 15 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.align 2
# 16 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_Pokemart:
# 17 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 18 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 19 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 20 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 21 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 22 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 23 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 24 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 25 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_SUPER_LURE
# 26 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 27 "data/maps/LavaridgeTown_Mart/scripts.pory"
	pokemartlistend
# 28 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 29 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_EventScript_ExpertM::
# 30 "data/maps/LavaridgeTown_Mart/scripts.pory"
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
# 31 "data/maps/LavaridgeTown_Mart/scripts.pory"
	end
# 32 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 33 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_EventScript_OldWoman::
# 34 "data/maps/LavaridgeTown_Mart/scripts.pory"
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
# 35 "data/maps/LavaridgeTown_Mart/scripts.pory"
	end
# 36 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 37 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_Text_XSpeedFirstStrike:
# 38 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "Use X Speed to add to a Pokémon's\n"
# 39 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "Speed in battle.\p"
# 40 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "That will help it get in the first\n"
# 41 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "strike--a decided advantage!$"
# 42 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 43 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
# 44 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "On Mt. Chimney's peak, there's a local\n"
# 45 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "specialty that you can buy only there.\p"
# 46 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "Give it to a Pokémon--it will be elated.$"

Lavaridge_ExtraSalesWoman::
# 52 "data/maps/LavaridgeTown_Mart/scripts.pory"
	lock
# 53 "data/maps/LavaridgeTown_Mart/scripts.pory"
	faceplayer
# 54 "data/maps/LavaridgeTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 55 "data/maps/LavaridgeTown_Mart/scripts.pory"
	waitmessage
# 56 "data/maps/LavaridgeTown_Mart/scripts.pory"
	pokemart LavaridgeSecondMart
# 57 "data/maps/LavaridgeTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain
# 58 "data/maps/LavaridgeTown_Mart/scripts.pory"
	release
	end


	.align 2
# 62 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeSecondMart:
# 63 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_SCEPTILITE
# 64 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_BLAZIKENITE
# 65 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_SWAMPERTITE
# 66 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 67 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 68 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_VENUSAURITE
# 69 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_BLASTOISINITE
# 70 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_RAZOR_FANG
# 71 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_REAPER_CLOTH
# 72 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_PROTECTOR
# 73 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_ELECTIRIZER
# 74 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_NONE
