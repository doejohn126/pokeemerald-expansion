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

JaydenFinalMainFight1::
# 43 "data/maps/EverGrandeCity/scripts.pory"
	lock
# 44 "data/maps/EverGrandeCity/scripts.pory"
	applymovement 2, JaydenApproachYetAgain1
# 45 "data/maps/EverGrandeCity/scripts.pory"
	waitmovement 0
# 46 "data/maps/EverGrandeCity/scripts.pory"
	msgbox WellHereWeGo
# 47 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_JAYDEN_5, JaydenLose
# 48 "data/maps/EverGrandeCity/scripts.pory"
	msgbox ScotMan
# 49 "data/maps/EverGrandeCity/scripts.pory"
	applymovement 2, JaydenHeadOut1
# 50 "data/maps/EverGrandeCity/scripts.pory"
	waitmovement 0
# 51 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_JAYDEN_EVERGRANDE, 1
# 52 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_JAYDEN_EVERGRANDE
# 53 "data/maps/EverGrandeCity/scripts.pory"
	removeobject 2
# 54 "data/maps/EverGrandeCity/scripts.pory"
	playse SE_EXIT
# 55 "data/maps/EverGrandeCity/scripts.pory"
	waitse
# 56 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


JaydenFinalMainFight2::
# 61 "data/maps/EverGrandeCity/scripts.pory"
	lock
# 62 "data/maps/EverGrandeCity/scripts.pory"
	addobject 2
# 63 "data/maps/EverGrandeCity/scripts.pory"
	applymovement 2, JaydenApproachYetAgain2
# 64 "data/maps/EverGrandeCity/scripts.pory"
	waitmovement 0
# 65 "data/maps/EverGrandeCity/scripts.pory"
	msgbox WellHereWeGo
# 66 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_JAYDEN_5, JaydenLose
# 67 "data/maps/EverGrandeCity/scripts.pory"
	msgbox ScotMan
# 68 "data/maps/EverGrandeCity/scripts.pory"
	applymovement 2, JaydenHeadOut2
# 69 "data/maps/EverGrandeCity/scripts.pory"
	waitmovement 0
# 70 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_JAYDEN_EVERGRANDE, 1
# 71 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_JAYDEN_EVERGRANDE
# 72 "data/maps/EverGrandeCity/scripts.pory"
	removeobject 2
# 73 "data/maps/EverGrandeCity/scripts.pory"
	playse SE_EXIT
# 74 "data/maps/EverGrandeCity/scripts.pory"
	waitse
# 75 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


GeetaMain::
# 80 "data/maps/EverGrandeCity/scripts.pory"
	lock
# 81 "data/maps/EverGrandeCity/scripts.pory"
	faceplayer
# 82 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_defeated TRAINER_GEETA, GoodLuck
# 83 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GeetaPardonMe, MSGBOX_YESNO
# 84 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, GeetaAwwMan
# 85 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GiveItUrAll
# 86 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_GEETA, GeetaLoseText
# 87 "data/maps/EverGrandeCity/scripts.pory"
	msgbox AmazingPower
# 88 "data/maps/EverGrandeCity/scripts.pory"
	giveitem ITEM_TERA_ORB
# 89 "data/maps/EverGrandeCity/scripts.pory"
	msgbox ItShouldHelp
# 90 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


GoodLuck::
# 95 "data/maps/EverGrandeCity/scripts.pory"
	msgbox BecomeChamp
# 96 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


GeetaAwwMan::
# 101 "data/maps/EverGrandeCity/scripts.pory"
	msgbox HowUnfortunate
# 102 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


# 106 "data/maps/EverGrandeCity/scripts.pory"
JaydenApproachYetAgain1:
# 107 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 107 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 107 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 107 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 107 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 107 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 108 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 108 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 108 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 108 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
	step_end

# 111 "data/maps/EverGrandeCity/scripts.pory"
JaydenHeadOut1:
# 112 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 113 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 113 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 113 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 114 "data/maps/EverGrandeCity/scripts.pory"
	walk_up
# 114 "data/maps/EverGrandeCity/scripts.pory"
	walk_up
	step_end

# 117 "data/maps/EverGrandeCity/scripts.pory"
JaydenApproachYetAgain2:
# 118 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 118 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 118 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 118 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 118 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 118 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 118 "data/maps/EverGrandeCity/scripts.pory"
	walk_down
# 119 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 119 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 119 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 119 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
	step_end

# 122 "data/maps/EverGrandeCity/scripts.pory"
JaydenHeadOut2:
# 123 "data/maps/EverGrandeCity/scripts.pory"
	walk_up
# 124 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 124 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 124 "data/maps/EverGrandeCity/scripts.pory"
	walk_left
# 125 "data/maps/EverGrandeCity/scripts.pory"
	walk_up
	step_end

ScotMan::
# 128 "data/maps/EverGrandeCity/scripts.pory"
	.string "After I lost in the League, a guy named\n"
	.string "Scot told me I had potential in a place\l"
	.string "called the Battle Frontier.\p"
	.string "So I think that's what I'll put the rest\n"
	.string "of my time in going forward.\p"
	.string "But hey, next time we see each other, I\n"
	.string "want you to be the Champion you hear?\p"
	.string "Well, until then my friend...$"

JaydenLose::
# 139 "data/maps/EverGrandeCity/scripts.pory"
	.string "Y'know {PLAYER}, this battle had me\n"
	.string "thinking back to our battle in the woods.\p"
	.string "I honestly think you can become the\n"
	.string "Champion.$"

WellHereWeGo::
# 146 "data/maps/EverGrandeCity/scripts.pory"
	.string "Hey {PLAYER}, good to see you again.\n"
	.string ".................................\p"
	.string "I just battled in the Pokémon League...\n"
	.string "And I lost...\p"
	.string "I know you're going to head in there so..\n"
	.string "We need to have one last battle!$"

BecomeChamp::
# 155 "data/maps/EverGrandeCity/scripts.pory"
	.string "I hope we meet again especially if you\n"
	.string "become a Champion like me!$"

ItShouldHelp::
# 160 "data/maps/EverGrandeCity/scripts.pory"
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
# 172 "data/maps/EverGrandeCity/scripts.pory"
	.string "Wow, your talent really impressed me!\p"
	.string "This was my first real time battling\n"
	.string "someone like this outside my region.\p"
	.string "Sorry for my rambling. But here's my\n"
	.string "reward, It's our main gimmick here in\l"
	.string "Paldea!$"

GeetaLoseText::
# 181 "data/maps/EverGrandeCity/scripts.pory"
	.string "Such overwhelming power… Such amazing\n"
	.string "skill…$"

GiveItUrAll::
# 186 "data/maps/EverGrandeCity/scripts.pory"
	.string "Great! I want to see the true measure\n"
	.string "of your talent!$"

HowUnfortunate::
# 191 "data/maps/EverGrandeCity/scripts.pory"
	.string "Oh my, are you certain?\p"
	.string "Well it is quite unfortunate I wont be\n"
	.string "able to see your talent.$"

GeetaPardonMe::
# 197 "data/maps/EverGrandeCity/scripts.pory"
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
