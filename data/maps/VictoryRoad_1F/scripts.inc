# 1 "data/maps/VictoryRoad_1F/scripts.pory"

# 2 "data/maps/VictoryRoad_1F/scripts.pory"
.set LOCALID_WALLY_ENTRANCE, 4
# 3 "data/maps/VictoryRoad_1F/scripts.pory"

# 4 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_MapScripts::
# 5 "data/maps/VictoryRoad_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
# 6 "data/maps/VictoryRoad_1F/scripts.pory"
	.byte 0
# 7 "data/maps/VictoryRoad_1F/scripts.pory"

# 8 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_OnTransition:
# 9 "data/maps/VictoryRoad_1F/scripts.pory"
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
# 10 "data/maps/VictoryRoad_1F/scripts.pory"
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
# 11 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 12 "data/maps/VictoryRoad_1F/scripts.pory"

# 13 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
# 14 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
# 15 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
# 16 "data/maps/VictoryRoad_1F/scripts.pory"
	return
# 17 "data/maps/VictoryRoad_1F/scripts.pory"

# 18 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
# 19 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
# 20 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
# 21 "data/maps/VictoryRoad_1F/scripts.pory"
	return
# 22 "data/maps/VictoryRoad_1F/scripts.pory"

# 23 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyBattleTrigger1::
# 24 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 25 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 26 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject LOCALID_WALLY_ENTRANCE
# 27 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
# 28 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 29 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
# 30 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 31 "data/maps/VictoryRoad_1F/scripts.pory"

# 32 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyBattleTrigger2::
# 33 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 34 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 35 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject LOCALID_WALLY_ENTRANCE
# 36 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
# 37 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 38 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
# 39 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 40 "data/maps/VictoryRoad_1F/scripts.pory"

# 41 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyEntranceBattle::
# 42 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 43 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 44 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
# 45 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
# 46 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
# 47 "data/maps/VictoryRoad_1F/scripts.pory"
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
# 48 "data/maps/VictoryRoad_1F/scripts.pory"
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
# 49 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
# 50 "data/maps/VictoryRoad_1F/scripts.pory"
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
# 51 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
# 52 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 53 "data/maps/VictoryRoad_1F/scripts.pory"

# 54 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_WallyApproachPlayer1:
# 55 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 56 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 57 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 58 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 59 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 60 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 61 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 62 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 63 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 64 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 65 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 66 "data/maps/VictoryRoad_1F/scripts.pory"
	step_end
# 67 "data/maps/VictoryRoad_1F/scripts.pory"

# 68 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_WallyApproachPlayer2:
# 69 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 70 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 71 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 72 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 73 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 74 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 75 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 76 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 77 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 78 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 79 "data/maps/VictoryRoad_1F/scripts.pory"
	step_end
# 80 "data/maps/VictoryRoad_1F/scripts.pory"

# 81 "data/maps/VictoryRoad_1F/scripts.pory"
@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
# 82 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_EntranceWally::
# 83 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
# 84 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 85 "data/maps/VictoryRoad_1F/scripts.pory"

# 86 "data/maps/VictoryRoad_1F/scripts.pory"
@ This Wally appears and remains at the exit after the Hall of Fame is entered
# 87 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_ExitWally::
# 88 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
# 89 "data/maps/VictoryRoad_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 90 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
# 91 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
# 92 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 93 "data/maps/VictoryRoad_1F/scripts.pory"

# 94 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_RematchWally::
# 95 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
# 96 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
# 97 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 98 "data/maps/VictoryRoad_1F/scripts.pory"

# 99 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Edgar::
# 100 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
# 101 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
# 102 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 103 "data/maps/VictoryRoad_1F/scripts.pory"

# 104 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Albert::
# 105 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
# 106 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
# 107 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 108 "data/maps/VictoryRoad_1F/scripts.pory"

# 109 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Hope::
# 110 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
# 111 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
# 112 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 113 "data/maps/VictoryRoad_1F/scripts.pory"

# 114 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Quincy::
# 115 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
# 116 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
# 117 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 118 "data/maps/VictoryRoad_1F/scripts.pory"

# 119 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Katelynn::
# 120 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
# 121 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
# 122 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 123 "data/maps/VictoryRoad_1F/scripts.pory"

# 124 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
# 125 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wally: Hi! {PLAYER}!\p"
# 126 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I bet you're surprised to see me here!\p"
# 127 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I made it all the way here, and it's\n"
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "all thanks to you!\p"
# 129 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, losing to you that time\n"
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "made me stronger!\p"
# 131 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "But I'm not going to lose anymore!\p"
# 132 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'm going to win! For the Pokémon who\n"
# 133 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "gave me courage and strength!\p"
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay… Here I come!$"
# 135 "data/maps/VictoryRoad_1F/scripts.pory"

