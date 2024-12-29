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
	playfanfare MUS_HG_OBTAIN_EGG
# 247 "data/maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 248 "data/maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 249 "data/maps/LavaridgeTown/scripts.pory"
	random 27
# 250 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 1, CharmanderEgg
# 251 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 2, SquirtleEgg
# 252 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 3, ChikoritaEgg
# 253 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 4, ChikoritaEgg
# 254 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 5, CyndaquilEgg
# 255 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 6, TotodileEgg
# 256 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 7, TreeckoEgg
# 257 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 8, TorchicEgg
# 258 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 9, MudkipEgg
# 259 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 10, TurtwigEgg
# 260 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 11, ChimcharEgg
# 261 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 12, PiplupEgg
# 262 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 13, SnivyEgg
# 263 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 14, TepigEgg
# 264 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 15, OshawottEgg
# 265 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 16, ChespinEgg
# 266 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 17, FroakieEgg
# 267 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 18, FennekinEgg
# 268 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 19, RowletEgg
# 269 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 20, LittenEgg
# 270 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 21, PopplioEgg
# 271 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 22, GrookeyEgg
# 272 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 23, ScorbunnyEgg
# 273 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 24, SobbleEgg
# 274 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 25, SprigatitoEgg
# 275 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 26, FuecocoEgg
# 276 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, 27, QuaxlyEgg
# 277 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_BULBASAUR
# 278 "data/maps/LavaridgeTown/scripts.pory"
	release
# 279 "data/maps/LavaridgeTown/scripts.pory"
	end
# 280 "data/maps/LavaridgeTown/scripts.pory"

# 281 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg::
# 282 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 283 "data/maps/LavaridgeTown/scripts.pory"
	release
# 284 "data/maps/LavaridgeTown/scripts.pory"
	end
# 285 "data/maps/LavaridgeTown/scripts.pory"

# 286 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg::
# 287 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 288 "data/maps/LavaridgeTown/scripts.pory"
	release
# 289 "data/maps/LavaridgeTown/scripts.pory"
	end
# 290 "data/maps/LavaridgeTown/scripts.pory"

# 291 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg::
# 292 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 293 "data/maps/LavaridgeTown/scripts.pory"
	release
# 294 "data/maps/LavaridgeTown/scripts.pory"
	end
# 295 "data/maps/LavaridgeTown/scripts.pory"

# 296 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign::
# 297 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 298 "data/maps/LavaridgeTown/scripts.pory"
	end
# 299 "data/maps/LavaridgeTown/scripts.pory"

# 300 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign::
# 301 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 302 "data/maps/LavaridgeTown/scripts.pory"
	end
# 303 "data/maps/LavaridgeTown/scripts.pory"

# 304 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign::
# 305 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 306 "data/maps/LavaridgeTown/scripts.pory"
	end
# 307 "data/maps/LavaridgeTown/scripts.pory"

# 308 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis:
# 309 "data/maps/LavaridgeTown/scripts.pory"
	.string "May: {PLAYER}{KUN}! Long time no see!\p"
# 310 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 311 "data/maps/LavaridgeTown/scripts.pory"
	.string "you got the Lavaridge Gym Badge.\p"
# 312 "data/maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 313 "data/maps/LavaridgeTown/scripts.pory"
	.string "good Pokémon…\l"
# 314 "data/maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 315 "data/maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 316 "data/maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 317 "data/maps/LavaridgeTown/scripts.pory"

# 318 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
# 319 "data/maps/LavaridgeTown/scripts.pory"
	.string "May: With those Go-Goggles, you'll\n"
# 320 "data/maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 321 "data/maps/LavaridgeTown/scripts.pory"
	.string "desert near Route 111.\p"
# 322 "data/maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 323 "data/maps/LavaridgeTown/scripts.pory"
	.string "Challenging Gyms…\p"
# 324 "data/maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 325 "data/maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 326 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 327 "data/maps/LavaridgeTown/scripts.pory"
	.string "your dad in Petalburg Gym.\p"
# 328 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you again!$"
# 329 "data/maps/LavaridgeTown/scripts.pory"

# 330 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
# 331 "data/maps/LavaridgeTown/scripts.pory"
	.string "Brendan: {PLAYER}, hey, it's been a while.\n"
# 332 "data/maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 333 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 334 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of Badges.\p"
# 335 "data/maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 336 "data/maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 337 "data/maps/LavaridgeTown/scripts.pory"

