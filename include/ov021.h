#ifndef POKEBLACK_OV021_H
#define POKEBLACK_OV021_H

#include "global.h"
#include "gf_fwd.h"   /* FieldSystem is registered opaque there */
/*
 * ===========================================================================
 *  ov021 -- FieldSystem, the overworld context
 * ===========================================================================
 *
 * PROMOTED from src/ov021/fld_fieldsys.h. Delete that file and include this.
 *
 * GameFreak's own name for the translation unit is `fieldmap.c`, recovered
 * from the assert __FILE__ string at 0x021DD9C0.
 *
 * Size 0x154 is proven by the allocation in FieldSystem_New (0x02188030):
 *     Heap_AllocTagged(heapId, 0x154, 1, "fieldmap.c", 521)
 * and 49 of the 85 word slots are each pinned to a byte-exact accessor, named
 * in the comment on the field ("acc <addr>").
 *
 * DO NOT RECONCILE AGAINST GEN 4. pokeheartgold's FieldSystem is 0x128 and
 * gen 5 reordered the head of the struct. The subsystem *set* is recognisable
 * -- camera, light, fog, weather, encounter, task manager -- and that is
 * exactly what makes the temptation dangerous: the names transfer and the
 * offsets do not.
 *
 * GRADES: a field with an "acc" comment is PROVEN. A bare `void *unkNNN` is a
 * word slot of the right size at the right offset whose purpose is unknown --
 * the offset is proven by the struct size and the fields around it, the
 * meaning is not.
 */


/*
 * The map-load "mode" vtable that FieldSystem+0x108 points at. It comes out of
 * a static table at 0x021D373C indexed by map class (func_02189BA8), and the
 * ROM calls two of its slots: +0x08 from the field main loop at 0x021887BA and
 * +0x0C from the teardown at 0x02188A7A. Slot +0x00 is an int read by the
 * accessor at 0x02188CF0.
 */
typedef struct FieldMapMode {
    /* 0x00 */ int id;
    /* 0x04 */ void *unk04;
    /* 0x08 */ void (*main)(FieldSystem *fieldSystem, void *a1);
    /* 0x0C */ void (*exit)(FieldSystem *fieldSystem);
} FieldMapMode;

