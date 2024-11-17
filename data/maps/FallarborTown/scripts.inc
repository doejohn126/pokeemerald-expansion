# 1 "data/maps/FallarborTown/scripts.pory"

# 2 "data/maps/FallarborTown/scripts.pory"
FallarborTown_MapScripts::
# 3 "data/maps/FallarborTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
# 4 "data/maps/FallarborTown/scripts.pory"
	.byte 0
# 5 "data/maps/FallarborTown/scripts.pory"

# 6 "data/maps/FallarborTown/scripts.pory"
FallarborTown_OnTransition:
# 7 "data/maps/FallarborTown/scripts.pory"
	setflag FLAG_VISITED_FALLARBOR_TOWN
# 8 "data/maps/FallarborTown/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 9 "data/maps/FallarborTown/scripts.pory"
	clearflag FLAG_CONTEST_SKETCH_CREATED
# 10 "data/maps/FallarborTown/scripts.pory"
	end
# 11 "data/maps/FallarborTown/scripts.pory"

# 12 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_ExpertM::
# 13 "data/maps/FallarborTown/scripts.pory"
	lock
# 14 "data/maps/FallarborTown/scripts.pory"
	faceplayer
# 15 "data/maps/FallarborTown/scripts.pory"
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
# 16 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
# 17 "data/maps/FallarborTown/scripts.pory"
	release
# 18 "data/maps/FallarborTown/scripts.pory"
	end
# 19 "data/maps/FallarborTown/scripts.pory"

# 20 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_ExpertMNormal::
# 21 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
# 22 "data/maps/FallarborTown/scripts.pory"
	release
# 23 "data/maps/FallarborTown/scripts.pory"
	end
# 24 "data/maps/FallarborTown/scripts.pory"

# 25 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_Girl::
# 26 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
# 27 "data/maps/FallarborTown/scripts.pory"
	end
# 28 "data/maps/FallarborTown/scripts.pory"

# 29 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_Gentleman::
# 30 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
# 31 "data/maps/FallarborTown/scripts.pory"
	end
# 32 "data/maps/FallarborTown/scripts.pory"

# 33 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_Azurill::
# 34 "data/maps/FallarborTown/scripts.pory"
	lock
# 35 "data/maps/FallarborTown/scripts.pory"
	faceplayer
# 36 "data/maps/FallarborTown/scripts.pory"
	waitse
# 37 "data/maps/FallarborTown/scripts.pory"
	playmoncry SPECIES_DEDENNE, CRY_MODE_NORMAL
# 38 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
# 39 "data/maps/FallarborTown/scripts.pory"
	waitmoncry
# 40 "data/maps/FallarborTown/scripts.pory"
	release
# 41 "data/maps/FallarborTown/scripts.pory"
	end
# 42 "data/maps/FallarborTown/scripts.pory"

# 43 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_BattleTentSign::
# 44 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
# 45 "data/maps/FallarborTown/scripts.pory"
	end
# 46 "data/maps/FallarborTown/scripts.pory"

# 47 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_TownSign::
# 48 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
# 49 "data/maps/FallarborTown/scripts.pory"
	end
# 50 "data/maps/FallarborTown/scripts.pory"

# 51 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_MoveTutorSign::
# 52 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
# 53 "data/maps/FallarborTown/scripts.pory"
	end
# 54 "data/maps/FallarborTown/scripts.pory"

# 55 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_ShadyCharactersCozmosHome:
# 56 "data/maps/FallarborTown/scripts.pory"
	.string "Something's happening,\n"
# 57 "data/maps/FallarborTown/scripts.pory"
	.string "and I don't like it!\p"
# 58 "data/maps/FallarborTown/scripts.pory"
	.string "I've seen shady characters wandering\n"
# 59 "data/maps/FallarborTown/scripts.pory"
	.string "in and out of PROF. COZMO's home…$"
# 60 "data/maps/FallarborTown/scripts.pory"

# 61 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_RegionKnownForMeteors:
# 62 "data/maps/FallarborTown/scripts.pory"
	.string "This region's been known for meteors\n"
