# 1 "data/maps/LavaridgeTown/scripts.pory"

# 2 "data/maps/LavaridgeTown/scripts.pory"
.set LOCALID_RIVAL_ON_BIKE, 7
# 3 "data/maps/LavaridgeTown/scripts.pory"
.set LOCALID_RIVAL, 8
# 4 "data/maps/LavaridgeTown/scripts.pory"

# 5 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_MapScripts::
# 6 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
# 7 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
# 8 "data/maps/LavaridgeTown/scripts.pory"
	.byte 0
# 9 "data/maps/LavaridgeTown/scripts.pory"

# 10 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnTransition:
# 11 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_VISITED_LAVARIDGE_TOWN
# 12 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
# 13 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
# 14 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 15 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 16 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
# 17 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
# 18 "data/maps/LavaridgeTown/scripts.pory"
	end
# 19 "data/maps/LavaridgeTown/scripts.pory"

# 20 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
# 21 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
# 22 "data/maps/LavaridgeTown/scripts.pory"
	return
# 23 "data/maps/LavaridgeTown/scripts.pory"

# 24 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CheckSetRivalPos::
# 25 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 26 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
# 27 "data/maps/LavaridgeTown/scripts.pory"
	return
# 28 "data/maps/LavaridgeTown/scripts.pory"

# 29 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetRivalPos::
# 30 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 11, 9
# 31 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
# 32 "data/maps/LavaridgeTown/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
# 33 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
# 34 "data/maps/LavaridgeTown/scripts.pory"
	return
# 35 "data/maps/LavaridgeTown/scripts.pory"

# 36 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ShowMtChimneyTrainers::
# 37 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
# 38 "data/maps/LavaridgeTown/scripts.pory"
	return
# 39 "data/maps/LavaridgeTown/scripts.pory"

# 40 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HideMapNamePopup::
# 41 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 42 "data/maps/LavaridgeTown/scripts.pory"
	return
# 43 "data/maps/LavaridgeTown/scripts.pory"

# 44 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnFrame:
# 45 "data/maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
# 46 "data/maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 47 "data/maps/LavaridgeTown/scripts.pory"

# 48 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalGiveGoGoggles::
# 49 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 50 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 51 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
# 52 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
# 53 "data/maps/LavaridgeTown/scripts.pory"
	delay 20
# 54 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 55 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
# 56 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
# 57 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
# 58 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
# 59 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 60 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
# 61 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
# 62 "data/maps/LavaridgeTown/scripts.pory"
	end
# 63 "data/maps/LavaridgeTown/scripts.pory"

# 64 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_MayGiveGoGoggles::
# 65 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
# 66 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 67 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 68 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 69 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 70 "data/maps/LavaridgeTown/scripts.pory"
	end
# 71 "data/maps/LavaridgeTown/scripts.pory"

# 72 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_BrendanGiveGoGoggles::
# 73 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
# 74 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 75 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 76 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 77 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 78 "data/maps/LavaridgeTown/scripts.pory"
	end
# 79 "data/maps/LavaridgeTown/scripts.pory"

# 80 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit::
# 81 "data/maps/LavaridgeTown/scripts.pory"
	closemessage
# 82 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_RIVAL
# 83 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 84 "data/maps/LavaridgeTown/scripts.pory"
	delay 30
# 85 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
# 86 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
# 87 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 88 "data/maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
# 89 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 90 "data/maps/LavaridgeTown/scripts.pory"
	savebgm MUS_DUMMY
# 91 "data/maps/LavaridgeTown/scripts.pory"
	fadedefaultbgm
# 92 "data/maps/LavaridgeTown/scripts.pory"
	releaseall
# 93 "data/maps/LavaridgeTown/scripts.pory"
	end
# 94 "data/maps/LavaridgeTown/scripts.pory"

# 95 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayMayMusic::
# 96 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 97 "data/maps/LavaridgeTown/scripts.pory"
	return
