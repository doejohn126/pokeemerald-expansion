# 1 "data/maps/GiratinasRoom/scripts.pory"

# 2 "data/maps/GiratinasRoom/scripts.pory"
GiratinasRoom_MapScripts::
# 3 "data/maps/GiratinasRoom/scripts.pory"
	.byte 0

GiratinaMain::
# 8 "data/maps/GiratinasRoom/scripts.pory"
	lockall
# 9 "data/maps/GiratinasRoom/scripts.pory"
	faceplayer
# 10 "data/maps/GiratinasRoom/scripts.pory"
	setflag FLAG_GIRATINA
# 11 "data/maps/GiratinasRoom/scripts.pory"
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
# 12 "data/maps/GiratinasRoom/scripts.pory"
	waitmoncry
# 13 "data/maps/GiratinasRoom/scripts.pory"
	setwildbattle SPECIES_GIRATINA, 90
# 14 "data/maps/GiratinasRoom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 15 "data/maps/GiratinasRoom/scripts.pory"
	waitstate
# 17 "data/maps/GiratinasRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 18 "data/maps/GiratinasRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GiratinaMain_1
# 21 "data/maps/GiratinasRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GiratinaMain_2
# 25 "data/maps/GiratinasRoom/scripts.pory"
	goto RanAway
	return

GiratinaMain_1:
# 19 "data/maps/GiratinasRoom/scripts.pory"
	goto Won_or_Caught_Gira
	return

GiratinaMain_2:
# 22 "data/maps/GiratinasRoom/scripts.pory"
	goto Won_or_Caught_Gira
	return


Won_or_Caught_Gira::
# 30 "data/maps/GiratinasRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 31 "data/maps/GiratinasRoom/scripts.pory"
	removeobject 1
# 32 "data/maps/GiratinasRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 33 "data/maps/GiratinasRoom/scripts.pory"
	msgbox Won_or_Caught_Gira_Text_0
# 34 "data/maps/GiratinasRoom/scripts.pory"
	releaseall
	end


RanAway::
# 39 "data/maps/GiratinasRoom/scripts.pory"
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
# 40 "data/maps/GiratinasRoom/scripts.pory"
	msgbox RanAway_Text_0
# 41 "data/maps/GiratinasRoom/scripts.pory"
	delay 25
# 42 "data/maps/GiratinasRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 43 "data/maps/GiratinasRoom/scripts.pory"
	removeobject 1
# 44 "data/maps/GiratinasRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 45 "data/maps/GiratinasRoom/scripts.pory"
	msgbox RanAway_Text_1
# 46 "data/maps/GiratinasRoom/scripts.pory"
	releaseall
	end


Won_or_Caught_Gira_Text_0:
# 33 "data/maps/GiratinasRoom/scripts.pory"
	.string "Giratina has been sealed.$"

RanAway_Text_0:
# 40 "data/maps/GiratinasRoom/scripts.pory"
	.string "Ayeuhhhh!!!$"

RanAway_Text_1:
# 45 "data/maps/GiratinasRoom/scripts.pory"
	.string "Giratina fled...$"
