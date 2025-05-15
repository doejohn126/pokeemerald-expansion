# 1 "data/maps/Route114/scripts.pory"

# 2 "data/maps/Route114/scripts.pory"
Route114_MapScripts::
# 3 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_OnTransition
# 4 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route114_OnLoad
# 5 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_OnFrame
# 6 "data/maps/Route114/scripts.pory"
	.byte 0
# 7 "data/maps/Route114/scripts.pory"

# 8 "data/maps/Route114/scripts.pory"
Route114_OnTransition:
# 9 "data/maps/Route114/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 10 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 11 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, AbnormalWeather_StartGroudonWeather
# 12 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, AbnormalWeather_StartGroudonWeather
# 13 "data/maps/Route114/scripts.pory"
	end
# 14 "data/maps/Route114/scripts.pory"

# 15 "data/maps/Route114/scripts.pory"
Route114_OnLoad:
# 16 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute114North
# 17 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute114South
# 18 "data/maps/Route114/scripts.pory"
	end
# 19 "data/maps/Route114/scripts.pory"

# 20 "data/maps/Route114/scripts.pory"
Route114_OnFrame:
# 21 "data/maps/Route114/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 22 "data/maps/Route114/scripts.pory"
	.2byte 0
# 23 "data/maps/Route114/scripts.pory"

# 24 "data/maps/Route114/scripts.pory"
Route114_EventScript_Man::
# 25 "data/maps/Route114/scripts.pory"
	lock
# 26 "data/maps/Route114/scripts.pory"
	faceplayer
# 27 "data/maps/Route114/scripts.pory"
	dotimebasedevents
# 28 "data/maps/Route114/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_114_RECEIVED_BERRY, Route114_EventScript_ReceivedBerry
# 29 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LoveUsingBerryCrushShareBerry, MSGBOX_DEFAULT
# 30 "data/maps/Route114/scripts.pory"
	random NUM_ROUTE_114_MAN_BERRIES
# 31 "data/maps/Route114/scripts.pory"
	addvar VAR_RESULT, NUM_ROUTE_114_MAN_BERRIES_SKIPPED
# 32 "data/maps/Route114/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 33 "data/maps/Route114/scripts.pory"
	giveitem VAR_RESULT
# 34 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 35 "data/maps/Route114/scripts.pory"
	setflag FLAG_DAILY_ROUTE_114_RECEIVED_BERRY
# 36 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_TryBerryCrushWithFriends, MSGBOX_DEFAULT
# 37 "data/maps/Route114/scripts.pory"
	release
# 38 "data/maps/Route114/scripts.pory"
	end
# 39 "data/maps/Route114/scripts.pory"

# 40 "data/maps/Route114/scripts.pory"
Route114_EventScript_ReceivedBerry::
# 41 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_FunToThinkAboutBerries, MSGBOX_DEFAULT
# 42 "data/maps/Route114/scripts.pory"
	release
# 43 "data/maps/Route114/scripts.pory"
	end
# 44 "data/maps/Route114/scripts.pory"

# 45 "data/maps/Route114/scripts.pory"
Route114_EventScript_RoarGentleman::
# 46 "data/maps/Route114/scripts.pory"
	lock
# 47 "data/maps/Route114/scripts.pory"
	faceplayer
# 48 "data/maps/Route114/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_ROAR, Route114_EventScript_ReceivedRoar
# 49 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_AllMyMonDoesIsRoarTakeThis, MSGBOX_DEFAULT
# 50 "data/maps/Route114/scripts.pory"
	giveitem ITEM_TM_ROAR
# 51 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 52 "data/maps/Route114/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROAR
# 53 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
# 54 "data/maps/Route114/scripts.pory"
	release
# 55 "data/maps/Route114/scripts.pory"
	end
# 56 "data/maps/Route114/scripts.pory"

# 57 "data/maps/Route114/scripts.pory"
Route114_EventScript_ReceivedRoar::
# 58 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
# 59 "data/maps/Route114/scripts.pory"
	release
# 60 "data/maps/Route114/scripts.pory"
	end
# 61 "data/maps/Route114/scripts.pory"

# 62 "data/maps/Route114/scripts.pory"
Route114_EventScript_Poochyena::
# 63 "data/maps/Route114/scripts.pory"
	lock
# 64 "data/maps/Route114/scripts.pory"
	faceplayer