# 98 "data/maps/LavaridgeTown/scripts.pory"

# 99 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayBrendanMusic::
# 100 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 101 "data/maps/LavaridgeTown/scripts.pory"
	return
# 102 "data/maps/LavaridgeTown/scripts.pory"

# 103 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalNoticePlayer::
# 104 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 105 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 106 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 107 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 108 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 109 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 110 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 111 "data/maps/LavaridgeTown/scripts.pory"
	return
# 112 "data/maps/LavaridgeTown/scripts.pory"

# 113 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExitHerbShop::
# 114 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 12, 15
# 115 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 116 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_RIVAL
# 117 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
# 118 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 119 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 12, 15
# 120 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 121 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
# 122 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 123 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 124 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 125 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 126 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 127 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 128 "data/maps/LavaridgeTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 129 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 130 "data/maps/LavaridgeTown/scripts.pory"
	return
# 131 "data/maps/LavaridgeTown/scripts.pory"

# 132 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer1::
# 133 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
# 134 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 135 "data/maps/LavaridgeTown/scripts.pory"
	return
# 136 "data/maps/LavaridgeTown/scripts.pory"

# 137 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer2::
# 138 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
# 139 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 140 "data/maps/LavaridgeTown/scripts.pory"
	return
# 141 "data/maps/LavaridgeTown/scripts.pory"

# 142 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit1::
# 143 "data/maps/LavaridgeTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
# 144 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
# 145 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 146 "data/maps/LavaridgeTown/scripts.pory"
	return
# 147 "data/maps/LavaridgeTown/scripts.pory"

# 148 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit2::
# 149 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
# 150 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 151 "data/maps/LavaridgeTown/scripts.pory"
	return
# 152 "data/maps/LavaridgeTown/scripts.pory"

# 153 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit2:
# 154 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 155 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 156 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 157 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 158 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 159 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 160 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 161 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 162 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 163 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 164 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 165 "data/maps/LavaridgeTown/scripts.pory"

# 166 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_PlayerWatchRivalExit:
# 167 "data/maps/LavaridgeTown/scripts.pory"
	delay_16
# 168 "data/maps/LavaridgeTown/scripts.pory"
	delay_8
# 169 "data/maps/LavaridgeTown/scripts.pory"
	walk_in_place_faster_right
# 170 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 171 "data/maps/LavaridgeTown/scripts.pory"

# 172 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit1:
# 173 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_down
# 174 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 175 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 176 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 177 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 178 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 179 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 180 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 181 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 182 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 183 "data/maps/LavaridgeTown/scripts.pory"

# 184 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer2:
# 185 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 186 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 187 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 188 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 189 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 190 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 191 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 192 "data/maps/LavaridgeTown/scripts.pory"

# 193 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer1:
# 194 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 195 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 196 "data/maps/LavaridgeTown/scripts.pory"
	walk_up
# 197 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 198 "data/maps/LavaridgeTown/scripts.pory"

# 199 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExitHerbShop:
# 200 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 201 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 202 "data/maps/LavaridgeTown/scripts.pory"

# 203 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsTrigger::
# 204 "data/maps/LavaridgeTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 205 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
# 206 "data/maps/LavaridgeTown/scripts.pory"
	end
# 207 "data/maps/LavaridgeTown/scripts.pory"

# 208 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EnteredHotSprings::
# 209 "data/maps/LavaridgeTown/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
# 210 "data/maps/LavaridgeTown/scripts.pory"
	end
# 211 "data/maps/LavaridgeTown/scripts.pory"

# 212 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertM::
# 213 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
# 214 "data/maps/LavaridgeTown/scripts.pory"
	end
# 215 "data/maps/LavaridgeTown/scripts.pory"

# 216 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_OldMan::
# 217 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
# 218 "data/maps/LavaridgeTown/scripts.pory"
	end
# 219 "data/maps/LavaridgeTown/scripts.pory"

