# 1 "data/maps/EverGrandeCity/scripts.pory"

# 2 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_MapScripts::
# 3 "data/maps/EverGrandeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
# 4 "data/maps/EverGrandeCity/scripts.pory"
	.byte 0
# 5 "data/maps/EverGrandeCity/scripts.pory"

# 6 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_OnTransition:
# 7 "data/maps/EverGrandeCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 8 "data/maps/EverGrandeCity/scripts.pory"
	end
# 9 "data/maps/EverGrandeCity/scripts.pory"

# 10 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_VictoryRoadSign::
# 11 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
# 12 "data/maps/EverGrandeCity/scripts.pory"
	end
# 13 "data/maps/EverGrandeCity/scripts.pory"

# 14 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_CitySign::
# 15 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
# 16 "data/maps/EverGrandeCity/scripts.pory"
	end
# 17 "data/maps/EverGrandeCity/scripts.pory"

# 18 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_PokemonLeagueSign::
# 19 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
# 20 "data/maps/EverGrandeCity/scripts.pory"
	end
# 21 "data/maps/EverGrandeCity/scripts.pory"

# 22 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_SetVisitedEverGrande::
# 23 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_VISITED_EVER_GRANDE_CITY
# 24 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 25 "data/maps/EverGrandeCity/scripts.pory"
	end
# 26 "data/maps/EverGrandeCity/scripts.pory"

# 27 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringVictoryRoad:
# 28 "data/maps/EverGrandeCity/scripts.pory"
	.string "Entering Victory Road$"
# 29 "data/maps/EverGrandeCity/scripts.pory"

# 30 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringPokemonLeague:
# 31 "data/maps/EverGrandeCity/scripts.pory"
	.string "Entering Pokémon League\n"
# 32 "data/maps/EverGrandeCity/scripts.pory"
	.string "Center Gate$"
# 33 "data/maps/EverGrandeCity/scripts.pory"

# 34 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_CitySign:
# 35 "data/maps/EverGrandeCity/scripts.pory"
	.string "Ever Grande City\p"
# 36 "data/maps/EverGrandeCity/scripts.pory"
	.string "“The paradise of flowers, the sea,\n"
# 37 "data/maps/EverGrandeCity/scripts.pory"
	.string "and Pokémon.”$"

GeetaMain::
# 43 "data/maps/EverGrandeCity/scripts.pory"
	lock
# 44 "data/maps/EverGrandeCity/scripts.pory"
	faceplayer
# 45 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_defeated TRAINER_GEETA, GoodLuck
# 46 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GeetaPardonMe, MSGBOX_YESNO
# 47 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, GeetaAwwMan
# 48 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GiveItUrAll
# 49 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_GEETA, GeetaLoseText
# 50 "data/maps/EverGrandeCity/scripts.pory"
	msgbox AmazingPower
# 51 "data/maps/EverGrandeCity/scripts.pory"
	giveitem ITEM_TERA_ORB
# 52 "data/maps/EverGrandeCity/scripts.pory"
	msgbox ItShouldHelp
# 53 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


GoodLuck::
# 58 "data/maps/EverGrandeCity/scripts.pory"
	msgbox BecomeChamp
# 59 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


GeetaAwwMan::
# 64 "data/maps/EverGrandeCity/scripts.pory"
	msgbox HowUnfortunate
# 65 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


BecomeChamp::
# 69 "data/maps/EverGrandeCity/scripts.pory"
	.string "I hope we meet again especially if you\n"
	.string "become a Champion like me!$"

ItShouldHelp::
# 74 "data/maps/EverGrandeCity/scripts.pory"
	.string "This Tera Orb should be very useful\n"
	.string "going forward but do keep in mind...\p"
	.string "You cant Tera and Mega Evolve in the\n"
	.string "same battle and you need to charge\l"
	.string "your Orb using a Pokévial or at the\n"
	.string "Pokémon Center.\p"
	.string "Anyways though, good luck at the\n"
	.string "Pokémon League trainer and don't\l"
	.string "to charge your Tera Orb!$"

AmazingPower::
# 86 "data/maps/EverGrandeCity/scripts.pory"
	.string "Wow, your talent really impressed me!\p"
	.string "This was my first real time battling\n"
	.string "someone like this outside my region.\p"
	.string "Sorry for my rambling. But here's my\n"
	.string "reward, It's our main gimmick here in\l"
	.string "Paldea!$"

GeetaLoseText::
# 95 "data/maps/EverGrandeCity/scripts.pory"
	.string "Such overwhelming power… Such amazing\n"
	.string "skill…$"

GiveItUrAll::
# 100 "data/maps/EverGrandeCity/scripts.pory"
	.string "Great! I want to see the true measure\n"
	.string "of your talent!$"

HowUnfortunate::
# 105 "data/maps/EverGrandeCity/scripts.pory"
	.string "Oh my, are you certain?\p"
	.string "Well it is quite unfortunate I wont be\n"
	.string "able to see your talent.$"

GeetaPardonMe::
# 111 "data/maps/EverGrandeCity/scripts.pory"
	.string "Pardon me. Hello there trainer.\n"
	.string "I was just taking a little vacation\l"
	.string "around this region.\p"
	.string "I see you must be going for the\n"
	.string "Champion title knowing this is the\l"
	.string "Victory Road.\p"
	.string "Oh, but I've gotten ahead of myself.\p"
	.string "I am Geeta, chairwoman of the Pokémon\n"
	.string "League in the Paldea Region.\p"
	.string "So you're {PLAYER}? Well I'm very\n"
	.string "interested in seeing your talent.\p"
	.string "I'm aware that you guys don't use\n"
	.string "Terastallization so I have a reward you\l"
	.string "might like if you beat me.$"