# 65 "data/maps/Route114/scripts.pory"
	waitse
# 66 "data/maps/Route114/scripts.pory"
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
# 67 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Poochyena, MSGBOX_DEFAULT
# 68 "data/maps/Route114/scripts.pory"
	waitmoncry
# 69 "data/maps/Route114/scripts.pory"
	release
# 70 "data/maps/Route114/scripts.pory"
	end
# 71 "data/maps/Route114/scripts.pory"

# 72 "data/maps/Route114/scripts.pory"
Route114_EventScript_MeteorFallsSign::
# 73 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_MeteorFallsSign, MSGBOX_SIGN
# 74 "data/maps/Route114/scripts.pory"
	end
# 75 "data/maps/Route114/scripts.pory"

# 76 "data/maps/Route114/scripts.pory"
Route114_EventScript_FossilManiacsHouseSign::
# 77 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_FossilManiacsHouseSign, MSGBOX_SIGN
# 78 "data/maps/Route114/scripts.pory"
	end
# 79 "data/maps/Route114/scripts.pory"

# 80 "data/maps/Route114/scripts.pory"
Route114_EventScript_LanettesHouseSign::
# 81 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LanettesHouse, MSGBOX_SIGN
# 82 "data/maps/Route114/scripts.pory"
	end
# 83 "data/maps/Route114/scripts.pory"

# 84 "data/maps/Route114/scripts.pory"
Route114_EventScript_Lenny::
# 85 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_LENNY, Route114_Text_LennyIntro, Route114_Text_LennyDefeat
# 86 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
# 87 "data/maps/Route114/scripts.pory"
	end
# 88 "data/maps/Route114/scripts.pory"

# 89 "data/maps/Route114/scripts.pory"
Route114_EventScript_Lucas::
# 90 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_LUCAS_1, Route114_Text_LucasIntro, Route114_Text_LucasDefeat
# 91 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
# 92 "data/maps/Route114/scripts.pory"
	end
# 93 "data/maps/Route114/scripts.pory"

# 94 "data/maps/Route114/scripts.pory"
Route114_EventScript_Shane::
# 95 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_SHANE, Route114_Text_ShaneIntro, Route114_Text_ShaneDefeat
# 96 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ShanePostBattle, MSGBOX_AUTOCLOSE
# 97 "data/maps/Route114/scripts.pory"
	end
# 98 "data/maps/Route114/scripts.pory"

# 99 "data/maps/Route114/scripts.pory"
Route114_EventScript_Nancy::
# 100 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_NANCY, Route114_Text_NancyIntro, Route114_Text_NancyDefeat
# 101 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
# 102 "data/maps/Route114/scripts.pory"
	end
# 103 "data/maps/Route114/scripts.pory"

# 104 "data/maps/Route114/scripts.pory"
Route114_EventScript_Steve::
# 105 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_STEVE_1, Route114_Text_SteveIntro, Route114_Text_SteveDefeat, Route114_EventScript_RegisterSteve
# 106 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 107 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_RematchSteve
# 108 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_StevePostBattle, MSGBOX_DEFAULT
# 109 "data/maps/Route114/scripts.pory"
	release
# 110 "data/maps/Route114/scripts.pory"
	end
# 111 "data/maps/Route114/scripts.pory"

# 112 "data/maps/Route114/scripts.pory"
Route114_EventScript_RegisterSteve::
# 113 "data/maps/Route114/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 114 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 115 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_SteveRegister, MSGBOX_DEFAULT
# 116 "data/maps/Route114/scripts.pory"
	register_matchcall TRAINER_STEVE_1
# 117 "data/maps/Route114/scripts.pory"
	release
# 118 "data/maps/Route114/scripts.pory"
	end
# 119 "data/maps/Route114/scripts.pory"

# 120 "data/maps/Route114/scripts.pory"
Route114_EventScript_RematchSteve::
# 121 "data/maps/Route114/scripts.pory"
	trainerbattle_rematch TRAINER_STEVE_1, Route114_Text_SteveRematchIntro, Route114_Text_SteveRematchDefeat
# 122 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_StevePostRematch, MSGBOX_AUTOCLOSE
# 123 "data/maps/Route114/scripts.pory"
	end
# 124 "data/maps/Route114/scripts.pory"

