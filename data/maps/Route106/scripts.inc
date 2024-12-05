# 1 "data/maps/Route106/scripts.pory"

# 2 "data/maps/Route106/scripts.pory"
Route106_MapScripts::
# 3 "data/maps/Route106/scripts.pory"
	.byte 0
# 4 "data/maps/Route106/scripts.pory"

# 5 "data/maps/Route106/scripts.pory"
Route106_EventScript_TrainerTipsSign::
# 6 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
# 7 "data/maps/Route106/scripts.pory"
	end
# 8 "data/maps/Route106/scripts.pory"

# 9 "data/maps/Route106/scripts.pory"
Route106_EventScript_Douglas::
# 10 "data/maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
# 11 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
# 12 "data/maps/Route106/scripts.pory"
	end
# 13 "data/maps/Route106/scripts.pory"

# 14 "data/maps/Route106/scripts.pory"
Route106_EventScript_Kyla::
# 15 "data/maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
# 16 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
# 17 "data/maps/Route106/scripts.pory"
	end
# 18 "data/maps/Route106/scripts.pory"

# 19 "data/maps/Route106/scripts.pory"
Route106_EventScript_Elliot::
# 20 "data/maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
# 21 "data/maps/Route106/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 22 "data/maps/Route106/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
# 23 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
# 24 "data/maps/Route106/scripts.pory"
	release
# 25 "data/maps/Route106/scripts.pory"
	end
# 26 "data/maps/Route106/scripts.pory"

# 27 "data/maps/Route106/scripts.pory"
Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
# 28 "data/maps/Route106/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 29 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 30 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
# 31 "data/maps/Route106/scripts.pory"
	register_matchcall TRAINER_ELLIOT_1
# 32 "data/maps/Route106/scripts.pory"
	release
# 33 "data/maps/Route106/scripts.pory"
	end
# 34 "data/maps/Route106/scripts.pory"

# 35 "data/maps/Route106/scripts.pory"
Route106_EventScript_ElliotRematch::
# 36 "data/maps/Route106/scripts.pory"
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
# 37 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
# 38 "data/maps/Route106/scripts.pory"
	end
# 39 "data/maps/Route106/scripts.pory"

# 40 "data/maps/Route106/scripts.pory"
Route106_EventScript_Ned::
# 41 "data/maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
# 42 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
# 43 "data/maps/Route106/scripts.pory"
	end
# 44 "data/maps/Route106/scripts.pory"

# 45 "data/maps/Route106/scripts.pory"
Route106_Text_TrainerTips:
# 46 "data/maps/Route106/scripts.pory"
	.string "Trainer Tips\p"
# 47 "data/maps/Route106/scripts.pory"
	.string "Advice on catching Pokémon with a Rod:\n"
# 48 "data/maps/Route106/scripts.pory"
	.string "Press the A Button if you get a bite.$"

Jayden1061::
# 54 "data/maps/Route106/scripts.pory"
	lock
# 55 "data/maps/Route106/scripts.pory"
	clearflag FLAG_JAYDEN_ROUTE106
# 56 "data/maps/Route106/scripts.pory"
	addobject 6
# 57 "data/maps/Route106/scripts.pory"
	playse SE_EXIT
# 58 "data/maps/Route106/scripts.pory"
	applymovement 6, JaydenMoveUp
# 59 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 60 "data/maps/Route106/scripts.pory"
	playse SE_PIN
# 61 "data/maps/Route106/scripts.pory"
	applymovement 6, JaydenGoToPlayer1
# 62 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 63 "data/maps/Route106/scripts.pory"
	msgbox JaydenHiAgain
# 64 "data/maps/Route106/scripts.pory"
	trainerbattle_no_intro TRAINER_JAYDEN_2, JaydenYouGotBetter
# 65 "data/maps/Route106/scripts.pory"
	setvar VAR_JAYDEN_106, 1
# 66 "data/maps/Route106/scripts.pory"
	msgbox PrettyGood
# 67 "data/maps/Route106/scripts.pory"
	giveitem ITEM_VS_SEEKER, 1
# 68 "data/maps/Route106/scripts.pory"
	msgbox Jayden106Outro
# 69 "data/maps/Route106/scripts.pory"
	applymovement 6, JaydenLeave1
# 70 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 71 "data/maps/Route106/scripts.pory"
	setflag FLAG_JAYDEN_ROUTE106
# 72 "data/maps/Route106/scripts.pory"
	removeobject 6
# 73 "data/maps/Route106/scripts.pory"
	release
	end


Jayden1062::
# 78 "data/maps/Route106/scripts.pory"
	lock
# 79 "data/maps/Route106/scripts.pory"
	clearflag FLAG_JAYDEN_ROUTE106
