//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
#line 7
    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 9
#line 15
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 10
        .trainerName = _("Steven"),
#line 11
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 12
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender = 
#line 14
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 17
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 21
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 20
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 19
            .lvl = 75,
#line 18
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 22
                MOVE_BRAVE_BIRD,
                MOVE_BODY_PRESS,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 27
            .species = SPECIES_GOODRA_HISUI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 31
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 30
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 29
            .lvl = 75,
#line 28
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 32
                MOVE_THUNDERBOLT,
                MOVE_DRAGON_PULSE,
                MOVE_SHELTER,
                MOVE_FLASH_CANNON,
            },
            },
            {
#line 37
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 37
            .heldItem = ITEM_METAGROSSITE,
#line 41
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 40
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 39
            .lvl = 76,
#line 38
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 42
                MOVE_METEOR_MASH,
                MOVE_ZEN_HEADBUTT,
                MOVE_REFLECT,
                MOVE_BULLET_PUNCH,
            },
            },
        },
    },
#line 47
#line 53
    [DIFFICULTY_NORMAL][PARTNER_DAWN] =
    {
#line 48
        .trainerName = _("Dawn"),
#line 49
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 50
        .trainerPic = TRAINER_BACK_PIC_DAWN,
        .encounterMusic_gender = 
#line 51
F_TRAINER_FEMALE | 
#line 52
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 55
            .species = SPECIES_CLEFABLE,
#line 55
            .gender = TRAINER_MON_FEMALE,
#line 58
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 57
            .ability = ABILITY_MAGIC_GUARD,
#line 56
            .lvl = 84,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 59
                MOVE_MOONBLAST,
                MOVE_METRONOME,
                MOVE_THUNDERBOLT,
                MOVE_FLAMETHROWER,
            },
            },
            {
#line 64
            .species = SPECIES_EMPOLEON,
#line 64
            .gender = TRAINER_MON_MALE,
#line 67
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 66
            .ability = ABILITY_COMPETITIVE,
#line 65
            .lvl = 85,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 68
                MOVE_ICE_BEAM,
                MOVE_HYDRO_PUMP,
                MOVE_FLASH_CANNON,
                MOVE_STEALTH_ROCK,
            },
            },
            {
#line 73
            .species = SPECIES_LOPUNNY,
#line 73
            .gender = TRAINER_MON_FEMALE,
#line 73
            .heldItem = ITEM_LOPUNNITE,
#line 76
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 74
            .lvl = 86,
#line 75
            .friendship = 240,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 77
                MOVE_FAKE_OUT,
                MOVE_RETURN,
                MOVE_HIGH_JUMP_KICK,
                MOVE_TRIPLE_AXEL,
            },
            },
        },
    },
#line 82
#line 89
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_TREECKO] =
    {
#line 83
        .trainerName = _("Brendan"),
#line 84
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 85
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 87
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 88
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 92
            .species = SPECIES_SWELLOW,
#line 92
            .gender = TRAINER_MON_FEMALE,
#line 95
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 94
            .ability = ABILITY_AERILATE,
#line 93
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 96
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 101
            .species = SPECIES_VENUSAUR,
#line 101
            .gender = TRAINER_MON_MALE,
#line 103
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 102
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 104
                MOVE_GIGA_DRAIN,
                MOVE_SLEEP_POWDER,
                MOVE_LEECH_SEED,
                MOVE_SLUDGE_BOMB,
            },
            },
            {
#line 109
            .species = SPECIES_BLAZIKEN,
#line 109
            .gender = TRAINER_MON_FEMALE,
#line 111
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 110
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 112
                MOVE_ACROBATICS,
                MOVE_LOW_KICK,
                MOVE_FLAMETHROWER,
                MOVE_BOUNCE,
            },
            },
        },
    },
#line 117
#line 124
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_TORCHIC] =
    {
#line 118
        .trainerName = _("Brendan"),
#line 119
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 120
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 122
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 123
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 127
            .species = SPECIES_SWELLOW,
#line 127
            .gender = TRAINER_MON_FEMALE,
#line 130
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 129
            .ability = ABILITY_AERILATE,
#line 128
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 131
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 136
            .species = SPECIES_SKELEDIRGE,
#line 136
            .gender = TRAINER_MON_MALE,
#line 138
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 137
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 139
                MOVE_TORCH_SONG,
                MOVE_SHADOW_BALL,
                MOVE_SNARL,
                MOVE_ROAR,
            },
            },
            {
#line 144
            .species = SPECIES_SWAMPERT,
#line 144
            .gender = TRAINER_MON_FEMALE,
#line 146
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 145
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 147
                MOVE_MUDDY_WATER,
                MOVE_ROCK_SLIDE,
                MOVE_EARTHQUAKE,
                MOVE_AMNESIA,
            },
            },
        },
    },
#line 152
#line 159
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_MUDKIP] =
    {
#line 153
        .trainerName = _("Brendan"),
#line 154
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 155
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 157
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 158
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 162
            .species = SPECIES_SWELLOW,
#line 162
            .gender = TRAINER_MON_FEMALE,
#line 165
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 164
            .ability = ABILITY_AERILATE,
#line 163
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 166
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 171
            .species = SPECIES_GRENINJA,
#line 171
            .gender = TRAINER_MON_MALE,
#line 173
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 172
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 174
                MOVE_NIGHT_SLASH,
                MOVE_WATER_SHURIKEN,
                MOVE_SHADOW_SNEAK,
                MOVE_ROLE_PLAY,
            },
            },
            {
#line 179
            .species = SPECIES_SCEPTILE,
#line 179
            .gender = TRAINER_MON_FEMALE,
#line 181
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 180
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 182
                MOVE_LEAF_BLADE,
                MOVE_X_SCISSOR,
                MOVE_SHED_TAIL,
                MOVE_DETECT,
            },
            },
        },
    },
