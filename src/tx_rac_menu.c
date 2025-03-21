#include "global.h"
#include "main.h"
#include "menu.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sprite.h"
#include "sound.h"
#include "task.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "strings.h"
#include "string_util.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"
#include "battle_main.h"
#include "tx_randomizer_and_challenges.h"
#include "pokemon.h"
#include "constants/songs.h"

enum
{
    MENU_RANDOMIZER,
    MENU_NUZLOCKE,
    MENU_DIFFICULTY,
    MENU_CHALLENGES,
    MENU_COUNT,
};

// Menu items
enum
{
    MENUITEM_RANDOM_OFF_ON,
    MENUITEM_RANDOM_STARTER,
    MENUITEM_RANDOM_WILD_PKMN,
    MENUITEM_RANDOM_TRAINER,
    MENUITEM_RANDOM_STATIC,
    MENUITEM_RANDOM_SIMILAR_EVOLUTION_LEVEL,
    MENUITEM_RANDOM_INCLUDE_LEGENDARIES,
    MENUITEM_RANDOM_TYPE,
    MENUITEM_RANDOM_MOVES,
    MENUITEM_RANDOM_ABILITIES,
    MENUITEM_RANDOM_EVOLUTIONS,
    MENUITEM_RANDOM_EVOLUTIONS_METHODS,
    MENUITEM_RANDOM_TYPE_EFFEC,
    MENUITEM_RANDOM_ITEMS,
    MENUITEM_RANDOM_CHAOS,
    MENUITEM_RANDOM_NEXT,
    MENUITEM_RANDOM_COUNT,
};

enum
{
    MENUITEM_NUZLOCKE_NUZLOCKE,
    MENUITEM_NUZLOCKE_SPECIES_CLAUSE,
    MENUITEM_NUZLOCKE_SHINY_CLAUSE,
    MENUITEM_NUZLOCKE_NICKNAMING,
    MENUITEM_NUZLOCKE_DELETION,
    MENUITEM_NUZLOCKE_NEXT,
    MENUITEM_NUZLOCKE_COUNT,
};

enum
{
    MENUITEM_DIFFICULTY_PARTY_LIMIT,
    MENUITEM_DIFFICULTY_LEVEL_CAP,
    MENUITEM_DIFFICULTY_EXP_MULTIPLIER,
    MENUITEM_DIFFICULTY_ITEM_PLAYER,
    MENUITEM_DIFFICULTY_ITEM_TRAINER,
    MENUITEM_DIFFICULTY_NO_EVS,
    MENUITEM_DIFFICULTY_SCALING_IVS,
    MENUITEM_DIFFICULTY_SCALING_EVS,
    MENUITEM_DIFFICULTY_POKECENTER,
    MENUITEM_DIFFICULTY_NEXT,
    MENUITEM_DIFFICULTY_COUNT,
};

enum
{
    MENUITEM_CHALLENGES_EVO_LIMIT,
    MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE,
    MENUITEM_CHALLENGES_BASE_STAT_EQUALIZER,
    MENUITEM_CHALLENGES_MIRROR,
    MENUITEM_CHALLENGES_MIRROR_THIEF,
    MENUITEM_CHALLENGES_SAVE,
    MENUITEM_CHALLENGES_COUNT,
};

// Window Ids
enum
{
    WIN_TOPBAR,
    WIN_OPTIONS,
    WIN_DESCRIPTION
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    {//WIN_TOPBAR
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    {//WIN_OPTIONS
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 62
    },
    {//WIN_DESCRIPTION
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 500
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
    {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
    },
    {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
    },
};

struct OptionMenu
{
    u8 submenu;
    u8 sel_randomizer[MENUITEM_RANDOM_COUNT];
    u8 sel_nuzlocke[MENUITEM_NUZLOCKE_COUNT];
    u8 sel_difficulty[MENUITEM_DIFFICULTY_COUNT];
    u8 sel_challenges[MENUITEM_CHALLENGES_COUNT];
    int menuCursor[MENU_COUNT];
    int visibleCursor[MENU_COUNT];
    u8 arrowTaskId;
};

#define Y_DIFF 16 // Difference in pixels between items.
#define OPTIONS_ON_SCREEN 5
#define NUM_OPTIONS_FROM_BORDER 1

// local functions
static void MainCB2(void);
static void VBlankCB(void);
static void DrawTopBarText(void); //top Option text
static void DrawLeftSideOptionText(int selection, int y);
static void DrawRightSideChoiceText(const u8 *str, int x, int y, bool8 choosen, bool8 active);
static void DrawOptionMenuTexts(void); //left side text;
static void DrawChoices(u32 id, int y); //right side draw function
static void HighlightOptionMenuItem(void);
static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_RandomizerChallengesMenuSave(u8 taskId);
static void Task_RandomizerChallengesMenuFadeOut(u8 taskId);
static void ScrollMenu(int direction);
static void ScrollAll(int direction); // to bottom or top
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3);
static int XOptions_ProcessInput(int x, int selection);
static int ProcessInput_Options_Two(int selection);
static int ProcessInput_Options_Three(int selection);
static int ProcessInput_Options_Four(int selection);
static int ProcessInput_Options_Six(int selection);
//static int ProcessInput_Options_Eleven(int selection);
static int ProcessInput_Options_OneTypeChallenge(int selection);
//static int ProcessInput_Sound(int selection);
//static int ProcessInput_FrameType(int selection);
static const u8 *const OptionTextDescription(void);
static const u8 *const OptionTextRight(u8 menuItem);
static u8 MenuItemCount(void);
#ifndef NDEBUG
static u8 MenuItemCountFromIndex(u8 index);
#endif
static u8 MenuItemCancel(void);
static void DrawDescriptionText(void);
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active);
static void DrawChoices_Options_Four(const u8 *const *const strings, int selection, int y, bool8 active);
static void ReDrawAll(void);
static void DrawBgWindowFrames(void);

static void DrawChoices_Random_OffOn(int selection, int y, bool8 active);
static void DrawChoices_Random_OffRandom(int selection, int y, bool8 active);
static void DrawChoices_Random_Toggle(int selection, int y);
static void DrawChoices_Random_Starter(int selection, int y);
static void DrawChoices_Random_WildPkmn(int selection, int y);
static void DrawChoices_Random_Trainer(int selection, int y);
static void DrawChoices_Random_Static(int selection, int y);
static void DrawChoices_Random_EvoStages(int selection, int y);
static void DrawChoices_Random_Legendaries(int selection, int y);
static void DrawChoices_Random_Types(int selection, int y);
static void DrawChoices_Random_Moves(int selection, int y);
static void DrawChoices_Random_Abilities(int selection, int y);
static void DrawChoices_Random_Evolutions(int selection, int y);
static void DrawChoices_Random_EvolutionMethods(int selection, int y);
static void DrawChoices_Random_TypeEffect(int selection, int y);
static void DrawChoices_Random_Items(int selection, int y);
static void DrawChoices_Random_OffChaos(int selection, int y);

static void DrawChoices_Nuzlocke_OnOff(int selection, int y, bool8 active);
static void DrawChoices_Challenges_Nuzlocke(int selection, int y);
static void DrawChoices_Nuzlocke_SpeciesClause(int selection, int y);
static void DrawChoices_Nuzlocke_ShinyClause(int selection, int y);
static void DrawChoices_Nuzlocke_Nicknaming(int selection, int y);
static void DrawChoices_Nuzlocke_Deletion(int selection, int y);

static void DrawChoices_Challenges_PartyLimit(int selection, int y);
static void DrawChoices_Challenges_LevelCap(int selection, int y);
static void DrawChoices_Challenges_ExpMultiplier(int selection, int y);
static void DrawChoices_Challenges_YesNo(int selection, int y, bool8 active);
static void DrawChoices_Challenges_ItemsPlayer(int selection, int y);
static void DrawChoices_Challenges_ItemsTrainer(int selection, int y);
static void DrawChoices_Challenges_NoEVs(int selection, int y);
static void DrawChoices_Challenges_ScalingIVs(int selection, int y);
static void DrawChoices_Challenges_ScalingEVs(int selection, int y);
static void DrawChoices_Challenges_Pokecenters(int selection, int y);

static void DrawChoices_Challenges_EvoLimit(int selection, int y);
static void DrawChoices_Challenges_OneTypeChallenge(int selection, int y);
static void DrawChoices_Challenges_BaseStatEqualizer(int selection, int y);
static void DrawChoices_Challenges_Mirror(int selection, int y);
static void DrawChoices_Challenges_Mirror_Thief(int selection, int y);

#ifndef NDEBUG
static void PrintCurrentSelections(void);
#endif

// EWRAM vars
EWRAM_DATA static struct OptionMenu *sOptions = NULL;

// const data
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp"); // note: this is only used in the Japanese release
static const u16 sOptionMenuBg_Pal[] = {RGB(17, 18, 31)};
static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");

#define TEXT_COLOR_OPTIONS_WHITE                1
#define TEXT_COLOR_OPTIONS_GRAY_FG              2
#define TEXT_COLOR_OPTIONS_GRAY_SHADOW          3
#define TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG        4
#define TEXT_COLOR_OPTIONS_ORANGE_FG            5
#define TEXT_COLOR_OPTIONS_ORANGE_SHADOW        6
#define TEXT_COLOR_OPTIONS_RED_FG               7
#define TEXT_COLOR_OPTIONS_RED_SHADOW           8
#define TEXT_COLOR_OPTIONS_GREEN_FG             9
#define TEXT_COLOR_OPTIONS_GREEN_SHADOW         10
#define TEXT_COLOR_OPTIONS_GREEN_DARK_FG        11
#define TEXT_COLOR_OPTIONS_GREEN_DARK_SHADOW    12
#define TEXT_COLOR_OPTIONS_RED_DARK_FG          13
#define TEXT_COLOR_OPTIONS_RED_DARK_SHADOW      14

// Menu draw and input functions
struct // MENU_RANDOMIZER
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsRandom[MENUITEM_RANDOM_COUNT] =
{
    [MENUITEM_RANDOM_OFF_ON]                    = {DrawChoices_Random_Toggle,           ProcessInput_Options_Two},
    [MENUITEM_RANDOM_STARTER]                   = {DrawChoices_Random_Starter,          ProcessInput_Options_Three},
    [MENUITEM_RANDOM_WILD_PKMN]                 = {DrawChoices_Random_WildPkmn,         ProcessInput_Options_Two},
    [MENUITEM_RANDOM_TRAINER]                   = {DrawChoices_Random_Trainer,          ProcessInput_Options_Two},
    [MENUITEM_RANDOM_STATIC]                    = {DrawChoices_Random_Static,           ProcessInput_Options_Two},
    [MENUITEM_RANDOM_SIMILAR_EVOLUTION_LEVEL]   = {DrawChoices_Random_EvoStages,        ProcessInput_Options_Two},
    [MENUITEM_RANDOM_INCLUDE_LEGENDARIES]       = {DrawChoices_Random_Legendaries,      ProcessInput_Options_Two},
    [MENUITEM_RANDOM_TYPE]                      = {DrawChoices_Random_Types,            ProcessInput_Options_Two},
    [MENUITEM_RANDOM_MOVES]                     = {DrawChoices_Random_Moves,            ProcessInput_Options_Two},
    [MENUITEM_RANDOM_ABILITIES]                 = {DrawChoices_Random_Abilities,        ProcessInput_Options_Two},
    [MENUITEM_RANDOM_EVOLUTIONS]                = {DrawChoices_Random_Evolutions,       ProcessInput_Options_Two},
    [MENUITEM_RANDOM_EVOLUTIONS_METHODS]        = {DrawChoices_Random_EvolutionMethods, ProcessInput_Options_Two},
    [MENUITEM_RANDOM_TYPE_EFFEC]                = {DrawChoices_Random_TypeEffect,       ProcessInput_Options_Two},
    [MENUITEM_RANDOM_ITEMS]                     = {DrawChoices_Random_Items,            ProcessInput_Options_Two},
    [MENUITEM_RANDOM_CHAOS]                     = {DrawChoices_Random_OffChaos,         ProcessInput_Options_Two},
    [MENUITEM_RANDOM_NEXT]                      = {NULL, NULL},
};

struct // MENU_NUZLOCKE
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsNuzlocke[MENUITEM_NUZLOCKE_COUNT] =
{
    [MENUITEM_NUZLOCKE_NUZLOCKE]        = {DrawChoices_Challenges_Nuzlocke,     ProcessInput_Options_Three},
    [MENUITEM_NUZLOCKE_SPECIES_CLAUSE]  = {DrawChoices_Nuzlocke_SpeciesClause,  ProcessInput_Options_Two},
    [MENUITEM_NUZLOCKE_SHINY_CLAUSE]    = {DrawChoices_Nuzlocke_ShinyClause,    ProcessInput_Options_Two},
    [MENUITEM_NUZLOCKE_NICKNAMING]      = {DrawChoices_Nuzlocke_Nicknaming,     ProcessInput_Options_Two},
    [MENUITEM_NUZLOCKE_DELETION]        = {DrawChoices_Nuzlocke_Deletion,       ProcessInput_Options_Two},
    [MENUITEM_NUZLOCKE_NEXT]            = {NULL, NULL},
};