# 338 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
# 339 "data/maps/LavaridgeTown/scripts.pory"
	.string "Brendan: Keep those with you if you're\n"
# 340 "data/maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 341 "data/maps/LavaridgeTown/scripts.pory"
	.string "Route 111.\p"
# 342 "data/maps/LavaridgeTown/scripts.pory"
	.string "There should be some Pokémon that\n"
# 343 "data/maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 344 "data/maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 345 "data/maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 346 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging Norman,\l"
# 347 "data/maps/LavaridgeTown/scripts.pory"
	.string "the Gym Leader of Petalburg.\p"
# 348 "data/maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 349 "data/maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 350 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you around!$"
# 351 "data/maps/LavaridgeTown/scripts.pory"

# 352 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt:
# 353 "data/maps/LavaridgeTown/scripts.pory"
	.string "I have here an Egg.\p"
# 354 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 355 "data/maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 356 "data/maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 357 "data/maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 358 "data/maps/LavaridgeTown/scripts.pory"
	.string "kept together with Pokémon and\l"
# 359 "data/maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 360 "data/maps/LavaridgeTown/scripts.pory"
	.string "You are a Trainer, yes?\n"
# 361 "data/maps/LavaridgeTown/scripts.pory"
	.string "And your Pokémon radiate vitality.\p"
# 362 "data/maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 363 "data/maps/LavaridgeTown/scripts.pory"
	.string "Will you take this Egg to hatch?$"
# 364 "data/maps/LavaridgeTown/scripts.pory"

# 365 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
# 366 "data/maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 367 "data/maps/LavaridgeTown/scripts.pory"
	.string "this here Egg!$"
# 368 "data/maps/LavaridgeTown/scripts.pory"

# 369 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg:
# 370 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the Egg.$"
# 371 "data/maps/LavaridgeTown/scripts.pory"

# 372 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg:
# 373 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many Pokémon.\n"
# 374 "data/maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this Egg…$"
# 375 "data/maps/LavaridgeTown/scripts.pory"

# 376 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen:
# 377 "data/maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 378 "data/maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 379 "data/maps/LavaridgeTown/scripts.pory"
	.string "hatching this Egg, I will be here.$"
# 380 "data/maps/LavaridgeTown/scripts.pory"

# 381 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
# 382 "data/maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an Egg will be found at\n"
# 383 "data/maps/LavaridgeTown/scripts.pory"
	.string "the Pokémon Day Care.\p"
# 384 "data/maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 385 "data/maps/LavaridgeTown/scripts.pory"

# 386 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry:
# 387 "data/maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 388 "data/maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 389 "data/maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?\p"
# 390 "data/maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 391 "data/maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 392 "data/maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by magma to well up\l"
# 393 "data/maps/LavaridgeTown/scripts.pory"
	.string "as hot springs.$"
# 394 "data/maps/LavaridgeTown/scripts.pory"

# 395 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside:
# 396 "data/maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 397 "data/maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 398 "data/maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 399 "data/maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 400 "data/maps/LavaridgeTown/scripts.pory"
	.string "A Pokémon nipped my backside!$"
# 401 "data/maps/LavaridgeTown/scripts.pory"

# 402 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings:
# 403 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 404 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 405 "data/maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 406 "data/maps/LavaridgeTown/scripts.pory"

# 407 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay:
# 408 "data/maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 409 "data/maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 410 "data/maps/LavaridgeTown/scripts.pory"
	.string "Gym Leader like Flannery.$"
# 411 "data/maps/LavaridgeTown/scripts.pory"

# 412 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings:
# 413 "data/maps/LavaridgeTown/scripts.pory"
	.string "If people put Pokémon in hot springs,\n"
# 414 "data/maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 415 "data/maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 416 "data/maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 417 "data/maps/LavaridgeTown/scripts.pory"

# 418 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims:
# 419 "data/maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 420 "data/maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 421 "data/maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 422 "data/maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 423 "data/maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 424 "data/maps/LavaridgeTown/scripts.pory"

# 425 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign:
# 426 "data/maps/LavaridgeTown/scripts.pory"
	.string "Lavaridge Town\p"
# 427 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Pokémon Center Hot Springs\n"
# 428 "data/maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 429 "data/maps/LavaridgeTown/scripts.pory"

