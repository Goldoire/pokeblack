#ifndef POKEBLACK_OV021_H
#define POKEBLACK_OV021_H

#include "global.h"
#include "gf_fwd.h"   /* FieldSystem is registered opaque there */

/*
 * ===========================================================================
 *  ov021 -- the field system (the overworld)
 * ===========================================================================
 *
 * PROMOTED from src/ov021/fld_*.h. Delete those five files and include this;
 * while they exist they win the quoted-include search and shadow this header.
 *
 * Every offset carries the byte-exact function that constrains it. GameFreak's
 * own translation-unit names are recovered from the rodata __FILE__ strings
 * (build/reference/tu_map.json): fieldmap.c, field_camera.c, field_encount.c,
 * field_msgbg.c.
 *
 * DO NOT RECONCILE AGAINST GEN 4. pokeheartgold's FieldSystem is 0x128 and
 * gen 5 reordered the head. The subsystem *set* is recognisable -- camera,
 * light, fog, weather, encounter, task manager -- which is exactly what makes
 * it dangerous: the names transfer and the offsets do not.
 *
 * GRADES: a field with an "acc"/"PROVEN" comment is pinned by a function that
 * verifies N/N OK. A bare `void *unkNNN` is a word slot at a proven offset
 * whose purpose is unknown. `filler` runs exist only to place the next proven
 * field.
 *
 * ---------------------------------------------------------------------------
 * OPEN CONFLICT -- DO NOT MERGE MsgBgWinSet AND MsgBg
 * ---------------------------------------------------------------------------
 * 0x02190708 writes a u16 at +0x06 of its first argument. That cannot coexist
 * with MsgBgWinSet::win being a pointer at +0x04, because +0x06 would land in
 * the middle of it.
 *
 * Both readings are live. The worker read the argument as a MsgBg -- whose
 * +0x06 is free, and that reading verifies -- so MsgBg::unk006 is where the
 * write is recorded here. But that is one function's argument type inferred
 * from a field being available, which is weaker than the rest of this header.
 * The alternative is that MsgBgWinSet has a different head than assumed.
 *
 * Until somebody settles it from a call site, the two types stay separate and
 * neither absorbs the other. Whoever resolves it should send the call site
 * that types 0x02190708's first argument, not a preference.
 */

/* --- FieldSystem + FieldMapMode + FieldSysBuf   (from src/ov021/fld_fieldsys.h) --- */

/*
 * FieldSystem -- the overworld context struct of ov021 (GameFreak's
 * `fieldmap.c`, recovered from the assert __FILE__ string at 0x021DD9C0).
 *
 * PROPOSAL for include/: do not copy this into a second file. Evidence for
 * every offset is in the comment on the field; "acc" is the byte-exact
 * accessor function that proves it.
 *
 * Size is 0x154, proven by the allocation in FieldSystem_New (0x02188030):
 *     ldr r1,=0x209 ; str r1,[sp] ; ... ; subs r1,#0xb5   -> size 0x154
 *     blx FUN_02030734 (heapId, 0x154, 1, "fieldmap.c", 521)
 *
 * The gen-4 ancestor is pokeheartgold's `struct FieldSystem`
 * (include/field_system.h, size 0x128). The shape is recognisable but the
 * offsets are NOT the same -- gen 5 reordered the head of the struct.
 */


/*
 * The map-load "mode" vtable that FieldSystem+0x108 points at. It comes out of
 * a static table at 0x021D373C indexed by map class (func_02189BA8), and the
 * ROM calls two of its slots: +0x08 from the field main loop at 0x021887BA and
 * +0x0C from the teardown at 0x02188A7A. Slot +0x00 is an int read by the
 * accessor at 0x02188CF0.
 */
/*
 * A claimed scratch buffer. FieldSystem+0x118 holds one; 0x02189764 refuses to
 * hand it out unless id == -1, and stamps the requester's id into it.
 */
typedef struct FieldSysBuf {
    /* 0x00 */ int id;    // PROVEN 0x02189758 (= -1) / 0x02189764
    /* 0x04 */ void *data; // PROVEN 0x02189758 (= NULL) / 0x02189764
} FieldSysBuf;

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
    /* 0x118 */ FieldSysBuf buf118; // PROVEN 0x02189764: {id, data} -- id is -1 when
                                 // free, data is a heap block of a caller-chosen size
                                 // allocated at "fieldmap.c":0xD7C. 0x02189758 resets it.
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


/* --- FieldPlayer   (from src/ov021/fld_player_core.h) --- */

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