struct // MENU_DIFFICULTY
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsDifficulty[MENUITEM_DIFFICULTY_COUNT] =
{
    [MENUITEM_DIFFICULTY_PARTY_LIMIT]           = {DrawChoices_Challenges_PartyLimit,       ProcessInput_Options_Six},
    [MENUITEM_DIFFICULTY_LEVEL_CAP]             = {DrawChoices_Challenges_LevelCap,         ProcessInput_Options_Three},
    [MENUITEM_DIFFICULTY_EXP_MULTIPLIER]        = {DrawChoices_Challenges_ExpMultiplier,    ProcessInput_Options_Four},
    [MENUITEM_DIFFICULTY_ITEM_PLAYER]           = {DrawChoices_Challenges_ItemsPlayer,      ProcessInput_Options_Two},
    [MENUITEM_DIFFICULTY_ITEM_TRAINER]          = {DrawChoices_Challenges_ItemsTrainer,     ProcessInput_Options_Two},
    [MENUITEM_DIFFICULTY_NO_EVS]                = {DrawChoices_Challenges_NoEVs,            ProcessInput_Options_Two},
    [MENUITEM_DIFFICULTY_SCALING_IVS]           = {DrawChoices_Challenges_ScalingIVs,       ProcessInput_Options_Three},
    [MENUITEM_DIFFICULTY_SCALING_EVS]           = {DrawChoices_Challenges_ScalingEVs,       ProcessInput_Options_Four},
    [MENUITEM_DIFFICULTY_POKECENTER]            = {DrawChoices_Challenges_Pokecenters,      ProcessInput_Options_Two},
    [MENUITEM_DIFFICULTY_NEXT] = {NULL, NULL},
};

struct // MENU_CHALLENGES
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} static const sItemFunctionsChallenges[MENUITEM_CHALLENGES_COUNT] =
{
    [MENUITEM_CHALLENGES_EVO_LIMIT]             = {DrawChoices_Challenges_EvoLimit,             ProcessInput_Options_Three},
    [MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE]    = {DrawChoices_Challenges_OneTypeChallenge,     ProcessInput_Options_OneTypeChallenge},
    [MENUITEM_CHALLENGES_BASE_STAT_EQUALIZER]   = {DrawChoices_Challenges_BaseStatEqualizer,    ProcessInput_Options_Four},
    [MENUITEM_CHALLENGES_MIRROR]                = {DrawChoices_Challenges_Mirror,               ProcessInput_Options_Two},
    [MENUITEM_CHALLENGES_MIRROR_THIEF]          = {DrawChoices_Challenges_Mirror_Thief,         ProcessInput_Options_Two},
    [MENUITEM_CHALLENGES_SAVE] = {NULL, NULL},
};

// Menu left side option names text
static const u8 sText_Dummy[] =                     _("Dummy");
static const u8 sText_Randomizer[] =                _("Randomizer");
static const u8 sText_Starter[] =                   _("Starter Pokémon");
static const u8 sText_WildPkmn[] =                  _("Wild Pokémon");
static const u8 sText_Trainer[] =                   _("Trainer");
static const u8 sText_Static[] =                    _("Static Pokémon");
static const u8 sText_SimiliarEvolutionLevel[] =    _("Balance on Tiers");
static const u8 sText_InlcudeLegendaries[]=         _("Legendaries");
static const u8 sText_Type[] =                      _("Type");
static const u8 sText_Moves[] =                     _("Moves");
static const u8 sText_Abilities[] =                 _("Abilities");
static const u8 sText_Evolutions[] =                _("Evolutions");
static const u8 sText_EvolutionMethods[] =          _("Evo Lines");
static const u8 sText_TypeEff[] =                   _("Effectiveness");
static const u8 sText_Items[] =                     _("Items");
static const u8 sText_Chaos[] =                     _("Chaos Mode");
static const u8 sText_Next[] =                      _("Next");
static const u8 *const sOptionMenuItemsNamesRandom[MENUITEM_RANDOM_COUNT] =
{
    [MENUITEM_RANDOM_OFF_ON]                    = sText_Randomizer,
    [MENUITEM_RANDOM_STARTER]                   = sText_Starter,
    [MENUITEM_RANDOM_WILD_PKMN]                 = sText_WildPkmn,
    [MENUITEM_RANDOM_TRAINER]                   = sText_Trainer,
    [MENUITEM_RANDOM_STATIC]                    = sText_Static,
    [MENUITEM_RANDOM_SIMILAR_EVOLUTION_LEVEL]   = sText_SimiliarEvolutionLevel,
    [MENUITEM_RANDOM_INCLUDE_LEGENDARIES]       = sText_InlcudeLegendaries,
    [MENUITEM_RANDOM_TYPE]                      = sText_Type,
    [MENUITEM_RANDOM_MOVES]                     = sText_Moves,
    [MENUITEM_RANDOM_ABILITIES]                 = sText_Abilities,
    [MENUITEM_RANDOM_EVOLUTIONS]                = sText_Evolutions,
    [MENUITEM_RANDOM_EVOLUTIONS_METHODS]        = sText_EvolutionMethods,
    [MENUITEM_RANDOM_TYPE_EFFEC]                = sText_TypeEff,
    [MENUITEM_RANDOM_ITEMS]                     = sText_Items,
    [MENUITEM_RANDOM_CHAOS]                     = sText_Chaos,
    [MENUITEM_RANDOM_NEXT]                      = sText_Next,
};

// MENU_NUZLOCKE
static const u8 sText_Nuzlocke[]        = _("Nuzlocke");
static const u8 sText_SpeciesClause[]   = _("Dupes Clause");
static const u8 sText_ShinyClause[]     = _("Shiny Clause");
static const u8 sText_Nicknaming[]      = _("Nicknames");
static const u8 sText_Deletion[]        = _("Fainting");
static const u8 *const sOptionMenuItemsNamesNuzlocke[MENUITEM_NUZLOCKE_COUNT] =
{
    [MENUITEM_NUZLOCKE_NUZLOCKE]        = sText_Nuzlocke,
    [MENUITEM_NUZLOCKE_SPECIES_CLAUSE]  = sText_SpeciesClause,
    [MENUITEM_NUZLOCKE_SHINY_CLAUSE]    = sText_ShinyClause,
    [MENUITEM_NUZLOCKE_NICKNAMING]      = sText_Nicknaming,
    [MENUITEM_NUZLOCKE_DELETION]        = sText_Deletion,
    [MENUITEM_NUZLOCKE_NEXT]            = sText_Next,
};

//MENU_DIFFICULTY
static const u8 sText_PartyLimit[]          = _("Party Limit");
static const u8 sText_LevelCap[]            = _("Harder Level Cap");
static const u8 sText_ExpMultiplier[]       = _("EXP Multiplier");
static const u8 sText_Items_Player[]        = _("Player Items");
static const u8 sText_Items_Trainer[]       = _("Trainer Items");
static const u8 sText_NoEVs[]               = _("Player EVs");
static const u8 sText_ScalingIVs[]          = _("Trainer IVs");
static const u8 sText_ScalingEVs[]          = _("Trainer EVs");
static const u8 sText_Pokecenter[]          = _("Pokécenter");
static const u8 *const sOptionMenuItemsNamesDifficulty[MENUITEM_DIFFICULTY_COUNT] =
{
    [MENUITEM_DIFFICULTY_PARTY_LIMIT]           = sText_PartyLimit,
    [MENUITEM_DIFFICULTY_LEVEL_CAP]             = sText_LevelCap,
    [MENUITEM_DIFFICULTY_EXP_MULTIPLIER]        = sText_ExpMultiplier,
    [MENUITEM_DIFFICULTY_ITEM_PLAYER]           = sText_Items_Player,
    [MENUITEM_DIFFICULTY_ITEM_TRAINER]          = sText_Items_Trainer,
    [MENUITEM_DIFFICULTY_NO_EVS]                = sText_NoEVs,
    [MENUITEM_DIFFICULTY_SCALING_IVS]           = sText_ScalingIVs,
    [MENUITEM_DIFFICULTY_SCALING_EVS]           = sText_ScalingEVs,
    [MENUITEM_DIFFICULTY_POKECENTER]            = sText_Pokecenter,
    [MENUITEM_DIFFICULTY_NEXT]                  = sText_Next,
};

// MENU_CHALLENGES
static const u8 sText_EvoLimit[]            = _("Evo Limit");
static const u8 sText_OneTypeChallenge[]    = _("One Type Only");
static const u8 sText_BaseStatEqualizer[]   = _("Stat Equalizer");
static const u8 sText_Mirror[]              = _("Mirror Mode");
static const u8 sText_MirrorThief[]         = _("Mirror Theif");
static const u8 sText_Save[]                = _("Save");
static const u8 *const sOptionMenuItemsNamesChallenges[MENUITEM_CHALLENGES_COUNT] =
{
    [MENUITEM_CHALLENGES_EVO_LIMIT]             = sText_EvoLimit,
    [MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE]    = sText_OneTypeChallenge,
    [MENUITEM_CHALLENGES_BASE_STAT_EQUALIZER]   = sText_BaseStatEqualizer,
    [MENUITEM_CHALLENGES_MIRROR]                = sText_Mirror,
    [MENUITEM_CHALLENGES_MIRROR_THIEF]          = sText_MirrorThief,
    [MENUITEM_CHALLENGES_SAVE]                  = sText_Save,
};

static const u8 *const OptionTextRight(u8 menuItem)
{
    switch (sOptions->submenu)
    {
    case MENU_RANDOMIZER:       return sOptionMenuItemsNamesRandom[menuItem];
    case MENU_NUZLOCKE:         return sOptionMenuItemsNamesNuzlocke[menuItem];
    case MENU_DIFFICULTY:       return sOptionMenuItemsNamesDifficulty[menuItem];
    case MENU_CHALLENGES:       return sOptionMenuItemsNamesChallenges[menuItem];
    }
    return 0;
}

// Menu left side text conditions
static bool8 CheckConditions(int selection)
{
    switch (sOptions->submenu)
    {
    case MENU_RANDOMIZER:
        switch(selection)
        {
            case MENUITEM_RANDOM_STARTER:                   return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_WILD_PKMN:                 return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_TRAINER:                   return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_STATIC:                    return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_SIMILAR_EVOLUTION_LEVEL:   return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON] 
                                                                && (sOptions->sel_randomizer[MENUITEM_RANDOM_WILD_PKMN] 
                                                                    || sOptions->sel_randomizer[MENUITEM_RANDOM_STARTER]
                                                                    || sOptions->sel_randomizer[MENUITEM_RANDOM_TRAINER] 
                                                                    || sOptions->sel_randomizer[MENUITEM_RANDOM_STATIC])
                                                                && !sOptions->sel_randomizer[MENUITEM_RANDOM_CHAOS];
            case MENUITEM_RANDOM_INCLUDE_LEGENDARIES:       return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON] 
                                                                && (sOptions->sel_randomizer[MENUITEM_RANDOM_WILD_PKMN] 
                                                                    || sOptions->sel_randomizer[MENUITEM_RANDOM_STARTER]
                                                                    || sOptions->sel_randomizer[MENUITEM_RANDOM_TRAINER]
                                                                    || sOptions->sel_randomizer[MENUITEM_RANDOM_STATIC]);
            case MENUITEM_RANDOM_TYPE:                      return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_MOVES:                     return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_ABILITIES:                 return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_EVOLUTIONS:                return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_EVOLUTIONS_METHODS:        return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_TYPE_EFFEC:                return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_ITEMS:                     return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON];
            case MENUITEM_RANDOM_CHAOS:                     return sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON] && (sOptions->sel_randomizer[MENUITEM_RANDOM_WILD_PKMN]
                                                                || sOptions->sel_randomizer[MENUITEM_RANDOM_STARTER]
                                                                || sOptions->sel_randomizer[MENUITEM_RANDOM_TRAINER]
                                                                || sOptions->sel_randomizer[MENUITEM_RANDOM_STATIC]
                                                                || sOptions->sel_randomizer[MENUITEM_RANDOM_TYPE]
                                                                || sOptions->sel_randomizer[MENUITEM_RANDOM_MOVES]
                                                                || sOptions->sel_randomizer[MENUITEM_RANDOM_ABILITIES]
                                                                || sOptions->sel_randomizer[MENUITEM_RANDOM_EVOLUTIONS]
                                                                || sOptions->sel_randomizer[MENUITEM_RANDOM_EVOLUTIONS_METHODS]
                                                                || sOptions->sel_randomizer[MENUITEM_RANDOM_TYPE_EFFEC]);
            default:                                        return TRUE;
        }
    case MENU_NUZLOCKE:
        switch(selection)
        {
        case MENUITEM_NUZLOCKE_SPECIES_CLAUSE:  return sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NUZLOCKE];
        case MENUITEM_NUZLOCKE_SHINY_CLAUSE:    return sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NUZLOCKE];
        case MENUITEM_NUZLOCKE_NICKNAMING:      return sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NUZLOCKE];
        case MENUITEM_NUZLOCKE_DELETION:        return sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NUZLOCKE];
        default:                                return TRUE;
        }
    case MENU_DIFFICULTY:
        switch(selection)
        {
        default:       return TRUE;;
        }
    case MENU_CHALLENGES:
        switch(selection)
        {
        case MENUITEM_CHALLENGES_MIRROR_THIEF:  return sOptions->sel_challenges[MENUITEM_CHALLENGES_MIRROR];
        default:                                return TRUE;
        }
    }
    return 0;
}

