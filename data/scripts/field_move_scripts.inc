@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	checkitem ITEM_MATTOCK, 1
	compare VAR_RESULT, 0
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	msgbox Text_PlayerUsedMattock, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
EventScript_CutTreeCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
EventScript_CutTreeDown:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	goto EventScript_CutTreeCommon

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_PlayerUsedMattock:
	.string "{PLAYER} used the Mattock!$"

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "cut down!$"

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	goto EventScript_RockSmashCommon

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	checkitem ITEM_MATTOCK, 1
	compare VAR_RESULT, 0
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	msgbox Text_PlayerUsedMattockSmash, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
EventScript_RockSmashCommon:
	@ check if follower should use the field move
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
EventScript_SmashRock:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_FollowerFieldMove:
	getdirectiontoface VAR_0x8005, OBJ_EVENT_ID_FOLLOWER, OBJ_EVENT_ID_PLAYER
	specialvar VAR_0x8006, GetPlayerFacingDirection
	goto_if_eq VAR_0x8005, DIR_NONE, EventScript_FollowerFieldMoveEnd
	@ Swap follower and player
	call EventScript_FollowerSwap
	@ Face follower in direction and jump
	switch VAR_0x8006
	case DIR_NORTH, EventScript_FollowerJumpNorth
	case DIR_EAST, EventScript_FollowerJumpEast
	case DIR_SOUTH, EventScript_FollowerJumpSouth
	case DIR_WEST, EventScript_FollowerJumpWest
EventScript_FollowerFieldMoveEnd:
	return

EventScript_FollowerSwap:
	switch VAR_0x8005
	case DIR_NORTH, EventScript_FollowerMoveNorth
	case DIR_EAST, EventScript_FollowerMoveEast
	case DIR_SOUTH, EventScript_FollowerMoveSouth
	case DIR_WEST, EventScript_FollowerMoveWest
	return

EventScript_FollowerMoveNorth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

EventScript_FollowerMoveEast:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

EventScript_FollowerMoveSouth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return

EventScript_FollowerMoveWest:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

EventScript_FollowerJumpNorth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
	waitmovement 0
	return

EventScript_FollowerJumpEast:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
	waitmovement 0
	return

EventScript_FollowerJumpSouth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
	waitmovement 0
	return

EventScript_FollowerJumpWest:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
	waitmovement 0
	return

EventScript_EndSmash::
	releaseall
	end

Movement_WalkUp:
	walk_up
	step_end

Movement_JumpUp:
	jump_in_place_up
	step_end

Movement_WalkRight:
	walk_right
	step_end

Movement_JumpRight:
	jump_in_place_right
	step_end

Movement_WalkDown:
	walk_down
	step_end

Movement_JumpDown:
	jump_in_place_down
	step_end

Movement_WalkLeft:
	walk_left
	step_end

Movement_JumpLeft:
	jump_in_place_left
	step_end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_CantSmash:
	.string "It's a rugged rock, but a\n"
	.string "sharp tool would smash it.$"

Text_PlayerUsedMattockSmash:
	.string "{PLAYER} used the Mattock!$"	

EventScript_StrengthBoulder::
	lockall
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkitem ITEM_GAINZ, 1
	goto_if_eq VAR_RESULT, 0, EventScript_CantStrength
	msgbox Text_PlayerUsedGainz, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_CantStrength:
	.string "It's a big boulder, but its too heavy\n"
	.string "to push it aside.$"

Text_StrengthActivated:
	.string "Its now possible to move boulders\n"
	.string "around.$"
	
Text_PlayerUsedGainz:
	.string "{PLAYER} used Gain-Z!$"

EventScript_UseWaterfall::
	lockall
	msgbox Text_PlayerUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	callnative FollowerNPC_WarpSetEnd
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_PlayerUsedWaterfall:
	.string "{PLAYER} climbed the waterfall!$"
	
EventScript_DiveSpot::
	lockall
	checkitem ITEM_SCUBA_GEAR, 1
	goto_if_eq VAR_RESULT, 0, EventScript_CantDive
	msgbox Text_PlayerUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_UseDive::
	lockall
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkitem ITEM_SCUBA_GEAR, 1
	goto_if_eq VAR_RESULT, 0, EventScript_CantSurface
	msgbox Text_Surfaced, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	callnative SetFollowerNPCSurfSpriteAfterDive