/* --- FieldCamera   (from src/ov021/fld_camera.h) --- */

/*
 * FieldCamera -- the overworld camera of ov021 (GameFreak's `field_camera.c`,
 * __FILE__ string at 0x021DDA28; TU spans 0x0218E018..0x0218FF30).
 * FieldSystem+0x10 points at one of these.
 *
 * PROPOSAL for include/. Gen-4 ancestor: pokeheartgold `Camera`.
 *
 * Size is 0x1B0, PROVEN by the allocation at 0x0218E028:
 *     movs r1,#0x1b ; lsls r1,r1,#4 ; movs r2,#1 ; blx sub_02030734
 *     (heapId, 0x1B0, 1, "field_camera.c", 128)
 *
 * The camera has three interchangeable MODES, selected by unk014 and dispatched
 * through three parallel tables of function pointers indexed by it:
 *   0x021DDA00  enter  (0x0218E13C)
 *   0x021DDA0C  set    (0x0218E124)
 *   0x021D3E44  update (0x0218E58C)
 * 0x021DDA00 and 0x021DDA0C are 3 entries each (0x0C bytes apart), so there are
 * exactly three modes.
 */

typedef struct FieldCamera {
    /* 0x000 */ u16 heapId;   // PROVEN 0x0218E018 (the 5th, stack-passed ctor
                              // argument); re-read by 0x0218E018 for sub_020490F4
    /* 0x002 */ u16 unk002;
    /* 0x004 */ void *unk004; // PROVEN 0x0218E018 = sub_020490F4(0x3C, heapId);
                              // released by sub_02049238 in 0x0218E0E4
    /* 0x008 */ void *unk008; // PROVEN 0x0218E018 = sub_020490F4(0x6C, heapId);
                              // released by sub_02049238 in 0x0218E0E4
    /* 0x00C */ void *unk00C; // PROVEN 0x0218E018 (ctor arg 3); acc 0x0218EC2C
    /* 0x010 */ u32 unk010;   // PROVEN 0x0218E018 (ctor arg 1); set by 0x0218E17C
    /* 0x014 */ u32 mode;     // PROVEN 0x0218E018 (ctor arg 2), 0x0218E124 (set),
                              // 0x0218E13C, 0x0218E58C, 0x0218E73C -- the mode index
    /* 0x018 */ VecFx32 *unk018; // PROVEN 0x0218EC60 (copied into unk01C),
                              // 0x0218E160 (2nd arg of sub_0218E18C)
    /* 0x01C */ VecFx32 *unk01C; // PROVEN 0x0218E284 (deref'd, 12-byte copy into
                              // unk048); acc 0x0218EC5C, cleared 0x0218EC54/0x0218E5F4
    /* 0x020 */ VecFx32 *unk020; // PROVEN 0x0218E298 (deref'd, 12-byte copy into
                              // unk024); ctor NULLs it; cleared by 0x0218E5EC
    /* 0x024 */ VecFx32 unk024;  // PROVEN 0x0218E018 (three words zeroed),
                              // 0x0218E298 (whole-struct copy target)
    /* 0x030 */ VecFx32 unk030;  // PROVEN 0x0218E018 (three words zeroed)
    /* 0x03C */ VecFx32 unk03C;  // PROVEN 0x0218F19C (whole-struct copy out)
    /* 0x048 */ VecFx32 unk048;  // PROVEN 0x0218E018 (zeroed), 0x0218E284/0x0218EC30/
                              // 0x0218EC90 (copy in), 0x0218ECB4 (copy out)
    /* 0x054 */ VecFx32 unk054;  // PROVEN 0x0218F18C (whole-struct copy out)
    /* 0x060 */ VecFx32 unk060;  // PROVEN 0x0218ECC4 (out) / 0x0218ECD4 (in)
    /* 0x06C */ VecFx32 unk06C;  // PROVEN 0x0218E018 (zeroed), 0x0218EC30/0x0218EC90 (in)
    /* 0x078 */ u16 unk078;   // PROVEN 0x0218E018, 0x0218E5FC (zeroed);
                              // acc 0x0218ED2C (get) / 0x0218ED34 (set)
    /* 0x07A */ u16 unk07A;   // PROVEN 0x0218E018, 0x0218E5FC (zeroed);
                              // acc 0x0218ED40 (get) / 0x0218ED48 (set)
    /* 0x07C */ u32 unk07C;   // PROVEN 0x0218E018 (= 0x78), 0x0218E5FC (zeroed);
                              // acc 0x0218ED54 (get) / 0x0218ED58 (set)
    /* 0x080 */ u16 unk080;   // PROVEN 0x0218E018 = sub_0207D184(...) (FX_AtanIdx)
    /* 0x082 */ u16 unk082;   // acc 0x0218ED50 returns &unk082
    /* 0x084 */ u16 unk084;   // acc 0x0218ED3C returns &unk084; read as u16 by 0x02189A80
    /* 0x086 */ u16 unk086;
    /* 0x088 */ u8 unk088[4 * 0x18]; // PROVEN 0x0218F114 (MI_CpuCopy8 of count*0x18
                              // bytes to here) and 0x0218F134 (MI_CpuFill8 of 0x60):
                              // four 0x18-byte entries
    /* 0x0E8 */ u8 unk0E8;    // PROVEN 0x0218F114 / 0x0218F134 -- how many of unk088
    /* 0x0E9 */ u8 unk0E9;    // PROVEN 0x0218E018 (= 1), 0x0218E160 (= 1);
                              // acc 0x0218F1B4 (get) / 0x0218F1AC (set)
    /* 0x0EA */ u16 unk0EA;   // PROVEN 0x0218E018 (= 0xFFFF, from the literal pool)
    /* 0x0EC */ struct FieldCamera *unk0EC; // PROVEN 0x0218F0D4 / 0x0218F0E8 /
                              // 0x0218F0F8: nullable, and the fields reached through
                              // it (+0x10, +0x28, +0x2C) are FieldCamera's own
    /* 0x0F0 */ u8 filler0F0[0x18C - 0xF0];
    /* 0x18C */ void *unk18C; // PROVEN 0x0218FE50 (nullable)
    /* 0x190 */ u8 filler190[0x1A8 - 0x190];
    /* 0x1A8 */ void *cbArg;  // PROVEN 0x0218E104 (the callback's 2nd argument)
    /* 0x1AC */ void (*cb)(struct FieldCamera *camera, void *arg);
                              // PROVEN 0x0218E018 (NULLed) / 0x0218E104 (called)
} FieldCamera;                // size 0x1B0