// Descriptions
static const u8 sText_Empty[]               = _("");
static const u8 sText_Description_Save[]    = _("Save choices and continue...");

static const u8 sText_Description_Randomizer_Off[]                  = _("Game will not be randomized.");
static const u8 sText_Description_Randomizer_On[]                   = _("Play the game randomized.\nSettings below!");
static const u8 sText_Description_Random_Starter_Off[]              = _("Standard starter Pokémon.");
static const u8 sText_Description_Random_Starter_On[]               = _("Randomize starter Pokémon.");
static const u8 sText_Description_Random_Starter_Stage2[]           = _("Randomize starter Pokémon with\n3-stage Pokémon.");
static const u8 sText_Description_Random_WildPokemon_Off[]          = _("Same wild encounter as in the\nbase game.");
static const u8 sText_Description_Random_WildPokemon_On[]           = _("Randomize wild Pokémon.");
static const u8 sText_Description_Random_Trainer_Off[]              = _("Trainer will have their expected\nparty.");
static const u8 sText_Description_Random_Trainer_On[]               = _("Randomize enemy trainer parties.");
static const u8 sText_Description_Random_Static_Off[]               = _("Static encounter will be the same\nas in the base game.");
static const u8 sText_Description_Random_Static_On[]                = _("Randomize static encounter Pokémon.");
static const u8 sText_Description_Random_BalanceTiers_Off[]         = _("Distribution of Pokémon {COLOR 7}{COLOR 8}not balanced{COLOR 1}{COLOR 2}\naround their strength!");
static const u8 sText_Description_Random_BalanceTiers_On[]          = _("{PKMN} replaced with similar tiered ones.\nCurrently based on evo stages.");
static const u8 sText_Description_Random_IncludeLegendaries_Off[]   = _("Legendary Pokémon will not be\nincluded and randomized.");
static const u8 sText_Description_Random_IncludeLegendaries_On[]    = _("Include legendary Pokémon in\nrandomization!");
static const u8 sText_Description_Random_Types_Off[]                = _("Pokémon types stay the same as in\nthe base game.");
static const u8 sText_Description_Random_Types_On[]                 = _("Randomize all Pokémon types.");
static const u8 sText_Description_Random_Moves_Off[]                = _("Pokémon moves stay the same as in\nthe base game.");
static const u8 sText_Description_Random_Moves_On[]                 = _("Randomize all Pokémon moves.");
static const u8 sText_Description_Random_Abilities_Off[]            = _("Pokémon abilities stay the same as in\nthe base game.");
static const u8 sText_Description_Random_Abilities_On[]             = _("Randomize all Pokémon abilities.");
static const u8 sText_Description_Random_Evos_Off[]                 = _("Pokémon evolutions stay the same as\nin the base game.");
static const u8 sText_Description_Random_Evos_On[]                  = _("Randomize all Pokémon evolutions.");
static const u8 sText_Description_Random_Evo_Methods_Off[]          = _("The Pokémon that can potentially\nevolve are unchanged.");
static const u8 sText_Description_Random_Evo_Methods_On[]           = _("Randomize evolution lines. Allows\nnew evolution lines to occure!");
static const u8 sText_Description_Random_Effectiveness_Off[]        = _("Type effectiveness chart will remain\nthe same as in the base game.");
static const u8 sText_Description_Random_Effectiveness_On[]         = _("Randomize type effectiveness.");
static const u8 sText_Description_Random_Items_Off[]                = _("All found or recieved items are the\nsame as in the base game.");
static const u8 sText_Description_Random_Items_On[]                 = _("Randomize found, hidden and revieved\nitems. KEY items are excluded!");
static const u8 sText_Description_Random_ChaosMode_Off[]            = _("Chaos mode disabled.");
static const u8 sText_Description_Random_ChaosMode_On[]             = _("Every above choosen option will be\nvery chaotic. {COLOR 7}{COLOR 8}NOT recommended!");
static const u8 sText_Description_Random_Next[]                     = _("Continue to Nuzlocke options.");
static const u8 *const sOptionMenuItemDescriptionsRandomizer[MENUITEM_RANDOM_COUNT][3] =
{
    [MENUITEM_RANDOM_OFF_ON]                    = {sText_Description_Randomizer_Off,                    sText_Description_Randomizer_On},
    [MENUITEM_RANDOM_STARTER]                   = {sText_Description_Random_Starter_Off,                sText_Description_Random_Starter_On,                sText_Description_Random_Starter_Stage2},
    [MENUITEM_RANDOM_WILD_PKMN]                 = {sText_Description_Random_WildPokemon_Off,            sText_Description_Random_WildPokemon_On,            sText_Empty},
    [MENUITEM_RANDOM_TRAINER]                   = {sText_Description_Random_Trainer_Off,                sText_Description_Random_Trainer_On,                sText_Empty},
    [MENUITEM_RANDOM_STATIC]                    = {sText_Description_Random_Static_Off,                 sText_Description_Random_Static_On,                 sText_Empty},
    [MENUITEM_RANDOM_SIMILAR_EVOLUTION_LEVEL]   = {sText_Description_Random_BalanceTiers_On,            sText_Description_Random_BalanceTiers_Off,          sText_Empty},
    [MENUITEM_RANDOM_INCLUDE_LEGENDARIES]       = {sText_Description_Random_IncludeLegendaries_Off,     sText_Description_Random_IncludeLegendaries_On,     sText_Empty},
    [MENUITEM_RANDOM_TYPE]                      = {sText_Description_Random_Types_Off,                  sText_Description_Random_Types_On,                  sText_Empty},
    [MENUITEM_RANDOM_MOVES]                     = {sText_Description_Random_Moves_Off,                  sText_Description_Random_Moves_On,                  sText_Empty},
    [MENUITEM_RANDOM_ABILITIES]                 = {sText_Description_Random_Abilities_Off,              sText_Description_Random_Abilities_On,              sText_Empty},
    [MENUITEM_RANDOM_EVOLUTIONS]                = {sText_Description_Random_Evos_Off,                   sText_Description_Random_Evos_On,                   sText_Empty},
    [MENUITEM_RANDOM_EVOLUTIONS_METHODS]        = {sText_Description_Random_Evo_Methods_Off,            sText_Description_Random_Evo_Methods_On,            sText_Empty},
    [MENUITEM_RANDOM_TYPE_EFFEC]                = {sText_Description_Random_Effectiveness_Off,          sText_Description_Random_Effectiveness_On,          sText_Empty},
    [MENUITEM_RANDOM_ITEMS]                     = {sText_Description_Random_Items_Off,                  sText_Description_Random_Items_On,                  sText_Empty},
    [MENUITEM_RANDOM_CHAOS]                     = {sText_Description_Random_ChaosMode_Off,              sText_Description_Random_ChaosMode_On,              sText_Empty},
    [MENUITEM_RANDOM_NEXT]                      = {sText_Description_Random_Next,                       sText_Empty,                                        sText_Empty},
};

static const u8 sText_Description_Nuzlocke_Base[]               = _("Nuzlocke mode is disabled.");
static const u8 sText_Description_Nuzlocke_Normal[]             = _("One catch per route! Fainted Pokémon\ncan't be used anymore.");
static const u8 sText_Description_Nuzlocke_Hard[]               = _("Same rules as Normal but also\n{COLOR 7}{COLOR 8}deletes Save on battle loss!");
static const u8 sText_Description_Nuzlocke_SpeciesClause_Off[]  = _("The player always has to catch the\nfirst Pokémon per route.");
static const u8 sText_Description_Nuzlocke_SpeciesClause_On[]   = _("Only not prior caught Pokémon count\nas first encounter. {COLOR 7}{COLOR 8}RECOMMENDED!");
static const u8 sText_Description_Nuzlocke_ShinyClause_Off[]    = _("The player can only catch a shiny\p Pokémon if it's the first encounter.");
static const u8 sText_Description_Nuzlocke_ShinyClause_On[]     = _("The player can always catch shiny\p Pokémon. {COLOR 7}{COLOR 8}RECOMMENDED!");
static const u8 sText_Description_Nuzlocke_Nicknaming_Off[]     = _("Nicknames are optional.");
static const u8 sText_Description_Nuzlocke_Nicknaming_On[]      = _("Forces the player to nickname every\p Pokémon. {COLOR 7}{COLOR 8}RECOMMENDED!");
static const u8 sText_Description_Nuzlocke_Deletion_Cemetery[]  = _("Fainted Pokémon are send to the PC\nafter battle and can't be retrieved.");
static const u8 sText_Description_Nuzlocke_Deletion_Deletion[]  = _("Fainted Pokémon are {COLOR 7}{COLOR 8}released{COLOR 1}{COLOR 2} after\nbattle!");
static const u8 sText_Description_Nuzlocke_Next[]                   = _("Continue to difficulty options.");
static const u8 *const sOptionMenuItemDescriptionsNuzlocke[MENUITEM_NUZLOCKE_COUNT][4] =
{
    [MENUITEM_NUZLOCKE_NUZLOCKE]            = {sText_Description_Nuzlocke_Base,                 sText_Description_Nuzlocke_Normal,                  sText_Description_Nuzlocke_Hard,    sText_Empty},
    [MENUITEM_NUZLOCKE_SPECIES_CLAUSE]      = {sText_Description_Nuzlocke_SpeciesClause_On,     sText_Description_Nuzlocke_SpeciesClause_Off,       sText_Empty,                        sText_Empty},
    [MENUITEM_NUZLOCKE_SHINY_CLAUSE]        = {sText_Description_Nuzlocke_ShinyClause_On,       sText_Description_Nuzlocke_ShinyClause_Off,         sText_Empty,                        sText_Empty},
    [MENUITEM_NUZLOCKE_NICKNAMING]          = {sText_Description_Nuzlocke_Nicknaming_On,        sText_Description_Nuzlocke_Nicknaming_Off,          sText_Empty,                        sText_Empty},
    [MENUITEM_NUZLOCKE_DELETION]            = {sText_Description_Nuzlocke_Deletion_Cemetery,    sText_Description_Nuzlocke_Deletion_Deletion,       sText_Empty,                        sText_Empty},
    [MENUITEM_NUZLOCKE_NEXT]                = {sText_Description_Nuzlocke_Next,                 sText_Empty,                                        sText_Empty,                        sText_Empty},
};