# 125 "data/maps/Route114/scripts.pory"
Route114_EventScript_Bernie::
# 126 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_BERNIE_1, Route114_Text_BernieIntro, Route114_Text_BernieDefeat, Route114_EventScript_RegisterBernie
# 127 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 128 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_RematchBernie
# 129 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BerniePostBattle, MSGBOX_DEFAULT
# 130 "data/maps/Route114/scripts.pory"
	release
# 131 "data/maps/Route114/scripts.pory"
	end
# 132 "data/maps/Route114/scripts.pory"

# 133 "data/maps/Route114/scripts.pory"
Route114_EventScript_RegisterBernie::
# 134 "data/maps/Route114/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 135 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 136 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BernieRegister, MSGBOX_DEFAULT
# 137 "data/maps/Route114/scripts.pory"
	register_matchcall TRAINER_BERNIE_1
# 138 "data/maps/Route114/scripts.pory"
	release
# 139 "data/maps/Route114/scripts.pory"
	end
# 140 "data/maps/Route114/scripts.pory"

# 141 "data/maps/Route114/scripts.pory"
Route114_EventScript_RematchBernie::
# 142 "data/maps/Route114/scripts.pory"
	trainerbattle_rematch TRAINER_BERNIE_1, Route114_Text_BernieRematchIntro, Route114_Text_BernieRematchDefeat
# 143 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BerniePostRematch, MSGBOX_AUTOCLOSE
# 144 "data/maps/Route114/scripts.pory"
	end
# 145 "data/maps/Route114/scripts.pory"

# 146 "data/maps/Route114/scripts.pory"
Route114_EventScript_Claude::
# 147 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_CLAUDE, Route114_Text_ClaudeIntro, Route114_Text_ClaudeDefeat
# 148 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
# 149 "data/maps/Route114/scripts.pory"
	end
# 150 "data/maps/Route114/scripts.pory"

# 151 "data/maps/Route114/scripts.pory"
Route114_EventScript_Nolan::
# 152 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_NOLAN, Route114_Text_NolanIntro, Route114_Text_NolanDefeat
# 153 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
# 154 "data/maps/Route114/scripts.pory"
	end
# 155 "data/maps/Route114/scripts.pory"

# 156 "data/maps/Route114/scripts.pory"
Route114_EventScript_Tyra::
# 157 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_TyraIntro, Route114_Text_TyraDefeat, Route114_Text_TyraNotEnoughMons
# 158 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
# 159 "data/maps/Route114/scripts.pory"
	end
# 160 "data/maps/Route114/scripts.pory"

# 161 "data/maps/Route114/scripts.pory"
Route114_EventScript_Ivy::
# 162 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_IvyIntro, Route114_Text_IvyDefeat, Route114_Text_IvyNotEnoughMons
# 163 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_IvyPostBattle, MSGBOX_AUTOCLOSE
# 164 "data/maps/Route114/scripts.pory"
	end
# 165 "data/maps/Route114/scripts.pory"

# 166 "data/maps/Route114/scripts.pory"
Route114_EventScript_Angelina::
# 167 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_ANGELINA, Route114_Text_AngelinaIntro, Route114_Text_AngelinaDefeat
# 168 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_AngelinaPostBattle, MSGBOX_AUTOCLOSE
# 169 "data/maps/Route114/scripts.pory"
	end
# 170 "data/maps/Route114/scripts.pory"

# 171 "data/maps/Route114/scripts.pory"
Route114_EventScript_Charlotte::
# 172 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_CHARLOTTE, Route114_Text_CharlotteIntro, Route114_Text_CharlotteDefeat
# 173 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_CharlottePostBattle, MSGBOX_AUTOCLOSE
# 174 "data/maps/Route114/scripts.pory"
	end
# 175 "data/maps/Route114/scripts.pory"

# 176 "data/maps/Route114/scripts.pory"
Route114_EventScript_Kai::
# 177 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_KAI, Route114_Text_KaiIntro, Route114_Text_KaiDefeat
# 178 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_KaiPostBattle, MSGBOX_AUTOCLOSE
# 179 "data/maps/Route114/scripts.pory"
	end
# 180 "data/maps/Route114/scripts.pory"

# 181 "data/maps/Route114/scripts.pory"
Route114_Text_AllMyMonDoesIsRoarTakeThis:
# 182 "data/maps/Route114/scripts.pory"
	.string "All my Pokémon does is ROAR…\n"