/* --- FieldEncount + FieldEncountStep + FieldEncountInfo   (from src/ov021/fld_encount.h) --- */

/*
 * ov021 / field_encount.c -- wild-encounter driver.
 *
 * PROPOSAL for include/. Every offset below is byte-proven; the constraining
 * function address is on the field.  __FILE__ string "field_encount.c" is at
 * 0x021DDFA4; the TU spans 0x021A9ED8..0x021AA77C.
 *
 * Gen-4 ancestor: pokeheartgold's `FieldEncounter` (src/field_encounter.c).
 * The shape is recognisable, the offsets are not the same.
 */


/*
 * Size 0x14, PROVEN by the allocation in FieldEncount_New (0x021A9ED8):
 *     movs r1,#0x14 ; movs r2,#1 ; ldr r3,=0x021DDFA4 ; str #0x62,[sp]
 *     blx sub_02030734 (heapId, 0x14, 1, "field_encount.c", 98)
 */
typedef struct FieldEncount {
    /* 0x00 */ FieldSystem *fieldSystem; // PROVEN 0x021A9ED8 (the ctor argument)
    /* 0x04 */ void *ovyManager;         // PROVEN 0x021A9ED8 = sub_02188C80(fieldSystem)
    /* 0x08 */ void *saveData;           // PROVEN 0x021A9ED8 = sub_020120F4(ovyManager);
                                         // sub_02012A38 / sub_02012844 take it
    /* 0x0C */ u8 *rates;                // PROVEN 0x021A9ED8 = sub_0216255C(sub_02012844(saveData));
                                         // indexed [0..6] as bytes by sub_021AA3E0
    /* 0x10 */ void *unk10;              // PROVEN 0x021A9ED8 = sub_021AA77C(heapId);
                                         // torn down by 0x021A9F28
} FieldEncount;                          // size 0x14

/*
 * The 12-byte "has the player moved" step counter that lives in the save file
 * (sub_02012A38 hands it out).  Size 12 PROVEN by the MI_CpuFill8(p, 0, 12) in
 * 0x021AA6F8; every field offset is proven by 0x021AA6F8 / 0x021AA728.
 */
