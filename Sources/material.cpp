#include "Headers/material.h"


uint Material::getFlags()
{
    return flags;
}


void Material::setFlags(uint newFlags)
{
    flags = newFlags;
}

void Material::testFlags()
{
    shadow = (flags & (int)TextureFlags::Shadow) > 0;
    dummyramp = (flags & (int)TextureFlags::DummyRamp) > 0;
    spheremap = (flags & (int)TextureFlags::SphereMap) > 0;
    aomap = (flags & (int)TextureFlags::StageAOMap) > 0 && !dummyramp;
    stagemap = (flags & (int)TextureFlags::StageAOMap) > 0 && dummyramp;

    cubemap = (flags & (int)TextureFlags::RampCubeMap) > 0 && (!dummyramp) && (!spheremap);
    ramp = (flags & (int)TextureFlags::RampCubeMap) > 0 && dummyramp;

    diffuse = (flags & (int)TextureFlags::DiffuseMap) > 0;
    diffuse3 = (flags & 0x00009100) == 0x00009100 || (flags & 0x00009600) == 0x00009600 || ((flags & 0x00009900) == 0x00009900);
    diffuse2 = ((flags & (int)TextureFlags::RampCubeMap) > 0 && ((flags & (int)TextureFlags::NormalMap) == 0)
        && dummyramp) || diffuse3;

    normalmap = (flags & (int)TextureFlags::NormalMap) > 0;
}

void Material::calculateTextureCount()
{
    if (diffuse)
        expectedTextureCount += 1;
    if (spheremap)
        expectedTextureCount += 1;
    if (diffuse2)
        expectedTextureCount += 1;
    if (diffuse3)
        expectedTextureCount += 1;
    if (stagemap)
        expectedTextureCount += 1;
    if (cubemap)
        expectedTextureCount += 1;
    if (aomap)
        expectedTextureCount += 1;
    if (normalmap)
        expectedTextureCount += 1;
    if (ramp)
        expectedTextureCount += 1;
    if (dummyramp)
        expectedTextureCount += 1;
}