# 183 "data/maps/Route114/scripts.pory"
	.string "No one dares to come near me…\p"
# 184 "data/maps/Route114/scripts.pory"
	.string "Sigh… If you would, please take\n"
# 185 "data/maps/Route114/scripts.pory"
	.string "this TM away…$"
# 186 "data/maps/Route114/scripts.pory"

# 187 "data/maps/Route114/scripts.pory"
Route114_Text_ExplainRoar:
# 188 "data/maps/Route114/scripts.pory"
	.string "TM05 contains Roar.\n"
# 189 "data/maps/Route114/scripts.pory"
	.string "A Roar sends Pokémon scurrying.$"
# 190 "data/maps/Route114/scripts.pory"

# 191 "data/maps/Route114/scripts.pory"
Route114_Text_Poochyena:
# 192 "data/maps/Route114/scripts.pory"
	.string "Bow! Bowwow!$"
# 193 "data/maps/Route114/scripts.pory"

# 194 "data/maps/Route114/scripts.pory"
Route114_Text_MeteorFallsSign:
# 195 "data/maps/Route114/scripts.pory"
	.string "Meteor Falls\n"
# 196 "data/maps/Route114/scripts.pory"
	.string "Rustboro City through here$"
# 197 "data/maps/Route114/scripts.pory"

# 198 "data/maps/Route114/scripts.pory"
Route114_Text_FossilManiacsHouseSign:
# 199 "data/maps/Route114/scripts.pory"
	.string "Fossil Maniac's House\n"
# 200 "data/maps/Route114/scripts.pory"
	.string "“Fossils gratefully accepted!”$"
# 201 "data/maps/Route114/scripts.pory"

# 202 "data/maps/Route114/scripts.pory"
Route114_Text_LanettesHouse:
# 203 "data/maps/Route114/scripts.pory"
	.string "Lanette's House$"

MayLetsFight::
# 209 "data/maps/Route114/scripts.pory"
	lock
# 210 "data/maps/Route114/scripts.pory"
	faceplayer
# 211 "data/maps/Route114/scripts.pory"
	checkplayergender
# 212 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BrendanLetsFight
# 213 "data/maps/Route114/scripts.pory"
	msgbox MayMagmas
# 214 "data/maps/Route114/scripts.pory"
	release
	end


RivalMultiBattle::
# 219 "data/maps/Route114/scripts.pory"
	lock
# 220 "data/maps/Route114/scripts.pory"
	faceplayer
# 221 "data/maps/Route114/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 222 "data/maps/Route114/scripts.pory"
	applymovement 30, MayBrendanWalkInplace
# 223 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 224 "data/maps/Route114/scripts.pory"
	checkplayergender
# 225 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, MayMulti
# 226 "data/maps/Route114/scripts.pory"
	msgbox BrendanConfront
# 227 "data/maps/Route114/scripts.pory"
	applymovement 28, CourtneyMove
# 228 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 229 "data/maps/Route114/scripts.pory"
	msgbox PrettyFunny
# 230 "data/maps/Route114/scripts.pory"
	choose_mons
# 231 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, 0, AreYouScared
# 232 "data/maps/Route114/scripts.pory"
	msgbox GetReadyNow
# 233 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FacePlayer
# 234 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 235 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 236 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 237 "data/maps/Route114/scripts.pory"
	msgbox LockIn
# 238 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FaceUp
# 239 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 240 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 241 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 242 "data/maps/Route114/scripts.pory"
	switch VAR_STARTER_MON
# 243 "data/maps/Route114/scripts.pory"
	case 0, RivalMultiBattle_2
# 245 "data/maps/Route114/scripts.pory"
	case 1, RivalMultiBattle_3
# 247 "data/maps/Route114/scripts.pory"
	case 2, RivalMultiBattle_4
	return

RivalMultiBattle_2:
# 244 "data/maps/Route114/scripts.pory"
	call BrendanBlazikenTeam
	return

RivalMultiBattle_3:
# 246 "data/maps/Route114/scripts.pory"
	call BrendanSwampertTeam
	return

RivalMultiBattle_4:
# 248 "data/maps/Route114/scripts.pory"
	call BrendanSceptileTeam
	return


