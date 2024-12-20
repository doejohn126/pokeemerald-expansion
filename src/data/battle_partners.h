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
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 19
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 18
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 17
            .lvl = 42,
#line 16
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 20
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 25
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 29
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 28
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 27
            .lvl = 43,
#line 26
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 30
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 35
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 39
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 38
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 37
            .lvl = 44,
#line 36
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 40
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
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
            .species = SPECIES_EMPOLEON,
#line 52
            .gender = TRAINER_MON_FEMALE,
#line 54
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 53
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 56
            .species = SPECIES_CLEFABLE,
#line 56
            .gender = TRAINER_MON_FEMALE,
#line 58
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 57
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 60
            .species = SPECIES_PILOSWINE,
#line 60
            .gender = TRAINER_MON_MALE,
#line 62
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 61
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 64
    [PARTNER_BRENDAN_TREECKO] =
    {
#line 65
        .trainerName = _("Brendan"),
#line 66
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 67
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 69
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 70
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 73
            .species = SPECIES_SWELLOW,
#line 73
            .gender = TRAINER_MON_FEMALE,
#line 76
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 75
            .ability = ABILITY_AERILATE,
#line 74
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 77
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 82
            .species = SPECIES_VENUSAUR,
#line 82
            .gender = TRAINER_MON_MALE,
#line 84
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 83
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 85
                MOVE_GIGA_DRAIN,
                MOVE_SLEEP_POWDER,
                MOVE_LEECH_SEED,
                MOVE_SLUDGE_BOMB,
            },
            },
            {
#line 90
            .species = SPECIES_BLAZIKEN,
#line 90
            .gender = TRAINER_MON_FEMALE,
#line 92
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 91
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 93
                MOVE_ACROBATICS,
                MOVE_LOW_KICK,
                MOVE_FLAMETHROWER,
                MOVE_BOUNCE,
            },
            },
        },
    },
#line 98
    [PARTNER_BRENDAN_TORCHIC] =
    {
#line 99
        .trainerName = _("Brendan"),
#line 100
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 101
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 103
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 104
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 107
            .species = SPECIES_SWELLOW,
#line 107
            .gender = TRAINER_MON_FEMALE,
#line 110
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 109
            .ability = ABILITY_AERILATE,
#line 108
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 111
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 116
            .species = SPECIES_SKELEDIRGE,
#line 116
            .gender = TRAINER_MON_MALE,
#line 118
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 117
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 119
                MOVE_TORCH_SONG,
                MOVE_SHADOW_BALL,
                MOVE_SNARL,
                MOVE_ROAR,
            },
            },
            {
#line 124
            .species = SPECIES_SWAMPERT,
#line 124
            .gender = TRAINER_MON_FEMALE,
#line 126
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 125
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 127
                MOVE_MUDDY_WATER,
                MOVE_ROCK_SLIDE,
                MOVE_EARTHQUAKE,
                MOVE_AMNESIA,
            },
            },
        },
    },
#line 132
    [PARTNER_BRENDAN_MUDKIP] =
    {
#line 133
        .trainerName = _("Brendan"),
#line 134
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 135
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 137
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 138
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 141
            .species = SPECIES_SWELLOW,
#line 141
            .gender = TRAINER_MON_FEMALE,
#line 144
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 143
            .ability = ABILITY_AERILATE,
#line 142
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 145
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 150
            .species = SPECIES_GRENINJA,
#line 150
            .gender = TRAINER_MON_MALE,
#line 152
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 151
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 153
                MOVE_NIGHT_SLASH,
                MOVE_WATER_SHURIKEN,
                MOVE_SHADOW_SNEAK,
                MOVE_ROLE_PLAY,
            },
            },
            {
#line 158
            .species = SPECIES_SCEPTILE,
#line 158
            .gender = TRAINER_MON_FEMALE,
#line 160
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 159
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 161
                MOVE_LEAF_BLADE,
                MOVE_X_SCISSOR,
                MOVE_SHED_TAIL,
                MOVE_DETECT,
            },
            },
        },
    },
