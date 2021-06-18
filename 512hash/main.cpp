#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include "cryptoclass.h"
#include "stdio.h"

enum CommandLineParseResult {
    clOK,
    clHelpRequested,
    clVerRequested,
    clArgMissing,
    clError
};

CommandLineParseResult parseReulst(QCommandLineParser &parser,QString *resString, QString *pw) {
    QCommandLineOption helpOption = parser.addHelpOption();
    QCommandLineOption verOption = parser.addVersionOption();
    parser.addPositionalArgument("password", "A password to be hashed.");
    if (!parser.parse(QCoreApplication::arguments())) {
        *resString = parser.errorText();
        return clError;
    }
    if (parser.isSet(helpOption)) {
        return clHelpRequested;
    }
    if (parser.isSet(verOption)) {
        return clVerRequested;
    }
    if (parser.positionalArguments().size()==0) {
        return clArgMissing;
    }
    if (parser.positionalArguments().size()>1) {
        *resString = "More than 1 parameter provided. This program requires exactly 1 (one) parameter";
        return clError;
    }
    *pw = parser.positionalArguments().at(0);
    return clOK;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationVersion("0.1");
    QCoreApplication::setOrganizationName("TrollNet");
    QCoreApplication::setOrganizationDomain("trollnet.com.pl");
    QCoreApplication::setApplicationName("512hash");
    QCommandLineParser parser;
    parser.setApplicationDescription(aboutConsoleString);
    QString pw;
    QString errMsg;
    switch (parseReulst(parser,&errMsg,&pw)) {
    case clOK:
        break;
    case clError:
        fputs(qPrintable(errMsg),stderr);
        fputs("\n",stderr);
        fputs(qPrintable(parser.helpText()),stderr);
        return 1;
        break;
    case clVerRequested:
        fputs(qPrintable(aboutQt),stdout);
        parser.showVersion();
        break;
    case clHelpRequested:
        fputs(qPrintable(aboutQt),stdout);
        parser.showHelp(0);
        break;
    case clArgMissing:
        fputs(qPrintable("Missing parameter"),stderr);
        fputs("\n",stderr);
        parser.showHelp(1);
        break;
    }
    CryptoClass crypto;
    const QString result = crypto.getHash(pw.toUtf8()).toBase64();
    printf(qPrintable(result));
    printf("\n");
    return 0;
}
