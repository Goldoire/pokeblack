#ifndef POKEBLACK_OV021_FLD_PLAYER_CORE_H
#define POKEBLACK_OV021_FLD_PLAYER_CORE_H

/*
 * FieldPlayer -- the overworld player-avatar context of ov021
 * (GameFreak's `field_player_core.c`, __FILE__ string at 0x021DDEB8;
 * TU spans 0x021A36E4..0x021A4140).
 *
 * PROPOSAL for include/. Gen-4 ancestor: pokeheartgold `PlayerAvatar`.
 *
 * Size is 0x34, proven by the allocation at 0x021A36FC:
 *     movs r1,#0x34 ; movs r2,#1 ; blx FUN_02030734
 */

typedef struct FieldPlayer {
    /* 0x00 */ void *unk00;
    /* 0x04 */ void *ovyManager;   // ctor: = FieldSystem_GetOvyManager(fieldSystem) (0x02188C80)
    /* 0x08 */ void *fieldSystem;  // acc 0x021A395C; ctor arg 1
    /* 0x0C */ void *unk0C;        // acc 0x021A3994; ctor arg 0; fed to sub_02012B28/2C/30/34
    /* 0x10 */ void *unk10;        // acc 0x021A3970 (get) / 0x021A396C (set)
    /* 0x14 */ void *unk14;        // acc 0x021A3968 (get) / 0x021A3964 (set)
    /* 0x18 */ void *unk18;        // acc 0x021A398C; ctor arg 3
    /* 0x1C */ void *mapObject;    // acc 0x021A3960; = sub_0216DE94(fieldSystem->unk038, 0xFF);
                                   // every use forwards into the ov010 MMDL API at 0x0216Dxxx
    /* 0x20 */ u16 unk20;          // ctor: = 9
    /* 0x22 */ u16 unk22;          // ctor: = 9
    /* 0x24 */ u32 unk24;
    /* 0x28 */ void *unk28;        // acc 0x021A3AD4 (get) / 0x021A3ACC (set)
    /* 0x2C */ u16 unk2C;          // step counter, cleared at 0x021A39DE
    /* 0x2E */ u16 unk2E;
    /* 0x30 */ u32 unk30;
} FieldPlayer;                     // size 0x34

#endif // POKEBLACK_OV021_FLD_PLAYER_CORE_H
