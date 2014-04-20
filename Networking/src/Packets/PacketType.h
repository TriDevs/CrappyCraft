#ifndef PACKET_TYPE_H
#define PACKET_TYPE_H

namespace Networking
{
    namespace Packets
    {
        enum PacketType
        {
            // Handshaking
            CS_HANDSHAKE                            = 0x00,

            // Play, server->client
            SC_PLAY_KEEP_ALIVE                      = 0x00,
            SC_PLAY_JOIN_GAME                       = 0x01,
            SC_PLAY_CHAT_MESSAGE                    = 0x02,
            SC_PLAY_TIME_UPDATE                     = 0x03,
            SC_PLAY_ENTITY_EQUIPMENT                = 0x04,
            SC_PLAY_SPAWN_POSITION                  = 0x05,
            SC_PLAY_UPDATE_HEALTH                   = 0x06,
            SC_PLAY_RESPAWN                         = 0x07,
            SC_PLAY_PLAYER_POSITION_AND_LOOK        = 0x08,
            SC_PLAY_HELD_ITEM_CHANGE                = 0x09,
            SC_PLAY_USE_BED                         = 0x0A,
            SC_PLAY_ANIMATION                       = 0x0B,
            SC_PLAY_SPAWN_PLAYER                    = 0x0C,
            SC_PLAY_COLLECT_ITEM                    = 0x0D,
            SC_PLAY_SPAWN_OBJECT                    = 0x0E,
            SC_PLAY_SPAWN_MOB                       = 0x0F,
            SC_PLAY_SPAWN_PAINTING                  = 0x10,
            SC_PLAY_SPAWN_EXPERIENCE_ORB            = 0x11,
            SC_PLAY_ENTITY_VELOCITY                 = 0x12,
            SC_PLAY_DESTROY_ENTITIES                = 0x13,
            SC_PLAY_ENTITY                          = 0x14,
            SC_PLAY_ENTITY_RELATIVE_MOVE            = 0x15,
            SC_PLAY_ENTITY_LOOK                     = 0x16,
            SC_PLAY_ENTITY_LOOK_AND_RELATIVE_MOVE   = 0x17,
            SC_PLAY_ENTITY_TELEPORT                 = 0x18,
            SC_PLAY_ENTITY_HEAD_LOOK                = 0x19,
            SC_PLAY_ENTITY_STATUS                   = 0x1A,
            SC_PLAY_ATTACH_ENTITY                   = 0x1B,
            SC_PLAY_ENTITY_METADATA                 = 0x1C,
            SC_PLAY_ENTITY_EFFECT                   = 0x1D,
            SC_PLAY_REMOVE_ENTITY_EFFECT            = 0x1E,
            SC_PLAY_SET_EXPERIENCE                  = 0x1F,
            SC_PLAY_ENTITY_PROPERTIES               = 0x20,
            SC_PLAY_CHUNK_DATA                      = 0x21,
            SC_PLAY_MULTI_BLOCK_CHANGE              = 0x22,
            SC_PLAY_BLOCK_CHANGE                    = 0x23,
            SC_PLAY_BLOCK_ACTION                    = 0x24,
            SC_PLAY_BLOCK_BREAK_ANIMATION           = 0x25,
            SC_PLAY_MAP_CHUNK_BULK                  = 0x26,
            SC_PLAY_EXPLOSION                       = 0x27,
            SC_PLAY_EFFECT                          = 0x28,
            SC_PLAY_SOUND_EFFECT                    = 0x29,
            SC_PLAY_PARTICLE                        = 0x2A,
            SC_PLAY_CHANGE_GAME_STATE               = 0x2B,
            SC_PLAY_SPAWN_GLOBAL_ENTITY             = 0x2C,
            SC_PLAY_OPEN_WINDOW                     = 0x2D,
            SC_PLAY_CLOSE_WINDOW                    = 0x2E,
            SC_PLAY_SET_SLOT                        = 0x2F,
            SC_PLAY_WINDOW_ITEMS                    = 0x30,
            SC_PLAY_WINDOW_PROPERTY                 = 0x31,
            SC_PLAY_CONFIRM_TRANSACTION             = 0x32,
            SC_PLAY_UPDATE_SIGN                     = 0x33,
            SC_PLAY_MAPS                            = 0x34,
            SC_PLAY_UPDATE_BLOCK_ENTITY             = 0x35,
            SC_PLAY_SIGN_EDITOR_OPEN                = 0x36,
            SC_PLAY_STATISTICS                      = 0x37,
            SC_PLAY_PLAYER_LIST_ITEM                = 0x38,
            SC_PLAY_PLAYER_ABILITIES                = 0x39,
            SC_PLAY_TAB_COMPLETE                    = 0x3A,
            SC_PLAY_SCOREBOARD_OBJECTIVE            = 0x3B,
            SC_PLAY_UPDATE_SCORE                    = 0x3C,
            SC_PLAY_DISPLAY_SCOREBOARD              = 0x3D,
            SC_PLAY_TEAMS                           = 0x3E,
            SC_PLAY_PLUGIN_MESSAGE                  = 0x3F,
            SC_PLAY_DISCONNECT                      = 0x40,

            // Client->server
            CS_PLAY_KEEP_ALIVE                      = 0x00,
            CS_PLAY_CHAT_MESSAGE                    = 0x01,
            CS_PLAY_USE_ENTITY                      = 0x02,
            CS_PLAY_PLAYER                          = 0x03,
            CS_PLAY_PLAYER_POSITION                 = 0x04,
            CS_PLAY_PLAYER_LOOK                     = 0x05,
            CS_PLAY_PLAYER_POSITION_AND_LOOK        = 0x06,
            CS_PLAY_PLAYER_DIGGING                  = 0x07,
            CS_PLAY_PLAYER_BLOCK_PLACEMENT          = 0x08,
            CS_PLAY_HELD_ITEM_CHANGE                = 0x09,
            CS_PLAY_ANIMATION                       = 0x0A,
            CS_PLAY_ENTITY_ACTION                   = 0x0B,
            CS_PLAY_STEER_VEHICLE                   = 0x0C,
            CS_PLAY_CLOSE_WINDOW                    = 0x0D,
            CS_PLAY_CLICK_WINDOW                    = 0x0E,
            CS_PLAY_CONFIRM_TRANSACTION             = 0x0F,
            CS_PLAY_CREATIVE_INVENTORY_ACTION       = 0x10,
            CS_PLAY_ENCHANT_ITEM                    = 0x11,
            CS_PLAY_UPDATE_SIGN                     = 0x12,
            CS_PLAY_PLAYER_ABILITIES                = 0x13,
            CS_PLAY_TAB_COMPLETE                    = 0x14,
            CS_PLAY_CLIENT_SETTINGS                 = 0x15,
            CS_PLAY_CLIENT_STATUS                   = 0x16,
            CS_PLAY_PLUGIN_MESSAGE                  = 0x17,

            // Status server->client
            SC_STATUS_RESPONSE                      = 0x00,
            SC_STATUS_PING                          = 0x01,

            // Client->server
            CS_STATUS_REQUEST                       = 0x00,
            CS_STATUS_PING                          = 0x01,


            // Login server->client
            SC_LOGIN_DISCONNECT                     = 0x00,
            SC_LOGIN_ENCRYPTION_REQUEST             = 0x01,
            SC_LOGIN_SUCCESS                        = 0x02,

            // Client->server
            CS_LOGIN_START                          = 0x00,
            CS_LOGIN_ENCRYPTION_RESPONSE            = 0x01
        };
    }
}

#endif