typedef struct FieldEncountStep {
    /* 0x00 */ u16 x;      // PROVEN 0x021AA6F8/0x021AA728 = sub_0216D83C(player)
    /* 0x02 */ u16 y;      // PROVEN 0x021AA6F8/0x021AA728 = sub_0216D854(player)
    /* 0x04 */ u16 z;      // PROVEN 0x021AA6F8/0x021AA728 = sub_0216D86C(player)
    /* 0x06 */ u16 moved;  // PROVEN 0x021AA728 (halfword, set to 1 once the
                           // position differs; gates the counter)
    /* 0x08 */ u32 steps;  // PROVEN 0x021AA728 (word, saturates at 0xA000)
} FieldEncountStep;        // size 0x0C

/*
 * The context block the wild-mon roll is handed. Filled field-by-field by
 * 0x021AA304, which is the only proof of the layout (the allocation is in the
 * caller's frame, so no size is proven -- >= 0x0E, and the caller reserves
 * 0x10 of stack for it).
 */
typedef struct FieldEncountInfo {
    /* 0x00 */ u32 unk00;        // PROVEN 0x021AA304 = sub_02013ED8(zoneId)
    /* 0x04 */ u32 unk04;        // PROVEN 0x021AA304 =
                                 //   sub_021AB580(sub_021AB0F0(sub_021A30C8(player)))
    /* 0x08 */ u8 weatherClass;  // PROVEN 0x021AA304 = sub_021AA69C(fieldSystem)
    /* 0x09 */ u8 unk09;         // PROVEN 0x021AA304 = sub_02012984(a1)
    /* 0x0A */ u16 zoneId;       // PROVEN 0x021AA304 = sub_02188C9C(fieldSystem)
    /* 0x0C */ u8 hour;          // PROVEN 0x021AA304 (RTCTime.hour, truncated)
    /* 0x0D */ u8 minute;        // PROVEN 0x021AA304 (RTCTime.minute, truncated)
} FieldEncountInfo;

/*
 * RTCTime -- deliberately NOT declared here.
 *
 * src/ov021/fld_encount.h transcribed it as three s32s. That is the SDK's own
 * RTCTime (<nitro/rtc/ARM9/api.h>, three u32s -- same 0x0C layout), which
 * arrives through global.h, so redeclaring it is a hard compile error. Using
 * the SDK type makes the layout verified by construction rather than
 * transcribed, exactly as with TPData in main_types.h.
 *
 * The signedness differs on paper (SDK u32 vs the worker's s32) and does not
 * matter for the field loads in 0x021AA304, which truncate to u8.
 */


/* --- MsgBg + the message-layer records   (from src/ov021/fld_msgbg.h) --- */

/*
 * ov021 / field_msgbg.c -- the overworld message/BG text layer.
 *
 * PROPOSAL for include/. TU recovered from the assert __FILE__ string
 * "field_msgbg.c" at 0x021DDA50 (13 references); it spans
 * 0x021901EC..0x021938AC, 180 functions / 14016 bytes -- the largest per-file
 * count in ov021 outside the fldmmdl_acmd belt.
 *
 * FieldSystem+0x02C points at a MsgBg (fld_fieldsys.h), and FieldSystem+0x028
 * points at a second, distinct object of this TU.
 *
 * The TU owns at least three objects. Only MsgBg has a proven size; the other
 * two are only ever reached through a pointer, so their extents are open.
 */

/*
 * Size 0x17C, PROVEN by the allocation in MsgBg_New (0x021901EC):
 *     movs r1,#0x69 ; lsls r1,r1,#2   -> 0x1A4, stored as the line number 420
 *     subs r1,#0x28                   -> 0x17C, the size
 *     blx sub_02030734 (heapId, 0x17C, 1, "field_msgbg.c", 420)
 * The 0x17C/420 pun is CW reusing one constant for both, which is also why
 * 0xFF is materialised twice in the ctor (as a value and as an offset base).
 */
