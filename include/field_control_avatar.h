#ifndef GUARD_FIELDCONTROLAVATAR_H
#define GUARD_FIELDCONTROLAVATAR_H

struct FieldInput
{
    bool8 pressedAButton:1;
    bool8 checkStandardWildEncounter:1;
    bool8 pressedStartButton:1;
    bool8 pressedSelectButton:1;
    bool8 heldDirection:1;
    bool8 heldDirection2:1;
    bool8 tookStep:1;
    bool8 pressedBButton:1;
    bool8 pressedRButton:1;
    bool8 pressedListButton:1; //related to Xaman registered list
    bool8 input_field_1_1:1;
    bool8 input_field_1_2:1;
    bool8 input_field_1_3:1;
    bool8 input_field_1_4:1;
    bool8 input_field_1_5:1;
    bool8 input_field_1_6:1;
    bool8 input_field_1_7:1;
    u8 dpadDirection;
};

void FieldClearPlayerInput(struct FieldInput *pStruct);
void FieldGetPlayerInput(struct FieldInput *pStruct, u16 keys, u16 heldKeys);
int ProcessPlayerFieldInput(struct FieldInput *pStruct);
void RestartWildEncounterImmunitySteps(void);
const u8 *GetObjectEventScriptPointerPlayerFacing(void);
bool8 TryDoDiveWarp(struct MapPosition *position, u16 metatileBehavior);
bool8 TryDoCliffWarp(struct MapPosition *position, u16 b);
int SetCableClubWarp(void);
u8 TrySetDiveWarp(void);
u8 TrySetCliffWarp(void);
const u8 *GetInteractedLinkPlayerScript(struct MapPosition *position, u8 metatileBehavior, u8 direction);
const u8 *GetCoordEventScriptAtMapPosition(struct MapPosition *position);
void ClearPoisonStepCounter(void);
void CancelSignPostMessageBox(struct FieldInput *input);

#define NOT_SIGNPOST 0
#define WALK_AWAY_SIGNPOST_FRAMES 6

#endif // GUARD_FIELDCONTROLAVATAR_H
