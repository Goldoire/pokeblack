#ifndef POKEBLACK_OV021_FLD_FIELDSYS_H
#define POKEBLACK_OV021_FLD_FIELDSYS_H

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

typedef struct FieldSystem FieldSystem;

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

#endif // POKEBLACK_OV021_FLD_FIELDSYS_H
