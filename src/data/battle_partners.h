//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [PARTNER_NONE] =
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
#line 8
    [PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("Steven"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender = 
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 19
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 18
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 17
            .lvl = 75,
#line 16
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 20
                MOVE_BRAVE_BIRD,
                MOVE_BODY_PRESS,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 25
            .species = SPECIES_GOODRA_HISUI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 29
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 28
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 27
            .lvl = 75,
#line 26
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 30
                MOVE_THUNDERBOLT,
                MOVE_DRAGON_PULSE,
                MOVE_SHELTER,
                MOVE_FLASH_CANNON,
            },
            },
            {
#line 35
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 35
            .heldItem = ITEM_METAGROSSITE,
#line 39
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 38
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 37
            .lvl = 76,
#line 36
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 40
                MOVE_METEOR_MASH,
                MOVE_ZEN_HEADBUTT,
                MOVE_REFLECT,
                MOVE_BULLET_PUNCH,
            },
            },
        },
    },
#line 45
    [PARTNER_DAWN] =
    {
#line 46
        .trainerName = _("Dawn"),
#line 47
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 48
        .trainerPic = TRAINER_BACK_PIC_DAWN,
        .encounterMusic_gender = 
#line 49
F_TRAINER_FEMALE | 
#line 50
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 52
            .species = SPECIES_CLEFABLE,
#line 52
            .gender = TRAINER_MON_FEMALE,
#line 55
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 54
            .ability = ABILITY_MAGIC_GUARD,
#line 53
            .lvl = 84,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 56
                MOVE_MOONBLAST,
                MOVE_METRONOME,
                MOVE_THUNDERBOLT,
                MOVE_FLAMETHROWER,
            },
            },
            {
#line 61
            .species = SPECIES_EMPOLEON,
#line 61
            .gender = TRAINER_MON_MALE,
#line 64
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 63
            .ability = ABILITY_COMPETITIVE,
#line 62
            .lvl = 85,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 65
                MOVE_ICE_BEAM,
                MOVE_HYDRO_PUMP,
                MOVE_FLASH_CANNON,
                MOVE_STEALTH_ROCK,
            },
            },
            {
#line 70
            .species = SPECIES_LOPUNNY,
#line 70
            .gender = TRAINER_MON_FEMALE,
#line 70
            .heldItem = ITEM_LOPUNNITE,
#line 73
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 71
            .lvl = 86,
#line 72
            .friendship = 240,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 74
                MOVE_FAKE_OUT,
                MOVE_RETURN,
                MOVE_HIGH_JUMP_KICK,
                MOVE_TRIPLE_AXEL,
            },
            },
        },
    },
#line 79
    [PARTNER_BRENDAN_TREECKO] =
    {
#line 80
        .trainerName = _("Brendan"),
#line 81
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 82
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 84
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 85
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 88
            .species = SPECIES_SWELLOW,
#line 88
            .gender = TRAINER_MON_FEMALE,
#line 91
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 90
            .ability = ABILITY_AERILATE,
#line 89
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 92
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 97
            .species = SPECIES_VENUSAUR,
#line 97
            .gender = TRAINER_MON_MALE,
#line 99
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 98
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 100
                MOVE_GIGA_DRAIN,
                MOVE_SLEEP_POWDER,
                MOVE_LEECH_SEED,
                MOVE_SLUDGE_BOMB,
            },
            },
            {
#line 105
            .species = SPECIES_BLAZIKEN,
#line 105
            .gender = TRAINER_MON_FEMALE,
#line 107
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 106
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 108
                MOVE_ACROBATICS,
                MOVE_LOW_KICK,
                MOVE_FLAMETHROWER,
                MOVE_BOUNCE,
            },
            },
        },
    },
#line 113
    [PARTNER_BRENDAN_TORCHIC] =
    {
#line 114
        .trainerName = _("Brendan"),
#line 115
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 116
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 118
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 119
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 122
            .species = SPECIES_SWELLOW,
#line 122
            .gender = TRAINER_MON_FEMALE,
#line 125
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 124
            .ability = ABILITY_AERILATE,
#line 123
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 126
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 131
            .species = SPECIES_SKELEDIRGE,
#line 131
            .gender = TRAINER_MON_MALE,
#line 133
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 132
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 134
                MOVE_TORCH_SONG,
                MOVE_SHADOW_BALL,
                MOVE_SNARL,
                MOVE_ROAR,
            },
            },
            {
#line 139
            .species = SPECIES_SWAMPERT,
#line 139
            .gender = TRAINER_MON_FEMALE,
#line 141
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 140
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 142
                MOVE_MUDDY_WATER,
                MOVE_ROCK_SLIDE,
                MOVE_EARTHQUAKE,
                MOVE_AMNESIA,
            },
            },
        },
    },
#line 147
    [PARTNER_BRENDAN_MUDKIP] =
    {
#line 148
        .trainerName = _("Brendan"),
#line 149
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 150
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 152
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 153
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 156
            .species = SPECIES_SWELLOW,
#line 156
            .gender = TRAINER_MON_FEMALE,
#line 159
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 158
            .ability = ABILITY_AERILATE,
#line 157
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 160
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 165
            .species = SPECIES_GRENINJA,
#line 165
            .gender = TRAINER_MON_MALE,
#line 167
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 166
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 168
                MOVE_NIGHT_SLASH,
                MOVE_WATER_SHURIKEN,
                MOVE_SHADOW_SNEAK,
                MOVE_ROLE_PLAY,
            },
            },
            {
#line 173
            .species = SPECIES_SCEPTILE,
#line 173
            .gender = TRAINER_MON_FEMALE,
#line 175
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 174
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 176
                MOVE_LEAF_BLADE,
                MOVE_X_SCISSOR,
                MOVE_SHED_TAIL,
                MOVE_DETECT,
            },
            },
        },
    },