# 63 "data/maps/FallarborTown/scripts.pory"
	.string "since the olden days.\p"
# 64 "data/maps/FallarborTown/scripts.pory"
	.string "They say METEOR FALLS was gouged out\n"
# 65 "data/maps/FallarborTown/scripts.pory"
	.string "by a falling meteorite long ago.$"
# 66 "data/maps/FallarborTown/scripts.pory"

# 67 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_MyPreciousAzurill:
# 68 "data/maps/FallarborTown/scripts.pory"
	.string "See! Take a look!\n"
# 69 "data/maps/FallarborTown/scripts.pory"
	.string "This is my precious Dedenne!\p"
# 70 "data/maps/FallarborTown/scripts.pory"
	.string "It's slick and smooth and plushy, too!$"
# 71 "data/maps/FallarborTown/scripts.pory"

# 72 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_Azurill:
# 73 "data/maps/FallarborTown/scripts.pory"
	.string "Dedenne: Redeeeee.$"
# 74 "data/maps/FallarborTown/scripts.pory"

# 75 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_HaveYouChallengedFlannery:
# 76 "data/maps/FallarborTown/scripts.pory"
	.string "Have you already challenged FLANNERY,\n"
# 77 "data/maps/FallarborTown/scripts.pory"
	.string "the LEADER of LAVARIDGE GYM?\p"
# 78 "data/maps/FallarborTown/scripts.pory"
	.string "The girl's grandfather was famous.\n"
# 79 "data/maps/FallarborTown/scripts.pory"
	.string "He was one of the ELITE FOUR in the\l"
# 80 "data/maps/FallarborTown/scripts.pory"
	.string "POKéMON LEAGUE at one point.\p"
# 81 "data/maps/FallarborTown/scripts.pory"
	.string "It wouldn't surprise me to see FLANNERY\n"
# 82 "data/maps/FallarborTown/scripts.pory"
	.string "become a great TRAINER in her own\l"
# 83 "data/maps/FallarborTown/scripts.pory"
	.string "right.$"
# 84 "data/maps/FallarborTown/scripts.pory"

# 85 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_BattleTentSign:
# 86 "data/maps/FallarborTown/scripts.pory"
	.string "BATTLE TENT FALLARBOR SITE\n"
# 87 "data/maps/FallarborTown/scripts.pory"
	.string "“May the Greatest Teams Gather!”$"
# 88 "data/maps/FallarborTown/scripts.pory"

# 89 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_TownSign:
# 90 "data/maps/FallarborTown/scripts.pory"
	.string "FALLARBOR TOWN\n"
# 91 "data/maps/FallarborTown/scripts.pory"
	.string "“A farm community with small gardens.”$"
# 92 "data/maps/FallarborTown/scripts.pory"

# 93 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_MoveTutorSign:
# 94 "data/maps/FallarborTown/scripts.pory"
	.string "MOVE TUTOR'S HOUSE\n"
# 95 "data/maps/FallarborTown/scripts.pory"
	.string "“New moves taught to POKéMON.”$"

FantinaMain::
# 101 "data/maps/FallarborTown/scripts.pory"
	lock
# 102 "data/maps/FallarborTown/scripts.pory"
	faceplayer
# 103 "data/maps/FallarborTown/scripts.pory"
	goto_if_defeated TRAINER_FANTINA, BeatFantina
# 104 "data/maps/FallarborTown/scripts.pory"
	playse SE_PIN
# 105 "data/maps/FallarborTown/scripts.pory"
	applymovement 5, Common_Movement_ExclamationMark
# 106 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 107 "data/maps/FallarborTown/scripts.pory"
	applymovement 5, Common_Movement_Delay32
# 108 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 109 "data/maps/FallarborTown/scripts.pory"
	applymovement 5, FantinaSpin
# 110 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 111 "data/maps/FallarborTown/scripts.pory"
	msgbox FantinaIntro, MSGBOX_YESNO
# 112 "data/maps/FallarborTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, DeclineFantinaFight
# 113 "data/maps/FallarborTown/scripts.pory"
	msgbox LetsStart
