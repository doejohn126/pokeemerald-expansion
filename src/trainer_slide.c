#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "test_runner.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "line_break.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"
#include "trainer_slide.h"
#include "battle_message.h"

static u32 BattlerHPPercentage(u32 battler, u32 operation, u32 threshold);
static u32 GetEnemyMonCount(u32 firstId, u32 lastId, bool32 onlyAlive);
static bool32 DoesTrainerHaveSlideMessage(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstCriticalHit(enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(u32 battler, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstSTABMove(u32 firstId, u32 lastId, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstDown(u32 firstId, u32 lastId);
static bool32 ShouldRunTrainerSlideEnemyMonUnaffected(u32 firstId, u32 lastId, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlideLastSwitchIn(u32 battler);
static bool32 ShouldRunTrainerSlideLastHalfHP(u32 firstId, u32 lastId, u32 battler);
static bool32 ShouldRunTrainerSlideLastLowHp(u32 firstId, u32 lastId, u32 battler);
static void SetTrainerSlideParamters(u32 battler, u32* firstId, u32* lastId, u32* trainerId, u32* retValue);
static bool32 IsSlideInitalizedOrPlayed(enum TrainerSlideType slideId);

const u8 gText_May1stBattleHpLow[] = _("Uh oh! Getting pretty low here!\p");
const u8 gText_May1stBattleCrit[] = _("Ouch! Alright, that was a lot of damage!\p");
const u8 gText_May1stBattleIntro[] = _("This is our first battle but don't\nexpect me to go easy!\p");
const u8 gText_Brendan1stBattleIntro[] = _("Heh, let me show you how it's done.\p");
const u8 gText_Brendan1stBattleCrit[] = _("Wow, you crit me! Okay your not bad.\p");
const u8 gText_Brendan1stBattleHpLow[] = _("Hmm, okay well this isn't good.\p");
const u8 gText_RoxanneCrit[] = _("That was a pretty tough critical hit,\nbut me and my Pokémon can recover.\p");
const u8 gText_RoxanneFirstDown[] = _("You're battle style really does\ntell me what kind of trainer you are.\p");
const u8 gText_RoxanneLastMon[] = _("You're a pretty good opponent!\nI may even lose here...\p");
const u8 gText_JaydenFirstDown[] = _("You may have got through one of my\nPokémon but don't expect to win.\p");
const u8 gText_JaydenCrit[] = _("Sheesh.. my Pokémon did not take that\ncrit very well.\p");
const u8 gText_JaydenLastLow[] = _("Wow, you're actually pretty good.\p");
const u8 gText_BrockLast[] = _("Pretty impressive, you got me to my\nlast Pokémon!\p");
const u8 gText_BrockCrit[] = _("Wow! Nice critical hit!\p");
const u8 gText_BrockBeforeTurn[] = _("I may not be as good as the Rustboro\nGym Leader but I'll still be a tough\lopponent.\p");
const u8 gText_SkyKidLastSwitch[] = _("woa ur pretty good bro\p");
const u8 gText_May2ndBattleHpLow[] = _("Woah, you got pretty strong {B_PLAYER_NAME}!\p");
const u8 gText_May2ndBattleCrit[] = _("Uh oh, that was a pretty powerful\ncritical hit!\p");
const u8 gText_May2ndBattleIntro[] = _("Don't underestimate my new Pokémon\n{B_PLAYER_NAME}.\p");
const u8 gText_Brendan2ndBattleHpLow[] = _("Seems like you got better too {B_PLAYER_NAME}.\p");
const u8 gText_Brendan2ndBattleCrit[] = _("Well alright then...\p");
const u8 gText_Brendan2ndBattleIntro[] = _("Check out my new mons {B_PLAYER_NAME}!\nThis time, don't expect to win.\p");
const u8 gText_BrawlyLastSwitch[] = _("You're pretty tough but the battle\nisn't over yet.\p");
const u8 gText_BrawlyCrit[] = _("Oof, slick crit bro!\p");
const u8 gText_BrawlyIntro[] = _("Alright, let's get this started!\p");
const u8 gText_JaydenLastMon[] = _("Hey, don't think this is over yet\nbecause there's still room for me to win.\p");
const u8 gText_Jayden2Crit[] = _("Well I guess today is not my day.\p");
const u8 gText_Jayden2FirstDown[] = _("Okay you sure did improve, but will you\nwin?\p");
const u8 gText_BugsyLast[] = _("Uh oh, down to my last bug Pokémon!\p");
const u8 gText_BugsyCrit[] = _("Well that was pretty impressive!\p");
const u8 gText_BugsyBeforeTurn[] = _("Forgot to mention it but I'm also a Gym\nLeader in Johto, so don't expect an\leasy fight just because I use bugs.\p");
const u8 gText_ArchieLast[] = _("My last Pokémon...\p");
const u8 gText_ArchieFirstDown[] = _("Grr... you're a stubborn one I see.\p");
const u8 gText_Brendan3rdBattleIntro[] = _("You're not gonna believe how much\nbetter I've got.\p");
const u8 gText_Brendan3Last[] = _("Hah, seems like I'm not the only one who\ngot better.\p");
const u8 gText_BrendanFirstDown[] = _("We're only getting started, don't get\nyour hopes up {B_PLAYER_NAME}.\p");
const u8 gText_May3rdBattleIntro[] = _("My Pokémon got stronger, so I hope\nyou're prepared for a good battle!\p");
const u8 gText_May3Last[] = _("You have a pretty good battle style\nseeing how you're team holds up.\p");
const u8 gText_MayCrit[] = _("Ah, that critical hit wasn't pleasant!\p");
const u8 gText_WallyBattleIntro[] = _("I still might be new but don't\nunderestimate me.\p");
const u8 gText_WallyLast[] = _("Oh geez, you're pretty good...\p");
const u8 gText_WallyCrit[] = _("Woah!! that was a critical hit...\p");
const u8 gText_WattsonCrit[] = _("Wahaha! That was a pretty nice Crit!");
const u8 gText_WattsonLast[] = _("Wahahaha! Looks like I'm down to my\nlast Pokémon!");
const u8 gText_FantinaLast[] = _("Oh, heavens. What is this? Is this my\nfinal Pokémon?\p");
const u8 gText_FantinaCrit[] = _("Oh no. Pas bon at all.\p");
const u8 gText_FantinaLow[] = _("Never give up, never surrender!\p");
const u8 gText_FantinaUnaffected[] = _("Ohohoho! Don't forget now that all my\nPokémon is ghosts. And never forget\labout the Levitate ability!\p");
const u8 gText_MaxieStartMessage[] = _("This is the result for messing with our\nplans.\p");
const u8 gText_MaxieLast[] = _("How is this imbecile winning?\nThis is insane!\p");
const u8 gText_JaydenLastMon3[] = _("Down to my last Pokémon again.\nStill doesn't mean I lost though.\p");
const u8 gText_FlanneryBeforeTurn[] = _("Okay so uh, let's see how you get past\nmy sun strategy.\p");
const u8 gText_FlanneryLastMon[] = _("Yikes... I'm down to my last Pokémon.\p");
const u8 gText_ClayCrit[] = _("Well I'll be! Sure didn't see that coming.\p");
const u8 gText_ClayFirstDown[] = _("Impressive! That's some strength\nyou've got!\p");
const u8 gText_ClayLast[] = _("No hard feelings, but I'm extremely\nstubborn.\p");
const u8 gText_NormanBeforeFirst[] = _("I hope you came prepared {B_PLAYER_NAME},\nbecause I'm highly considered one of\lthe toughest Gym Leaders here.\p");
const u8 gText_NormanMegaEvolve[] = _("Kangaskhan Mega Evolve!\pMega Evolving is a great way to turn\nthe tables of a battle.\p");
const u8 gText_NormanLast[] = _("Wow I didn't expect this...\nYou're quite the trainer {B_PLAYER_NAME}.\p");
const u8 gText_KorrinaLast[] = _("How could it be?! You're pretty good!\p");
const u8 gText_KorrinaMega[] = _("Woohoo! Let's get this show on the road\nLucario!\p");
const u8 gText_KorrinaBeforeFirst[] = _("Time for Lady Korrina's big appearance!\p");
const u8 gText_BrendanMegaEvolve[] = _("Heh, I've been waiting for this moment!\p");
const u8 gText_MayMegaEvolve[] = _("I bet you didn't see this coming\n{B_PLAYER_NAME}!\p");
const u8 gText_WinonaBeforeFirst[] = _("You mustn't take my birds for granted\nnow.\p");
const u8 gText_WinonaLast[] = _("How graceful, but our show isn't over\nyet!\p");
const u8 gText_WinonaMegaEvolve[] = _("Altaria, it's time to really take to the\nsky!\p");
const u8 gText_MinaLast[] = _("What a great composition!\p");
const u8 gText_MinaZMove[] = _("You'll only see Trainers from Alola do\nsomething this epic!\p");
const u8 gText_MaxieLast2[] = _("I don't get how you're so skilled.\p");
const u8 gText_MaxieMega[] = _("Fufufu, I hope you realize we aren't\ngiving up on Groudon!\p");
const u8 gText_JaydenMega[] = _("Hehehe, I've been waiting for this\nmoment!\p");
const u8 gText_TateAndLizaLast[] = _("Tate: Good job beating our strategy.\nLiza: But things get worse from here!\p");
const u8 gText_TateAndLizaBeforeFirst[] = _("Tate: Can you even..\nLiza: Handle our antics?\p");
const u8 gText_TateNLizaMegaEvolve[] = _("Tate: Fufufu... say it Liza!\nLiza: Gardevoir, Mega Evolve!\p");
const u8 gText_MaxieMegaEvolve[] = _("Maxie: Heh, we aren't done yet.\p");
const u8 gText_ArchieIntro[] = _("I should've dealt with you a long time\nago.\p");
const u8 gText_ArchieLast2[] = _("What! I can't believe this is happening!\p");
const u8 gText_ArchieMega[] = _("Hah! Bet you didn't see this coming!\p");
const u8 gText_JuanBeforeFirst[] = _("Fufufu, watch how my elegant water\ntypes make a splash.\p");
const u8 gText_JuanMegaEvolve[] = _("Blastoise, let's see your elegance!\p");
const u8 gText_JuanLast[] = _("You are quite a strong trainer indeed!\p");
const u8 gText_GeetaBeforeFirst[] = _("I do hope you can defeat me so you can\nhave a greater shot at the Pokémon\lLeague.\p");
const u8 gText_GeetaLast[] = _("Heh! Hahahahahaha! Don't think you've\nwon just yet!\p");
const u8 gText_WallyBeforeFirst[] = _("Hey {PLAYER}, I bet you didn't expect\nme to improve this much!\p");
const u8 gText_WallyLast2[] = _("Let's wrap this up! You haven't won yet!\p");
const u8 gText_DawnLast[] = _("Wow, now you're pretty tough!\p");
const u8 gText_Jayden3FirstDown[] = _("Heh, I've forgotten how good you've got.\p");
const u8 gText_JaydenBeforeFirst[] = _("I'm not holding back anymore!\p");
const u8 gText_SidneyLast[] = _("Heh, not bad kid.\p");
const u8 gText_PhoebeLast[] = _("Hah, you're pretty good!\p");
const u8 gText_GlaciaLast[] = _("Such dedication. Too bad we're not done\nyet.\p");
const u8 gText_DrakeLast[] = _("Very talented indeed...\p");
const u8 gText_WallaceLast[] = _("I'm in shock on how amazing you are.\nYou still haven't won yet though!\p");
const u8 gText_WallaceBeforeFirst[] = _("I want us to make this the most\nexciting battle we've ever had!\p");

static const u8* const sTrainerSlides[DIFFICULTY_COUNT][TRAINERS_COUNT][TRAINER_SLIDE_COUNT] =
{
    [DIFFICULTY_NORMAL] =
    {
        [TRAINER_MAY_ROUTE_103_MUDKIP] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_May1stBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_May1stBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_May1stBattleIntro,
        },
        [TRAINER_MAY_ROUTE_103_TORCHIC] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_May1stBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_May1stBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_May1stBattleIntro,
        },
        [TRAINER_MAY_ROUTE_103_TREECKO] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_May1stBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_May1stBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_May1stBattleIntro,
        },
        [TRAINER_BRENDAN_ROUTE_103_MUDKIP] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_Brendan1stBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_Brendan1stBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_Brendan1stBattleIntro,
        },
        [TRAINER_BRENDAN_ROUTE_103_TORCHIC] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_Brendan1stBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_Brendan1stBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_Brendan1stBattleIntro,
        },
        [TRAINER_BRENDAN_ROUTE_103_TREECKO] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_Brendan1stBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_Brendan1stBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_Brendan1stBattleIntro,
        },
        [TRAINER_ROXANNE_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_RoxanneLastMon,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_RoxanneCrit,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_RoxanneFirstDown,
        },
        [TRAINER_JAYDEN] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_JaydenFirstDown,
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_JaydenLastLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_JaydenCrit,
        },
        [TRAINER_BROCK] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_BrockLast,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_BrockCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_BrockBeforeTurn,
        },
        [TRAINER_SKY_KID] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_SkyKidLastSwitch,
        },
        [TRAINER_MAY_RUSTBORO_MUDKIP] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_May2ndBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_May2ndBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_May2ndBattleIntro,
        },
        [TRAINER_MAY_RUSTBORO_TORCHIC] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_May2ndBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_May2ndBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_May2ndBattleIntro,
        },
        [TRAINER_MAY_RUSTBORO_TREECKO] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_May2ndBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_May2ndBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_May2ndBattleIntro,
        },
        [TRAINER_BRENDAN_RUSTBORO_MUDKIP] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_Brendan2ndBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_Brendan2ndBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_Brendan2ndBattleIntro,
        },
        [TRAINER_BRENDAN_RUSTBORO_TREECKO] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_Brendan2ndBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_Brendan2ndBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_Brendan2ndBattleIntro,
        },
        [TRAINER_BRENDAN_RUSTBORO_TORCHIC] =
        {
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_Brendan2ndBattleHpLow,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_Brendan2ndBattleCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_Brendan2ndBattleIntro,
        },
        [TRAINER_BRAWLY_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_BrawlyLastSwitch,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_BrawlyCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_BrawlyIntro,
        },
        [TRAINER_JAYDEN_2] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_JaydenLastMon,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_Jayden2Crit,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_Jayden2FirstDown,
        },
        [TRAINER_BUGSY] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_BugsyLast,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_BugsyCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_BugsyBeforeTurn,
        },
        [TRAINER_ARCHIE_MUSEUM] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_ArchieLast,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_ArchieFirstDown,
        },
        [TRAINER_BRENDAN_ROUTE_110_TORCHIC] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_Brendan3Last,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_Brendan3rdBattleIntro,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_BrendanFirstDown,
        },
        [TRAINER_BRENDAN_ROUTE_110_TREECKO] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_Brendan3Last,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_Brendan3rdBattleIntro,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_BrendanFirstDown,
        },
        [TRAINER_BRENDAN_ROUTE_110_MUDKIP] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_Brendan3Last,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_Brendan3rdBattleIntro,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_BrendanFirstDown,
        },
        [TRAINER_MAY_ROUTE_110_MUDKIP] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_May3Last,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_MayCrit,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_May3rdBattleIntro,
        },
        [TRAINER_MAY_ROUTE_110_TREECKO] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_May3Last,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_MayCrit,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_May3rdBattleIntro,
        },
        [TRAINER_MAY_ROUTE_110_TORCHIC] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_May3Last,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_MayCrit,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_May3rdBattleIntro,
        },
        [TRAINER_WALLY_MAUVILLE] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_WallyLast,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_WallyCrit,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_WallyBattleIntro,
        },
        [TRAINER_WATTSON_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_WattsonLast,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_WattsonCrit,
        },
        [TRAINER_SKY_KID_2] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_SkyKidLastSwitch,
        },
        [TRAINER_FANTINA] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_FantinaLast,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_FantinaCrit,
            [TRAINER_SLIDE_LAST_LOW_HP] = gText_FantinaLow,
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = gText_FantinaUnaffected,
        },
        [TRAINER_MAXIE_MT_CHIMNEY] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_MaxieLast,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_MaxieStartMessage,
        },
        [TRAINER_JAYDEN_3] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_JaydenLastMon3,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_JaydenCrit,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_Jayden2FirstDown,
        },
        [TRAINER_FLANNERY_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_FlanneryLastMon,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_FlanneryBeforeTurn,
        },
        [TRAINER_CLAY] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_ClayLast,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_ClayCrit,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_ClayFirstDown,
        },
        [TRAINER_NORMAN_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_NormanLast,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_NormanMegaEvolve,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_NormanBeforeFirst,
        },
        [TRAINER_SKY_KID_3] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_SkyKidLastSwitch,
        },
        [TRAINER_KORRINA] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_KorrinaLast,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_KorrinaMega,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_KorrinaBeforeFirst,
        },
        [TRAINER_BRENDAN_ROUTE_119_TORCHIC] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_Brendan3Last,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_BrendanMegaEvolve,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_BrendanFirstDown,
        },
        [TRAINER_BRENDAN_ROUTE_119_TREECKO] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_Brendan3Last,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_BrendanMegaEvolve,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_BrendanFirstDown,
        },
        [TRAINER_BRENDAN_ROUTE_119_MUDKIP] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_Brendan3Last,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_BrendanMegaEvolve,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_BrendanFirstDown,
        },
        [TRAINER_MAY_ROUTE_119_MUDKIP] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_May3Last,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_MayMegaEvolve,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_MayCrit,
        },
        [TRAINER_MAY_ROUTE_119_TREECKO] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_May3Last,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_MayMegaEvolve,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_MayCrit,
        },
        [TRAINER_MAY_ROUTE_119_TORCHIC] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_May3Last,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_MayMegaEvolve,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = gText_MayCrit,
        },
        [TRAINER_WINONA_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_WinonaLast,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_WinonaMegaEvolve,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_WinonaBeforeFirst,
        },
        [TRAINER_BRENDAN_LILYCOVE_MUDKIP] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_Brendan3Last,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_BrendanFirstDown,
        },
        [TRAINER_BRENDAN_LILYCOVE_TORCHIC] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_Brendan3Last,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_BrendanFirstDown,
        },
        [TRAINER_BRENDAN_LILYCOVE_TREECKO] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_Brendan3Last,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_BrendanFirstDown,
        },
        [TRAINER_MAY_LILYCOVE_MUDKIP] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_May3Last,
        },
        [TRAINER_MAY_LILYCOVE_TREECKO] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_May3Last,
        },
        [TRAINER_MAY_LILYCOVE_TORCHIC] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_May3Last,
        },
        [TRAINER_MINA] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_MinaLast,
            [TRAINER_SLIDE_Z_MOVE] = gText_MinaZMove,
        },
        [TRAINER_MAXIE_MAGMA_HIDEOUT] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_MaxieLast2,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_MaxieMega,
        },
        [TRAINER_JAYDEN_4] =
        {
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_JaydenMega,
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = gText_Jayden2FirstDown,
        },
        [TRAINER_TATE_AND_LIZA_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_TateAndLizaLast,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_TateNLizaMegaEvolve,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_TateAndLizaBeforeFirst,
        },
        [TRAINER_MAXIE_MOSSDEEP] =
        {
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_MaxieMegaEvolve,
        },
        [TRAINER_ARCHIE] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_ArchieLast2,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_ArchieMega,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_ArchieIntro,
        },
        [TRAINER_JUAN_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_JuanLast,
            [TRAINER_SLIDE_MEGA_EVOLUTION] = gText_JuanMegaEvolve,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_JuanBeforeFirst,
        },
        [TRAINER_GEETA] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_GeetaLast,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_GeetaBeforeFirst,
        },
        [TRAINER_WALLY_VR_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_WallyLast2,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_WallyBeforeFirst,
        },
        [TRAINER_DAWN] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_DawnLast,
        },
        [TRAINER_SIDNEY] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_SidneyLast,
        },
        [TRAINER_PHOEBE] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_PhoebeLast,
        },
        [TRAINER_GLACIA] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_GlaciaLast,
        },
        [TRAINER_DRAKE] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_DrakeLast,
        },
        [TRAINER_WALLACE] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = gText_WallaceLast,
            [TRAINER_SLIDE_BEFORE_FIRST_TURN] = gText_WallaceBeforeFirst,
        },
    },
};