#line 181
    [PARTNER_MAY_TREECKO] =
    {
#line 182
        .trainerName = _("May"),
#line 183
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 184
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 185
F_TRAINER_FEMALE | 
#line 186
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 187
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 190
            .species = SPECIES_SWELLOW,
#line 190
            .gender = TRAINER_MON_FEMALE,
#line 193
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 192
            .ability = ABILITY_AERILATE,
#line 191
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 194
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 199
            .species = SPECIES_MEGANIUM,
#line 199
            .gender = TRAINER_MON_FEMALE,
#line 202
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 201
            .ability = ABILITY_TRIAGE,
#line 200
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 203
                MOVE_ENERGY_BALL,
                MOVE_REFLECT,
                MOVE_DAZZLING_GLEAM,
                MOVE_SYNTHESIS,
            },
            },
            {
#line 208
            .species = SPECIES_BLAZIKEN,
#line 208
            .gender = TRAINER_MON_MALE,
#line 210
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 209
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 211
                MOVE_ACROBATICS,
                MOVE_LOW_KICK,
                MOVE_FLAMETHROWER,
                MOVE_BOUNCE,
            },
            },
        },
    },
#line 216
    [PARTNER_MAY_TORCHIC] =
    {
#line 217
        .trainerName = _("May"),
#line 218
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 219
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 220
F_TRAINER_FEMALE | 
#line 221
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 222
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 225
            .species = SPECIES_SWELLOW,
#line 225
            .gender = TRAINER_MON_FEMALE,
#line 228
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 227
            .ability = ABILITY_AERILATE,
#line 226
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 229
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 234
            .species = SPECIES_DELPHOX,
#line 234
            .gender = TRAINER_MON_FEMALE,
#line 236
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 235
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 237
                MOVE_MYSTICAL_FIRE,
                MOVE_LIGHT_SCREEN,
                MOVE_SHADOW_BALL,
                MOVE_PSYSHOCK,
            },
            },
            {
#line 242
            .species = SPECIES_SWAMPERT,
#line 242
            .gender = TRAINER_MON_MALE,
#line 244
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 243
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 245
                MOVE_MUDDY_WATER,
                MOVE_ROCK_SLIDE,
                MOVE_EARTHQUAKE,
                MOVE_AMNESIA,
            },
            },
        },
    },
#line 250
    [PARTNER_MAY_MUDKIP] =
    {
#line 251
        .trainerName = _("May"),
#line 252
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 253
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 255
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 256
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 259
            .species = SPECIES_SWELLOW,
#line 259
            .gender = TRAINER_MON_FEMALE,
#line 262
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 261
            .ability = ABILITY_AERILATE,
#line 260
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 263
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 268
            .species = SPECIES_PRIMARINA,
#line 268
            .gender = TRAINER_MON_FEMALE,
#line 270
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 269
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 271
                MOVE_SPARKLING_ARIA,
                MOVE_MISTY_TERRAIN,
                MOVE_DRAINING_KISS,
                MOVE_ICY_WIND,
            },
            },
            {
#line 276
            .species = SPECIES_SCEPTILE,
#line 276
            .gender = TRAINER_MON_MALE,
#line 278
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 277
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 279
                MOVE_LEAF_BLADE,
                MOVE_X_SCISSOR,
                MOVE_SHED_TAIL,
                MOVE_DETECT,
            },
            },
        },
    },
#line 284
    [PARTNER_JAYDEN] =
    {
#line 285
        .trainerName = _("Jayden"),
#line 286
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 287
        .trainerPic = TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN,
        .encounterMusic_gender = 
#line 289
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 290
        .items = { ITEM_MAX_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 292
            .species = SPECIES_JOLTEON,
#line 292
            .gender = TRAINER_MON_FEMALE,
#line 295
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 294
            .ability = ABILITY_VOLT_ABSORB,
#line 293
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 296
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
                MOVE_VOLT_SWITCH,
                MOVE_ALLURING_VOICE,
            },
            },
            {
#line 301
            .species = SPECIES_FERALIGATR,
#line 301
            .gender = TRAINER_MON_MALE,
#line 304
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 303
            .ability = ABILITY_STRONG_JAW,
#line 302
            .lvl = 74,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 305
                MOVE_CRUNCH,
                MOVE_ICE_FANG,
                MOVE_AQUA_JET,
                MOVE_WATERFALL,
            },
            },
            {
#line 310
            .species = SPECIES_CHARIZARD,
#line 310
            .gender = TRAINER_MON_MALE,
#line 310
            .heldItem = ITEM_CHARIZARDITE_X,
#line 312
            .iv = TRAINER_PARTY_IVS(26, 25, 25, 26, 25, 25),
#line 311
            .lvl = 75,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 313
                MOVE_DRAGON_CLAW,
                MOVE_FLARE_BLITZ,
                MOVE_AIR_SLASH,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