BrendanBlazikenTeam::
# 253 "data/maps/Route114/scripts.pory"
	multi_2_vs_2 TRAINER_COURTNEY, CourtneyDefeat, TRAINER_GRUNT_114, GruntLose, PARTNER_BRENDAN_TREECKO
# 254 "data/maps/Route114/scripts.pory"
	goto BrendanJoinParty1
	return


BrendanSwampertTeam::
# 258 "data/maps/Route114/scripts.pory"
	multi_2_vs_2 TRAINER_COURTNEY, CourtneyDefeat, TRAINER_GRUNT_114, GruntLose, PARTNER_BRENDAN_TORCHIC
# 259 "data/maps/Route114/scripts.pory"
	goto BrendanJoinParty2
	return


BrendanSceptileTeam::
# 263 "data/maps/Route114/scripts.pory"
	multi_2_vs_2 TRAINER_COURTNEY, CourtneyDefeat, TRAINER_GRUNT_114, GruntLose, PARTNER_BRENDAN_MUDKIP
# 264 "data/maps/Route114/scripts.pory"
	goto BrendanJoinParty3
	return


BrendanJoinParty1::
# 268 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 269 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BothWhiteOut
# 270 "data/maps/Route114/scripts.pory"
	msgbox WeGotMeteorite
# 271 "data/maps/Route114/scripts.pory"
	fadescreen FADE_TO_BLACK
# 272 "data/maps/Route114/scripts.pory"
	setflag FLAG_MAGMAS_114
# 273 "data/maps/Route114/scripts.pory"
	removeobject 28
# 274 "data/maps/Route114/scripts.pory"
	removeobject 29
# 275 "data/maps/Route114/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 276 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FacePlayer
# 277 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 278 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 279 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 280 "data/maps/Route114/scripts.pory"
	msgbox NglPrettyGood
# 281 "data/maps/Route114/scripts.pory"
	setfollowernpc 30, FOLLOWER_NPC_FLAG_ALL, BrendanChatRandom, PARTNER_BRENDAN_TREECKO
# 282 "data/maps/Route114/scripts.pory"
	setvar VAR_FOLLOWER_WRONG_WAY, 1
# 283 "data/maps/Route114/scripts.pory"
	release
	end


BrendanJoinParty2::
# 288 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 289 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BothWhiteOut
# 290 "data/maps/Route114/scripts.pory"
	msgbox WeGotMeteorite
# 291 "data/maps/Route114/scripts.pory"
	fadescreen FADE_TO_BLACK
# 292 "data/maps/Route114/scripts.pory"
	setflag FLAG_MAGMAS_114
# 293 "data/maps/Route114/scripts.pory"
	removeobject 28
# 294 "data/maps/Route114/scripts.pory"
	removeobject 29
# 295 "data/maps/Route114/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 296 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FacePlayer
# 297 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 298 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 299 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 300 "data/maps/Route114/scripts.pory"
	msgbox NglPrettyGood
# 301 "data/maps/Route114/scripts.pory"
	setfollowernpc 30, FOLLOWER_NPC_FLAG_ALL, BrendanChatRandom, PARTNER_BRENDAN_TORCHIC
# 302 "data/maps/Route114/scripts.pory"
	setvar VAR_FOLLOWER_WRONG_WAY, 1
# 303 "data/maps/Route114/scripts.pory"
	release
	end


BrendanJoinParty3::
# 308 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 309 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BothWhiteOut
# 310 "data/maps/Route114/scripts.pory"
	msgbox WeGotMeteorite
# 311 "data/maps/Route114/scripts.pory"
	fadescreen FADE_TO_BLACK
# 312 "data/maps/Route114/scripts.pory"
	setflag FLAG_MAGMAS_114
# 313 "data/maps/Route114/scripts.pory"
	removeobject 28
# 314 "data/maps/Route114/scripts.pory"
	removeobject 29
# 315 "data/maps/Route114/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 316 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FacePlayer
# 317 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 318 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 319 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 320 "data/maps/Route114/scripts.pory"
	msgbox NglPrettyGood
# 321 "data/maps/Route114/scripts.pory"
	setfollowernpc 30, FOLLOWER_NPC_FLAG_ALL, BrendanChatRandom, PARTNER_BRENDAN_MUDKIP
# 322 "data/maps/Route114/scripts.pory"
	setvar VAR_FOLLOWER_WRONG_WAY, 1