static const u8* const sFrontierTrainerSlides[DIFFICULTY_COUNT][TRAINERS_COUNT][TRAINER_SLIDE_COUNT] =
{
    [DIFFICULTY_NORMAL] =
    {
    },
};

static const u8* const sTestTrainerSlides[DIFFICULTY_COUNT][FRONTIER_TRAINERS_COUNT][TRAINER_SLIDE_COUNT] =
{
#include "../test/battle/trainer_slides.h"
};

static u32 BattlerHPPercentage(u32 battler, u32 operation, u32 threshold)
{
    switch (operation)
    {
        case LESS_THAN:
            return gBattleMons[battler].hp < (gBattleMons[battler].maxHP / threshold);
        case EQUAL:
            return gBattleMons[battler].hp == (gBattleMons[battler].maxHP / threshold);
        case GREATER_THAN:
            return gBattleMons[battler].hp > (gBattleMons[battler].maxHP / threshold);
        case LESS_THAN_OR_EQUAL:
            return gBattleMons[battler].hp <= (gBattleMons[battler].maxHP / threshold);
        case GREATER_THAN_OR_EQUAL:
            return gBattleMons[battler].hp >= (gBattleMons[battler].maxHP / threshold);
        case NOT_EQUAL:
        default:
            return gBattleMons[battler].hp != (gBattleMons[battler].maxHP / threshold);
    }
}

