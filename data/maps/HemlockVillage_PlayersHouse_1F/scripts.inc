HemlockVillage_PlayersHouse_1F_MapScripts::
	.byte 0


HemlockVillage_PlayersHouse_1F_EventScript_Mom_Introduction::
# 6 "data/maps/HemlockVillage_PlayersHouse_1F/scripts.pory"
	lockall
# 7 "data/maps/HemlockVillage_PlayersHouse_1F/scripts.pory"
	faceplayer
# 8 "data/maps/HemlockVillage_PlayersHouse_1F/scripts.pory"
	setspeaker HemlockVillage_PlayersHouse_1F_EventScript_Mom_Introduction_Text_0
# 9 "data/maps/HemlockVillage_PlayersHouse_1F/scripts.pory"
	msgbox HemlockVillage_PlayersHouse_1F_EventScript_Mom_Introduction_Text_1
# 10 "data/maps/HemlockVillage_PlayersHouse_1F/scripts.pory"
	releaseall
	return


HemlockVillage_PlayersHouse_1F_EventScript_Mom_Introduction_Text_0:
# 8 "data/maps/HemlockVillage_PlayersHouse_1F/scripts.pory"
	.string "Mother$"

HemlockVillage_PlayersHouse_1F_EventScript_Mom_Introduction_Text_1:
# 9 "data/maps/HemlockVillage_PlayersHouse_1F/scripts.pory"
	.string "Hello there, {PLAYER}!$"
