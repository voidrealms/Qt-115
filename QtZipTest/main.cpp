#include <QCoreApplication>

#include <QDebug>
#include "zipreader.h"
#include "zipwriter.h"

/**
 * @brief Compression Test
 * @param ZipFile The zip file
 */
void CompressTest(QString ZipFile)
{
    //ZipWriter cZip(ZipFile);
    //cZip.addDirectory("E:/Development/qt114/QtZipTest/Images");
    //cZip.close();

    ZipWriter cZip(ZipFile);
    QString SingleFile = "E:/Development/qt114/QtZipTest/Images/fail1.jpg";
    QFile file(SingleFile);
    file.open(QIODevice::ReadOnly);

    cZip.addFile("test.jpg", file.readAll());

    file.close();
    cZip.close();
}


/**
 * @brief Decompression Test
 * @param ZipFile The zip file
 */
void DecompressTest(QString ZipFile)
{
    ZipReader cZip(ZipFile);
    foreach(ZipReader::FileInfo item, cZip.fileInfoList())
    {
        qDebug() << item.filePath;
    }

    //cZip.extractAll("DEST");

    ZipReader::FileInfo finfo = cZip.entryInfoAt(0);
    QFile file("E:/Development/qt114/QtZipTest/Images/fail2.jpg");
    file.open(QIODevice::WriteOnly);

    file.write(cZip.fileData(finfo.filePath));

    file.close();
    cZip.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString ZipFile = "E:/Development/qt114/QtZipTest/test.zip";
    CompressTest(ZipFile);
    DecompressTest(ZipFile);

    return a.exec();
}
