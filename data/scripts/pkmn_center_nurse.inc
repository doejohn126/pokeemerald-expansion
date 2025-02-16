Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
    goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_PkmnCenterChallenge_NoVisits
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard
    goto EventScript_PkmnCenterNurse_HealPkmn
	end

EventScript_PkmnCenterNurse_Goodbye::
	return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterNurse_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_IllTakeYourPkmn2
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
	message gText_IllTakeYourPkmn
	return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
	message gText_IllTakeYourPkmn2
	return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	hidefollower 0
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Turn
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
.if OW_UNION_DISABLE_CHECK == FALSE && OW_FLAG_MOVE_UNION_ROOM_CHECK != 0
	setflag OW_FLAG_MOVE_UNION_ROOM_CHECK
	call CableClub_OnResume
	clearflag OW_FLAG_MOVE_UNION_ROOM_CHECK
.endif
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_ReturnPkmn2
	message gText_RestoredPkmnToFullHealth
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	goto EventScript_PkmnCenterNurse_PlayerTurn
	return

EventScript_PkmnCenterNurse_ReturnPkmn2::
	message gText_ThankYouForWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain2
	goto EventScript_PkmnCenterNurse_PlayerTurn
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message CableClub_Text_PlayerIsWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_ExplainPokerus::
	message gText_PokerusExplanation
	setflag FLAG_POKERUS_EXPLAINED
	return

EventScript_PkmnCenterNurse_GoldCard::
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x800B, Common_Movement_Delay48
	waitmovement 0
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_AskForUsual::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
	setvar VAR_0x8004, 1
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

Movement_PkmnCenterNurse_Turn:
	walk_in_place_faster_left
	step_end

EventScript_PkmnCenterNurse_PlayerTurn::
   closemessage
   applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
   waitmovement 0
   release
   end

WinonaLevelCap::
   msgbox gText_TheWinonaCap, MSGBOX_DEFAULT
   release
   end

NormanLevelCap::
   msgbox gText_TheNormanCap, MSGBOX_DEFAULT
   release
   end

FlanLevelCap::
   msgbox gText_TheFlanCap, MSGBOX_DEFAULT
   release
   end

WattsonLevelCap::
   msgbox gText_TheWattsonCap, MSGBOX_DEFAULT
   release
   end

BrawlyLevelCap::
   msgbox gText_TheBrawlyCap, MSGBOX_DEFAULT
   release
   end

TateLizaLevelCap::
   msgbox gText_TheTateLizaCap, MSGBOX_DEFAULT
   release
   end

JuanLevelCap::
   msgbox gText_TheJuanCap, MSGBOX_DEFAULT
   release
   end

LeagueLevelCap::
   msgbox gText_TheLeagueCap, MSGBOX_DEFAULT
   release
   end

NoLevelCap::
	msgbox gText_NoCap, MSGBOX_DEFAULT
	release
	end

UnknownLevelCap::
   msgbox gText_UnknownCap, MSGBOX_DEFAULT
   release
   end


Common_EventScript_ExtraThingsReceptionist::
   lock
   faceplayer
   msgbox gText_DoYouNeedSomething, MSGBOX_DEFAULT
   dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, gText_MysteryGiftOption, gText_LevelCap, gText_ChangeBall
   call_if_eq VAR_RESULT, 0, Common_EventScript_MysteryGift
   call_if_eq VAR_RESULT, 1, Common_EventScript_LevelCap
   call_if_eq VAR_RESULT, 2, Common_EventScript_ChangeBall
   release
   end

Common_EventScript_LevelCap::
   goto_if_set FLAG_IS_CHAMPION, NoLevelCap
   goto_if_set FLAG_BADGE08_GET, LeagueLevelCap
   goto_if_set FLAG_BADGE07_GET, JuanLevelCap
   goto_if_set FLAG_BADGE06_GET, TateLizaLevelCap
   goto_if_set FLAG_BADGE05_GET, WinonaLevelCap
   goto_if_set FLAG_BADGE04_GET, NormanLevelCap
   goto_if_set FLAG_BADGE03_GET, FlanLevelCap
   goto_if_set FLAG_BADGE02_GET, WattsonLevelCap
   goto_if_set FLAG_BADGE01_GET, BrawlyLevelCap
   msgbox gText_TheRoxanneCap, MSGBOX_DEFAULT
   release
   end