typedef struct MsgBg {
    /* 0x000 */ u16 heapId;   // PROVEN 0x021901EC (the ctor argument); re-read
                              // by 0x021902AC and 0x021904B0
    /* 0x002 */ u16 unk002;   // PROVEN 0x021901EC = 0xFF; read by 0x021902AC
    /* 0x004 */ u16 unk004;   // PROVEN 0x021901EC = 0xFF
    /* 0x006 */ u16 unk006;   // PROVEN 0x02190708 (set to 14, then re-read as
                              // the 7th argument of 0x02190680)
    /* 0x008 */ void *unk008; // PROVEN 0x021901EC = sub_0201D7EC(0x17,0,0,0,heapId)
    /* 0x00C */ void *unk00C; // PROVEN 0x021901EC = sub_0201C440(heapId);
                              // acc 0x021904A8, fed to sub_0201C6EC / sub_0201C6B4
    /* 0x010 */ u8 filler010[0x15C - 0x010];
    /* 0x15C */ void *unk15C; // PROVEN 0x0219047C (nullable; sub_02194764 frees it)
    /* 0x160 */ u32 unk160;   // PROVEN 0x021901EC / 0x021904DC: the ADDRESS of this
                              // slot is handed to sub_021931F4 (init) and
                              // sub_02193208, so 0x160 starts an embedded struct
    /* 0x164 */ void *unk164; // PROVEN 0x021901EC = sub_0203101C(heapId, heapId, 1, 4)
    /* 0x168 */ void *unk168; // PROVEN 0x021901EC (the ctor's 2nd argument)
    /* 0x16C */ void *task16C;// PROVEN 0x0219027C = sub_020056A0(sub_02192EB8, this, 0),
                              // created lazily; 0x021903CC tests it for NULL
    /* 0x170 */ u8 unk170;    // PROVEN 0x021904D0 (strb 1)
    /* 0x171 */ u8 filler171[3];
    /* 0x174 */ void *unk174; // PROVEN 0x021901EC = sub_0204A1BC(5, 0xC, 0, heapId)
    /* 0x178 */ u32 unk178;   // PROVEN 0x021901EC: the ADDRESS of this slot is the
                              // 2nd argument of sub_02062A4C
} MsgBg;                      // size 0x17C

/*
 * The per-window record. No allocation site in this TU reaches it, so the size
 * is open; 0x19 bytes are proven.
 */
typedef struct MsgBgWin {
    /* 0x00 */ u8 filler00[8];
    /* 0x08 */ void *unk08;  // PROVEN 0x02190538 (NULLed), 0x02190604 (read)
    /* 0x0C */ void *unk0C;  // PROVEN 0x02190538 (NULLed)
    /* 0x10 */ void *unk10;  // PROVEN 0x02190538 (NULLed)
    /* 0x14 */ void *unk14;  // PROVEN 0x02190620 (fed to sub_02045770 / sub_02045730)
    /* 0x18 */ void *unk18;  // PROVEN 0x02190538 (read, freed by sub_02045808, NULLed)
} MsgBgWin;

/*
 * The pair that 0x02190728 tears down. Two words; every forwarder in the
 * 0x02190740..0x021907A8 run reaches its window through +0x04.
 *
 * NOTE the open question: 0x02190708 writes a u16 at +0x06 of ITS first
 * argument, which cannot coexist with unk04 being a pointer. Either 0x02190708
 * takes a MsgBg (whose +0x06 is free -- the reading adopted here) or this pair
 * has a different head. Do not merge the two types without resolving it.
 */
typedef struct MsgBgWinSet {
    /* 0x00 */ void *unk00;    // PROVEN 0x02190728 (sub_02193130), 0x02190740
    /* 0x04 */ MsgBgWin *win;  // PROVEN 0x02190728, 0x02190740, 0x02190758,
                               // 0x02190764, 0x0219077C, 0x02190788, 0x02190794
} MsgBgWinSet;

/*
 * A larger printer record. Same window at +0x04 as MsgBgWinSet but a different
 * head, so the two are genuinely distinct objects.
 */
typedef struct MsgBgPrinter {
    /* 0x00 */ u8 filler00[4];
    /* 0x04 */ MsgBgWin *win; // PROVEN 0x021909BC (sub_02190538)
    /* 0x08 */ void *unk08;   // PROVEN 0x021909BC (sub_02193130), 0x02190B1C
    /* 0x0C */ void *unk0C;   // PROVEN 0x021909BC (sub_0201F868)
    /* 0x10 */ void *unk10;   // PROVEN 0x021909BC (sub_0202020C), 0x02190A14
} MsgBgPrinter;

/* The window template the 0x02190938 family is handed. */
typedef struct MsgBgWinTemplate {
    /* 0x00 */ u16 unk00;     // PROVEN 0x02190B08
    /* 0x02 */ u8 filler02[0x14 - 0x02];
    /* 0x14 */ u16 unk14;     // PROVEN 0x02190B08
    /* 0x16 */ u16 unk16;     // PROVEN 0x02190B08
    /* 0x18 */ u16 unk18;     // PROVEN 0x02190B08
    /* 0x1A */ u16 unk1A;     // PROVEN 0x02190B08
    /* 0x1C */ u32 unk1C;     // PROVEN 0x02190960
} MsgBgWinTemplate;

#endif // POKEBLACK_OV021_H
