#ifndef GUARD_MAIN_MENU_H
#define GUARD_MAIN_MENU_H

void CB2_InitMainMenu(void);
void CreateYesNoMenuParameterized(u8 x, u8 y, u16 baseTileNum, u16 baseBlock, u8 yesNoPalNum, u8 winPalNum);
void CB2_NewGameBirchSpeech_ReturnFromTxRandomizerChallengesOptions(void);
void NewGameBirchSpeech_SetDefaultPlayerName(u8);
void CB2_ReinitMainMenu(void);

#endif // GUARD_MAIN_MENU_H
