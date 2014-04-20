#ifndef PACKET_H
#define PACKET_H

#include "PacketType.h"

namespace Networking::Packets
{
    class Packet
    {
    public:
        Packet();
        Packet(PacketType type);
        ~Packet();

        PacketType mType;
    };
}

#endif