struct FieldSystem {
    /* 0x000 */ u16 heapId;      // acc 0x02188C84; FieldSystem_New strh's the heapId arg here
    /* 0x002 */ u16 unk002;
    /* 0x004 */ void *ovyManager; // acc 0x02188C80; fed to sub_020120D8/F4/F8 (OverlayManager API)
    /* 0x008 */ void *unk008;    // = sub_020120F4(ovyManager) in the ctor
    /* 0x00C */ void *unk00C;    // acc 0x02188D58; = sub_0201407C(...), destroyed by sub_020140B4
    /* 0x010 */ void *camera;    // acc 0x02188C58; fed to field_camera.c (0x0218ED3C)
    /* 0x014 */ void *light;     // acc 0x02188C60; freed by field_light.c 0x021A0448
    /* 0x018 */ void *fog;       // acc 0x02188C64; freed by field_fog.c 0x021A0138
    /* 0x01C */ void *zoneFog;   // acc 0x02188C68; freed by field_zonefog.c 0x021A02F4
    /* 0x020 */ void *weather;   // acc 0x02188C6C; freed by weather.c 0x021A1AAC, then NULLed
    /* 0x024 */ void *subScreen; // acc 0x02188CCC; field_subscreen.c 0x021A0D44/0x021A0E58
    /* 0x028 */ void *unk028;    // acc 0x02188C54; nullable; field_msgbg.c 0x021902BC/0x021903E0
    /* 0x02C */ void *msgBg;     // acc 0x02188D48 (get) / 0x02188D4C (set); nullable;
                                 // freed by field_msgbg.c 0x02190728
    /* 0x030 */ void *placeName; // acc 0x02188D20; nullable; field_place_name.c 0x021BC424/4F0/484
    /* 0x034 */ void *expObj;    // acc 0x02188D2C; freed by fld_exp_obj.c 0x021BE2E0
    /* 0x038 */ void *mapObjMan; // acc 0x02188C7C; the ov010 MMDL manager -- FieldPlayer's
                                 // map object is sub_0216DE94(this, 0xFF) (0x021A3718)
    /* 0x03C */ void *nogridMapper; // acc 0x02188C5C; freed by field_nogrid_mapper.c 0x021BB240
    /* 0x040 */ void *sceneArea; // acc 0x02189A18; freed by fld_scenearea.c 0x021AB624
    /* 0x044 */ void *sceneAreaLoader; // freed by fld_scenearea_loader.c 0x021AB81C
    /* 0x048 */ void *g3dMapper; // acc 0x02188C98; = field_g3d_mapper.c ctor 0x0218C9E8
    /* 0x04C */ void *unk04C;
    /* 0x050 */ void *unk050;
    /* 0x054 */ void *unk054;
    /* 0x058 */ void *unk058;
    /* 0x05C */ void *unk05C;
    /* 0x060 */ void *unk060;
    /* 0x064 */ void *unk064;
    /* 0x068 */ void *unk068;
    /* 0x06C */ void *unk06C;
    /* 0x070 */ void *unk070;
    /* 0x074 */ void *unk074;
    /* 0x078 */ void *unk078;
    /* 0x07C */ void *unk07C;
    /* 0x080 */ void *unk080;
    /* 0x084 */ void *unk084;
    /* 0x088 */ void *unk088;
    /* 0x08C */ void *unk08C;    // acc 0x02188CB4 (get) / 0x02188CBC (non-NULL test);
                                 // fed to field_player.c (0x021A3098, 0x021A2F48, 0x021A2F54)
    /* 0x090 */ void *encount;   // acc 0x02188CE8; freed by field_encount.c 0x021A9F28
    /* 0x094 */ void *fieldEffect; // acc 0x02188CD0; field_effect.c 0x021ABDE8/0x021ABE04
    /* 0x098 */ void *unk098;    // acc 0x02188CE0; nullable, NULLed on teardown; owner is in main
                                 // (0x0217F8EC / 0x0217F914)
    /* 0x09C */ void *palaceSys; // freed by field_palace_sys.c 0x021D33E0
    /* 0x0A0 */ void *mapEff;    // acc 0x02189A10; fieldskill_mapeff.c 0x021C7F9C/0x021C7FAC
    /* 0x0A4 */ void *unk0A4;
    /* 0x0A8 */ void *unk0A8;
    /* 0x0AC */ void *task0AC;   // = sub_020056A0(func_02189108, this, 0) in FieldMap init
    /* 0x0B0 */ void *unk0B0;
    /* 0x0B4 */ void *unk0B4;    // acc 0x02188C88
    /* 0x0B8 */ void *unk0B8;    // acc 0x02188C90
    /* 0x0BC */ void *fieldmapFunc; // acc 0x02188D24; fieldmap_func.c 0x021BB90C/0x021BB948
    /* 0x0C0 */ int unk0C0;      // zeroed by FieldSystem_New; state, set to 2 by 0x02188BD8,
                                 // tested ==1 by 0x02188BE8
    /* 0x0C4 */ int unk0C4;      // index into the 8-byte-stride table at 0x021D36B8 (0x02188B58)
    /* 0x0C8 */ u8 unk0C8;       // cleared by 0x02188BC4
    /* 0x0C9 */ u8 unk0C9;       // sub-step: table[unk0C4].fn[unk0C9] (0x02188B58)
    /* 0x0CA */ u16 unk0CA;
    /* 0x0CC */ int unk0CC;      // frame counter, incremented every 0x02188B58 call
    /* 0x0D0 */ u16 unk0D0;      // set in FieldSystem_New; fed to sub_02013B38/02013CC8/02013CE0
    /* 0x0D2 */ u16 unk0D2;
    /* 0x0D4 */ void *unk0D4;
    /* 0x0D8 */ u16 unk0D8;      // acc 0x02188C9C
    /* 0x0DA */ u16 unk0DA;
    /* 0x0DC */ void *unk0DC;
    /* 0x0E0 */ void *unk0E0;
    /* 0x0E4 */ void *unk0E4;
    /* 0x0E8 */ void *unk0E8;
    /* 0x0EC */ void *unk0EC;
    /* 0x0F0 */ void *unk0F0;    // acc 0x02188D40 (set); when non-NULL the field main loop
                                 // (0x02188880) copies 12 bytes from it into unk0F4
    /* 0x0F4 */ u8 unk0F4[12];   // 12-byte vector, destination of the unk0F0 copy and the
                                 // second argument of mode->main() and of 0x0218D158
    /* 0x100 */ s32 unk100;      // acc 0x02189A78; = 0x02189A80(fieldSystem), a camera-derived depth
    /* 0x104 */ void *unk104;
    /* 0x108 */ const FieldMapMode *mode; // acc 0x02188CF0 returns mode->id; = func_02189BA8(mapClass)
    /* 0x10C */ void *unk10C;    // acc 0x02188CA4 (get) / 0x02188CAC (set)
    /* 0x110 */ void *unk110;    // acc 0x02188D30; = FUN_02030CBC(0x20) in FieldMap init
    /* 0x114 */ void *unk114;    // 0x20-byte allocation in FieldMap init
    /* 0x118 */ void *unk118;
    /* 0x11C */ void *unk11C;
    /* 0x120 */ void *particle; // freed by fld_particle.c 0x021C1AD0
    /* 0x124 */ void *ci3d;      // acc 0x02189A00; fld3d_ci.c 0x021C1C04/0x021C1C4C
    /* 0x128 */ void *sodateya;  // acc 0x02188D50; freed by sodateya.c 0x021C31FC
    /* 0x12C */ void *unk12C;    // acc 0x021899F0 (get) / 0x021899F8 (set)
    /* 0x130 */ void *unk130;    // acc 0x02188CD8
    /* 0x134 */ void *taskManager; // acc 0x02188D38; = field_task_manager.c ctor 0x021C6D10(10, heapId)
    /* 0x138 */ void *unk138;    // acc 0x02189A24 (get) / 0x02189A1C (set)
    /* 0x13C */ void *encEff;    // acc 0x02189A08; enceff.c 0x021CF480/0x021CF520
    /* 0x140 */ void *unk140;    // acc 0x02189A58 (set)
    /* 0x144 */ void *unk144;    // acc 0x02189A48 (get) / 0x02189A50 (set)
    /* 0x148 */ void *unk148;    // acc 0x02189A60 returns &unk148
    /* 0x14C */ void *vreq;      // = fld_vreq.c ctor 0x021D317C(heapId)
    /* 0x150 */ void *unk150;    // acc 0x02189A70 (get) / 0x02189A68 (set)
};                               // size 0x154


