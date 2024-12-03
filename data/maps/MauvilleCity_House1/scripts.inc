MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_PICKAXE, MauvilleCity_House1_EventScript_ReceivedPickaxe
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	giveitem ITEM_ROCKSMASH_TOOL
	setflag FLAG_PICKAXE
	release
	end

MauvilleCity_House1_EventScript_ReceivedPickaxe::
	msgbox MauvillePickaxeOrRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Woohoo!\p"
	.string "I hear people call me the Rock Smash\n"
	.string "Guy, but I find that sort of degrading.\p"
	.string "I think I deserve a bit more respect,\n"
	.string "like maybe the Rock Smash Dude.\p"
	.string "Woohoo!\p"
	.string "Anyways, your Pokémon look pretty\n"
	.string "strong.\p"
	.string "I like that!\n"
	.string "Here, take this Hidden Machine!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "That HM contains Rock Smash.\p"
	.string "If you come across large boulders\n"
	.string "that block your path…\p"
	.string "Well, use that HM move and smash\n"
	.string "them right out of your way!\p"
	.string "Yes, sir! Smash rocks aside, I say!\n"
	.string "Woohoo!$"

MauvillePickaxeOrRockSmash:
	.string "Hmm, I might become Pickaxe Man again.\n"
	.string "To be fair Pokémon did remove HM's.\p"
	.string "Eh screw it, I'll be both! Woohoo!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "....... .......\n"
	.string "What??\p"
	.string "Oh, I think I know!\n"
	.string "You must not be satisfied with my HM!\p"
	.string "I got you covered because back in the\n"
	.string "day, I used to be Pickaxe Dude!\p"
	.string "Okay well, maybe they called me Pickaxe\n"
	.string "Guy but I never liked that name.\p"
	.string "I'll tell ya what, you can have one of my\n"
	.string "old trusty Pickaxes! Woohoo!$"


