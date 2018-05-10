#include "materialxml.h"

#include <QFile>
#include <QDebug>

void MaterialXml::addMaterialsFromXML(QString fileName, SearchSettings &settings) {
    QXmlStreamReader reader;

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
		return;
    }
    reader.setDevice(&file);

    if (reader.readNextStartElement()) {
        if (reader.name() == "NUDMATERIAL") {
            readMesh(reader, fileName, settings);
        } else
            reader.raiseError(QObject::tr("Incorrect file"));
    }
}

void MaterialXml::readMesh(QXmlStreamReader &reader, QString fileName, SearchSettings &settings) {
    while(reader.readNextStartElement()) {
        if(reader.name() == "mesh") {
            QString name = "";
            if (reader.attributes().hasAttribute(("name")))
                name = reader.attributes().value("name").toString();

            readPolygon(reader, fileName, settings);
        } else
            reader.skipCurrentElement();
    }
}

void MaterialXml::readPolygon(QXmlStreamReader &reader, QString fileName,
                              SearchSettings &settings) {
    while(reader.readNextStartElement()) {
        if(reader.name() == "polygon") {
            readMaterial(reader, fileName, settings);
        } else
            reader.skipCurrentElement();
    }
}

void MaterialXml::readMaterial(QXmlStreamReader &reader, QString fileName,
                               SearchSettings &settings) {
    while(reader.readNextStartElement()) {
        if(reader.name() == "material") {
            Material material;

            // In case we need to display the file path later.
            material.fileName = fileName;

            // Set the attribute values.
            material.flags = readUintAttribute(reader, "flags", true);
            material.srcFactor = readIntAttribute(reader, "srcFactor", true);
            material.dstFactor = readIntAttribute(reader, "dstFactor", true);
			material.cullMode = readIntAttribute(reader, "cullmode", true);
            material.zBufferOffset = readIntAttribute(reader, "zbuffoff", false);

            readTexturesAndProperties(reader, material);

            // add the material to the global material list
            settings.materialList.append(material);
        } else
            reader.skipCurrentElement();
    }
}

int MaterialXml::readIntAttribute(QXmlStreamReader &reader, QString attributeName, bool useHex) {
	int value = 0;
	if (reader.attributes().hasAttribute((attributeName))) {
		bool ok;
		if (useHex) {
			value = reader.attributes().value(attributeName).toInt(&ok, 16);
		} else {
			value = reader.attributes().value(attributeName).toInt(&ok, 10);
		}
	}
	return value;
}

uint MaterialXml::readUintAttribute(QXmlStreamReader &reader, QString attributeName, bool useHex) {
	uint value = 0;
	if (reader.attributes().hasAttribute((attributeName))) {
		bool ok;
		if (useHex) {
			value = reader.attributes().value(attributeName).toUInt(&ok, 16);
		} else {
			value = reader.attributes().value(attributeName).toUInt(&ok, 10);
		}
	}
	return value;
}

void MaterialXml::readTexturesAndProperties(QXmlStreamReader &reader, Material &material) {
    while(reader.readNextStartElement()) {
		if (reader.name() == "texture") {
			readTexture(reader, material);
			reader.skipCurrentElement();
		} else if (reader.name() == "param") {
			readParam(reader, material);
		}
    }
}

void MaterialXml::readTexture(QXmlStreamReader & reader, Material & material) {
	if (reader.attributes().hasAttribute(("hash"))) {
		QString hash = reader.attributes().value("hash").toString();
		material.textureHashes.append(hash);
	}
}

void MaterialXml::readParam(QXmlStreamReader &reader, Material &material) {
	QString name = "";
	if (reader.attributes().hasAttribute(("name")))
		name = reader.attributes().value("name").toString();

	QString valuesString = reader.readElementText();
	QStringList values = valuesString.split(" ");
	QList<float> paramValues;

	for (int i = 0; i < 4; i++) {
		paramValues.append(values.at(i).toFloat());
	}

	material.properties.insert(name, paramValues);
}
