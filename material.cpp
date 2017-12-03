#include "material.h"

Material::Material()
{

}

uint Material::getFlags()
{
    return flags;
}


void Material::setFlags(uint newFlags)
{
    flags = newFlags;
}