# 220 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_Twin::
# 221 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
# 222 "data/maps/LavaridgeTown/scripts.pory"
	end
# 223 "data/maps/LavaridgeTown/scripts.pory"

# 224 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman1::
# 225 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
# 226 "data/maps/LavaridgeTown/scripts.pory"
	end
# 227 "data/maps/LavaridgeTown/scripts.pory"

# 228 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman2::
# 229 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
# 230 "data/maps/LavaridgeTown/scripts.pory"
	end
# 231 "data/maps/LavaridgeTown/scripts.pory"

# 232 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertF::
# 233 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
# 234 "data/maps/LavaridgeTown/scripts.pory"
	end
# 235 "data/maps/LavaridgeTown/scripts.pory"

# 236 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EggWoman::
# 237 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 238 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 239 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
# 240 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 241 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
# 242 "data/maps/LavaridgeTown/scripts.pory"
	getpartysize
# 243 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
# 244 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
# 245 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
# 246 "data/maps/LavaridgeTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 247 "data/maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 248 "data/maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 249 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_WYNAUT
# 250 "data/maps/LavaridgeTown/scripts.pory"
	release
# 251 "data/maps/LavaridgeTown/scripts.pory"
	end
# 252 "data/maps/LavaridgeTown/scripts.pory"

# 253 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg::
# 254 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 255 "data/maps/LavaridgeTown/scripts.pory"
	release
# 256 "data/maps/LavaridgeTown/scripts.pory"
	end
# 257 "data/maps/LavaridgeTown/scripts.pory"

# 258 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg::
# 259 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 260 "data/maps/LavaridgeTown/scripts.pory"
	release
# 261 "data/maps/LavaridgeTown/scripts.pory"
	end
# 262 "data/maps/LavaridgeTown/scripts.pory"

# 263 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg::
# 264 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 265 "data/maps/LavaridgeTown/scripts.pory"
	release
# 266 "data/maps/LavaridgeTown/scripts.pory"
	end
# 267 "data/maps/LavaridgeTown/scripts.pory"

# 268 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign::
# 269 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 270 "data/maps/LavaridgeTown/scripts.pory"
	end
# 271 "data/maps/LavaridgeTown/scripts.pory"

# 272 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign::
# 273 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 274 "data/maps/LavaridgeTown/scripts.pory"
	end
# 275 "data/maps/LavaridgeTown/scripts.pory"

# 276 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign::
# 277 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 278 "data/maps/LavaridgeTown/scripts.pory"
	end
# 279 "data/maps/LavaridgeTown/scripts.pory"

# 280 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis:
# 281 "data/maps/LavaridgeTown/scripts.pory"
	.string "May: {PLAYER}{KUN}! Long time no see!\p"
# 282 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 283 "data/maps/LavaridgeTown/scripts.pory"
	.string "you got the Lavaridge Gym Badge.\p"
# 284 "data/maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 285 "data/maps/LavaridgeTown/scripts.pory"
	.string "good Pokémon…\l"
# 286 "data/maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 287 "data/maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 288 "data/maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 289 "data/maps/LavaridgeTown/scripts.pory"

# 290 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
# 291 "data/maps/LavaridgeTown/scripts.pory"
	.string "May: With those Go-Goggles, you'll\n"
# 292 "data/maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 293 "data/maps/LavaridgeTown/scripts.pory"
	.string "desert near Route 111.\p"
# 294 "data/maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 295 "data/maps/LavaridgeTown/scripts.pory"
	.string "Challenging Gyms…\p"
# 296 "data/maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 297 "data/maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 298 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 299 "data/maps/LavaridgeTown/scripts.pory"
	.string "your dad in Petalburg Gym.\p"
# 300 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you again!$"
# 301 "data/maps/LavaridgeTown/scripts.pory"

# 302 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
# 303 "data/maps/LavaridgeTown/scripts.pory"
	.string "Brendan: {PLAYER}, hey, it's been a while.\n"