EventScript_NoSurface::
	releaseall
	end

EventScript_DigCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_DIG
	waitstate
EventScript_DigSealedChamber:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	callnative DoBrailleDigEffect
	releaseall
	end

@ Use Dig from party menu
EventScript_UseDig::
	lockall
	goto EventScript_DigCommon

@ Interact with a tree a Pokémon can use headbutt on
EventScript_Headbutt::
	lockall
	checkpartymove MOVE_HEADBUTT
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CantHeadbuttTree
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_HEADBUTT
	msgbox Text_WantToHeadbutt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelHeadbutt
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_HEADBUTT
	waitstate
	goto EventScript_HeadbuttTree
	end

EventScript_CantHeadbuttTree::
	msgbox Text_CantHeadbuttTree, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelHeadbutt::
	closemessage
	releaseall
	end

@ Use headbutt from party menu
EventScript_UseHeadbutt::
	lockall
	dofieldeffect FLDEFF_USE_HEADBUTT
	waitstate
EventScript_HeadbuttTree:
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	special HeadbuttWildEncounter
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_EndHeadbutt
	waitstate
EventScript_EndHeadbutt:
	releaseall
	end


EventScript_CutGrassCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
	waitstate

@ Use Cut grass from party menu
EventScript_UseCutGrass::
	lockall
	goto EventScript_CutGrassCommon

Text_CantDive:
	.string "The sea is deep here. With\n"
	.string "scuba gear I could go underwater.$"

Text_PlayerUsedDive:
	.string "{PLAYER} put on the Scuba Gear!$"
	
Text_Surfaced:
	.string "{PLAYER} surfaced!$"

Text_CantSurface:
	.string "Light is filtering down from above.$"

Text_WantToHeadbutt:
	.string "It sounds like a Pokémon\n"
	.string "might be up in this tree!\p"
	.string "Would you like to use Headbutt\n"
	.string "to shake it loose?$"

Text_CantHeadbuttTree:
	.string "It sounds like a Pokémon\n"
	.string "might be up in this tree!\p"
	.string "I wonder how I can shake it loose…$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"

Text_MonUsedFieldMove: @ 8290771
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

@ Interact with cliffside

EventScript_CliffSpot::
	lockall
	checkitem ITEM_JETPACK, 1
	goto_if_eq VAR_RESULT, 0, EventScript_CantCliff
	msgbox Text_PlayerUsedCliff, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_CLIFF
	goto EventScript_EndCliff
	end

EventScript_UseCliff::
	lockall
	dofieldeffect FLDEFF_USE_CLIFF
	goto EventScript_EndCliff
	end

EventScript_CantCliff::
	msgbox Text_CantCliff, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndCliff::
	releaseall
	end

EventScript_UseCliffTop::
	lockall
	checkitem ITEM_JETPACK, 1
	msgbox Text_Return, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_ReturnToRoute
	compare VAR_RESULT, NO
	goto_if_eq EventScript_StayOnCliff
	end

EventScript_ReturnToRoute::
	lockall
	msgbox Text_Returned, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_CLIFF
	goto EventScript_EndLanded
	end

EventScript_StayOnCliff::
	lockall
	msgbox Text_DontReturn, MSGBOX_DEFAULT
	goto EventScript_EndLanded
	end

EventScript_EndLanded::
	releaseall
	end

Text_Return:
	.string "Do you want to descend\n"
	.string "down the cliffside?$"

Text_CantCliff:
	.string "I think I see something at the\n"
	.string "top of this cliff…\p"
	.string "I wonder how I get up there…$"

Text_PlayerUsedCliff:
	.string "{PLAYER} put on the Jetpack!$"

Text_Returned:
	.string "{PLAYER} used the Jetpack to\n"
	.string "safely descend the cliff!$"

Text_DontReturn:
	.string "{PLAYER} decided to stay\n"
	.string "on the cliff landing.$"

EventScript_UseDefog::
	lockall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_DEFOG
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	waitmovement 0
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_DEFOG
	waitstate
	releaseall
	end