Common_EventScript_ChangeBall::
	msgbox gText_WhatBall, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, gText_PokeBall, gText_GreatBall, gText_UltraBall, gText_SafariBall, gText_FastBall, gText_LevelBall, gText_LureBall, gText_HeavyBall, gText_LoveBall, gText_FriendBall, gText_MoonBall, gText_SportBall, gText_NetBall, gText_DiveBall, gText_NestBall, gText_RepeatBall, gText_TimerBall, gText_LuxuryBall, gText_PremierBall, gText_DuskBall, gText_HealBall, gText_QuickBall, gText_ParkBall, gText_DreamBall, gText_BeastBall
	call_if_eq VAR_RESULT, 0, ChangeToPokeball
	call_if_eq VAR_RESULT, 1, ChangeToGreatBall
	call_if_eq VAR_RESULT, 2, ChangeToUltraBall
	call_if_eq VAR_RESULT, 3, ChangeToSafariBall
	call_if_eq VAR_RESULT, 4, ChangeToFastBall
	call_if_eq VAR_RESULT, 5, ChangeToLevelBall
	call_if_eq VAR_RESULT, 6, ChangeToLureBall
	call_if_eq VAR_RESULT, 7, ChangeToHeavyBall
	call_if_eq VAR_RESULT, 8, ChangeToLoveBall
	call_if_eq VAR_RESULT, 9, ChangeToFriendBall
	call_if_eq VAR_RESULT, 10, ChangeToMoonBall
	call_if_eq VAR_RESULT, 11, ChangeToSportBall
	call_if_eq VAR_RESULT, 12, ChangeToNetBall
	call_if_eq VAR_RESULT, 13, ChangeToDiveBall
	call_if_eq VAR_RESULT, 14, ChangeToNestBall
	call_if_eq VAR_RESULT, 15, ChangeToRepeatBall
	call_if_eq VAR_RESULT, 16, ChangeToTimerBall
	call_if_eq VAR_RESULT, 17, ChangeToLuxuryBall
	call_if_eq VAR_RESULT, 18, ChangeToPremierBall
	call_if_eq VAR_RESULT, 19, ChangeToDuskBall
	call_if_eq VAR_RESULT, 20, ChangeToHealBall
	call_if_eq VAR_RESULT, 21, ChangeToQuickBall
	call_if_eq VAR_RESULT, 22, ChangeToParkBall
	call_if_eq VAR_RESULT, 23, ChangeToDreamBall
	call_if_eq VAR_RESULT, 24, ChangeToBeastBall

ChangeToPokeball::
	SetMonBall ITEM_POKE_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToGreatBall::
	SetMonBall ITEM_GREAT_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToUltraBall::
	SetMonBall ITEM_ULTRA_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToSafariBall::
	SetMonBall ITEM_SAFARI_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToFastBall::
	SetMonBall ITEM_FAST_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToLevelBall::
	SetMonBall ITEM_LEVEL_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToLureBall::
	SetMonBall ITEM_LURE_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToHeavyBall::
	SetMonBall ITEM_HEAVY_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToLoveBall::
	SetMonBall ITEM_LOVE_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToFriendBall::
	SetMonBall ITEM_FRIEND_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToMoonBall::
	SetMonBall ITEM_MOON_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToSportBall::
	SetMonBall ITEM_SPORT_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToNetBall::
	SetMonBall ITEM_NET_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToDiveBall::
	SetMonBall ITEM_DIVE_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToNestBall::
	SetMonBall ITEM_NEST_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToRepeatBall::
	SetMonBall ITEM_REPEAT_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToTimerBall::
	SetMonBall ITEM_TIMER_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToLuxuryBall::
	SetMonBall ITEM_LUXURY_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToPremierBall::
	SetMonBall ITEM_PREMIER_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToDuskBall::
	SetMonBall ITEM_DUSK_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToHealBall::
	SetMonBall ITEM_HEAL_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToQuickBall::
	SetMonBall ITEM_QUICK_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToParkBall::
	SetMonBall ITEM_PARK_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToDreamBall::
	SetMonBall ITEM_DREAM_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end

ChangeToBeastBall::
	SetMonBall ITEM_BEAST_BALL
	msgbox ThereYouGo, MSGBOX_DEFAULT
	release
	end


EventScript_PkmnCenterNurse_PkmnCenterChallenge_NoVisits:: @ tx_randomizer_and_challenges
    message gText_PkmnCenterChallenge_NoVisitsLeft
    waitmessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
    waitmovement 0
    release
    end