# 80 "data/maps/Route106/scripts.pory"
	addobject 6
# 81 "data/maps/Route106/scripts.pory"
	playse SE_EXIT
# 82 "data/maps/Route106/scripts.pory"
	applymovement 6, JaydenMoveUp
# 83 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 84 "data/maps/Route106/scripts.pory"
	playse SE_PIN
# 85 "data/maps/Route106/scripts.pory"
	applymovement 6, JaydenGoToPlayer2
# 86 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 87 "data/maps/Route106/scripts.pory"
	msgbox JaydenHiAgain
# 88 "data/maps/Route106/scripts.pory"
	trainerbattle_no_intro TRAINER_JAYDEN_2, JaydenYouGotBetter
# 89 "data/maps/Route106/scripts.pory"
	setvar VAR_JAYDEN_106, 1
# 90 "data/maps/Route106/scripts.pory"
	msgbox PrettyGood
# 91 "data/maps/Route106/scripts.pory"
	giveitem ITEM_VS_SEEKER, 1
# 92 "data/maps/Route106/scripts.pory"
	msgbox Jayden106Outro
# 93 "data/maps/Route106/scripts.pory"
	applymovement 6, JaydenLeave2
# 94 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 95 "data/maps/Route106/scripts.pory"
	setflag FLAG_JAYDEN_ROUTE106
# 96 "data/maps/Route106/scripts.pory"
	removeobject 6
# 97 "data/maps/Route106/scripts.pory"
	release
	end


Jayden1063::
# 103 "data/maps/Route106/scripts.pory"
	lock
# 104 "data/maps/Route106/scripts.pory"
	clearflag FLAG_JAYDEN_ROUTE106
# 105 "data/maps/Route106/scripts.pory"
	addobject 6
# 106 "data/maps/Route106/scripts.pory"
	playse SE_EXIT
# 107 "data/maps/Route106/scripts.pory"
	applymovement 6, JaydenMoveUp2
# 108 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 109 "data/maps/Route106/scripts.pory"
	playse SE_PIN
# 110 "data/maps/Route106/scripts.pory"
	applymovement 6, JaydenGoToPlayer3
# 111 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 112 "data/maps/Route106/scripts.pory"
	msgbox JaydenHiAgain
# 113 "data/maps/Route106/scripts.pory"
	trainerbattle_no_intro TRAINER_JAYDEN_2, JaydenYouGotBetter
# 114 "data/maps/Route106/scripts.pory"
	setvar VAR_JAYDEN_106, 1
# 115 "data/maps/Route106/scripts.pory"
	msgbox PrettyGood
# 116 "data/maps/Route106/scripts.pory"
	giveitem ITEM_VS_SEEKER, 1
# 117 "data/maps/Route106/scripts.pory"
	msgbox Jayden106Outro
# 118 "data/maps/Route106/scripts.pory"
	applymovement 6, JaydenLeave3
# 119 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 120 "data/maps/Route106/scripts.pory"
	setflag FLAG_JAYDEN_ROUTE106
# 121 "data/maps/Route106/scripts.pory"
	removeobject 6
# 122 "data/maps/Route106/scripts.pory"
	release
	end


# 153 "data/maps/Route106/scripts.pory"
JaydenLeave3:
# 154 "data/maps/Route106/scripts.pory"
	walk_up
# 155 "data/maps/Route106/scripts.pory"
	walk_right
# 155 "data/maps/Route106/scripts.pory"
	walk_right
# 155 "data/maps/Route106/scripts.pory"
	walk_right
# 155 "data/maps/Route106/scripts.pory"
	walk_right
# 156 "data/maps/Route106/scripts.pory"
	walk_up
# 156 "data/maps/Route106/scripts.pory"
	walk_up
# 157 "data/maps/Route106/scripts.pory"
	walk_right
# 157 "data/maps/Route106/scripts.pory"
	walk_right
# 157 "data/maps/Route106/scripts.pory"
	walk_right
# 157 "data/maps/Route106/scripts.pory"
	walk_right
# 157 "data/maps/Route106/scripts.pory"
	walk_right
# 157 "data/maps/Route106/scripts.pory"
	walk_right
	step_end

# 160 "data/maps/Route106/scripts.pory"
JaydenLeave2:
# 161 "data/maps/Route106/scripts.pory"
	walk_up
# 162 "data/maps/Route106/scripts.pory"
	walk_right
# 162 "data/maps/Route106/scripts.pory"
	walk_right
# 162 "data/maps/Route106/scripts.pory"
	walk_right
# 162 "data/maps/Route106/scripts.pory"
	walk_right
# 163 "data/maps/Route106/scripts.pory"
	walk_up
# 163 "data/maps/Route106/scripts.pory"
	walk_up
