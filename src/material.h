#ifndef MATERIAL_H
#define MATERIAL_H

#include<QString>
#include<QHash>

#include "texture.h"

class Material {
public:
    bool hasSphereMap;
    bool hasAoMap;
    bool hasStageMap;
    bool hasCubeMap;
    bool hasDiffuse;
    bool hasDiffuse2;
    bool hasDiffuse3;
    bool hasRamp;
    bool hasShadow;
    bool hasDummyRamp;
    bool hasNormalMap;

    int textureCount = 0;
    int expectedTextureCount = 0;

    int srcFactor;
    int dstFactor;

	int cullMode;

	int alphaFunc;
	int alphaTest;

    int zBufferOffset;

    QString fileName;

    QHash<QString, QList<float>> properties;

	// This could be stored as Uint, but we won't be processing the numbers.
    QList<Texture> textures;


	uint flags;

    enum TextureFlags {
        Glow = 0x00000080,
        Shadow = 0x00000040,
        DummyRamp = 0x00000020,
        SphereMap = 0x00000010,
        StageAOMap = 0x00000008,
        RampCubeMap = 0x00000004,
        NormalMap = 0x00000002,
        DiffuseMap = 0x00000001
    };

    void testFlags();

    void calculateTextureCount();
};

#endif // MATERIAL_H