# 430 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign:
# 431 "data/maps/LavaridgeTown/scripts.pory"
	.string "Lavaridge Town Pokémon Gym\n"
# 432 "data/maps/LavaridgeTown/scripts.pory"
	.string "Leader: Flannery\l"
# 433 "data/maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 434 "data/maps/LavaridgeTown/scripts.pory"

# 435 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign:
# 436 "data/maps/LavaridgeTown/scripts.pory"
	.string "Pokémon Herb Shop\n"
# 437 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"

CharmanderEgg::
# 443 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_CHARMANDER
# 444 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


SquirtleEgg::
# 449 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_SQUIRTLE
# 450 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


ChikoritaEgg::
# 455 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_CHIKORITA
# 456 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


CyndaquilEgg::
# 461 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_CYNDAQUIL
# 462 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


TotodileEgg::
# 467 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_TOTODILE
# 468 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


TreeckoEgg::
# 473 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_TREECKO
# 474 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


TorchicEgg::
# 479 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_TORCHIC
# 480 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


MudkipEgg::
# 485 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_MUDKIP
# 486 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


TurtwigEgg::
# 491 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_TURTWIG
# 492 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


ChimcharEgg::
# 497 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_CHIMCHAR
# 498 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


PiplupEgg::
# 503 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_PIPLUP
# 504 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


SnivyEgg::
# 509 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_SNIVY
# 510 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


TepigEgg::
# 515 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_TEPIG
# 516 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


OshawottEgg::
# 521 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_OSHAWOTT
# 522 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


FroakieEgg::
# 527 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_FROAKIE
# 528 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


FennekinEgg::
# 533 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_FENNEKIN
# 534 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


ChespinEgg::
# 539 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_CHESPIN
# 540 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


RowletEgg::
# 545 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_ROWLET
# 546 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


LittenEgg::
# 551 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_LITTEN
# 552 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


PopplioEgg::
# 557 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_POPPLIO
# 558 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


GrookeyEgg::
# 563 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_GROOKEY
# 564 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


ScorbunnyEgg::
# 569 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_SCORBUNNY
# 570 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


SobbleEgg::
# 575 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_SOBBLE
# 576 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


SprigatitoEgg::
# 581 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_SPRIGATITO
# 582 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


FuecocoEgg::
# 587 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_FUECOCO
# 588 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


QuaxlyEgg::
# 593 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_QUAXLY
# 594 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


AbraTeleport::
# 599 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 600 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 601 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_unset FLAG_TELEPORTER, GiveTeleport
# 602 "data/maps/LavaridgeTown/scripts.pory"
	waitse
# 603 "data/maps/LavaridgeTown/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 604 "data/maps/LavaridgeTown/scripts.pory"
	msgbox AbraMain
# 605 "data/maps/LavaridgeTown/scripts.pory"
	waitmoncry
# 606 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


GiveTeleport::
# 611 "data/maps/LavaridgeTown/scripts.pory"
	waitse
# 612 "data/maps/LavaridgeTown/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ROAR_1
# 613 "data/maps/LavaridgeTown/scripts.pory"
	msgbox WoaLook
# 614 "data/maps/LavaridgeTown/scripts.pory"
	waitmoncry
# 615 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_TELEPORT_TOOL
# 616 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_TELEPORTER
# 617 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


JaydenExitGym1::
# 631 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 632 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 5, 15
# 633 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_JAYDEN_LAVARIDGE
# 634 "data/maps/LavaridgeTown/scripts.pory"
	addobject 11
# 635 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_SLIDING_DOOR
# 636 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 5, 15
# 637 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenMoveDownThenNotice
# 638 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 639 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 5, 15
# 640 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 641 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 642 "data/maps/LavaridgeTown/scripts.pory"
	waitse
# 643 "data/maps/LavaridgeTown/scripts.pory"
	delay 60
# 644 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenApproach1
# 645 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 646 "data/maps/LavaridgeTown/scripts.pory"
	goto JaydenBattleAgain
	return


JaydenExitGym2::
# 650 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 651 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 5, 15
# 652 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_JAYDEN_LAVARIDGE
# 653 "data/maps/LavaridgeTown/scripts.pory"
	addobject 11
# 654 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_SLIDING_DOOR
# 655 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenMoveDownThenNotice
# 656 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 657 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 5, 15
# 658 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 659 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 660 "data/maps/LavaridgeTown/scripts.pory"
	waitse