static const u8 sText_Description_Difficulty_Party_Limit[]              = _("Limit the amount of Pokémon in the\nplayers party.");
static const u8 sText_Description_Difficulty_LevelCap_Base[]            = _("No level cap. Overleveling possible.\n");
static const u8 sText_Description_Difficulty_LevelCap_Normal[]          = _("Maximum level is based on the\nnext gym's highest Pokémon level.");
static const u8 sText_Description_Difficulty_LevelCap_Hard[]            = _("Maximum level is based on the\nnext gym's {COLOR 7}{COLOR 8}lowest Pokémon level.");
static const u8 sText_Description_Difficulty_ExpMultiplier_1_0[]        = _("Pokémon gain normal EXP. Points.");
static const u8 sText_Description_Difficulty_ExpMultiplier_1_5[]        = _("Pokémon 50 percent more EXP. Points!");
static const u8 sText_Description_Difficulty_ExpMultiplier_2_0[]        = _("Pokémon gain double EXP. Points!");
static const u8 sText_Description_Difficulty_ExpMultiplier_0_0[]        = _("Pokémon gain {COLOR 7}{COLOR 8}ZERO EXP. Points!!!");
static const u8 sText_Description_Difficulty_Items_Player_Yes[]         = _("The player can use battle items.");
static const u8 sText_Description_Difficulty_Items_Player_No[]          = _("The player can {COLOR 7}{COLOR 8}NOT use battle items.\nHold items are allowed!");
static const u8 sText_Description_Difficulty_Items_Trainer_Yes[]        = _("Enemy trainer can use battle items.");
static const u8 sText_Description_Difficulty_Items_Trainer_No[]         = _("Enemy trainer can {COLOR 7}{COLOR 8}NOT use battle\nitems.");
static const u8 sText_Description_Difficulty_Pokecenter_Yes[]           = _("The player can visit Pokécenters and\nother locations to heal their party.");
static const u8 sText_Description_Difficulty_Pokecenter_No[]            = _("The player {COLOR 7}{COLOR 8}CAN'T visit Pokécenters or\nother locations to heal their party.");
static const u8 sText_Description_Difficulty_NoEVs_Off[]                = _("The players Pokémon gain effort\nvalues as expected.");
static const u8 sText_Description_Difficulty_NoEVs_On[]                 = _("The players Pokémon do {COLOR 7}{COLOR 8}NOT{COLOR 1}{COLOR 2} gain\nany effort values!");
static const u8 sText_Description_Difficulty_ScalingIVs_Off[]           = _("The Pokémon of enemy Trainer have\nthe expected IVs.");
static const u8 sText_Description_Difficulty_ScalingIVs_Scaling[]       = _("The IVs of Trainer Pokémon increase\nwith gym badges!");
static const u8 sText_Description_Difficulty_ScalingIVs_Hard[]          = _("All Trainer Pokémon have perfect\nIVs!");
static const u8 sText_Description_Difficulty_ScalingEVs_Off[]           = _("The Pokémon of enemy Trainer have\nthe expected EVs.");
static const u8 sText_Description_Difficulty_ScalingEVs_Scaling[]       = _("The EVs of Trainer Pokémon increase\nwith gym badges!");
static const u8 sText_Description_Difficulty_ScalingEVs_Hard[]          = _("All Trainer Pokémon have high EVs!");
static const u8 sText_Description_Difficulty_ScalingEVs_Extreme[]       = _("All Trainer Pokémon have {COLOR 7}{COLOR 8}252 EVs!\nVery Hard!");
static const u8 sText_Description_Difficulty_Next[]              = _("Continue to challenge options.");
static const u8 *const sOptionMenuItemDescriptionsDifficulty[MENUITEM_DIFFICULTY_COUNT][4] =
{
    [MENUITEM_DIFFICULTY_PARTY_LIMIT]           = {sText_Description_Difficulty_Party_Limit,        sText_Empty,                                        sText_Empty,                                    sText_Empty},
    [MENUITEM_DIFFICULTY_LEVEL_CAP]             = {sText_Description_Difficulty_LevelCap_Base,      sText_Description_Difficulty_LevelCap_Normal,       sText_Description_Difficulty_LevelCap_Hard,     sText_Empty},
    [MENUITEM_DIFFICULTY_EXP_MULTIPLIER]        = {sText_Description_Difficulty_ExpMultiplier_1_0,  sText_Description_Difficulty_ExpMultiplier_1_5,     sText_Description_Difficulty_ExpMultiplier_2_0, sText_Description_Difficulty_ExpMultiplier_0_0},
    [MENUITEM_DIFFICULTY_ITEM_PLAYER]           = {sText_Description_Difficulty_Items_Player_Yes,   sText_Description_Difficulty_Items_Player_No,       sText_Empty,                                    sText_Empty},
    [MENUITEM_DIFFICULTY_ITEM_TRAINER]          = {sText_Description_Difficulty_Items_Trainer_Yes,  sText_Description_Difficulty_Items_Trainer_No,      sText_Empty,                                    sText_Empty},
    [MENUITEM_DIFFICULTY_NO_EVS]                = {sText_Description_Difficulty_NoEVs_Off,          sText_Description_Difficulty_NoEVs_On,              sText_Empty,                                    sText_Empty},
    [MENUITEM_DIFFICULTY_SCALING_IVS]           = {sText_Description_Difficulty_ScalingIVs_Off,     sText_Description_Difficulty_ScalingIVs_Scaling,    sText_Description_Difficulty_ScalingIVs_Hard,   sText_Empty},
    [MENUITEM_DIFFICULTY_SCALING_EVS]           = {sText_Description_Difficulty_ScalingEVs_Off,     sText_Description_Difficulty_ScalingEVs_Scaling,    sText_Description_Difficulty_ScalingEVs_Hard,   sText_Description_Difficulty_ScalingEVs_Extreme},
    [MENUITEM_DIFFICULTY_POKECENTER]            = {sText_Description_Difficulty_Pokecenter_Yes,     sText_Description_Difficulty_Pokecenter_No,         sText_Empty,                                    sText_Empty},
    [MENUITEM_DIFFICULTY_NEXT]                  = {sText_Description_Difficulty_Next,               sText_Empty,                                        sText_Empty,                                    sText_Empty},
};  

static const u8 sText_Description_Challenges_EvoLimit_Base[]            = _("Pokémon evolve as expected.");
static const u8 sText_Description_Challenges_EvoLimit_First[]           = _("Pokémon can only evolve into\ntheir first evolution.");
static const u8 sText_Description_Challenges_EvoLimit_All[]             = _("Pokémon can {COLOR 7}{COLOR 8}NOT evolve at all!");
static const u8 sText_Description_Challenges_OneTypeChallenge[]         = _("Allow only one Pokémon type the\nplayer can capture and use.");
static const u8 sText_Description_Challenges_BaseStatEqualizer_Base[]   = _("All Pokémon have their original base\nstats.");
static const u8 sText_Description_Challenges_BaseStatEqualizer_100[]    = _("Pokémon stats are calculated with\n100 of each base stat.");
static const u8 sText_Description_Challenges_BaseStatEqualizer_255[]    = _("Pokémon stats are calculated with\n255 of each base stat.");
static const u8 sText_Description_Challenges_BaseStatEqualizer_500[]    = _("Pokémon stats are calculated with\n500 of each base stat.");
static const u8 sText_Description_Challenges_Mirror_Off[]               = _("The player uses their own party.");
static const u8 sText_Description_Challenges_Mirror_Trainer[]           = _("In Trainer battles the player gets\na copy of the enemies party!");
static const u8 sText_Description_Challenges_Mirror_All[]               = _("The player gets a copy of the\nenemies party in {COLOR 7}{COLOR 8}ALL battles!");
static const u8 sText_Description_Challenges_MirrorThief_Off[]          = _("The player gets their own party back\nafter battles.");
static const u8 sText_Description_Challenges_MirrorThief_On[]           = _("The player keeps the enemies party\nafter battle!");
static const u8 *const sOptionMenuItemDescriptionsChallenges[MENUITEM_CHALLENGES_COUNT][4] =
{
    [MENUITEM_CHALLENGES_EVO_LIMIT]             = {sText_Description_Challenges_EvoLimit_Base,          sText_Description_Challenges_EvoLimit_First,        sText_Description_Challenges_EvoLimit_All,          sText_Empty},
    [MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE]    = {sText_Description_Challenges_OneTypeChallenge,       sText_Empty,                                        sText_Empty,                                        sText_Empty},
    [MENUITEM_CHALLENGES_BASE_STAT_EQUALIZER]   = {sText_Description_Challenges_BaseStatEqualizer_Base, sText_Description_Challenges_BaseStatEqualizer_100, sText_Description_Challenges_BaseStatEqualizer_255, sText_Description_Challenges_BaseStatEqualizer_500},
    [MENUITEM_CHALLENGES_MIRROR]                = {sText_Description_Challenges_Mirror_Off,             sText_Description_Challenges_Mirror_Trainer,        sText_Empty,                                        sText_Empty},
    [MENUITEM_CHALLENGES_MIRROR_THIEF]          = {sText_Description_Challenges_MirrorThief_Off,        sText_Description_Challenges_MirrorThief_On,        sText_Empty,                                        sText_Empty},
    [MENUITEM_CHALLENGES_SAVE]                  = {sText_Description_Save,                              sText_Empty,                                        sText_Empty,                                        sText_Empty},
};

// Disabled descriptions
static const u8 sText_Description_Disabled_Random_SimiliarEvolutionLevel[]  = _("Only usable with random starter,\nTrainer, wild or static Pokémon.");
static const u8 sText_Description_Disabled_Random_IncludeLegendaries[]      = _("Only usable with random starter,\nTrainer, wild or static Pokémon.");
static const u8 sText_Description_Disabled_Random_Chaos_Mode[]              = _("Only usable if other random options\nare activated.");
static const u8 *const sOptionMenuItemDescriptionsDisabledRandomizer[MENUITEM_RANDOM_COUNT] =
{
    [MENUITEM_RANDOM_OFF_ON]                    = sText_Empty,
    [MENUITEM_RANDOM_STARTER]                   = sText_Empty,
    [MENUITEM_RANDOM_WILD_PKMN]                 = sText_Empty,
    [MENUITEM_RANDOM_TRAINER]                   = sText_Empty,
    [MENUITEM_RANDOM_STATIC]                    = sText_Empty,
    [MENUITEM_RANDOM_SIMILAR_EVOLUTION_LEVEL]   = sText_Description_Disabled_Random_SimiliarEvolutionLevel,
    [MENUITEM_RANDOM_INCLUDE_LEGENDARIES]       = sText_Description_Disabled_Random_IncludeLegendaries,
    [MENUITEM_RANDOM_TYPE]                      = sText_Empty,
    [MENUITEM_RANDOM_MOVES]                     = sText_Empty,
    [MENUITEM_RANDOM_ABILITIES]                 = sText_Empty,
    [MENUITEM_RANDOM_EVOLUTIONS]                = sText_Empty,
    [MENUITEM_RANDOM_EVOLUTIONS_METHODS]        = sText_Empty,
    [MENUITEM_RANDOM_TYPE_EFFEC]                = sText_Empty,
    [MENUITEM_RANDOM_ITEMS]                     = sText_Empty,
    [MENUITEM_RANDOM_CHAOS]                     = sText_Description_Disabled_Random_Chaos_Mode,
    [MENUITEM_RANDOM_NEXT]                      = sText_Empty,
};

static const u8 sText_Description_Disabled_Nuzlocke_Nuzlocke[]   = _("Only usable with Nuzlocke!");
static const u8 *const sOptionMenuItemDescriptionsDisabledNuzlocke[MENUITEM_NUZLOCKE_COUNT] =
{
    [MENUITEM_NUZLOCKE_NUZLOCKE]            = sText_Empty,
    [MENUITEM_NUZLOCKE_SPECIES_CLAUSE]      = sText_Description_Disabled_Nuzlocke_Nuzlocke,
    [MENUITEM_NUZLOCKE_SHINY_CLAUSE]        = sText_Description_Disabled_Nuzlocke_Nuzlocke,
    [MENUITEM_NUZLOCKE_NICKNAMING]          = sText_Description_Disabled_Nuzlocke_Nuzlocke,
    [MENUITEM_NUZLOCKE_DELETION]            = sText_Description_Disabled_Nuzlocke_Nuzlocke,
    [MENUITEM_NUZLOCKE_NEXT]                = sText_Empty,
};

static const u8 *const sOptionMenuItemDescriptionsDisabledDifficulty[MENUITEM_DIFFICULTY_COUNT] =
{
    [MENUITEM_DIFFICULTY_PARTY_LIMIT]           = sText_Empty,
    [MENUITEM_DIFFICULTY_LEVEL_CAP]             = sText_Empty,
    [MENUITEM_DIFFICULTY_EXP_MULTIPLIER]        = sText_Empty,
    [MENUITEM_DIFFICULTY_ITEM_PLAYER]           = sText_Empty,
    [MENUITEM_DIFFICULTY_ITEM_TRAINER]          = sText_Empty,
    [MENUITEM_DIFFICULTY_NO_EVS]                = sText_Empty,
    [MENUITEM_DIFFICULTY_SCALING_IVS]           = sText_Empty,
    [MENUITEM_DIFFICULTY_SCALING_EVS]           = sText_Empty,
    [MENUITEM_DIFFICULTY_POKECENTER]            = sText_Empty,
    [MENUITEM_DIFFICULTY_NEXT]                  = sText_Empty,
};  

static const u8 sText_Description_Disabled_Challenges_MirrorThief[]    = _("Only usable with Mirror Mode!");
static const u8 *const sOptionMenuItemDescriptionsDisabledChallenges[MENUITEM_CHALLENGES_COUNT] =
{
    [MENUITEM_CHALLENGES_EVO_LIMIT]             = sText_Empty,
    [MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE]    = sText_Empty,
    [MENUITEM_CHALLENGES_BASE_STAT_EQUALIZER]   = sText_Empty,
    [MENUITEM_CHALLENGES_MIRROR]                = sText_Empty,
    [MENUITEM_CHALLENGES_MIRROR_THIEF]          = sText_Description_Disabled_Challenges_MirrorThief,
    [MENUITEM_CHALLENGES_SAVE]                  = sText_Empty,
};