# 323 "data/maps/Route114/scripts.pory"
	release
	end


BrendanChatRandom::
# 328 "data/maps/Route114/scripts.pory"
	lock
# 329 "data/maps/Route114/scripts.pory"
	faceplayer
# 330 "data/maps/Route114/scripts.pory"
	random 2
# 331 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BrendanChatMagmas
# 332 "data/maps/Route114/scripts.pory"
	msgbox WhatIMissed
# 333 "data/maps/Route114/scripts.pory"
	release
	end


MayChatRandom::
# 338 "data/maps/Route114/scripts.pory"
	lock
# 339 "data/maps/Route114/scripts.pory"
	faceplayer
# 340 "data/maps/Route114/scripts.pory"
	random 2
# 341 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MayTraining
# 342 "data/maps/Route114/scripts.pory"
	msgbox WhatIMissed
# 343 "data/maps/Route114/scripts.pory"
	release
	end


MayTraining::
# 348 "data/maps/Route114/scripts.pory"
	msgbox HowsItGoing
# 349 "data/maps/Route114/scripts.pory"
	release
	end


BrendanChatMagmas::
# 354 "data/maps/Route114/scripts.pory"
	msgbox ThoseMagmas
# 355 "data/maps/Route114/scripts.pory"
	release
	end


FollowerWrongWay::
# 360 "data/maps/Route114/scripts.pory"
	lockall
# 361 "data/maps/Route114/scripts.pory"
	msgbox PlayerSenses
# 362 "data/maps/Route114/scripts.pory"
	closemessage
# 363 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
# 364 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 365 "data/maps/Route114/scripts.pory"
	releaseall
	end


MayJoinParty1::
# 370 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 371 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BothWhiteOut
# 372 "data/maps/Route114/scripts.pory"
	msgbox WeGotMeteorite
# 373 "data/maps/Route114/scripts.pory"
	fadescreen FADE_TO_BLACK
# 374 "data/maps/Route114/scripts.pory"
	setflag FLAG_MAGMAS_114
# 375 "data/maps/Route114/scripts.pory"
	removeobject 28
# 376 "data/maps/Route114/scripts.pory"
	removeobject 29
# 377 "data/maps/Route114/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 378 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FacePlayer
# 379 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 380 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 381 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 382 "data/maps/Route114/scripts.pory"
	msgbox NiceJob
# 383 "data/maps/Route114/scripts.pory"
	setfollowernpc 30, FOLLOWER_NPC_FLAG_ALL, MayChatRandom, PARTNER_MAY_TREECKO
# 384 "data/maps/Route114/scripts.pory"
	setvar VAR_FOLLOWER_WRONG_WAY, 1
# 385 "data/maps/Route114/scripts.pory"
	release
	end


MayJoinParty2::
# 390 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 391 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BothWhiteOut
# 392 "data/maps/Route114/scripts.pory"
	msgbox WeGotMeteorite
# 393 "data/maps/Route114/scripts.pory"
	fadescreen FADE_TO_BLACK
# 394 "data/maps/Route114/scripts.pory"
	setflag FLAG_MAGMAS_114
# 395 "data/maps/Route114/scripts.pory"
	removeobject 28
# 396 "data/maps/Route114/scripts.pory"
	removeobject 29
# 397 "data/maps/Route114/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 398 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FacePlayer
# 399 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 400 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 401 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 402 "data/maps/Route114/scripts.pory"
	msgbox NiceJob
# 403 "data/maps/Route114/scripts.pory"
	setfollowernpc 30, FOLLOWER_NPC_FLAG_ALL, MayChatRandom, PARTNER_MAY_TORCHIC
# 404 "data/maps/Route114/scripts.pory"
	setvar VAR_FOLLOWER_WRONG_WAY, 1
# 405 "data/maps/Route114/scripts.pory"
	release
	end


MayJoinParty3::
# 410 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 411 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BothWhiteOut
# 412 "data/maps/Route114/scripts.pory"
	msgbox WeGotMeteorite
# 413 "data/maps/Route114/scripts.pory"
	fadescreen FADE_TO_BLACK
# 414 "data/maps/Route114/scripts.pory"
	setflag FLAG_MAGMAS_114
# 415 "data/maps/Route114/scripts.pory"
	removeobject 28
# 416 "data/maps/Route114/scripts.pory"
	removeobject 29
