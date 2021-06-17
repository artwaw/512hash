#include "cryptoclass.h"

CryptoClass::CryptoClass(QObject *parent) : QObject(parent)
{
    generator = QRandomGenerator::securelySeeded();
    hash = new QCryptographicHash(method);
}

QByteArray CryptoClass::getHash(const QByteArray &data) const {
    hash->addData(crypt(data.constData(),generateRndStr(16).toUtf8().constData()));
    return hash->result();
}

QString CryptoClass::generateRndStr(int length) const {
    QString result;
    for (auto x=0;x<length;++x) {
        result.append(pool.at(generator.global()->bounded(pool.size())));
    }
    return result;
}

CryptoClass::~CryptoClass() {
    delete hash;
}

void CryptoClass::reset() {
    hash->reset();
}