# 304 "data/maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 305 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 306 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of Badges.\p"
# 307 "data/maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 308 "data/maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 309 "data/maps/LavaridgeTown/scripts.pory"

# 310 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
# 311 "data/maps/LavaridgeTown/scripts.pory"
	.string "Brendan: Keep those with you if you're\n"
# 312 "data/maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 313 "data/maps/LavaridgeTown/scripts.pory"
	.string "Route 111.\p"
# 314 "data/maps/LavaridgeTown/scripts.pory"
	.string "There should be some Pokémon that\n"
# 315 "data/maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 316 "data/maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 317 "data/maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 318 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging Norman,\l"
# 319 "data/maps/LavaridgeTown/scripts.pory"
	.string "the Gym Leader of Petalburg.\p"
# 320 "data/maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 321 "data/maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 322 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you around!$"
# 323 "data/maps/LavaridgeTown/scripts.pory"

# 324 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt:
# 325 "data/maps/LavaridgeTown/scripts.pory"
	.string "I have here an Egg.\p"
# 326 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 327 "data/maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 328 "data/maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 329 "data/maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 330 "data/maps/LavaridgeTown/scripts.pory"
	.string "kept together with Pokémon and\l"
# 331 "data/maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 332 "data/maps/LavaridgeTown/scripts.pory"
	.string "You are a Trainer, yes?\n"
# 333 "data/maps/LavaridgeTown/scripts.pory"
	.string "And your Pokémon radiate vitality.\p"
# 334 "data/maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 335 "data/maps/LavaridgeTown/scripts.pory"
	.string "Will you take this Egg to hatch?$"
# 336 "data/maps/LavaridgeTown/scripts.pory"

# 337 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
# 338 "data/maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 339 "data/maps/LavaridgeTown/scripts.pory"
	.string "this here Egg!$"
# 340 "data/maps/LavaridgeTown/scripts.pory"

# 341 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg:
# 342 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the Egg.$"
# 343 "data/maps/LavaridgeTown/scripts.pory"

# 344 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg:
# 345 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many Pokémon.\n"
# 346 "data/maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this Egg…$"
# 347 "data/maps/LavaridgeTown/scripts.pory"

# 348 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen:
# 349 "data/maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 350 "data/maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 351 "data/maps/LavaridgeTown/scripts.pory"
	.string "hatching this Egg, I will be here.$"
# 352 "data/maps/LavaridgeTown/scripts.pory"

# 353 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
# 354 "data/maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an Egg will be found at\n"
# 355 "data/maps/LavaridgeTown/scripts.pory"
	.string "the Pokémon Day Care.\p"
# 356 "data/maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 357 "data/maps/LavaridgeTown/scripts.pory"

# 358 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry:
# 359 "data/maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 360 "data/maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 361 "data/maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?\p"
# 362 "data/maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 363 "data/maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 364 "data/maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by magma to well up\l"
# 365 "data/maps/LavaridgeTown/scripts.pory"
	.string "as hot springs.$"
# 366 "data/maps/LavaridgeTown/scripts.pory"

# 367 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside:
# 368 "data/maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 369 "data/maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 370 "data/maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 371 "data/maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 372 "data/maps/LavaridgeTown/scripts.pory"
	.string "A Pokémon nipped my backside!$"
# 373 "data/maps/LavaridgeTown/scripts.pory"

# 374 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings:
# 375 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 376 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 377 "data/maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 378 "data/maps/LavaridgeTown/scripts.pory"

# 379 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay:
# 380 "data/maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 381 "data/maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 382 "data/maps/LavaridgeTown/scripts.pory"
	.string "Gym Leader like Flannery.$"
# 383 "data/maps/LavaridgeTown/scripts.pory"

# 384 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings:
# 385 "data/maps/LavaridgeTown/scripts.pory"
	.string "If people put Pokémon in hot springs,\n"
