#ifndef CRYPTOCLASS_H
#define CRYPTOCLASS_H

#include <QObject>
#include <QRandomGenerator>
#include <QDebug>
#include "openssl/evp.h"
#include "openssl/sha.h"

static const QString aboutString = "Program takes a password and makes SHA512 hash from it.\n"
                                   "It uses GNU crypt as this was my requirement.\n"
                                   "If needed, new random password of desired lengh can be created.\n"
                                   "Author info and contact: https://512sha.trollnet.com.pl/\n"
                                   "Program is licenced under GNU LGPL licence 2.0, please see LICENSE file "
                                   "in the program folder and with absolutely NO WARRANTY whatsoever.";

static const QString aboutConsoleString = "\nProgram takes a password and makes SHA512 hash from it.\n"
                                          "It uses GNU crypt as this was my requirement.\n"
                                          "Author info and contact: https://512sha.trollnet.com.pl/\n"
                                          "Program is licenced under GNU LGPL licence 2.0, please see LICENSE file "
                                          "in the program folder and with absolutely NO WARRANTY whatsoever.";

static const QString aboutQt = "\n\n *** This program uses Qt version 5.15.2. *** \n\n"
"Qt is a C++ toolkit for cross-platform application development.\n"
"Qt provides single-source portability across all major desktop operating systems. It is also available for embedded Linux and other embedded and mobile operating systems.\n"
"Qt is available under multiple licensing options designed to accommodate the needs of our various users.\n"
"Qt licensed under our commercial license agreement is appropriate for development of proprietary/commercial software where you do not want to share any source code with third parties or otherwise cannot comply with the terms of GNU (L)GPL.\n"
"Qt licensed under GNU (L)GPL is appropriate for the development of Qt applications provided you can comply with the terms and conditions of the respective licenses.\n"
"Please see qt.io/licensing for an overview of Qt licensing.\n"
"Copyright (C) 2020 The Qt Company Ltd and other contributors.\n"
"Qt and the Qt logo are trademarks of The Qt Company Ltd.\n"
"Qt is The Qt Company Ltd product developed as an open source project. See qt.io for more information.\n\n";

class CryptoClass : public QObject
{
    Q_OBJECT
public:
    explicit CryptoClass(QObject *parent = nullptr);
    QString getCHash(const QByteArray &data) const;
    QString generateRndStr(int length) const;
    void reset();

private:
    const QString pool = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    QRandomGenerator generator;
};

#endif // CRYPTOCLASS_H
