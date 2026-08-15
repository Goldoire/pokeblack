#ifndef POKEBLACK_GF_FWD_H
#define POKEBLACK_GF_FWD_H

#include "global.h"

/*
 * ===========================================================================
 *  Name registry for GameFreak engine objects.
 * ===========================================================================
 *
 * These are OPAQUE typedefs and nothing else. There is deliberately no field
 * in this file: not one of these layouts has been checked against Black's
 * bytes yet, and a struct that compiles with the wrong offsets is worse than
 * no struct at all -- it turns a loud compile error into a silent near-miss
 * that costs an afternoon to find.
 *
 * What this file IS for: stopping ten agents from inventing ten different
 * names for the same object. If you are looking at something that is
 * recognisably one of these, use this name for your pointer, keep the fields
 * as raw offsets inside your own file for now, and send the integrator the
 * evidence (which functions constrain which offsets, and what the accesses
 * look like). The layout lands here, verified, and everyone recompiles.
 *
 * Names follow pret/pokeheartgold, because gen 5 is an evolution of that
 * engine and a matching name makes the gen 4 source searchable as an oracle:
 *   C:\Users\pranav\decomp\pokeheartgold
 *
 * If you need a field TODAY, do this in your own .c and nothing more:
 *
 *     struct UnkStruct021D0F00 { u32 unk_00; u16 unk_04; };   // local, private
 *
 * or plain pointer arithmetic. Do not put a speculative layout in include/.
 *
 * ---------------------------------------------------------------------------
 * NO LONGER OPAQUE -- these now have real, evidenced layouts. Include the
 * header instead of guessing, and note that they define the struct BODY while
 * the typedef below stays here, so both files can be included together:
 *
 *     FieldSystem                     -> "ov021.h"   (0x154, 49 slots pinned)
 *     Pokemon / BoxPokemon / Party    -> "pokemon.h" (proven twice over)
 *
 * Still genuinely opaque, and still the right place to send a proposal:
 * String, MsgData, MessageFormat, SaveData, BgConfig, Window, SpriteList,
 * SpriteRenderer, SpriteResourceManager, Sprite, OverlayManager, TaskManager,
 * SysTask, SysTaskQueue, NARC, ScriptContext.
 *
 * (The 2D sprite system does have a layout now -- "g_clact.h" -- but it is
 * GameFreak's `clact.c` object, named GClact*, not the gen-4 `Sprite` this
 * file reserves. Whether they are the same object is unresolved.)
 */

/* --- memory / core ------------------------------------------------------- */
typedef struct SysTask SysTask;           /* one scheduler callback slot */
typedef struct SysTaskQueue SysTaskQueue; /* the priority-ordered task list */

/* --- process / overlay --------------------------------------------------- */
typedef struct OverlayManager OverlayManager; /* init/exec/exit state machine */
typedef struct OverlayManagerTemplate OverlayManagerTemplate;
typedef struct TaskManager TaskManager; /* field-side coroutine stack */

/* --- script VM (lives in main; overlays supply the command tables) ------- */
typedef struct ScriptContext ScriptContext; /* sub_0201134C = ScriptReadWord */

/* --- text ---------------------------------------------------------------- */
typedef struct String String;       /* the u16 GameFreak string object */
typedef struct MsgData MsgData;     /* a loaded message archive (GMM/MSG) */
typedef struct MessageFormat MessageFormat; /* placeholder-expansion buffers */

/* --- save ---------------------------------------------------------------- */
typedef struct SaveData SaveData; /* the whole save image + block directory */

/* --- 2D graphics --------------------------------------------------------- */
typedef struct BgConfig BgConfig;               /* the four BG layers per screen */
typedef struct Window Window;                   /* a tilemap rectangle you draw into */
typedef struct SpriteList SpriteList;           /* NNS cell-animation instances */
typedef struct SpriteRenderer SpriteRenderer;   /* OAM + VRAM plumbing */
typedef struct SpriteResourceManager SpriteResourceManager;
typedef struct Sprite Sprite;                   /* one drawable */

/* --- field --------------------------------------------------------------- */
typedef struct FieldSystem FieldSystem; /* the overworld root object */

/* --- filesystem ---------------------------------------------------------- */
typedef struct NARC NARC; /* an open NARC archive handle */

#endif // POKEBLACK_GF_FWD_H