// Functions to dynamically retrieve data
static const u8 *const OptionTextDescription(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu];
    u8 selection;

    switch (sOptions->submenu)
    {
    case MENU_RANDOMIZER:
        if (!CheckConditions(menuItem) && sOptionMenuItemDescriptionsDisabledRandomizer[menuItem] != sText_Empty)
            return sOptionMenuItemDescriptionsDisabledRandomizer[menuItem];
        selection = sOptions->sel_randomizer[menuItem];  
        return sOptionMenuItemDescriptionsRandomizer[menuItem][selection];
    case MENU_NUZLOCKE:
        if (!CheckConditions(menuItem) && sOptionMenuItemDescriptionsDisabledNuzlocke[menuItem] != sText_Empty)
            return sOptionMenuItemDescriptionsDisabledNuzlocke[menuItem];
        selection = sOptions->sel_nuzlocke[menuItem];
        return sOptionMenuItemDescriptionsNuzlocke[menuItem][selection];
    case MENU_DIFFICULTY:
        if (!CheckConditions(menuItem) && sOptionMenuItemDescriptionsDisabledDifficulty[menuItem] != sText_Empty)
            return sOptionMenuItemDescriptionsDisabledDifficulty[menuItem];
        selection = sOptions->sel_difficulty[menuItem];
        if (sOptions->menuCursor[MENU_DIFFICULTY] == MENUITEM_DIFFICULTY_PARTY_LIMIT)
            return sOptionMenuItemDescriptionsDifficulty[menuItem][0];
        else
            return sOptionMenuItemDescriptionsDifficulty[menuItem][selection];
    case MENU_CHALLENGES:
        if (!CheckConditions(menuItem) && sOptionMenuItemDescriptionsDisabledChallenges[menuItem] != sText_Empty)
            return sOptionMenuItemDescriptionsDisabledChallenges[menuItem];
        selection = sOptions->sel_challenges[menuItem];
        if (sOptions->menuCursor[MENU_CHALLENGES] == MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE)
            return sOptionMenuItemDescriptionsChallenges[menuItem][0];
        else
            return sOptionMenuItemDescriptionsChallenges[menuItem][selection];
    }
    return 0;
}

static u8 MenuItemCount(void)
{
    switch (sOptions->submenu)
    {
    case MENU_RANDOMIZER:   return MENUITEM_RANDOM_COUNT;
    case MENU_NUZLOCKE:     return MENUITEM_NUZLOCKE_COUNT;
    case MENU_DIFFICULTY:   return MENUITEM_DIFFICULTY_COUNT;
    case MENU_CHALLENGES:   return MENUITEM_CHALLENGES_COUNT;
    }
    return 0;
}
#ifndef NDEBUG
static u8 MenuItemCountFromIndex(u8 index)
{
    switch (index)
    {
    case MENU_RANDOMIZER:   return MENUITEM_RANDOM_COUNT;
    case MENU_NUZLOCKE:     return MENUITEM_NUZLOCKE_COUNT;
    case MENU_DIFFICULTY:   return MENUITEM_DIFFICULTY_COUNT;
    case MENU_CHALLENGES:   return MENUITEM_CHALLENGES_COUNT;
    }
    return 0;
}
#endif
static u8 MenuItemCancel(void)
{
    switch (sOptions->submenu)
    {
    case MENU_RANDOMIZER:   return MENUITEM_RANDOM_NEXT;
    case MENU_NUZLOCKE:     return MENUITEM_NUZLOCKE_NEXT;
    case MENU_DIFFICULTY:   return MENUITEM_DIFFICULTY_NEXT;
    case MENU_CHALLENGES:   return MENUITEM_CHALLENGES_SAVE;
    }
    return 0;
}

// Main code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static const u8 sText_TopBar_Left[]             = _("{L_BUTTON}General");
static const u8 sText_TopBar_Right[]            = _("{R_BUTTON}Custom");
static const u8 sText_TopBar_Randomizer[]       = _("Randomizer");
static const u8 sText_TopBar_Nuzlocke[]         = _("Nuzlocke");
static const u8 sText_TopBar_Difficulty[]       = _("Difficulty");
static const u8 sText_TopBar_Challenges[]       = _("Challenges");
static void DrawTopBarText(void)
{
    const u8 color[3] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };
    int width = 0;
    int right = 240 - GetStringWidth(FONT_SMALL, sText_TopBar_Right, 0) - 5;

    FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(15));
    switch (sOptions->submenu)
    {
        case MENU_RANDOMIZER:
            width = GetStringWidth(FONT_SMALL, sText_TopBar_Randomizer, 0) / 2;
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 120-width, 1, color, 0, sText_TopBar_Randomizer);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, right, 1, color, 0, sText_TopBar_Right);
            break;
        case MENU_NUZLOCKE:
            width = GetStringWidth(FONT_SMALL, sText_TopBar_Nuzlocke, 0) / 2;
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 5, 1, color, 0, sText_TopBar_Left);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 120-width, 1, color, 0, sText_TopBar_Nuzlocke);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, right, 1, color, 0, sText_TopBar_Right);
            break;
        case MENU_DIFFICULTY:
            width = GetStringWidth(FONT_SMALL, sText_TopBar_Difficulty, 0) / 2;
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 5, 1, color, 0, sText_TopBar_Left);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 120-width, 1, color, 0, sText_TopBar_Difficulty);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, right, 1, color, 0, sText_TopBar_Right);
            break;
        case MENU_CHALLENGES:
            width = GetStringWidth(FONT_SMALL, sText_TopBar_Challenges, 0) / 2;
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 5, 1, color, 0, sText_TopBar_Left);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 120-width, 1, color, 0, sText_TopBar_Challenges);
            break;
    }
    PutWindowTilemap(WIN_TOPBAR);
    CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
}

static void DrawOptionMenuTexts(void) //left side text
{
    u8 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < MenuItemCount(); i++)
        DrawLeftSideOptionText(i, (i * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawDescriptionText(void)
{
    u8 color_gray[3];
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
        
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));
    AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_NORMAL, 8, 1, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextDescription());
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
}

static void DrawLeftSideOptionText(int selection, int y)
{
    u8 color_yellow[3];
    u8 color_gray[3];

    color_yellow[0] = TEXT_COLOR_TRANSPARENT;
    color_yellow[1] = TEXT_COLOR_OPTIONS_ORANGE_FG;
    color_yellow[2] = TEXT_COLOR_OPTIONS_ORANGE_SHADOW;
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;

    if (CheckConditions(selection))
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_yellow, TEXT_SKIP_DRAW, OptionTextRight(selection));
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextRight(selection));
}

static void DrawRightSideChoiceText(const u8 *text, int x, int y, bool8 choosen, bool8 active)
{
    u8 color_red[3];
    u8 color_gray[3];

    if (active)
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_RED_FG;
        color_red[2] = TEXT_COLOR_OPTIONS_RED_SHADOW;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }
    else
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_RED_DARK_FG;
        color_red[2] = TEXT_COLOR_OPTIONS_RED_DARK_SHADOW;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }


    if (choosen)
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_red, TEXT_SKIP_DRAW, text);
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_gray, TEXT_SKIP_DRAW, text);
}

static void DrawChoices(u32 id, int y) //right side draw function
{
    switch (sOptions->submenu)
    {
        case MENU_RANDOMIZER:
            if (sItemFunctionsRandom[id].drawChoices != NULL)
                sItemFunctionsRandom[id].drawChoices(sOptions->sel_randomizer[id], y);
            break;
        case MENU_NUZLOCKE:
            if (sItemFunctionsNuzlocke[id].drawChoices != NULL)
                sItemFunctionsNuzlocke[id].drawChoices(sOptions->sel_nuzlocke[id], y);
            break;
        case MENU_DIFFICULTY:
            if (sItemFunctionsDifficulty[id].drawChoices != NULL)
                sItemFunctionsDifficulty[id].drawChoices(sOptions->sel_difficulty[id], y);
            break;
        case MENU_CHALLENGES:
            if (sItemFunctionsChallenges[id].drawChoices != NULL)
                sItemFunctionsChallenges[id].drawChoices(sOptions->sel_challenges[id], y);
            break;
    }
}

static void HighlightOptionMenuItem(void)
{
    int cursor = sOptions->visibleCursor[sOptions->submenu];

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(Y_DIFF, 224));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(cursor * Y_DIFF + 24, cursor * Y_DIFF + 40));
}