# 164 "data/maps/Route106/scripts.pory"
	walk_right
# 164 "data/maps/Route106/scripts.pory"
	walk_right
# 164 "data/maps/Route106/scripts.pory"
	walk_right
# 164 "data/maps/Route106/scripts.pory"
	walk_right
# 164 "data/maps/Route106/scripts.pory"
	walk_right
	step_end

# 167 "data/maps/Route106/scripts.pory"
JaydenLeave1:
# 168 "data/maps/Route106/scripts.pory"
	walk_down
# 169 "data/maps/Route106/scripts.pory"
	walk_right
# 169 "data/maps/Route106/scripts.pory"
	walk_right
# 169 "data/maps/Route106/scripts.pory"
	walk_right
# 169 "data/maps/Route106/scripts.pory"
	walk_right
# 170 "data/maps/Route106/scripts.pory"
	walk_up
# 170 "data/maps/Route106/scripts.pory"
	walk_up
# 171 "data/maps/Route106/scripts.pory"
	walk_right
# 171 "data/maps/Route106/scripts.pory"
	walk_right
# 171 "data/maps/Route106/scripts.pory"
	walk_right
# 171 "data/maps/Route106/scripts.pory"
	walk_right
# 171 "data/maps/Route106/scripts.pory"
	walk_right
# 171 "data/maps/Route106/scripts.pory"
	walk_right
	step_end

# 174 "data/maps/Route106/scripts.pory"
JaydenGoToPlayer3:
# 175 "data/maps/Route106/scripts.pory"
	emote_exclamation_mark
# 176 "data/maps/Route106/scripts.pory"
	delay_16
# 177 "data/maps/Route106/scripts.pory"
	delay_16
# 178 "data/maps/Route106/scripts.pory"
	delay_16
# 179 "data/maps/Route106/scripts.pory"
	walk_down
# 179 "data/maps/Route106/scripts.pory"
	walk_down
# 180 "data/maps/Route106/scripts.pory"
	walk_right
	step_end

# 183 "data/maps/Route106/scripts.pory"
JaydenGoToPlayer2:
# 184 "data/maps/Route106/scripts.pory"
	emote_exclamation_mark
# 185 "data/maps/Route106/scripts.pory"
	delay_16
# 186 "data/maps/Route106/scripts.pory"
	delay_16
# 187 "data/maps/Route106/scripts.pory"
	delay_16
# 188 "data/maps/Route106/scripts.pory"
	walk_down
# 189 "data/maps/Route106/scripts.pory"
	walk_right
	step_end

# 192 "data/maps/Route106/scripts.pory"
JaydenGoToPlayer1:
# 193 "data/maps/Route106/scripts.pory"
	emote_exclamation_mark
# 194 "data/maps/Route106/scripts.pory"
	delay_16
# 195 "data/maps/Route106/scripts.pory"
	delay_16
# 196 "data/maps/Route106/scripts.pory"
	delay_16
# 197 "data/maps/Route106/scripts.pory"
	walk_right
	step_end

# 200 "data/maps/Route106/scripts.pory"
JaydenMoveUp:
# 201 "data/maps/Route106/scripts.pory"
	walk_down
# 202 "data/maps/Route106/scripts.pory"
	delay_16
# 203 "data/maps/Route106/scripts.pory"
	delay_16
# 204 "data/maps/Route106/scripts.pory"
	face_right
	step_end

# 207 "data/maps/Route106/scripts.pory"
JaydenMoveUp2:
# 208 "data/maps/Route106/scripts.pory"
	walk_down
# 209 "data/maps/Route106/scripts.pory"
	delay_16
# 210 "data/maps/Route106/scripts.pory"
	delay_16
	step_end

Jayden106Outro::
# 126 "data/maps/Route106/scripts.pory"
	.string "Once it charges, use it to rematch any\n"
	.string "trainer you fought!\p"
	.string "Anyways though, I'll catch ya later\n"
	.string "{PLAYER}.$"

PrettyGood::
# 133 "data/maps/Route106/scripts.pory"
	.string "Alright well I'm planning on going to\n"
	.string "Mauville City for my third badge.\p"
	.string "But before I go, I got a cool item you\n"
	.string "might like {PLAYER}.$"

JaydenYouGotBetter::
# 140 "data/maps/Route106/scripts.pory"
	.string "Ouch, yeah okay, you definitely got\n"
	.string "better too.$"

JaydenHiAgain::
# 145 "data/maps/Route106/scripts.pory"
	.string "Oh hey, it's you again!\p"
	.string "Since our last battle I've gotten some\n"
	.string "more Pokémon and my second badge.\p"
	.string "Hey, let's battle and see how much we\n"
	.string "improved.$"