# 417 "data/maps/Route114/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 418 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FacePlayer
# 419 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 420 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 421 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 422 "data/maps/Route114/scripts.pory"
	msgbox NiceJob
# 423 "data/maps/Route114/scripts.pory"
	setfollowernpc 30, FOLLOWER_NPC_FLAG_ALL, MayChatRandom, PARTNER_MAY_MUDKIP
# 424 "data/maps/Route114/scripts.pory"
	setvar VAR_FOLLOWER_WRONG_WAY, 1
# 425 "data/maps/Route114/scripts.pory"
	release
	end


BothWhiteOut::
# 430 "data/maps/Route114/scripts.pory"
	msgbox CourtneyTaunt
# 431 "data/maps/Route114/scripts.pory"
	goto EventScript_FieldWhiteOut
	return


AreYouScared::
# 435 "data/maps/Route114/scripts.pory"
	applymovement 28, CourtneyMove
# 436 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FacePlayer
# 437 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 438 "data/maps/Route114/scripts.pory"
	msgbox HAHAHAH
# 439 "data/maps/Route114/scripts.pory"
	release
	end


MayMulti::
# 444 "data/maps/Route114/scripts.pory"
	msgbox MayGiveItUp
# 445 "data/maps/Route114/scripts.pory"
	applymovement 28, CourtneyMove
# 446 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 447 "data/maps/Route114/scripts.pory"
	msgbox PrettyFunny
# 448 "data/maps/Route114/scripts.pory"
	choose_mons
# 449 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, 0, AreYouScared
# 450 "data/maps/Route114/scripts.pory"
	msgbox GetReadyNow
# 451 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FacePlayer
# 452 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 453 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 454 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 455 "data/maps/Route114/scripts.pory"
	msgbox WeGotThis
# 456 "data/maps/Route114/scripts.pory"
	applymovement 30, Common_Movement_FaceUp
# 457 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 458 "data/maps/Route114/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 459 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 460 "data/maps/Route114/scripts.pory"
	switch VAR_STARTER_MON
# 461 "data/maps/Route114/scripts.pory"
	case 0, MayMulti_2
# 463 "data/maps/Route114/scripts.pory"
	case 1, MayMulti_3
# 465 "data/maps/Route114/scripts.pory"
	case 2, MayMulti_4
	return

MayMulti_2:
# 462 "data/maps/Route114/scripts.pory"
	call MayBlazikenTeam
	return

MayMulti_3:
# 464 "data/maps/Route114/scripts.pory"
	call MaySwampertTeam
	return

MayMulti_4:
# 466 "data/maps/Route114/scripts.pory"
	call MaySceptileTeam
	return


MayBlazikenTeam::
# 471 "data/maps/Route114/scripts.pory"
	multi_2_vs_2 TRAINER_COURTNEY, CourtneyDefeat, TRAINER_GRUNT_114, GruntLose, PARTNER_MAY_TREECKO
# 472 "data/maps/Route114/scripts.pory"
	goto MayJoinParty1
	return


MaySwampertTeam::
# 476 "data/maps/Route114/scripts.pory"
	multi_2_vs_2 TRAINER_COURTNEY, CourtneyDefeat, TRAINER_GRUNT_114, GruntLose, PARTNER_MAY_TORCHIC
# 477 "data/maps/Route114/scripts.pory"
	goto MayJoinParty2
	return


MaySceptileTeam::
# 481 "data/maps/Route114/scripts.pory"
	multi_2_vs_2 TRAINER_COURTNEY, CourtneyDefeat, TRAINER_GRUNT_114, GruntLose, PARTNER_MAY_MUDKIP
# 482 "data/maps/Route114/scripts.pory"
	goto MayJoinParty3
	return


BrendanLetsFight::
# 486 "data/maps/Route114/scripts.pory"
	msgbox BrendanMagmas
# 487 "data/maps/Route114/scripts.pory"
	release
	end


# 609 "data/maps/Route114/scripts.pory"
CourtneyMove:
# 610 "data/maps/Route114/scripts.pory"
	walk_in_place_down
	step_end

# 613 "data/maps/Route114/scripts.pory"
MayBrendanWalkInplace:
# 614 "data/maps/Route114/scripts.pory"
	walk_in_place_up
	step_end

