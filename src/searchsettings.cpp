#include "searchsettings.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QCoreApplication>

SearchSettings::SearchSettings() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/Sm4shMaterials.db");
    db.open();
}

SearchSettings::~SearchSettings() {
    db.close();
}

bool SearchSettings::matchesSearch(ComparisonOperation operation, int value, int compareValue) {
    if (operation == SearchSettings::ComparisonOperation::Equals)
        return value == compareValue;
    else if (operation == SearchSettings::ComparisonOperation::Greater)
        return value > compareValue;
    else if (operation == SearchSettings::ComparisonOperation::GreaterOrEqual)
        return value >= compareValue;
    else if (operation == SearchSettings::ComparisonOperation::Less)
        return value < compareValue;
    else if (operation == SearchSettings::ComparisonOperation::LessOrEqual)
        return value <= compareValue;

    return false;
}

bool SearchSettings::matchesSearch(ComparisonOperation operation, uint value, uint compareValue) {
	if (operation == SearchSettings::ComparisonOperation::Equals)
        return value == compareValue;
	else if (operation == SearchSettings::ComparisonOperation::Greater)
        return value > compareValue;
	else if (operation == SearchSettings::ComparisonOperation::GreaterOrEqual)
        return value >= compareValue;
	else if (operation == SearchSettings::ComparisonOperation::Less)
        return value < compareValue;
	else if (operation == SearchSettings::ComparisonOperation::LessOrEqual)
        return value <= compareValue;

	return false;
}

QString SearchSettings::getComparisonOperator(ComparisonOperation op) {
    switch (op) {
        case ComparisonOperation::Equals:
            return "=";
        case ComparisonOperation::Greater:
            return ">";
        case ComparisonOperation::GreaterOrEqual:
            return ">=";
        case ComparisonOperation::Less:
            return "<";
        case ComparisonOperation::LessOrEqual:
            return "<=";
        case ComparisonOperation::NotEqual:
            return "<>";
    }
    return "";
}

QList<Material> SearchSettings::filterMaterials() {
	QList<Material> filteredMaterialList;

    // TODO: Reuse the database connection.
    const QString DRIVER("QSQLITE");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/Sm4shMaterials.db");
    db.open();
    QSqlQuery query(db);

    QString query_text = "SELECT Path,Flags,CullMode,AlphaTest,AlphaFunction,SrcFactor,DstFactor,ZBufferOffset,Properties,Textures FROM Material WHERE TRUE";
    // Construct a WHERE statement to filter the other fields.
    if (filterSrc) {
        query_text += QString(" AND SrcFactor %1 %2").arg(getComparisonOperator(srcComparison), QString::number(srcFactor));
    }
    if (filterDst) {
        query_text += QString(" AND DstFactor %1 %2").arg(getComparisonOperator(dstComparison), QString::number(dstFactor));
    }
    if (filterAlphaFunc) {
        query_text += QString(" AND AlphaFunction %1 %2").arg(getComparisonOperator(alphaFuncComparison), QString::number(alphaFunc));
    }
    if (filterAlphaTest) {
        query_text += QString(" AND AlphaTest %1 %2").arg(getComparisonOperator(alphaTestComparison), QString::number(alphaTest));
    }
    if (filterCullMode) {
        query_text += QString(" AND CullMode %1 %2").arg(getComparisonOperator(cullComparison), QString::number(cullMode));
    }
    if (filterZBufferOffset) {
        query_text += QString(" AND ZBufferOffset %1 %2").arg(getComparisonOperator(zBuffComparison), QString::number(zBufferOffset));
    }

    qInfo() << query_text << '\n';
    query.exec(query_text);
    qInfo() << query.lastError();

    while (query.next()) {
        Material material;
        material.fileName = query.value(0).toString();
        material.flags = query.value(1).toString().toUInt(nullptr, 16);
        material.cullMode = query.value(2).toUInt();
        material.alphaTest = query.value(3).toUInt();
        material.alphaFunc = query.value(4).toUInt();
        material.srcFactor = query.value(5).toUInt();
        material.dstFactor = query.value(6).toUInt();
        material.zBufferOffset = query.value(7).toUInt();
        material.properties = query.value(8).toString();
        material.textures = query.value(9).toString();

        bool validMaterial = true;

        // Check flags using the selected flags values and comparison operator.
        if (filterFlags) {
            uint value = material.flags & flags1;
            bool validFlags = SearchSettings::matchesSearch(flagsComparison, value, flags2);
            validMaterial = validMaterial && validFlags;
        }
        if (filterTextureCount) {
            int count = material.textures.split('\n').size();
            validMaterial = validMaterial && matchesSearch(textureComparison, count, textureCount);
        }
        if (filterPropertyName) {
            bool hasProperty = false;
            for (const auto& property : material.properties.split('\n')) {
                if (property.contains(materialProperty, Qt::CaseInsensitive)) {
                    hasProperty = true;
                }
            }
            validMaterial = validMaterial && hasProperty;
        }

        if (validMaterial) {
            filteredMaterialList.append(material);
        }

    }
    db.close();

	return filteredMaterialList;
}