#line 187
#line 194
    [DIFFICULTY_NORMAL][PARTNER_MAY_TREECKO] =
    {
#line 188
        .trainerName = _("May"),
#line 189
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 190
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 191
F_TRAINER_FEMALE | 
#line 192
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 193
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 197
            .species = SPECIES_SWELLOW,
#line 197
            .gender = TRAINER_MON_FEMALE,
#line 200
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 199
            .ability = ABILITY_AERILATE,
#line 198
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 201
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 206
            .species = SPECIES_MEGANIUM,
#line 206
            .gender = TRAINER_MON_FEMALE,
#line 209
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 208
            .ability = ABILITY_TRIAGE,
#line 207
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 210
                MOVE_ENERGY_BALL,
                MOVE_REFLECT,
                MOVE_DAZZLING_GLEAM,
                MOVE_SYNTHESIS,
            },
            },
            {
#line 215
            .species = SPECIES_BLAZIKEN,
#line 215
            .gender = TRAINER_MON_MALE,
#line 217
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 216
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 218
                MOVE_ACROBATICS,
                MOVE_LOW_KICK,
                MOVE_FLAMETHROWER,
                MOVE_BOUNCE,
            },
            },
        },
    },
#line 223
#line 230
    [DIFFICULTY_NORMAL][PARTNER_MAY_TORCHIC] =
    {
#line 224
        .trainerName = _("May"),
#line 225
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 226
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 227
F_TRAINER_FEMALE | 
#line 228
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 229
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 233
            .species = SPECIES_SWELLOW,
#line 233
            .gender = TRAINER_MON_FEMALE,
#line 236
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 235
            .ability = ABILITY_AERILATE,
#line 234
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 237
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 242
            .species = SPECIES_DELPHOX,
#line 242
            .gender = TRAINER_MON_FEMALE,
#line 244
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 243
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 245
                MOVE_MYSTICAL_FIRE,
                MOVE_LIGHT_SCREEN,
                MOVE_SHADOW_BALL,
                MOVE_PSYSHOCK,
            },
            },
            {
#line 250
            .species = SPECIES_SWAMPERT,
#line 250
            .gender = TRAINER_MON_MALE,
#line 252
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 251
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 253
                MOVE_MUDDY_WATER,
                MOVE_ROCK_SLIDE,
                MOVE_EARTHQUAKE,
                MOVE_AMNESIA,
            },
            },
        },
    },
#line 258
#line 265
    [DIFFICULTY_NORMAL][PARTNER_MAY_MUDKIP] =
    {
#line 259
        .trainerName = _("May"),
#line 260
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 261
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 263
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 264
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 268
            .species = SPECIES_SWELLOW,
#line 268
            .gender = TRAINER_MON_FEMALE,
#line 271
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 270
            .ability = ABILITY_AERILATE,
#line 269
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 272
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 277
            .species = SPECIES_PRIMARINA,
#line 277
            .gender = TRAINER_MON_FEMALE,
#line 279
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 278
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 280
                MOVE_SPARKLING_ARIA,
                MOVE_MISTY_TERRAIN,
                MOVE_DRAINING_KISS,
                MOVE_ICY_WIND,
            },
            },
            {
#line 285
            .species = SPECIES_SCEPTILE,
#line 285
            .gender = TRAINER_MON_MALE,
#line 287
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 286
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 288
                MOVE_LEAF_BLADE,
                MOVE_X_SCISSOR,
                MOVE_SHED_TAIL,
                MOVE_DETECT,
            },
            },
        },
    },
#line 293
#line 300
    [DIFFICULTY_NORMAL][PARTNER_JAYDEN] =
    {
#line 294
        .trainerName = _("Jayden"),
#line 295
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 296
        .trainerPic = TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN,
        .encounterMusic_gender = 
#line 298
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 299
        .items = { ITEM_MAX_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 302
            .species = SPECIES_JOLTEON,
#line 302
            .gender = TRAINER_MON_FEMALE,
#line 305
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 304
            .ability = ABILITY_VOLT_ABSORB,
#line 303
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 306
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
                MOVE_VOLT_SWITCH,
                MOVE_ALLURING_VOICE,
            },
            },
            {
#line 311
            .species = SPECIES_FERALIGATR,
#line 311
            .gender = TRAINER_MON_MALE,
#line 314
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 313
            .ability = ABILITY_STRONG_JAW,
#line 312
            .lvl = 74,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 315
                MOVE_CRUNCH,
                MOVE_ICE_FANG,
                MOVE_AQUA_JET,
                MOVE_WATERFALL,
            },
            },
            {
#line 320
            .species = SPECIES_CHARIZARD,
#line 320
            .gender = TRAINER_MON_MALE,
#line 320
            .heldItem = ITEM_CHARIZARDITE_X,
#line 322
            .iv = TRAINER_PARTY_IVS(26, 25, 25, 26, 25, 25),
#line 321
            .lvl = 75,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 323
                MOVE_DRAGON_CLAW,
                MOVE_FLARE_BLITZ,
                MOVE_AIR_SLASH,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
