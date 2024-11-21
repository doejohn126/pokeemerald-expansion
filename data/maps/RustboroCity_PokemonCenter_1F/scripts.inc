# 1 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_MapScripts::
# 5 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
# 6 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_OnTransition:
# 10 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
# 11 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 12 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 13 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 14 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_EventScript_Nurse::
# 15 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 16 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 17 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 18 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 19 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
# 20 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 21 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 22 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_EventScript_Man::
# 23 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
# 24 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 25 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 26 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_EventScript_Boy::
# 27 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
# 28 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 29 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 30 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_EventScript_Girl::
# 31 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
# 32 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 33 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 34 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
# 35 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "My POKéMON has a NAIVE nature, and my\n"
# 36 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "friend's has a JOLLY nature.\p"
# 37 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "It's fascinating how POKéMON have\n"
# 38 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "personalities!$"
# 39 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 40 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
# 41 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "Just like people, there are male and\n"
# 42 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "female POKéMON.\p"
# 43 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "But no one seems to have any idea how\n"
# 44 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "they're different.$"
# 45 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 46 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
# 47 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "The man next door gave me an HM!\p"
# 48 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "I used it to teach my POKéMON how to\n"
# 49 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "CUT down skinny trees.$"

ImDoneWithThis::
# 55 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	lock
# 56 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 57 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_CANDY_JAR, MightMissIt
# 58 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox NoMoreAddiction
# 59 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_SWEETSCENT_TOOL
# 60 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	setflag FLAG_CANDY_JAR
# 61 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
	end


MightMissIt::
# 66 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox HopeNot
# 67 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
	end


SkyKid::
# 72 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	lock
# 73 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 74 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	goto_if_defeated TRAINER_SKY_KID, WSkyBattle
# 75 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox XpKidReturns, MSGBOX_YESNO
SkyKid_2:
# 76 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SkyKid_3
# 79 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox GoodSeeingYou
# 80 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
	end

SkyKid_3:
# 77 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	goto TryDoSkybattle
	goto SkyKid_2


TryDoSkybattle::
# 85 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	special TrySkyBattle
# 86 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
# 87 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq VsSkyKid1
# 88 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox WrongMons
# 89 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
	end


VsSkyKid1::
# 94 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox LetsFrickingGo
# 95 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_SKY_KID, CrapILost
# 96 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox AlrightYouEarned
# 97 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_EXP_CANDY_S, 10
# 98 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
	end


WSkyBattle::
# 103 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	goto_if_defeated TRAINER_SKY_KID_2, LetsRematchOnceAgain
# 104 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, TryDoSkybattle2
# 105 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox Woohoo
# 106 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
	end


LetsRematchOnceAgain::
# 111 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox BeatNorman
# 112 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
	end


TryDoSkybattle2::
# 117 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	special TrySkyBattle
# 118 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
# 119 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq skykidrematch
# 120 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox WrongMons
# 121 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
	end


skykidrematch::
# 126 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox NiceBadges
# 127 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_SKY_KID_2, DangIt
# 128 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox AlrightYouEarned
# 129 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_EXP_CANDY_S, 10
# 130 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_EXP_CANDY_M, 3
# 131 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
	end


HopeNot::
# 135 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "Oh no. I'm already missing my candy.\n"
	.string "Whatever it's too late I'm done with\l"
	.string "candy until next year!$"

NoMoreAddiction::
# 141 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "Oww... my teeth..\n"
	.string "Alright that's it I'm done with this!\p"
	.string "I'm about sick and tired of my candy\n"
	.string "addiction!\p"
	.string "Get rid of this for me please.$"

BeatNorman::
# 149 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "how about we rematch once again once u\n"
	.string "beat norman$"

DangIt::
# 154 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "dam it$"

NiceBadges::
# 158 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "woaa those are some nice badges there\n"
	.string "brody.\p"
	.string "as you can see ive been training too so\n"
	.string "i think its time for our first rematch\p"
	.string "devs yall arleady know what song to play$"

Woohoo::
# 166 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "ngl that was a w sky battle$"

AlrightYouEarned::
# 170 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "alright a deals a deal here you go\n"
	.string "also lets rematch again once u get more\l"
	.string "badges$"

CrapILost::
# 176 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "ah shoot$"

WrongMons::
# 180 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "wait nope u got the wrong mons brody\n"
	.string "id say bring some flying or levitating mons$"

LetsFrickingGo::
# 185 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "alright lets get this show on the road\n"
	.string "Oh also devs give me that sick frontier\l"
	.string "song pretty please$"

GoodSeeingYou::
# 191 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "dang ok then good seeing you again tho\n"
	.string "bro$"

XpKidReturns::
# 196 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "woah hey howve you been bru!!!\n"
	.string "its me xp kid you remember me!!!??\p"
	.string "but im retired from being the xp kid now\n"
	.string "and been testing with sky battles\l"
	.string "since i was missing\p"
	.string "carrying those chanseys and blisseys\n"
	.string "got pretty annoying so now i only carry\l"
	.string "around xp candies\p"
	.string "hey if you want some how about we do a\n"
	.string "sky battle for some?$"