void CB2_InitTxRandomizerChallengesMenu(void)
{
    u32 i;
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void*)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ResetBgPositions();
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN1_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        PlayBGM(MUS_RG_NEW_GAME_INTRO);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, 0, sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, 16, sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        //tx_randomizer_and_challenges
        gSaveBlock1Ptr->tx_Random_Starter                   = TX_RANDOM_STARTER;
        gSaveBlock1Ptr->tx_Random_Starter_Stage2            = TX_RANDOM_STARTER_STAGE2;
        gSaveBlock1Ptr->tx_Random_WildPokemon               = TX_RANDOM_WILD_POKEMON;
        gSaveBlock1Ptr->tx_Random_Trainer                   = TX_RANDOM_TRAINER;
        gSaveBlock1Ptr->tx_Random_Static                    = TX_RANDOM_STATIC;
        gSaveBlock1Ptr->tx_Random_Similar                   = TX_RANDOM_SIMILAR;
        gSaveBlock1Ptr->tx_Random_MapBased                  = TX_RANDOM_MAP_BASED;
        gSaveBlock1Ptr->tx_Random_IncludeLegendaries        = TX_RANDOM_INCLUDE_LEGENDARIES;
        gSaveBlock1Ptr->tx_Random_Type                      = TX_RANDOM_TYPE;
        gSaveBlock1Ptr->tx_Random_Moves                     = TX_RANDOM_MOVES;
        gSaveBlock1Ptr->tx_Random_Abilities                 = TX_RANDOM_ABILITIES;
        gSaveBlock1Ptr->tx_Random_Evolutions                = TX_RANDOM_EVOLUTION;
        gSaveBlock1Ptr->tx_Random_EvolutionMethods          = TX_RANDOM_EVOLUTION_METHODE;
        gSaveBlock1Ptr->tx_Random_TypeEffectiveness         = TX_RANDOM_TYPE_EFFECTIVENESS;
        gSaveBlock1Ptr->tx_Random_Items                     = TX_RANDOM_ITEMS;
        gSaveBlock1Ptr->tx_Random_Chaos                     = TX_RANDOM_CHAOS_MODE;
        gSaveBlock1Ptr->tx_Random_OneForOne                 = TX_RANDOM_ONE_FOR_ONE;

        gSaveBlock1Ptr->tx_Challenges_Nuzlocke              = TX_NUZLOCKE_NUZLOCKE;
        gSaveBlock1Ptr->tx_Challenges_NuzlockeHardcore      = TX_NUZLOCKE_NUZLOCKE_HARDCORE;
        gSaveBlock1Ptr->tx_Nuzlocke_SpeciesClause           = TX_NUZLOCKE_SPECIES_CLAUSE;
        gSaveBlock1Ptr->tx_Nuzlocke_ShinyClause             = TX_NUZLOCKE_SHINY_CLAUSE;
        gSaveBlock1Ptr->tx_Nuzlocke_Nicknaming              = TX_NUZLOCKE_NICKNAMING;
        gSaveBlock1Ptr->tx_Nuzlocke_Deletion                = TX_NUZLOCKE_DELETION;
    
        gSaveBlock1Ptr->tx_Challenges_PartyLimit            = TX_DIFFICULTY_PARTY_LIMIT;
        gSaveBlock1Ptr->tx_Challenges_LevelCap              = TX_DIFFICULTY_LEVEL_CAP;
        gSaveBlock1Ptr->tx_Challenges_ExpMultiplier         = TX_DIFFICULTY_EXP_MULTIPLIER;
        gSaveBlock1Ptr->tx_Challenges_NoItemPlayer          = TX_DIFFICULTY_NO_ITEM_PLAYER;
        gSaveBlock1Ptr->tx_Challenges_NoItemTrainer         = TX_DIFFICULTY_NO_ITEM_TRAINER;
        gSaveBlock1Ptr->tx_Challenges_NoEVs                 = TX_DIFFICULTY_NO_EVS;
        gSaveBlock1Ptr->tx_Challenges_TrainerScalingIVs     = TX_DIFFICULTY_SCALING_IVS;
        gSaveBlock1Ptr->tx_Challenges_TrainerScalingEVs     = TX_DIFFICULTY_SCALING_EVS;
        gSaveBlock1Ptr->tx_Challenges_PkmnCenter            = TX_DIFFICULTY_PKMN_CENTER;

        gSaveBlock1Ptr->tx_Challenges_EvoLimit              = TX_CHALLENGE_EVO_LIMIT;
        gSaveBlock1Ptr->tx_Challenges_OneTypeChallenge      = TX_CHALLENGE_TYPE;
        gSaveBlock1Ptr->tx_Challenges_BaseStatEqualizer     = TX_CHALLENGE_BASE_STAT_EQUALIZER;
        gSaveBlock1Ptr->tx_Challenges_Mirror                = TX_CHALLENGE_MIRROR;
        gSaveBlock1Ptr->tx_Challenges_Mirror_Thief          = TX_CHALLENGE_MIRROR_THIEF;
               

        sOptions = AllocZeroed(sizeof(*sOptions));
        sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON]                     = FALSE;
        if (gSaveBlock1Ptr->tx_Random_Starter_Stage2)
            sOptions->sel_randomizer[MENUITEM_RANDOM_STARTER] = 2;
        else if (gSaveBlock1Ptr->tx_Random_Starter)
            sOptions->sel_randomizer[MENUITEM_RANDOM_STARTER] = 1;
        else
            sOptions->sel_randomizer[MENUITEM_RANDOM_STARTER] = 0;
        sOptions->sel_randomizer[MENUITEM_RANDOM_WILD_PKMN]                  = gSaveBlock1Ptr->tx_Random_WildPokemon;
        sOptions->sel_randomizer[MENUITEM_RANDOM_TRAINER]                    = gSaveBlock1Ptr->tx_Random_Trainer;
        sOptions->sel_randomizer[MENUITEM_RANDOM_STATIC]                     = gSaveBlock1Ptr->tx_Random_Static;
        sOptions->sel_randomizer[MENUITEM_RANDOM_SIMILAR_EVOLUTION_LEVEL]    = !gSaveBlock1Ptr->tx_Random_Similar;
        sOptions->sel_randomizer[MENUITEM_RANDOM_INCLUDE_LEGENDARIES]        = gSaveBlock1Ptr->tx_Random_IncludeLegendaries;
        sOptions->sel_randomizer[MENUITEM_RANDOM_TYPE]                       = gSaveBlock1Ptr->tx_Random_Type;
        sOptions->sel_randomizer[MENUITEM_RANDOM_MOVES]                      = gSaveBlock1Ptr->tx_Random_Moves;
        sOptions->sel_randomizer[MENUITEM_RANDOM_ABILITIES]                  = gSaveBlock1Ptr->tx_Random_Abilities;
        sOptions->sel_randomizer[MENUITEM_RANDOM_EVOLUTIONS]                 = gSaveBlock1Ptr->tx_Random_Evolutions;
        sOptions->sel_randomizer[MENUITEM_RANDOM_EVOLUTIONS_METHODS]         = gSaveBlock1Ptr->tx_Random_EvolutionMethods;
        sOptions->sel_randomizer[MENUITEM_RANDOM_TYPE_EFFEC]                 = gSaveBlock1Ptr->tx_Random_TypeEffectiveness;
        sOptions->sel_randomizer[MENUITEM_RANDOM_ITEMS]                      = gSaveBlock1Ptr->tx_Random_Items;
        sOptions->sel_randomizer[MENUITEM_RANDOM_CHAOS]                      = gSaveBlock1Ptr->tx_Random_Chaos;

        // MENU_NUZLOCKE
        if (gSaveBlock1Ptr->tx_Challenges_Nuzlocke && gSaveBlock1Ptr->tx_Challenges_NuzlockeHardcore)
            sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NUZLOCKE] = 2;
        else if (gSaveBlock1Ptr->tx_Challenges_Nuzlocke)
            sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NUZLOCKE] = 1;
        else
            sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NUZLOCKE] = 0;
        sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_SPECIES_CLAUSE]    = !gSaveBlock1Ptr->tx_Nuzlocke_SpeciesClause;
        sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_SHINY_CLAUSE]      = !gSaveBlock1Ptr->tx_Nuzlocke_ShinyClause;
        sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NICKNAMING]        = !gSaveBlock1Ptr->tx_Nuzlocke_Nicknaming;
        sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_DELETION]          = gSaveBlock1Ptr->tx_Nuzlocke_Deletion;
        
        // MENU_DIFFICULTY
        sOptions->sel_difficulty[MENUITEM_DIFFICULTY_PARTY_LIMIT]    = gSaveBlock1Ptr->tx_Challenges_PartyLimit;
        sOptions->sel_difficulty[MENUITEM_DIFFICULTY_LEVEL_CAP]      = gSaveBlock1Ptr->tx_Challenges_LevelCap;
        sOptions->sel_difficulty[MENUITEM_DIFFICULTY_EXP_MULTIPLIER] = gSaveBlock1Ptr->tx_Challenges_ExpMultiplier;
        sOptions->sel_difficulty[MENUITEM_DIFFICULTY_ITEM_PLAYER]    = gSaveBlock1Ptr->tx_Challenges_NoItemPlayer;
        sOptions->sel_difficulty[MENUITEM_DIFFICULTY_ITEM_TRAINER]   = gSaveBlock1Ptr->tx_Challenges_NoItemTrainer;
        sOptions->sel_difficulty[MENUITEM_DIFFICULTY_NO_EVS]         = gSaveBlock1Ptr->tx_Challenges_NoEVs;
        sOptions->sel_difficulty[MENUITEM_DIFFICULTY_SCALING_IVS]    = gSaveBlock1Ptr->tx_Challenges_TrainerScalingIVs;
        sOptions->sel_difficulty[MENUITEM_DIFFICULTY_SCALING_EVS]    = gSaveBlock1Ptr->tx_Challenges_TrainerScalingEVs;
        sOptions->sel_difficulty[MENUITEM_DIFFICULTY_POKECENTER]     = gSaveBlock1Ptr->tx_Challenges_PkmnCenter;
        // MENU_CHALLENGES
        sOptions->sel_challenges[MENUITEM_CHALLENGES_EVO_LIMIT]              = gSaveBlock1Ptr->tx_Challenges_EvoLimit;
        sOptions->sel_challenges[MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE]     = gSaveBlock1Ptr->tx_Challenges_OneTypeChallenge;
        sOptions->sel_challenges[MENUITEM_CHALLENGES_BASE_STAT_EQUALIZER]    = gSaveBlock1Ptr->tx_Challenges_BaseStatEqualizer;
        sOptions->sel_challenges[MENUITEM_CHALLENGES_MIRROR]                 = gSaveBlock1Ptr->tx_Challenges_Mirror;
        sOptions->sel_challenges[MENUITEM_CHALLENGES_MIRROR_THIEF]           = gSaveBlock1Ptr->tx_Challenges_Mirror_Thief;

        sOptions->submenu = MENU_RANDOMIZER;

        gMain.state++;
        break;
    case 7:
        PutWindowTilemap(WIN_TOPBAR);
        DrawTopBarText();
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_DESCRIPTION);
        DrawDescriptionText();
        gMain.state++;
        break;
    case 9:
        PutWindowTilemap(WIN_OPTIONS);
        DrawOptionMenuTexts();
        gMain.state++;
        break;
    case 10:
        CreateTask(Task_OptionMenuFadeIn, 0);
        
        sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MENUITEM_RANDOM_COUNT - 1, 110, 110, 0);

        for (i = 0; i < OPTIONS_ON_SCREEN; i++)
            DrawChoices(i, i * Y_DIFF);

        HighlightOptionMenuItem();

        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        gMain.state++;
        break;
    case 11:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 12:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    //int i, scrollCount = 0, itemsToRedraw;
    if (JOY_NEW(A_BUTTON))
    {
        if (sOptions->menuCursor[sOptions->submenu] == MenuItemCancel())
        {
            if (sOptions->submenu == MENU_COUNT-1)
                gTasks[taskId].func = Task_RandomizerChallengesMenuSave;
            else
            {
                sOptions->submenu++;
                DrawTopBarText();
                ReDrawAll();
                HighlightOptionMenuItem();
                DrawDescriptionText();
            }
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == NUM_OPTIONS_FROM_BORDER) // don't advance visible cursor until scrolled to the bottom
        {
            if (--sOptions->menuCursor[sOptions->submenu] == 0)
                sOptions->visibleCursor[sOptions->submenu]--;
            else
                ScrollMenu(1);
        }
        else
        {
            if (--sOptions->menuCursor[sOptions->submenu] < 0) // Scroll all the way to the bottom.
            {
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = 3;
                ScrollAll(0);
                sOptions->visibleCursor[sOptions->submenu] = 4;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - 1;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]--;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == 3) // don't advance visible cursor until scrolled to the bottom
        {
            if (++sOptions->menuCursor[sOptions->submenu] == MenuItemCount() - 1)
                sOptions->visibleCursor[sOptions->submenu]++;
            else
                ScrollMenu(0);
        }
        else
        {
            if (++sOptions->menuCursor[sOptions->submenu] >= MenuItemCount()-1) // Scroll all the way to the top.
            {
                sOptions->visibleCursor[sOptions->submenu] = 3;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - 4;
                ScrollAll(1);
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = 0;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]++;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        if (sOptions->submenu == MENU_RANDOMIZER)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_randomizer[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsRandom[cursor].processInput != NULL)
                {
                    sOptions->sel_randomizer[cursor] = sItemFunctionsRandom[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_randomizer[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_NUZLOCKE)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_nuzlocke[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsNuzlocke[cursor].processInput != NULL)
                {
                    sOptions->sel_nuzlocke[cursor] = sItemFunctionsNuzlocke[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_nuzlocke[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_DIFFICULTY)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_difficulty[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsDifficulty[cursor].processInput != NULL)
                {
                    sOptions->sel_difficulty[cursor] = sItemFunctionsDifficulty[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_difficulty[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_CHALLENGES)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_challenges[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsChallenges[cursor].processInput != NULL)
                {
                    sOptions->sel_challenges[cursor] = sItemFunctionsChallenges[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_challenges[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
    }
    else if (JOY_NEW(R_BUTTON))
    {
        if (sOptions->submenu != MENU_COUNT-1)
            sOptions->submenu++;

        DrawTopBarText();
        ReDrawAll();
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(L_BUTTON))
    {
        if (sOptions->submenu != 0)
            sOptions->submenu--;
        
        DrawTopBarText();
        ReDrawAll();
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
}

static void Task_RandomizerChallengesMenuSave(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_RandomizerChallengesMenuFadeOut;
}

static void Task_RandomizerChallengesMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

void SaveData_TxRandomizerAndChallenges(void)
{
    #ifndef NDEBUG
    PrintCurrentSelections();
    #endif
    // MENU_RANDOMIZER
    switch (sOptions->sel_randomizer[MENUITEM_RANDOM_STARTER])
    {
    case 0:
        gSaveBlock1Ptr->tx_Random_Starter          = FALSE;
        gSaveBlock1Ptr->tx_Random_Starter_Stage2   = FALSE;
        break;
    case 1:
        gSaveBlock1Ptr->tx_Random_Starter          = TRUE;
        gSaveBlock1Ptr->tx_Random_Starter_Stage2   = FALSE;
        break;
    case 2:
        gSaveBlock1Ptr->tx_Random_Starter          = TRUE;
        gSaveBlock1Ptr->tx_Random_Starter_Stage2   = TRUE;
        break;
    }
    if (sOptions->sel_randomizer[MENUITEM_RANDOM_OFF_ON] == TRUE)
    {
        gSaveBlock1Ptr->tx_Random_WildPokemon        = sOptions->sel_randomizer[MENUITEM_RANDOM_WILD_PKMN];
        gSaveBlock1Ptr->tx_Random_Trainer            = sOptions->sel_randomizer[MENUITEM_RANDOM_TRAINER];
        gSaveBlock1Ptr->tx_Random_Static             = sOptions->sel_randomizer[MENUITEM_RANDOM_STATIC];
        gSaveBlock1Ptr->tx_Random_Similar            = !sOptions->sel_randomizer[MENUITEM_RANDOM_SIMILAR_EVOLUTION_LEVEL];
        gSaveBlock1Ptr->tx_Random_MapBased           = TX_RANDOM_MAP_BASED;
        gSaveBlock1Ptr->tx_Random_IncludeLegendaries = sOptions->sel_randomizer[MENUITEM_RANDOM_INCLUDE_LEGENDARIES];
        gSaveBlock1Ptr->tx_Random_Type               = sOptions->sel_randomizer[MENUITEM_RANDOM_TYPE];
        gSaveBlock1Ptr->tx_Random_Moves              = sOptions->sel_randomizer[MENUITEM_RANDOM_MOVES];
        gSaveBlock1Ptr->tx_Random_Abilities          = sOptions->sel_randomizer[MENUITEM_RANDOM_ABILITIES];
        gSaveBlock1Ptr->tx_Random_Evolutions         = sOptions->sel_randomizer[MENUITEM_RANDOM_EVOLUTIONS];
        gSaveBlock1Ptr->tx_Random_EvolutionMethods   = sOptions->sel_randomizer[MENUITEM_RANDOM_EVOLUTIONS_METHODS];
        gSaveBlock1Ptr->tx_Random_TypeEffectiveness  = sOptions->sel_randomizer[MENUITEM_RANDOM_TYPE_EFFEC];
        gSaveBlock1Ptr->tx_Random_Items              = sOptions->sel_randomizer[MENUITEM_RANDOM_ITEMS];
        gSaveBlock1Ptr->tx_Random_Chaos              = sOptions->sel_randomizer[MENUITEM_RANDOM_CHAOS];
    }
    else
    {
        gSaveBlock1Ptr->tx_Random_WildPokemon        = FALSE;
        gSaveBlock1Ptr->tx_Random_Trainer            = FALSE;
        gSaveBlock1Ptr->tx_Random_Static             = FALSE;
        gSaveBlock1Ptr->tx_Random_Similar            = FALSE;
        gSaveBlock1Ptr->tx_Random_MapBased           = FALSE;
        gSaveBlock1Ptr->tx_Random_IncludeLegendaries = FALSE;
        gSaveBlock1Ptr->tx_Random_Type               = FALSE;
        gSaveBlock1Ptr->tx_Random_Moves              = FALSE;
        gSaveBlock1Ptr->tx_Random_Abilities          = FALSE;
        gSaveBlock1Ptr->tx_Random_Evolutions         = FALSE;
        gSaveBlock1Ptr->tx_Random_EvolutionMethods   = FALSE;
        gSaveBlock1Ptr->tx_Random_TypeEffectiveness  = FALSE;
        gSaveBlock1Ptr->tx_Random_Chaos              = FALSE;
    } 
    //MENU_NUZLOCKE
    switch (sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NUZLOCKE])
    {
    case 0:
        gSaveBlock1Ptr->tx_Challenges_Nuzlocke          = FALSE;
        gSaveBlock1Ptr->tx_Challenges_NuzlockeHardcore  = FALSE;
        break;
    case 1:
        gSaveBlock1Ptr->tx_Challenges_Nuzlocke          = TRUE;
        gSaveBlock1Ptr->tx_Challenges_NuzlockeHardcore  = FALSE;
        break;
    case 2:
        gSaveBlock1Ptr->tx_Challenges_Nuzlocke          = TRUE;
        gSaveBlock1Ptr->tx_Challenges_NuzlockeHardcore  = TRUE;
        break;
    }
    if (gSaveBlock1Ptr->tx_Challenges_Nuzlocke)
    {
        gSaveBlock1Ptr->tx_Nuzlocke_SpeciesClause   = !sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_SPECIES_CLAUSE];
        gSaveBlock1Ptr->tx_Nuzlocke_ShinyClause     = !sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_SHINY_CLAUSE];
        gSaveBlock1Ptr->tx_Nuzlocke_Nicknaming      = !sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NICKNAMING];
        gSaveBlock1Ptr->tx_Nuzlocke_Deletion        = sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_DELETION];
    }
    else
    {
        gSaveBlock1Ptr->tx_Nuzlocke_SpeciesClause   = FALSE;
        gSaveBlock1Ptr->tx_Nuzlocke_ShinyClause     = FALSE;
        gSaveBlock1Ptr->tx_Nuzlocke_Nicknaming      = FALSE;
    }
    // MENU_DIFFICULTY
    gSaveBlock1Ptr->tx_Challenges_PartyLimit    = sOptions->sel_difficulty[MENUITEM_DIFFICULTY_PARTY_LIMIT];
    gSaveBlock1Ptr->tx_Challenges_LevelCap      = sOptions->sel_difficulty[MENUITEM_DIFFICULTY_LEVEL_CAP];
    gSaveBlock1Ptr->tx_Challenges_ExpMultiplier = sOptions->sel_difficulty[MENUITEM_DIFFICULTY_EXP_MULTIPLIER];
    gSaveBlock1Ptr->tx_Challenges_NoItemPlayer  = sOptions->sel_difficulty[MENUITEM_DIFFICULTY_ITEM_PLAYER];
    gSaveBlock1Ptr->tx_Challenges_NoItemTrainer = sOptions->sel_difficulty[MENUITEM_DIFFICULTY_ITEM_TRAINER];
    gSaveBlock1Ptr->tx_Challenges_NoEVs                 = sOptions->sel_difficulty[MENUITEM_DIFFICULTY_NO_EVS];
    gSaveBlock1Ptr->tx_Challenges_TrainerScalingIVs     = sOptions->sel_difficulty[MENUITEM_DIFFICULTY_SCALING_IVS];
    gSaveBlock1Ptr->tx_Challenges_TrainerScalingEVs     = sOptions->sel_difficulty[MENUITEM_DIFFICULTY_SCALING_EVS];
    gSaveBlock1Ptr->tx_Challenges_PkmnCenter            = sOptions->sel_difficulty[MENUITEM_DIFFICULTY_POKECENTER];
    // MENU_CHALLENGES
    gSaveBlock1Ptr->tx_Challenges_EvoLimit             = sOptions->sel_challenges[MENUITEM_CHALLENGES_EVO_LIMIT];
    if (sOptions->sel_challenges[MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE] > NUMBER_OF_MON_TYPES-1)
        gSaveBlock1Ptr->tx_Challenges_OneTypeChallenge = TX_CHALLENGE_TYPE_OFF;
    else if (sOptions->sel_challenges[MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE] == NUMBER_OF_MON_TYPES-1)
        gSaveBlock1Ptr->tx_Challenges_OneTypeChallenge = GetRandomType();
    else if (sOptions->sel_challenges[MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE] >= TYPE_MYSTERY)
        gSaveBlock1Ptr->tx_Challenges_OneTypeChallenge = sOptions->sel_challenges[MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE] + 1;
    else
        gSaveBlock1Ptr->tx_Challenges_OneTypeChallenge = sOptions->sel_challenges[MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE];
    gSaveBlock1Ptr->tx_Challenges_BaseStatEqualizer    = sOptions->sel_challenges[MENUITEM_CHALLENGES_BASE_STAT_EQUALIZER];
    gSaveBlock1Ptr->tx_Challenges_Mirror               = sOptions->sel_challenges[MENUITEM_CHALLENGES_MIRROR]; 
    gSaveBlock1Ptr->tx_Challenges_Mirror_Thief         = sOptions->sel_challenges[MENUITEM_CHALLENGES_MIRROR_THIEF]; 

    PrintTXSaveData();

    FREE_AND_SET_NULL(sOptions);
}

static void ScrollMenu(int direction)
{
    int menuItem, pos;

    if (direction == 0) // scroll down
        menuItem = sOptions->menuCursor[sOptions->submenu] + NUM_OPTIONS_FROM_BORDER, pos = OPTIONS_ON_SCREEN - 1;
    else
        menuItem = sOptions->menuCursor[sOptions->submenu] - NUM_OPTIONS_FROM_BORDER, pos = 0;

    // Hide one
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF, PIXEL_FILL(0));
    // Show one
    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, Y_DIFF * pos, 26 * 8, Y_DIFF);
    // Print
    DrawChoices(menuItem, pos * Y_DIFF);
    DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}
static void ScrollAll(int direction) // to bottom or top
{
    int i, y, menuItem, pos;
    int scrollCount;

    scrollCount = MenuItemCount() - OPTIONS_ON_SCREEN;

    // Move items up/down
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF * scrollCount, PIXEL_FILL(1));

    // Clear moved items
    if (direction == 0)
    {
        y = OPTIONS_ON_SCREEN - scrollCount;
        if (y < 0)
            y = OPTIONS_ON_SCREEN;
        y *= Y_DIFF;
    }
    else
    {
        y = 0;
    }

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, y, 26 * 8, Y_DIFF * scrollCount);
    // Print new texts
    for (i = 0; i < scrollCount; i++)
    {
        if (direction == 0) // From top to bottom
            menuItem = MenuItemCount() - 1 - i, pos = OPTIONS_ON_SCREEN - 1 - i;
        else // From bottom to top
            menuItem = i, pos = i;
        DrawChoices(menuItem, pos * Y_DIFF);
        DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Process Input functions ****GENERIC****
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int xMid;
    int widthLeft = GetStringWidth(1, txt1, 0);
    int widthMid = GetStringWidth(1, txt2, 0);
    int widthRight = GetStringWidth(1, txt3, 0);

    widthMid -= (198 - 104);
    xMid = (widthLeft - widthMid - widthRight) / 2 + 104;
    return xMid;
}

static int XOptions_ProcessInput(int x, int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (++selection > (x - 1))
            selection = 0;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (--selection < 0)
            selection = (x - 1);
    }
    return selection;
}

static int ProcessInput_Options_Two(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;

    return selection;
}

static int ProcessInput_Options_Three(int selection)
{
    return XOptions_ProcessInput(3, selection);
}

static int ProcessInput_Options_Four(int selection)
{
    return XOptions_ProcessInput(4, selection);
}

static int ProcessInput_Options_Six(int selection)
{
    return XOptions_ProcessInput(6, selection);
}
/*
static int ProcessInput_Options_Eleven(int selection)
{
    return XOptions_ProcessInput(11, selection);
}
*/
static int ProcessInput_Options_OneTypeChallenge(int selection)
{
    return XOptions_ProcessInput(NUMBER_OF_MON_TYPES+1, selection);
}
/*
// Process Input functions ****SPECIFIC****
static int ProcessInput_Sound(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
    }

    return selection;
}

static int ProcessInput_FrameType(int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    return selection;
}
*/
// Draw Choices functions ****GENERIC****
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active)
{
    bool8 choosen = FALSE;
    if (style != 0)
        choosen = TRUE;

    DrawRightSideChoiceText(text, x, y+1, choosen, active);
}