/* --- promoted from src/ov021/fld_player_core.h --- */
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


/* --- promoted from src/ov021/fld_camera.h --- */
/*
 * FieldCamera -- the overworld camera of ov021 (GameFreak's `field_camera.c`,
 * __FILE__ string at 0x021DDA28; TU spans 0x0218E018..0x0218FF30).
 * FieldSystem+0x10 points at one of these.
 *
 * PROPOSAL for include/. Gen-4 ancestor: pokeheartgold `Camera`.
 *
 * Size is 0x1B0, proven by the allocation at 0x0218E028:
 *     movs r1,#0x1b ; ... ; lsls r1,r1,#4 ; movs r2,#1 ; blx FUN_02030734
 *     (heapId, 0x1B0, 1, "field_camera.c", 128)
 */

typedef struct FieldCamera {
    /* 0x000 */ u16 unk000;   // ctor: = heapId argument
    /* 0x002 */ u16 unk002;
    /* 0x004 */ u32 unk004;
    /* 0x008 */ u32 unk008;
    /* 0x00C */ void *unk00C; // acc 0x0218EC2C; ctor arg 2
    /* 0x010 */ void *unk010; // ctor arg 0; cleared by 0x0218F0D4
    /* 0x014 */ void *unk014; // ctor arg 1
    /* 0x018 */ u32 unk018;   // acc 0x0218EC60 copies unk018 -> unk01C
    /* 0x01C */ u32 unk01C;   // acc 0x0218EC5C (get) / 0x0218EC54, 0x0218E5F4 (clear)
    /* 0x020 */ u32 unk020;   // acc 0x0218E5EC (clear); ctor: = 0
    /* 0x024 */ u32 unk024;   // ctor: = 0
    /* 0x028 */ u32 unk028;   // acc 0x0218F0E8 (via unk0EC); ctor: = 0
    /* 0x02C */ u32 unk02C;   // set to 1 by 0x0218F0C0; ctor: = 0
    /* 0x030 */ u32 unk030;   // ctor: = 0
    /* 0x034 */ u32 unk034;   // ctor: = 0
    /* 0x038 */ u32 unk038;   // ctor: = 0
    /* 0x03C */ u8 filler03C[0x48 - 0x3C];
    /* 0x048 */ u32 unk048;   // ctor: = 0
    /* 0x04C */ u32 unk04C;   // ctor: = 0
    /* 0x050 */ u32 unk050;   // ctor: = 0
    /* 0x054 */ u8 filler054[0x6C - 0x54];
    /* 0x06C */ u32 unk06C;   // ctor: = 0
    /* 0x070 */ u32 unk070;   // ctor: = 0
    /* 0x074 */ u32 unk074;   // ctor: = 0
    /* 0x078 */ u16 unk078;   // acc 0x0218ED2C (get) / 0x0218ED34 (set); ctor: = 0
    /* 0x07A */ u16 unk07A;   // acc 0x0218ED40 (get) / 0x0218ED48 (set); ctor: = 0
    /* 0x07C */ u32 unk07C;   // acc 0x0218ED54 (get) / 0x0218ED58 (set); ctor: = 0x78
    /* 0x080 */ u16 unk080;
    /* 0x082 */ u16 unk082;   // acc 0x0218ED50 returns &unk082
    /* 0x084 */ u16 unk084;   // acc 0x0218ED3C returns &unk084; read as u16 by 0x02189A80
    /* 0x086 */ u16 unk086;
    /* 0x088 */ u8 filler088[0xE9 - 0x88];
    /* 0x0E9 */ u8 unk0E9;    // acc 0x0218F1B4 (get) / 0x0218F1AC (set); ctor: = 1
    /* 0x0EA */ u8 filler0EA[0x1B0 - 0xEA];
} FieldCamera;                // size 0x1B0

#endif // POKEBLACK_OV021_H