# 136 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyEntranceDefeat:
# 137 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wow!\n"
# 138 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, you are strong, after all!$"
# 139 "data/maps/VictoryRoad_1F/scripts.pory"

# 140 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyPostEntranceBattle:
# 141 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wally: I couldn't beat you today,\n"
# 142 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, but one of these days, I'll\l"
# 143 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "catch up to you!$"
# 144 "data/maps/VictoryRoad_1F/scripts.pory"

# 145 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyIntro:
# 146 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wally: Hi! {PLAYER}!\p"
# 147 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I've gotten stronger since that last\n"
# 148 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "time! I wanted to show you, {PLAYER}!\p"
# 149 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay… Here I come!$"
# 150 "data/maps/VictoryRoad_1F/scripts.pory"

# 151 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyDefeat:
# 152 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wow!\n"
# 153 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, you are strong, after all!$"
# 154 "data/maps/VictoryRoad_1F/scripts.pory"

# 155 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyPostBattle:
# 156 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wally: I couldn't beat you this time,\n"
# 157 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "too… But one of these days, {PLAYER},\l"
# 158 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'm going to catch up to you…\p"
# 159 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "And challenge the Pokémon League!$"
# 160 "data/maps/VictoryRoad_1F/scripts.pory"

# 161 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarIntro:
# 162 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I've made it this far a couple times,\n"
# 163 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "but the last stretch is so long…$"
# 164 "data/maps/VictoryRoad_1F/scripts.pory"

# 165 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarDefeat:
# 166 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "My dream ends here again…$"
# 167 "data/maps/VictoryRoad_1F/scripts.pory"

# 168 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarPostBattle:
# 169 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "You've made it this far. Keep the\n"
# 170 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "momentum going and become the\l"
# 171 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Champion! If anyone can, it's you!$"
# 172 "data/maps/VictoryRoad_1F/scripts.pory"

# 173 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertIntro:
# 174 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I didn't come all this way to lose now.\n"
# 175 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That possibility doesn't exist!$"
# 176 "data/maps/VictoryRoad_1F/scripts.pory"

# 177 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertDefeat:
# 178 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Impossible…\n"
# 179 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I lost?$"
# 180 "data/maps/VictoryRoad_1F/scripts.pory"

# 181 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertPostBattle:
# 182 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I lost here…\p"
# 183 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That means I lack the qualifications\n"
# 184 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "to become the Champion…$"
# 185 "data/maps/VictoryRoad_1F/scripts.pory"

# 186 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopeIntro:
# 187 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "This seemingly infinite and harsh road\n"
# 188 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "lives up to its name of Victory.$"
# 189 "data/maps/VictoryRoad_1F/scripts.pory"

# 190 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopeDefeat:
# 191 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Your battle style is fantastic…$"
# 192 "data/maps/VictoryRoad_1F/scripts.pory"

# 193 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopePostBattle:
# 194 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "You seem to have the potential for\n"
# 195 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "becoming the Champion.$"
# 196 "data/maps/VictoryRoad_1F/scripts.pory"

# 197 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyIntro:
# 198 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "What is the Victory Road?\n"
# 199 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'll tell you if you win!$"
# 200 "data/maps/VictoryRoad_1F/scripts.pory"

# 201 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyDefeat:
# 202 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay!\n"
# 203 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Well done!$"
# 204 "data/maps/VictoryRoad_1F/scripts.pory"

# 205 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyPostBattle:
# 206 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Getting through here safely--that's\n"
# 207 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "the final test for any Trainer aiming\l"
# 208 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "to become the Pokémon Champion.\p"
# 209 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That's why it's called the Victory\n"
# 210 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Road.$"
# 211 "data/maps/VictoryRoad_1F/scripts.pory"

# 212 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnIntro:
# 213 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I have nothing to say to anyone\n"
# 214 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "that's come this far. Come on!$"
# 215 "data/maps/VictoryRoad_1F/scripts.pory"

# 216 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnDefeat:
# 217 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "This is a disgrace…$"
# 218 "data/maps/VictoryRoad_1F/scripts.pory"

# 219 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnPostBattle:
# 220 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Humph, go right on ahead.\n"
# 221 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "See if I care.$"

DawnApproachPlayer1::
# 226 "data/maps/VictoryRoad_1F/scripts.pory"
	lock
# 227 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_DP_DAWN, FALSE
# 228 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 229 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 230 "data/maps/VictoryRoad_1F/scripts.pory"
	clearflag FLAG_DAWN
# 231 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject 10
# 232 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement 10, DawnWalkUp1
# 233 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 234 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox HiThere
# 235 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_DAWN, DawnLoseText
# 236 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_FOLLOWER_WRONG_WAY, 1
# 237 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_DAWN, 1
# 238 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox LetsGo
# 239 "data/maps/VictoryRoad_1F/scripts.pory"
	setfollowernpc 10, FOLLOW_ME_FLAG_ALL_NO_FRAME, DawnChat, PARTNER_DAWN
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end


