#pragma once
#include <cstdint>

using Any = int;
using Hash = std::uint32_t;
using Entity = std::int32_t;
using Player = std::int32_t;
using FireId = std::int32_t;
using Interior = std::int32_t;
using Ped = Entity;
using Vehicle = Entity;
using Cam = std::int32_t;
using Object = Entity;
using Pickup = Object;
using Blip = std::int32_t;
using Camera = Entity;
using ScrHandle = Entity;

#pragma pack(push, 1)
class Vector3
{
public:
    Vector3() = default;

    Vector3(float x, float y, float z) :
        x(x), y(y), z(z)
    {}

    Vector3 operator+(const Vector3& other)
    {
        Vector3 vec;
        vec.x = this->x + other.x;
        vec.y = this->y + other.y;
        vec.z = this->z + other.z;
        return vec;
    }

    Vector3 operator-(const Vector3& other)
    {
        Vector3 vec;
        vec.x = this->x - other.x;
        vec.y = this->y - other.y;
        vec.z = this->z - other.z;
        return vec;
    }

    Vector3 operator*(const Vector3& other)
    {
        Vector3 vec;
        vec.x = this->x * other.x;
        vec.y = this->y * other.y;
        vec.z = this->z * other.z;
        return vec;
    }

    Vector3 operator*(const float& other)
    {
        Vector3 vec;
        vec.x = this->x * other;
        vec.y = this->y * other;
        vec.z = this->z * other;
        return vec;
    }
public:
    float x{};
private:
    char m_padding1[0x04];
public:
    float y{};
private:
    char m_padding2[0x04];
public:
    float z{};
private:
    char m_padding3[0x04];
};
#pragma pack(pop)

class Vector2 final
{
public:
    Vector2() = default;

    Vector2(float x, float y)
        : x(x), y(y)
    {}

public:
    float x, y;
};

class Vector4 final
{
public:
    Vector4() = default;

    Vector4(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w)
    {}

public:
    float x, y, z, w;
};