#line 166
    [PARTNER_MAY_TREECKO] =
    {
#line 167
        .trainerName = _("May"),
#line 168
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 169
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 170
F_TRAINER_FEMALE | 
#line 171
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 172
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 175
            .species = SPECIES_SWELLOW,
#line 175
            .gender = TRAINER_MON_FEMALE,
#line 178
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 177
            .ability = ABILITY_AERILATE,
#line 176
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 179
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 184
            .species = SPECIES_MEGANIUM,
#line 184
            .gender = TRAINER_MON_FEMALE,
#line 187
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 186
            .ability = ABILITY_TRIAGE,
#line 185
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 188
                MOVE_ENERGY_BALL,
                MOVE_REFLECT,
                MOVE_DAZZLING_GLEAM,
                MOVE_SYNTHESIS,
            },
            },
            {
#line 193
            .species = SPECIES_BLAZIKEN,
#line 193
            .gender = TRAINER_MON_MALE,
#line 195
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 194
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 196
                MOVE_ACROBATICS,
                MOVE_LOW_KICK,
                MOVE_FLAMETHROWER,
                MOVE_BOUNCE,
            },
            },
        },
    },
#line 201
    [PARTNER_MAY_TORCHIC] =
    {
#line 202
        .trainerName = _("May"),
#line 203
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 204
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 205
F_TRAINER_FEMALE | 
#line 206
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 207
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 210
            .species = SPECIES_SWELLOW,
#line 210
            .gender = TRAINER_MON_FEMALE,
#line 213
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 212
            .ability = ABILITY_AERILATE,
#line 211
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 214
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 219
            .species = SPECIES_DELPHOX,
#line 219
            .gender = TRAINER_MON_FEMALE,
#line 221
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 220
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 222
                MOVE_MYSTICAL_FIRE,
                MOVE_LIGHT_SCREEN,
                MOVE_SHADOW_BALL,
                MOVE_PSYSHOCK,
            },
            },
            {
#line 227
            .species = SPECIES_SWAMPERT,
#line 227
            .gender = TRAINER_MON_MALE,
#line 229
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 228
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 230
                MOVE_MUDDY_WATER,
                MOVE_ROCK_SLIDE,
                MOVE_EARTHQUAKE,
                MOVE_AMNESIA,
            },
            },
        },
    },
#line 235
    [PARTNER_MAY_MUDKIP] =
    {
#line 236
        .trainerName = _("May"),
#line 237
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 238
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender = 
#line 240
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 241
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 244
            .species = SPECIES_SWELLOW,
#line 244
            .gender = TRAINER_MON_FEMALE,
#line 247
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 246
            .ability = ABILITY_AERILATE,
#line 245
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 248
                MOVE_AIR_SLASH,
                MOVE_BOOMBURST,
                MOVE_ROOST,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 253
            .species = SPECIES_PRIMARINA,
#line 253
            .gender = TRAINER_MON_FEMALE,
#line 255
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 254
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 256
                MOVE_SPARKLING_ARIA,
                MOVE_MISTY_TERRAIN,
                MOVE_DRAINING_KISS,
                MOVE_ICY_WIND,
            },
            },
            {
#line 261
            .species = SPECIES_SCEPTILE,
#line 261
            .gender = TRAINER_MON_MALE,
#line 263
            .iv = TRAINER_PARTY_IVS(23, 23, 23, 23, 23, 23),
#line 262
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 264
                MOVE_LEAF_BLADE,
                MOVE_X_SCISSOR,
                MOVE_SHED_TAIL,
                MOVE_DETECT,
            },
            },
        },
    },
#line 269
    [PARTNER_JAYDEN] =
    {
#line 270
        .trainerName = _("Jayden"),
#line 271
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 272
        .trainerPic = TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN,
        .encounterMusic_gender = 
#line 274
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 275
        .items = { ITEM_MAX_POTION, ITEM_HYPER_POTION },
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 277
            .species = SPECIES_JOLTEON,
#line 277
            .gender = TRAINER_MON_FEMALE,
#line 280
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 279
            .ability = ABILITY_VOLT_ABSORB,
#line 278
            .lvl = 73,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 281
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
                MOVE_VOLT_SWITCH,
                MOVE_ALLURING_VOICE,
            },
            },
            {
#line 286
            .species = SPECIES_FERALIGATR,
#line 286
            .gender = TRAINER_MON_MALE,
#line 289
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 288
            .ability = ABILITY_STRONG_JAW,
#line 287
            .lvl = 74,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 290
                MOVE_CRUNCH,
                MOVE_ICE_FANG,
                MOVE_AQUA_JET,
                MOVE_WATERFALL,
            },
            },
            {
#line 295
            .species = SPECIES_CHARIZARD,
#line 295
            .gender = TRAINER_MON_MALE,
#line 295
            .heldItem = ITEM_CHARIZARDITE_X,
#line 297
            .iv = TRAINER_PARTY_IVS(26, 25, 25, 26, 25, 25),
#line 296
            .lvl = 75,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 298
                MOVE_DRAGON_CLAW,
                MOVE_FLARE_BLITZ,
                MOVE_AIR_SLASH,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
