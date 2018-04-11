#include "material.h"

void Material::testFlags()
{
    hasShadow = (flags & (int)TextureFlags::Shadow) > 0;
    hasDummyRamp = (flags & (int)TextureFlags::DummyRamp) > 0;
    hasSphereMap = (flags & (int)TextureFlags::SphereMap) > 0;
    hasAoMap = (flags & (int)TextureFlags::StageAOMap) > 0 && !hasDummyRamp;
    hasStageMap = (flags & (int)TextureFlags::StageAOMap) > 0 && hasDummyRamp;

    hasCubeMap = (flags & (int)TextureFlags::RampCubeMap) > 0 && (!hasDummyRamp) && (!hasSphereMap);
    hasRamp = (flags & (int)TextureFlags::RampCubeMap) > 0 && hasDummyRamp;

    hasDiffuse = (flags & (int)TextureFlags::DiffuseMap) > 0;
    hasDiffuse3 = (flags & 0x00009100) == 0x00009100 || (flags & 0x00009600) == 0x00009600 || ((flags & 0x00009900) == 0x00009900);
    hasDiffuse2 = ((flags & (int)TextureFlags::RampCubeMap) > 0 && ((flags & (int)TextureFlags::NormalMap) == 0)
        && hasDummyRamp) || hasDiffuse3;

    hasNormalMap = (flags & (int)TextureFlags::NormalMap) > 0;
}

void Material::calculateTextureCount()
{
    if (hasDiffuse)
        expectedTextureCount += 1;
    if (hasSphereMap)
        expectedTextureCount += 1;
    if (hasDiffuse2)
        expectedTextureCount += 1;
    if (hasDiffuse3)
        expectedTextureCount += 1;
    if (hasStageMap)
        expectedTextureCount += 1;
    if (hasCubeMap)
        expectedTextureCount += 1;
    if (hasAoMap)
        expectedTextureCount += 1;
    if (hasNormalMap)
        expectedTextureCount += 1;
    if (hasRamp)
        expectedTextureCount += 1;
    if (hasDummyRamp)
        expectedTextureCount += 1;
}