static void DrawChoices_Options_Four(const u8 *const *const strings, int selection, int y, bool8 active)
{
    static const u8 choiceOrders[][3] =
    {
        {0, 1, 2},
        {0, 1, 2},
        {1, 2, 3},
        {1, 2, 3},
    };
    u8 styles[4] = {0};
    int xMid;
    const u8 *order = choiceOrders[selection];
    styles[selection] = 1;
    xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);

    DrawOptionMenuChoice(strings[order[0]], 104, y, styles[order[0]], active);
    DrawOptionMenuChoice(strings[order[1]], xMid, y, styles[order[1]], active);
    DrawOptionMenuChoice(strings[order[2]], GetStringRightAlignXOffset(1, strings[order[2]], 198), y, styles[order[2]], active);
}

static void ReDrawAll(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu] - sOptions->visibleCursor[sOptions->submenu];
    u8 i;

    if (MenuItemCount() <= 5) // Draw or delete the scrolling arrows based on options in the menu
    {
        if (sOptions->arrowTaskId != TASK_NONE)
        {
            RemoveScrollIndicatorArrowPair(sOptions->arrowTaskId);
            sOptions->arrowTaskId = TASK_NONE;
        }
    }
    else
    {
        if (sOptions->arrowTaskId == TASK_NONE)
            sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MenuItemCount() - 1, 110, 110, 0);

    }

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < OPTIONS_ON_SCREEN; i++)
    {
        DrawChoices(menuItem+i, i * Y_DIFF);
        DrawLeftSideOptionText(menuItem+i, (i * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Draw Choices functions ****SPECIFIC****
// MENU_RANDOMIZER
static const u8 sText_Off[]  = _("Off");
static const u8 sText_On[]   = _("On");
static const u8 sText_None[] = _("None");
static void DrawChoices_Random_OffOn(int selection, int y, bool8 active)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_On, GetStringRightAlignXOffset(1, sText_On, 198), y, styles[1], active);
}

static const u8 sText_Random[]  = _("Random");
static void DrawChoices_Random_OffRandom(int selection, int y, bool8 active)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);   
    DrawOptionMenuChoice(sText_Random, GetStringRightAlignXOffset(1, sText_Random, 198), y, styles[1], active);
}

static void DrawChoices_Random_Toggle(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_OFF_ON);
    DrawChoices_Random_OffOn(selection, y, active);
}
static const u8 sText_3Stage[]  = _("Evo");
static void DrawChoices_Random_Starter(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_STARTER);
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_Off, sText_Random, sText_3Stage);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Random, xMid, y, styles[1], active);
    DrawOptionMenuChoice(sText_3Stage, GetStringRightAlignXOffset(1, sText_3Stage, 198), y, styles[2], active);
}
static void DrawChoices_Random_WildPkmn(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_WILD_PKMN);
    DrawChoices_Random_OffRandom(selection, y, active);
}
static void DrawChoices_Random_Trainer(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_TRAINER);
    DrawChoices_Random_OffRandom(selection, y, active);
}
static void DrawChoices_Random_Static(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_STATIC);
    DrawChoices_Random_OffRandom(selection, y, active);
}
static void DrawChoices_Random_EvoStages(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_SIMILAR_EVOLUTION_LEVEL);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_On, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Off, GetStringRightAlignXOffset(1, sText_Off, 198), y, styles[1], active);
}
static void DrawChoices_Random_Legendaries(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_INCLUDE_LEGENDARIES);
    DrawChoices_Random_OffOn(selection, y, active);
}
static void DrawChoices_Random_Types(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_TYPE);
    DrawChoices_Random_OffRandom(selection, y, active);
}
static void DrawChoices_Random_Moves(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_MOVES);
    DrawChoices_Random_OffRandom(selection, y, active);
}
static void DrawChoices_Random_Abilities(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_ABILITIES);
    DrawChoices_Random_OffRandom(selection, y, active);
}
static void DrawChoices_Random_Evolutions(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_EVOLUTIONS);
    DrawChoices_Random_OffRandom(selection, y, active);
}
static void DrawChoices_Random_EvolutionMethods(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_EVOLUTIONS_METHODS);
    DrawChoices_Random_OffRandom(selection, y, active);
}
static void DrawChoices_Random_TypeEffect(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_TYPE_EFFEC);
    DrawChoices_Random_OffRandom(selection, y, active);
}
static void DrawChoices_Random_Items(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_ITEMS);
    DrawChoices_Random_OffRandom(selection, y, active);
}

