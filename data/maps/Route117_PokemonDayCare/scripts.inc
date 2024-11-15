# 1 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 2 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_MapScripts::
# 3 "data/maps/Route117_PokemonDayCare/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
# 4 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.byte 0
# 5 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 6 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_OnTransition:
# 7 "data/maps/Route117_PokemonDayCare/scripts.pory"
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
# 8 "data/maps/Route117_PokemonDayCare/scripts.pory"
	end

OldTogepiGuy::
# 14 "data/maps/Route117_PokemonDayCare/scripts.pory"
	lock
# 15 "data/maps/Route117_PokemonDayCare/scripts.pory"
	faceplayer
# 16 "data/maps/Route117_PokemonDayCare/scripts.pory"
	goto_if_set FLAG_TOGEPI, OldTogepiGuy2
# 17 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox CouldYouHelpMe, MSGBOX_YESNO
# 18 "data/maps/Route117_PokemonDayCare/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TogepiEggDecline
# 19 "data/maps/Route117_PokemonDayCare/scripts.pory"
	getpartysize
# 20 "data/maps/Route117_PokemonDayCare/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, FullParty
# 21 "data/maps/Route117_PokemonDayCare/scripts.pory"
	message PlayerGotEgg
# 22 "data/maps/Route117_PokemonDayCare/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 23 "data/maps/Route117_PokemonDayCare/scripts.pory"
	waitfanfare
# 24 "data/maps/Route117_PokemonDayCare/scripts.pory"
	setflag FLAG_TOGEPI
# 25 "data/maps/Route117_PokemonDayCare/scripts.pory"
	giveegg SPECIES_TOGEPI
# 26 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox TyForTakingIt
# 27 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
	end


OldTogepiGuy2::
# 32 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox HowsTheEgg
# 33 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
	end


FullParty::
# 38 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox UhOhLol
# 39 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
	end


TogepiEggDecline::
# 44 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox MaybeIllFindSomeoneElse
# 45 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
	end


Togetic::
# 50 "data/maps/Route117_PokemonDayCare/scripts.pory"
	lock
# 51 "data/maps/Route117_PokemonDayCare/scripts.pory"
	faceplayer
# 52 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox TogeticTalk
# 53 "data/maps/Route117_PokemonDayCare/scripts.pory"
	playmoncry SPECIES_TOGETIC, CRY_MODE_NORMAL
# 54 "data/maps/Route117_PokemonDayCare/scripts.pory"
	waitmoncry
# 55 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
	end


HowsTheEgg::
# 59 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "How's the Togepi egg?$"

TogeticTalk::
# 63 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Togetic: Toge toge!$"

TyForTakingIt::
# 67 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Thank you for taking the egg for me\n"
	.string "young one. Please take care of it.$"

PlayerGotEgg::
# 72 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "{PLAYER} received the Egg.$"

UhOhLol::
# 76 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Seems like you naturally have a full\n"
	.string "team. Come back with at least 5.$"

MaybeIllFindSomeoneElse::
# 81 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Oh ok, maybe I will just look for\n"
	.string "someone else then.$"

CouldYouHelpMe::
# 86 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Oh, Hello there young one.\n"
	.string "I can tell by your looks that you're a\l"
	.string "trainer.\p"
	.string "My Togetic mysteriously left an egg\n"
	.string "here while I was gone so could you do me\l"
	.string "little favor?\p"
	.string "Could you take care of this egg for me?\n"
	.string "I'm too old to take care of it.$"