DawnApproachPlayer2::
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	lock
# 246 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_DP_DAWN, FALSE
# 247 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	clearflag FLAG_DAWN
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject 10
# 251 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement 10, DawnWalkUp2
# 252 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox HiThere
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_DAWN, DawnLoseText
# 255 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_FOLLOWER_WRONG_WAY, 1
# 256 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_DAWN, 1
# 257 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox LetsGo
# 258 "data/maps/VictoryRoad_1F/scripts.pory"
	setfollowernpc 10, FOLLOW_ME_FLAG_ALL_NO_FRAME, DawnChat, PARTNER_DAWN
# 259 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end


DawnChat::
# 264 "data/maps/VictoryRoad_1F/scripts.pory"
	lock
# 265 "data/maps/VictoryRoad_1F/scripts.pory"
	faceplayer
# 266 "data/maps/VictoryRoad_1F/scripts.pory"
	random 2
# 267 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SinnohRegion
# 268 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 2, ToughCave
# 269 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox TrynaBecomeChamp
# 270 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end


SinnohRegion::
# 275 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox SinnohFr
# 276 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end


ToughCave::
# 281 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox MightSoundWeird
# 282 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end


DawnApproachPlayer3::
# 287 "data/maps/VictoryRoad_1F/scripts.pory"
	lock
# 288 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_DP_DAWN, FALSE
# 289 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 290 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 291 "data/maps/VictoryRoad_1F/scripts.pory"
	clearflag FLAG_DAWN
# 292 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject 10
# 293 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement 10, DawnWalkUp3
# 294 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 295 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox HiThere
# 296 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_DAWN, DawnLoseText
# 297 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_FOLLOWER_WRONG_WAY, 1
# 298 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_DAWN, 1
# 299 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox LetsGo
# 300 "data/maps/VictoryRoad_1F/scripts.pory"
	setfollowernpc 10, FOLLOW_ME_FLAG_ALL_NO_FRAME, DawnChat, PARTNER_DAWN
# 301 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end


FollowerWrongWay2::
# 306 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 307 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox PlayerSenses
# 308 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
# 309 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 310 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 311 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	end


DawnLeaveParty::
# 316 "data/maps/VictoryRoad_1F/scripts.pory"
	lock
# 317 "data/maps/VictoryRoad_1F/scripts.pory"
	facefollowernpc
# 318 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox ThxImaGo
# 319 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, DawnLeave
# 320 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 321 "data/maps/VictoryRoad_1F/scripts.pory"
	destroyfollowernpc
# 322 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_DAWN
# 323 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject OBJ_EVENT_ID_NPC_FOLLOWER
# 324 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_FOLLOWER_WRONG_WAY, 0
# 325 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_DAWN_LEAVE_PARTY, 1
# 326 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end


# 330 "data/maps/VictoryRoad_1F/scripts.pory"
DawnWalkUp1:
# 331 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 331 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 331 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 331 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 331 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 332 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_right
# 332 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_right
# 332 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_right
	step_end

# 335 "data/maps/VictoryRoad_1F/scripts.pory"
DawnWalkUp2:
# 336 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 336 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 336 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 336 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 337 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_right
# 337 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_right
# 337 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_right
	step_end

# 340 "data/maps/VictoryRoad_1F/scripts.pory"
DawnWalkUp3:
# 341 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 341 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 341 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 341 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 341 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 342 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_right
# 343 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 344 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_right
# 344 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_right
	step_end

# 347 "data/maps/VictoryRoad_1F/scripts.pory"
DawnLeave:
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
	step_end

HiThere::
# 351 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Oh hi, sorry! I'm Dawn and I'm taking a\n"
	.string "little vacation here.\p"
	.string "Hey, you look pretty tough, how about\n"
	.string "we have a little battle!$"

SinnohFr::
# 358 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "You probably didn't know but I'm from\n"
	.string "Sinnoh.\p"
	.string "The contest scene is pretty big there!$"

TrynaBecomeChamp::
# 364 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "So you're trying to battle in the\n"
	.string "Pokémon League here?\p"
	.string "Dang, I just realized then that I'm in a\n"
	.string "Victory Road!$"

MightSoundWeird::
# 371 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "This might sound weird but I wish there\n"
	.string "were more populated caves in Hoenn.\p"
	.string "I only say that because the trainers\n"
	.string "here are no joke though.$"

LetsGo::
# 378 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay, let's go!$"

ThxImaGo::
# 382 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Thank you for training with me. So\n"
	.string "you're going to the Pokémon League huh?\p"
	.string "In that case, I wish you the best of\n"
	.string "luck and hopefully we'll meet again.$"

DawnLoseText::
# 389 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Woah, you're so strong, how about we\n"
	.string "both go through this cave!$"