static u32 GetEnemyMonCount(u32 firstId, u32 lastId, bool32 onlyAlive)
{
    u32 i, count = 0;

    for (i = firstId; i < lastId; i++)
    {
        u32 species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG, NULL);
        if (species != SPECIES_NONE
                && species != SPECIES_EGG
                && (!onlyAlive || GetMonData(&gEnemyParty[i], MON_DATA_HP, NULL)))
            count++;
    }

    return count;
}

static bool32 DoesTrainerHaveSlideMessage(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId)
{
    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        return (sFrontierTrainerSlides[difficulty][trainerId][slideId] != NULL);
    else if (TESTING)
        return (sTestTrainerSlides[difficulty][trainerId][slideId] != NULL);
    else
        return (sTrainerSlides[difficulty][trainerId][slideId] != NULL);
}

void SetTrainerSlideMessage(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId)
{
    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        gBattleStruct->trainerSlideMsg = sFrontierTrainerSlides[difficulty][trainerId][slideId];
    else if (TESTING)
        gBattleStruct->trainerSlideMsg = sTestTrainerSlides[difficulty][trainerId][slideId];
    else
        gBattleStruct->trainerSlideMsg = sTrainerSlides[difficulty][trainerId][slideId];
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstCriticalHit(enum TrainerSlideType slideId)
{
    return IsTrainerSlideInitialized(slideId);
}

static bool32 ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(enum TrainerSlideType slideId)
{
    return IsTrainerSlideInitialized(slideId);
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(u32 battler, enum TrainerSlideType slideId)
{
    if (!IsTrainerSlideInitialized(slideId))
        return FALSE;

    if (!IsBattlerAlive(battler))
        return FALSE;

    return TRUE;
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstSTABMove(u32 firstId, u32 lastId, enum TrainerSlideType slideId)
{
    if (!IsTrainerSlideInitialized(slideId))
        return FALSE;

    if (GetEnemyMonCount(firstId, lastId, TRUE) != GetEnemyMonCount(firstId, lastId, FALSE))
        return FALSE;

    return TRUE;
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstDown(u32 firstId, u32 lastId)
{
    return ((GetEnemyMonCount(firstId, lastId, TRUE) == (GetEnemyMonCount(firstId, lastId, FALSE) - 1)));
}

static bool32 ShouldRunTrainerSlideEnemyMonUnaffected(u32 firstId, u32 lastId, enum TrainerSlideType slideId)
{
    if (!IsTrainerSlideInitialized(slideId))
        return FALSE;

    return (GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE));
}

static bool32 ShouldRunTrainerSlideLastSwitchIn(u32 battler)
{
    return !CanBattlerSwitch(battler);
}

static bool32 ShouldRunTrainerSlideLastHalfHP(u32 firstId, u32 lastId, u32 battler)
{
    if (GetEnemyMonCount(firstId, lastId, TRUE) != 1)
        return FALSE;

    if (BattlerHPPercentage(battler, GREATER_THAN, 2))
        return FALSE;

    return (BattlerHPPercentage(battler, GREATER_THAN, 4));
}

static bool32 ShouldRunTrainerSlideLastLowHp(u32 firstId, u32 lastId, u32 battler)
{
    if (GetEnemyMonCount(firstId, lastId, TRUE) != 1)
        return FALSE;

    return (BattlerHPPercentage(battler, LESS_THAN_OR_EQUAL, 4));
}

static void SetTrainerSlideParamters(u32 battler, u32* firstId, u32* lastId, u32* trainerId, u32* retValue)
{
    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        if (gBattlerPartyIndexes[battler] >= MULTI_PARTY_SIZE)
        {
            *firstId = MULTI_PARTY_SIZE;
            *lastId = PARTY_SIZE;
            *trainerId = SanitizeTrainerId(TRAINER_BATTLE_PARAM.opponentB);
            *retValue = TRAINER_SLIDE_TARGET_TRAINER_B;
        }
        else
        {
            *firstId = 0;
            *lastId = MULTI_PARTY_SIZE;
            *trainerId = SanitizeTrainerId(TRAINER_BATTLE_PARAM.opponentA);
        }
    }
    else
    {
        *firstId = 0;
        *lastId = PARTY_SIZE;
        *trainerId = SanitizeTrainerId(TRAINER_BATTLE_PARAM.opponentA);
    }
}

enum TrainerSlideTargets ShouldDoTrainerSlide(u32 battler, enum TrainerSlideType slideId)
{
    u32 firstId, lastId, trainerId;
    u32 retValue = TRAINER_SLIDE_TARGET_TRAINER_A;
    bool32 shouldRun = FALSE;

    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || GetBattlerSide(battler) != B_SIDE_OPPONENT)
        return TRAINER_SLIDE_TARGET_NONE;

    SetTrainerSlideParamters(battler, &firstId, &lastId, &trainerId, &retValue);
    enum DifficultyLevel difficulty = GetTrainerDifficultyLevel(trainerId);

    gBattleScripting.battler = battler;

    if (IsTrainerSlidePlayed(slideId))
        return TRAINER_SLIDE_TARGET_NONE;

    if (!DoesTrainerHaveSlideMessage(difficulty,trainerId,slideId))
        return TRAINER_SLIDE_TARGET_NONE;

    switch (slideId)
    {
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstCriticalHit(slideId);
            break;
        case TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT:
            shouldRun = ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(slideId);
            break;
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(battler, slideId);
            break;
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstSTABMove(firstId, lastId, slideId);
            break;
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstDown(firstId, lastId);
            break;
        case TRAINER_SLIDE_ENEMY_MON_UNAFFECTED:
            shouldRun = ShouldRunTrainerSlideEnemyMonUnaffected(firstId, lastId, slideId);
            break;
        case TRAINER_SLIDE_LAST_SWITCHIN:
            shouldRun = ShouldRunTrainerSlideLastSwitchIn(battler);
            break;
        case TRAINER_SLIDE_LAST_HALF_HP:
            shouldRun = ShouldRunTrainerSlideLastHalfHP(firstId, lastId, battler);
            break;
        case TRAINER_SLIDE_LAST_LOW_HP:
            shouldRun = ShouldRunTrainerSlideLastLowHp(firstId, lastId, battler);
            break;
        case TRAINER_SLIDE_BEFORE_FIRST_TURN:
        case TRAINER_SLIDE_MEGA_EVOLUTION:
        case TRAINER_SLIDE_Z_MOVE:
        case TRAINER_SLIDE_DYNAMAX:
            shouldRun = TRUE;
            break;
        default:
            return TRAINER_SLIDE_TARGET_NONE;
    }

    if (shouldRun == FALSE)
        return TRAINER_SLIDE_TARGET_NONE;

    MarkTrainerSlideAsPlayed(slideId);
    SetTrainerSlideMessage(difficulty,trainerId,slideId);
    return retValue;
}

static bool32 IsSlideInitalizedOrPlayed(enum TrainerSlideType slideId)
{
    if (IsTrainerSlideInitialized(slideId))
        return TRUE;

    if (IsTrainerSlidePlayed(slideId))
        return TRUE;

    return FALSE;
}

void TryInitalizeFirstSTABMoveTrainerSlide(u32 battlerDef, u32 battlerAtk, u32 moveType)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE;

    if (IsSlideInitalizedOrPlayed(slideId))
        return;

    if ((GetBattlerSide(battlerDef) == B_SIDE_PLAYER))
        return;

    if (IS_BATTLER_OF_TYPE(battlerAtk, moveType) == FALSE)
        return;

    InitalizeTrainerSlide(slideId);
}