static const u8 sText_Random_Chaos[] = _("Chaos");
static void DrawChoices_Random_OffChaos(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_RANDOM_CHAOS);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Random_Chaos, GetStringRightAlignXOffset(1, sText_Random_Chaos, 198), y, styles[1], active);

    if (selection == 1)
        sOptions->sel_randomizer[MENUITEM_RANDOM_SIMILAR_EVOLUTION_LEVEL] = 1;
}

// MENU_NUZLOCKE
static void DrawChoices_Nuzlocke_OnOff(int selection, int y, bool8 active)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_On, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Off, GetStringRightAlignXOffset(1, sText_Off, 198), y, styles[1], active);
}
static const u8 sText_Challenges_Nuzlocke_Normal[]      = _("Normal");
static const u8 sText_Challenges_Nuzlocke_Hardcore[]    = _("Hard");
static void DrawChoices_Challenges_Nuzlocke(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_NUZLOCKE_NUZLOCKE);
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_Off, sText_Challenges_Nuzlocke_Normal, sText_Challenges_Nuzlocke_Hardcore);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Challenges_Nuzlocke_Normal, xMid, y, styles[1], active);
    DrawOptionMenuChoice(sText_Challenges_Nuzlocke_Hardcore, GetStringRightAlignXOffset(1, sText_Challenges_Nuzlocke_Hardcore, 198), y, styles[2], active);

    if (selection == 0)
    {
        sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_SPECIES_CLAUSE]    = !TX_NUZLOCKE_SPECIES_CLAUSE;
        sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_SHINY_CLAUSE]      = !TX_NUZLOCKE_SHINY_CLAUSE; 
        sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_NICKNAMING]        = !TX_NUZLOCKE_NICKNAMING;
        sOptions->sel_nuzlocke[MENUITEM_NUZLOCKE_DELETION]          = TX_NUZLOCKE_DELETION; 
    }
}

static void DrawChoices_Nuzlocke_SpeciesClause(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_NUZLOCKE_SPECIES_CLAUSE);
    DrawChoices_Nuzlocke_OnOff(selection, y, active);
}
static void DrawChoices_Nuzlocke_ShinyClause(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_NUZLOCKE_SHINY_CLAUSE);
    DrawChoices_Nuzlocke_OnOff(selection, y, active);
}
static void DrawChoices_Nuzlocke_Nicknaming(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_NUZLOCKE_NICKNAMING);
    DrawChoices_Nuzlocke_OnOff(selection, y, active);
}
static const u8 sText_Nuzlocke_Cemetery[]  = _("Cemetry");
static const u8 sText_Nuzlocke_Deletion[]  = _("Release");
static void DrawChoices_Nuzlocke_Deletion(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_NUZLOCKE_DELETION);
    u8 styles[2] = {0};
    styles[selection] = 1;
    DrawOptionMenuChoice(sText_Nuzlocke_Cemetery, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Nuzlocke_Deletion, GetStringRightAlignXOffset(1, sText_Nuzlocke_Deletion, 198), y, styles[1], active);
}

// MENU_DIFFICULTY
static const u8 sText_Yes[] = _("Yes");
static const u8 sText_No[]  = _("No");
static void DrawChoices_Challenges_YesNo(int selection, int y, bool8 active)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Yes, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_No, GetStringRightAlignXOffset(1, sText_No, 198), y, styles[1], active);
}
static void DrawChoices_Challenges_ItemsPlayer(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFFICULTY_ITEM_PLAYER);
    DrawChoices_Challenges_YesNo(selection, y, active);
}
static void DrawChoices_Challenges_ItemsTrainer(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFFICULTY_ITEM_TRAINER);
    DrawChoices_Challenges_YesNo(selection, y, active);
}
static void DrawChoices_Challenges_NoEVs(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFFICULTY_NO_EVS);
    DrawChoices_Challenges_YesNo(selection, y, active);
}
static const u8 sText_ScalingIVsEVs_Scaling[]   = _("Scale");
static const u8 sText_ScalingIVsEVs_Hard[]      = _("Hard");
static void DrawChoices_Challenges_ScalingIVs(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFFICULTY_SCALING_IVS);
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_Off, sText_ScalingIVsEVs_Scaling, sText_ScalingIVsEVs_Hard);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_ScalingIVsEVs_Scaling, xMid, y, styles[1], active);
    DrawOptionMenuChoice(sText_ScalingIVsEVs_Hard, GetStringRightAlignXOffset(1, sText_ScalingIVsEVs_Hard, 198), y, styles[2], active);
}
static const u8 sText_ScalingIVsEVs_Extrem[]    = _("Extrem");
static const u8 *const sText_ScalingEVs_Strings[] = {sText_Off, sText_ScalingIVsEVs_Scaling, sText_ScalingIVsEVs_Hard, sText_ScalingIVsEVs_Extrem};
static void DrawChoices_Challenges_ScalingEVs(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFFICULTY_SCALING_EVS);
    DrawChoices_Options_Four(sText_ScalingEVs_Strings, selection, y, active);
}

static const u8 sText_Challenges_PartyLimit_1[]  = _("1");
static const u8 sText_Challenges_PartyLimit_2[]  = _("2");
static const u8 sText_Challenges_PartyLimit_3[]  = _("3");
static const u8 sText_Challenges_PartyLimit_4[]  = _("4");
static const u8 sText_Challenges_PartyLimit_5[]  = _("5");
static void DrawChoices_Challenges_PartyLimit(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFFICULTY_PARTY_LIMIT);
    u8 styles[6] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Challenges_PartyLimit_5, 130, y, styles[1], active);
    DrawOptionMenuChoice(sText_Challenges_PartyLimit_4, 146, y, styles[2], active);
    DrawOptionMenuChoice(sText_Challenges_PartyLimit_3, 161, y, styles[3], active);
    DrawOptionMenuChoice(sText_Challenges_PartyLimit_2, 176, y, styles[4], active);
    DrawOptionMenuChoice(sText_Challenges_PartyLimit_1, 192, y, styles[5], active);
}

static const u8 sText_Challenges_LevelCap_Normal[]  = _("Normal");
static const u8 sText_Challenges_LevelCap_Hard[]    = _("Hard");
static void DrawChoices_Challenges_LevelCap(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFFICULTY_LEVEL_CAP);
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_Off, sText_Challenges_LevelCap_Normal, sText_Challenges_LevelCap_Hard);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Challenges_LevelCap_Normal, xMid, y, styles[1], active);
    DrawOptionMenuChoice(sText_Challenges_LevelCap_Hard, GetStringRightAlignXOffset(1, sText_Challenges_LevelCap_Hard, 198), y, styles[2], active);
}

static const u8 sText_Challenges_ExpMultiplier_1_0[]   = _("x1.0");
static const u8 sText_Challenges_ExpMultiplier_1_5[]   = _("x1.5");
static const u8 sText_Challenges_ExpMultiplier_2_0[]   = _("x2.0");
static const u8 sText_Challenges_ExpMultiplier_0_0[]   = _("x0.0");
static const u8 *const sText_Challenges_ExpMultiplier_Strings[] = {sText_Challenges_ExpMultiplier_1_0, sText_Challenges_ExpMultiplier_1_5, sText_Challenges_ExpMultiplier_2_0, sText_Challenges_ExpMultiplier_0_0};
static void DrawChoices_Challenges_ExpMultiplier(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFFICULTY_EXP_MULTIPLIER);
    DrawChoices_Options_Four(sText_Challenges_ExpMultiplier_Strings, selection, y, active);
}

static void DrawChoices_Challenges_Pokecenters(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_DIFFICULTY_POKECENTER);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Yes, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_No, GetStringRightAlignXOffset(1, sText_No, 198), y, styles[1], active);
}


// MENU_CHALLENGES
static const u8 sText_Challenges_EvoLimit_First[]   = _("First");
static const u8 sText_Challenges_EvoLimit_All[]     = _("All");
static void DrawChoices_Challenges_EvoLimit(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_CHALLENGES_EVO_LIMIT);
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_Off, sText_Challenges_EvoLimit_First, sText_None);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_Challenges_EvoLimit_First, xMid, y, styles[1], active);
    DrawOptionMenuChoice(sText_Challenges_EvoLimit_All, GetStringRightAlignXOffset(1, sText_Challenges_EvoLimit_All, 198), y, styles[2], active);
}

static void DrawChoices_Challenges_OneTypeChallenge(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_CHALLENGES_ONE_TYPE_CHALLENGE);
    u8 n = selection;

    if (n > NUMBER_OF_MON_TYPES-1)
        StringCopyPadded(gStringVar1, sText_Off, 0, 15);
    else if (n == NUMBER_OF_MON_TYPES-1)
        StringCopyPadded(gStringVar1, sText_Random, 0, 15);
    else if (n >= TYPE_MYSTERY)
        StringCopyPadded(gStringVar1, gTypesInfo[n+1].name, 0, 10);
    else
        StringCopyPadded(gStringVar1, gTypesInfo[n].name, 0, 10);

    DrawOptionMenuChoice(gStringVar1, 104, y, 1, active);
}

static const u8 sText_Challenges_BaseStatEqualizer_100[]   = _("100");
static const u8 sText_Challenges_BaseStatEqualizer_255[]   = _("255");
static const u8 sText_Challenges_BaseStatEqualizer_500[]   = _("500");
static const u8 *const sText_Challenges_BaseStatEqualizer_Strings[] = {sText_Off, sText_Challenges_BaseStatEqualizer_100, sText_Challenges_BaseStatEqualizer_255, sText_Challenges_BaseStatEqualizer_500};
static void DrawChoices_Challenges_BaseStatEqualizer(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_CHALLENGES_BASE_STAT_EQUALIZER);
    DrawChoices_Options_Four(sText_Challenges_BaseStatEqualizer_Strings, selection, y, active);
}

static const u8 sText_Challenges_Mirror_All[]   = _("All");
static void DrawChoices_Challenges_Mirror(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_CHALLENGES_MIRROR);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_On, GetStringRightAlignXOffset(1, sText_On, 198), y, styles[1], active);

    if (selection == 0)
        sOptions->sel_challenges[MENUITEM_CHALLENGES_MIRROR_THIEF] = 0;
}
static void DrawChoices_Challenges_Mirror_Thief(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_CHALLENGES_MIRROR_THIEF);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Off, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_On, GetStringRightAlignXOffset(1, sText_On, 198), y, styles[1], active);
}


// Background tilemap
#define TILE_TOP_CORNER_L 0x1A2 // 418
#define TILE_TOP_EDGE     0x1A3 // 419
#define TILE_TOP_CORNER_R 0x1A4 // 420
#define TILE_LEFT_EDGE    0x1A5 // 421
#define TILE_RIGHT_EDGE   0x1A7 // 423
#define TILE_BOT_CORNER_L 0x1A8 // 424
#define TILE_BOT_EDGE     0x1A9 // 425
#define TILE_BOT_CORNER_R 0x1AA // 426

static void DrawBgWindowFrames(void)
{
    //                     bg, tile,              x, y, width, height, palNum
    // Option Texts window
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  2, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  3,  1, 16,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  3,  1, 16,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 13,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 13, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 13,  1,  1,  7);

    // Description window
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2, 14, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1, 15,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28, 15,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}


// Debug
#ifndef NDEBUG
static void PrintCurrentSelections(void)
{
    u8 i, j;

    for (i = 0; i < MENU_COUNT; i++)
    {
        MgbaPrintf(MGBA_LOG_DEBUG, "Menu = %d", i);
        for (j = 0; j < MenuItemCountFromIndex(i); j++)
        {
            switch (i)
            {
            case MENU_RANDOMIZER:   MgbaPrintf(MGBA_LOG_DEBUG, "MENU_RANDOMIZER %d",   sOptions->sel_randomizer[j]); break;
            case MENU_NUZLOCKE:     MgbaPrintf(MGBA_LOG_DEBUG, "MENU_NUZLOCKE %d",     sOptions->sel_nuzlocke[j]); break;
            case MENU_DIFFICULTY:   MgbaPrintf(MGBA_LOG_DEBUG, "MENU_DIFFICULTY %d",   sOptions->sel_difficulty[j]); break;
            case MENU_CHALLENGES:   MgbaPrintf(MGBA_LOG_DEBUG, "MENU_CHALLENGES %d",   sOptions->sel_challenges[j]); break;
            }
        }
           
    }
}
#endif