# 386 "data/maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 387 "data/maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 388 "data/maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 389 "data/maps/LavaridgeTown/scripts.pory"

# 390 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims:
# 391 "data/maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 392 "data/maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 393 "data/maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 394 "data/maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 395 "data/maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 396 "data/maps/LavaridgeTown/scripts.pory"

# 397 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign:
# 398 "data/maps/LavaridgeTown/scripts.pory"
	.string "Lavaridge Town\p"
# 399 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Pokémon Center Hot Springs\n"
# 400 "data/maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 401 "data/maps/LavaridgeTown/scripts.pory"

# 402 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign:
# 403 "data/maps/LavaridgeTown/scripts.pory"
	.string "Lavaridge Town Pokémon Gym\n"
# 404 "data/maps/LavaridgeTown/scripts.pory"
	.string "Leader: Flannery\l"
# 405 "data/maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 406 "data/maps/LavaridgeTown/scripts.pory"

# 407 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign:
# 408 "data/maps/LavaridgeTown/scripts.pory"
	.string "Pokémon Herb Shop\n"
# 409 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"

AbraTeleport::
# 415 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 416 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 417 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_unset FLAG_TELEPORTER, GiveTeleport
# 418 "data/maps/LavaridgeTown/scripts.pory"
	waitse
# 419 "data/maps/LavaridgeTown/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 420 "data/maps/LavaridgeTown/scripts.pory"
	msgbox AbraMain
# 421 "data/maps/LavaridgeTown/scripts.pory"
	waitmoncry
# 422 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


GiveTeleport::
# 427 "data/maps/LavaridgeTown/scripts.pory"
	waitse
# 428 "data/maps/LavaridgeTown/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ROAR_1
# 429 "data/maps/LavaridgeTown/scripts.pory"
	msgbox WoaLook
# 430 "data/maps/LavaridgeTown/scripts.pory"
	waitmoncry
# 431 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_TELEPORT_TOOL
# 432 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_TELEPORTER
# 433 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


JaydenExitGym1::
# 447 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 448 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 5, 15
# 449 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_JAYDEN_LAVARIDGE
# 450 "data/maps/LavaridgeTown/scripts.pory"
	addobject 11
# 451 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_SLIDING_DOOR
# 452 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 5, 15
# 453 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenMoveDownThenNotice
# 454 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 455 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 5, 15
# 456 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 457 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 458 "data/maps/LavaridgeTown/scripts.pory"
	waitse
# 459 "data/maps/LavaridgeTown/scripts.pory"
	delay 60
# 460 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenApproach1
# 461 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 462 "data/maps/LavaridgeTown/scripts.pory"
	goto JaydenBattleAgain
	return


JaydenExitGym2::
# 466 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 467 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 5, 15
# 468 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_JAYDEN_LAVARIDGE
# 469 "data/maps/LavaridgeTown/scripts.pory"
	addobject 11
# 470 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_SLIDING_DOOR
# 471 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenMoveDownThenNotice
# 472 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 473 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 5, 15
# 474 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 475 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 476 "data/maps/LavaridgeTown/scripts.pory"
	waitse
# 477 "data/maps/LavaridgeTown/scripts.pory"
	delay 60
# 478 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenApproach2
# 479 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 480 "data/maps/LavaridgeTown/scripts.pory"
	goto JaydenBattleAgain
	return


JaydenExitGym3::
# 484 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 485 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 5, 15
# 486 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_JAYDEN_LAVARIDGE
# 487 "data/maps/LavaridgeTown/scripts.pory"
	addobject 11
# 488 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_SLIDING_DOOR
# 489 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenMoveDownThenNotice2
# 490 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 491 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 492 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 5, 15
# 493 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 494 "data/maps/LavaridgeTown/scripts.pory"
	waitse
# 495 "data/maps/LavaridgeTown/scripts.pory"
	delay 60