PlayerSenses::
# 491 "data/maps/Route114/scripts.pory"
	.string "A part of me thinks it's not a good idea\n"
	.string "to go this way right now.$"

HowsItGoing::
# 496 "data/maps/Route114/scripts.pory"
	.string "How's your training been going lately\n"
	.string "{PLAYER}\p"
	.string "I heard there's another Gym close by.$"

NiceJob::
# 502 "data/maps/Route114/scripts.pory"
	.string "Alright! we did it!\n"
	.string "About time they finally left.\p"
	.string "Hey, since we're kind of heading to the\n"
	.string "same place, why don't we go with each\l"
	.string "other {PLAYER}?$"

WhatIMissed::
# 510 "data/maps/Route114/scripts.pory"
	.string "Route 115 has quite a few Pokémon Dex\n"
	.string "entries I missed.\p"
	.string "This side of the route past the exit\n"
	.string "also is good for training.$"

ThoseMagmas::
# 517 "data/maps/Route114/scripts.pory"
	.string "Those Team Magma Grunts have been\n"
	.string "really annoying lately.\p"
	.string "I wonder what they're up to.$"

NglPrettyGood::
# 523 "data/maps/Route114/scripts.pory"
	.string "I'm not gonna lie, you did pretty good\n"
	.string "out there.\p"
	.string "So you're going to Meteors Falls then?\n"
	.string "I guess we might as well go in together\l"
	.string "because I'm going back to Route 115.$"

WeGotMeteorite::
# 531 "data/maps/Route114/scripts.pory"
	.string "Courtney: Hahah, you may have won the\n"
	.string "battle, but you haven't won the war!\p"
	.string "Little did you guys know is that we\n"
	.string "already collected the meteorite.$"

CourtneyTaunt::
# 538 "data/maps/Route114/scripts.pory"
	.string "Courtney: Hahaha, how pathetic!\p"
	.string "This is why you never bother with Team\n"
	.string "Magmas plans!$"

CourtneyDefeat::
# 544 "data/maps/Route114/scripts.pory"
	.string "I cant believe I lost!\n"
	.string "Okay, lets dip!$"

GruntLose::
# 549 "data/maps/Route114/scripts.pory"
	.string "Ah, gosh dang it!$"

WeGotThis::
# 553 "data/maps/Route114/scripts.pory"
	.string "This'll be our first time battling\n"
	.string "together {PLAYER}!\p"
	.string "We've got to do our best!$"

LockIn::
# 559 "data/maps/Route114/scripts.pory"
	.string "Brendan: It's not gonna look pretty if\n"
	.string "we lose this so we have to lock in {PLAYER}.$"

GetReadyNow::
# 564 "data/maps/Route114/scripts.pory"
	.string "Courtney: Heheh, I already know those\n"
	.string "tears are gonna be dropping from both\l"
	.string "of your faces after this.$"

HAHAHAH::
# 570 "data/maps/Route114/scripts.pory"
	.string "Courtney: Hahah, oh what? You're\n"
	.string "scared?$"

PrettyFunny::
# 575 "data/maps/Route114/scripts.pory"
	.string "Courtney: You're pretty funny!\n"
	.string "You think its fun to mess with us, huh?\p"
	.string "Too bad we're going to destroy and\n"
	.string "embarrass you both.$"

MayGiveItUp::
# 582 "data/maps/Route114/scripts.pory"
	.string "May: Give it up you bozos!\n"
	.string "You're not getting anywhere blocking\l"
	.string "the entrance!$"

BrendanConfront::
# 588 "data/maps/Route114/scripts.pory"
	.string "Brendan: Give it up already you weirdos!\n"
	.string "I know you guys are from Team Magma!$"

BrendanMagmas::
# 593 "data/maps/Route114/scripts.pory"
	.string "Yo {PLAYER}, get a load of these losers.\p"
	.string "I saw them blocking the entrance here\n"
	.string "and they're pretty suspicious.\p"
	.string "We've got to see what's up with them!$"

MayMagmas::
# 600 "data/maps/Route114/scripts.pory"
	.string "Hey {PLAYER}, good timing.\p"
	.string "I wanted to revisit Route 115 again but\n"
	.string "these strange people here thought it\l"
	.string "was a good idea to block the entrance.\p"
	.string "It looks like they're up to no good so\n"
	.string "maybe we should fight them.$"
