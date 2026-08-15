/*
 * ov021 / field_player_core.c -- FieldPlayer accessor block (0x021A3920..0x021A3AD8).
 *
 * TU recovered from the assert __FILE__ string "field_player_core.c" at
 * 0x021DDEB8, referenced from 0x021A36E4. The TU spans 0x021A36E4..0x021A4140.
 *
 * Compiler: tools/mwccarm/dsi/1.1 (repo default), --thumb.
 * Each accessor is a proof of a FieldPlayer offset -- see fld_player_core.h.
 */
#include "types.h"

#include "fld_player_core.h"

void *sub_0216D5E0(void *mapObject);
void *sub_0216D5F8(void *mapObject);
void *sub_02012B28(void *a0);
void *sub_02012B2C(void *a0);
void *sub_02012B30(void *a0, u32 a1);
void sub_021A3AD8(FieldPlayer *player, u32 a1);
void *sub_021A3C24(FieldPlayer *player, u16 a1);


void *sub_021A3920(FieldPlayer *player)
{
    return sub_0216D5F8(player->mapObject);
}

void *sub_021A392C(FieldPlayer *player)
{
    return sub_0216D5E0(player->mapObject);
}

void sub_021A3938(FieldPlayer *player, u32 a1)
{
    sub_021A3AD8(player, a1);
    sub_02012B30(player->unk0C, a1);
}

void *sub_021A394C(FieldPlayer *player)
{
    return sub_02012B30(player->unk0C, 0xFFFF);
}

void *sub_021A395C(FieldPlayer *player)
{
    return player->fieldSystem;
}

void *sub_021A3960(FieldPlayer *player)
{
    return player->mapObject;
}

void sub_021A3964(FieldPlayer *player, void *a1)
{
    player->unk14 = a1;
}

void *sub_021A3968(FieldPlayer *player)
{
    return player->unk14;
}

void sub_021A396C(FieldPlayer *player, void *a1)
{
    player->unk10 = a1;
}

void *sub_021A3970(FieldPlayer *player)
{
    return player->unk10;
}

void *sub_021A3974(FieldPlayer *player)
{
    return sub_02012B28(player->unk0C);
}

void *sub_021A3980(FieldPlayer *player)
{
    return sub_02012B2C(player->unk0C);
}

void *sub_021A398C(FieldPlayer *player)
{
    return player->unk18;
}

void *sub_021A3990(FieldPlayer *player)
{
    return player->ovyManager;
}

void *sub_021A3994(FieldPlayer *player)
{
    return player->unk0C;
}

void *sub_021A3AC4(FieldPlayer *player, u32 a1)
{
    return sub_021A3C24(player, a1);
}

void sub_021A3AD0(FieldPlayer *player, void *a1)
{
    player->unk28 = a1;
}

void *sub_021A3AD4(FieldPlayer *player)
{
    return player->unk28;
}