void TryInitalizeTrainerSlidePlayerLandsFirstCriticalHit(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT;

    if (IsSlideInitalizedOrPlayed(slideId))
        return;

    if (GetBattlerSide(target) == B_SIDE_PLAYER)
        return;

    InitalizeTrainerSlide(slideId);
}

void TryInitalizeTrainerSlideEnemyLandsFirstCriticalHit(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT;

    if (IsSlideInitalizedOrPlayed(slideId))
        return;

    if (GetBattlerSide(target) == B_SIDE_OPPONENT)
        return;

    InitalizeTrainerSlide(slideId);
}

void TryInitalizeTrainerSlidePlayerLandsFirstSuperEffectiveHit(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT;

    if (IsSlideInitalizedOrPlayed(slideId))
        return;

    if (GetBattlerSide(target) == B_SIDE_PLAYER)
        return;

    InitalizeTrainerSlide(slideId);
}

void TryInitalizeTrainerSlideEnemyMonUnaffected(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_ENEMY_MON_UNAFFECTED;

    if (IsSlideInitalizedOrPlayed(slideId))
        return;

    if (GetBattlerSide(target) != B_SIDE_OPPONENT)
        return;

    InitalizeTrainerSlide(slideId);
}

bool32 IsTrainerSlideInitialized(enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    return (gBattleStruct->slideMessageStatus.messageInitalized[arrayIndex] & (1 << bitPosition)) != 0;
}

bool32 IsTrainerSlidePlayed(enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    return (gBattleStruct->slideMessageStatus.messagePlayed[arrayIndex] & (1 << bitPosition)) != 0;
}

void InitalizeTrainerSlide(enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    gBattleStruct->slideMessageStatus.messageInitalized[arrayIndex] |= (1 << bitPosition);
}

void MarkTrainerSlideAsPlayed(enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    gBattleStruct->slideMessageStatus.messagePlayed[arrayIndex] |= (1 << bitPosition);
}