# 496 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenApproach3
# 497 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 498 "data/maps/LavaridgeTown/scripts.pory"
	goto JaydenBattleAgain
	return


JaydenBattleAgain::
# 502 "data/maps/LavaridgeTown/scripts.pory"
	msgbox JaydenHeya
# 503 "data/maps/LavaridgeTown/scripts.pory"
	trainerbattle_no_intro TRAINER_JAYDEN_3, Jayden3Lose
# 504 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_JAYDEN_LAVARIDGE
# 505 "data/maps/LavaridgeTown/scripts.pory"
	setvar VAR_JAYDEN_LAVARIDGE, 1
# 506 "data/maps/LavaridgeTown/scripts.pory"
	msgbox MegaRing
# 507 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_MEGA_RING
# 508 "data/maps/LavaridgeTown/scripts.pory"
	msgbox FindAMegaStone
# 509 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


JaydenBroke::
# 514 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 515 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 516 "data/maps/LavaridgeTown/scripts.pory"
	msgbox YoureLucky
# 517 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


# 560 "data/maps/LavaridgeTown/scripts.pory"
JaydenApproach1:
# 561 "data/maps/LavaridgeTown/scripts.pory"
	walk_right
	step_end

# 564 "data/maps/LavaridgeTown/scripts.pory"
JaydenApproach2:
# 565 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 566 "data/maps/LavaridgeTown/scripts.pory"
	walk_right
	step_end

# 569 "data/maps/LavaridgeTown/scripts.pory"
JaydenApproach3:
# 570 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 570 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 571 "data/maps/LavaridgeTown/scripts.pory"
	walk_right
	step_end

# 574 "data/maps/LavaridgeTown/scripts.pory"
JaydenMoveDownThenNotice:
# 575 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 576 "data/maps/LavaridgeTown/scripts.pory"
	delay_8
# 577 "data/maps/LavaridgeTown/scripts.pory"
	face_right
# 578 "data/maps/LavaridgeTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 581 "data/maps/LavaridgeTown/scripts.pory"
JaydenMoveDownThenNotice2:
# 582 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 583 "data/maps/LavaridgeTown/scripts.pory"
	delay_8
# 584 "data/maps/LavaridgeTown/scripts.pory"
	emote_exclamation_mark
	step_end

AbraMain::
# 437 "data/maps/LavaridgeTown/scripts.pory"
	.string "Abra: Heeehhe$"

WoaLook::
# 441 "data/maps/LavaridgeTown/scripts.pory"
	.string "Abra: Heeehhe\n"
	.string "Woah, what is that next to it?$"

YoureLucky::
# 521 "data/maps/LavaridgeTown/scripts.pory"
	.string "Heh, you're lucky I wasn't able to\n"
	.string "afford that Charizard Mega Stone.\p"
	.string "But the next time we battle, you should\n"
	.string "expect to see me use a Mega.$"

FindAMegaStone::
# 528 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh and don't worry, a lot of shops will\n"
	.string "start having Mega Stones, like this one.$"

MegaRing::
# 533 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}, there's something I have to\n"
	.string "tell you about.\p"
	.string "So I learned about a pretty sick\n"
	.string "mechanic called Mega Evolution.\p"
	.string "It basically turns a Pokémon into a\n"
	.string "stronger form of themselves.\p"
	.string "Downside is that you need a Mega Ring\n"
	.string "and a separate Mega Stone to do it.\p"
	.string "I know you'd probably want to use this\n"
	.string "so I have a spare Mega Ring for you.$"

Jayden3Lose::
# 546 "data/maps/LavaridgeTown/scripts.pory"
	.string "I lost again, even though I have more\n"
	.string "badges...$"

JaydenHeya::
# 551 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh hey {PLAYER}, it's been a while.\n"
	.string "What have you been doing lately?\p"
	.string "For me I've literally just beaten the\n"
	.string "Gym here.\p"
	.string "I want to see if you're prepared\n"
	.string "because she's tough so let's do this!$"
