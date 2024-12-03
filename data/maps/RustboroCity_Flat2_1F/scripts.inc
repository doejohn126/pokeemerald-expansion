RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DELCATTY, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end


RustboroCity_Flat2_1F_EventScript_Glameow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GLAMEOW, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Glameow, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_Glameow:
	.string "GLAMEOW: Ehaheee!$"

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.string "Devon Corporation's workers live in\n"
	.string "this building.$"

RustboroCity_Flat2_1F_Text_Skitty:
	.string "Delcatty: Gyaaaah!$"