# 661 "data/maps/LavaridgeTown/scripts.pory"
	delay 60
# 662 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenApproach2
# 663 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 664 "data/maps/LavaridgeTown/scripts.pory"
	goto JaydenBattleAgain
	return


JaydenExitGym3::
# 668 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 669 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 5, 15
# 670 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_JAYDEN_LAVARIDGE
# 671 "data/maps/LavaridgeTown/scripts.pory"
	addobject 11
# 672 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_SLIDING_DOOR
# 673 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenMoveDownThenNotice2
# 674 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 675 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 676 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 5, 15
# 677 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 678 "data/maps/LavaridgeTown/scripts.pory"
	waitse
# 679 "data/maps/LavaridgeTown/scripts.pory"
	delay 60
# 680 "data/maps/LavaridgeTown/scripts.pory"
	applymovement 11, JaydenApproach3
# 681 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 682 "data/maps/LavaridgeTown/scripts.pory"
	goto JaydenBattleAgain
	return


JaydenBattleAgain::
# 686 "data/maps/LavaridgeTown/scripts.pory"
	msgbox JaydenHeya
# 687 "data/maps/LavaridgeTown/scripts.pory"
	trainerbattle_no_intro TRAINER_JAYDEN_3, Jayden3Lose
# 688 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_JAYDEN_LAVARIDGE
# 689 "data/maps/LavaridgeTown/scripts.pory"
	setvar VAR_JAYDEN_LAVARIDGE, 1
# 690 "data/maps/LavaridgeTown/scripts.pory"
	msgbox MegaRing
# 691 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_MEGA_RING
# 692 "data/maps/LavaridgeTown/scripts.pory"
	msgbox FindAMegaStone
# 693 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


JaydenBroke::
# 698 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 699 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 700 "data/maps/LavaridgeTown/scripts.pory"
	msgbox YoureLucky
# 701 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


# 744 "data/maps/LavaridgeTown/scripts.pory"
JaydenApproach1:
# 745 "data/maps/LavaridgeTown/scripts.pory"
	walk_right
	step_end

# 748 "data/maps/LavaridgeTown/scripts.pory"
JaydenApproach2:
# 749 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 750 "data/maps/LavaridgeTown/scripts.pory"
	walk_right
	step_end

# 753 "data/maps/LavaridgeTown/scripts.pory"
JaydenApproach3:
# 754 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 754 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 755 "data/maps/LavaridgeTown/scripts.pory"
	walk_right
	step_end

# 758 "data/maps/LavaridgeTown/scripts.pory"
JaydenMoveDownThenNotice:
# 759 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 760 "data/maps/LavaridgeTown/scripts.pory"
	delay_8
# 761 "data/maps/LavaridgeTown/scripts.pory"
	face_right
# 762 "data/maps/LavaridgeTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 765 "data/maps/LavaridgeTown/scripts.pory"
JaydenMoveDownThenNotice2:
# 766 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 767 "data/maps/LavaridgeTown/scripts.pory"
	delay_8
# 768 "data/maps/LavaridgeTown/scripts.pory"
	emote_exclamation_mark
	step_end

AbraMain::
# 621 "data/maps/LavaridgeTown/scripts.pory"
	.string "Abra: Heeehhe$"

WoaLook::
# 625 "data/maps/LavaridgeTown/scripts.pory"
	.string "Abra: Heeehhe\n"
	.string "Woah, what is that next to it?$"

YoureLucky::
# 705 "data/maps/LavaridgeTown/scripts.pory"
	.string "Heh, you're lucky I wasn't able to\n"
	.string "afford that Charizard Mega Stone.\p"
	.string "But the next time we battle, you should\n"
	.string "expect to see me use a Mega.$"

FindAMegaStone::
# 712 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh and don't worry, a lot of shops will\n"
	.string "start having Mega Stones, like this one.$"

MegaRing::
# 717 "data/maps/LavaridgeTown/scripts.pory"
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
# 730 "data/maps/LavaridgeTown/scripts.pory"
	.string "I lost again, even though I have more\n"
	.string "badges...$"

JaydenHeya::
# 735 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh hey {PLAYER}, it's been a while.\n"
	.string "What have you been doing lately?\p"
	.string "For me I've literally just beaten the\n"
	.string "Gym here.\p"
	.string "I want to see if you're prepared\n"
	.string "because she's tough so let's do this!$"