# 114 "data/maps/FallarborTown/scripts.pory"
	trainerbattle_no_intro TRAINER_FANTINA, FantinaLose
# 115 "data/maps/FallarborTown/scripts.pory"
	msgbox YoureStrong
# 116 "data/maps/FallarborTown/scripts.pory"
	giveitem ITEM_TM_SHADOW_BALL
# 117 "data/maps/FallarborTown/scripts.pory"
	release
	end


BeatFantina::
# 122 "data/maps/FallarborTown/scripts.pory"
	msgbox FightOthers
	return


DeclineFantinaFight::
# 126 "data/maps/FallarborTown/scripts.pory"
	msgbox MaybeIWasMistaken
# 127 "data/maps/FallarborTown/scripts.pory"
	release
	end


Mismagius::
# 132 "data/maps/FallarborTown/scripts.pory"
	lock
# 133 "data/maps/FallarborTown/scripts.pory"
	faceplayer
# 134 "data/maps/FallarborTown/scripts.pory"
	playmoncry SPECIES_MISMAGIUS, CRY_MODE_NORMAL
# 135 "data/maps/FallarborTown/scripts.pory"
	msgbox MismagiusCry
# 136 "data/maps/FallarborTown/scripts.pory"
	waitmoncry
# 137 "data/maps/FallarborTown/scripts.pory"
	release
	end


# 141 "data/maps/FallarborTown/scripts.pory"
FantinaSpin:
# 142 "data/maps/FallarborTown/scripts.pory"
	face_up
# 143 "data/maps/FallarborTown/scripts.pory"
	face_left
# 144 "data/maps/FallarborTown/scripts.pory"
	face_down
# 145 "data/maps/FallarborTown/scripts.pory"
	face_right
# 146 "data/maps/FallarborTown/scripts.pory"
	face_up
# 147 "data/maps/FallarborTown/scripts.pory"
	face_left
# 148 "data/maps/FallarborTown/scripts.pory"
	face_down
# 149 "data/maps/FallarborTown/scripts.pory"
	face_right
# 150 "data/maps/FallarborTown/scripts.pory"
	face_player
	step_end

FightOthers::
# 153 "data/maps/FallarborTown/scripts.pory"
	.string "You must not forget our fight. There\n"
	.string "are many other Trainers.\p"
	.string "Strong Trainers, too.\n"
	.string "I know lots in Hoenn and Sinnoh.\p"
	.string "You must become stronger, one at a time.$"

YoureStrong::
# 161 "data/maps/FallarborTown/scripts.pory"
	.string "I know why I have lost! Your power is\n"
	.string "admirable!\p"
	.string "I would give you a Gym Badge if we were\n"
	.string "in Sinnoh but I have alternative.\p"
	.string "I shall honor it with my favorite\n"
	.string "Technical Machine, Shadow Ball!\p$"

MaybeIWasMistaken::
# 170 "data/maps/FallarborTown/scripts.pory"
	.string "Oops! I may have been mistaken then.\n"
	.string "You might be coordinator or something\l"
	.string "like that.\p"
	.string "désolée!$"

LetsStart::
# 177 "data/maps/FallarborTown/scripts.pory"
	.string "So you challenge me then. I am a Gym\n"
	.string "Leader non? So, I shall win!$"

FantinaIntro::
# 182 "data/maps/FallarborTown/scripts.pory"
	.string "Salut trainer! You may be wondering who\n"
	.string "am I.\p"
	.string "Well, I am Fantina. I have came to be Gym\n"
	.string "Leader in Sinnoh and I even do some\l"
	.string "contests there.\p"
	.string "I have been traveling here with mon\n"
	.string "cher, Mismagius. Mostly because I\l"
	.string "always want to see new things!\p"
	.string "I can tell you are trainer so\n"
	.string "do you want to challenge yours truly?$"

MismagiusCry::
# 195 "data/maps/FallarborTown/scripts.pory"
	.string "Mismagius: Wuuuawaee$"

FantinaLose::
# 199 "data/maps/FallarborTown/scripts.pory"
	.string "Very impressive! You, your Pokémon, so\n"
	.string "strong!$"
