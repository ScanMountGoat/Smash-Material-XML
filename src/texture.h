#ifndef TEXTURE_H
#define TEXTURE_H

#include <QString>

class Texture {
public:
    QString hash = "";
    uint wrapModeS = 0;
    uint wrapModeT = 0;
    uint minFilter = 0;
    uint magFilter = 0;
    uint mipDetail = 0;
};

#endif // TEXTURE_H
