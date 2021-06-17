#ifndef CRYPTOCLASS_H
#define CRYPTOCLASS_H

#include <QObject>
#include <QRandomGenerator>
#include <QCryptographicHash>
#include <QDebug>
#include "unistd.h"

class CryptoClass : public QObject
{
    Q_OBJECT
public:
    explicit CryptoClass(QObject *parent = nullptr);
    QByteArray getHash(const QByteArray &data) const;
    ~CryptoClass();
    QString generateRndStr(int length) const;
    void reset();

private:
    const QString pool = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const QCryptographicHash::Algorithm method = QCryptographicHash::Sha512;
    QRandomGenerator generator;
    QCryptographicHash *hash;
};

#endif // CRYPTOCLASS_H
