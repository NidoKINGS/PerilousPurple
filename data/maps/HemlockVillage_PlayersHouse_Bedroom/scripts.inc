HemlockVillage_PlayersHouse_Bedroom_MapScripts::
# 4 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, HemlockVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 10 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HemlockVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

HemlockVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	setflag FLAG_HIDE_MOM
# 6 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
# 7 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	setobjectxyperm 1, 4, 7
	return

HemlockVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	map_script_2 VAR_HEMLOCKVILLAGE_INTRO_STATE, 0, HemlockVillage_PlayersHouse_Bedroom_OnFrame_PlayerWakeUp
	.2byte 0


HemlockVillage_PlayersHouse_Bedroom_OnFrame_PlayerWakeUp::
# 24 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	lockall
# 25 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	setspeaker HemlockVillage_PlayersHouse_Bedroom_OnFrame_PlayerWakeUp_Text_0
# 26 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	msgbox HemlockVillage_PlayersHouse_Bedroom_OnFrame_PlayerWakeUp_Text_1
# 27 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	clearflag FLAG_HIDE_MOM
# 28 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	playse SE_DOOR
# 29 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	delay 10
# 30 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	goto HemlockVillage_PlayersHouse_Bedroom_MomTalks
	return


HemlockVillage_PlayersHouse_Bedroom_MomTalks::
# 34 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	addobject 1
# 35 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	applymovement 1, Mom_MovementToPlayer
# 36 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	waitmovement
# 37 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Player_TurnToMom
# 38 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	waitmovement
# 39 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	setspeaker HemlockVillage_PlayersHouse_Bedroom_MomTalks_Text_0
# 40 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	msgbox HemlockVillage_PlayersHouse_Bedroom_MomTalks_Text_1
# 41 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	waitmessage
# 42 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	applymovement 1, Mom_MovementToDoor
# 43 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	waitmovement
# 44 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	playse SE_DOOR
# 45 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	delay 10
# 46 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	setflag FLAG_HIDE_MOM
# 47 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	removeobject 1
# 48 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	setvar VAR_HEMLOCKVILLAGE_INTRO_STATE, 1
# 49 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	releaseall
	return


# 52 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
Mom_MovementToPlayer:
# 53 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_fast_up
# 53 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_fast_up
# 53 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_fast_up
# 53 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_fast_up
# 53 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_fast_up
# 54 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	face_right
# 55 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_fast_right
# 55 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_fast_right
# 56 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	step_end

# 59 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
Player_TurnToMom:
# 60 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	face_left
# 61 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	step_end

# 64 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
Mom_MovementToDoor:
# 65 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	face_left
# 66 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_faster_left
# 66 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_faster_left
# 67 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	face_down
# 68 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_faster_down
# 68 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_faster_down
# 68 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_faster_down
# 68 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_faster_down
# 68 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	walk_faster_down
# 69 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	step_end

OpenDresser::
# 73 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	lockall
# 74 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	setspeaker OpenDresser_Text_0
# 75 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	msgbox OpenDresser_Text_1
# 76 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	closemessage
# 77 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 78 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	callnative Script_OpenOutfitMenu
# 79 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	waitstate
# 80 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	releaseall
	end


HemlockVillage_PlayersHouse_Bedroom_OnFrame_PlayerWakeUp_Text_0:
# 25 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	.string "???$"

HemlockVillage_PlayersHouse_Bedroom_OnFrame_PlayerWakeUp_Text_1:
# 26 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	.string "Knock, knock! Are you almost ready?$"

HemlockVillage_PlayersHouse_Bedroom_MomTalks_Text_0:
# 39 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	.string "Mom$"

HemlockVillage_PlayersHouse_Bedroom_MomTalks_Text_1:
# 40 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	.string "{PLAYER}, you must have slept\n"
	.string "through your alarm, it's after 8:30…\l"
	.string "You're going to be late, Professor\l"
	.string "Halesia will be extremely disappointed.\l"
	.string "Get dressed now and get your behind\l"
	.string "downstairs.$"

OpenDresser_Text_0:
# 74 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	.string "Self$"

OpenDresser_Text_1:
# 75 "data/maps/HemlockVillage_PlayersHouse_Bedroom/scripts.pory"
	.string "Hmmm, what should I wear?$"
