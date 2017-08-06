#pragma once
/*
Не пытайтесь редактировать этот файл. Любые изменения сделаные в этом файле будут потеряны!
*/

#include <vector>
#include <string>
#include <cstring>

struct BuildInfo
{
    BuildInfo()
    {
        shortHash = "2aa1c71";
        branch = "master";
        tag = "-";
        buildId = "-"; 
        os = "Linux_Ubuntu_16.04"; 
        compiler = "-"; 
        dateTime = "06/08/2017 01:16:03"; 
        changedFiles = std::vector<const char *>({""});
        untrackedFiles = std::vector<const char *>({"buildInfoCreator.py"});
    }
    const char * shortHash;
    const char * branch;
    const char * tag;
    const char * buildId;
    const char * os;
    const char * compiler;
    const char * dateTime;
    std::vector<const char *> changedFiles;
    std::vector<const char *> untrackedFiles;

    std::string info()
    {
        std::string versionInfo = "";
        versionInfo += withRightPad(u8"Короткий хеш:", 24, ' ') + shortHash + '\n';
        versionInfo += withRightPad(u8"Ветка:", 24, ' ')        + branch + '\n';
        versionInfo += withRightPad(u8"Метка:", 24, ' ')        + tag + '\n';
        versionInfo += withRightPad(u8"Номер сборки:", 24, ' ') + buildId + '\n';
        versionInfo += withRightPad(u8"ОС:", 24, ' ') + os + '\n';
        versionInfo += withRightPad(u8"Компилятор:", 24, ' ') + compiler + '\n';
        versionInfo += withRightPad(u8"Дата и время:", 24, ' ') + dateTime + '\n';

        writeList(versionInfo, u8"Измененные файлы:", changedFiles);
        writeList(versionInfo, u8"Не отслеживаемые файлы:", untrackedFiles);
        return versionInfo;
    }

private:
    std::string withRightPad(std::string keyName, uint width, char c) const
    {
        uint keyNameLength = strlen_utf8(keyName);
        int additionSize = (int)width-(int)keyNameLength;

        std::string result = keyName;

        if (additionSize > 0)
        {
            for (uint i=0; i < additionSize; i++)
            {
                result += c;
            }
        }
        return result;
    };

    void writeList(std::string & target, std::string preamble, std::vector<const char *> & list) const
    {
        bool isFirstLine = true;
        for(const char * file : list)
        {
            if (isFirstLine)
            {
                if (file == std::string(""))
                {
                    target += withRightPad(preamble, 24, ' ') + "-\n";
                }
                else
                {
                    target += withRightPad(preamble, 24, ' ') + file + "\n";

                }
                isFirstLine = false;
            }
            else
            {
                target += withRightPad(" ", 24, ' ') + file + "\n";
            }
        }
    };

    std::size_t strlen_utf8(const std::string & str) const
    {
        std::size_t length = 0;
        for (char c : str) {
            if ((c & 0xC0) != 0x80) {
                ++length;
            }
        }
        return length;
    }
};